#include "moveorder.h"

MoveScore CalculateStaticMoveScore(const Move move, const SearchState& state, const Ply ply, const Move pvMove)
{
    const bool isPrincipalVariation = move.Value == pvMove.Value;
    if (isPrincipalVariation)
    {
        return 200'000'000;
    }

    const Piece takes = move.GetTakesPiece();
    if(takes != Pieces::Empty)
    {
        return 100'000'000;
    }
    
    const PlyData& plyData = state.Thread[0].Plies[ply];

    if(move.Value == plyData.Killers[0].Value)
    {
        return 9'000'000;
    }
    
    if (move.Value == plyData.Killers[1].Value)
    {
        return 8'000'000;
    }

    return 0;
}

void MoveOrdering::CalculateStaticScores(const SearchState& state, const MoveArray& moves, const MoveCount moveCount, const Ply ply, const Move pvMove, MoveScoreArray& staticScores)
{
    for (MoveCount i = 0; i < moveCount; i++)
    {
        const MoveScore score = CalculateStaticMoveScore(moves[i], state, ply, pvMove);
        staticScores[i] = score;
    }
}

void MoveOrdering::OrderNextMove(const SearchState& state, const MoveCount currentIndex, MoveArray& moves, MoveScoreArray& staticScores, const MoveCount moveCount)
{
    MoveScore bestScore = std::numeric_limits<MoveScore>::min();
    MoveCount bestScoreIndex = 0;
    
    for(MoveCount i = currentIndex; i < moveCount; i++)
    {
        const MoveScore staticScore = staticScores[i];
        const MoveScore score = staticScore;
        if(score > bestScore)
        {
            bestScore = score;
            bestScoreIndex = i;
        }
    }

    const Move tempMove = moves[currentIndex];
    moves[currentIndex] = moves[bestScoreIndex];
    moves[bestScoreIndex] = tempMove;
    
    const MoveScore tempScore = staticScores[currentIndex];
    staticScores[currentIndex] = staticScores[bestScoreIndex];
    staticScores[bestScoreIndex] = tempScore;
}
