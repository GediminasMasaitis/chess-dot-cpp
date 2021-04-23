#include "evaluation.h"

#include "attacks.h"
#include "magics.h"

#include <iostream>

#include "movegen.h"

class EvaluationScores
{
public:
    Score Result = 0;
    Phase GamePhase = 0; // function of piece material: 24 in opening, 0 in endgame
    
    EachColor<Score> MidgameMobility{};
    EachColor<Score> EndgameMobility{};
    EachColor<Score> AttackCount{};
    EachColor<Score> AttackWeight{};
    EachColor<Score> MidgameTropism{};
    EachColor<Score> EndgameTropism{};
    EachColor<Score> KingShield{};
    EachColor<Score> MaterialAdjustment{};
    EachColor<Score> Blockages{};
    EachColor<Score> PositionalThemes{};
    EachColor<Score> PieceSquaresMidgame{};
    EachColor<Score> PieceSquaresEndgame{};
    
    void Clear()
    {
        GamePhase = 0;
        for (Piece side = 0; side <= 1; side++)
        {
            MidgameMobility[side] = 0;
            EndgameMobility[side] = 0;
            AttackCount[side] = 0;
            AttackWeight[side] = 0;
            MidgameTropism[side] = 0;
            EndgameTropism[side] = 0;
            KingShield[side] = 0;
            MaterialAdjustment[side] = 0;
            Blockages[side] = 0;
            PositionalThemes[side] = 0;
            PieceSquaresMidgame[side] = 0;
            PieceSquaresEndgame[side] = 0;
        }
    }

    static void PrintEachColor(const EachColor<Score>& scores, const std::string header)
    {
        std::cout << header << "; White: " << scores[Colors::White] << ", Black: " << scores[Colors::Black] << ", Diff: " << (scores[Colors::White] - scores[Colors::Black]) << std::endl;
    }
    
    void Print(const Board& board)
    {
        std::cout << "Result: " << Result << std::endl;
        std::cout << "Phase: " << std::to_string(GamePhase) << std::endl;
        PrintEachColor(board.PawnMaterial, "Pawn material");
        PrintEachColor(board.PieceMaterial, "Piece material");
        PrintEachColor(MidgameMobility, "Midgame mobility");
        PrintEachColor(EndgameMobility, "Endgame mobility");
        PrintEachColor(AttackCount, "Attack count");
        PrintEachColor(AttackWeight, "Attack weight");
        PrintEachColor(MidgameTropism, "Midgame tropism");
        PrintEachColor(EndgameTropism, "Endgame tropism");
        PrintEachColor(KingShield, "King shield");
        PrintEachColor(MaterialAdjustment, "Material adjustment");
        PrintEachColor(Blockages, "Blockages");
        PrintEachColor(PositionalThemes, "PositionalThemes");
        PrintEachColor(PieceSquaresMidgame, "Piece squares midgame");
        PrintEachColor(PieceSquaresEndgame, "Piece squares endgame");
    }
};

template<Color TColor>
Score KingShield(const Board& board)
{
    Score result = 0;
    
    const Position kingPos = board.KingPositions[TColor];
    const File kingCol = Files::Get(kingPos);
    constexpr Piece pawn = Pieces::Pawn | TColor;

    // Kingside
    if (kingCol > Files::E)
    {
        if (board.ArrayBoard[Positions::Relative[TColor][Positions::F2]] == pawn) result += EvaluationData::KingShieldRank2;
        else if (board.ArrayBoard[Positions::Relative[TColor][Positions::F3]] == pawn) result += EvaluationData::KingShieldRank3;

        if (board.ArrayBoard[Positions::Relative[TColor][Positions::G2]] == pawn) result += EvaluationData::KingShieldRank2;
        else if (board.ArrayBoard[Positions::Relative[TColor][Positions::G3]] == pawn) result += EvaluationData::KingShieldRank3;

        if (board.ArrayBoard[Positions::Relative[TColor][Positions::H2]] == pawn) result += EvaluationData::KingShieldRank2;
        else if (board.ArrayBoard[Positions::Relative[TColor][Positions::H3]] == pawn) result += EvaluationData::KingShieldRank3;
    }

    // Queenside
    else if (kingCol < Files::D)
    {

        if (board.ArrayBoard[Positions::Relative[TColor][Positions::A2]] == pawn) result += EvaluationData::KingShieldRank2;
        else if (board.ArrayBoard[Positions::Relative[TColor][Positions::A3]] == pawn) result += EvaluationData::KingShieldRank3;

        if (board.ArrayBoard[Positions::Relative[TColor][Positions::B2]] == pawn) result += EvaluationData::KingShieldRank2;
        else if (board.ArrayBoard[Positions::Relative[TColor][Positions::B3]] == pawn) result += EvaluationData::KingShieldRank3;

        if (board.ArrayBoard[Positions::Relative[TColor][Positions::C2]] == pawn) result += EvaluationData::KingShieldRank2;
        else if (board.ArrayBoard[Positions::Relative[TColor][Positions::C3]] == pawn) result += EvaluationData::KingShieldRank3;
    }

    return result;
}

