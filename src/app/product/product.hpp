#pragma once
#include <string>

class Product
{
  public:
    Product() = delete;
    Product(const std::string &name, double price, int amount);

    void increaseAmount(int amount);
    void decreaseAmount(int amount);
    std::string_view getName() const;

  private:
    std::string name_;
    double price_;
    int amount_;
};
