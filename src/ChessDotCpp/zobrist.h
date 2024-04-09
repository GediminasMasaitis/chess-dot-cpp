#pragma once

#include <array>
#include <random>

#include "constants.h"
#include "random.h"

class ZobristKeysClass
{
public:
    EachPosition<EachPiece<ZobristKey>> ZPieces {};
    std::array<ZobristKey, 8> ZEnPassant {};
    std::array<ZobristKey, CastlingPermissions::All + 1> ZCastle {};
    ZobristKey ZWhiteToMove {};

    constexpr ZobristKeysClass()
    {
        //auto rng = std::mt19937_64(0);
        auto rng = PRNG();

        for (Position position = 0; position < Positions::Count; position++)
        {
            for (Piece piece = 0; piece < Pieces::Count; piece++)
            {
                ZPieces[position][piece] = static_cast<ZobristKey>(rng.rand64());
            }
        }

        for (File file = 0; file < Files::Count; file++)
        {
            ZEnPassant[file] = static_cast<ZobristKey>(rng.rand64());
        }

        constexpr auto castleLength = CastlingPermissions::All + 1;
        ZCastle[CastlingPermissions::WhiteQueen] = static_cast<ZobristKey>(rng.rand64());
        ZCastle[CastlingPermissions::WhiteKing] = static_cast<ZobristKey>(rng.rand64());
        ZCastle[CastlingPermissions::BlackQueen] = static_cast<ZobristKey>(rng.rand64());
        ZCastle[CastlingPermissions::BlackKing] = static_cast<ZobristKey>(rng.rand64());
        for (int i = 1; i < castleLength; i++)
        {
            if
                (
                    i == CastlingPermissions::WhiteQueen
                    || i == CastlingPermissions::WhiteKing
                    || i == CastlingPermissions::BlackQueen
                    || i == CastlingPermissions::BlackKing
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

        ZWhiteToMove = static_cast<ZobristKey>(rng.rand64());
    }

    [[nodiscard]] constexpr ZobristKey CalculateKey(const BoardBase& board) const
    {
        ZobristKey key = 0;
        for (Position i = 0; i < Positions::Count; i++)
        {
            const Piece piece = board.ArrayBoard[i];
            if (piece != Pieces::Empty)
            {
                key ^= ZPieces[i][piece];
            }
        }

        if (board.EnPassantFileIndex >= 0)
        {
            key ^= ZEnPassant[board.EnPassantFileIndex];
        }

        if ((board.CastlingPermissions & CastlingPermissions::WhiteQueen) != CastlingPermissions::None)
        {
            key ^= ZCastle[CastlingPermissions::WhiteQueen];
        }
        if ((board.CastlingPermissions & CastlingPermissions::WhiteKing) != CastlingPermissions::None)
        {
            key ^= ZCastle[CastlingPermissions::WhiteKing];
        }
        if ((board.CastlingPermissions & CastlingPermissions::BlackQueen) != CastlingPermissions::None)
        {
            key ^= ZCastle[CastlingPermissions::BlackQueen];
        }
        if ((board.CastlingPermissions & CastlingPermissions::BlackKing) != CastlingPermissions::None)
        {
            key ^= ZCastle[CastlingPermissions::BlackKing];
        }

        if (board.WhiteToMove)
        {
            key ^= ZWhiteToMove;
        }

        return key;
    }

    [[nodiscard]] constexpr ZobristKey CalculatePawnKey(const BoardBase& board) const
    {
        ZobristKey key = 0;
        for (Position i = 0; i < Positions::Count; i++)
        {
            const Piece piece = board.ArrayBoard[i];
            if ((piece & ~Pieces::Color) == Pieces::Pawn)
            {
                key ^= ZPieces[i][piece];
            }
        }
        return key;
    }

    [[nodiscard]] constexpr ZobristKey GetMoveKey(const MoveValue moveValue) const
    {
    	if(moveValue == 0)
    	{
            return 0;
    	}
    	
        return moveValue * 6364136223846793005ULL + 1442695040888963407ULL;
    }

    [[nodiscard]] constexpr ZobristKey GetSingularKey(const ZobristKey boardKey, const MoveValue singularValue) const
    {
        //const auto singularKey = GetMoveKey(singularValue);
        return boardKey ^ singularValue;
    }
};

constexpr ZobristKeysClass ZobristKeys = ZobristKeysClass();