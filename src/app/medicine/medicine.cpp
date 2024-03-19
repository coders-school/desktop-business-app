#include "medicine.hpp"

Medicine::Medicine(const std::string &name, double price, int amount, int expiration_date,
                   std::pair<double, double> storage_temperature, std::vector<std::string> composition)
    : Product(name, price, amount), expiration_date_(expiration_date), storage_temperature_(storage_temperature),
      composition_(composition)
{
}
