#include "account.hpp"

Account::Account(const std::string& user_name, const std::string& password)
    : user_name_(user_name), password_hash_(hashSHA512(password)), map_of_random_questions_and_answers_{}
{
}

bool Account::isPasswordProper(const std::string& login, const std::string& password)
{
    std::ifstream file("users/users.json");
    nlohmann::json json_file;
    file >> json_file;

    std::string hashedPassword = hashSHA512(password);

    for (const auto& element : json_file)
    {
        if (element[login] == login && element[password] == hashedPassword)
        {
            return true;
        }
    }

    return false;
}

bool Account::isAnswerCorrect(const std::string& answer, const int& id)
{
    std::ifstream file("users/users.json");
    nlohmann::json json_file;
    file >> json_file;

    for (const auto& user : json_file)
    {
        for (const auto& question : user["security_questions"])
        {
            if (question["id"] == id && question["answer"] == answer)
            {
                return true;
            }
        }
    }
    return false;
}

std::string Account::getPasswordHash() const
{
    return password_hash_;
}

std::string Account::getUserName() const
{
    return user_name_;
}
