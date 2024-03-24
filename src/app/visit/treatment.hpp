#pragma once

#include <string>

enum class Treatment : unsigned
{
    TeethCleaning,
    RootCanal,
    DentalFilling,
    ToothExtraction,
    TeethWhitening,
    DentalImplants,
    Orthodontics,
    Periodontics,
    DentalVeneers,
    DentalCrowns,
    DentalBridges,
    Dentures,
    GumSurgery,
    DentalSealants,
    MouthGuards,
    SleepApneaTreatment
};

std::string toString(Treatment dentalTreatment);
