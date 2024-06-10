#include "Treatment.hpp"

#include <map>

namespace common
{

namespace treatment
{

namespace
{

const std::map<Treatment, std::string> DentalTreatments = {
    {Treatment::TeethCleaning, "teeth cleaning"},   {Treatment::RootCanal, "root canal"},
    {Treatment::DentalFilling, "dental filling"},   {Treatment::ToothExtraction, "tooth extraction"},
    {Treatment::TeethWhitening, "teeth whitening"}, {Treatment::DentalImplants, "dental implants"},
    {Treatment::Orthodontics, "orthodontics"},      {Treatment::Periodontics, "periodontics"},
    {Treatment::DentalVeneers, "dental veneers"},   {Treatment::DentalCrowns, "dental crowns"},
    {Treatment::DentalBridges, "dental bridges"},   {Treatment::Dentures, "dentures"},
    {Treatment::GumSurgery, "gum surgery"},         {Treatment::DentalSealants, "dental sealants"},
    {Treatment::MouthGuards, "mouth guards"},       {Treatment::SleepApneaTreatment, "sleep apnea treatment"},
    {Treatment::OTHER, "other treatment type"}};

} // namespace

std::string toString(Treatment dental_treatment)
{
    auto searched_pair = DentalTreatments.find(dental_treatment);

    return searched_pair != DentalTreatments.end() ? searched_pair->second : "other treatment type";
}

Treatment toEnum(const std::string& treatment_name)
{
    for (const auto& pair : DentalTreatments)
    {
        if (pair.second == treatment_name)
        {
            return pair.first;
        }
    }
    return Treatment::OTHER;
}

} // namespace treatment
} // namespace common
