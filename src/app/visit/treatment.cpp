#include "treatment.hpp"

#include <map>
#include <stdexcept>

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
