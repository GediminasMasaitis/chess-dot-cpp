#include "evaluation.h"

#include "attacks.h"
#include "magics.h"

#include <iostream>

#include "movegen.h"
#include "options.h"

class EvaluationScores
{
public:
    Score Result = 0;
    Phase GamePhase = 0; // function of piece material: 24 in opening, 0 in endgame

    EachPhase<EachColor<Score>> Material{};
    EachPhase<EachColor<Score>> Mobility{};
    EachPhase<EachColor<Score>> Tropism{};
    EachPhase<EachColor<Score>> PieceSquares{};
    EachPhase<EachColor<Score>> MaterialAdjustment{};
    
    EachColor<Score> AttackCount{};
    EachColor<Score> AttackWeight{};
    EachColor<Score> KingShield{};
    EachColor<Score> Blockages{};
    EachColor<Score> PositionalThemes{};
    
    void Clear()
    {
        GamePhase = 0;
        for (Piece side = 0; side <= 1; side++)
        {
            for(PhaseStage stage = PhaseStages::Midgame; stage < PhaseStages::Count; stage++)
            {
                Material[stage][side] = 0;
                Mobility[stage][side] = 0;
                Tropism[stage][side] = 0;
                PieceSquares[stage][side] = 0;
                MaterialAdjustment[stage][side] = 0;
            }
            
            AttackCount[side] = 0;
            AttackWeight[side] = 0;
            KingShield[side] = 0;
            Blockages[side] = 0;
            PositionalThemes[side] = 0;
        }
    }

    static void PrintEachColor(const EachColor<Score>& scores, const std::string header)
    {
        std::cout << header << "; White: " << scores[Colors::White] << ", Black: " << scores[Colors::Black] << ", Diff: " << (scores[Colors::White] - scores[Colors::Black]) << std::endl;
    }
    
    void Print(const BoardBase& board)
    {
        std::cout << "Result: " << Result << std::endl;
        std::cout << "Phase: " << std::to_string(GamePhase) << std::endl;
        PrintEachColor(board.PawnMaterial, "Pawn material");
        PrintEachColor(board.PieceMaterial, "Piece material");
        PrintEachColor(Mobility[PhaseStages::Midgame], "Midgame mobility");
        PrintEachColor(Mobility[PhaseStages::Endgame], "Endgame mobility");
        PrintEachColor(AttackCount, "Attack count");
        PrintEachColor(AttackWeight, "Attack weight");
        PrintEachColor(Tropism[PhaseStages::Midgame], "Midgame tropism");
        PrintEachColor(Tropism[PhaseStages::Endgame], "Endgame tropism");
        PrintEachColor(KingShield, "King shield");
        PrintEachColor(MaterialAdjustment[PhaseStages::Midgame], "Midgame material adjustment");
        PrintEachColor(MaterialAdjustment[PhaseStages::Endgame], "Endgame material adjustment");
        PrintEachColor(Blockages, "Blockages");
        PrintEachColor(PositionalThemes, "PositionalThemes");
        PrintEachColor(PieceSquares[PhaseStages::Midgame], "Piece squares midgame");
        PrintEachColor(PieceSquares[PhaseStages::Endgame], "Piece squares endgame");
    }
};

class AttackDetails
{
public:
    EachPiece<Bitboard> PieceAttacks;
    EachPosition<Bitboard> AttacksFrom;
};

template<Color TColor>
Score KingShield(const BoardBase& board)
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
constexpr bool IsPieceRel(const BoardBase& board)
{
    constexpr Position relativePos = Positions::Rel<TColor>(TPosition);
    constexpr Piece piece = TPiece | TColor;
    return board.ArrayBoard[relativePos] == piece;
}

template<Color TColor, Piece TPiece, Position TPosition>
constexpr bool IsPiece(const BoardBase& board)
{
    constexpr Piece piece = TPiece | TColor;
    return board.ArrayBoard[TPosition] == piece;
}

