#include "medicine.hpp"

Medicine::Medicine(const std::string& name, const double price, const int amount,
                   const std::chrono::year_month_day expiration_date,
                   const std::pair<double, double>& storage_temperature, const std::vector<std::string>& composition)
    : Product(name, price, amount), expiration_date_{expiration_date}, storage_temperature_{storage_temperature},
      composition_{composition}
{
}
bool Medicine::isExpired() const
{
    const auto expDate = std::chrono::sys_days{expiration_date_};
    const auto currentDate = std::chrono::system_clock::now();
    return expDate < currentDate;
}

std::map<std::string, std::string> Medicine::getInfo() const
{
    std::string comp{};
    for (const auto& el : composition_)
    {
        comp += el + ", ";
    }
    const auto expDateDay = std::to_string(static_cast<unsigned>(expiration_date_.day()));
    const auto expDateMonth = std::to_string(static_cast<unsigned>(expiration_date_.month()));
    const auto expDateYear = std::to_string(static_cast<int>(expiration_date_.year()));
    const auto expDate = expDateDay + "." + expDateMonth + "." + expDateYear;
    return {{{"expiration date"}, {expDate}},
            {{"storage temperature"},
             {std::to_string(storage_temperature_.first) + " / " + std::to_string(storage_temperature_.second)}},
            {{"composition"}, {comp}}};
}
