#pragma once

#include "common.h"
#include "constants.h"

//#include "magicMoveboardFixed.h"

class HyperbolaQuintessence
{
private:
	constexpr static Bitboard MaskedSlide(const Bitboard allPieces, const Bitboard pieceBitboard, const Bitboard mask)
	{
		const auto left = ((allPieces & mask) - 2 * pieceBitboard);
		const auto right = ReverseBits(ReverseBits(allPieces & mask) - 2 * ReverseBits(pieceBitboard));
		const auto both = left ^ right;
		const auto slide = both & mask;
		return slide;
	}

public:
	constexpr static Bitboard HorizontalVerticalSlide(const Bitboard allPieces, const Position position)
	{
		const auto pieceBitboard = GetBitboard(position);
		const auto horizontal = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Ranks[position / 8]);
		const auto vertical = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Files[position % 8]);
		return horizontal | vertical;
	}

	constexpr static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position)
	{
		const auto pieceBitboard = GetBitboard(position);
		const auto horizontal = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Diagonals[position / 8 + position % 8]);
		const auto vertical = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Antidiagonals[position / 8 + 7 - position % 8]);
		return horizontal | vertical;
	}

	constexpr static Bitboard AllSlide(const Bitboard allPieces, const Position position)
	{
		const auto hv = HorizontalVerticalSlide(allPieces, position);
		const auto dad = DiagonalAntidiagonalSlide(allPieces, position);
		return hv | dad;
	}
};

template<bool TDiagonal>
class MagicsEntry
{
public:
	constexpr static bool Diagonal = TDiagonal;
	constexpr static uint8_t Shift = Diagonal ? 55 : 52;
	Bitboard BlockerMask;
	Magic MagicNumber;
	//size_t Offset;
	Bitboard* Attacks;

	[[nodiscard]] constexpr size_t GetLocalOffset(const Bitboard blockers) const
	{
		//const auto index = static_cast<size_t>(_pext_u64(blockers, BlockerMask));
		const auto index = static_cast<size_t>(((blockers & BlockerMask) * MagicNumber) >> Shift);
		return index;
	}
};

using BishopMagicsEntry = MagicsEntry<true>;
using RookMagicsEntry = MagicsEntry<false>;

class KnownMagic
{
public:
	Magic MagicNumber;
	size_t Position;
};

class MagicsDataClass
{
public:
	using BishopEntryArray = std::array<BishopMagicsEntry, 64>;
	using RookEntryArray = std::array<RookMagicsEntry, 64>;
	using MoveboardArray = std::array<Bitboard, 88772>;

	BishopEntryArray Bishops{};
	RookEntryArray Rooks{};
	MoveboardArray Table{};
	//bool Initialized;

private:
	using ReferenceGenerator = HyperbolaQuintessence;
	using KnownMagicsArray = std::array<KnownMagic, 64>;

