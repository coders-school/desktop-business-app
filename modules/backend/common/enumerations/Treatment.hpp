#pragma once

#include <cstdint>
#include <string>

namespace common
{

enum class Treatment : uint32_t
{
    TeethCleaning = 0,
    RootCanal = 1,
    DentalFilling = 2,
    ToothExtraction = 3,
    TeethWhitening = 4,
    DentalImplants = 5,
    Orthodontics = 6,
    Periodontics = 7,
    DentalVeneers = 8,
    DentalCrowns = 9,
    DentalBridges = 10,
    Dentures = 11,
    GumSurgery = 12,
    DentalSealants = 13,
    MouthGuards = 14,
    SleepApneaTreatment = 15,
    OTHER = 16
};

std::string toString(Treatment dental_treatment);

} // namespace common
