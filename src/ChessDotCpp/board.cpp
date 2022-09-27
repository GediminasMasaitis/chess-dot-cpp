#include "board.h"

#include "zobrist.h"

bool BoardBase::CanCastle(const CastlingPermission permission) const
{
    return (CastlingPermissions & permission) != CastlingPermissions::None;
}

void BoardBase::SyncExtraBitBoards()
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
    assert(move.GetTakesPiece() != Pieces::WhiteKing);
    assert(move.GetTakesPiece() != Pieces::BlackKing);

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

    assert(move.GetColorToMove() == originalColorToMove);

    const Position from = move.GetFrom();
    const Position to = move.GetTo();
    const Piece piece = move.GetPiece();
    const Piece takesPiece = move.GetTakesPiece();
    const Piece pieceNoColor = piece & ~Colors::Mask;

    const bool originalKingSide = KingSides[originalColorToMove];
    const bucket_t originalBucket = Buckets[originalColorToMove];

    const bool isKingMove = pieceNoColor == Pieces::King;
    if(isKingMove)
    {
        const auto kingFile = Files::Get(to);
        const bool kingQueenSide = kingFile < 4;
        KingSides[originalColorToMove] = kingQueenSide;

        const bucket_t newBucket = EvaluationNnueBase::GetBucket(to, originalColorToMove);
        Buckets[originalColorToMove] = newBucket;
    }

    /*for(auto color = Colors::White; color < Colors::Black; color++)
    {
        const auto kingPos = KingPositions[color];
        const auto kingFile = Files::Get();

    }*/

    PushAccumulator();
    
    // FROM
    const Bitboard fromPosBitBoard = GetBitboard(from);
    ArrayBoard[from] = Pieces::Empty;
    BitBoard[piece] &= ~fromPosBitBoard;
    Key ^= ZobristKeys.ZPieces[from][piece];
    UnsetAccumulatorPiece(from, piece);

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
    SetAccumulatorPiece(to, promotedPiece);
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
            UnsetAccumulatorPiece(to, takesPiece);
            if (takesPawn)
            {
                PawnKey ^= ZobristKeys.ZPieces[to][takesPiece];
            }
        }
        FiftyMoveRuleIndex = static_cast<HistoryPly>(HistoryDepth - 1);
        PieceCounts[takesPiece]--;
        if (!takesPawn)
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
        Position killedPawnPos;
        if (originalWhiteToMove) // TODO: whitetomove
        {
            killedPawnPos = static_cast<Position>(to - 8);
        }
        else
        {
            killedPawnPos = static_cast<Position>(to + 8);
        }

        Bitboard killedPawnBitBoard = GetBitboard(killedPawnPos);

        BitBoard[takesPiece] &= ~killedPawnBitBoard;
        ArrayBoard[killedPawnPos] = Pieces::Empty;
        Key ^= ZobristKeys.ZPieces[killedPawnPos][takesPiece];
        UnsetAccumulatorPiece(killedPawnPos, takesPiece);
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
        UnsetAccumulatorPiece(castlingRookPos, rookPiece);
        Key ^= ZobristKeys.ZPieces[castlingRookNewPos][rookPiece];
        SetAccumulatorPiece(castlingRookNewPos, rookPiece);
    }

    const CastlingPermission originalPermissions = CastlingPermissions;
    CastlingPermissions &= CastleRevocation.Table[from];
    CastlingPermissions &= CastleRevocation.Table[to];
    const CastlingPermission revoked = CastlingPermissions ^ originalPermissions;
    Key ^= ZobristKeys.ZCastle[revoked];
    
    //SyncCastleTo1();
    SyncExtraBitBoards();

    if (KingSides[originalColorToMove] != originalKingSide || Buckets[originalColorToMove] != originalBucket)
    {
        FinalizeAccumulator(originalColorToMove);
    }
}

