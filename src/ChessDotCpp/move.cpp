#include "move.h"

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
