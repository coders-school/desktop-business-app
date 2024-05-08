#pragma once
#include "doctor.hpp"
#include "room.hpp"
#include "connector.hpp"
#include <chrono>
#include <map>
#include <memory>
#include <stdexcept>

class Calendar
{
    std::multimap<std::chrono::year_month_day, Connector> map_calendar_;

  public:
    static void createCalendar();
    void addConnector(const std::chrono::year_month_day& ymd, const std::shared_ptr<Room>& room,
                                            const std::shared_ptr<Doctor>& doctor);
};
