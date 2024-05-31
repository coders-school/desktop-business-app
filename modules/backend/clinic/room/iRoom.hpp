#pragma once

#include <cstdint>

namespace clinic
{
namespace room
{

class iRoom
{
  public:
    virtual ~iRoom() = 0;
    virtual std::uint8_t getNumber() const = 0;
    virtual void updateUsedProducts() = 0;
};

} // namespace room
} // namespace clinic
