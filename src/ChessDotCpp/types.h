#pragma once

#include <cstdint>
#include <string>

using Color = uint8_t;
using Piece = uint8_t;
using HuffmanPieceValue = uint8_t;
using Position = uint8_t;
using Bitboard = uint64_t;
using File = int8_t;
using Rank = int8_t;
using Diagonal = int8_t;
using Antidialgonal = int8_t;
using Ply = int8_t;
using HistoryPly = int16_t;
using CastlingPermission = uint8_t;
using MoveValue = uint32_t;
using MoveString = std::string;
using MoveCount = uint8_t;
using Score = int16_t;
using MoveScore = int32_t;
using Tropism = int8_t;
using ZobristKey = uint64_t;
using Magic = uint64_t;
using Time = int32_t;
using Stat = uint64_t;
using TtFlag = uint8_t;
using ThreadId = int8_t;
using AbdadaMoveKey = uint64_t;

// Evaluation
using Phase = uint8_t;
using PhaseStage = uint8_t;
using PhaseScore = int32_t;

using Fen = std::string;
