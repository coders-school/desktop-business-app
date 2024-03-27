#include "medicine.hpp"

Medicine::Medicine(const std::string& name, const double price, const int amount, const int expirationDate,
                   const std::pair<double, double>& storageTemperature, const std::vector<std::string>& composition)
    : Product(name, price, amount), expirationDate_{expirationDate}, storageTemperature_{storageTemperature},
      composition_{composition}
{
}
bool Medicine::checkIfExpired()
{
    // TODO: Write this function when Date will be ready
    return false;
}

std::map<std::string, std::string> Medicine::getInfo() const
{
    std::string comp{};
    for (const auto& el : composition_)
    {
        comp += el + ", ";
    }
    return {{{"expiration date"}, {std::to_string(expirationDate_)}},
            {{"storage temperature"},
             {std::to_string(storageTemperature_.first) + " / " + std::to_string(storageTemperature_.second)}},
            {{"composition"}, {comp}}};
}
