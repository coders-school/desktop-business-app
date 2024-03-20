#include "shift.hpp"

std::string toString(const Shift& shift)
{
    std::string shift_text{};

    switch (shift)
    {
    case Shift::Morning:
        shift_text = "morning shift";
        break;
    case Shift::Afternoon:
        shift_text = "afternoon shift";
        break;
    default:
        break;
    }

    return shift_text;
}
