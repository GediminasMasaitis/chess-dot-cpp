#pragma once

#include <array>
#include <random>

#include "constants.h"

class ZobristKeysClass
{
public:
    std::array<std::array<ZobristKey, ChessPiece::Count>, 64> ZPieces {};
    std::array<ZobristKey, 8> ZEnPassant {};
    std::array<ZobristKey, ChessCastlingPermissions::All + 1> ZCastle {};
    ZobristKey ZWhiteToMove {};

    ZobristKeysClass()
    {
        auto rng = std::mt19937_64(0);

        for (auto i = 0; i < 64; i++)
        {
            for (auto j = 0; j < 13; j++)
            {
                ZPieces[i][j] = static_cast<ZobristKey>(rng());
            }
        }

        for (auto i = 0; i < 8; i++)
        {
            ZEnPassant[i] = static_cast<ZobristKey>(rng());
        }

        constexpr auto castleLength = ChessCastlingPermissions::All + 1;
        ZCastle[ChessCastlingPermissions::WhiteQueen] = static_cast<ZobristKey>(rng());
        ZCastle[ChessCastlingPermissions::WhiteKing] = static_cast<ZobristKey>(rng());
        ZCastle[ChessCastlingPermissions::BlackQueen] = static_cast<ZobristKey>(rng());
        ZCastle[ChessCastlingPermissions::BlackKing] = static_cast<ZobristKey>(rng());
        for (int i = 1; i < castleLength; i++)
        {
            if
                (
                    i == ChessCastlingPermissions::WhiteQueen
                    || i == ChessCastlingPermissions::WhiteKing
                    || i == ChessCastlingPermissions::BlackQueen
                    || i == ChessCastlingPermissions::BlackKing
                    )
            {
                continue;
            }

            uint64_t key = 0ULL;
            for (int j = 0; j < 4; j++)
            {
                const auto existingCastleIndex = 1 << j;
                const auto bitSet = (i & existingCastleIndex) != 0;
                if (bitSet)
                {
                    key ^= ZCastle[existingCastleIndex];
                }
            }
            ZCastle[i] = key;
        }

        ZWhiteToMove = static_cast<ZobristKey>(rng());
    }

    ZobristKey CalculateKey(Board& board)
    {
        ZobristKey key = 0;
        for (Position i = 0; i < 64; i++)
        {
            Piece piece = board.ArrayBoard[i];
            if (piece != ChessPiece::Empty)
            {
                key ^= ZPieces[i][piece];
            }
        }

        if (board.EnPassantFileIndex >= 0)
        {
            key ^= ZEnPassant[board.EnPassantFileIndex];
        }

        if ((board.CastlingPermissions & ChessCastlingPermissions::WhiteQueen) != ChessCastlingPermissions::None)
        {
            key ^= ZCastle[ChessCastlingPermissions::WhiteQueen];
        }
        if ((board.CastlingPermissions & ChessCastlingPermissions::WhiteKing) != ChessCastlingPermissions::None)
        {
            key ^= ZCastle[ChessCastlingPermissions::WhiteKing];
        }
        if ((board.CastlingPermissions & ChessCastlingPermissions::BlackQueen) != ChessCastlingPermissions::None)
        {
            key ^= ZCastle[ChessCastlingPermissions::BlackQueen];
        }
        if ((board.CastlingPermissions & ChessCastlingPermissions::BlackKing) != ChessCastlingPermissions::None)
        {
            key ^= ZCastle[ChessCastlingPermissions::BlackKing];
        }

        if (board.WhiteToMove)
        {
            key ^= ZWhiteToMove;
        }

        return key;
    }
};

inline ZobristKeysClass ZobristKeys = ZobristKeysClass();