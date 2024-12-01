#pragma once

#include "User.hpp"
#include <cstdint>
#include <memory>

namespace login
{

enum class AccountType : uint8_t
{
    Administrator = 0U,
    Doctor = 1U,
    Receptionist = 2U,
};

class UserStrategy
{
    UserStrategy() = default;

  public:
    static std::unique_ptr<User> createUser(AccountType strategy)
    {
        switch (strategy)
        {
        case AccountType::Administrator:
            return std::make_unique<User>();
        default:
            throw std::runtime_error("Invalid user strategy");
        }
    }
};

} // namespace login
