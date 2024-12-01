#pragma once

#include "visit/iVisit.hpp"
#include <chrono>

namespace calendar
{

class TimeSlot
{
  public:
    explicit TimeSlot(const std::chrono::time_point<std::chrono::system_clock>& time_point,
                      const std::chrono::minutes& duration, visit::iVisit* visit = nullptr);

    std::chrono::minutes getDuration() const;

    void changeDuration(const std::chrono::minutes& duration);
    void assignVisit(visit::iVisit* visit);
    visit::iVisit* getVisit() const;

    bool operator<(const TimeSlot& other) const;
    bool operator>(const TimeSlot& other) const;
    bool operator==(const TimeSlot& other) const;
    bool operator!=(const TimeSlot& other) const;

    /* In terms of comparing time_point and duration the following operators are
      not applicable as there is no use case for them.
      TimeSlots can be compared if they are equal in multiple WorkUnit objects to
      compare if there's a possibility to create another TimeSlot object.
      Timeslotc can be bigger or smaller than other TimeSlot object to check if
      timepoint of TimeSlot is not overlapping with another TimeSlot object.
    */
    bool operator<=(const TimeSlot& other) const = delete;
    bool operator>=(const TimeSlot& other) const = delete;

  private:
    std::chrono::time_point<std::chrono::system_clock> time_point_;
    std::chrono::minutes duration_;
    visit::iVisit* visit_;
};

} // namespace calendar
