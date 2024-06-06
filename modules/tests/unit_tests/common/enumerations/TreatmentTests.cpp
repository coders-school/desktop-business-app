#include "enumerations/treatment/Treatment.hpp"
#include <gtest/gtest.h>

namespace common
{
namespace treatment
{
namespace tests
{

struct ToStringTestParams
{
    Treatment treatment;
    std::string expected_output;
};

class ToStringTest : public ::testing::TestWithParam<ToStringTestParams>
{
};

TEST_P(ToStringTest, GivenTreatmentWhenToStringCalledThenReturnCorrectString)
{
    Treatment treatment = GetParam().treatment;
    std::string expected_output = GetParam().expected_output;

    std::string output = toString(treatment);

    EXPECT_EQ(output, expected_output);
}

INSTANTIATE_TEST_SUITE_P(Treatment, ToStringTest,
                         ::testing::Values(ToStringTestParams{Treatment::TeethCleaning, "teeth cleaning"},
                                           ToStringTestParams{Treatment::RootCanal, "root canal"},
                                           ToStringTestParams{Treatment::DentalFilling, "dental filling"},
                                           ToStringTestParams{Treatment::ToothExtraction, "tooth extraction"},
                                           ToStringTestParams{Treatment::TeethWhitening, "teeth whitening"},
                                           ToStringTestParams{Treatment::DentalImplants, "dental implants"},
                                           ToStringTestParams{Treatment::Orthodontics, "orthodontics"},
                                           ToStringTestParams{Treatment::Periodontics, "periodontics"},
                                           ToStringTestParams{Treatment::DentalVeneers, "dental veneers"},
                                           ToStringTestParams{Treatment::DentalCrowns, "dental crowns"},
                                           ToStringTestParams{Treatment::DentalBridges, "dental bridges"},
                                           ToStringTestParams{Treatment::Dentures, "dentures"},
                                           ToStringTestParams{Treatment::GumSurgery, "gum surgery"},
                                           ToStringTestParams{Treatment::DentalSealants, "dental sealants"},
                                           ToStringTestParams{Treatment::MouthGuards, "mouth guards"},
                                           ToStringTestParams{Treatment::SleepApneaTreatment, "sleep apnea treatment"},
                                           ToStringTestParams{Treatment::OTHER, "other treatment type"},
                                           ToStringTestParams{static_cast<Treatment>(999), "other treatment type"}));

struct ToEnumTestParams
{
    std::string allergen;
    Treatment expected_treatment;
};

class ToEnumTest : public ::testing::TestWithParam<ToEnumTestParams>
{
};

TEST_P(ToEnumTest, GivenTreatmentStringWhenToEnumCalledThenReturnCorrectTreatment)
{
    std::string allergen = GetParam().allergen;
    Treatment expected_treatment = GetParam().expected_treatment;

    Treatment output = toEnum(allergen);

    EXPECT_EQ(output, expected_treatment);
}

INSTANTIATE_TEST_SUITE_P(Treatment, ToEnumTest,
                         ::testing::Values(ToEnumTestParams{"teeth cleaning", Treatment::TeethCleaning},
                                           ToEnumTestParams{"root canal", Treatment::RootCanal},
                                           ToEnumTestParams{"dental filling", Treatment::DentalFilling},
                                           ToEnumTestParams{"tooth extraction", Treatment::ToothExtraction},
                                           ToEnumTestParams{"teeth whitening", Treatment::TeethWhitening},
                                           ToEnumTestParams{"dental implants", Treatment::DentalImplants},
                                           ToEnumTestParams{"orthodontics", Treatment::Orthodontics},
                                           ToEnumTestParams{"periodontics", Treatment::Periodontics},
                                           ToEnumTestParams{"dental veneers", Treatment::DentalVeneers},
                                           ToEnumTestParams{"dental crowns", Treatment::DentalCrowns},
                                           ToEnumTestParams{"dental bridges", Treatment::DentalBridges},
                                           ToEnumTestParams{"dentures", Treatment::Dentures},
                                           ToEnumTestParams{"gum surgery", Treatment::GumSurgery},
                                           ToEnumTestParams{"dental sealants", Treatment::DentalSealants},
                                           ToEnumTestParams{"mouth guards", Treatment::MouthGuards},
                                           ToEnumTestParams{"sleep apnea treatment", Treatment::SleepApneaTreatment},
                                           ToEnumTestParams{"other treatment type", Treatment::OTHER},
                                           ToEnumTestParams{"invalid", Treatment::OTHER}));

} // namespace tests
} // namespace treatment
} // namespace common