	static constexpr KnownMagicsArray BishopMagics = KnownMagicsArray
	{
		KnownMagic { 0x007fbfbfbfbfbfffu,   5378 },
		KnownMagic { 0x0000a060401007fcu,   4093 },
		KnownMagic { 0x0001004008020000u,   4314 },
		KnownMagic { 0x0000806004000000u,   6587 },
		KnownMagic { 0x0000100400000000u,   6491 },
		KnownMagic { 0x000021c100b20000u,   6330 },
		KnownMagic { 0x0000040041008000u,   5609 },
		KnownMagic { 0x00000fb0203fff80u,  22236 },
		KnownMagic { 0x0000040100401004u,   6106 },
		KnownMagic { 0x0000020080200802u,   5625 },
		KnownMagic { 0x0000004010202000u,  16785 },
		KnownMagic { 0x0000008060040000u,  16817 },
		KnownMagic { 0x0000004402000000u,   6842 },
		KnownMagic { 0x0000000801008000u,   7003 },
		KnownMagic { 0x000007efe0bfff80u,   4197 },
		KnownMagic { 0x0000000820820020u,   7356 },
		KnownMagic { 0x0000400080808080u,   4602 },
		KnownMagic { 0x00021f0100400808u,   4538 },
		KnownMagic { 0x00018000c06f3fffu,  29531 },
		KnownMagic { 0x0000258200801000u,  45393 },
		KnownMagic { 0x0000240080840000u,  12420 },
		KnownMagic { 0x000018000c03fff8u,  15763 },
		KnownMagic { 0x00000a5840208020u,   5050 },
		KnownMagic { 0x0000020008208020u,   4346 },
		KnownMagic { 0x0000804000810100u,   6074 },
		KnownMagic { 0x0001011900802008u,   7866 },
		KnownMagic { 0x0000804000810100u,  32139 },
		KnownMagic { 0x000100403c0403ffu,  57673 },
		KnownMagic { 0x00078402a8802000u,  55365 },
		KnownMagic { 0x0000101000804400u,  15818 },
		KnownMagic { 0x0000080800104100u,   5562 },
		KnownMagic { 0x00004004c0082008u,   6390 },
		KnownMagic { 0x0001010120008020u,   7930 },
		KnownMagic { 0x000080809a004010u,  13329 },
		KnownMagic { 0x0007fefe08810010u,   7170 },
		KnownMagic { 0x0003ff0f833fc080u,  27267 },
		KnownMagic { 0x007fe08019003042u,  53787 },
		KnownMagic { 0x003fffefea003000u,   5097 },
		KnownMagic { 0x0000101010002080u,   6643 },
		KnownMagic { 0x0000802005080804u,   6138 },
		KnownMagic { 0x0000808080a80040u,   7418 },
		KnownMagic { 0x0000104100200040u,   7898 },
		KnownMagic { 0x0003ffdf7f833fc0u,  42012 },
		KnownMagic { 0x0000008840450020u,  57350 },
		KnownMagic { 0x00007ffc80180030u,  22813 },
		KnownMagic { 0x007fffdd80140028u,  56693 },
		KnownMagic { 0x00020080200a0004u,   5818 },
		KnownMagic { 0x0000101010100020u,   7098 },
		KnownMagic { 0x0007ffdfc1805000u,   4451 },
		KnownMagic { 0x0003ffefe0c02200u,   4709 },
		KnownMagic { 0x0000000820806000u,   4794 },
		KnownMagic { 0x0000000008403000u,  13364 },
		KnownMagic { 0x0000000100202000u,   4570 },
		KnownMagic { 0x0000004040802000u,   4282 },
		KnownMagic { 0x0004010040100400u,  14964 },
		KnownMagic { 0x00006020601803f4u,   4026 },
		KnownMagic { 0x0003ffdfdfc28048u,   4826 },
		KnownMagic { 0x0000000820820020u,   7354 },
		KnownMagic { 0x0000000008208060u,   4848 },
		KnownMagic { 0x0000000000808020u,  15946 },
		KnownMagic { 0x0000000001002020u,  14932 },
		KnownMagic { 0x0000000401002008u,  16588 },
		KnownMagic { 0x0000004040404040u,   6905 },
		KnownMagic { 0x007fff9fdf7ff813u,  16076 }
	};

