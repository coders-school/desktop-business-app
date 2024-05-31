#pragma once

#include "modules/backend/common/personal_data/PersonalData.hpp"
#include "modules/backend/patients/patient/allergens/Allergens.hpp"
#include "modules/backend/patients/patient/iPatient.hpp"
#include "modules/backend/patients/patient/payments/Payments.hpp"
#include "modules/backend/patients/patient/treatments/Treatments.hpp"

namespace patient
{

class Patient : public iPatient
{
    PersonalData personal_data_;
    Payments payments_;
    Allergens allergens_;
    Treatments treatments_;

  public:
    Patient()
        : personal_data_{PersonalData{Name{}, Address{}, Pesel{""}, PhoneNumber{}}}, payments_{Payments{}},
          allergens_{Allergens{}}, treatments_{Treatments{}}
    {
    }
    // date of treatment should be also added
    // what if planned treatment is done faster than expected?
    // find a way to handle such situation -> will it require using additional method?
    // try to do it without additional public method
};

// *** EXAMPLE USAGE ***
// void someFunction()
// {
//     Serializer serializer;
//     PatientCollection patient_collection{InitializePatients(serializer)};
//     VisitCollection visit_collection;

//     Patient patient;
//     patient_collection.AppendPatient(patient);
// }

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

} // namespace patient
