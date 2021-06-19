#include "board.h"

#include "zobrist.h"
#include "likeliness.h"

bool Board::CanCastle(const CastlingPermission permission) const
{
    return (CastlingPermissions & permission) != CastlingPermissions::None;
}

void Board::SyncExtraBitBoards()
{
    BitBoard[Colors::White] = BitBoard[Pieces::WhitePawn]
        | BitBoard[Pieces::WhiteKnight]
        | BitBoard[Pieces::WhiteBishop]
        | BitBoard[Pieces::WhiteRook]
        | BitBoard[Pieces::WhiteQueen]
        | BitBoard[Pieces::WhiteKing];

    BitBoard[Colors::Black] = BitBoard[Pieces::BlackPawn]
        | BitBoard[Pieces::BlackKnight]
        | BitBoard[Pieces::BlackBishop]
        | BitBoard[Pieces::BlackRook]
        | BitBoard[Pieces::BlackQueen]
        | BitBoard[Pieces::BlackKing];

    AllPieces = BitBoard[Colors::White] | BitBoard[Colors::Black];
    EmptySquares = ~AllPieces;
}

void Board::DoMove(const Move move)
{
    History[HistoryDepth].Move = move;
    History[HistoryDepth].Key = Key;
    History[HistoryDepth].PawnKey = PawnKey;
    History[HistoryDepth].CastlingPermission = CastlingPermissions;
    History[HistoryDepth].EnPassantFileIndex = EnPassantFileIndex;
    History[HistoryDepth].EnPassantRankIndex = EnPassantRankIndex;
    History[HistoryDepth].FiftyMoveRule = FiftyMoveRuleIndex;
    History[HistoryDepth].StaticEvaluation = StaticEvaluation;
    HistoryDepth++;

    const auto originalWhiteToMove = WhiteToMove;
    const auto originalColorToMove = ColorToMove;

    WhiteToMove = !originalWhiteToMove;
    ColorToMove = ColorToMove ^ 1;
    Key ^= ZobristKeys.ZWhiteToMove;

    if (EnPassantFile != 0)
    {
        Key ^= ZobristKeys.ZEnPassant[EnPassantFileIndex];

        EnPassantFile = 0;
        EnPassantFileIndex = -1;
        EnPassantRankIndex = -1;
    }

    if (move.GetNullMove())
    {
        SyncExtraBitBoards();
        // TODO check
        return;
    }


    const Position from = move.GetFrom();
    const Position to = move.GetTo();
    const Position piece = move.GetPiece();
    const Piece takesPiece = move.GetTakesPiece();
    
    // FROM
    const Bitboard fromPosBitBoard = GetBitboard(from);
    ArrayBoard[from] = Pieces::Empty;
    BitBoard[piece] &= ~fromPosBitBoard;
    Key ^= ZobristKeys.ZPieces[from][piece];

    const bool isPawn = (piece & ~Pieces::Color) == Pieces::Pawn;
    const bool takesPawn = (takesPiece & ~Pieces::Color) == Pieces::Pawn;
    if (isPawn)
    {
        FiftyMoveRuleIndex = static_cast<HistoryPly>(HistoryDepth - 1);
        PawnKey ^= ZobristKeys.ZPieces[from][piece];
    }

    // PROMOTIONS
    Piece promotedPiece;
    if (move.GetPawnPromoteTo() != Pieces::Empty)
    {
        promotedPiece = move.GetPawnPromoteTo();
        PieceCounts[piece]--;
        PieceCounts[promotedPiece]++;
        PawnMaterial[originalColorToMove] -= EvaluationConstants::PieceValues[Pieces::Pawn];
        PieceMaterial[originalColorToMove] += EvaluationConstants::PieceValues[promotedPiece];
    }
    else
    {
        promotedPiece = piece;
    }
        
    // TO
    const Bitboard toPosBitBoard = GetBitboard(to);
    ArrayBoard[to] = promotedPiece;
    BitBoard[promotedPiece] |= toPosBitBoard;
    Key ^= ZobristKeys.ZPieces[to][promotedPiece];
    if (isPawn && move.GetPawnPromoteTo() == Pieces::Empty)
    {
        PawnKey ^= ZobristKeys.ZPieces[to][piece];
    }
    
    // TAKES
    if (takesPiece > 0)
    {
        if (!move.GetEnPassant())
        {
            BitBoard[takesPiece] &= ~toPosBitBoard;
            Key ^= ZobristKeys.ZPieces[to][takesPiece];
            if (takesPawn)
            {
                PawnKey ^= ZobristKeys.ZPieces[to][takesPiece];
            }
        }
        FiftyMoveRuleIndex = HistoryDepth - 1;
        PieceCounts[takesPiece]--;
        if (takesPawn)
        {
            PawnMaterial[ColorToMove] -= EvaluationConstants::PieceValues[takesPiece];
        }
        else
        {
            PieceMaterial[ColorToMove] -= EvaluationConstants::PieceValues[takesPiece];
        }
    }
    
    // KING POS
    if (piece == (Pieces::King | originalColorToMove))
    {
        KingPositions[originalColorToMove] = to;
    }

    // EN PASSANT
    if (move.GetEnPassant())
    {
        int killedPawnPos;
        if (originalWhiteToMove) // TODO: whitetomove
        {
            killedPawnPos = to - 8;
        }
        else
        {
            killedPawnPos = to + 8;
        }

        Bitboard killedPawnBitBoard = GetBitboard(killedPawnPos);

        BitBoard[takesPiece] &= ~killedPawnBitBoard;
        ArrayBoard[killedPawnPos] = Pieces::Empty;
        Key ^= ZobristKeys.ZPieces[killedPawnPos][takesPiece];
        PawnKey ^= ZobristKeys.ZPieces[killedPawnPos][takesPiece];
    }

    // PAWN DOUBLE MOVES
    if ((piece == Pieces::WhitePawn && from + 16 == to) || (piece == Pieces::BlackPawn && from - 16 == to))
    {
        File fileIndex = from % 8;
        Rank rankIndex = (to >> 3) + (originalWhiteToMove ? -1 : 1);
        EnPassantFile = BitboardConstants::Files[fileIndex];
        EnPassantFileIndex = fileIndex;
        EnPassantRankIndex = rankIndex;
        Key ^= ZobristKeys.ZEnPassant[fileIndex];
    }
    else
    {
        EnPassantFile = 0;
        EnPassantFileIndex = -1;
        EnPassantRankIndex = -1;
    }

    // CASTLING
    if (move.GetCastle())
    {
        auto kingSide = to % 8 > 3;
        Position castlingRookPos = (kingSide ? 7 : 0) + (originalWhiteToMove ? 0 : 56);
        Position castlingRookNewPos = (from + to) / 2;
        Piece rookPiece = originalWhiteToMove ? Pieces::WhiteRook : Pieces::BlackRook;

        ArrayBoard[castlingRookPos] = Pieces::Empty;
        ArrayBoard[castlingRookNewPos] = rookPiece;
        BitBoard[rookPiece] &= ~GetBitboard(castlingRookPos);
        BitBoard[rookPiece] |= GetBitboard(castlingRookNewPos);
        Key ^= ZobristKeys.ZPieces[castlingRookPos][rookPiece];
        Key ^= ZobristKeys.ZPieces[castlingRookNewPos][rookPiece];
    }

    const CastlingPermission originalPermissions = CastlingPermissions;
    CastlingPermissions &= CastleRevocation.Table[from];
    CastlingPermissions &= CastleRevocation.Table[to];
    const CastlingPermission revoked = CastlingPermissions ^ originalPermissions;
    Key ^= ZobristKeys.ZCastle[revoked];
    
    //SyncCastleTo1();
    SyncExtraBitBoards();
}

