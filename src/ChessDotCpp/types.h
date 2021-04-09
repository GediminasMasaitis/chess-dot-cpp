#pragma once

#include <cstdint>
#include <string>

using Piece = uint8_t;
using Position = uint8_t;
using Bitboard = uint64_t;
using File = int8_t;
using Rank = int8_t;
using Ply = int16_t;
using Material = int32_t;
using CastlingPermission = uint8_t;
using MoveValue = uint32_t;
using Score = int32_t;
using ZobristKey = uint64_t;

using Fen = std::string;
