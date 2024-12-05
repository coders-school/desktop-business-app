#pragma once

#include <cstdint>
#include <string>

namespace common
{

namespace phone_code
{

enum class PhoneCode : uint16_t
{
    Greece = 30,
    Netherlands = 31,
    Belgium = 32,
    France = 33,
    Spain = 34,
    Hungary = 36,
    Italy = 39,
    Romania = 40,
    Austria = 43,
    Denmark = 45,
    Sweden = 46,
    Norway = 47,
    Poland = 48,
    Germany = 49,
    Portugal = 351,
    Ireland = 353,
    Luxembourg = 352,
    Iceland = 354,
    Malta = 356,
    Cyprus = 357,
    Finland = 358,
    Bulgaria = 359,
    Lithuania = 370,
    Latvia = 371,
    Estonia = 372,
    Croatia = 385,
    Slovenia = 386,
    CzechRepublic = 420,
    Slovakia = 421,
    Lichtenstein = 423,
    Unkown = 500
};

std::string toString(const PhoneCode& phone_code);
PhoneCode toEnum(const std::string& phone_code);
std::string getPhoneCodeIndex(const PhoneCode& phone_code = PhoneCode::Poland);

} // namespace phone_code
} // namespace common