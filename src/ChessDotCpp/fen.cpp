#include "fen.h"

#include "common.h"
#include "zobrist.h"

#include <regex>
#include <sstream>

Piece TryParsePiece(char ch)
{
    switch (ch)
    {
    case 'p': return ChessPiece::BlackPawn;
    case 'P': return ChessPiece::WhitePawn;
    case 'n': return ChessPiece::BlackKnight;
    case 'N': return ChessPiece::WhiteKnight;
    case 'b': return ChessPiece::BlackBishop;
    case 'B': return ChessPiece::WhiteBishop;
    case 'r': return ChessPiece::BlackRook;
    case 'R': return ChessPiece::WhiteRook;
    case 'q': return ChessPiece::BlackQueen;
    case 'Q': return ChessPiece::WhiteQueen;
    case 'k': return ChessPiece::BlackKing;
    case 'K': return ChessPiece::WhiteKing;
    default: return ChessPiece::Empty;
    }
}

void SyncMaterial(Board& board)
{
    // TODO
    /*board.WhiteMaterial = 0;
    board.BlackMaterial = 0;
    for (auto i = 1; i < 7; i++)
    {
        board.WhiteMaterial += board.PieceCounts[i] * EvaluationConstants::Weights[i];
    }
    for (auto i = 7; i < ChessPiece::Count; i++)
    {
        board.BlackMaterial += board.PieceCounts[i] * EvaluationConstants::Weights[i];
    }*/
}

void Fens::Parse(Board& board, Fen fen)
{
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
        if (piece != ChessPiece::Empty)
        {
            const auto pieceBitBoard = GetBitboard(fixedBoardPosition);
            board.BitBoard[piece] |= pieceBitBoard;
            board.ArrayBoard[fixedBoardPosition] = piece;
            board.PieceCounts[piece]++;
            if (piece == ChessPiece::WhiteKing)
            {
                board.KingPositions[ChessPiece::White] = fixedBoardPosition;
            }
            else if (piece == ChessPiece::BlackKing)
            {
                board.KingPositions[ChessPiece::Black] = fixedBoardPosition;
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
        board.ColorToMove = ChessPiece::White;
        board.WhiteToMove = true;
        break;
    case 'b':
        board.ColorToMove = ChessPiece::Black;
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
            board.CastlingPermissions |= ChessCastlingPermissions::WhiteKing;
            break;
        case 'Q':
            board.CastlingPermissions |= ChessCastlingPermissions::WhiteQueen;
            break;
        case 'k':
            board.CastlingPermissions |= ChessCastlingPermissions::BlackKing;
            break;
        case 'q':
            board.CastlingPermissions |= ChessCastlingPermissions::BlackQueen;
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


    board.SyncExtraBitBoards();
    SyncMaterial(board);
    board.Key = ZobristKeys.CalculateKey(board);
}

char PieceToChar(Piece piece)
{
    switch (piece)
    {
    case ChessPiece::Empty: return '\0';
    case ChessPiece::WhitePawn: return 'P';
    case ChessPiece::WhiteKnight: return 'N';
    case ChessPiece::WhiteBishop: return 'B';
    case ChessPiece::WhiteRook: return 'R';
    case ChessPiece::WhiteQueen: return 'Q';
    case ChessPiece::WhiteKing: return 'K';
    case ChessPiece::BlackPawn: return 'p';
    case ChessPiece::BlackKnight: return 'n';
    case ChessPiece::BlackBishop: return 'b';
    case ChessPiece::BlackRook: return 'r';
    case ChessPiece::BlackQueen: return 'q';
    case ChessPiece::BlackKing: return 'k';
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
    if (board.CastlingPermissions == ChessCastlingPermissions::None)
    {
        builder << "-";
    }
    else
    {
        if ((board.CastlingPermissions & ChessCastlingPermissions::WhiteKing) != ChessCastlingPermissions::None)
        {
            builder << "K";
        }
        if ((board.CastlingPermissions & ChessCastlingPermissions::WhiteQueen) != ChessCastlingPermissions::None)
        {
            builder << "Q";
        }
        if ((board.CastlingPermissions & ChessCastlingPermissions::BlackKing) != ChessCastlingPermissions::None)
        {
            builder << "k";
        }
        if ((board.CastlingPermissions & ChessCastlingPermissions::BlackQueen) != ChessCastlingPermissions::None)
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