	static constexpr KnownMagicsArray RookMagics = KnownMagicsArray
	{
		KnownMagic { 0x00280077ffebfffeu,  26304 },
		KnownMagic { 0x2004010201097fffu,  35520 },
		KnownMagic { 0x0010020010053fffu,  38592 },
		KnownMagic { 0x0040040008004002u,   8026 },
		KnownMagic { 0x7fd00441ffffd003u,  22196 },
		KnownMagic { 0x4020008887dffffeu,  80870 },
		KnownMagic { 0x004000888847ffffu,  76747 },
		KnownMagic { 0x006800fbff75fffdu,  30400 },
		KnownMagic { 0x000028010113ffffu,  11115 },
		KnownMagic { 0x0020040201fcffffu,  18205 },
		KnownMagic { 0x007fe80042ffffe8u,  53577 },
		KnownMagic { 0x00001800217fffe8u,  62724 },
		KnownMagic { 0x00001800073fffe8u,  34282 },
		KnownMagic { 0x00001800e05fffe8u,  29196 },
		KnownMagic { 0x00001800602fffe8u,  23806 },
		KnownMagic { 0x000030002fffffa0u,  49481 },
		KnownMagic { 0x00300018010bffffu,   2410 },
		KnownMagic { 0x0003000c0085fffbu,  36498 },
		KnownMagic { 0x0004000802010008u,  24478 },
		KnownMagic { 0x0004002020020004u,  10074 },
		KnownMagic { 0x0001002002002001u,  79315 },
		KnownMagic { 0x0001001000801040u,  51779 },
		KnownMagic { 0x0000004040008001u,  13586 },
		KnownMagic { 0x0000006800cdfff4u,  19323 },
		KnownMagic { 0x0040200010080010u,  70612 },
		KnownMagic { 0x0000080010040010u,  83652 },
		KnownMagic { 0x0004010008020008u,  63110 },
		KnownMagic { 0x0000040020200200u,  34496 },
		KnownMagic { 0x0002008010100100u,  84966 },
		KnownMagic { 0x0000008020010020u,  54341 },
		KnownMagic { 0x0000008020200040u,  60421 },
		KnownMagic { 0x0000820020004020u,  86402 },
		KnownMagic { 0x00fffd1800300030u,  50245 },
		KnownMagic { 0x007fff7fbfd40020u,  76622 },
		KnownMagic { 0x003fffbd00180018u,  84676 },
		KnownMagic { 0x001fffde80180018u,  78757 },
		KnownMagic { 0x000fffe0bfe80018u,  37346 },
		KnownMagic { 0x0001000080202001u,    370 },
		KnownMagic { 0x0003fffbff980180u,  42182 },
		KnownMagic { 0x0001fffdff9000e0u,  45385 },
		KnownMagic { 0x00fffefeebffd800u,  61659 },
		KnownMagic { 0x007ffff7ffc01400u,  12790 },
		KnownMagic { 0x003fffbfe4ffe800u,  16762 },
		KnownMagic { 0x001ffff01fc03000u,      0 },
		KnownMagic { 0x000fffe7f8bfe800u,  38380 },
		KnownMagic { 0x0007ffdfdf3ff808u,  11098 },
		KnownMagic { 0x0003fff85fffa804u,  21803 },
		KnownMagic { 0x0001fffd75ffa802u,  39189 },
		KnownMagic { 0x00ffffd7ffebffd8u,  58628 },
		KnownMagic { 0x007fff75ff7fbfd8u,  44116 },
		KnownMagic { 0x003fff863fbf7fd8u,  78357 },
		KnownMagic { 0x001fffbfdfd7ffd8u,  44481 },
		KnownMagic { 0x000ffff810280028u,  64134 },
		KnownMagic { 0x0007ffd7f7feffd8u,  41759 },
		KnownMagic { 0x0003fffc0c480048u,   1394 },
		KnownMagic { 0x0001ffffafd7ffd8u,  40910 },
		KnownMagic { 0x00ffffe4ffdfa3bau,  66516 },
		KnownMagic { 0x007fffef7ff3d3dau,   3897 },
		KnownMagic { 0x003fffbfdfeff7fau,   3930 },
		KnownMagic { 0x001fffeff7fbfc22u,  72934 },
		KnownMagic { 0x0000020408001001u,  72662 },
		KnownMagic { 0x0007fffeffff77fdu,  56325 },
		KnownMagic { 0x0003ffffbf7dfeecu,  66501 },
		KnownMagic { 0x0001ffff9dffa333u,  14826 }
	};

	static constexpr Bitboard GetOrthogonalMask(Position pos)
	{
		const Rank rank = pos >> 3;
		const File file = pos & 7;
		Bitboard mask = BitboardConstants::Ranks[rank];
		mask |= BitboardConstants::Files[file];
		if (rank != 0) mask &= ~BitboardConstants::Ranks[0];
		if (rank != 7) mask &= ~BitboardConstants::Ranks[7];
		if (file != 0) mask &= ~BitboardConstants::Files[0];
		if (file != 7) mask &= ~BitboardConstants::Files[7];
		mask &= ~GetBitboard(pos);
		return mask;
	}

	static constexpr Bitboard GetDiagonalMask(Position pos)
	{
		const Rank rank = pos >> 3;
		const File file = pos & 7;
		const Diagonal diagonal = file + rank;
		const Antidialgonal antidiagonal = rank - file + 7;
		Bitboard mask = BitboardConstants::Diagonals[diagonal];
		mask |= BitboardConstants::Antidiagonals[antidiagonal];
		mask &= ~BitboardConstants::Ranks[0];
		mask &= ~BitboardConstants::Ranks[7];
		mask &= ~BitboardConstants::Files[0];
		mask &= ~BitboardConstants::Files[7];
		mask &= ~GetBitboard(pos);
		return mask;
	}

