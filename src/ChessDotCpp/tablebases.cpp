#include "tablebases.h"

#include "movegen.h"
#include "fathom/tbprobe.h"

void Tablebases::Init()
{
    tb_init("C:\\Chess\\Tablebases\\3-4-5piecesSyzygy\\3-4-5");
}

bool Tablebases::CanProbe(const Board& board)
{
    const auto pieceCount = PopCount(board.AllPieces);
    return pieceCount <= 5;
}


GameOutcome Tablebases::Probe(const Board& board)
{
    //const auto canProbe = CanProbe(board);
    //if (!canProbe)
    //{
    //    return TablebaseResult::Unknown;
    //}
    
    const HistoryPly rule50 = board.HistoryDepth - board.FiftyMoveRuleIndex;
    const auto externalResult = tb_probe_wdl
    (
        board.BitBoard[Colors::White],
        board.BitBoard[Colors::Black],
        board.BitBoard[Pieces::WhiteKing] | board.BitBoard[Pieces::BlackKing],
        board.BitBoard[Pieces::WhiteQueen] | board.BitBoard[Pieces::BlackQueen],
        board.BitBoard[Pieces::WhiteRook] | board.BitBoard[Pieces::BlackRook],
        board.BitBoard[Pieces::WhiteBishop] | board.BitBoard[Pieces::BlackBishop],
        board.BitBoard[Pieces::WhiteKnight] | board.BitBoard[Pieces::BlackKnight],
        board.BitBoard[Pieces::WhitePawn] | board.BitBoard[Pieces::BlackPawn],
        0, //static_cast<unsigned>(rule50), // 50 move
        0, // castling
        0, // en passant
        board.WhiteToMove // white to move
    );

    GameOutcome result;
    
    switch (externalResult)
    {
    case TB_LOSS:
    case TB_BLESSED_LOSS:
        result = GameOutcome::Loss;
        break;
    case TB_DRAW:
        result = GameOutcome::Draw;
        break;
    case TB_CURSED_WIN:
    case TB_WIN:
        result = GameOutcome::Win;
        break;
    case TB_RESULT_FAILED:
    default:
        Throw();
        result = GameOutcome::Loss;
        break;
    }

    return result;
}

Piece GetPromote(const Color colorToMove, const unsigned value)
{
    const auto externalPromote = TB_GET_PROMOTES(value);
    switch (externalPromote)
    {
    case TB_PROMOTES_NONE:
        return Pieces::Empty;
    case TB_PROMOTES_QUEEN:
        return Pieces::Queen | colorToMove;
    case TB_PROMOTES_KNIGHT:
        return Pieces::Knight | colorToMove;
    case TB_PROMOTES_ROOK:
        return Pieces::Rook | colorToMove;
    case TB_PROMOTES_BISHOP:
        return Pieces::Bishop | colorToMove;
    default:
        Throw();
    }

    return Pieces::Empty;
}

bool Tablebases::ProbeRoot(const Board& board, Move& tbMove)
{
    tbMove = Move(0);

 //   const auto canProbe = CanProbe(board);
    //if(!canProbe)
    //{
 //       return false;
    //}
    
    const HistoryPly rule50 = board.HistoryDepth - board.FiftyMoveRuleIndex;
    auto extraResults = std::array<unsigned, TB_MAX_MOVES>{};
    const auto externalResult = tb_probe_root
    (
        board.BitBoard[Colors::White],
        board.BitBoard[Colors::Black],
        board.BitBoard[Pieces::WhiteKing] | board.BitBoard[Pieces::BlackKing],
        board.BitBoard[Pieces::WhiteQueen] | board.BitBoard[Pieces::BlackQueen],
        board.BitBoard[Pieces::WhiteRook] | board.BitBoard[Pieces::BlackRook],
        board.BitBoard[Pieces::WhiteBishop] | board.BitBoard[Pieces::BlackBishop],
        board.BitBoard[Pieces::WhiteKnight] | board.BitBoard[Pieces::BlackKnight],
        board.BitBoard[Pieces::WhitePawn] | board.BitBoard[Pieces::BlackPawn],
        static_cast<unsigned>(rule50), // 50 move
        0, // castling
        0, // en passant
        board.WhiteToMove, // white to move
        extraResults.data()
    );

    auto wdl = TB_GET_WDL(externalResult);
    if(wdl != TB_WIN)
    {
        return false;
    }

    const auto from = static_cast<Position>(TB_GET_FROM(externalResult));
    const auto to = static_cast<Position>(TB_GET_TO(externalResult));
    const auto promote = GetPromote(board.ColorToMove, externalResult);
    const auto dtz = TB_GET_DTZ(externalResult);

    auto moves = MoveArray();
    MoveCount moveCount = 0;
    MoveGenerator::GetAllPotentialMoves(board, 0, 0, moves, moveCount);
        
    for(MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    {
        Move move = moves[moveIndex];
        if(move.GetFrom() != from)
        {
            continue;
        }
        if (move.GetTo() != to)
        {
            continue;
        }
        if(move.GetPawnPromoteTo() != promote)
        {
            continue;
        }

        tbMove = move;
        break;
    }
    assert(tbMove.Value != 0);
    return true;
}