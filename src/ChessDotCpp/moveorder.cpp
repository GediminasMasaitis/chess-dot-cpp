#include "moveorder.h"

class MvvLvaClass
{
public:
    EachPiece<EachPiece<MoveScore>> Values{};

    constexpr MvvLvaClass()
    {
        constexpr EachPiece<MoveScore> pieceScores{ 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

        for (size_t i = 0; i < Pieces::Count; i++)
        {
            for (size_t j = 1; j < Pieces::Count; j++)
            {
                MoveScore score = (pieceScores[j] * 10) + (6 - pieceScores[i]);
                score *= 10'000'000;
                score += 500'000'000;
                Values[i][j] = score;
            }
        }
    }
};

constexpr MvvLvaClass MvvLva = MvvLvaClass();

MoveScore CalculateStaticMoveScore(const Move move, const Score seeScore, const SearchState& state, const Ply ply, const Move pvMove, const Move countermove)
{
    const bool isPrincipalVariation = move.Value == pvMove.Value;
    if (isPrincipalVariation)
    {
        return 1'000'000'000;
    }

    const Piece takes = move.GetTakesPiece();
    if(takes != Pieces::Empty)
    {
        const MoveScore mvvLvaScore = MvvLva.Values[move.GetPiece()][move.GetTakesPiece()];
    	if(seeScore > 0)
    	{
            return mvvLvaScore;
    	}
    	if(seeScore == 0)
    	{
            return mvvLvaScore / 2;
    	}
        return mvvLvaScore - 2'000'000'000;
    }
    
    const PlyData& plyData = state.Thread[0].Plies[ply];

    if(move.Value == plyData.Killers[0].Value)
    {
        return 90'000'000;
    }
    
    if (move.Value == plyData.Killers[1].Value)
    {
        return 80'000'000;
    }

    if(move.Value == countermove.Value)
    {
        return 70'000'000;
    }

    return 0;
}

void MoveOrdering::CalculateStaticScores(const SearchState& state, const MoveArray& moves, const ScoreArray& seeScores, const MoveCount moveCount, const Ply ply, const Move pvMove, const Move countermove, MoveScoreArray& staticScores)
{
    for (MoveCount i = 0; i < moveCount; i++)
    {
        const Score seeScore = seeScores[i];
        const MoveScore score = CalculateStaticMoveScore(moves[i], seeScore, state, ply, pvMove, countermove);
        staticScores[i] = score;
    }
}

void MoveOrdering::OrderNextMove(const SearchState& state, const MoveCount currentIndex, MoveArray& moves, ScoreArray& seeScores, MoveScoreArray& staticScores, const MoveCount moveCount)
{
    const ThreadData& threadState = state.Thread[0];
    
    MoveScore bestScore = std::numeric_limits<MoveScore>::min();
    MoveCount bestScoreIndex = 0;
    
    for(MoveCount i = currentIndex; i < moveCount; i++)
    {
        const MoveScore staticScore = staticScores[i];
        MoveScore score = staticScore;
        const Move move = moves[i];
    	
        if(move.GetTakesPiece() != Pieces::Empty)
        {
            score += threadState.CaptureHistory[move.GetPiece()][move.GetTo()][move.GetTakesPiece()];
        }
        else if(score == 0)
        {
            const MoveScore history = threadState.History[move.GetColorToMove()][move.GetFrom()][move.GetTo()];
            score = history;
        }
    	
        if(score > bestScore)
        {
            bestScore = score;
            bestScoreIndex = i;
        }
    }

    const Move tempMove = moves[currentIndex];
    moves[currentIndex] = moves[bestScoreIndex];
    moves[bestScoreIndex] = tempMove;

    const Score tempSee = seeScores[currentIndex];
    seeScores[currentIndex] = seeScores[bestScoreIndex];
    seeScores[bestScoreIndex] = tempSee;
    
    const MoveScore tempScore = staticScores[currentIndex];
    staticScores[currentIndex] = staticScores[bestScoreIndex];
    staticScores[bestScoreIndex] = tempScore;
}
