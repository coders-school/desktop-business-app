#pragma once
#include "../../../app/login/login.hpp"
#include "gtest/gtest.h"

struct LoginTestFixture : public ::testing::Test
{
    Login login{"admin", "password"};
};
