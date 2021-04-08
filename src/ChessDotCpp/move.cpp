#include "move.h"


#include <iostream>
#include <sstream>

std::string PositionToText(const Position position)
{
	const Rank rank = position / 8;
	const File file = position % 8;

	char positions[2];
	positions[0] = static_cast<char>(file + 97);
	positions[1] = static_cast<char>(rank + 0x31);
	auto str = std::string(positions);
	return str;
}

std::string Move::ToPositionString() const
{
	std::string text = PositionToText(GetFrom()) + PositionToText(GetTo());
	if (GetPawnPromoteTo() != ChessPiece::Empty)
	{
		char promotionLetter;
		switch (GetPawnPromoteTo())
		{
		case ChessPiece::WhiteKnight:
		case ChessPiece::BlackKnight:
			promotionLetter = 'n';
			break;
		case ChessPiece::WhiteBishop:
		case ChessPiece::BlackBishop:
			promotionLetter = 'b';
			break;
		case ChessPiece::WhiteRook:
		case ChessPiece::BlackRook:
			promotionLetter = 'r';
			break;
		case ChessPiece::WhiteQueen:
		case ChessPiece::BlackQueen:
			promotionLetter = 'q';
			break;
		default:
			throw std::exception("Invalid pawn promotion");
		}
		text += promotionLetter;
	}
	return text;
}

std::string Move::ToDebugString() const
{
	std::stringstream stream = std::stringstream();
	std::cout << ToPositionString();
	stream << "From:" << GetFrom();
	stream << ", To:" << GetTo();
	stream << ", Piece: " << GetPiece();
	stream << ", TakesPiece: " << GetTakesPiece();
	stream << ", PawnPromoteTo: " << GetPawnPromoteTo();
	stream << ", EnPassant: " << GetEnPassant();
	stream << ", Castle: " << GetCastle();
	stream << ", NullMove: " << GetNullMove();
	stream << ", White: " << GetWhiteToMove();

	return stream.str();
}
