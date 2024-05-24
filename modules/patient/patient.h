#pragma once

#include <cstdint>
#include <string>
#include <vector>
// all enum types should have following functions
// getX returning std::string

// methods in a class should follow the following convention
// GetData, CreateSometing, FindSomething

// free functions should follow the following convention
// getData, createSomething, findSomething

// enum class have to have assigned values and inherit
// types like std::uin8_t
// Male = 0, Female = 1..

// class, enum class, struct should follow the following naming conveniton
// class Name, struct Name, enum class Name

// interfaces naming should follow the following convention
// class iName, struct iName

// interfaces need a short description about the
// context in which shall be used 

// each interface -> class?? should have, if possible, a mock class
// example will be shown 

// data should be separated by context 
// if there's general class, it should have it's own directory
// example:
// class Patient and Person are introduced in single file
// class Doctor has been created and it will contain some
// of the data that Patient has (Person)
// Person shall be moved to separated file and directory
// all objects that are part of the Person will be moved
// to the person directory and will own files
// Person has gender, then person.h and gender.h 


enum class Gender : std::uint8_t
{
    Male = 0,
    Female = 1,
    Unknown = 255
};

struct Name
{
    std::string first_name_;
    std::string second_name_;
    std::string last_name_;
};

struct Address
{
    std::string city_;
    std::string country_;
    std::string province_;
    std::string street_;
    std::string zip_code_;
};

class Pesel
{
    std::string pesel_;
    std::string ValidatePesel(const std::string& pesel)
    {
        // move validation
        return pesel;
    }

  public:
    Pesel(const std::string& pesel) : pesel_{ValidatePesel(pesel)}
    {
    }

    std::string GetPesel()
    {
        return pesel_;
    }
};

struct PhoneNumber
{
    std::string phone_code_; // +1, +48 (+ == 00)
    std::string cellphone_number_;
    std::string home_number;
};

class Person
{
    Name name_;
    Address address_;
    Pesel pesel_;
    PhoneNumber phone_number_;

  public:
    Person(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number)
        : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}
    {
    }
};

struct Payments
{
    std::uint8_t paid_;
    std::uint8_t planned_;
    std::uint8_t overdue_;
    // paid -> total received from patient
    // planned -> informative value for planned treatment
    // overdue -> if patient did not have enough money,
    // patient may pay in installments
};

enum class Allergen : std::uint8_t // to be updated
{
    Al = 0
};

class Allergens
{
    // this class should contain allergens container
    // allow to add and remove allergen/s
    // return list of allergens
    // inform (true/false) if queried allergen is present
    std::vector<Allergen> allergens_;

  public:
    // expected methods
    // addAllergen(singular -> Allergen)
    // addAllergen(plural -> set, vector?<Allergen>)
    // checkAllergen(Allergen)
};

class Treatments
{
    // vector<treatment> done
    // vector<treatment> planned
  public:
    // Treatments should contain logic
    // planned -> set once visit is made
    // done -> set once visit state switches
};

// find better name for the interface
class iVisitPatient
{
    // this interface shall be used within Visit context
    // it should provide methods that will allow to:
    // 1. set planned treatment
    // 2. update the treatment state (planned -> done) once Visit is fulfiled
    // 3. other.. 
  public:
    virtual void SetTreatment() = 0;
};

// find better name for the interface
class iSerdePatient
{
    public:
    virtual void SerializeData() = 0;

};

/**
 * represents both personal and medical data of patient.
 * It includes personal information such as the patients' name, address
 * identification number and contact details. It manages financial
 * data connected to particular patient. It contains finished
 * and planned treatment informations.
 */
class Patient : public iVisitPatient, public iSerdePatient
{
    Person person_;
    Payments payments_;
    Allergens allergens_;
    Treatments treatments_;

  public:
    void SetTreatment() override
    {
    }

    void SerializeData() override
    {
    }
};
