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
    void addProducts(const std::vector<std::shared_ptr<Product>> products);
    bool validateAdd(const std::string &name);
    void removeProducts(const std::vector<std::shared_ptr<Product>> &products);
    bool validateRemoval(const std::string &name);
    std::shared_ptr<Product> getPtrToProduct(std::string name);
    std::vector<std::shared_ptr<Product>> getExpiredProducts();
    std::vector<std::shared_ptr<Product>> &getProducts();

  private:
    bool is_valid_state;
    std::vector<std::shared_ptr<Product>> products_;
};
