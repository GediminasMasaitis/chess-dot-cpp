#pragma once

#include <string>

#if __cpp_exceptions
#include <stdexcept>
#else
#include <cstdlib>
#endif

#define UNUSED(x) (void)(x)

enum class ErrorCode
{
	Ok = 0,

	Error = 1
};

[[noreturn]] [[maybe_unused]] static void Throw(const ErrorCode code, const std::string description)
{
#if __cpp_exceptions
	UNUSED(code);
	throw std::runtime_error(description);
#else
	UNUSED(description);
	exit(static_cast<int>(code));
#endif
}

[[noreturn]] [[maybe_unused]] static void Throw(const ErrorCode code)
{
	Throw(code, "");
}

[[noreturn]] [[maybe_unused]] static void Throw(const std::string description)
{
	Throw(ErrorCode::Error, description);
}

[[noreturn]] [[maybe_unused]] static void Throw()
{
	Throw(ErrorCode::Error, "");
}