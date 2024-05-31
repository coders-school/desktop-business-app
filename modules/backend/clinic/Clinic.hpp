#pragma once

#include "modules/backend/clinic/staff/iStaff.hpp"
#include "modules/backend/clinic/staff/room/iRoom.hpp"
#include <memory>
#include <vector>

class Clinic
{
    std::unique_ptr<iStaff> staff_;
    std::vector<std::unique_ptr<iRoom>> rooms_;

  public:
    Clinic(std::unique_ptr<iStaff> staff, std::vector<std::unique_ptr<iRoom>> rooms)
        : staff_{std::move(staff)}, rooms_{std::move(rooms)}
    {
    }
};
