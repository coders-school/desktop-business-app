#include "TreatmentState.hpp"

namespace common
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

} // namespace common
