#pragma once

#include <cstdint>
#include <string>

namespace common
{

namespace treatment_state
{
enum class TreatmentState : uint8_t
{
    Planned = 0,
    Done = 1,
    Unknown = 255
};

std::string toString(const TreatmentState& treatment_state);
TreatmentState toEnum(const std::string& treatment_state);

} // namespace treatment_state
} // namespace common
