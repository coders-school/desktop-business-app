#pragma once

#include <memory>
#include <vector>

class iProduct
{
  public:
    virtual ~iProduct() = default;
};

class iEquipment : virtual public iProduct
{
  public:
    virtual ~iEquipment() = default;
};

class iMedicine : virtual public iProduct
{
  public:
    virtual ~iMedicine() = default;
};

class Product : public iMedicine, public iEquipment
{
  public:
  // Could be a single class product defined 
  // which will cover all types of products?
  // depending on what kind of product you 
  // might want to create, needed methods to 
  // create it will be called
};

class Warehouse
{
    std::vector<std::unique_ptr<iProduct>> products_;

  public:
    void AppendProduct(std::unique_ptr<iProduct> product)
    {
        products_.emplace_back(std::move(product));
    }

    // expectation from Room object is to receive
    // all the object in categories 
    // define a middleman class to handle separation, 
    // searching through categorized objects, etc. 
    // Middleman class will be a API to interact Room
    // object with Warehouse object
    // Once it's defined, Warehouse could become 
    // a separated module. But in fact, it's behavior
    // needs to satisfy defined API. 
};
