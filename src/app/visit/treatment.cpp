#include "treatment.hpp"

#include <map>
#include <stdexcept>

namespace
{
const std::map<Treatment, std::string> DentalTreatments = {
    {Treatment::TeethCleaning, "Teeth Cleaning"},   {Treatment::RootCanal, "Root Canal"},
    {Treatment::DentalFilling, "Dental Filling"},   {Treatment::ToothExtraction, "Tooth Extraction"},
    {Treatment::TeethWhitening, "Teeth Whitening"}, {Treatment::DentalImplants, "Dental Implants"},
    {Treatment::Orthodontics, "Orthodontics"},      {Treatment::Periodontics, "Periodontics"},
    {Treatment::DentalVeneers, "Dental Veneers"},   {Treatment::DentalCrowns, "Dental Crowns"},
    {Treatment::DentalBridges, "Dental Bridges"},   {Treatment::Dentures, "Dentures"},
    {Treatment::GumSurgery, "Gum Surgery"},         {Treatment::DentalSealants, "Dental Sealants"},
    {Treatment::MouthGuards, "Mouth Guards"},       {Treatment::SleepApneaTreatment, "Sleep Apnea Treatment"}};
} // namespace

std::string toString(Treatment dentalTreatment)
{
    try
    {
        return DentalTreatments.at(dentalTreatment);
    }
    catch (const std::out_of_range& atException)
    {
        return "Unknown treatment enum value!";
    }
}
