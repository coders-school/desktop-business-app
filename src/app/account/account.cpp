#include "account.hpp"

Account::Account(const std::string& user_name, const std::string& password)
    : user_name_(user_name), password_hash_(hashSHA512(password)), map_of_random_questions_and_answers_{}
{
}

bool Account::isPasswordProper(const std::string& login, const std::string& password)
{
    std::ifstream file("users/users.json");
    nlohmann::json jsonFile;
    file >> jsonFile;

    std::string hashedPassword = hashSHA512(password);

    for (auto& element : jsonFile)
    {
        if (element[login] == login && element[password] == hashedPassword)
        {
            return true;
        }
    }

    return false;
}

bool Account::areAnswersCorrect(const std::string& answer1, const std::string& answer2, const std::string& answer3)
{
    size_t judge{};
    std::ifstream file("users/users.json");
    nlohmann::json jsonFile;
    file >> jsonFile;

    for (const auto& user : jsonFile) 
    {
        for(const auto& answer : user["security_questions"])
        {
            if (answer == answer1)
            {
                judge++;
            } 
            if(answer == answer2)
            {
                judge++;
            }
            if(answer == answer3) 
            {
                judge++;
            }
        }
    }
    return judge >= 2;
}

std::string Account::getPasswordHash() const
{
    return password_hash_;
}

std::string Account::getUserName() const
{
    return user_name_;
}
