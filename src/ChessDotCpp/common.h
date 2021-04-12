#pragma once

#include "constants.h"
#include "bits.h"

#include <array>
#include <cassert>
#include <string>

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
