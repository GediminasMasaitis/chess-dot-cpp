#pragma once

#include "common.h"
#include "fen.h"

class Display
{
public:
    using DisplayEvaluation = EvaluationNnue2;//EvaluationClassical2;

    static void DisplayBoard(const BoardBase& board, const bool evalPieces = true)
    {
        std::stringstream ss;

        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        Score eval = DisplayEvaluation::Evaluate(board, pins);
        eval = board.WhiteToMove ? eval : -eval;

        if (evalPieces)
        {
            BoardBase clone = board;

            auto checkers = CheckDetector::GetCheckers(clone);
            clone.WhiteToMove = !clone.WhiteToMove;
            clone.ColorToMove ^= 1;
            checkers |= CheckDetector::GetCheckers(clone);
            clone.WhiteToMove = !clone.WhiteToMove;
            clone.ColorToMove ^= 1;

            const std::string border = "+-------+-------+-------+-------+-------+-------+-------+-------+\n";
            for (auto rank = 7; rank >= 0; rank--)
            {
                ss << border;
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    const char pieceChar = Pieces::CharMap[piece];
                    ss << "|   " << pieceChar << "   ";
                }
                ss << "|\n";

                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    if (piece > Pieces::Empty && piece < Pieces::Count)
                    {
                        const Bitboard posBitboard = GetBitboard(pos);
                        const Color color = piece & Colors::Mask;
                        clone.ArrayBoard[pos] = Pieces::Empty;
                        clone.BitBoard[piece] &= ~posBitboard;
                        clone.BitBoard[color] &= ~posBitboard;
                        clone.AllPieces &= ~posBitboard;
                        clone.PieceCounts[piece]--;
                        clone.UnsetAccumulatorPiece(pos, piece);

                        EachColor<Bitboard> noPiecePins;
                        PinDetector::GetPinnedToKings(clone, noPiecePins);
                        Score noPieceEval = DisplayEvaluation::Evaluate(clone, noPiecePins);
                        noPieceEval = board.WhiteToMove ? noPieceEval : -noPieceEval;
                        const Score difference = static_cast<Score>(eval - noPieceEval);
                        const std::string diffStr = std::to_string(difference);
                        const auto padLeft = (7 - diffStr.size()) / 2;
                        const auto padRight = 7 - diffStr.size() - padLeft;

                        ss << "|";
                        for (auto i = 0; i < padLeft; i++)
                        {
                            ss << " ";
                        }
                        ss << diffStr;
                        for (auto i = 0; i < padRight; i++)
                        {
                            ss << " ";
                        }

                        clone.ArrayBoard[pos] = piece;
                        clone.BitBoard[piece] |= posBitboard;
                        clone.BitBoard[color] |= posBitboard;
                        clone.AllPieces |= posBitboard;
                        clone.PieceCounts[piece]++;
                        clone.SetAccumulatorPiece(pos, piece);
                    }
                    else
                    {
                        ss << "|       ";
                    }
                }
                ss << "| " << (rank + 1) << "\n";
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Bitboard posBitboard = GetBitboard(pos);
                    const Piece piece = board.ArrayBoard[pos];
                    const Color color = piece & Colors::Mask;

                    ss << "|";
                    if (pins[color] & posBitboard)
                    {
                        ss << "PIN";
                    }
                    else
                    {
                        ss << "   ";
                    }
                    ss << " ";
                    if (checkers & posBitboard)
                    {
                        ss << "CHK";
                    }
                    else
                    {
                        ss << "   ";
                    }
                }

                ss << "|\n";
            }
            ss << border << "";
            for (auto file = 0; file < 8; file++)
            {
                ss << "    " << static_cast<char>('A' + file) << "   ";
            }
            ss << "\n";
        }
        else
        {
            const std::string border = "+---+---+---+---+---+---+---+---+\n";
            for (auto rank = 7; rank >= 0; rank--)
            {
                ss << border;
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    const char pieceChar = Pieces::CharMap[piece];
                    ss << "| " << pieceChar << " ";
                }
                ss << "|\n";
            }
            ss << border << "";
        }

        const Fen fen = Fens::Serialize(board);
        ss << "Side: " << (board.WhiteToMove ? "White" : "Black") << "\n";
        ss << "FEN: " << fen << "\n";
        ss << "Key: " << board.Key << "\n";
        ss << "Eval: " << eval << "\n";
        //const PhaseScore phasedEval = DisplayEvaluation::EvaluatePhased(board, pins);
        //const PhaseScore flippedPhasedEval = phasedEval;//board.WhiteToMove ? static_cast<Score>(phasedEval) : -phasedEval;
        //ss << "Midgame: " << MgScore(flippedPhasedEval) << "\n";
        //ss << "Endgame: " << EgScore(flippedPhasedEval) << "\n";
        const int32_t phase = static_cast<int32_t>(GetPhase(board));
        ss << "Phase: " << phase << "\n";

        ss << "\n\n";
        std::cout << ss.str();
    }
};