#pragma once

#include "room/iRoom.hpp"
#include <gmock/gmock.h>

namespace clinic
{
namespace room
{

class MockRoom : public iRoom
{
  public:
    MOCK_METHOD(std::uint8_t, getNumber, (), (const, override));
    MOCK_METHOD(void, updateUsedProducts, (), (override));
};

} // namespace room
} // namespace clinic
