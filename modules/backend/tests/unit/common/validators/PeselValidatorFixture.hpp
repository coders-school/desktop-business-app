#pragma once

#include "validators/PeselValidator.hpp"
#include <gtest/gtest.h>

namespace common
{

namespace validators
{

class PeselValidatorFixture : public ::testing::Test
{
  protected:
    void ExpectNoThrow(const std::string& pesel)
    {
        EXPECT_NO_THROW(validator.Validate(pesel));
    }

    void ExpectThrow(const std::string& pesel)
    {
        EXPECT_THROW(validator.Validate(pesel), std::invalid_argument);
    }

  private:
    PeselValidator validator{};
};

} // namespace validators
} // namespace common
