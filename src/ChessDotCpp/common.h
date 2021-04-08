#pragma once

#include "constants.h"

#include <array>
#include <cassert>

constexpr Bitboard GetBitboard(const Position position)
{
	return 1ULL << position;
}

#if defined(__GNUC__)

constexpr Position BitScanForward(const Bitboard bitboard)
{
	return static_cast<Position>(__builtin_ctzll(bitboard));
}

//#elif defined(_MSC_VER)
//
//constexpr Position BitScanForward(const Bitboard bitboard)
//{
//	unsigned long result;
//	_BitScanForward64(&result, bitboard);
//	return static_cast<Position>(result);
//}

#else

constexpr std::array<uint8_t, 64> BitScanTable = {
	0, 47,  1, 56, 48, 27,  2, 60,
	57, 49, 41, 37, 28, 16,  3, 61,
	54, 58, 35, 52, 50, 42, 21, 44,
	38, 32, 29, 23, 17, 11,  4, 62,
	46, 55, 26, 59, 40, 36, 15, 53,
	34, 51, 20, 43, 31, 22, 10, 45,
	25, 39, 14, 33, 19, 30,  9, 24,
	13, 18,  8, 12,  7,  6,  5, 63
};

constexpr Position BitScanForward(const Bitboard bitboard)
{
	constexpr uint64_t debruijn64 = 0x03f79d71b4cb0a89UL;
	if (bitboard == 0)
	{
		return 64;
	}

	return BitScanTable[((bitboard ^ (bitboard - 1)) * debruijn64) >> 58];
}

#endif

constexpr Bitboard ReverseBits(Bitboard bitboard)
{
	const Bitboard h1 = 0x5555555555555555;
	const Bitboard h2 = 0x3333333333333333;
	const Bitboard h4 = 0x0F0F0F0F0F0F0F0F;
	const Bitboard v1 = 0x00FF00FF00FF00FF;
	const Bitboard v2 = 0x0000FFFF0000FFFF;
	bitboard = ((bitboard >> 1) & h1) | ((bitboard & h1) << 1);
	bitboard = ((bitboard >> 2) & h2) | ((bitboard & h2) << 2);
	bitboard = ((bitboard >> 4) & h4) | ((bitboard & h4) << 4);
	bitboard = ((bitboard >> 8) & v1) | ((bitboard & v1) << 8);
	bitboard = ((bitboard >> 16) & v2) | ((bitboard & v2) << 16);
	bitboard = (bitboard >> 32) | (bitboard << 32);
	return bitboard;
}