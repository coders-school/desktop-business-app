#include "visitStatus.hpp"

std::string toString(VisitStatus status)
{
    switch (status)
    {
    case VisitStatus::Canceled:
        return "Canceled";

    case VisitStatus::Confirmed:
        return "Confirmed";

    case VisitStatus::Relocated:
        return "Relocated";

    case VisitStatus::Visited:
        return "Visited";
    }
    return "Unassigned";
}
