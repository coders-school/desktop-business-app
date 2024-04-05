#include "encrypt.hpp"

std::string Encrypt::hashSHA512(const std::string& string)
{
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len{};
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha512(), NULL);
    EVP_DigestUpdate(ctx, string.c_str(), string.size());
    EVP_DigestFinal_ex(ctx, hash, &hash_len);
    EVP_MD_CTX_free(ctx);

    std::stringstream ss;

    for (unsigned int i = 0; i < hash_len; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}
