#include "test_utils.hpp"
#include "clinic_facade.hpp"

void cleanupClinic()
{
    for (const auto& visit : Clinic::getVisits())
    {
        Clinic::removeVisit(visit);
    }

    for (const auto& doctor : Clinic::getDoctors())
    {
        Clinic::removeDoctor(doctor);
    }

    for (const auto& receptionist : Clinic::getReceptionists())
    {
        Clinic::removeReceptionist(receptionist);
    }

    for (const auto& patient : Clinic::getPatients())
    {
        Clinic::removePatient(patient);
    }

    for (const auto& room : Clinic::getRooms())
    {
        Clinic::removeRoom(room);
    }

    Clinic::removeCalendar();
    Clinic::removeWarehouse();
}
