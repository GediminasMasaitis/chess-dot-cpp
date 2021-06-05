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

void SyncMaterial(Board& board)
{
    for (Piece piece = 0; piece < Pieces::Count; piece++)
    {
        Color color = piece & Pieces::Color;
        bool isPawn = (piece & ~Pieces::Color) == Pieces::Pawn;
        if (isPawn)
        {
            board.PawnMaterial[color] += board.PieceCounts[piece] * EvaluationConstants::PieceValues[piece];
        }
        else
        {
            board.PieceMaterial[color] += board.PieceCounts[piece] * EvaluationConstants::PieceValues[piece];
        }
    }
}

void Fens::Parse(Board& board, Fen fen)
{
    board = Board();
    fen = std::regex_replace(fen, std::regex("/"), "");
    //board.ArrayBoard = new Piece[64];
    //board.BitBoard = new ulong[13];
    //board.CastlingPermissions = CastlingPermission.None;
    //board.History2 = new UndoMove[2048];

    Position boardPosition = 0;
    size_t fenPosition = 0;
    for (; fenPosition < fen.size(); fenPosition++)
    {
        Position fixedBoardPosition = (7 - boardPosition / 8) * 8 + boardPosition % 8;
        auto ch = fen[fenPosition];
        const Piece piece = TryParsePiece(ch);
        if (piece != Pieces::Empty)
        {
            const auto pieceBitBoard = GetBitboard(fixedBoardPosition);
            board.BitBoard[piece] |= pieceBitBoard;
            board.ArrayBoard[fixedBoardPosition] = piece;
            board.PieceCounts[piece]++;
            if (piece == Pieces::WhiteKing)
            {
                board.KingPositions[Colors::White] = fixedBoardPosition;
            }
            else if (piece == Pieces::BlackKing)
            {
                board.KingPositions[Colors::Black] = fixedBoardPosition;
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
    switch (fen[fenPosition])
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
        if (fenPosition >= fen.size())
        {
            break;
        }
        
        bool done = false;
        switch (fen[fenPosition])
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
    if (fenPosition < fen.size() && fen[fenPosition] != '-')
    {
        auto lower = tolower(fen[fenPosition]);
        auto file = static_cast<File>(lower - 0x61);
        //var rank = fen[fenPosition] - 0x30;
        if (file >= 0 && file < 8)
        {
            board.EnPassantFileIndex = file;
            board.EnPassantFile = BitboardConstants::Files[file];
        }
        fenPosition++;
        board.EnPassantRankIndex = fen[fenPosition] - '0' - 1;
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

Fen Fens::Serialize(const Board& board)
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

