#pragma once

#include "common.h"
#include "constants.h"

//#include "magicMoveboard.h"

class HyperbolaQuintessence
{
public:
	constexpr static Bitboard HorizontalVerticalSlide(const Bitboard allPieces, const Position position);
	constexpr static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position);
	constexpr static Bitboard AllSlide(const Bitboard allPieces, const Position position);
};

template<bool TDiagonal>
class MagicsEntry
{
public:
	constexpr static bool Diagonal = TDiagonal;
	constexpr static uint8_t Shift = Diagonal ? 55 : 52;
	Bitboard BlockerMask;
	Magic MagicNumber;
	//uint8_t Shift;
	size_t Offset;

	[[nodiscard]] constexpr size_t GetLocalOffset(const Bitboard blockers, const Position pos) const
	{
		//const auto index = static_cast<size_t>(_pext_u64(blockers, BlockerMask));
		const auto index = static_cast<size_t>(((blockers & BlockerMask) * MagicNumber) >> Shift);
		return index;
	}
};

using BishopMagicsEntry = MagicsEntry<true>;
using RookMagicsEntry = MagicsEntry<false>;

class KnownMagicEntry
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
		using MoveboardArray = std::array<Bitboard, 89524>;
	
	BishopEntryArray Bishops{};
	RookEntryArray Rooks{};
	MoveboardArray Table{};
	//bool Initialized;

