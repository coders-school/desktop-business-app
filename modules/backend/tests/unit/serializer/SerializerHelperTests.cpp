#include "SerializerHelper.hpp"
#include <gtest/gtest.h>

namespace
{
    
TEST(SerializerHelperTests, serializeSpecialization)
{
    auto specialization = ::common::specialization::Specialization::Dentist;
    auto proto_specialization = ::serde::serializeSpecialization(specialization);
    EXPECT_EQ(proto_specialization, ::proto_common::Specialization::DENTIST);
}

TEST(SerializerHelperTests, deserializeSpecialization)
{
    auto proto_specialization = ::proto_common::Specialization::DENTIST;
    auto specialization = ::serde::deserializeSpecialization(proto_specialization);
    EXPECT_EQ(specialization, ::common::specialization::Specialization::Dentist);
}

} // namespace
