#include <stdexcept>
#include "Sex.hpp"

namespace common
{
    
std::string toString(const Sex& sex)
{
    switch (sex)
    {
    case Sex::Male:
        return "Male";
    case Sex::Female:
        return "Female";
    default:
        throw std::invalid_argument("Invalid sex value");
    }
}

Sex toEnum(const std::string& sex)
{
    if (sex == "Male")
    {
        return Sex::Male;
    }
    else if (sex == "Female")
    {
        return Sex::Female;
    }
    else
    {
        throw std::invalid_argument("Invalid sex value");
    }
}

} // namespace common
