#include "login.hpp"

Login::Login(const std::string& user_name, const std::string& password)
    : user_name_(user_name), password_hash_(hashPassword(password))
{
}

std::string Login::hashPassword(const std::string& password)
{
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len{};
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha512(), NULL);
    EVP_DigestUpdate(ctx, password.c_str(), password.size());
    EVP_DigestFinal_ex(ctx, hash, &hash_len);
    EVP_MD_CTX_free(ctx);

    std::stringstream ss;

    for (unsigned int i = 0; i < hash_len; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

bool Login::isPasswordProper(const std::string& login, const std::string& password)
{
    std::ifstream file("verySecretPasswords/users.json");
    nlohmann::json jsonFile;
    file >> jsonFile;

    std::string hashedPassword = hashPassword(password);

    for (auto& element : jsonFile)
    {
        if (element[login] == login && element[password] == hashedPassword)
        {
            return true;
        }
    }

    return false;
}

std::string Login::getPasswordHash() const
{
    return password_hash_;
}

std::string Login::getUserName() const
{
    return user_name_;
}
