#include "medicine.hpp"

Medicine::Medicine(const std::string &name, const double price, const int amount, const int expirationDate,
                   const std::pair<double, double> &storageTemperature, const std::vector<std::string> &composition)
    : Product(name, price, amount), expirationDate_(expirationDate), storageTemperature_(storageTemperature),
      composition_(composition)
{
}
bool Medicine::checkIfExpired()
{
    // TODO: Write this function when Date will be ready
    return false;
}

int Medicine::getExpirationDate() const
{
    return expirationDate_;
}

std::pair<double, double> Medicine::getStorageTemperature() const
{
    return storageTemperature_;
}

std::vector<std::string> Medicine::getComposition() const
{
    return composition_;
}

void Medicine::setExpirationDate(const int expirationDate)
{
    expirationDate_ = expirationDate;
}

void Medicine::setStorageTemperature(const std::pair<double, double> &storageTemperature)
{
    storageTemperature_ = storageTemperature;
}

void Medicine::setComposition(const std::vector<std::string> &composition)
{
    composition_ = composition;
}
