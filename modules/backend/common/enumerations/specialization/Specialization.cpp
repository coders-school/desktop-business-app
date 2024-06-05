#include "Specialization.hpp"

namespace common
{
namespace specialization
{
std::string toString(const Specialization& specialization)
{
    switch (specialization)
    {
    case Specialization::Dentist:
        return "Dentist";
    default:
        return "Unknown";
    }
}

Specialization toEnum(const std::string& specialization)
{
    if (specialization == "Dentist")
    {
        return Specialization::Dentist;
    }
    return Specialization::Unknown;
}

} // namespace specialization
} // namespace common
