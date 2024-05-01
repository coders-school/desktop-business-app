#pragma once
#include "connector.hpp"
#include "../room/room.hpp"
#include <chrono>
#include <map>
#include <memory>
#include "../doctor/doctor.hpp"
#include <stdexcept>

class Calendar
{
    std::multimap<std::chrono::year_month_day, std::shared_ptr<Connector>> mapCalendar_;

public:
    static void createCalendar();
    std::shared_ptr<Connector> addConnector(std::chrono::year_month_day ymd, std::shared_ptr<Room>, std::shared_ptr<Doctor>);
};
