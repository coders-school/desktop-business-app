#include "TimeSlot.hpp"

namespace calendar
{

TimeSlot::TimeSlot(const std::chrono::time_point<std::chrono::system_clock>& time_point,
                   const std::chrono::minutes& duration, visit::iVisit* visit)

    : time_point_{time_point}, duration_{duration}, visit_{visit}
{
}

std::chrono::minutes TimeSlot::getDuration() const
{
    return duration_;
}

void TimeSlot::changeDuration(const std::chrono::minutes& duration)
{
    duration_ = duration;
}

void TimeSlot::assignVisit(visit::iVisit* visit)
{
    visit_ = visit;
}

visit::iVisit* TimeSlot::getVisit() const
{
    return visit_;
}

bool TimeSlot::operator<(const TimeSlot& other) const
{
    return (time_point_ + duration_) < other.time_point_;
}

bool TimeSlot::operator>(const TimeSlot& other) const
{
    return time_point_ > (other.time_point_ + other.duration_);
}

bool TimeSlot::operator==(const TimeSlot& other) const
{
    return time_point_ == other.time_point_;
}

bool TimeSlot::operator!=(const TimeSlot& other) const
{
    return !(*this == other);
}

} // namespace calendar