template<Color TColor, Piece TPiece, Position TPosition>
constexpr bool IsPieceRel(const Board& board)
{
    constexpr Position relativePos = Positions::Rel<TColor>(TPosition);
    constexpr Piece piece = TPiece | TColor;
    return board.ArrayBoard[relativePos] == piece;
}

template<Color TColor, Piece TPiece, Position TPosition>
constexpr bool IsPiece(const Board& board)
{
    constexpr Piece piece = TPiece | TColor;
    return board.ArrayBoard[TPosition] == piece;
}

template<Color TColor>
void BlockedPieces(const Board& board, EvaluationScores& scores)
{
    constexpr Color side = TColor;
    constexpr Color oppo = side ^ 1;

    // central pawn blocked, bishop hard to develop
    if (IsPieceRel<side, Pieces::Bishop, Positions::C1>(board)
        && IsPiece<side, Pieces::Pawn, Positions::Rel<side, Positions::D2>()>(board)
        && board.ArrayBoard[Positions::Rel<side, Positions::D3>()] != Pieces::Empty)
        scores.Blockages[side] += EvaluationData::BlockedCentralPawn;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::F1>()>(board)
        && IsPiece<side, Pieces::Pawn, Positions::Rel<side, Positions::E2>()>(board)
        && board.ArrayBoard[Positions::Rel<side, Positions::E3>()] != Pieces::Empty)
        scores.Blockages[side] += EvaluationData::BlockedCentralPawn;

    // trapped knight
    if (IsPiece<side, Pieces::Knight, Positions::Rel<side, Positions::A8>()>(board)
        && (IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::A7>()>(board) || IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::C7>()>(board)))
        scores.Blockages[side] += EvaluationData::KnightTrappedA8;

    if (IsPiece<side, Pieces::Knight, Positions::Rel<side, Positions::H8>()>(board)
        && (IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::H7>()>(board) || IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::F7>()>(board)))
        scores.Blockages[side] += EvaluationData::KnightTrappedA8;

    if (IsPiece<side, Pieces::Knight, Positions::Rel<side, Positions::A7>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::A6>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::B7>()>(board))
        scores.Blockages[side] += EvaluationData::KnightTrappedA7;

    if (IsPiece<side, Pieces::Knight, Positions::Rel<side, Positions::H7>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::H6>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::G7>()>(board))
        scores.Blockages[side] += EvaluationData::KnightTrappedA7;

    // knight blocking queenside pawns
    if (IsPiece<side, Pieces::Knight, Positions::Rel<side, Positions::C3>()>(board)
        && IsPiece<side, Pieces::Pawn, Positions::Rel<side, Positions::C2>()>(board)
        && IsPiece<side, Pieces::Pawn, Positions::Rel<side, Positions::D4>()>(board)
        && !IsPiece<side, Pieces::Pawn, Positions::Rel<side, Positions::E4>()>(board))
        scores.Blockages[side] += EvaluationData::KnightC3;

    // trapped bishop
    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::A7>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::B6>()>(board))
        scores.Blockages[side] += EvaluationData::BishopTrappedA7;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::H7>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::G6>()>(board))
        scores.Blockages[side] += EvaluationData::BishopTrappedA7;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::B8>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::C7>()>(board))
        scores.Blockages[side] += EvaluationData::BishopTrappedA7;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::G8>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::F7>()>(board))
        scores.Blockages[side] += EvaluationData::BishopTrappedA7;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::A6>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::B5>()>(board))
        scores.Blockages[side] += EvaluationData::BishopTrappedA6;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::H6>()>(board)
        && IsPiece<oppo, Pieces::Pawn, Positions::Rel<side, Positions::G5>()>(board))
        scores.Blockages[side] += EvaluationData::BishopTrappedA6;

    // bishop on initial sqare supporting castled king
    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::F1>()>(board)
        && IsPiece<side, Pieces::King, Positions::Rel<side, Positions::G1>()>(board))
        scores.PositionalThemes[side] += EvaluationData::ReturningBishop;

    if (IsPiece<side, Pieces::Bishop, Positions::Rel<side, Positions::C1>()>(board)
        && IsPiece<side, Pieces::King, Positions::Rel<side, Positions::B1>()>(board))
        scores.PositionalThemes[side] += EvaluationData::ReturningBishop;

    // uncastled king blocking own rook
    if ((IsPiece<side, Pieces::King, Positions::Rel<side, Positions::F1>()>(board) || IsPiece<side, Pieces::King, Positions::Rel<side, Positions::G1>()>(board))
        && (IsPiece<side, Pieces::Rook, Positions::Rel<side, Positions::H1>()>(board) || IsPiece<side, Pieces::Rook, Positions::Rel<side, Positions::G1>()>(board)))
        scores.Blockages[side] += EvaluationData::KingBlocksRook;

    if ((IsPiece<side, Pieces::King, Positions::Rel<side, Positions::C1>()>(board) || IsPiece<side, Pieces::King, Positions::Rel<side, Positions::B1>()>(board))
        && (IsPiece<side, Pieces::Rook, Positions::Rel<side, Positions::A1>()>(board) || IsPiece<side, Pieces::Rook, Positions::Rel<side, Positions::B1>()>(board)))
        scores.Blockages[side] += EvaluationData::KingBlocksRook;
}

