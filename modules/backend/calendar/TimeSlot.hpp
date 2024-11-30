#pragma once

#include "visit/iVisit.hpp"
#include <chrono>

namespace calendar
{

class TimeSlot
{
  public:
    explicit TimeSlot(const std::chrono::time_point<std::chrono::system_clock>& time_point,
                      const std::chrono::minutes& duration, visit::iVisit* visit);

    std::chrono::minutes getDuration() const;

    void changeDuration(const std::chrono::minutes& duration);
    void assignVisit(visit::iVisit* visit);

    bool operator<(const TimeSlot& other) const;

  private:
    std::chrono::time_point<std::chrono::system_clock> time_point_;
    std::chrono::minutes duration_;
    visit::iVisit* visit_;
};

} // namespace calendar
