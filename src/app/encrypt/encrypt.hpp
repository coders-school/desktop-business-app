#pragma once

#include <iomanip>
#include <string>
#include <sstream>
#include <openssl/evp.h>

class Encrypt
{
public:
    std::string hashSHA512(const std::string& string);
};
