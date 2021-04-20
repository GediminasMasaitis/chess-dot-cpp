#pragma once

#include <string>

#if __cpp_exceptions
#include <stdexcept>
#else
#include <cstdlib>
#endif


enum class ErrorCode
{
	Ok = 0,

	Error = 1
};

[[noreturn]] static void Throw(const ErrorCode code, const std::string description)
{
#if __cpp_exceptions
	throw std::runtime_error(description);
#else
	exit(static_cast<int>(code));
#endif
}

[[noreturn]] static void Throw(const ErrorCode code)
{
	Throw(code, "");
}

[[noreturn]] static void Throw(const std::string description)
{
	Throw(ErrorCode::Error, description);
}

static void Throw()
{
	Throw(ErrorCode::Error, "");
}