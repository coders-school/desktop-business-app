#pragma once

#include <fstream>
#include <map>
#include <nlohmann/json.hpp>
#include <string>

#include "encrypt.hpp"

class Account : public Encrypt
{
    std::string user_name_;
    std::string password_hash_;
    std::unordered_map<std::string, std::string> map_of_random_questions_and_answers_;

  public:
    explicit Account(const std::string& user_name, const std::string& password);
    bool isPasswordProper(const std::string& user_name, const std::string& password);
    bool areAnswersCorrect(const std::string& answer1, const std::string& answer2, const std::string& answer3);
    std::string getPasswordHash() const;
    std::string getUserName() const;
};
