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
		assert(piece >= 0 && piece < ChessPiece::Count);
		assert(takesPiece >= 0 && takesPiece < ChessPiece::Count);
		assert(pawnPromoteTo >= 0 && pawnPromoteTo < ChessPiece::Count);
		
		MoveValue value = 0;
		value |= static_cast<MoveValue>(from);
		value |= static_cast<MoveValue>(to) << 8;
		value |= static_cast<MoveValue>(piece) << 16;
		value |= static_cast<MoveValue>(takesPiece) << 20;
		value |= static_cast<MoveValue>(pawnPromoteTo) << 24;
		value |= static_cast<MoveValue>(enPassant) << 28;
		//value |= static_cast<MoveValue>((piece == ChessPiece::WhiteKing || piece == ChessPiece::BlackKing) && Math.Abs(from - to) == 2) << 41;
		value |= static_cast<MoveValue>(castle) << 29;
		value |= static_cast<MoveValue>(piece == ChessPiece::Empty) << 30;
		value |= static_cast<MoveValue>(piece & ChessPiece::Color) << 31;
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
		return static_cast<Position>((Value >> 16) & 0x0F);
	}

	Piece GetTakesPiece() const
	{
		return static_cast<Position>((Value >> 20) & 0x0F);
	}

	Piece GetPawnPromoteTo() const
	{
		return static_cast<Position>((Value >> 24) & 0x0F);
	}

	bool GetEnPassant() const
	{
		return ((Value >> 28) & 0x01) == 1;
	}

	bool GetCastle() const
	{
		return ((Value >> 29) & 0x01) == 1;
	}

	bool GetNullMove() const
	{
		return ((Value >> 30) & 0x01) == 1;
	}
	bool GetWhiteToMove() const
	{
		return ((Value >> 31) & 0x01) == 1;
	}

	MoveValue GetColorToMove() const
	{
		return (Value >> 31) & 0x01;
	}

	std::string ToPositionString() const;
	std::string ToDebugString() const;
};

using MoveArray = std::array<Move, Constants::MaxMoves>;