void Board::GetKeyAfterMove(const Move move, KeyAnd50Move& keyAnd50Move) const
{
    assert(move.GetTakesPiece() != Pieces::WhiteKing);
    assert(move.GetTakesPiece() != Pieces::BlackKing);

    const auto originalWhiteToMove = WhiteToMove;
    assert(move.GetColorToMove() == ColorToMove);

    keyAnd50Move.Key = Key ^ ZobristKeys.ZWhiteToMove;
    keyAnd50Move.FiftyMoveRuleIndex = FiftyMoveRuleIndex;

    if (EnPassantFile != 0)
    {
        keyAnd50Move.Key ^= ZobristKeys.ZEnPassant[EnPassantFileIndex];
    }

    if (move.GetNullMove())
    {
        return;
    }

    const Position from = move.GetFrom();
    const Position to = move.GetTo();
    const Position piece = move.GetPiece();
    const Piece takesPiece = move.GetTakesPiece();

    // FROM
    keyAnd50Move.Key ^= ZobristKeys.ZPieces[from][piece];

    const bool isPawn = (piece & ~Pieces::Color) == Pieces::Pawn;
    if (isPawn)
    {
        keyAnd50Move.FiftyMoveRuleIndex = HistoryDepth;
    }

    // PROMOTIONS
    Piece promotedPiece;
    if (move.GetPawnPromoteTo() != Pieces::Empty)
    {
        promotedPiece = move.GetPawnPromoteTo();
    }
    else
    {
        promotedPiece = piece;
    }

    // TO
    keyAnd50Move.Key ^= ZobristKeys.ZPieces[to][promotedPiece];

    // TAKES
    if (takesPiece > 0)
    {
        if (!move.GetEnPassant())
        {
            keyAnd50Move.Key ^= ZobristKeys.ZPieces[to][takesPiece];
        }
        keyAnd50Move.FiftyMoveRuleIndex = HistoryDepth;
    }

    // EN PASSANT
    if (move.GetEnPassant())
    {
        Position killedPawnPos;
        if (originalWhiteToMove) // TODO: whitetomove
        {
            killedPawnPos = static_cast<Position>(to - 8);
        }
        else
        {
            killedPawnPos = static_cast<Position>(to + 8);
        }
        keyAnd50Move.Key ^= ZobristKeys.ZPieces[killedPawnPos][takesPiece];
    }

    // PAWN DOUBLE MOVES
    if ((piece == Pieces::WhitePawn && from + 16 == to) || (piece == Pieces::BlackPawn && from - 16 == to))
    {
        const File fileIndex = from % 8;
        keyAnd50Move.Key ^= ZobristKeys.ZEnPassant[fileIndex];
    }

    // CASTLING
    if (move.GetCastle())
    {
        const bool kingSide = to % 8 > 3;
        const Position castlingRookPos = (kingSide ? 7 : 0) + (originalWhiteToMove ? 0 : 56);
        const Position castlingRookNewPos = (from + to) / 2;
        const Piece rookPiece = originalWhiteToMove ? Pieces::WhiteRook : Pieces::BlackRook;

        keyAnd50Move.Key ^= ZobristKeys.ZPieces[castlingRookPos][rookPiece];
        keyAnd50Move.Key ^= ZobristKeys.ZPieces[castlingRookNewPos][rookPiece];
    }

    const CastlingPermission originalPermissions = CastlingPermissions;
    CastlingPermission newPermissions = CastlingPermissions;
    newPermissions &= CastleRevocation.Table[from];
    newPermissions &= CastleRevocation.Table[to];
    const CastlingPermission revoked = newPermissions ^ originalPermissions;
    keyAnd50Move.Key ^= ZobristKeys.ZCastle[revoked];
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
    const Piece pieceNoColor = piece & ~Colors::Mask;

    if (pieceNoColor == Pieces::King)
    {
        const Color kingColor = piece & Colors::Mask;
        const auto kingFile = Files::Get(from);
        const bool kingQueenSide = kingFile < 4;
        KingSides[kingColor] = kingQueenSide;
        Buckets[kingColor] = EvaluationNnueBase::GetBucket(from, kingColor);
    }

    PopAccumulator();
    
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
        if (!takesPawn)
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

Board::Board(): BoardBase(), History()
{
    HistoryDepth = 0;
    FiftyMoveRuleIndex = 0;
}

Move BoardBase::FromPositionString(const MoveString& moveString) const
{
    const Position from = Positions::TextToPosition(moveString.substr(0, 2));
    const Position to = Positions::TextToPosition(moveString.substr(2, 2));
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

void BoardBase::FlipColors()
{
    ArrayBoard = Positions::MakeReflected(ArrayBoard);

    for(Piece i = 0; i < Colors::Count; i++)
    {
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

        if(noColor != Pieces::Pawn)
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

void BoardBase::SetPiece(const Position pos, const Piece piece)
{
    const Bitboard posBitboard = GetBitboard(pos);
    const Color color = piece & Colors::Mask;

    ArrayBoard[pos] = piece;
    BitBoard[piece] |= posBitboard;
    BitBoard[color] |= posBitboard;
    AllPieces |= posBitboard;
    PieceCounts[piece]++;
    SetAccumulatorPiece(pos, piece);
}

void BoardBase::UnsetPiece(const Position pos)
{
    const Piece piece = ArrayBoard[pos];
    const Bitboard posBitboard = GetBitboard(pos);
    const Color color = piece & Colors::Mask;

    ArrayBoard[pos] = Pieces::Empty;
    BitBoard[piece] &= ~posBitboard;
    BitBoard[color] &= ~posBitboard;
    AllPieces &= ~posBitboard;
    PieceCounts[piece]--;
    UnsetAccumulatorPiece(pos, piece);
}

bool BoardBase::IsDrawByMaterial() const
{
    constexpr EachPiece<Piece> limits = {0, 0, 0, 0, 0, 0, 2, 2, 1, 1, 0, 0, 0, 0, 1, 1};

    PieceCounter counter = 0;
    for (Piece piece = Pieces::Pawn; piece < Pieces::King; piece++)
    {
        const auto count = static_cast<PieceCounter>(PieceCounts[piece]);
        if(count > limits[piece])
        {
            return false;
        }

        counter |= count << (piece * 4);
    }

    switch (counter)
    {
    case 0x0000000000000000ULL: // KvK
    case 0x0000000001000000ULL: // KNvK
    case 0x0000000010000000ULL: // KvKN
    case 0x0000000002000000ULL: // KNNvK
    case 0x0000000020000000ULL: // KvKNN
    case 0x0000000012000000ULL: // KNNvKN
    case 0x0000000021000000ULL: // KNvKNN
    case 0x0000000100000000ULL: // KBvK
    case 0x0000001000000000ULL: // KvKB
    case 0x0000001100000000ULL: // KBvKB
    case 0x0000000110000000ULL: // KBvKN
    case 0x0000001001000000ULL: // KNvKB
        return true;
    default:
        return false;
    }
}
