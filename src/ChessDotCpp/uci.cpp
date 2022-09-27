#include "uci.h"


#include "datagen.h"
#include "displaysearch.h"
#include "texel.h"

void Uci::OnCallback(SearchCallbackData& data) const
{
	const ThreadState& mainThreadState = data.State.Thread[0];
	std::stringstream builder = std::stringstream();
	//builder << std::to_string(data.Board.cacheSets) << " " << std::to_string(data.Board.cacheUnsets) << " " << std::to_string(data.Board.cacheSets + data.Board.cacheUnsets) << " " << std::to_string(data.Board.cacheCount) << " " << std::to_string((data.Board.cacheSets + data.Board.cacheUnsets) / static_cast<double>(data.Board.cacheCount)) << "\n";
	builder << "info";
	if(data.Aborted)
	{
		//builder << " aborted";
	}
	builder << " depth " << std::to_string(data.Depth);
	builder << " seldepth " << std::to_string(data.State.Thread[0].SelectiveDepth);

	builder << " multipv 1";
	if(data._Score > Constants::MateThreshold)
	{
		const Score mateInPlies = static_cast<Score>(Constants::Mate - data._Score);
		const Score mateInMoves = static_cast<Score>((mateInPlies + 1) / 2);
		builder << " score mate " << std::to_string(mateInMoves);
	}
	else if(data._Score < -Constants::MateThreshold)
	{
		const Score mateInPlies = static_cast<Score>(Constants::Mate + data._Score);
		const Score mateInMoves = static_cast<Score>((mateInPlies + 1) / 2);
		builder << " score mate -" << std::to_string(mateInMoves);
	}
	else
	{
		builder << " score cp " << std::to_string(data._Score);
	}
	
	builder << " nodes " << std::to_string(mainThreadState.Stats.Nodes);
	auto elapsed = mainThreadState.Stats.Elapsed;
	if (elapsed == 0)
	{
		elapsed = 1;
	}

	Stat nodes = 0;
	for(auto i = 0; i < Options::Threads; i++)
	{
		nodes += data.State.Thread[i].Stats.Nodes;
	}

	auto nps = (nodes * 1000) / elapsed;

	builder << " nps " << nps;
	builder << " time " << elapsed;

	builder << " pv";
	std::vector<Move>& principalVariation = data.State.Thread[data.Id].SavedPrincipalVariation;
	for (size_t ply = 0; ply < principalVariation.size(); ply++)
	{
		const auto& entry = principalVariation[ply];
		builder << " " << entry.ToPositionString();
	}

    //MoveArray moves;
    //MoveCount moveCount = 0;
    //MoveGenerator::GetAllPossibleMoves(board, moves, moveCount);
    //for(MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    //{
    //    const auto move = moves[moveIndex];
    //    const auto moveTotalNodes = mainThreadState.NodesPerMove[move.GetFrom()][move.GetTo()];
    //    const auto moveNodePercent = (moveTotalNodes * 100) / mainThreadState.Stats.Nodes;
    //    builder << move.ToPositionString() << " " << moveNodePercent << "% " << moveTotalNodes << " nodes\n";
    //}

	Out(builder.str());
}

void Uci::HandleMoves(std::stringstream& reader)
{
	while (!reader.eof())
	{
		MoveString moveStr;
		reader >> moveStr;

		board.DoMove(moveStr);
	}
}

void Uci::HandleStartpos(std::stringstream& reader)
{
	Fens::Parse(board, StartingFen);
	if (!reader.eof())
	{
		std::string type;
		reader >> type;

		if (type == "moves")
		{
			HandleMoves(reader);
		}
	}
}

void Uci::HandleFen(std::stringstream& reader)
{
	std::stringstream fenBuilder;
	bool hasMoves = false;
	while (!reader.eof())
	{
		std::string fenPart;
		reader >> fenPart;
		if (fenPart == "moves")
		{
			hasMoves = true;
			break;
		}
		fenBuilder << fenPart << " ";
	}

	std::string fen = fenBuilder.str();
	Fens::Parse(board, fen);

	if (hasMoves)
	{
		HandleMoves(reader);
	}
}

void Uci::HandlePosition(std::stringstream& reader)
{
	std::string type;
	reader >> type;

	if (type == "startpos")
	{
		HandleStartpos(reader);
	}
	else if (type == "moves")
	{
		Fens::Parse(board, StartingFen);
		HandleMoves(reader);
	}
	else if (type == "fen")
	{
		HandleFen(reader);
	}
}