Tropism GetTropism(const Position sq1, const Position sq2)
{
    const Rank rankDiff = static_cast<Rank>(std::abs(Ranks::Get(sq1) - Ranks::Get(sq2)));
    const File fileDiff = static_cast<File>(std::abs(Files::Get(sq1) - Files::Get(sq2)));
    const Tropism distance = static_cast<Tropism>(rankDiff + fileDiff);
    return 7 - distance;
}

template<Color TColor>
void EvalKnight(const Board& board, EvaluationScores& scores, const Position position, const EachColor<Bitboard>& pawnControl, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Color opp = color ^ 1;
    int att = 0;
    int mob = 0;

    /**************************************************************************
    *  Collect data about mobility and king attacks. This resembles move      *
    *  generation code, except that we are just incrementing the counters     *
    *  instead of adding actual moves.                                        *
    **************************************************************************/

    const Bitboard jumps = BitboardJumps.KnightJumps[position];
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & jumps;

    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        const Bitboard uncontrolled = emptyOrOpponent & ~pawnControl[color ^ 1];
        mob += PopCount(uncontrolled);
    }

    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    /**************************************************************************
    *  Evaluate mobility. We try to do it in such a way that zero represents  *
    *  average mobility, but  our formula of doing so is a puer guess.        *
    **************************************************************************/

    scores.MidgameMobility[color] += 4 * (mob - 4);
    scores.EndgameMobility[color] += 4 * (mob - 4);

    /**************************************************************************
    *  Save data about king attacks                                           *
    **************************************************************************/

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 2 * att;
    }

    /**************************************************************************
    * Evaluate king tropism                                                   *
    **************************************************************************/

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.MidgameTropism[color] += 3 * tropism;
    scores.EndgameTropism[color] += 3 * tropism;
}

