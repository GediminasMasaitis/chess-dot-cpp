#pragma once

#include "board.h"

#include <string>


class MoveAndNodes
{
public:
    std::string MovePos;
    int Nodes;
    Move EngineMove;

    MoveAndNodes(std::string move, int nodes, Move engineMove = Move(0))
    {
        MovePos = move;
        Nodes = nodes;
        EngineMove = engineMove;
    }

    MoveAndNodes()
    {
        
    }
};

using MoveAndNodeArray = std::array<MoveAndNodes, Constants::MaxMoves>;

class InternalPerftClient
{
public:
    static size_t GetMovesAndNodes(Board& board, Ply depth, MoveAndNodeArray& movesAndNodes, size_t& moveAndNodeCount);
};