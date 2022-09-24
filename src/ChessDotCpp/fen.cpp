#include "fen.h"

#include "common.h"
#include "zobrist.h"

#include <regex>
#include <sstream>

Piece TryParsePiece(char ch)
{
    switch (ch)
    {
    case 'p': return Pieces::BlackPawn;
    case 'P': return Pieces::WhitePawn;
    case 'n': return Pieces::BlackKnight;
    case 'N': return Pieces::WhiteKnight;
    case 'b': return Pieces::BlackBishop;
    case 'B': return Pieces::WhiteBishop;
    case 'r': return Pieces::BlackRook;
    case 'R': return Pieces::WhiteRook;
    case 'q': return Pieces::BlackQueen;
    case 'Q': return Pieces::WhiteQueen;
    case 'k': return Pieces::BlackKing;
    case 'K': return Pieces::WhiteKing;
    default: return Pieces::Empty;
    }
}

void SyncMaterial(BoardBase& board)
{
    for (Piece piece = 0; piece < Pieces::Count; piece++)
    {
        Color color = piece & Pieces::Color;
        bool isPawn = (piece & ~Pieces::Color) == Pieces::Pawn;
        if (!isPawn)
        {
            board.PieceMaterial[color] += board.PieceCounts[piece] * EvaluationConstants::PieceValues[piece];
        }
    }
}

template<class TBoard>
void Fens::Parse(TBoard& board, Fen fen)
{
    board = TBoard();
    board.ResetAccumulator();
    //fen = std::regex_replace(fen, std::regex("/"), "");
    auto cleanedFen = Fen();
    cleanedFen.reserve(fen.size());
	for (auto i : fen)
	{
        if (i != '/')
        {
            cleanedFen += i;
        }
	}

    
    //board.ArrayBoard = new Piece[64];
    //board.BitBoard = new ulong[13];
    //board.CastlingPermissions = CastlingPermission.None;
    //board.History2 = new UndoMove[2048];

    Position boardPosition = 0;
    size_t fenPosition = 0;
    for (; fenPosition < cleanedFen.size(); fenPosition++)
    {
        Position fixedBoardPosition = (7 - boardPosition / 8) * 8 + boardPosition % 8;
        auto ch = cleanedFen[fenPosition];
        const Piece piece = TryParsePiece(ch);
        if (piece != Pieces::Empty)
        {
            const auto pieceBitBoard = GetBitboard(fixedBoardPosition);
            board.BitBoard[piece] |= pieceBitBoard;
            board.ArrayBoard[fixedBoardPosition] = piece;
            //board.SetAccumulatorPiece(fixedBoardPosition, piece);
            board.PieceCounts[piece]++;
            const auto file = Files::Get(fixedBoardPosition);
            const auto queenSide = file < 4;
            if (piece == Pieces::WhiteKing)
            {
                board.KingPositions[Colors::White] = fixedBoardPosition;
                board.KingSides[Colors::White] = queenSide;
                board.Buckets[Colors::White] = EvaluationNnueBase::GetBucket(fixedBoardPosition, Colors::White);
                board.AccumulatorInvalidations[Colors::White] = true;
            }
            else if (piece == Pieces::BlackKing)
            {
                board.KingPositions[Colors::Black] = fixedBoardPosition;
                board.KingSides[Colors::Black] = queenSide;
                board.Buckets[Colors::Black] = EvaluationNnueBase::GetBucket(fixedBoardPosition, Colors::Black);
                board.AccumulatorInvalidations[Colors::Black] = true;
            }
            boardPosition++;
            continue;
        }

        auto emptySpaces = static_cast<int16_t>(ch) - 0x30;
        if (emptySpaces > 0 && emptySpaces < 9)
        {
            boardPosition += static_cast<Position>(emptySpaces);
            continue;
        }

        if (ch == ' ')
        {
            break;
        }

    }

    fenPosition++;
    switch (cleanedFen[fenPosition])
    {
    case 'w':
        board.ColorToMove = Colors::White;
        board.WhiteToMove = true;
        break;
    case 'b':
        board.ColorToMove = Colors::Black;
        board.WhiteToMove = false;
        break;
    default:
        Throw("Unknown color");
    }
    
    fenPosition += 2;

    for (auto i = 0; i < 4; i++)
    {
        if (fenPosition >= cleanedFen.size())
        {
            break;
        }
        
        bool done = false;
        switch (cleanedFen[fenPosition])
        {
        case 'K':
            board.CastlingPermissions |= CastlingPermissions::WhiteKing;
            break;
        case 'Q':
            board.CastlingPermissions |= CastlingPermissions::WhiteQueen;
            break;
        case 'k':
            board.CastlingPermissions |= CastlingPermissions::BlackKing;
            break;
        case 'q':
            board.CastlingPermissions |= CastlingPermissions::BlackQueen;
            break;
        case ' ':
            fenPosition--;
            done = true;
            break;
        case '-':
            done = true;
            break;
        default:
            Throw("Unknown character in castling permissions");
        }
        fenPosition++;
        if (done)
        {
            break;
        }
    }

    fenPosition++;
    if (fenPosition < cleanedFen.size() && cleanedFen[fenPosition] != '-')
    {
        auto lower = tolower(cleanedFen[fenPosition]);
        auto file = static_cast<File>(lower - 0x61);
        //var rank = fen[fenPosition] - 0x30;
        if (file >= 0 && file < 8)
        {
            board.EnPassantFileIndex = file;
            board.EnPassantFile = BitboardConstants::Files[file];
        }
        fenPosition++;
        board.EnPassantRankIndex = cleanedFen[fenPosition] - '0' - 1;
    }
    else
    {
        board.EnPassantFile = 0;
        board.EnPassantFileIndex = -1;
        board.EnPassantRankIndex = -1;
    }

    board.SyncExtraBitBoards();
    SyncMaterial(board);
    board.Key = ZobristKeys.CalculateKey(board);
    board.PawnKey = ZobristKeys.CalculatePawnKey(board);

    board.FinalizeAccumulator();
}

