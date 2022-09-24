#pragma once

#include "common.h"

#include <string>

class Move
{
public:
	MoveValue Value;

	Move
	(
		const Position from,
		const Position to,
		const Piece piece,
		const Piece takesPiece = 0,
		const bool enPassant = false,
		const bool castle = false,
		const Piece pawnPromoteTo = Pieces::Empty
	)
	{
		assert(from >= 0 && from < 64);
		assert(to >= 0 && to < 64);
		assert(piece >= 0 && piece < Pieces::Count);
		assert(takesPiece >= 0 && takesPiece < Pieces::Count);
		assert(pawnPromoteTo >= 0 && pawnPromoteTo < Pieces::Count);
		
		MoveValue value = 0;
		value |= static_cast<MoveValue>(from);
		value |= static_cast<MoveValue>(to) << 8;
		value |= static_cast<MoveValue>(piece) << 16;
		value |= static_cast<MoveValue>(takesPiece) << 20;
		value |= static_cast<MoveValue>(pawnPromoteTo) << 24;
		value |= static_cast<MoveValue>(enPassant) << 28;
		//value |= static_cast<MoveValue>((piece == ChessPiece::WhiteKing || piece == ChessPiece::BlackKing) && Math.Abs(from - to) == 2) << 41;
		value |= static_cast<MoveValue>(castle) << 29;
		value |= static_cast<MoveValue>(piece == Pieces::Empty) << 30;
		value |= static_cast<MoveValue>(piece & Pieces::Color) << 31;
		Value = value;
	}

	explicit Move(MoveValue value)
	{
		Value = value;
	}

	Move()
	{
		Value = 0;
	}

	[[nodiscard]] Position GetFrom() const
	{
		return static_cast<Position>(Value & 0xFF);
	}

	[[nodiscard]] Position GetTo() const
	{
		return static_cast<Position>((Value >> 8) & 0xFF);
	}

	[[nodiscard]] Piece GetPiece() const
	{
		return static_cast<Position>((Value >> 16) & 0x0F);
	}

	[[nodiscard]] Piece GetTakesPiece() const
	{
		return static_cast<Position>((Value >> 20) & 0x0F);
	}

	[[nodiscard]] Piece GetPawnPromoteTo() const
	{
		return static_cast<Position>((Value >> 24) & 0x0F);
	}

	[[nodiscard]] bool GetEnPassant() const
	{
		return ((Value >> 28) & 0x01) == 1;
	}

	[[nodiscard]] bool GetCastle() const
	{
		return ((Value >> 29) & 0x01) == 1;
	}

	[[nodiscard]] bool GetNullMove() const
	{
		return ((Value >> 30) & 0x01) == 1;
	}
	[[nodiscard]] bool GetWhiteToMove() const
	{
		return ((Value >> 31) & 0x01) == Colors::White;
	}

	[[nodiscard]] MoveValue GetColorToMove() const
	{
		return (Value >> 31) & 0x01;
	}
	
	[[nodiscard]] MoveString ToPositionString() const;
	[[nodiscard]] std::string ToDebugString() const;
};

using MoveArray = std::array<Move, Constants::MaxMoves>;
using MoveScoreArray = std::array<MoveScore, Constants::MaxMoves>;
using ScoreArray = std::array<Score, Constants::MaxMoves>;