private:
	using ReferenceGenerator = HyperbolaQuintessence;
	using KnownMagicsArray = std::array<KnownMagicEntry, 64>;

	static constexpr KnownMagicsArray BishopMagics = KnownMagicsArray
	{
		KnownMagicEntry { 0x0000404040404040u,  33104 },
		KnownMagicEntry { 0x0000a060401007fcu,   4094 },
		KnownMagicEntry { 0x0000401020200000u,  24764 },
		KnownMagicEntry { 0x0000806004000000u,  13882 },
		KnownMagicEntry { 0x0000440200000000u,  23090 },
		KnownMagicEntry { 0x0000080100800000u,  32640 },
		KnownMagicEntry { 0x0000104104004000u,  11558 },
		KnownMagicEntry { 0x0000020020820080u,  32912 },
		KnownMagicEntry { 0x0000040100202004u,  13674 },
		KnownMagicEntry { 0x0000020080200802u,   6109 },
		KnownMagicEntry { 0x0000010040080200u,  26494 },
		KnownMagicEntry { 0x0000008060040000u,  17919 },
		KnownMagicEntry { 0x0000004402000000u,  25757 },
		KnownMagicEntry { 0x00000021c100b200u,  17338 },
		KnownMagicEntry { 0x0000000400410080u,  16983 },
		KnownMagicEntry { 0x000003f7f05fffc0u,  16659 },
		KnownMagicEntry { 0x0004228040808010u,  13610 },
		KnownMagicEntry { 0x0000200040404040u,   2224 },
		KnownMagicEntry { 0x0000400080808080u,  60405 },
		KnownMagicEntry { 0x0000200200801000u,   7983 },
		KnownMagicEntry { 0x0000240080840000u,     17 },
		KnownMagicEntry { 0x000018000c03fff8u,  34321 },
		KnownMagicEntry { 0x00000a5840208020u,  33216 },
		KnownMagicEntry { 0x0000058408404010u,  17127 },
		KnownMagicEntry { 0x0002022000408020u,   6397 },
		KnownMagicEntry { 0x0000402000408080u,  22169 },
		KnownMagicEntry { 0x0000804000810100u,  42727 },
		KnownMagicEntry { 0x000100403c0403ffu,    155 },
		KnownMagicEntry { 0x00078402a8802000u,   8601 },
		KnownMagicEntry { 0x0000101000804400u,  21101 },
		KnownMagicEntry { 0x0000080800104100u,  29885 },
		KnownMagicEntry { 0x0000400480101008u,  29340 },
		KnownMagicEntry { 0x0001010102004040u,  19785 },
		KnownMagicEntry { 0x0000808090402020u,  12258 },
		KnownMagicEntry { 0x0007fefe08810010u,  50451 },
		KnownMagicEntry { 0x0003ff0f833fc080u,   1712 },
		KnownMagicEntry { 0x007fe08019003042u,  78475 },
		KnownMagicEntry { 0x0000202040008040u,   7855 },
		KnownMagicEntry { 0x0001004008381008u,  13642 },
		KnownMagicEntry { 0x0000802003700808u,   8156 },
		KnownMagicEntry { 0x0000208200400080u,   4348 },
		KnownMagicEntry { 0x0000104100200040u,  28794 },
		KnownMagicEntry { 0x0003ffdf7f833fc0u,  22578 },
		KnownMagicEntry { 0x0000008840450020u,  50315 },
		KnownMagicEntry { 0x0000020040100100u,  85452 },
		KnownMagicEntry { 0x007fffdd80140028u,  32816 },
		KnownMagicEntry { 0x0000202020200040u,  13930 },
		KnownMagicEntry { 0x0001004010039004u,  17967 },
		KnownMagicEntry { 0x0000040041008000u,  33200 },
		KnownMagicEntry { 0x0003ffefe0c02200u,  32456 },
		KnownMagicEntry { 0x0000001010806000u,   7762 },
		KnownMagicEntry { 0x0000000008403000u,   7794 },
		KnownMagicEntry { 0x0000000100202000u,  22761 },
		KnownMagicEntry { 0x0000040100200800u,  14918 },
		KnownMagicEntry { 0x0000404040404000u,  11620 },
		KnownMagicEntry { 0x00006020601803f4u,  15925 },
		KnownMagicEntry { 0x0003ffdfdfc28048u,  32528 },
		KnownMagicEntry { 0x0000000820820020u,  12196 },
		KnownMagicEntry { 0x0000000010108060u,  32720 },
		KnownMagicEntry { 0x0000000000084030u,  26781 },
		KnownMagicEntry { 0x0000000001002020u,  19817 },
		KnownMagicEntry { 0x0000000040408020u,  24732 },
		KnownMagicEntry { 0x0000004040404040u,  25468 },
		KnownMagicEntry { 0x0000404040404040u,  10186 }
	};

	static constexpr KnownMagicsArray RookMagics = KnownMagicsArray
	{
		KnownMagicEntry { 0x00280077ffebfffeu,  41305 },
		KnownMagicEntry { 0x2004010201097fffu,  14326 },
		KnownMagicEntry { 0x0010020010053fffu,  24477 },
		KnownMagicEntry { 0x0030002ff71ffffau,   8223 },
		KnownMagicEntry { 0x7fd00441ffffd003u,  49795 },
		KnownMagicEntry { 0x004001d9e03ffff7u,  60546 },
		KnownMagicEntry { 0x004000888847ffffu,  28543 },
		KnownMagicEntry { 0x006800fbff75fffdu,  79282 },
		KnownMagicEntry { 0x000028010113ffffu,   6457 },
		KnownMagicEntry { 0x0020040201fcffffu,   4125 },
		KnownMagicEntry { 0x007fe80042ffffe8u,  81021 },
		KnownMagicEntry { 0x00001800217fffe8u,  42341 },
		KnownMagicEntry { 0x00001800073fffe8u,  14139 },
		KnownMagicEntry { 0x007fe8009effffe8u,  19465 },
		KnownMagicEntry { 0x00001800602fffe8u,   9514 },
		KnownMagicEntry { 0x000030002fffffa0u,  71090 },
		KnownMagicEntry { 0x00300018010bffffu,  75419 },
		KnownMagicEntry { 0x0003000c0085fffbu,  33476 },
		KnownMagicEntry { 0x0004000802010008u,  27117 },
		KnownMagicEntry { 0x0002002004002002u,  85964 },
		KnownMagicEntry { 0x0002002020010002u,  54915 },
		KnownMagicEntry { 0x0001002020008001u,  36544 },
		KnownMagicEntry { 0x0000004040008001u,  71854 },
		KnownMagicEntry { 0x0000802000200040u,  37996 },
		KnownMagicEntry { 0x0040200010080010u,  30398 },
		KnownMagicEntry { 0x0000080010040010u,  55939 },
		KnownMagicEntry { 0x0004010008020008u,  53891 },
		KnownMagicEntry { 0x0000040020200200u,  56963 },
		KnownMagicEntry { 0x0000010020020020u,  77451 },
		KnownMagicEntry { 0x0000010020200080u,  12319 },
		KnownMagicEntry { 0x0000008020200040u,  88500 },
		KnownMagicEntry { 0x0000200020004081u,  51405 },
		KnownMagicEntry { 0x00fffd1800300030u,  72878 },
		KnownMagicEntry { 0x007fff7fbfd40020u,    676 },
		KnownMagicEntry { 0x003fffbd00180018u,  83122 },
		KnownMagicEntry { 0x001fffde80180018u,  22206 },
		KnownMagicEntry { 0x000fffe0bfe80018u,  75186 },
		KnownMagicEntry { 0x0001000080202001u,    681 },
		KnownMagicEntry { 0x0003fffbff980180u,  36453 },
		KnownMagicEntry { 0x0001fffdff9000e0u,  20369 },
		KnownMagicEntry { 0x00fffeebfeffd800u,   1981 },
		KnownMagicEntry { 0x007ffff7ffc01400u,  13343 },
		KnownMagicEntry { 0x0000408104200204u,  10650 },
		KnownMagicEntry { 0x001ffff01fc03000u,  57987 },
		KnownMagicEntry { 0x000fffe7f8bfe800u,  26302 },
		KnownMagicEntry { 0x0000008001002020u,  58357 },
		KnownMagicEntry { 0x0003fff85fffa804u,  40546 },
		KnownMagicEntry { 0x0001fffd75ffa802u,      0 },
		KnownMagicEntry { 0x00ffffec00280028u,  14967 },
		KnownMagicEntry { 0x007fff75ff7fbfd8u,  80361 },
		KnownMagicEntry { 0x003fff863fbf7fd8u,  40905 },
		KnownMagicEntry { 0x001fffbfdfd7ffd8u,  58347 },
		KnownMagicEntry { 0x000ffff810280028u,  20381 },
		KnownMagicEntry { 0x0007ffd7f7feffd8u,  81868 },
		KnownMagicEntry { 0x0003fffc0c480048u,  59381 },
		KnownMagicEntry { 0x0001ffffafd7ffd8u,  84404 },
		KnownMagicEntry { 0x00ffffe4ffdfa3bau,  45811 },
		KnownMagicEntry { 0x007fffef7ff3d3dau,  62898 },
		KnownMagicEntry { 0x003fffbfdfeff7fau,  45796 },
		KnownMagicEntry { 0x001fffeff7fbfc22u,  66994 },
		KnownMagicEntry { 0x0000020408001001u,  67204 },
		KnownMagicEntry { 0x0007fffeffff77fdu,  32448 },
		KnownMagicEntry { 0x0003ffffbf7dfeecu,  62946 },
		KnownMagicEntry { 0x0001ffff9dffa333u,  17005 }
	};
	
	/*using KnownMagicsArray = std::array<Magic, 64>;
	
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
	};*/
	
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
		entry.Offset = diagonal ? BishopMagics[position].Position : RookMagics[position].Position;
		entry.MagicNumber = diagonal ? BishopMagics[position].MagicNumber : RookMagics[position].MagicNumber;
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

			assert(Table[entry.Offset + localOffset] == 123456789123456 || Table[entry.Offset + localOffset] == moveboard);
			
			Table[entry.Offset + localOffset] = moveboard; // TODO: Uncomment if using non-hardcoded table
		}
		//entry.MagicNumber = diagonal ? BishopMagics[position] : RookMagics[position];
		//currentOffset += permutations;
	}
	

