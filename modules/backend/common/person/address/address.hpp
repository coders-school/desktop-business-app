#pragma once

#include <string>

struct Address
{
    std::string city_;
    std::string country_;
    std::string province_;
    std::string street_;
    std::string zip_code_;

    Address(const std::string& city, const std::string& country, const std::string& province, const std::string& street, const std::string& zip_code)
        : city_{city}, country_{country}, province_{province}, street_{street}, zip_code_{zip_code}
    {
    }
};
