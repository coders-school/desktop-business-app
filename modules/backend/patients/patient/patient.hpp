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

// namespaces should be up to 3 levels deep
// example:
// backend::patient
// clinic::staff::doctor

/**
 * represents both personal and medical data of patient.
 * It includes personal information such as the patients' name, address
 * identification number and contact details. It manages financial
 * data connected to particular patient. It contains finished
 * and planned treatment informations.
 */
class Patient : public iPatient
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
};

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