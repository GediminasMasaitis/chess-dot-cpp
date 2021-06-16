#include "uci.h"

#include "nnuetrain.h"

void Uci::OnCallback(SearchCallbackData& data) const
{
	std::stringstream builder = std::stringstream();

	builder << "info";
	builder << " depth " << std::to_string(data.Depth);
	builder << " multipv 1";
	builder << " score cp " << std::to_string(data._Score);
	builder << " nodes " << std::to_string(data.State.Stats.Nodes);
	auto elapsed = data.State.Stats.Elapsed;
	if (elapsed == 0)
	{
		elapsed = 1;
	}
	auto nps = (data.State.Stats.Nodes * 1000) / elapsed;

	builder << " nps " << nps;
	builder << " time " << elapsed;

	builder << " pv";
	std::vector<Move>& principalVariation = data.State.Thread[data.Id].SavedPrincipalVariation;
	for (size_t ply = 0; ply < principalVariation.size(); ply++)
	{
		const auto& entry = principalVariation[ply];
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
	Fens::Parse(board, startPos);
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
		Fens::Parse(board, startPos);
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

void Uci::HandleUci()
{
	Out("id name ChessDotCpp");
	Out("id author Gediminas Masaitis");
	Out("");
	Out("uciok");
}

void Uci::HandleIsReady()
{
	Out("readyok");
}

void Uci::HandleUciNewGame()
{
	search.State.NewGame();
	Fens::Parse(board, startPos);
}

void Uci::HandleTrain(std::stringstream& reader)
{
	auto parameters = TrainingParameters();
	parameters.SearchParams.WhiteTime = 1000;
	parameters.SearchParams.WhiteTimeIncrement = 50;
	parameters.SearchParams.BlackTime = 1000;
	parameters.SearchParams.BlackTimeIncrement = 50;
	//parameters.SearchParams.SkipNewSearch = true;
	parameters.InputPath = "C:/Chess/TrainingOld/data/fishpack_wins.epd";
	parameters.OffsetPath = "C:/Chess/TrainingOld/data/offset.txt";
	parameters.OutputPath = "C:/Chess/TrainingOld/data/results.plain";
	parameters.OutputFormat = OutputFormats::Plain;
	ReadSearchParameters(reader, parameters.SearchParams);
	NnueTrainer::Run(parameters);
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
		else if (word == "uci")
		{
			HandleUci();
		}
		else if (word == "ucinewgame")
		{
			HandleUciNewGame();
		}
		else if (word == "isready")
		{
			HandleIsReady();
		}
		else if (word == "train")
		{
			HandleTrain(reader);
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
	search.State.NewGame();
	Fens::Parse(board, startPos);
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
