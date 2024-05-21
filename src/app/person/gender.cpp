#include "gender.hpp"

std::string toString(const Gender gender)
{
    std::string gender_text{};
    switch (gender)
    {
    case Gender::Male:
        gender_text = "male";
        break;

    case Gender::Female:
        gender_text = "female";
        break;
    default:
        gender_text = "unknown";
        break;
    }
    return gender_text;
}

Gender toEnum(const std::string& gender)
{
    if (gender == "male")
    {
        return Gender::Male;
    }
    else if (gender == "female")
    {
        return Gender::Female;
    }
    else
        return Gender::Unknown;
}
