#pragma once

#include <memory>
#include <vector>

#include "room/iRoom.hpp"
#include "doctors/iDoctor.hpp"
#include "TimeSlot.hpp"

namespace calendar
{

class WorkUnit
{
  public:
    explicit WorkUnit(clinic::staff::doctor::iDoctor* doc, clinic::room::iRoom* room);
    void addNewTimeSlot(std::unique_ptr<calendar::TimeSlot> timeSlot);
    clinic::staff::doctor::iDoctor* getDoctor() const;
    clinic::room::iRoom* getRoom() const;

  private:
    std::vector<std::unique_ptr<calendar::TimeSlot>> time_slots_;
    clinic::staff::doctor::iDoctor* doc_;
    clinic::room::iRoom* room_;
};

} // namespace calendar