template<Color TColor>
void BlockedPieces(const BoardBase& board, EvaluationScores& scores)
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

//template<Color TColor>
//Bitboard GetPawnFutureAttacks(const Board& board, const AttackDetails& attacks)
//{
//	
//}

//Bitboard GetOutpostSquares(const Board& board)

template<Color TColor>
void EvalKnight(const BoardBase& board, EvaluationScores& scores, const Position position, const AttackDetails& attacks, const Bitboard pinned)
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

    const Bitboard attack = attacks.AttacksFrom[position];
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & attack;
    const Bitboard mobility = emptyOrOpponent & ~attacks.PieceAttacks[Pieces::Pawn | opp];
    const Bitboard bitboard = GetBitboard(position);   
    if ((bitboard & pinned) == 0)
    {
        mob += PopCount(mobility);
    }

    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    /**************************************************************************
    *  Evaluate mobility. We try to do it in such a way that zero represents  *
    *  average mobility, but  our formula of doing so is a puer guess.        *
    **************************************************************************/

    scores.Mobility[PhaseStages::Midgame][color] += 4 * (mob - 4);
    scores.Mobility[PhaseStages::Endgame][color] += 4 * (mob - 4);

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
    scores.Tropism[PhaseStages::Midgame][color] += 3 * tropism;
    scores.Tropism[PhaseStages::Endgame][color] += 3 * tropism;
}

template<Color TColor>
void EvalBishop(const BoardBase& board, EvaluationScores& scores, const Position position, const AttackDetails& attacks, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Color opp = color ^ 1;
    
    int att = 0;
    int mob = 0;

    /**************************************************************************
    *  Collect data about mobility and king attacks                           *
    **************************************************************************/
    const Bitboard attack = attacks.AttacksFrom[position];
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & attack;
    const Bitboard mobility = emptyOrOpponent & ~attacks.PieceAttacks[Pieces::Pawn | opp];
    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        mob += PopCount(mobility);
    }
    
    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    scores.Mobility[PhaseStages::Midgame][color] += 3 * (mob - 7);
    scores.Mobility[PhaseStages::Endgame][color] += 3 * (mob - 7);

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 2 * att;
    }

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.Tropism[PhaseStages::Midgame][color] += 2 * tropism;
    scores.Tropism[PhaseStages::Endgame][color] += 1 * tropism;
}

template<Color TColor>
void EvalRook(const BoardBase& board, EvaluationScores& scores, const Position position, const AttackDetails& attacks, const Bitboard pinned)
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
        scores.Mobility[PhaseStages::Midgame][color] += 20;
        scores.Mobility[PhaseStages::Endgame][color] += 30;
    }

    const Bitboard file = BitboardConstants::Files[sqCol];
    const Bitboard ownPawnsOnFile = board.BitBoard[Pieces::Pawn | color] & file;
    if (ownPawnsOnFile == 0)
    {
        const Bitboard opponentPawnsOnFile = board.BitBoard[Pieces::Pawn | opp] & file;
        if (opponentPawnsOnFile == 0) // fully open file
        {
            scores.Mobility[PhaseStages::Midgame][color] += EvaluationData::RookOpenFile;
            scores.Mobility[PhaseStages::Endgame][color] += EvaluationData::RookOpenFile;
            if (std::abs(sqCol - static_cast<int8_t>(Files::Get(board.KingPositions[opp]))) < 2)
            {
                scores.AttackWeight[color] += 1;
            }
        }
        else // half open file
        {
            scores.Mobility[PhaseStages::Midgame][color] += EvaluationData::RookHalfOpenFile;
            scores.Mobility[PhaseStages::Endgame][color] += EvaluationData::RookHalfOpenFile;
            if (std::abs(sqCol - static_cast<int8_t>(Files::Get(board.KingPositions[opp]))) < 2)
            {
                scores.AttackWeight[color] += 2;
            }
        }
    }

    const Bitboard attack = attacks.AttacksFrom[position];
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & attack;
    const Bitboard mobility = emptyOrOpponent
        & ~attacks.PieceAttacks[Pieces::Pawn | opp]
        //& ~attacks.PieceAttacks[Pieces::Knight | opp]
        //& ~attacks.PieceAttacks[Pieces::Bishop | opp]
    ;
    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        mob += PopCount(mobility);
    }

    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    scores.Mobility[PhaseStages::Midgame][color] += 2 * (mob - 7);
    scores.Mobility[PhaseStages::Endgame][color] += 4 * (mob - 7);

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 3 * att;
    }

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.Tropism[PhaseStages::Midgame][color] += 2 * tropism;
    scores.Tropism[PhaseStages::Endgame][color] += 1 * tropism;
}

