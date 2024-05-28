#pragma once

#include <memory>
#include <vector>
#include "clinic/staff/i_staff.hpp"
#include "modules/backend/clinic/staff/room/i_room.hpp"

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
