#include "WorkUnit.hpp"

namespace calendar
{

WorkUnit::WorkUnit(clinic::staff::doctor::iDoctor* doc, clinic::room::iRoom* room) : doc_(doc), room_(room)
{
}
void WorkUnit::addNewTimeSlot(std::unique_ptr<calendar::TimeSlot> timeSlot)
{
    time_slots_.emplace_back(std::move(timeSlot));
}
clinic::staff::doctor::iDoctor* WorkUnit::getDoctor() const
{
    return doc_;
}
clinic::room::iRoom* WorkUnit::getRoom() const
{
    return room_;
}

} // namespace calendar