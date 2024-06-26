#pragma once

#include <cstdint>
#include <string>

namespace common
{
namespace allergen
{

enum class Allergen : uint8_t
{
    Allergen = 0,
    AnotherAllergen = 1,
    SomeAllergen = 2,
    DifferentAllergen = 3,
    Unknown = 255
};

std::string toString(const Allergen shift);
Allergen toEnum(const std::string &shift);

} // namespace allergen
} // namespace common
