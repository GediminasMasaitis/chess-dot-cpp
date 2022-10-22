#pragma once

#include "displayeval.h"
#include "search.h"

class DisplaySearch
{
    static void PrintEndResult(const Search& search, const Score score)
    {
        std::stringstream builder = std::stringstream();
        builder << score << ",";
        const auto& principalVariation = search.State.Thread[0].SavedPrincipalVariations[0];
        for (size_t ply = 0; ply < principalVariation.Length; ply++)
        {
            const auto& entry = principalVariation.Moves[ply];
            builder << " " << entry.ToPositionString();
        }
        builder << "\n";
        std::cout << builder.str();
    }

public:
    static void DisplayBoard(const Board& board, const SearchParameters& parameters, const std::optional<Move> optMove = {})
    {
        DisplayData data;
        data.HasSearchData = true;

        Board clone = board;

        //Bitboard checkers = CheckDetector::GetCheckers(clone);
        //clone.WhiteToMove = !clone.WhiteToMove;
        //clone.ColorToMove ^= 1;
        //checkers |= CheckDetector::GetCheckers(clone);
        //clone.WhiteToMove = !clone.WhiteToMove;
        //clone.ColorToMove ^= 1;

        //EachColor<Bitboard> pins;
        //PinDetector::GetPinnedToKings(board, pins);
        Search search = Search(nullptr);
        search.State.NewGame();
        search.State.NewSearch(clone, parameters);

        std::cout << "Initial search... Score: ";
        SearchResults initialResults;
        search.Run(clone, parameters, initialResults);
        Score score = board.WhiteToMove ? initialResults.SScore : static_cast<Score>(-initialResults.SScore);
        data.SearchScore = score;
        PrintEndResult(search, score);

        for (Position pos = 0; pos < Positions::Count; pos++)
        {
            const Piece piece = board.ArrayBoard[pos];
            if (piece == Pieces::Empty)
            {
                continue;
            }

            if(piece >= Pieces::King)
            {
                continue;
            }

            auto& posData = data.Positions[pos];

            //const Bitboard posBitboard = GetBitboard(pos);
            //const Color color = piece & Colors::Mask;

            clone.UnsetPiece(pos);

            //EachColor<Bitboard> noPiecePins;
            //PinDetector::GetPinnedToKings(clone, noPiecePins);

            const auto posStr = Positions::PositionToText(pos);
            const auto pieceChar = Pieces::CharMap[piece];
            std::cout << "Searching without " << pieceChar << " " << posStr << "... Piece value: ";

            SearchResults results;
            search.State.NewGame();
            search.State.NewSearch(clone, parameters);
            search.Run(clone, parameters, results);
            Score noPieceScore = results.SScore;

            noPieceScore = board.WhiteToMove ? noPieceScore : static_cast<Score>(-noPieceScore);
            const Score difference = static_cast<Score>(score - noPieceScore);
            posData.SearchDiff = difference;

            PrintEndResult(search, difference);

            //posData.GivesCheck = (checkers & posBitboard) != 0;
            //posData.Pinned = (pins[color] & posBitboard) != 0;

            clone.SetPiece(pos, piece);
        }

        DisplayEval::DisplayBoard(board, data, optMove);
    }
};