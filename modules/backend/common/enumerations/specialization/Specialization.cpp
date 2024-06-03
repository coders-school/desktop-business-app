#include "Specialization.hpp"

namespace common
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

} // namespace common
