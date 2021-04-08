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
		const Piece pawnPromoteTo = ChessPiece::Empty
	)
	{
		assert(from >= 0 && from < 64);
		assert(to >= 0 && to < 64);
		assert(piece >= 0 && piece < Constants::PieceCount);
		assert(takesPiece >= 0 && takesPiece < Constants::PieceCount);
		assert(pawnPromoteTo >= 0 && pawnPromoteTo < Constants::PieceCount);
		
		MoveValue value = 0;
		value |= static_cast<MoveValue>(from);
		value |= static_cast<MoveValue>(to) << 8;
		value |= static_cast<MoveValue>(piece) << 16;
		value |= static_cast<MoveValue>(takesPiece) << 24;
		value |= static_cast<MoveValue>(pawnPromoteTo) << 32;
		value |= static_cast<MoveValue>(enPassant) << 40;
		//value |= static_cast<MoveValue>((piece == ChessPiece::WhiteKing || piece == ChessPiece::BlackKing) && Math.Abs(from - to) == 2) << 41;
		value |= static_cast<MoveValue>(castle) << 41;
		value |= static_cast<MoveValue>(piece == 0) << 42;
		value |= static_cast<MoveValue>(piece <= 6) << 43;
		Value = value;
	}

	Move(MoveValue value)
	{
		Value = value;
	}

	Move()
	{
		Value = 0;
	}

	Position GetFrom() const
	{
		return static_cast<Position>(Value & 0xFF);
	}

	Position GetTo() const
	{
		return static_cast<Position>((Value >> 8) & 0xFF);
	}

	Piece GetPiece() const
	{
		return static_cast<Position>((Value >> 16) & 0xFF);
	}

	Piece GetTakesPiece() const
	{
		return static_cast<Position>((Value >> 24) & 0xFF);
	}

	Piece GetPawnPromoteTo() const
	{
		return static_cast<Position>((Value >> 32) & 0xFF);
	}

	bool GetEnPassant() const
	{
		return ((Value >> 40) & 0x01) == 1;
	}

	bool GetCastle() const
	{
		return ((Value >> 41) & 0x01) == 1;
	}

	bool GetNullMove() const
	{
		return ((Value >> 42) & 0x01) == 1;
	}
	bool GetWhiteToMove() const
	{
		return ((Value >> 43) & 0x01) == 1;
	}

	MoveValue GetWhiteToMoveNum() const
	{
		return (Value >> 43) & 0x01;
	}

	std::string ToPositionString() const;
	std::string ToDebugString() const;
};

using MoveArray = std::array<Move, Constants::MaxMoves>;
