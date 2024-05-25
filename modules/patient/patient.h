#pragma once

#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
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
    Gender gender_;

  public:
    Person(const Name& name, const Address& address, const Pesel& pesel, const PhoneNumber& phone_number)
        : name_{name}, address_{address}, pesel_{pesel}, phone_number_{phone_number}, gender_{Gender::Unknown}
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

enum class Treatment : std::uint8_t
{
};

enum class TreatmentState : std::uint8_t
{
    Planned = 0,
    Done = 1
};
/*
 *  represents the treatment that is planned for the patient or has been provided to the patient.
 */
class Treatments
{
    // map or different object containing treatment and date
    // and then kept in vector?
    std::unordered_map<Treatment, std::chrono::year_month_day> treatments_done_;
    std::unordered_map<Treatment, std::chrono::year_month_day> treatments_planned_;
    std::unordered_map<Treatment, std::chrono::year_month_day> treatments_declined_;
    // vector<treatment> done
    // vector<treatment> declined
    // vector<treatment> planned
  public:
    // Treatments should contain logic
    // planned -> set once visit is made
    // done -> set once visit state switches
    // Treatmends done in future should also collect date when
    // treatment was completed
    void UpdateTreatment(const TreatmentState treatment_state)
    {
        // move Treatment from planned to done
    }
};

/*
 * is a general interface to keep Patietns in collection, other objects shall
 * use interfaces with API corresponding to their responsibility.
 */
class iPatient
{
  public:
    virtual ~iPatient() = 0;
};

// find better name for the interface
class iVisitPatient : public virtual iPatient
{
    // this interface shall be used within Visit context
    // it should provide methods that will allow to:
    // 1. set planned treatment
    // 2. update the treatment state (planned -> done) once Visit is fulfiled
    // 3. other..
  public:
    virtual void UpdateTreatment(const TreatmentState, const std::vector<Treatment>&) {};
    virtual ~iVisitPatient(){};
};

// find better name for the interface
class iSerdePatient : public virtual iPatient
{
  public:
    virtual void SerializeData() = 0;
    virtual ~iSerdePatient() = 0;
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
    Patient()
        : person_{Person{Name{}, Address{}, Pesel{""}, PhoneNumber{}}}, payments_{Payments{}}, allergens_{Allergens{}},
          treatments_{Treatments{}}
    {
    }
    // date of treatment should be also added
    // what if planned treatment is done faster than expected?
    // find a way to handle such situation -> will it require using additional method?
    // try to do it without additional public method
    void UpdateTreatment(const TreatmentState treatment_state, const std::vector<Treatment>& visit_treatments) override
    {
        treatments_.UpdateTreatment(treatment_state);
    }

    void SerializeData() override
    {
    }
};

class PatientCollection
{
    std::vector<std::unique_ptr<iPatient>> patients_;

  public:
    PatientCollection(std::vector<std::unique_ptr<iPatient>> patients) : patients_{std::move(patients)}
    {
    }
    void AppendPatient(const iPatient& patient)
    {
        patients_.emplace_back(std::make_unique<iPatient>(patient));
    }
    // this method should be used within context of data visualization
    // data visualization class should format Patient data accordingly
    // to the context in which it will be used e.g. doctors view, receptionist view etc.
};

// visits in future might be separated by type (completed, planned, canceled)
// thus iterface could help manage different types of visits
class iVisit
{
  public:
    virtual ~iVisit() = 0;
};

class Visit
{
    iVisitPatient patient_;
    std::vector<Treatment> actual_treatment_;
    // on gui, doctor should select treatment/s for exact visit
  public:
    Visit(const Patient& patient) : patient_{patient}
    {
    }

    void FinishVisit()
    {
        const TreatmentState treatment_state = TreatmentState::Done;
        patient_.UpdateTreatment(treatment_state, actual_treatment_);
    }
};

class VisitCollection
{
    std::vector<iVisit> visits_;

  public:
    void AppendVisit(const iVisit& visit)
    {
        visits_.emplace_back(visit);
    }
    std::vector<iVisit> GetVisits()
    {
        return visits_;
    }
};

void showVisits(const std::vector<Visit>& visits)
{
    for (const auto& visit : visits)
    {
    }
}

class iDoctor
{
  public:
    virtual ~iDoctor() = 0;
};

class iVisitDoctor : public iDoctor
{
  public:
    virtual ~iVisitDoctor() = 0;
};

enum class Specialization : std::uint8_t
{
    Dentist = 0,
};

class Doctor : public iVisitDoctor
{
    Person person_;
    Specialization specialization_;

  public:
    Doctor(const Person& person, const Specialization specialization) : person_{person}, specialization_{specialization}
    {
    }
};

class iRoom
{
  public:
    virtual ~iRoom() = 0;
};

class Room : public iRoom
{
    std::uint8_t room_number_;

  public:
    Room(const std::uint8_t room_number) : room_number_{room_number}
    {
    }
};

class iStaff
{
  public:
    virtual ~iStaff() = 0;
};

class Staff : public iStaff
{
    std::vector<Doctor> doctors_;
    // std::vector<Receptionist> receptionists_;
  public:
};

class Clinic
{
    std::unique_ptr<iStaff> staff_;
    std::vector<std::unique_ptr<iRoom>> rooms_;

  public:
    Clinic(std::unique_ptr<iStaff> staff, std::vector<std::unique_ptr<iRoom>> rooms)
        : staff_{std::move(staff)}, rooms_{std::move(rooms)}
    {
    }
};

class Serializer // find better name
{
    std::vector<std::unique_ptr<iSerdePatient>> patients_;

  public:
    void SerializeData()
    {
    }
};

/*
 * initializes Patients from serialized data.
 * Shall be performed only once when application is started.
 */
std::vector<std::unique_ptr<iPatient>> InitializePatients(const Serializer& serializer)
{
    // this free functions should be in single file
    // and only be accessible within start of the program section.
    std::vector<std::unique_ptr<iPatient>> patients;
    // Expected that Patient data will be deserialized and 
    // emplaced in patient vector, something like following way:
    // for(const auto& patient : serializer.DeserializePatients())
    // {
    //     patients.emplace_back(std::make_unique<iPatient>(patient));
    // }
    // other deserialized objects should follow the same approach
    patients.emplace_back(std::make_unique<iPatient>());

    return patients;
}

// *** EXAMPLE USAGE ***
void someFunction()
{
    Serializer serializer;
    PatientCollection patient_collection{InitializePatients(serializer)};
    VisitCollection visit_collection;

    Patient patient;
    patient_collection.AppendPatient(patient);
}

// *** IDEAS COLLECTOR ***
// Rules:
// 1. Idea should have a name
// 2. Idea should have a short description
// 3. Idea should have a context in which it should be used
// 4. Idea should follow below format

/// IDEA NAME
/// Context - where it should be used (e.g. GUI, data visualization)
/// Description - short description of the idea

// In the GUI,
// When patient comes receptionist should look up for patient first
// if patient not found, then create patient.
// This implies that active window should have a search bar
// *decide which data should be used for search* (will be sufficient? name, pesel, phone number)
// and if patient is not found, then create patient window should be opened.
// This window should contain all necessary fields to create patient, but it should follow:
// Lazy creation via temporary object
// "TempPatient" should be initialized and then all necessary fields
// should be filled. Once all fields are filled, then Patient
// object should be created and added to the Patient collection.
// This way, we can avoid creating Patient object with missing data.
// After system break down, TempPatient objects should be
// visible in additional field on the window which allows searching.
// Such filed should be accessible and creation can be resumed.