	template<bool diagonal>
	void InitializeEntry(MagicsEntry<diagonal>& entry, Position position/*,bool diagonal, size_t& currentOffset*/)
	{
		entry.BlockerMask = diagonal ? GetDiagonalMask(position) : GetOrthogonalMask(position);

		uint8_t bitCount = 0;
		auto bits = std::array<uint8_t, 12>();
		auto maskCopy = entry.BlockerMask;
		while (maskCopy != 0)
		{
			const Position blockerPosition = BitScanForward(maskCopy);
			bits[bitCount++] = blockerPosition;
			maskCopy &= maskCopy - 1;
		}
		//entry.Shift = 64 - bitCount;
		//entry.Offset = diagonal ? BishopMagics[position].Position : RookMagics[position].Position;
		entry.Attacks = diagonal ? &Table[BishopMagics[position].Position] : &Table[RookMagics[position].Position];
		entry.MagicNumber = diagonal ? BishopMagics[position].MagicNumber : RookMagics[position].MagicNumber;
		const auto permutations = 1 << bitCount;
		for (auto i = 0; i < permutations; i++)
		{
			Bitboard blockers = 0;
			for (auto j = 0; j < bitCount; j++)
			{
				const auto shouldSet = (i & (1 << j)) > 0;
				if (shouldSet)
				{
					auto bit = bits[j];
					blockers |= GetBitboard(bit);
				}
			}
			const Bitboard moveboard = diagonal ? ReferenceGenerator::DiagonalAntidiagonalSlide(blockers, position) : ReferenceGenerator::HorizontalVerticalSlide(blockers, position);
			const size_t localOffset = entry.GetLocalOffset(blockers);
			//const size_t localOffset = i;

			assert(entry.Attacks[localOffset] == 123456789123456 || entry.Attacks[localOffset] == moveboard);

			entry.Attacks[localOffset] = moveboard;
		}
		//entry.MagicNumber = diagonal ? BishopMagics[position] : RookMagics[position];
		//currentOffset += permutations;
	}


public:
	constexpr MagicsDataClass()
	{
		/*Rooks = RookEntryArray{};
		Bishops = BishopEntryArray{};
		Table = MoveboardArray{};*/
		Table.fill(123456789123456);
		//size_t currentOffset = 0;
		for (Position position = 0; position < 64; position++)
		{
			{
				auto& entry = Rooks[position];
				InitializeEntry(entry, position);
				/*entry.BlockerMask = GetOrthogonalMask(position);
				entry.Offset = RookMagics[position].Position;
				entry.MagicNumber = RookMagics[position].MagicNumber;*/
			}

			{
				auto& entry = Bishops[position];
				InitializeEntry(entry, position);
				/*entry.BlockerMask = GetDiagonalMask(position);
				entry.Offset = BishopMagics[position].Position;
				entry.MagicNumber = BishopMagics[position].MagicNumber;*/
			}

		}
		//assert(currentOffset == Table.size());
		//Initialized = true;
	}
};

static MagicsDataClass MagicsData = MagicsDataClass();

class MagicBitboards
{
public:
	constexpr static Bitboard HorizontalVerticalSlide(const Bitboard allPieces, const Position position)
	{
		const auto& entry = MagicsData.Rooks[position];
		const auto localOffset = entry.GetLocalOffset(allPieces);
		const auto bitboard = entry.Attacks[localOffset];
		//const auto bitboard = MagicMoveTable[entry.Offset + localOffset];
		return bitboard;
	}

	constexpr static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position)
	{
		const auto& entry = MagicsData.Bishops[position];
		const auto localOffset = entry.GetLocalOffset(allPieces);
		const auto bitboard = entry.Attacks[localOffset];
		//const auto bitboard = MagicMoveTable[entry.Offset + localOffset];
		return bitboard;
	}

	constexpr static Bitboard AllSlide(const Bitboard allPieces, const Position position)
	{
		return HorizontalVerticalSlide(allPieces, position) | DiagonalAntidiagonalSlide(allPieces, position);
	}
};

//using SlideMoveGenerator = HyperbolaQuintessence;
using SlideMoveGenerator = MagicBitboards;