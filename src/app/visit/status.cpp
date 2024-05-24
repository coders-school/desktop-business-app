#include "status.hpp"

std::string toString(Status status)
{
    switch (status)
    {
    case Status::Canceled:
        return "Canceled";

    case Status::Confirmed:
        return "Confirmed";

    case Status::Relocated:
        return "Relocated";

    case Status::Visited:
        return "Visited";
    }
    return "Other";
}
