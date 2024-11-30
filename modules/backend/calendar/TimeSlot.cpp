#include "TimeSlot.hpp"

calendar::TimeSlot::TimeSlot(const std::chrono::time_point<std::chrono::system_clock>& time_point,
                             const std::chrono::minutes& duration, visit::iVisit* visit = nullptr)

    : time_point_{time_point}, duration_{duration}, visit_{visit}
{
}

std::chrono::minutes calendar::TimeSlot::getDuration() const
{
    return duration_;
}

void calendar::TimeSlot::changeDuration(const std::chrono::minutes& duration)
{
    duration_ = duration;
}

void calendar::TimeSlot::assignVisit(visit::iVisit* visit)
{
    visit_ = visit;
}

bool calendar::TimeSlot::operator<(const TimeSlot& other) const
{
    return (time_point_ + duration_) < other.time_point_;
}
