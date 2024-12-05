#include "PhoneCode.hpp"

#include <algorithm>
#include <map>
#include <string>

namespace common
{

namespace phone_code
{

const std::map<PhoneCode, std::string> countriesPhoneCode{
    {PhoneCode::Greece, "Greece"},         {PhoneCode::Netherlands, "Netherlands"},
    {PhoneCode::Belgium, "Belgium"},       {PhoneCode::France, "France"},
    {PhoneCode::Spain, "Spain"},           {PhoneCode::Hungary, "Hungary"},
    {PhoneCode::Italy, "Italy"},           {PhoneCode::Romania, "Romania"},
    {PhoneCode::Austria, "Austria"},       {PhoneCode::Denmark, "Denmark"},
    {PhoneCode::Sweden, "Sweden"},         {PhoneCode::Norway, "Norway"},
    {PhoneCode::Poland, "Poland"},         {PhoneCode::Germany, "Germany"},
    {PhoneCode::Portugal, "Portugal"},     {PhoneCode::Ireland, "Ireland"},
    {PhoneCode::Luxembourg, "Luxembourg"}, {PhoneCode::Iceland, "Iceland"},
    {PhoneCode::Malta, "Malta"},           {PhoneCode::Cyprus, "Cyprus"},
    {PhoneCode::Finland, "Finland"},       {PhoneCode::Bulgaria, "Bulgaria"},
    {PhoneCode::Lithuania, "Lithuania"},   {PhoneCode::Latvia, "Latvia"},
    {PhoneCode::Estonia, "Estonia"},       {PhoneCode::Croatia, "Croatia"},
    {PhoneCode::Slovenia, "Slovenia"},     {PhoneCode::CzechRepublic, "CzechRepublic"},
    {PhoneCode::Slovakia, "Slovakia"},     {PhoneCode::Lichtenstein, "Lichtenstein"},
    {PhoneCode::Unkown, "Unkown"}};

std::string toString(const PhoneCode& phone_code)
{
    auto searchingElement = countriesPhoneCode.find(phone_code);
    return searchingElement != countriesPhoneCode.end() ? searchingElement->second : "Unknow";
}

PhoneCode toEnum(const std::string& phone_code)
{
    auto searchingElement =
        std::ranges::find_if(countriesPhoneCode, [&phone_code](const auto& pair) { return pair.second == phone_code; });
    return searchingElement != countriesPhoneCode.end() ? searchingElement->first : PhoneCode::Unkown;
}

std::string getPhoneCodeIndex(const PhoneCode& phone_code)
{
    return "+" + toString(phone_code);
}

} // namespace phone_code
} // namespace common