void Board::UndoMove()
{
    auto& history = History[HistoryDepth - 1];
    auto move = history.Move;
    HistoryDepth--;

    EnPassantFileIndex = history.EnPassantFileIndex;
    EnPassantRankIndex = history.EnPassantRankIndex;
    EnPassantFile = EnPassantFileIndex >= 0 ? BitboardConstants::Files[history.EnPassantFileIndex] : 0;
    CastlingPermissions = history.CastlingPermission;
    Key = history.Key;
    PawnKey = history.PawnKey;
    FiftyMoveRuleIndex = history.FiftyMoveRule;
    StaticEvaluation = history.StaticEvaluation;

    const Color originalColorToMove = ColorToMove;
    WhiteToMove = !WhiteToMove;
    ColorToMove = ColorToMove ^ 1;


    if (move.GetNullMove())
    {
        SyncExtraBitBoards();
        // TODO check
        return;
    }

    const Position from = move.GetFrom();
    const Position to = move.GetTo();
    const Piece piece = move.GetPiece();
    const Piece takesPiece = move.GetTakesPiece();
    
    // FROM
    Bitboard fromPosBitBoard = GetBitboard(from);
    
    //Piece promotedPiece = move.PawnPromoteTo.HasValue ? move.PawnPromoteTo.Value : move.Piece;
    ArrayBoard[from] = piece;
    BitBoard[piece] |= fromPosBitBoard;

    Piece promotedPiece;
    if (move.GetPawnPromoteTo() != Pieces::Empty)
    {
        promotedPiece = move.GetPawnPromoteTo();
        PieceCounts[piece]++;
        PieceCounts[promotedPiece]--;
        PawnMaterial[ColorToMove] += EvaluationConstants::PieceValues[Pieces::Pawn];
        PieceMaterial[ColorToMove] -= EvaluationConstants::PieceValues[promotedPiece];
    }
    else
    {
        promotedPiece = piece;
    }

    
    // TO
    Bitboard toPosBitBoard = GetBitboard(to);
    BitBoard[promotedPiece] &= ~toPosBitBoard;
    
    if (move.GetEnPassant())
    {
        ArrayBoard[to] = Pieces::Empty;
    }
    else
    {
        ArrayBoard[to] = takesPiece;
    }

    // KING POS
    if (piece == Pieces::King + ColorToMove)
    {
        KingPositions[ColorToMove] = from;
    }
    
    // TAKES
    if(takesPiece > 0)
    {
        if (!move.GetEnPassant())
        {
            BitBoard[takesPiece] |= toPosBitBoard;
        }
        PieceCounts[takesPiece]++;
        const bool takesPawn = (takesPiece & ~Pieces::Color) == Pieces::Pawn;
        if (takesPawn)
        {
            PawnMaterial[originalColorToMove] += EvaluationConstants::PieceValues[takesPiece];
        }
        else
        {
            PieceMaterial[originalColorToMove] += EvaluationConstants::PieceValues[takesPiece];
        }
    }

    // EN PASSANT
    if (move.GetEnPassant())
    {
        Position killedPawnPos;
        if (WhiteToMove)
        {
            killedPawnPos = to - 8;
        }
        else
        {
            killedPawnPos = to + 8;
        }

        const Bitboard killedPawnBitBoard = GetBitboard(killedPawnPos);
        BitBoard[takesPiece] |= killedPawnBitBoard;
        ArrayBoard[killedPawnPos] = takesPiece;
    }

    if (move.GetCastle())
    {
        auto kingSide = to % 8 > 3;
        auto castlingRookPos = (kingSide ? 7 : 0) + (WhiteToMove ? 0 : 56);
        auto castlingRookNewPos = (from + to) / 2;
        auto rookPiece = WhiteToMove ? Pieces::WhiteRook : Pieces::BlackRook;

        ArrayBoard[castlingRookPos] = rookPiece;
        ArrayBoard[castlingRookNewPos] = Pieces::Empty;
        BitBoard[rookPiece] |= GetBitboard(castlingRookPos);
        BitBoard[rookPiece] &= ~GetBitboard(castlingRookNewPos);
    }

    //SyncCastleTo1();
    SyncExtraBitBoards();
}

