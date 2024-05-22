#pragma once
#include <string>

enum class Status
{
    Canceled,
    Relocated,
    Confirmed,
    Visited
};

std::string toString(Status status);