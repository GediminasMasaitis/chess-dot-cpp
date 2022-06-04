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
	//using MetadataMap = std::unordered_map<std::string, OptionMetadata>;
	//static inline MetadataMap Metadata = MetadataMap();
	
	static inline size_t Hash = 16;
	static inline ThreadId Threads = 1;
	static inline int MoveOverhead = 0;

	static inline int32_t Tune1 = 100;
	static inline int32_t Tune2 = 0;
	static inline int32_t Tune3 = 0;
	
	Options() = delete;
};