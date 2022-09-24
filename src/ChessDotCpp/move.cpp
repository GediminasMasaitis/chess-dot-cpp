#include "move.h"


#include <iostream>
#include <sstream>

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
	stream << "EnPassant: " << (GetEnPassant() ? "true" : "false") << std::endl;
	stream << "Castle: " << (GetCastle() ? "true" : "false") << std::endl;
	stream << "NullMove: " << (GetNullMove() ? "true" : "false") << std::endl;

	return stream.str();
}
