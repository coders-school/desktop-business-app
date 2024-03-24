#include "treatment_test.hpp"

namespace
{

const std::map<Treatment, std::string> expectedDentalTreatments = {
    {Treatment::TeethCleaning, "Teeth Cleaning"},   {Treatment::RootCanal, "Root Canal"},
    {Treatment::DentalFilling, "Dental Filling"},   {Treatment::ToothExtraction, "Tooth Extraction"},
    {Treatment::TeethWhitening, "Teeth Whitening"}, {Treatment::DentalImplants, "Dental Implants"},
    {Treatment::Orthodontics, "Orthodontics"},      {Treatment::Periodontics, "Periodontics"},
    {Treatment::DentalVeneers, "Dental Veneers"},   {Treatment::DentalCrowns, "Dental Crowns"},
    {Treatment::DentalBridges, "Dental Bridges"},   {Treatment::Dentures, "Dentures"},
    {Treatment::GumSurgery, "Gum Surgery"},         {Treatment::DentalSealants, "Dental Sealants"},
    {Treatment::MouthGuards, "Mouth Guards"},       {Treatment::SleepApneaTreatment, "Sleep Apnea Treatment"}};

TEST_P(TreatmentParameterizedFixture, GivenTreatmentEnumToStringShouldProvideCorrectStringRepresentation)
{

    const auto& [enumValue, stringRepresentation] = GetParam();

    EXPECT_EQ(toString(enumValue), stringRepresentation);
}

INSTANTIATE_TEST_SUITE_P(TreatmentConversionToStringTest, TreatmentParameterizedFixture,
                         ::testing::ValuesIn(expectedDentalTreatments));
} // namespace
