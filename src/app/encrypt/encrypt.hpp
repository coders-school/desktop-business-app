#pragma once

#include <string>

class Encrypt
{
  public:
    std::string hashSHA512(const std::string& string);
};
