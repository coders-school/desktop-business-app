#pragma once

#include <memory>
#include <string>

class Person{
    private:
        std::string name_;
        std::string pesel_;
    public:
        virtual ~Person(){};
        void setName(std::string name){};
        std::string getName(){};
        void setPesel(std::string pesel){};
};