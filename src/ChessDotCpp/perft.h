#pragma once

#include "board.h"

#include <string>


class MoveAndNodes
{
public:
    std::string MovePos;
    size_t Nodes;
    Move EngineMove;

    MoveAndNodes(std::string move, size_t nodes, Move engineMove = Move(0))
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
using MoveStack = std::array<MoveArray, 10>;

class InternalPerftClient
{
public:
    static size_t GetMovesAndNodes(Board& board, Ply depth, MoveStack& moveStack,  MoveAndNodeArray& movesAndNodes, size_t& moveAndNodeCount);
};

class PerftRunner
{
public:
    static size_t Run(Board& board, Ply depth);
    static size_t Run(std::string fen, Ply depth);
};

class PerftSuite
{
public:
    static void Run();
};