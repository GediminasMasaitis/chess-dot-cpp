#include "evaluationNnue.h"

#include "nncpuprobe/nncpu.h"

static constexpr EachPiece<int> PieceMap { 0, 0, 0, 0, wpawn, bpawn, wknight, bknight, wbishop, bbishop, wrook, brook, wqueen, bqueen, wking, bking };

void SetAllPieces(const Board& board, NncpuPosition& position)
{
    position.squares[0] = board.KingPositions[Colors::White];
    position.squares[1] = board.KingPositions[Colors::Black];

    auto currentIndex = 2;
    
    for (Piece piece = Pieces::WhitePawn; piece <= Pieces::BlackQueen; piece++)
    {
        Bitboard bitboard = board.BitBoard[piece];
        while(bitboard != 0)
        {
            const Position pos = BitScanForward(bitboard);
            position.pieces[currentIndex] = PieceMap[piece];
            position.squares[currentIndex] = pos;
            currentIndex++;
            bitboard &= bitboard - 1;
        }
    }

    position.pieces[currentIndex] = 0;
    position.squares[currentIndex] = 0;

    /*for (; currentIndex < 33; currentIndex++)
    {
        position.pieces[currentIndex] = 0;
        position.squares[currentIndex] = 0;
    }*/
}

void UpdateCurrentPosition(const Board& board, NncpuPosition& position)
{
    position.player = board.ColorToMove;

    SetAllPieces(board, position);

    //for (int i = board.NnueData.Ply; i >= 0; i--)
    //int nnueEntryIndex = 0;
    //for (; nnueEntryIndex < 3; nnueEntryIndex++)
    //{
    //    var boardIndex = board.NnueData.Ply - nnueEntryIndex;
    //    if (boardIndex < 0)
    //    {
    //        break;
    //    }

    //    //_position.nnue[nnueEntryIndex] = new NnueNnueData();
    //    _position.Nnue[nnueEntryIndex].accumulator = board.NnueData.Accumulators[boardIndex];
    //    _position.Nnue[nnueEntryIndex].dirtyPiece = board.NnueData.Dirty[boardIndex];
    //}
    //_position.NnueCount = nnueEntryIndex;
}

Score EvaluateInner(const Board& board)
{
    NNCPUdata data;
    NncpuPosition position;
    position.pieces[0] = wking;
    position.pieces[1] = bking;
    data.accumulator.computedAccumulation = 0;
    for (auto i = 0; i < 3; i++)
    {
        position.nncpu[i] = &data;
    }

    UpdateCurrentPosition(board, position);
    const auto originalScore = nncpu_evaluate_pos(&position);
    const Score score = static_cast<Score>(originalScore / 2);
    return score;
}

Score EvaluationNnue::Evaluate(const Board& board, const EachColor<Bitboard>& pins, EvalState& state)
{
    PhaseScore score;
    if (state.EvalTable.TryProbe(board.Key, score))
    {
        return static_cast<Score>(score);
    }

    score = EvaluateInner(board);
    state.EvalTable.Store(board.Key, score);

    return static_cast<Score>(score);
}

void EvaluationNnue::Init()
{
    //nncpu_init("C:/temp/nn-62ef826d1a6d.nnue");
    nncpu_init("C:/Chess/TrainingOld/out/default/version_0/checkpoints/nn.nnue");
    
}
