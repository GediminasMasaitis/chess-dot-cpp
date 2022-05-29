#pragma once

#include "uci.h"

#include <queue>
#include <thread>
#include <fstream>
#include <codecvt>
#include <regex>

class Game
{
public:
	static void SelfPlay()
	{
		using Q = std::queue<std::string>;
				
		Q q1 = Q();
		Uci::InType in1 = [&]()
		{
			auto command = q1.front();
			q1.pop();
			return command;
		};
		Uci::OutType out1 = [&](std::string str)
		{
			std::cout << str << std::endl;
		};
		Uci uci1 = Uci(in1, out1);

		q1.push("uci");
		
		uci1.Run();

		/*std::stringstream in2 = std::stringstream();
		std::stringstream out2 = std::stringstream();
		Uci uci2 = Uci(&in2, &out2);*/

		
	}

	static void RunCommands(std::queue<std::string>& commands)
	{
		Uci::InType in = [&]()
		{
			auto command = commands.front();
			std::cerr << ">> " << command << std::endl;
			commands.pop();
			return command;
		};

		Uci::OutType out = [&](std::string str)
		{
			std::cerr << "<< " << str << std::endl;
		};

		Uci uci = Uci(in, out);
		uci.Run();
	}

	static void RunTestCommands()
	{
		std::ifstream file("C:/Temp/gameout.txt");
		std::string str;

		std::queue<std::string> commands{};
		
		while(std::getline(file, str))
		{
			commands.push(str);
		}
		
		//std::queue<std::string> commands(
		//{
		//	"uci",
		//	"ucinewgame",
		//	"position startpos",
		//	"isready",
		//	"go infinite"
		//});

		RunCommands(commands);
	}

	static void RunCuteChessOutput()
	{
		auto target_game = 1;
		auto reg = std::regex(R"(\d+ \>\ChessDotCpp\(0\): (.+))");

		std::ifstream file("C:/Chess/Runners/CuteChess/out2.txt");
		std::string str;

		std::queue<std::string> commands{};
		auto game_num = 0;
		while (std::getline(file, str))
		{
			auto matches = std::smatch();
			if(!std::regex_search(str, matches, reg))
			{
			    continue;
			}

			auto command = matches[1];
			if(command == "ucinewgame")
			{
				game_num++;
			}

			if(game_num == 0 || game_num == target_game)
			{
				commands.push(command);
			}
		}

		commands.push("quit");

		RunCommands(commands);
	}
};