template<Color TColor>
void EvalBishop(const Board& board, EvaluationScores& scores, const Position position, const EachColor<Bitboard>& pawnControl, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Color opp = color ^ 1;
    
    int att = 0;
    int mob = 0;

    /**************************************************************************
    *  Collect data about mobility and king attacks                           *
    **************************************************************************/
    const Bitboard slide = SlideMoveGenerator::DiagonalAntidiagonalSlide(board.AllPieces, position);
    const Bitboard opponent = board.BitBoard[opp] & slide;
    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        const Bitboard emptyUncontrolled = board.EmptySquares & ~pawnControl[opp] & slide;
        mob += PopCount(emptyUncontrolled);
        mob += PopCount(opponent);
    }

    const Bitboard emptyOrOpponentNearKing = (board.EmptySquares | opponent) & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]] & slide;
    att += PopCount(emptyOrOpponentNearKing);

    scores.MidgameMobility[color] += 3 * (mob - 7);
    scores.EndgameMobility[color] += 3 * (mob - 7);

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 2 * att;
    }

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.MidgameTropism[color] += 2 * tropism;
    scores.EndgameTropism[color] += 1 * tropism;
}

template<Color TColor>
void EvalRook(const Board& board, EvaluationScores& scores, const Position position, const EachColor<Bitboard>& pawnControl, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Color opp = color ^ 1;
    
    int att = 0;
    int mob = 0;

    const File sqCol = Files::Get(position);
    const Rank sqRow = Ranks::Get(position);

    constexpr Rank seventh = EvaluationData::Seventh[color];
    constexpr Rank eighth = EvaluationData::Eighth[color];
    if
    (
        sqRow == seventh
        && (
            (board.BitBoard[Pieces::Pawn | opp] & BitboardConstants::Ranks[seventh]) != 0
            || (board.BitBoard[Pieces::King | opp] & BitboardConstants::Ranks[eighth]) != 0
        )
    )
    {
        scores.MidgameMobility[color] += 20;
        scores.EndgameMobility[color] += 30;
    }

    const Bitboard file = BitboardConstants::Files[sqCol];
    const Bitboard ownPawnsOnFile = board.BitBoard[Pieces::Pawn | color] & file;
    if (ownPawnsOnFile == 0)
    {
        const Bitboard opponentPawnsOnFile = board.BitBoard[Pieces::Pawn | opp] & file;
        if (opponentPawnsOnFile == 0) // fully open file
        {
            scores.MidgameMobility[color] += EvaluationData::RookOpenFile;
            scores.EndgameMobility[color] += EvaluationData::RookOpenFile;
            if (std::abs(sqCol - static_cast<int8_t>(Files::Get(board.KingPositions[opp]))) < 2)
            {
                scores.AttackWeight[color] += 1;
            }
        }
        else // half open file
        {
            scores.MidgameMobility[color] += EvaluationData::RookHalfOpenFile;
            scores.EndgameMobility[color] += EvaluationData::RookHalfOpenFile;
            if (std::abs(sqCol - static_cast<int8_t>(Files::Get(board.KingPositions[opp]))) < 2)
            {
                scores.AttackWeight[color] += 2;
            }
        }
    }

    const Bitboard slide = SlideMoveGenerator::HorizontalVerticalSlide(board.AllPieces, position);
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & slide;
    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        mob += PopCount(emptyOrOpponent);
    }

    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    scores.MidgameMobility[color] += 2 * (mob - 7);
    scores.EndgameMobility[color] += 4 * (mob - 7);

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 3 * att;
    }

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.MidgameTropism[color] += 2 * tropism;
    scores.EndgameTropism[color] += 1 * tropism;
}

