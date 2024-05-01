#pragma once
#include <chrono>
#include <vector>
#include "../doctor/doctor.hpp"
#include "../room/room.hpp"
#include "../visit/visit.hpp"

struct TimePoint{
    std::chrono::hh_mm_ss<std::chrono::seconds> start_;
    std::chrono::hh_mm_ss<std::chrono::seconds> end_;
};

class Connector{
    std::chrono::year_month_day ymd_;
    std::shared_ptr<Room> room_;
    std::shared_ptr<Doctor> doctor_;
    std::vector<std::pair<std::shared_ptr<Visit>, TimePoint>> time_table_;

public:
    Connector(const std::chrono::year_month_day& ymd, const std::shared_ptr<Room>& room, const std::shared_ptr<Doctor>& doctor);
    void addVisit(const std::shared_ptr<Visit>& visit,const TimePoint& tp);
};