template<Color TColor>
void EvalQueen(const BoardBase& board, EvaluationScores& scores, const Position position, const AttackDetails& attacks, const Bitboard pinned)
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
        scores.Mobility[PhaseStages::Midgame][color] += 5;
        scores.Mobility[PhaseStages::Endgame][color] += 10;
    }

    if ((color == Colors::White && sqRow > 1) || (color == Colors::Black && sqRow < 6))
    {
        if (IsPiece<color, Pieces::Knight, Positions::Rel<color, Positions::B1>()>(board)) scores.PositionalThemes[color] -= 2;
        if (IsPiece<color, Pieces::Bishop, Positions::Rel<color, Positions::C1>()>(board)) scores.PositionalThemes[color] -= 2;
        if (IsPiece<color, Pieces::Bishop, Positions::Rel<color, Positions::F1>()>(board)) scores.PositionalThemes[color] -= 2;
        if (IsPiece<color, Pieces::Knight, Positions::Rel<color, Positions::G1>()>(board)) scores.PositionalThemes[color] -= 2;
    }

    const Bitboard attack = attacks.AttacksFrom[position];
    //const Bitboard attack2 = SlideMoveGenerator::AllSlide(board.AllPieces, position);
    //assert(attack == attack2);
    const Bitboard opponent = board.BitBoard[opp];
    const Bitboard emptyOrOpponent = (board.EmptySquares | opponent) & attack;
    const Bitboard mobility = emptyOrOpponent
        & ~attacks.PieceAttacks[Pieces::Pawn | opp]
        //& ~attacks.PieceAttacks[Pieces::Knight | opp]
        //& ~attacks.PieceAttacks[Pieces::Bishop | opp]
        //& ~attacks.PieceAttacks[Pieces::Rook | opp]
    ;
    const Bitboard bitboard = GetBitboard(position);
    if ((bitboard & pinned) == 0)
    {
        mob += PopCount(mobility);
    }

    const Bitboard emptyOrOpponentNearKing = emptyOrOpponent & BitboardJumps.KingExtendedJumps[opp][board.KingPositions[opp]];
    att += PopCount(emptyOrOpponentNearKing);

    scores.Mobility[PhaseStages::Midgame][color] += 1 * (mob - 14);
    scores.Mobility[PhaseStages::Endgame][color] += 2 * (mob - 14);

    if (att > 0)
    {
        scores.AttackCount[color] += 1;
        scores.AttackWeight[color] += 4 * att;
    }

    const Tropism tropism = GetTropism(position, board.KingPositions[opp]);
    scores.Tropism[PhaseStages::Midgame][color] += 2 * tropism;
    scores.Tropism[PhaseStages::Endgame][color] += 4 * tropism;
}

