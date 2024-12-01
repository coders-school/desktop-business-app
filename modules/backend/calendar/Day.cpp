#include "Day.hpp"

namespace calendar
{
Day::Day(const std::chrono::year_month_day date) : date_(date)
{
}

calendar::WorkUnit* Day::createWorkUnit(clinic::staff::doctor::iDoctor* doc, clinic::room::iRoom* room)
{
    unit_collection_.push_back(std::make_unique<WorkUnit>(doc, room));
    return unit_collection_.back().get();
}

std::chrono::year_month_day Day::getDate() const
{
    return date_;
}
} // namespace calendar