#pragma once
#include "encrypt.hpp"
#include "gtest/gtest.h"

struct EncryptTestFixture : public ::testing::Test
{
    Encrypt encrypt;
};
