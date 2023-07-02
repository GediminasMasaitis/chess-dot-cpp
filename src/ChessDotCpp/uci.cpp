#include "uci.h"


#include "datagen.h"
#include "displaysearch.h"
#include "perft.h"
#include "texel.h"

void Uci::OnCallback(SearchCallbackData& data) const
{
	const ThreadState& mainThreadState = data.State.Thread[0];
	std::stringstream builder = std::stringstream();

	builder << "info";
	if (data.Aborted)
	{
		//builder << " aborted";
	}
	builder << " depth " << std::to_string(data.Depth);
	builder << " seldepth " << std::to_string(data.State.Thread[0].SelectiveDepth);

	builder << " multipv " << static_cast<uint32_t>(data.MultiPv + 1);
	if (data._Score > Constants::MateThreshold)
	{
		const Score mateInPlies = static_cast<Score>(Constants::Mate - data._Score);
		const Score mateInMoves = static_cast<Score>((mateInPlies + 1) / 2);
		builder << " score mate " << std::to_string(mateInMoves);
	}
	else if (data._Score < -Constants::MateThreshold)
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
	for (auto i = 0; i < Options::Threads; i++)
	{
		nodes += data.State.Thread[i].Stats.Nodes;
	}

	auto nps = (nodes * 1000) / elapsed;

	builder << " nps " << nps;
	builder << " time " << elapsed;

	builder << " pv";
	const auto& principalVariation = mainThreadState.SavedPrincipalVariations[data.MultiPv];
	for (MoveCount ply = 0; ply < principalVariation.Length; ply++)
	{
		const auto& entry = principalVariation.Moves[ply];
		builder << " " << entry.ToPositionString();
	}

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

void Uci::ReadMoves(std::stringstream& reader, MoveArray& moves, MoveCount& moveCount, bool doMoves, bool undoMoves)
{
    const auto boardBackup = board;
	while (!reader.eof())
	{
		MoveString moveStr;
		reader >> moveStr;

		Move move;
		board.FromPositionString(moveStr, move);
		if(doMoves)
		{
			board.DoMove(move);
		}

		moves[moveCount] = move;
		moveCount++;
	}
	if(undoMoves)
	{
		board = boardBackup;
	}
}

void Uci::ReadSearchParameters(std::stringstream& reader, SearchParameters& parameters)
{
	while (!reader.eof())
	{
		std::string word;
		reader >> word;

		if(word == "movetime")
		{
			reader >> parameters.MoveTime;
		}
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
		else if(word == "searchmoves")
		{
			ReadMoves(reader, parameters.SearchMoves, parameters.SearchMoveCount, false, false);
		}
		else if (word == "multipv")
		{
			uint64_t multiPv;
			reader >> multiPv;
			if(multiPv > 218)
			{
				multiPv = 218;
			}
			parameters.MultiPv = static_cast<Ply>(multiPv);
		}
		else if (word == "ucithread")
		{
			parameters.UciThread = true;
		}
	}
}

void Uci::HandleGo(std::stringstream& reader)
{
	SearchParameters parameters = SearchParameters();
	parameters.MultiPv = Options::MultiPv;
	ReadSearchParameters(reader, parameters);

	if (parameters.UciThread)
	{
		SearchResults results;
		search.Run(board, parameters, results);
		Out("bestmove " + results.BestMove.ToPositionString());
	}
	else
	{
		auto lock = std::unique_lock<std::mutex>(SearchMutex);
		if (IsSearching)
		{
			SearchThread.join();
		}

		IsSearching = true;
		SearchThread = std::thread([this, parameters]()
		{
			SearchResults results;
			search.Run(board, parameters, results);
			Out("bestmove " + results.BestMove.ToPositionString());
		});
	}
	
}

void Uci::HandleStop()
{
	auto lock = std::unique_lock<std::mutex>(SearchMutex);
	if (!IsSearching)
	{
		return;
	}


	search.State.Thread[0].Stopper.Stopped = true;
	IsSearching = false;
	SearchThread.join();
}

void Uci::HandlePerft(std::stringstream& reader)
{
	uint16_t depth;
	if(!reader.eof())
	{
		reader >> depth;
		PerftRunner::Run(board, static_cast<Ply>(depth));
	}
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
	Out("option name MultiPV type spin default " + std::to_string(Options::Defaults::MultiPv) + " min 1 max 218");
	Out("option name NnuePath type string default <empty>");
	Out("option name SyzygyPath type string default <empty>");
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

	if (name == "Hash")
	{
		Options::Hash = static_cast<size_t>(std::stoull(value));
		search.State.Global.Table.SetSizeFromOptions();
	}
	else if (name == "Threads")
	{
		Options::Threads = static_cast<ThreadId>(std::stoull(value));
		//search.State.NewGame();
		search.State.Initialized = false;
	}
	else if(name == "MultiPV")
	{
		auto multiPv = std::stoull(value);
		if(multiPv > 218)
		{
			multiPv = 218;
		}
		Options::MultiPv = static_cast<MoveCount>(multiPv);
	}
#if NNUE
	else if (name == "NnuePath")
	{
		Options::NnuePath = GetOptionStrValue(value);
		EvaluationNnueBase::Init();
	}
#endif
	else if (name == "SyzygyPath")
	{
		Options::SyzygyPath = GetOptionStrValue(value);
		Tablebases::Init(Options::SyzygyPath);
	}
	else if (name == "TUNE1")
	{
		Options::Tune1 = static_cast<int32_t>(std::stoi(value));
	}
	else if (name == "TUNE2")
	{
		Options::Tune2 = static_cast<int32_t>(std::stoi(value));
	}
	else if (name == "TUNE3")
	{
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

void Uci::HandleDisplayMoves(std::stringstream& reader)
{
	MoveArray moves;
	MoveCount moveCount = 0;
	ReadMoves(reader, moves, moveCount, true, true);
	DisplayEval::DisplayBoard(board);
	const Board boardBackup = board;
	for(auto moveIndex = 0; moveIndex < moveCount; moveIndex++)
	{
		const Move move = moves[moveIndex];
		board.DoMove(move);
		DisplayEval::DisplayBoard(board, move);
	}
	board = boardBackup;
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
		else if (word == "stop")
		{
			HandleStop();
		}
		else if (word == "perft")
		{
			HandlePerft(reader);
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
		else if(word == "dm")
		{
			HandleDisplayMoves(reader);
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
	IsSearching = false;
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