template<Color TColor>
void EvalQueen(const Board& board, EvaluationScores& scores, const Position position, const EachColor<Bitboard>& pawnControl, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Color opp = color ^ 1;
    
    int att = 0;
    int mob = 0;

    const Rank sqRow = Ranks::Get(position);

    constexpr Rank seventh = EvaluationData::Seventh[color];
    constexpr Rank eighth = EvaluationData::Eighth[color];
    if
    (
        sqRow == seventh
        && (
            (board.BitBoard[Pieces::Pawn | opp] & BitboardConstants::Ranks[seventh]) != 0
            || (board.BitBoard[Pieces::King | opp] & BitboardConstants::Ranks[eighth]) != 0
        )
    )
    {
        scores.MidgameMobility[color] += 5;
        scores.EndgameMobility[color] += 10;
    }

    if ((color == Colors::White && sqRow > 1) || (color == Colors::Black && sqRow < 6))
    {
        if (IsPiece<color, Pieces::Knight, Positions::Rel<color, Positions::B1>()>(board)) scores.PositionalThemes[color] -= 2;
        if (IsPiece<color, Pieces::Bishop, Positions::Rel<color, Positions::C1>()>(board)) scores.PositionalThemes[color] -= 2;
        if (IsPiece<color, Pieces::Bishop, Positions::Rel<color, Positions::F1>()>(board)) scores.PositionalThemes[color] -= 2;
        if (IsPiece<color, Pieces::Knight, Positions::Rel<color, Positions::G1>()>(board)) scores.PositionalThemes[color] -= 2;
    }

    const Bitboard slide = SlideMoveGenerator::AllSlide(board.AllPieces, position);
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & slide;
    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        mob += PopCount(emptyOrOpponent);
    }

    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    scores.MidgameMobility[color] += 1 * (mob - 14);
    scores.EndgameMobility[color] += 2 * (mob - 14);

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 4 * att;
    }

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.MidgameTropism[color] += 2 * tropism;
    scores.EndgameTropism[color] += 4 * tropism;
}

template<Color TColor>
void EvaluatePieces(const Board& board, EvaluationScores& scores, const EachColor<Bitboard>& pawnControl, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Piece pawn = Pieces::Pawn | color;
    Bitboard pawns = board.BitBoard[pawn];
    while (pawns != 0)
    {
        Position pos = BitScanForward(pawns);
        scores.PieceSquaresMidgame[color] += EvaluationData::Midgame[pawn][pos];
        scores.PieceSquaresEndgame[color] += EvaluationData::Endgame[pawn][pos];
        pawns &= pawns - 1;
    }

    constexpr Piece knight = Pieces::Knight | color;
    Bitboard knights = board.BitBoard[knight];
    while (knights != 0)
    {
        Position pos = BitScanForward(knights);
        EvalKnight<TColor>(board, scores, pos, pawnControl, pinned);
        scores.PieceSquaresMidgame[color] += EvaluationData::Midgame[knight][pos];
        scores.PieceSquaresEndgame[color] += EvaluationData::Endgame[knight][pos];
        knights &= knights - 1;
    }

    constexpr Piece bishop = Pieces::Bishop | color;
    Bitboard bishops = board.BitBoard[bishop];
    while (bishops != 0)
    {
        Position pos = BitScanForward(bishops);
        EvalBishop<TColor>(board, scores, pos, pawnControl, pinned);
        scores.PieceSquaresMidgame[color] += EvaluationData::Midgame[bishop][pos];
        scores.PieceSquaresEndgame[color] += EvaluationData::Endgame[bishop][pos];
        bishops &= bishops - 1;
    }

    constexpr Piece rook = Pieces::Rook | color;
    Bitboard rooks = board.BitBoard[rook];
    while (rooks != 0)
    {
        Position pos = BitScanForward(rooks);
        EvalRook<TColor>(board, scores, pos, pawnControl, pinned);
        scores.PieceSquaresMidgame[color] += EvaluationData::Midgame[rook][pos];
        scores.PieceSquaresEndgame[color] += EvaluationData::Endgame[rook][pos];
        rooks &= rooks - 1;
    }

    constexpr Piece queen = Pieces::Queen | color;
    Bitboard queens = board.BitBoard[queen];
    while (queens != 0)
    {
        Position pos = BitScanForward(queens);
        EvalQueen<TColor>(board, scores, pos, pawnControl, pinned);
        scores.PieceSquaresMidgame[color] += EvaluationData::Midgame[queen][pos];
        scores.PieceSquaresEndgame[color] += EvaluationData::Endgame[queen][pos];
        queens &= queens - 1;
    }

    constexpr Piece king = Pieces::King | color;
    scores.PieceSquaresMidgame[color] += EvaluationData::Midgame[king][board.KingPositions[color]];
    scores.PieceSquaresEndgame[color] += EvaluationData::Endgame[king][board.KingPositions[color]];
}

template<Color TColor>
bool IsPawnSupported(const Board& board, const Position pos)
{
    const Bitboard supportMask = BitboardJumps.PawnSupportJumps[TColor][pos];
    const Bitboard pawns = board.BitBoard[Pieces::Pawn | TColor];
    const bool supported = (supportMask & pawns) != 0;
    return supported;
}