template<Color TColor>
void EvaluatePieces(const BoardBase& board, EvaluationScores& scores, const AttackDetails& attacks, const Bitboard pinned)
{
    constexpr Color color = TColor;
    constexpr Piece pawn = Pieces::Pawn | color;
    Bitboard pawns = board.BitBoard[pawn];
    while (pawns != 0)
    {
        Position pos = BitScanForward(pawns);
        scores.Material[PhaseStages::Midgame][color] += EvaluationData::Material[PhaseStages::Midgame][Pieces::Pawn];
        scores.Material[PhaseStages::Endgame][color] += EvaluationData::Material[PhaseStages::Endgame][Pieces::Pawn];
        scores.PieceSquares[PhaseStages::Midgame][color] += EvaluationData::Midgame[pawn][pos];
        scores.PieceSquares[PhaseStages::Endgame][color] += EvaluationData::Endgame[pawn][pos];
        pawns &= pawns - 1;
    }

    constexpr Piece knight = Pieces::Knight | color;
    Bitboard knights = board.BitBoard[knight];
    while (knights != 0)
    {
        Position pos = BitScanForward(knights);
        EvalKnight<TColor>(board, scores, pos, attacks, pinned);
        scores.Material[PhaseStages::Midgame][color] += EvaluationData::Material[PhaseStages::Midgame][Pieces::Knight];
        scores.Material[PhaseStages::Endgame][color] += EvaluationData::Material[PhaseStages::Endgame][Pieces::Knight];
        scores.PieceSquares[PhaseStages::Midgame][color] += EvaluationData::Midgame[knight][pos];
        scores.PieceSquares[PhaseStages::Endgame][color] += EvaluationData::Endgame[knight][pos];
        knights &= knights - 1;
    }

    constexpr Piece bishop = Pieces::Bishop | color;
    Bitboard bishops = board.BitBoard[bishop];
    while (bishops != 0)
    {
        Position pos = BitScanForward(bishops);
        EvalBishop<TColor>(board, scores, pos, attacks, pinned);
        scores.Material[PhaseStages::Midgame][color] += EvaluationData::Material[PhaseStages::Midgame][Pieces::Bishop];
        scores.Material[PhaseStages::Endgame][color] += EvaluationData::Material[PhaseStages::Endgame][Pieces::Bishop];
        scores.PieceSquares[PhaseStages::Midgame][color] += EvaluationData::Midgame[bishop][pos];
        scores.PieceSquares[PhaseStages::Endgame][color] += EvaluationData::Endgame[bishop][pos];
        bishops &= bishops - 1;
    }

    constexpr Piece rook = Pieces::Rook | color;
    Bitboard rooks = board.BitBoard[rook];
    while (rooks != 0)
    {
        Position pos = BitScanForward(rooks);
        EvalRook<TColor>(board, scores, pos, attacks, pinned);
        scores.Material[PhaseStages::Midgame][color] += EvaluationData::Material[PhaseStages::Midgame][Pieces::Rook];
        scores.Material[PhaseStages::Endgame][color] += EvaluationData::Material[PhaseStages::Endgame][Pieces::Rook];
        scores.PieceSquares[PhaseStages::Midgame][color] += EvaluationData::Midgame[rook][pos];
        scores.PieceSquares[PhaseStages::Endgame][color] += EvaluationData::Endgame[rook][pos];
        rooks &= rooks - 1;
    }

    constexpr Piece queen = Pieces::Queen | color;
    Bitboard queens = board.BitBoard[queen];
    while (queens != 0)
    {
        Position pos = BitScanForward(queens);
        EvalQueen<TColor>(board, scores, pos, attacks, pinned);
        scores.Material[PhaseStages::Midgame][color] += EvaluationData::Material[PhaseStages::Midgame][Pieces::Queen];
        scores.Material[PhaseStages::Endgame][color] += EvaluationData::Material[PhaseStages::Endgame][Pieces::Queen];
        scores.PieceSquares[PhaseStages::Midgame][color] += EvaluationData::Midgame[queen][pos];
        scores.PieceSquares[PhaseStages::Endgame][color] += EvaluationData::Endgame[queen][pos];
        queens &= queens - 1;
    }

    constexpr Piece king = Pieces::King | color;
    scores.PieceSquares[PhaseStages::Midgame][color] += EvaluationData::Midgame[king][board.KingPositions[color]];
    scores.PieceSquares[PhaseStages::Endgame][color] += EvaluationData::Endgame[king][board.KingPositions[color]];
}

