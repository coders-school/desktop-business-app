#pragma once

#include <memory>
#include <vector>

namespace clinic
{

namespace staff
{
class Staff;
}

namespace room
{
class iRoom;
}
class Clinic
{
  public:
    Clinic(std::unique_ptr<staff::Staff> staff, std::vector<std::unique_ptr<room::iRoom>> rooms);

  private:
    std::unique_ptr<staff::Staff> staff_;
    std::vector<std::unique_ptr<room::iRoom>> rooms_;
};

} // namespace clinic