template<Color TColor>
Score EvalPawn(const Board& board, const Position position, const EachColor<Bitboard>& pawnControl, const Bitboard bitboard)
{
    constexpr Color side = TColor;
    constexpr Color oppo = side ^ 1;
    constexpr Piece ownPawn = Pieces::Pawn | side;
    constexpr Piece opponentPawn = Pieces::Pawn | oppo;
    
    int result = 0;
    bool flagIsPassed = true; // we will be trying to disprove that
    bool flagIsWeak = true;   // we will be trying to disprove that
    bool flagIsOpposed = false;

    if ((bitboard & pawnControl[oppo]) != 0)
    {
        flagIsPassed = false;
    }

    const Bitboard inFront = InFront.ColumnInFront[side][position];
    const Bitboard ownPawnsInFront = inFront & board.BitBoard[ownPawn];
    result -= PopCount(ownPawnsInFront) * 20;

    const Bitboard opponentPawnsInFront = inFront & board.BitBoard[opponentPawn];
    flagIsOpposed = opponentPawnsInFront != 0;

    const Bitboard pawnControlledInFront = inFront & (pawnControl[oppo] | ownPawnsInFront | opponentPawnsInFront);
    flagIsPassed &= pawnControlledInFront == 0;

    /**************************************************************************
    *   Another loop, going backwards and checking whether pawn has support.  *
    *   Here we can at least break out of it for speed optimization.          *
    **************************************************************************/

    const Bitboard behind = InFront.ColumnSortOfBehind[side][position];
    const Bitboard ownControlledBehind = behind & pawnControl[side];
    flagIsWeak = ownControlledBehind == 0;

    /**************************************************************************
    *  Evaluate passed pawns, scoring them higher if they are protected       *
    *  or if their advance is supported by friendly pawns                     *
    **************************************************************************/

    if (flagIsPassed)
    {
        const bool pawnSupported = IsPawnSupported<side>(board, position);

        if (pawnSupported)
        {
            result += EvaluationData::ProtectedPasser[side][position];
        }
        else
        {
            result += EvaluationData::PassedPawn[side][position];
        }
    }

    /**************************************************************************
    *  Evaluate weak pawns, increasing the penalty if they are situated       *
    *  on a half-open file                                                    *
    **************************************************************************/

    if (flagIsWeak)
    {
        result += EvaluationData::WeakPawn[side][position];
        if (!flagIsOpposed)
        {
            result -= 4;
        }
    }

    return result;
}

Score EvalPawnStructure(const Board& board, const EachColor<Bitboard>& pawnControl)
{
    Score result = 0;

    Bitboard whitePawns = board.BitBoard[Pieces::WhitePawn];
    while (whitePawns != 0)
    {
        const Position position = BitScanForward(whitePawns);
        const Bitboard pawnBitboard = GetBitboard(position);

        const Score pawnResult = EvalPawn<Colors::White>(board, position, pawnControl, pawnBitboard);
        result += pawnResult;

        whitePawns &= ~pawnBitboard;
    }

    Bitboard blackPawns = board.BitBoard[Pieces::BlackPawn];
    while (blackPawns != 0)
    {
        const Position position = BitScanForward(blackPawns);
        const Bitboard pawnBitboard = GetBitboard(position);

        const Score pawnResult = EvalPawn<Colors::Black>(board, position, pawnControl, pawnBitboard);
        result -= pawnResult;

        blackPawns &= ~pawnBitboard;
    }

    return result;
}

Score GetPawnScore(const Board& board, const EachColor<Bitboard>& pawnControl)
{
    if (false)
    {
    }
    else
    {
        const Score score = EvalPawnStructure(board, pawnControl);
        return score;
    }
}

