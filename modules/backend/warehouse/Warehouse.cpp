#include "Warehouse.hpp"

namespace warehouse
{
void Warehouse::AppendProduct(std::unique_ptr<iProduct> product)
{
    products_.emplace_back(std::move(product));
}

} // namespace warehouse