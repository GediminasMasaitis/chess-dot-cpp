#pragma once

#include "common.h"
#include "board.h"
#include "attacks.h"

class See
{
    static constexpr EachPiece<Score> SeeWeights{ 0, 0, 0, 0, 100, 100, 325, 325, 325, 325, 500, 500, 975, 975, 0, 0 };

    static Bitboard GetLeastValuablePiece(const Board& board, Bitboard attadef, Color colorToMove, Piece& piece)
    {
        const Piece start = static_cast<Piece>(Pieces::Pawn | colorToMove);
        const Piece end = static_cast<Piece>(Pieces::Pawn | colorToMove);
        for (piece = start; piece <= end; piece += Pieces::NextPiece)
        {
            Bitboard subset = attadef & board.BitBoard[piece];
            if (subset > 0)
            {
                const Bitboard singleBitboard = static_cast<Bitboard>(static_cast<int64_t>(subset) & -static_cast<int64_t>(subset));
                return singleBitboard;
            }
        }
        
        return 0UL;
    }

public:
    static Score GetSee(const Board& board, const Position from, const Position to, Piece piece, const Piece takesPiece)
    {
        std::array<Score, 32> gain{};

        Ply depth = 0;
        Bitboard fromSet = GetBitboard(from);
        Bitboard occ = board.AllPieces;
        Color colorToMove = board.ColorToMove;
        gain[depth] = SeeWeights[takesPiece];
        do
        {
            depth++; // next depth and side
            gain[depth] = SeeWeights[piece] - gain[depth - 1]; // speculative store, if defended
            if (std::max(static_cast<Score>(-gain[depth - 1]), gain[depth]) < 0)
            {
                //break; // pruning does not influence the result
            }

            occ ^= fromSet;
            const Bitboard attadef = AttacksGenerator::GetAttackersOf(board, to, occ) & occ;
            colorToMove ^= 1;
            fromSet = GetLeastValuablePiece(board, attadef, colorToMove, piece);
        } while (fromSet != 0);

        while (--depth != 0)
        {
            gain[depth - 1] = -std::max(static_cast<Score>(-gain[depth - 1]), gain[depth]);
        }

        return gain[0];
    }

    static Score GetSee(const Board& board, const Move move)
    {
        assert(move.GetTakesPiece() != Pieces::Empty);

        return GetSee(board, move.GetFrom(), move.GetTo(), move.GetPiece(), move.GetTakesPiece());
    }
    
    static void CalculateSeeScores(const Board& board, const MoveArray& moves, const MoveCount moveCount, MoveScoreArray& seeScores)
    {
        for (MoveCount i = 0; i < moveCount; i++)
        {
            const auto move = moves[i];
            if (move.GetTakesPiece() != Pieces::Empty)
            {
                seeScores[i] = GetSee(board, move);
            }
            else
            {
                seeScores[i] = 0;
            }
        }
    }
};