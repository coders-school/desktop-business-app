#pragma once
#include <algorithm>
#include <string>
#include <vector>

class Product;

class Warehouse
{
  public:
    void increaseAmount(const std::string &name, const uint amount);
    void decreaseAmount(const std::string &name, const uint amount);
    void addProducts(const std::vector<Product> &products);
    bool validateAdd(const std::string &name);
    void removeProducts(const std::vector<Product> &products);
    bool validateRemoval(const std::string &name);
    std::vector<Product> getExpiredProducts();
    std::vector<Product> &getProducts();

  private:
    bool is_valid_state;
    std::vector<Product> products_;
};
