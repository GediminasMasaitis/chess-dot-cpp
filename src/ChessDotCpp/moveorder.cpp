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

MoveScore CalculateStaticCaptureScore
(
    const ThreadState& threadState,
    const Move move,
    const Score seeScore
)
{
    const Piece takes = move.GetTakesPiece();
    const Piece piece = move.GetPiece();
    const Position to = move.GetTo();
    const MoveScore mvvLvaScore = MvvLva.Values[piece][takes];
    const MoveScore captureHistory = threadState.CaptureHistory[piece][to][takes];
    if (seeScore > 0)
    {
        return mvvLvaScore + captureHistory;
    }
    if (seeScore == 0)
    {
        return (mvvLvaScore / 2) + captureHistory;
    }
    return (mvvLvaScore - 2'000'000'000) + captureHistory;
}

void MoveOrdering::CalculateStaticCaptureScores(const ThreadState& threadState, const MoveArray& moves, const ScoreArray& seeScores, const MoveCount moveCount, MoveScoreArray& staticScores)
{
    for (MoveCount i = 0; i < moveCount; i++)
    {
        const Score seeScore = seeScores[i];
        const MoveScore score = CalculateStaticCaptureScore(threadState, moves[i], seeScore);
        staticScores[i] = score;
    }
}

void MoveOrdering::OrderNextCaptureMove(const MoveCount currentIndex, MoveArray& moves, ScoreArray& seeScores, MoveScoreArray& staticScores, const MoveCount moveCount)
{
    MoveScore bestScore = std::numeric_limits<MoveScore>::min();
    MoveCount bestScoreIndex = 0;

    for (MoveCount i = currentIndex; i < moveCount; i++)
    {
        const MoveScore staticScore = staticScores[i];
        const MoveScore score = staticScore;

        if (score > bestScore)
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

MoveScore CalculateStaticNonCaptureScore
(
    const ThreadState& threadState,
    const Move move,
    const Move countermove,
    const ContinuationEntry& continuation1,
    const ContinuationEntry& continuation2
)
{
    const Piece piece = move.GetPiece();
    const Position to = move.GetTo();

    if (move.Value == countermove.Value)
    {
        return 70'000'000;
    }

    const MoveScore history = threadState.History[move.GetColorToMove()][move.GetFrom()][to];
    const MoveScore continuationScore1 = continuation1.Scores[piece][to];
    const MoveScore continuationScore2 = continuation2.Scores[piece][to];
    const MoveScore score = history + continuationScore1 + continuationScore2;

    return score;
}

void MoveOrdering::CalculateStaticNonCaptureScores
(
    const ThreadState& threadState,
    const MoveArray& moves,
    const MoveCount moveCount,
    const Move countermove,
    MoveScoreArray& staticScores,
    const Board& board
)
{
    const Move previousMove1 = board.HistoryDepth > 0 ? board.History[board.HistoryDepth - 1].Move : Move(0);
    const Move previousMove2 = board.HistoryDepth > 1 ? board.History[board.HistoryDepth - 2].Move : Move(0);

    const ContinuationEntry& continuation1 = threadState.AllContinuations[previousMove1.GetPiece()][previousMove1.GetTo()];
    const ContinuationEntry& continuation2 = threadState.AllContinuations[previousMove2.GetPiece()][previousMove2.GetTo()];

    for (MoveCount i = 0; i < moveCount; i++)
    {
        const MoveScore score = CalculateStaticNonCaptureScore(threadState, moves[i], countermove, continuation1, continuation2);
        staticScores[i] = score;
    }
}

void MoveOrdering::OrderNextNonCaptureMove(const MoveCount currentIndex, MoveArray& moves, MoveScoreArray& staticScores, const MoveCount moveCount)
{
    MoveScore bestScore = std::numeric_limits<MoveScore>::min();
    MoveCount bestScoreIndex = 0;

    for (MoveCount i = currentIndex; i < moveCount; i++)
    {
        const MoveScore staticScore = staticScores[i];
        const MoveScore score = staticScore;

        if (score > bestScore)
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
