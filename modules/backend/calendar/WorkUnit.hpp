#pragma once

#include <memory>
#include <vector>

#include "../clinic/room/iRoom.hpp"
#include "../clinic/staff/doctors/iDoctor.hpp"
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
    std::vector<std::unique_ptr<calendar::TimeSlot>> _slot_collection;
    clinic::staff::doctor::iDoctor* doc_ptr_;
    clinic::room::iRoom* room_ptr_;
};

} // namespace calendar
