#include "connector.hpp"

Connector::Connector(const std::chrono::year_month_day& ymd, const std::shared_ptr<Room>& room, const std::shared_ptr<Doctor>& doctor)
: ymd_{ymd}, room_{room}, doctor_{doctor} {};

void Connector::addVisit(const std::shared_ptr<Visit>& visit, const TimePoint& tp){
    time_table_.push_back(std::make_pair(visit, tp));
}
