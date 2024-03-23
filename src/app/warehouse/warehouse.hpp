#pragma once
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

class Product;

class Warehouse
{
    bool is_valid_state;
    std::vector<std::shared_ptr<Product>> products_;

    bool validateAdd(const std::string &name) const;
    bool validateRemoval(const std::string &name) const;

  public:
    void increaseAmount(const std::string &name, const uint amount);
    void decreaseAmount(const std::string &name, const uint amount);
    void addProducts(const std::vector<std::shared_ptr<Product>> &products);
    void removeProducts(const std::vector<std::string> &products);
    std::shared_ptr<Product> getPtrToProduct(const std::string &name);
    std::vector<std::shared_ptr<Product>> &getExpiredProducts(); // TODO: write this function when type Date will be
                                                                 // created
    std::vector<std::shared_ptr<Product>> &getProducts();
};
