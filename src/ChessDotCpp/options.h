#pragma once

#include "types.h"

//#include <unordered_map>
//
//class OptionMetadata
//{
//public:
//	std::string _name;
//	std::string _value;
//	std::string _min;
//	std::string _max;
//	
//	OptionMetadata(std::string&& name, std::string&& value, std::string&& min, std::string&& max) : _name(name), _value(value), _min(min), _max(max)
//	{
//		
//	};
//};

class Options
{
public:
	class Defaults
	{
	public:
		static constexpr size_t Hash = 16;
		static constexpr ThreadId Threads = 1;

#if NNUE
		static constexpr std::string_view NnuePath = "C:/Chess/Networks/50/nn-epoch500.nnue";
#endif
		static constexpr std::string_view SyzygyPath = "";
		static constexpr MoveCount MultiPv = 1;

		static constexpr int32_t Tune1 = 0;
		static constexpr int32_t Tune2 = 0;
		static constexpr int32_t Tune3 = 0;

		Defaults() = delete;
	};

	static inline size_t Hash = Defaults::Hash;
	static inline ThreadId Threads = Defaults::Threads;
	static inline MoveCount MultiPv = Defaults::MultiPv;

#if NNUE
	static inline std::string NnuePath = std::string(Defaults::NnuePath);
#endif
	static inline std::string SyzygyPath = std::string(Defaults::SyzygyPath);

	static inline int32_t Tune1 = Defaults::Tune1;
	static inline int32_t Tune2 = Defaults::Tune2;
	static inline int32_t Tune3 = Defaults::Tune3;

	Options() = delete;
};