template<Color TColor>
bool IsPawnSupported(const BoardBase& board, const Position pos)
{
    const Bitboard supportMask = BitboardJumps.PawnSupportJumps[TColor][pos];
    const Bitboard pawns = board.BitBoard[Pieces::Pawn | TColor];
    const bool supported = (supportMask & pawns) != 0;
    return supported;
}

template<Color TColor>
Score EvalPawn(const BoardBase& board, const Position position, const AttackDetails& attacks, const Bitboard bitboard)
{
    constexpr Color side = TColor;
    constexpr Color oppo = side ^ 1;
    constexpr Piece ownPawn = Pieces::Pawn | side;
    constexpr Piece opponentPawn = Pieces::Pawn | oppo;
    const Bitboard ownPawnControl = attacks.PieceAttacks[ownPawn];
    const Bitboard opponentPawnControl = attacks.PieceAttacks[opponentPawn];
    
    int result = 0;
    bool flagIsPassed = true; // we will be trying to disprove that
    bool flagIsWeak = true;   // we will be trying to disprove that
    bool flagIsOpposed = false;

    if ((bitboard & opponentPawnControl) != 0)
    {
        flagIsPassed = false;
    }

    const Bitboard inFront = InFront.ColumnInFront[side][position];
    const Bitboard ownPawnsInFront = inFront & board.BitBoard[ownPawn];
    result += PopCount(ownPawnsInFront) * EvaluationData::DoubledPawns;

    const Bitboard opponentPawnsInFront = inFront & board.BitBoard[opponentPawn];
    flagIsOpposed = opponentPawnsInFront != 0;

    const Bitboard pawnControlledInFront = inFront & (opponentPawnControl | ownPawnsInFront | opponentPawnsInFront);
    flagIsPassed &= pawnControlledInFront == 0;

    /**************************************************************************
    *   Another loop, going backwards and checking whether pawn has support.  *
    *   Here we can at least break out of it for speed optimization.          *
    **************************************************************************/

    const Bitboard behind = InFront.ColumnSortOfBehind[side][position];
    const Bitboard ownControlledBehind = behind & ownPawnControl;
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

Score EvalPawnStructure(const BoardBase& board, const AttackDetails& attacks)
{
    Score result = 0;

    Bitboard whitePawns = board.BitBoard[Pieces::WhitePawn];
    while (whitePawns != 0)
    {
        const Position position = BitScanForward(whitePawns);
        const Bitboard pawnBitboard = GetBitboard(position);

        const Score pawnResult = EvalPawn<Colors::White>(board, position, attacks, pawnBitboard);
        result += pawnResult;

        whitePawns &= ~pawnBitboard;
    }

    Bitboard blackPawns = board.BitBoard[Pieces::BlackPawn];
    while (blackPawns != 0)
    {
        const Position position = BitScanForward(blackPawns);
        const Bitboard pawnBitboard = GetBitboard(position);

        const Score pawnResult = EvalPawn<Colors::Black>(board, position, attacks, pawnBitboard);
        result -= pawnResult;

        blackPawns &= ~pawnBitboard;
    }

    return result;
}

Score GetPawnScore(const BoardBase& board, const AttackDetails& attacks, EvalState& state)
{
    PhaseScore score;
    if (state.PawnTable.Enable && state.PawnTable.TryProbe(board.PawnKey, score))
    {
        return static_cast<Score>(score);
    }

    score = EvalPawnStructure(board, attacks);
    if(state.PawnTable.Enable)
    {
        state.PawnTable.Store(board.PawnKey, score);
    }
    return static_cast<Score>(score);
}

template<Color TColor, Piece TPiece>
void GetAttackDetailsForPieces(const BoardBase& board, AttackDetails& attacks)
{
    constexpr Piece coloredPiece = TPiece | TColor;
    const Bitboard allPieces = board.AllPieces;
    //const Bitboard notOwnPieces = ~board.BitBoard[TColor];
    Bitboard piecesBitboard = board.BitBoard[coloredPiece];
    Bitboard allAttacks = BitboardConstants::Empty;
    while (piecesBitboard != 0)
    {
        const Position position = BitScanForward(piecesBitboard);
        Bitboard attack;
        if constexpr (TPiece == Pieces::Knight)
        {
            attack = BitboardJumps.KnightJumps[position];
        }
        else if constexpr (TPiece == Pieces::Bishop)
        {
            attack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, position);
        }
        else if constexpr (TPiece == Pieces::Rook)
        {
            attack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, position);
        }
        else if constexpr (TPiece == Pieces::Queen)
        {
            attack = SlideMoveGenerator::AllSlide(allPieces, position);
        }
        else if constexpr (TPiece == Pieces::King)
        {
            attack = BitboardJumps.KingJumps[position];
        }
        else
        {
            Throw();
        }
        
        //attack &= notOwnPieces;
        attacks.AttacksFrom[position] = attack;
        allAttacks |= attack;
        piecesBitboard &= piecesBitboard - 1;
    }
    attacks.PieceAttacks[coloredPiece] = allAttacks;
    attacks.PieceAttacks[TColor] |= allAttacks;
}

