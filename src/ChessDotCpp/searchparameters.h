#pragma once

class SearchParameters
{
public:
    bool Infinite = false;
    bool UciThread = false;
    Ply MaxDepth = Constants::MaxDepth;

    size_t WhiteTime = 1000000;
    size_t BlackTime = 1000000;

    size_t WhiteTimeIncrement = 10000;
    size_t BlackTimeIncrement = 10000;

    size_t MinNodes = 0;
    size_t MaxNodes = 0;

    MoveArray SearchMoves;
    MoveCount SearchMoveCount = 0;

    bool SkipNewSearch = false;
};