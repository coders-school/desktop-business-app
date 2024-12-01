#pragma once

#include <chrono>

#include "WorkUnit.hpp"

namespace calendar
{

class Day
{
  public:
    explicit Day(const std::chrono::year_month_day date);
    calendar::WorkUnit* createWorkUnit(clinic::staff::doctor::iDoctor* doc, clinic::room::iRoom* room);
    std::chrono::year_month_day getDate() const;

  private:
    std::vector<std::unique_ptr<calendar::WorkUnit>> unit_collection_;
    std::chrono::year_month_day date_;
};

} // namespace calendar
