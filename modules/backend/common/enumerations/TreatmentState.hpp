#pragma once

#include <cstdint>
#include <string>

enum class TreatmentState : uint8_t
{
    Planned = 0,
    Done = 1,
    Unknown = 255
};

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
