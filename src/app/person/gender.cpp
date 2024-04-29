#include "gender.hpp"

std::string toString(const Gender gender)
{
    switch (gender)
    {
    case Gender::Male:
        return "male";

    case Gender::Female:
        return "female";
    }
}
