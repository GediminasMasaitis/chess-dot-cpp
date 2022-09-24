#pragma once

#include "display.h"

class DisplayEval
{
public:
    static void DisplayBoard(const BoardBase& board, DisplayData& data, const std::optional<Move> optMove = {})
    {
        data.HasEvalData = true;

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
        data.EvalScore = eval;

        for(Position pos = 0; pos < Positions::Count; pos++)
        {
            const Piece piece = board.ArrayBoard[pos];
            if(piece == Pieces::Empty)
            {
                continue;
            }

            auto& posData = data.Positions[pos];

            const Bitboard posBitboard = GetBitboard(pos);
            const Color color = piece & Colors::Mask;

            clone.UnsetPiece(pos);

            EachColor<Bitboard> noPiecePins;
            PinDetector::GetPinnedToKings(clone, noPiecePins);
            Score noPieceEval = CallEval(clone, noPiecePins);
            noPieceEval = board.WhiteToMove ? noPieceEval : static_cast<Score>(-noPieceEval);
            const Score difference = static_cast<Score>(eval - noPieceEval);
            posData.EvalDiff = difference;
            posData.GivesCheck = (checkers & posBitboard) != 0;
            posData.Pinned = (pins[color] & posBitboard) != 0;

            clone.SetPiece(pos, piece);
        }

        Display::DisplayBoard(board, optMove, data);
    }

    static void DisplayBoard(const BoardBase& board, const std::optional<Move> optMove = {})
    {
        DisplayData data;
        DisplayBoard(board, data, optMove);
    }
};