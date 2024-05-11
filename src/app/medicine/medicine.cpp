#include "medicine.hpp"
#include <ctime>
#include <iostream>

Medicine::Medicine(const std::string& name, const double price, const int amount,
                   const std::chrono::year_month_day expiration_date,
                   const std::pair<double, double>& storage_temperature, const std::vector<std::string>& composition)
    : Product(name, price, amount), expiration_date_{expiration_date}, storage_temperature_{storage_temperature},
      composition_{composition}
{
}
bool Medicine::isExpired() const
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    if (static_cast<int>(expiration_date_.year()) < currentYear)
    {
        return true;
    }
    else if (static_cast<int>(expiration_date_.year()) >= currentYear and
             static_cast<unsigned>(expiration_date_.month()) < static_cast<unsigned>(currentMonth))
    {
        return true;
    }
    else if (static_cast<int>(expiration_date_.year()) >= currentYear and
             static_cast<unsigned>(expiration_date_.month()) >= static_cast<unsigned>(currentMonth) and
             static_cast<unsigned>(expiration_date_.day()) < static_cast<unsigned>(currentDay))
    {
        return true;
    }
    else
        return false;
}

std::map<std::string, std::string> Medicine::getInfo() const
{
    std::string comp{};
    for (const auto& el : composition_)
    {
        comp += el + ", ";
    }
    auto expDateDay = std::to_string(static_cast<unsigned>(expiration_date_.day()));
    auto expDateMonth = std::to_string(static_cast<unsigned>(expiration_date_.month()));
    auto expDateYear = std::to_string(static_cast<int>(expiration_date_.year()));
    auto expDate = expDateDay + "." + expDateMonth + "." + expDateYear;
    return {{{"expiration date"}, {expDate}},
            {{"storage temperature"},
             {std::to_string(storage_temperature_.first) + " / " + std::to_string(storage_temperature_.second)}},
            {{"composition"}, {comp}}};
}