Move Board::FromPositionString(const MoveString& moveString) const
{
    const Position from = Move::TextToPosition(moveString.substr(0, 2));
    const Position to = Move::TextToPosition(moveString.substr(2, 2));
    const Piece piece = ArrayBoard[from];
    Piece takesPiece = ArrayBoard[to];
    bool enPassant = false;
    Piece pawnPromotesTo = Pieces::Empty;
    if (piece == Pieces::WhitePawn || piece == Pieces::BlackPawn)
    {
        if (from % 8 != to % 8) // Must be take
        {
            if (takesPiece == Pieces::Empty) // Must be en-passant
            {
                takesPiece = static_cast<Piece>(Pieces::Pawn + (ColorToMove ^ 1));
                enPassant = true;
            }
        }
    }

    if (moveString.length() == 5)
    {
        switch (moveString[4])
        {
        case 'q':
        case 'Q':
            pawnPromotesTo = static_cast<Piece>(Pieces::Queen + ColorToMove);
            break;
        case 'n':
        case 'N':
            pawnPromotesTo = static_cast<Piece>(Pieces::Knight + ColorToMove);
            break;
        case 'b':
        case 'B':
            pawnPromotesTo = static_cast<Piece>(Pieces::Bishop + ColorToMove);
            break;
        case 'r':
        case 'R':
            pawnPromotesTo = static_cast<Piece>(Pieces::Rook + ColorToMove);
            break;
        default: Throw("Unknown promotion");
        }
    }

    const bool castle = (piece == Pieces::WhiteKing || piece == Pieces::BlackKing) && std::abs(from - to) == 2;
    
    const Move move = Move(from, to, piece, takesPiece, enPassant, castle, pawnPromotesTo);
    return move;
}

void Board::DoMove(const MoveString& moveString)
{
    const Move move = FromPositionString(moveString);
    DoMove(move);
}

void Board::FlipColors()
{
    ArrayBoard = Positions::MakeReflected(ArrayBoard);

    for(Piece i = 0; i < Colors::Count; i++)
    {
        PawnMaterial[i] = 0;
        PieceMaterial[i] = 0;
    }
    
    for(Piece i = 0; i < Pieces::Count; i++)
    {
        BitBoard[i] = 0;
        PieceCounts[i] = 0;
    }

    for(Position i = 0; i < Positions::Count; i++)
    {
        const auto piece = ArrayBoard[i];
        if(piece == Pieces::Empty)
        {
            continue;
        }
        
        const Piece flippedPiece = piece ^ 1;
        const Piece noColor = flippedPiece & ~Pieces::Color;
        const Color color = flippedPiece & Pieces::Color;

        if(noColor == Pieces::King)
        {
            KingPositions[color] = i;
        }

        if(noColor == Pieces::Pawn)
        {
            PawnMaterial[color] += EvaluationConstants::PieceValues[flippedPiece];
        }
        else
        {
            PieceMaterial[color] += EvaluationConstants::PieceValues[flippedPiece];
        }
        
        ArrayBoard[i] = flippedPiece;
        BitBoard[flippedPiece] |= GetBitboard(i);
        PieceCounts[flippedPiece] += 1;
    }

    ColorToMove = ColorToMove ^ 1;
    WhiteToMove = !WhiteToMove;
    
    Key = ZobristKeys.CalculateKey(*this);
    PawnKey = ZobristKeys.CalculatePawnKey(*this);
    
    SyncExtraBitBoards();
}
