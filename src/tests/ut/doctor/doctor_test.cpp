#include "doctor_test.hpp"

namespace
{

TEST_F(DoctorTestFixture, test)
{
    Doctor::createDoctor("Jan", "Kowalski", "00000000000", Gender::Male);
    Doctor::createDoctor("Janusz", "Schmit", "00000000001", Gender::Male);
    Doctor::createDoctor("Gawel", "Pawel", "00000000002", Gender::Male);
    Doctor::createDoctor("Jan", "Poniatowski", "00000000003", Gender::Male);
    auto expected_doctor = Clinic::getDoctors().at(3);

    EXPECT_EQ(Doctor::getDoctor("Jan", "Poniatowski").front(), expected_doctor);
}

} // namespace
