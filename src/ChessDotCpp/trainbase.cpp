#include "trainbase.h"

#include "fen.h"

#include <fstream>
#include <mutex>

bool TrainingReader::ReadLine(std::string& str, size_t skip)
{
	Stream.ignore(skip);
	if(Stream.eof())
	{
		return false;
	}
	
	std::getline(Stream, str);
	Position += skip;
	Position += str.size();
	Position += 2;
	/*size_t streampos = Stream.tellg();
	auto eof = Stream.eof();
	assert(!eof);
	assert(Position == streampos);*/
	return true;
}

bool TrainingReader::ReadPlain(TrainResult& data)
{
	const auto fenSuccess = ReadLine(data.FFen, 4);
	if (!fenSuccess || data.FFen.empty())
	{
		return false;
	}

	ReadLine(data.Move, 5);
	std::string temp;
	ReadLine(temp, 6);
	data.SScore = static_cast<Score>(std::stoi(temp));
	ReadLine(temp, 4);
	data.Ply = static_cast<HistoryPly>(std::stoi(temp));
	ReadLine(temp, 7);
	data.Result = static_cast<int8_t>(std::stoi(temp));
	ReadLine(temp, 0);
	return true;
}

bool TrainingReader::ReadData(TrainResult& data)
{
	if(Stream.eof())
	{
		return false;
	}
	
	std::lock_guard<std::mutex> guard(Mutex);
	switch (Format)
	{
	case InputFormats::Epd:
		std::getline(Stream, data.FFen);
		return true;
	case InputFormats::Plain:
		const bool success = ReadPlain(data);
		return success;
	}
	return false;
}

size_t TrainingReader::GetCurrentOffset() const
{
	//const size_t offset = Stream.tellg();
	//return offset;
	return Position;
}

void TrainingWriter::WriteResultsPlain(const TrainResult& result)
{
	Stream << "fen " << result.FFen << "\n";
	Stream << "move " << result.Move << "\n";
	Stream << "score " << result.SScore << "\n";
	Stream << "ply " << result.Ply << "\n";
	Stream << "result 1\n";
	Stream << "e\n";
}

void TrainingWriter::WriteResults(const TrainResult& result, const bool flush)
{
	switch (Format)
	{
	case OutputFormats::Plain:
		WriteResultsPlain(result);
		break;
	}

	if (flush)
	{
		Stream.flush();
	}
}

template <class TBoard>
void BoardCache<TBoard>::LoadAll(size_t limit)
{
	auto entry = BoardCacheEntry<TBoard>();
	size_t index = 0;
	while ((limit == 0 || index < limit) && Reader.ReadData(entry.Result))
	{
		entry.Index = index;
		Fens::Parse(entry.Board, entry.Result.FFen);
		Entries.push_back(entry);
		index++;
	}
}

template class BoardCache<BoardBase>;
template class BoardCache<Board>;