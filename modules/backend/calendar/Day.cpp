#include "Day.hpp"

namespace calendar
{
Day::Day(const std::chrono::year_month_day date) : date_(date)
{
}

calendar::WorkUnit* Day::createWorkUnit(clinic::staff::doctor::iDoctor* doc, clinic::room::iRoom* room)
{
    work_units_.push_back(std::make_unique<WorkUnit>(doc, room));
    return work_units_.back().get();
}

std::chrono::year_month_day Day::getDate() const
{
    return date_;
}
} // namespace calendar