public:
	MagicsDataClass()
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
				//entry.BlockerMask = GetOrthogonalMask(position);
				//uint8_t bitCount = PopCount(entry.BlockerMask);
				//entry.Shift = 64 - bitCount;
				//entry.Offset = currentOffset;
				//const auto permutations = 1 << bitCount;
				//entry.MagicNumber = RookMagics[position];
				//currentOffset += permutations;
			}

			{
				auto& entry = Bishops[position];
				InitializeEntry(entry, position);
				/*entry.BlockerMask = GetDiagonalMask(position);
				uint8_t bitCount = PopCount(entry.BlockerMask);
				entry.Shift = 64 - bitCount;
				entry.Offset = currentOffset;
				const auto permutations = 1 << bitCount;
				entry.MagicNumber = BishopMagics[position];
				currentOffset += permutations;*/
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
		const auto localOffset = entry.GetLocalOffset(allPieces, position);
		const auto bitboard = MagicsData.Table[entry.Offset + localOffset];
		//const auto bitboard = MagicMoveTable[entry.Offset + localOffset];
		return bitboard;
	}
	
	constexpr static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position)
	{
		const auto& entry = MagicsData.Bishops[position];
		const auto localOffset = entry.GetLocalOffset(allPieces, position);
		const auto bitboard = MagicsData.Table[entry.Offset + localOffset];
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