void ReadSearchParameters(std::stringstream& reader, SearchParameters& parameters)
{
	while (!reader.eof())
	{
		std::string word;
		reader >> word;

		if (word == "wtime")
		{
			reader >> parameters.WhiteTime;
		}
		else if (word == "btime")
		{
			reader >> parameters.BlackTime;
		}
		else if (word == "winc")
		{
			reader >> parameters.WhiteTimeIncrement;
		}
		else if (word == "binc")
		{
			reader >> parameters.BlackTimeIncrement;
		}
		else if (word == "depth")
		{
			uint16_t depth;
			reader >> depth;
			parameters.MaxDepth = static_cast<uint8_t>(depth);
		}
		else if (word == "nodes")
		{
			size_t nodes;
			reader >> nodes;
			parameters.MinNodes = nodes;
			parameters.MaxNodes = nodes;
		}
		else if (word == "infinite")
		{
			parameters.Infinite = true;
		}
	}
}

void Uci::HandleGo(std::stringstream& reader)
{
	SearchParameters parameters = SearchParameters();
	ReadSearchParameters(reader, parameters);

	SearchResults results;
	search.Run(board, parameters, results);
	Out("bestmove " + results.BestMove.ToPositionString());
}

std::string GetOptionStrValue(const std::string& input)
{
    if(input == "<empty>")
    {
		return "";
    }
	return input;
}

void Uci::PrintOptions()
{
	Out("option name Hash type spin default " + std::to_string(Options::Defaults::Hash) + " min 1 max 1024");
	Out("option name Threads type spin default " + std::to_string(Options::Defaults::Threads) + " min 1 max 64");
	Out("option name SyzygyPath type string default <empty> min 1 max 64");
	Out("option name TUNE1 type spin default 0 min -2147483647 max 2147483647");
	Out("option name TUNE2 type spin default 0 min -2147483647 max 2147483647");
	Out("option name TUNE3 type spin default 0 min -2147483647 max 2147483647");
}

void Uci::HandleUci()
{
	Out("id name ChessDotCpp");
	Out("id author Gediminas Masaitis");
	Out("");
	PrintOptions();
	Out("uciok");
}



void Uci::HandleSetoption(std::stringstream& reader)
{
	std::string temp;
	std::string name;
	std::string value;
	reader >> temp >> name >> temp >> value;

	if(name.empty() || value.empty())
	{
		return;
	}

	if (name == "Hash") {
		Options::Hash = static_cast<size_t>(std::stoull(value));
		search.State.Global.Table.SetSizeFromOptions();
	}
	else if (name == "Threads") {
		Options::Threads = static_cast<ThreadId>(std::stoull(value));
		//search.State.NewGame();
		search.State.Initialized = false;
	}
	else if (name == "SyzygyPath") {
		Options::SyzygyPath = GetOptionStrValue(value);
		Tablebases::Init(Options::SyzygyPath);
	}
	else if (name == "TUNE1") {
		Options::Tune1 = static_cast<int32_t>(std::stoi(value));
	}
	else if (name == "TUNE2") {
		Options::Tune2 = static_cast<int32_t>(std::stoi(value));
	}
	else if (name == "TUNE3") {
		Options::Tune3 = static_cast<int32_t>(std::stoi(value));
	}
}

void Uci::HandleIsReady()
{
	Out("readyok");
}

void Uci::HandleUciNewGame()
{
	search.State.NewGame();
	Fens::Parse(board, StartingFen);
}

void Uci::HandleDisplaySearch(std::stringstream& reader)
{
	SearchParameters parameters;
	parameters.MinNodes = 1000000;
	parameters.MaxNodes = 1000000;
	ReadSearchParameters(reader, parameters);
	DisplaySearch::DisplayBoard(board, parameters);
}

bool Uci::HandleInput(const std::string& line)
{
	std::stringstream reader(line);

	while (!reader.eof())
	{
		std::string word;
		reader >> word;

		if (word == "position")
		{
			HandlePosition(reader);
		}
		else if (word == "go")
		{
			HandleGo(reader);
		}
		else if (word == "gi")
		{
			HandleInput("go infinite");
		}
		else if (word == "uci")
		{
			HandleUci();
		}
		else if (word == "setoption")
		{
			HandleSetoption(reader);
		}
		else if (word == "ucinewgame")
		{
			HandleUciNewGame();
		}
		else if (word == "isready")
		{
			HandleIsReady();
		}
		else if (word == "tune")
		{
			Texel::Run();
		}
		else if (word == "datagen")
		{
			DataGenerator::Run();
		}
		else if (word == "d")
		{
			DisplayEval::DisplayBoard(board);
		}
		else if (word == "ds")
		{
			HandleDisplaySearch(reader);
		}
		else if (word == "quit")
		{
			return false;
		}
	}

	return true;
}

void Uci::Init()
{
	Fens::Parse(board, StartingFen);
}

void Uci::Run()
{
	Init();
	while (true)
	{
		std::string line = In();
		const bool shouldContinue = HandleInput(line);
		if (!shouldContinue)
		{
			break;
		}
	}
}
