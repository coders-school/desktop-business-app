#pragma once

#include <fstream>
#include <iomanip>
#include <map>
#include <nlohmann/json.hpp>
#include <openssl/evp.h>
#include <sstream>
#include <string>

class Login
{
    std::string user_name_{};
    std::string password_hash_{};
    //  std::map<std::string, std::string> mapOfRandomQuestionsAndAnswers{}; To do map with questions to reset password
    std::string hashPassword(const std::string& password);

  public:
    explicit Login(const std::string& user_name, const std::string& password);
    bool isPasswordProper(const std::string& user_name, const std::string& password);
    std::string getPasswordHash() const;
    std::string getUserName() const;
};
