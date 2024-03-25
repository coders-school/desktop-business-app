#include "treatment_test.hpp"

namespace
{

const std::map<Treatment, std::string> TestParams = {
    {Treatment::TeethCleaning, "teeth cleaning"},   {Treatment::RootCanal, "root canal"},
    {Treatment::DentalFilling, "dental filling"},   {Treatment::ToothExtraction, "tooth extraction"},
    {Treatment::TeethWhitening, "teeth whitening"}, {Treatment::DentalImplants, "dental implants"},
    {Treatment::Orthodontics, "orthodontics"},      {Treatment::Periodontics, "periodontics"},
    {Treatment::DentalVeneers, "dental veneers"},   {Treatment::DentalCrowns, "dental crowns"},
    {Treatment::DentalBridges, "dental bridges"},   {Treatment::Dentures, "dentures"},
    {Treatment::GumSurgery, "gum surgery"},         {Treatment::DentalSealants, "dental sealants"},
    {Treatment::MouthGuards, "mouth guards"},       {Treatment::SleepApneaTreatment, "sleep apnea treatment"},
    {Treatment::OTHER, "other treatment type"}};

TEST_P(TreatmentParameterizedFixture, GivenTreatmentEnumToStringShouldProvideCorrectStringRepresentation)
{

    const auto& [enumValue, stringRepresentation] = GetParam();

    EXPECT_EQ(toString(enumValue), stringRepresentation);
}

INSTANTIATE_TEST_SUITE_P(TreatmentConversionToStringTest, TreatmentParameterizedFixture,
                         ::testing::ValuesIn(TestParams));
} // namespace
