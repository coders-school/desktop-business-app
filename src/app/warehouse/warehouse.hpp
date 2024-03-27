#pragma once
#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <vector>

class Product;

class Warehouse
{
    bool is_valid_state;
    std::set<std::shared_ptr<Product>> products_;

  public:
    void increaseAmount(const std::shared_ptr<Product>& ptrToProduct, const uint amount);
    void decreaseAmount(const std::shared_ptr<Product>& ptrToProduct, const uint amount);
    void addProducts(const std::vector<std::shared_ptr<Product>>& products);
    void removeProducts(const std::vector<std::shared_ptr<Product>>& products);
    std::vector<std::shared_ptr<Product>> getPtrsToProducts(const std::string& name);
    std::vector<std::shared_ptr<Product>>& getExpiredProducts(); // TODO: write this function when type Date will be
                                                                 // created
    std::set<std::shared_ptr<Product>>& getProducts();
};
