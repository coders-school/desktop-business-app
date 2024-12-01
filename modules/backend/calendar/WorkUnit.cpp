#include "WorkUnit.hpp"

namespace calendar
{

WorkUnit::WorkUnit(clinic::staff::doctor::iDoctor* doc, clinic::room::iRoom* room) : doc_ptr_(doc), room_ptr_(room)
{
}
void WorkUnit::addNewTimeSlot(std::unique_ptr<calendar::TimeSlot> timeSlot)
{
    _slot_collection.push_back(std::move(timeSlot));
}
clinic::staff::doctor::iDoctor* WorkUnit::getDoctor() const
{
    return doc_ptr_;
}
clinic::room::iRoom* WorkUnit::getRoom() const
{
    return room_ptr_;
}

} // namespace calendar