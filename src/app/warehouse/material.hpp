#pragma once
#include <cstdint>
#include <string>

enum class Material : std::uint8_t
{
    DentalCement = 0,
    Amalgam = 1,
    DentalComposite = 2,
    Size = 255
};

inline std::string convertMaterial(const Material &material)
{
    std::string material_str{};

    switch (material)
    {
    case Material::DentalCement:
        material_str = "Dental cement";
        break;

    case Material::Amalgam:
        material_str = "Amalgam";
        break;

    case Material::DentalComposite:
        material_str = "Dental composite";
        break;
    default:
        break;
    }

    return material_str;
}
