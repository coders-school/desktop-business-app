#pragma once

#include <iomanip>
#include <openssl/evp.h>
#include <sstream>
#include <string>

class Encrypt
{
  public:
    std::string hashSHA512(const std::string& string);
};