template<Color TColor>
void GetAttackDetailsForColor(const BoardBase& board, AttackDetails& attacks)
{
    attacks.PieceAttacks[TColor] = BitboardConstants::Empty;
    GetAttackDetailsForPieces<TColor, Pieces::Knight>(board, attacks);
    GetAttackDetailsForPieces<TColor, Pieces::Bishop>(board, attacks);
    GetAttackDetailsForPieces<TColor, Pieces::Rook>(board, attacks);
    GetAttackDetailsForPieces<TColor, Pieces::Queen>(board, attacks);
    GetAttackDetailsForPieces<TColor, Pieces::King>(board, attacks);

    constexpr Piece coloredPawn = Pieces::Pawn | TColor;
    constexpr bool forWhite = TColor == Colors::White;
    const Bitboard pawnAttacks = AttacksGenerator::GetAttackedByPawns(board.BitBoard[coloredPawn], forWhite);
    attacks.PieceAttacks[coloredPawn] = pawnAttacks;
    attacks.PieceAttacks[TColor] |= pawnAttacks;
}

void GetAttackDetails(const BoardBase& board, AttackDetails& attacks)
{
    GetAttackDetailsForColor<Colors::White>(board, attacks);
    GetAttackDetailsForColor<Colors::Black>(board, attacks);
}

