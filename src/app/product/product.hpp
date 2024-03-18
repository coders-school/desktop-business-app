#pragma once
#include <string>

class Product
{
  public:
    void increaseAmount(int amount);
    void decreaseAmount(int amount);
    std::string_view getName() const;

  private:
    std::string name_;
    double price_;
    int amount_;
};
