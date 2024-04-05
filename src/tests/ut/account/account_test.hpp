#pragma once
#include "account.hpp"
#include "gtest/gtest.h"

struct AccountTestFixture : public ::testing::Test
{
    Account account{"admin", "password"};
};
