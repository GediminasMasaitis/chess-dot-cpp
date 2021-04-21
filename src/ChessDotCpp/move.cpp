#include "move.h"


#include <iostream>
#include <sstream>

std::string PositionToText(const Position position)
{
	const Rank rank = position / 8;
	const File file = position % 8;

	char positions[3];
	positions[0] = static_cast<char>(file + 97);
	positions[1] = static_cast<char>(rank + 0x31);
	positions[2] = '\0';
	auto str = std::string(positions);
	return str;
}

Position Move::TextToPosition(const std::string& text)
{
	const File file = std::tolower(text[0]) - 97;
	const Rank rank = text[1] - 0x31;
	const Position position = static_cast<Position>(rank * 8 + file);
	return position;
}

MoveString Move::ToPositionString() const
{
	std::stringstream stream = std::stringstream();
	stream << PositionToText(GetFrom());
	stream << PositionToText(GetTo());
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