Score EvaluateInner(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
{
    EvaluationScores scores = EvaluationScores();

    AttackDetails attacks;
    GetAttackDetails(board, attacks);

    scores.GamePhase =
        PiecePhases[Pieces::WhiteKnight] *board.PieceCounts[Pieces::WhiteKnight]
        + PiecePhases[Pieces::WhiteBishop] * board.PieceCounts[Pieces::WhiteBishop]
        + PiecePhases[Pieces::WhiteRook] * board.PieceCounts[Pieces::WhiteRook]
        + PiecePhases[Pieces::WhiteQueen] * board.PieceCounts[Pieces::WhiteQueen]
        + PiecePhases[Pieces::BlackKnight] * board.PieceCounts[Pieces::BlackKnight]
        + PiecePhases[Pieces::BlackBishop] * board.PieceCounts[Pieces::BlackBishop]
        + PiecePhases[Pieces::BlackRook] * board.PieceCounts[Pieces::BlackRook]
        + PiecePhases[Pieces::BlackQueen] * board.PieceCounts[Pieces::BlackQueen];

    if (scores.GamePhase > MaxPhase)
    {
        scores.GamePhase = MaxPhase;
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

    if (board.PieceCounts[Pieces::WhiteBishop] > 1)
    {
        scores.MaterialAdjustment[PhaseStages::Midgame][Colors::White] += EvaluationData::BishopPair[PhaseStages::Midgame];
        scores.MaterialAdjustment[PhaseStages::Endgame][Colors::White] += EvaluationData::BishopPair[PhaseStages::Endgame];
    }
    if (board.PieceCounts[Pieces::BlackBishop] > 1)
    {
        scores.MaterialAdjustment[PhaseStages::Midgame][Colors::Black] += EvaluationData::BishopPair[PhaseStages::Midgame];
        scores.MaterialAdjustment[PhaseStages::Endgame][Colors::Black] += EvaluationData::BishopPair[PhaseStages::Endgame];
    }
    if (board.PieceCounts[Pieces::WhiteKnight] > 1)
    {
        scores.MaterialAdjustment[PhaseStages::Midgame][Colors::White] += EvaluationData::KnightPair[PhaseStages::Midgame];
        scores.MaterialAdjustment[PhaseStages::Endgame][Colors::White] += EvaluationData::KnightPair[PhaseStages::Endgame];
    }
    if (board.PieceCounts[Pieces::BlackKnight] > 1)
    {
        scores.MaterialAdjustment[PhaseStages::Midgame][Colors::Black] += EvaluationData::KnightPair[PhaseStages::Midgame];
        scores.MaterialAdjustment[PhaseStages::Endgame][Colors::Black] += EvaluationData::KnightPair[PhaseStages::Endgame];
    }
    if (board.PieceCounts[Pieces::WhiteRook] > 1)
    {
        scores.MaterialAdjustment[PhaseStages::Midgame][Colors::White] += EvaluationData::RookPair[PhaseStages::Midgame];
        scores.MaterialAdjustment[PhaseStages::Endgame][Colors::White] += EvaluationData::RookPair[PhaseStages::Endgame];
    }
    if (board.PieceCounts[Pieces::BlackRook] > 1)
    {
        scores.MaterialAdjustment[PhaseStages::Midgame][Colors::Black] += EvaluationData::RookPair[PhaseStages::Midgame];
        scores.MaterialAdjustment[PhaseStages::Endgame][Colors::Black] += EvaluationData::RookPair[PhaseStages::Endgame];
    }

    scores.MaterialAdjustment[PhaseStages::Midgame][Colors::White] += EvaluationData::KnightPawnAdjust[board.PieceCounts[Pieces::WhitePawn]] * board.PieceCounts[Pieces::WhiteKnight];
    scores.MaterialAdjustment[PhaseStages::Endgame][Colors::White] += EvaluationData::KnightPawnAdjust[board.PieceCounts[Pieces::WhitePawn]] * board.PieceCounts[Pieces::WhiteKnight];
    scores.MaterialAdjustment[PhaseStages::Midgame][Colors::Black] += EvaluationData::KnightPawnAdjust[board.PieceCounts[Pieces::BlackPawn]] * board.PieceCounts[Pieces::BlackKnight];
    scores.MaterialAdjustment[PhaseStages::Endgame][Colors::Black] += EvaluationData::KnightPawnAdjust[board.PieceCounts[Pieces::BlackPawn]] * board.PieceCounts[Pieces::BlackKnight];
    scores.MaterialAdjustment[PhaseStages::Midgame][Colors::White] += EvaluationData::RookPawnAdjust[board.PieceCounts[Pieces::WhitePawn]] * board.PieceCounts[Pieces::WhiteRook];
    scores.MaterialAdjustment[PhaseStages::Endgame][Colors::White] += EvaluationData::RookPawnAdjust[board.PieceCounts[Pieces::WhitePawn]] * board.PieceCounts[Pieces::WhiteRook];
    scores.MaterialAdjustment[PhaseStages::Midgame][Colors::Black] += EvaluationData::RookPawnAdjust[board.PieceCounts[Pieces::BlackPawn]] * board.PieceCounts[Pieces::BlackRook];
    scores.MaterialAdjustment[PhaseStages::Endgame][Colors::Black] += EvaluationData::RookPawnAdjust[board.PieceCounts[Pieces::BlackPawn]] * board.PieceCounts[Pieces::BlackRook];

    const Score pawnScore = GetPawnScore(board, attacks, state);
    scores.Result += pawnScore;

    EvaluatePieces<Colors::White>(board, scores, attacks, pins[Colors::White]);
    EvaluatePieces<Colors::Black>(board, scores, attacks, pins[Colors::Black]);

    //assert((board.PieceMaterial[Colors::White] + board.PawnMaterial[Colors::White]) == scores.Material[EvalPhases::Midgame][Colors::White]);
    //assert((board.PieceMaterial[Colors::Black] + board.PawnMaterial[Colors::Black]) == scores.Material[EvalPhases::Midgame][Colors::Black]);

    Score midgameScore = 0;
    midgameScore += scores.KingShield[Colors::White];
    midgameScore -= scores.KingShield[Colors::Black];
    midgameScore += scores.Material[PhaseStages::Midgame][Colors::White];
    midgameScore -= scores.Material[PhaseStages::Midgame][Colors::Black];
    midgameScore += scores.PieceSquares[PhaseStages::Midgame][Colors::White];
    midgameScore -= scores.PieceSquares[PhaseStages::Midgame][Colors::Black];
    midgameScore += scores.Mobility[PhaseStages::Midgame][Colors::White];
    midgameScore -= scores.Mobility[PhaseStages::Midgame][Colors::Black];
    midgameScore += scores.MaterialAdjustment[PhaseStages::Midgame][Colors::White];
    midgameScore -= scores.MaterialAdjustment[PhaseStages::Midgame][Colors::Black];

    Score endgameScore = 0;
    endgameScore += scores.Material[PhaseStages::Endgame][Colors::White];
    endgameScore -= scores.Material[PhaseStages::Endgame][Colors::Black];
    endgameScore += scores.PieceSquares[PhaseStages::Endgame][Colors::White];
    endgameScore -= scores.PieceSquares[PhaseStages::Endgame][Colors::Black];
    endgameScore += scores.Mobility[PhaseStages::Endgame][Colors::White];
    endgameScore -= scores.Mobility[PhaseStages::Endgame][Colors::Black];
    endgameScore += scores.Tropism[PhaseStages::Endgame][Colors::White];
    endgameScore -= scores.Tropism[PhaseStages::Endgame][Colors::Black];
    endgameScore += scores.MaterialAdjustment[PhaseStages::Endgame][Colors::White];
    endgameScore -= scores.MaterialAdjustment[PhaseStages::Endgame][Colors::Black];

    const Phase midgameWeight = scores.GamePhase;
    const Phase endgameWeight = MaxPhase - midgameWeight;
    scores.Result += ((midgameScore * midgameWeight) + (endgameScore * endgameWeight)) / MaxPhase;

    scores.Result += (scores.Blockages[Colors::White] - scores.Blockages[Colors::Black]);
    scores.Result += (scores.PositionalThemes[Colors::White] - scores.PositionalThemes[Colors::Black]);

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

    //Score kingTropism = GetTropism(board.KingPositions[Colors::White], board.KingPositions[Colors::Black]);
    //Score materialDiff = board.PieceMaterial[Colors::White] - board.PieceMaterial[Colors::Black];
    //Score kingProximityBonus = (materialDiff * endgameWeight * kingTropism) / (EvaluationData::MaxPhase * 20);
    //scores.Result += kingProximityBonus;
    
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

Score ClassicEvaluation::Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
{
    PhaseScore score;
    if(state.EvalTable.Enable && state.EvalTable.TryProbe(board.Key, score))
    {
        return static_cast<Score>(score);
    }
    
    score = EvaluateInner(board, pins, state);
    if (state.EvalTable.Enable)
    {
        state.EvalTable.Store(board.Key, score);
    }
    

    /*auto clone = board;
    clone.FlipColors();
    EachColor<Bitboard> clonePins{};
    PinDetector::GetPinnedToKings(clone, clonePins);
    auto cloneScore = EvaluateInner(clone, clonePins);
    assert(score == cloneScore);*/
    
    return static_cast<Score>(score);
}
