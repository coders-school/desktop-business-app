#pragma once
#include <string>
#include <utility>
#include <vector>

class Product
{
    std::string name_;
    double price_;
    uint amount_;

  public:
    Product() = delete;
    Product(const std::string &name, const double price, const uint amount);
    virtual ~Product() = default;

    void increaseAmount(uint amount);
    void decreaseAmount(uint amount);

    std::string_view getName() const;
    double getPrice() const;
    uint getAmount() const;

    void setName(const std::string &name);
    void setPrice(const double price);
    void setAmount(const uint amount);

    virtual std::vector<std::pair<std::string, std::string>> getInfo() const = 0;
};
