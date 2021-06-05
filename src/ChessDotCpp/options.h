#pragma once

#include "types.h"

class Options
{
public:

	static inline size_t Hash = 16;
	static inline ThreadId Threads = 1;
	static inline int MoveOverhead = 0;
	
	Options() = delete;
};