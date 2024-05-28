#pragma once

#include <string>

struct Name
{
    std::string first_name_;
    std::string second_name_;
    std::string last_name_;

    Name(const std::string& first_name, const std::string& second_name, const std::string& last_name)
        : first_name_{first_name}, second_name_{second_name}, last_name_{last_name}
    {
    }
};
