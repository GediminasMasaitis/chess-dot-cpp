#pragma once

#include <cstdint>
#include <string>

using Color = uint8_t;
using Piece = uint8_t;
using Position = uint8_t;
using Bitboard = uint64_t;
using File = int8_t;
using Rank = int8_t;
using Diagonal = int8_t;
using Antidialgonal = int8_t;
using Ply = int8_t;
using HistoryPly = uint16_t;
using CastlingPermission = uint8_t;
using MoveValue = uint32_t;
using MoveString = std::string;
using MoveCount = uint8_t;
using Score = int16_t;
using MoveScore = int32_t;
using Phase = int32_t;
using Tropism = int8_t;
using ZobristKey = uint64_t;
using Magic = uint64_t;
using Time = int32_t;
using Stat = uint64_t;
using TtFlag = uint8_t;

using Fen = std::string;