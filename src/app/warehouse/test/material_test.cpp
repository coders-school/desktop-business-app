#include "material_test.hpp"
#include "gtest/gtest.h"

namespace
{

TEST_P(MaterialParameterizedFixture, GivenMaterialEnumeration_ExpectValidConversionToString)
{
    const auto conversion_output = convertMaterial(GetParam().material_input);

    EXPECT_EQ(conversion_output, GetParam().expected_output);
}

INSTANTIATE_TEST_SUITE_P(MaterialConversionTests, MaterialParameterizedFixture,
                         ::testing::Values(TestParams{Material::DentalCement, "Dental cement"},
                                           TestParams{Material::Amalgam, "Amalgam"},
                                           TestParams{Material::DentalComposite, "Dental composite"}));

} // namespace
