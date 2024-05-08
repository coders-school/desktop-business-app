#include "doctor_test.hpp"

namespace
{

TEST_F(DoctorTestFixture, test)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    Doctor::createDoctor("Janusz", "Schmit", "80062378532", Gender::Male);
    Doctor::createDoctor("Gawel", "Pawel", "80062378532", Gender::Male);
    Doctor::createDoctor("Jan", "Poniatowski", "80062378532", Gender::Male);
    auto expected_doctor = Clinic::getDoctors().at(3);

    EXPECT_EQ(Doctor::getDoctor("Jan", "Poniatowski").front(), expected_doctor);
}

} // namespace
