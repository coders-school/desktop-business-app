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
    }

    return {};
}

} // namespace common
