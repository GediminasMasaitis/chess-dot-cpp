#include "fen.h"

#include <regex>

#include "common.h"
#include "zobrist.h"

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
    board.WhiteMaterial = 0;
    board.BlackMaterial = 0;
    for (auto i = 1; i < 7; i++)
    {
        board.WhiteMaterial += board.PieceCounts[i] * EvaluationConstants::Weights[i];
    }
    for (auto i = 7; i < 13; i++)
    {
        board.BlackMaterial += board.PieceCounts[i] * EvaluationConstants::Weights[i];
    }
}

void Fens::Parse(Board& board, std::string fen)
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
            auto pieceBitBoard = GetBitboard(fixedBoardPosition);
            board.BitBoard[piece] |= pieceBitBoard;
            board.ArrayBoard[fixedBoardPosition] = piece;
            board.PieceCounts[piece]++;
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
    if (fen[fenPosition] == 'w')
    {
        board.WhiteToMove = true;
    }

    fenPosition += 2;

    for (auto i = 0; i < 4; i++)
    {
        if (fenPosition >= fen.size())
            break;
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
            throw std::exception("Unknown character in castling permissions");
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