Score EvaluateInner(const Board& board, const EachColor<Bitboard>& pins)
{
    EvaluationScores scores = EvaluationScores();

    EachColor<Bitboard> pawnControl;
    pawnControl[Colors::White] = AttacksGenerator::GetAttackedByPawns(board.BitBoard[Pieces::WhitePawn], true);
    pawnControl[Colors::Black] = AttacksGenerator::GetAttackedByPawns(board.BitBoard[Pieces::BlackPawn], false);

    scores.GamePhase =
        board.PieceCounts[Pieces::WhiteKnight]
        + board.PieceCounts[Pieces::WhiteBishop]
        + 2 * board.PieceCounts[Pieces::WhiteRook]
        + 4 * board.PieceCounts[Pieces::WhiteQueen]
        + board.PieceCounts[Pieces::BlackKnight]
        + board.PieceCounts[Pieces::BlackBishop]
        + 2 * board.PieceCounts[Pieces::BlackRook]
        + 4 * board.PieceCounts[Pieces::BlackQueen];

    if (scores.GamePhase > 24)
    {
        scores.GamePhase = 24;
    }

    scores.KingShield[Colors::White] = KingShield<Colors::White>(board);
    scores.KingShield[Colors::Black] = KingShield<Colors::Black>(board);

    BlockedPieces<Colors::White>(board, scores);
    BlockedPieces<Colors::Black>(board, scores);

    if (board.WhiteToMove)
    {
        scores.Result += EvaluationData::Tempo;
    }
    else
    {
        scores.Result -= EvaluationData::Tempo;
    }

    if (board.PieceCounts[Pieces::WhiteBishop] > 1) scores.MaterialAdjustment[Colors::White] += EvaluationData::BishopPair;
    if (board.PieceCounts[Pieces::BlackBishop] > 1) scores.MaterialAdjustment[Colors::Black] += EvaluationData::BishopPair;
    if (board.PieceCounts[Pieces::WhiteKnight] > 1) scores.MaterialAdjustment[Colors::White] += EvaluationData::KnightPair;
    if (board.PieceCounts[Pieces::BlackKnight] > 1) scores.MaterialAdjustment[Colors::Black] += EvaluationData::KnightPair;
    if (board.PieceCounts[Pieces::WhiteRook] > 1) scores.MaterialAdjustment[Colors::White] += EvaluationData::RookPair;
    if (board.PieceCounts[Pieces::BlackRook] > 1) scores.MaterialAdjustment[Colors::Black] += EvaluationData::RookPair;

    scores.MaterialAdjustment[Colors::White] += EvaluationData::KnightPawnAdjust[board.PieceCounts[Pieces::WhitePawn]] * board.PieceCounts[Pieces::WhiteKnight];
    scores.MaterialAdjustment[Colors::Black] += EvaluationData::KnightPawnAdjust[board.PieceCounts[Pieces::BlackPawn]] * board.PieceCounts[Pieces::BlackKnight];
    scores.MaterialAdjustment[Colors::White] += EvaluationData::RookPawnAdjust[board.PieceCounts[Pieces::WhitePawn]] * board.PieceCounts[Pieces::WhiteRook];
    scores.MaterialAdjustment[Colors::Black] += EvaluationData::RookPawnAdjust[board.PieceCounts[Pieces::BlackPawn]] * board.PieceCounts[Pieces::BlackRook];

    const Score pawnScore = GetPawnScore(board, pawnControl);
    scores.Result += pawnScore;

    EvaluatePieces<Colors::White>(board, scores, pawnControl, pins[Colors::White]);
    EvaluatePieces<Colors::Black>(board, scores, pawnControl, pins[Colors::Black]);

    Score midgameScore = 0;
    midgameScore += scores.KingShield[Colors::White];
    midgameScore -= scores.KingShield[Colors::Black];
    midgameScore += board.PieceMaterial[Colors::White];
    midgameScore -= board.PieceMaterial[Colors::Black];
    midgameScore += board.PawnMaterial[Colors::White];
    midgameScore -= board.PawnMaterial[Colors::Black];
    midgameScore += scores.PieceSquaresMidgame[Colors::White];
    midgameScore -= scores.PieceSquaresMidgame[Colors::Black];
    midgameScore += scores.MidgameMobility[Colors::White];
    midgameScore -= scores.MidgameMobility[Colors::Black];
    midgameScore += scores.MidgameTropism[Colors::White];
    midgameScore -= scores.MidgameTropism[Colors::Black];

    Score endgameScore = 0;
    endgameScore += board.PieceMaterial[Colors::White];
    endgameScore -= board.PieceMaterial[Colors::Black];
    endgameScore += board.PawnMaterial[Colors::White];
    endgameScore -= board.PawnMaterial[Colors::Black];
    endgameScore += scores.PieceSquaresEndgame[Colors::White];
    endgameScore -= scores.PieceSquaresEndgame[Colors::Black];
    endgameScore += scores.EndgameMobility[Colors::White];
    endgameScore -= scores.EndgameMobility[Colors::Black];
    endgameScore += scores.EndgameTropism[Colors::White];
    endgameScore -= scores.EndgameTropism[Colors::Black];


    const Phase midgameWeight = scores.GamePhase;
    const Phase endgameWeight = 24 - midgameWeight;
    scores.Result += ((midgameScore * midgameWeight) + (endgameScore * endgameWeight)) / 24;

    scores.Result += (scores.Blockages[Colors::White] - scores.Blockages[Colors::Black]);
    scores.Result += (scores.PositionalThemes[Colors::White] - scores.PositionalThemes[Colors::Black]);
    scores.Result += (scores.MaterialAdjustment[Colors::White] - scores.MaterialAdjustment[Colors::Black]);

    if (scores.AttackCount[Colors::White] < 2 || board.PieceCounts[Pieces::WhiteQueen] == 0) scores.AttackWeight[Colors::White] = 0;
    if (scores.AttackCount[Colors::Black] < 2 || board.PieceCounts[Pieces::BlackQueen] == 0) scores.AttackWeight[Colors::Black] = 0;
    scores.Result += EvaluationData::SafetyTable[scores.AttackWeight[Colors::White]];
    scores.Result -= EvaluationData::SafetyTable[scores.AttackWeight[Colors::Black]];

    Color stronger;
    Color weaker;
    if (scores.Result > 0)
    {
        stronger = Colors::White;
        weaker = Colors::Black;
    }
    else
    {
        stronger = Colors::Black;
        weaker = Colors::White;
    }

    if (board.PawnMaterial[stronger] == 0)
    {

        if (board.PieceMaterial[stronger] < 400)
        {
            return 0;
        }

        if (board.PawnMaterial[weaker] == 0 && (board.PieceMaterial[stronger] == 2 * EvaluationConstants::PieceValues[Pieces::Knight]))
        {
            return 0;
        }

        if
            (
                board.PieceMaterial[stronger] == EvaluationConstants::PieceValues[Pieces::Rook]
                && board.PieceMaterial[weaker] == EvaluationConstants::PieceValues[Pieces::Knight] // TODO FIXED
                )
        {
            scores.Result /= 2;
        }

        if
            (
                board.PieceMaterial[stronger] == EvaluationConstants::PieceValues[Pieces::Rook]
                && board.PieceMaterial[weaker] == EvaluationConstants::PieceValues[Pieces::Bishop]
                )
        {
            scores.Result /= 2;
        }

        if
            (
                board.PieceMaterial[stronger] == EvaluationConstants::PieceValues[Pieces::Rook] + EvaluationConstants::PieceValues[Pieces::Knight]
                && board.PieceMaterial[weaker] == EvaluationConstants::PieceValues[Pieces::Rook]
                )
        {
            scores.Result /= 2;
        }

        if
            (
                board.PieceMaterial[stronger] == EvaluationConstants::PieceValues[Pieces::Rook] + EvaluationConstants::PieceValues[Pieces::Bishop]
                && board.PieceMaterial[weaker] == EvaluationConstants::PieceValues[Pieces::Rook]
                )
        {
            scores.Result /= 2;
        }
    }

    if (board.ColorToMove == Colors::Black)
    {
        scores.Result = -scores.Result;
    }

    //scores.Print(board);

    return scores.Result;
}

Score Evaluation::Evaluate(const Board& board, const EachColor<Bitboard>& pins)
{
	const Score score = EvaluateInner(board, pins);

    /*auto clone = board;
    clone.FlipColors();
    EachColor<Bitboard> clonePins{};
    PinDetector::GetPinnedToKings(clone, clonePins);
    auto cloneScore = EvaluateInner(clone, clonePins);
    assert(score == cloneScore);*/
	
    return score;
}
