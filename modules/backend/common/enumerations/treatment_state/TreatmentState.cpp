#include "TreatmentState.hpp"

namespace common
{

namespace treatment_state
{
std::string toString(const TreatmentState& treatment_state)
{
    switch (treatment_state)
    {
    case TreatmentState::Planned:
        return "Planned";
    case TreatmentState::Done:
        return "Done";
    default:
        return "Unknown";
    }
}

TreatmentState toEnum(const std::string& treatment_state)
{
    if (treatment_state == "Planned")
    {
        return TreatmentState::Planned;
    }
    else if (treatment_state == "Done")
    {
        return TreatmentState::Done;
    }
    else
    {
        return TreatmentState::Unknown;
    }
}

} // namespace treatment_state
} // namespace common
