#pragma once

#include "common.h"
#include "constants.h"

#include "magicMoveboard.h"

class HyperbolaQuintessence
{
public:
	constexpr static Bitboard HorizontalVerticalSlide(const Bitboard allPieces, const Position position);
	constexpr static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position);
	constexpr static Bitboard AllSlide(const Bitboard allPieces, const Position position);
};

class MagicsEntry
{
public:
	Bitboard BlockerMask;
	Magic MagicNumber;
	uint8_t Shift;
	size_t Offset;

	[[nodiscard]] constexpr size_t GetLocalOffset(const Bitboard blockers, const Position pos) const
	{
		//const auto index = static_cast<size_t>(_pext_u64(blockers, BlockerMask));
		const auto index = static_cast<size_t>(((blockers & BlockerMask) * MagicNumber) >> Shift);
		return index;
	}
};

class MagicsDataClass
{
public:
	using ReferenceGenerator = HyperbolaQuintessence;
	using EntryArray = std::array<MagicsEntry, 64>;
	//using MoveboardArray = std::array<Bitboard, 107648>;
	
	EntryArray Rooks;
	EntryArray Bishops;
	//MoveboardArray Table;
	//bool Initialized;

private:
	using KnownMagicsArray = std::array<Magic, 64>;
	
	static constexpr KnownMagicsArray RookMagics = {
		0x808010800022C000,0x2040002009100040,0x6880100008A00082,0x800800B0000480,0x4200041012002008,0x2100030002240008,0x4400080402008910,0x3000040A2009100,
		0x8801084400220,0x48100210D400082,0x413001020010440,0x1001005820100100,0x6001A00041020,0x4000800400808200,0x5500020029000C,0x60020002011080C4,
		0x8004808000A14000,0x10004040002000,0x5030020003240,0x10808010000802,0x4160020060012,0x1010002040008,0xD440008821001,0x1140820004008241,
		0x480A080014000,0x4102500040002009,0x1202924200208201,0x2000A00401021,0x1200040080080080,0x880A0080800400,0x10040101000200,0x8108658200004104,
		0x488204001800080,0x401000402000,0x862005801000,0x9006219001000,0x4000080080801400,0x802400800200,0x400011014000228,0x10801040800100,
		0x3028884002208000,0x380402010004000,0x4010204082020010,0x1090000800808011,0x78280011010024,0x31020004100E0008,0x1000200010034,0x4030016402820001,
		0x1010800070410100,0x480C00102802500,0x200030008A200080,0x82001021408A0200,0x4404800D1004500,0x2200440012008080,0x1000800500020080,0x40050080640200,
		0x84820110402102,0xA300804000B361,0xA404A0050010C119,0x8904080421005001,0x36000CA0101802,0x902001025082402,0x460010090201D804,0x423C4210C0082
	};

	static constexpr KnownMagicsArray BishopMagics = {
		0x8520041000410121,0xC888811006000,0x8022042000000,0x805810840B004,0x151C04A064208200,0x1040640080400,0x2090A4042A400008,0xE005008211201A00,
		0x880210122200,0x6808D00420C041,0x120084090020,0xC13041C20800401,0x20211040188030,0x80608023A4104,0x60820104208410,0x108192094104814,
		0x248012008190800,0x8012042028810100,0x1802006C00340100,0x20008408020241E0,0x14022080A00000,0x5003800501600211,0x2801080401231000,0x2700601090800,
		0x4400044100408,0x30080422080140,0x22080410080A2020,0x8300C004040002,0x4030840002020200,0x80200008A1102,0x1108022103008200,0x8C008000420090,
		0x8010041080051010,0x80202A000820800,0x4000248800500060,0x101200800010050,0x1004040400871100,0x4040804201200A0,0x18050300040191,0x4002020202014442,
		0x202109082120C0D0,0xC04B011002041000,0x6240220022013000,0x1400414208000480,0x2000040810129200,0x40108280800900,0x200A020431000421,0x90020055500104,
		0x8480248200020,0x2804C0088080108,0x8000340A081400,0x280040042060110,0x2010100A1203E0,0x1042910610102,0x408424208A0218,0x400801080A084000,
		0x8001040203018821,0x884060110829020,0x1000088446080418,0x10A6000001840408,0x1000020010020210,0x45004018250100,0x840208090808064C,0x8202502020010
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
	
	void InitializeEntry(MagicsEntry& entry, Position position, bool diagonal, size_t& currentOffset)
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
		entry.Shift = 64 - bitCount;
		entry.Offset = currentOffset;
		entry.MagicNumber = diagonal ? BishopMagics[position] : RookMagics[position];
		const auto permutations = 1 << bitCount;
		for(size_t i = 0; i < permutations; i++)
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
			const size_t localOffset = entry.GetLocalOffset(blockers, position);
			//const size_t localOffset = i;
			
			//Table[entry.Offset + localOffset] = moveboard; // TODO: Uncomment if using non-hardcoded table
		}
		entry.MagicNumber = diagonal ? BishopMagics[position] : RookMagics[position];
		currentOffset += permutations;
	}
	

public:
	constexpr MagicsDataClass()
	{
		Rooks = EntryArray{};
		Bishops = EntryArray{};
		//Table = MoveboardArray{};
		
		size_t currentOffset = 0;
		for (Position position = 0; position < 64; position++)
		{
			{
				auto& entry = Rooks[position];
				entry.BlockerMask = GetOrthogonalMask(position);
				uint8_t bitCount = PopCount(entry.BlockerMask);
				entry.Shift = 64 - bitCount;
				entry.Offset = currentOffset;
				const auto permutations = 1 << bitCount;
				entry.MagicNumber = RookMagics[position];
				currentOffset += permutations;
			}

			{
				auto& entry = Bishops[position];
				entry.BlockerMask = GetDiagonalMask(position);
				uint8_t bitCount = PopCount(entry.BlockerMask);
				entry.Shift = 64 - bitCount;
				entry.Offset = currentOffset;
				const auto permutations = 1 << bitCount;
				entry.MagicNumber = BishopMagics[position];
				currentOffset += permutations;
			}
			
		}
		//assert(currentOffset == Table.size());
		//Initialized = true;
	}
};

static constexpr MagicsDataClass MagicsData = MagicsDataClass();

class MagicBitboards
{
public:
	constexpr static Bitboard HorizontalVerticalSlide(const Bitboard allPieces, const Position position)
	{
		const auto& entry = MagicsData.Rooks[position];
		const auto localOffset = entry.GetLocalOffset(allPieces, position);
		const auto bitboard = MagicMoveTable[entry.Offset + localOffset];
		return bitboard;
	}
	
	constexpr static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position)
	{
		const auto& entry = MagicsData.Bishops[position];
		const auto localOffset = entry.GetLocalOffset(allPieces, position);
		const auto bitboard = MagicMoveTable[entry.Offset + localOffset];
		return bitboard;
	}
	
	constexpr static Bitboard AllSlide(const Bitboard allPieces, const Position position)
	{
		return HorizontalVerticalSlide(allPieces, position) | DiagonalAntidiagonalSlide(allPieces, position);
	}
};

//using SlideMoveGenerator = HyperbolaQuintessence;
using SlideMoveGenerator = MagicBitboards;