#include "move.h"


#include <iostream>
#include <sstream>

Position Move::GetFrom() const
{
    return static_cast<Position>(Value & 0x3F);
}

Position Move::GetTo() const
{
    return static_cast<Position>((Value >> 6) & 0x3F);
}

Piece Move::GetPiece() const
{
    return static_cast<Position>((Value >> 12) & 0x0F);
}

Piece Move::GetTakesPiece() const
{
    return static_cast<Position>((Value >> 20) & 0x0F);
}

Piece Move::GetPawnPromoteTo() const
{
    return static_cast<Position>((Value >> 24) & 0x0F);
}

bool Move::get_en_passant() const
{
    return ((Value >> 28) & 0x01) == 1;
}

bool Move::GetCastle() const
{
    return ((Value >> 29) & 0x01) == 1;
}

bool Move::GetNullMove() const
{
    return ((Value >> 30) & 0x01) == 1;
}

bool Move::GetWhiteToMove() const
{
    return ((Value >> 31) & 0x01) == Colors::White;
}

MoveValue Move::GetColorToMove() const
{
    return (Value >> 31) & 0x01;
}

MoveString Move::ToPositionString() const
{
	std::stringstream stream = std::stringstream();
	stream << Positions::PositionToText(GetFrom());
	stream << Positions::PositionToText(GetTo());
	//std::string text = PositionToText(GetFrom()) + PositionToText(GetTo());
	if (GetPawnPromoteTo() != Pieces::Empty)
	{
		char promotionLetter;
		switch (GetPawnPromoteTo())
		{
		case Pieces::WhiteKnight:
		case Pieces::BlackKnight:
			promotionLetter = 'n';
			break;
		case Pieces::WhiteBishop:
		case Pieces::BlackBishop:
			promotionLetter = 'b';
			break;
		case Pieces::WhiteRook:
		case Pieces::BlackRook:
			promotionLetter = 'r';
			break;
		case Pieces::WhiteQueen:
		case Pieces::BlackQueen:
			promotionLetter = 'q';
			break;
		default:
			Throw("Invalid pawn promotion");
		}
		stream << promotionLetter;
	}
	return stream.str();
}

std::string Move::ToDebugString() const
{
	std::stringstream stream = std::stringstream();
	stream << "Move: " << ToPositionString() << std::endl;
	stream << "Color: " << (GetWhiteToMove() ? "White" : "Black") << std::endl;
	stream << "From: " << std::to_string(GetFrom()) << std::endl;
	stream << "To: " << std::to_string(GetTo()) << std::endl;
	stream << "Piece: " << Pieces::CharMap[GetPiece()] << std::endl;
	stream << "TakesPiece: " << Pieces::CharMap[GetTakesPiece()] << std::endl;
	stream << "PawnPromoteTo: " << Pieces::CharMap[GetPawnPromoteTo()] << std::endl;
	stream << "EnPassant: " << (get_en_passant() ? "true" : "false") << std::endl;
	stream << "Castle: " << (GetCastle() ? "true" : "false") << std::endl;
	stream << "NullMove: " << (GetNullMove() ? "true" : "false") << std::endl;

	return stream.str();
}