char PieceToChar(Piece piece)
{
    switch (piece)
    {
    case Pieces::Empty: return '\0';
    case Pieces::WhitePawn: return 'P';
    case Pieces::WhiteKnight: return 'N';
    case Pieces::WhiteBishop: return 'B';
    case Pieces::WhiteRook: return 'R';
    case Pieces::WhiteQueen: return 'Q';
    case Pieces::WhiteKing: return 'K';
    case Pieces::BlackPawn: return 'p';
    case Pieces::BlackKnight: return 'n';
    case Pieces::BlackBishop: return 'b';
    case Pieces::BlackRook: return 'r';
    case Pieces::BlackQueen: return 'q';
    case Pieces::BlackKing: return 'k';
    default: Throw("Unknown piece while parsing FEN");
    }
}

template void Fens::Parse(BoardBase& board, Fen fen);
template void Fens::Parse(Board& board, Fen fen);

template<class TBoard>
Fen Fens::Serialize(const TBoard& board)
{
    auto builder = std::stringstream();
    for (int i = 7; i >= 0; i--)
    {
        auto pawns = 0;
        for (int j = 0; j < 8; j++)
        {
            auto index = i * 8 + j;
            Piece piece = board.ArrayBoard[index];
            auto ch = PieceToChar(piece);
            if (ch == '\0')
            {
                pawns++;
            }
            else
            {
                if (pawns != 0)
                {
                    builder << pawns;
                    pawns = 0;
                }
                builder << ch;
            }
        }
        if (pawns != 0)
        {
            builder << pawns;
        }
        if (i != 0)
        {
            builder << '/';
        }
    }
    builder << " ";
    builder << (board.WhiteToMove ? 'w' : 'b');
    builder << " ";
    if (board.CastlingPermissions == CastlingPermissions::None)
    {
        builder << "-";
    }
    else
    {
        if ((board.CastlingPermissions & CastlingPermissions::WhiteKing) != CastlingPermissions::None)
        {
            builder << "K";
        }
        if ((board.CastlingPermissions & CastlingPermissions::WhiteQueen) != CastlingPermissions::None)
        {
            builder << "Q";
        }
        if ((board.CastlingPermissions & CastlingPermissions::BlackKing) != CastlingPermissions::None)
        {
            builder << "k";
        }
        if ((board.CastlingPermissions & CastlingPermissions::BlackQueen) != CastlingPermissions::None)
        {
            builder << "q";
        }
    }
    builder << " ";
    if (board.EnPassantFileIndex == -1)
    {
        builder << "-";
    }
    else
    {
        auto fileLetter = static_cast<char>('a' + board.EnPassantFileIndex);
        builder << fileLetter;
        builder << board.EnPassantRankIndex + 1;
    }

    auto fen = builder.str();
    return fen;
}

template Fen Fens::Serialize(const BoardBase& board);
template Fen Fens::Serialize(const Board& board);