#pragma once

#include <string>

namespace common
{

struct Address
{
    std::string city_;
    std::string country_;
    std::string province_;
    std::string street_;
    std::string zip_code_;
};

} // namespace common
