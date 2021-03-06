#pragma once

#include "constants.h"
#include "bits.h"
#include "error.h"

#include <array>
#include <cassert>
#include <string>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cstring>
#include <atomic>
#include <chrono>
#include <iomanip>

#define MAYBE_UNUSED(x) ((void)(x))

#ifdef __GNUC__
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

#ifdef _MSC_VER
#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
#endif

template<class T>
static std::string TrimNumber(const T number, double divisor, const std::string& sufffix)
{
    const double divided = static_cast<double>(number) / divisor;
    std::string str = std::to_string(divided);
    if (str.find(".") != std::string::npos)
    {
        const auto newLength = str.length() < 5 ? str.length() : 5;
        str = str.substr(0, newLength);
        while (str[str.length() - 1] == '0')
        {
            str = str.substr(0, str.length() - 1);
        }
        while (str[str.length() - 1] == '.')
        {
            str = str.substr(0, str.length() - 1);
        }
    }
    else
    {
        const auto newLength = str.length() < 4 ? str.length() : 4;
        str = str.substr(0, newLength);
    }

    return str + sufffix;
}

template<class T>
static std::string ToUserFriendly(T number)
{
    const std::string numberStr = std::to_string(number);
    switch (numberStr.length())
    {
    case 1:
    case 2:
    case 3:
        return numberStr;
    case 4:
    case 5:
    case 6:
        return TrimNumber(number, 1000, "k");
    case 7:
    case 8:
    case 9:
        return TrimNumber(number, 1000000, "M");
    case 10:
    case 11:
    case 12:
        return TrimNumber(number, 1000000000, "B");
    case 13:
    case 14:
    case 15:
        return TrimNumber(number, 1000000000000, "T");
    default:
        return numberStr;
    }
}

static std::string HumanReadableDuration(std::chrono::seconds input_seconds)
{
    using namespace std::chrono;
    typedef duration<int, std::ratio<86400>> days;
    const auto d = duration_cast<days>(input_seconds);
    input_seconds -= d;
    const auto h = duration_cast<hours>(input_seconds);
    input_seconds -= h;
    const auto m = duration_cast<minutes>(input_seconds);
    input_seconds -= m;
    const auto s = duration_cast<seconds>(input_seconds);

    std::stringstream ss;
    ss.fill('0');
    ss << d.count() << ".";
    ss << std::setw(2);
    ss << h.count() << ":";
    ss << std::setw(2);
    ss << m.count() << ":";
    ss << std::setw(2);
    ss << s.count();
    return ss.str();
}

constexpr Rank GetRank(const Position position)
{
    return position >> 3;
}

constexpr File GetFile(const Position position)
{
    return position & 7;
}

constexpr Position GetPosition(const File file, const Rank rank)
{
    return static_cast<Position>(file | (rank << 3));
}

enum class GameOutcome : int8_t
{
    Unknown,
    Win,
    Draw,
    Loss
};