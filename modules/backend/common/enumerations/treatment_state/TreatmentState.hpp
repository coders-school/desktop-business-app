#pragma once

#include <cstdint>
#include <string>

namespace common
{

enum class TreatmentState : uint8_t
{
    Planned = 0,
    Done = 1,
    Unknown = 255
};

std::string toString(const TreatmentState& treatment_state);

} // namespace common
