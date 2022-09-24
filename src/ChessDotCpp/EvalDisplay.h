#pragma once

#include "display.h"

class DisplayExtra
{
    static void UnsetPiece(BoardBase& clone, const Position pos)
    {
        const Piece piece = clone.ArrayBoard[pos];
        const Bitboard posBitboard = GetBitboard(pos);
        const Color color = piece & Colors::Mask;

        clone.ArrayBoard[pos] = Pieces::Empty;
        clone.BitBoard[piece] &= ~posBitboard;
        clone.BitBoard[color] &= ~posBitboard;
        clone.AllPieces &= ~posBitboard;
        clone.PieceCounts[piece]--;
        clone.UnsetAccumulatorPiece(pos, piece);
    }

    static void SetPiece(BoardBase& clone, const Position pos)
    {
        const Piece piece = clone.ArrayBoard[pos];
        const Bitboard posBitboard = GetBitboard(pos);
        const Color color = piece & Colors::Mask;

        clone.ArrayBoard[pos] = piece;
        clone.BitBoard[piece] |= posBitboard;
        clone.BitBoard[color] |= posBitboard;
        clone.AllPieces |= posBitboard;
        clone.PieceCounts[piece]++;
        clone.SetAccumulatorPiece(pos, piece);
    }

public:
    static void DisplayBoard(const BoardBase& board, const std::optional<Move> optMove = {})
    {
        BoardBase clone = board;

        Bitboard checkers = CheckDetector::GetCheckers(clone);
        clone.WhiteToMove = !clone.WhiteToMove;
        clone.ColorToMove ^= 1;
        checkers |= CheckDetector::GetCheckers(clone);
        clone.WhiteToMove = !clone.WhiteToMove;
        clone.ColorToMove ^= 1;

        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);

        Score eval = CallEval(board, pins);
        eval = board.WhiteToMove ? eval : static_cast<Score>(-eval);

        DisplayData data;
        data.HasPositionData = true;

        for(Position pos = 0; pos < Positions::Count; pos++)
        {
            const Piece piece = board.ArrayBoard[pos];
            if(piece == Pieces::Empty)
            {
                return;
            }

            auto& posData = data.Positions[pos];

            const Bitboard posBitboard = GetBitboard(pos);
            const Color color = piece & Colors::Mask;

            UnsetPiece(clone, pos);

            EachColor<Bitboard> noPiecePins;
            PinDetector::GetPinnedToKings(clone, noPiecePins);
            Score noPieceEval = CallEval(clone, noPiecePins);
            noPieceEval = board.WhiteToMove ? noPieceEval : static_cast<Score>(-noPieceEval);
            const Score difference = static_cast<Score>(eval - noPieceEval);
            posData.EvalDiff = difference;
            posData.GivesCheck = (checkers & posBitboard) != 0;
            posData.Pinned = (pins[color] & posBitboard) != 0;

            SetPiece(clone, pos);
        }

        Display::DisplayBoard(board, optMove, data);
    }
};