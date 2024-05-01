#pragma once
#include "../doctor/doctor.hpp"
#include "../room/room.hpp"
#include "connector.hpp"
#include <chrono>
#include <map>
#include <memory>
#include <stdexcept>

class Calendar
{
    std::multimap<std::chrono::year_month_day, std::shared_ptr<Connector>> map_calendar_;

  public:
    static void createCalendar();
    std::shared_ptr<Connector> addConnector(const std::chrono::year_month_day& ymd, const std::shared_ptr<Room>& room,
                                            const std::shared_ptr<Doctor>& doctor);
};
