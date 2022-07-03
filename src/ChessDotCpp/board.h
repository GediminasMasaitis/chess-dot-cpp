#pragma once

#include "common.h"
#include "move.h"
#include "evaluationNnueBase.h"

#include <array>

#define USEACCUMULATOR 1

class UndoMove
{
public:
	Move Move;
	CastlingPermission CastlingPermission;
	File EnPassantFileIndex;
	Rank EnPassantRankIndex;
	HistoryPly FiftyMoveRule;
	Score StaticEvaluation;
	ZobristKey Key;
	ZobristKey PawnKey;
};

class BoardBase
{
public:
	bool enableAccumulatorStack = false;
#if USEACCUMULATOR
	static constexpr bool useAccumulator = true;

	using value_t = EvaluationNnueBase::NnueValue;
	using accumulator_t = EvaluationNnueBase::hidden_layer_t;
	using accumulators_t = EvaluationNnueBase::hidden_layers_t;

    struct accumulator_wrapper_t
    {
		alignas(Simd<value_t>::alignment) accumulators_t accumulators {};
    };

	using accumulator_stack_t = std::vector<accumulator_wrapper_t>;
    accumulator_stack_t accumulatorStack;

	void PushAccumulator()
	{
		if(!enableAccumulatorStack)
		{
		    return;
		}

		auto& accumulators = accumulatorStack[accumulatorStack.size() - 1];
		accumulatorStack.push_back(accumulators);
	}

	void PopAccumulator()
	{
		assert(enableAccumulatorStack);
        assert(!accumulatorStack.empty());

		accumulatorStack.pop_back();
	}

	void ResetAccumulator()
	{
		accumulatorStack.clear();
		accumulatorStack.push_back(accumulator_wrapper_t{});
		EvaluationNnueBase::Reset(accumulatorStack[0].accumulators);
	}

	void SetAccumulatorPiece(const Position pos, const Piece piece)
	{
		auto& accumulators = accumulatorStack[accumulatorStack.size() - 1].accumulators;
		EvaluationNnueBase::SetPiece(accumulators, pos, piece);
	}

	void UnsetAccumulatorPiece(const Position pos, const Piece piece)
	{
		auto& accumulators = accumulatorStack[accumulatorStack.size() - 1].accumulators;
		EvaluationNnueBase::UnsetPiece(accumulators, pos, piece);
	}

#else
	static constexpr bool useAccumulator = false;

	void PushAccumulator()
	{
	}

	void PopAccumulator()
	{
	}

	void ResetAccumulator()
	{
	}

	void SetPiece(const Position pos, const Piece piece)
	{
	}

	void UnetPiece(const Position pos, const Piece piece)
	{
	}
#endif
	
	Color ColorToMove;
	bool WhiteToMove;
	CastlingPermission CastlingPermissions;

	//Bitboard WhitePieces;
	//Bitboard BlackPieces;
	Bitboard EmptySquares;
	Bitboard AllPieces;

	EachPiece<Bitboard> BitBoard;
	EachPosition<Piece> ArrayBoard;

	File EnPassantFileIndex;
	Rank EnPassantRankIndex;
	Bitboard EnPassantFile;
	ZobristKey Key;
	ZobristKey PawnKey;

	EachPiece<Piece> PieceCounts;
	EachColor<Position> KingPositions;
	EachColor<Score> PawnMaterial;
	EachColor<Score> PieceMaterial;
	Score StaticEvaluation;

	bool CanCastle(const CastlingPermission permission) const;
	void SyncExtraBitBoards();

	[[nodiscard]] Move FromPositionString(const MoveString& moveString) const;

	void FlipColors();
};

class KeyAnd50Move
{
public:
	ZobristKey Key;
	HistoryPly FiftyMoveRuleIndex;
};

class Board : public BoardBase
{
public:
	std::array<UndoMove, Constants::MaxHistory> History;
	HistoryPly HistoryDepth;
	HistoryPly FiftyMoveRuleIndex;
	
	void DoMove(const Move move);
	void GetKeyAfterMove(const Move move, KeyAnd50Move& keyAnd50Move) const;
	void DoMove(const MoveString& moveString);
	void UndoMove();

	Board();
};

class CastleRevocationClass
{
public:
	std::array<CastlingPermission, 64> Table{};

	constexpr CastleRevocationClass()
	{
		for (Position i = 0; i < 64; i++)
		{
			CastlingPermission permission = CastlingPermissions::All;
			switch (i)
			{
			case 0:
				permission &= ~CastlingPermissions::WhiteQueen;
				break;
			case 4:
				permission &= ~CastlingPermissions::WhiteQueen;
				permission &= ~CastlingPermissions::WhiteKing;
				break;
			case 7:
				permission &= ~CastlingPermissions::WhiteKing;
				break;
			case 56:
				permission &= ~CastlingPermissions::BlackQueen;
				break;
			case 60:
				permission &= ~CastlingPermissions::BlackQueen;
				permission &= ~CastlingPermissions::BlackKing;
				break;
			case 63:
				permission &= ~CastlingPermissions::BlackKing;
				break;
			default:
				break;
			}

			Table[i] = permission;
		}
	}
};

constexpr CastleRevocationClass CastleRevocation = CastleRevocationClass();
