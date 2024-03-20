#pragma once
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

class Product;

class Warehouse
{
  public:
    void increaseAmount(const std::string &name, const uint amount);
    void decreaseAmount(const std::string &name, const uint amount);
    void addProducts(const std::vector<std::shared_ptr<Product>> &products);
    bool validateAdd(const std::string &name) const;
    void removeProducts(const std::vector<std::string> &products);
    bool validateRemoval(const std::string &name) const;
    std::shared_ptr<Product> getPtrToProduct(const std::string &name);
    std::vector<std::shared_ptr<Product>> &getExpiredProducts(); // TODO: write this function when type Date will be
                                                                 // created
    std::vector<std::shared_ptr<Product>> &getProducts();

  private:
    bool is_valid_state;
    std::vector<std::shared_ptr<Product>> products_;
};
