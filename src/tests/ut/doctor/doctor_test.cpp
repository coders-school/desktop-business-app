#include "doctor_test.hpp"

namespace
{

TEST_F(DoctorTestFixture, test)
{
    Doctor::createDoctor("Jan", "Kowalski", "00000000000");
    Doctor::createDoctor("Janusz", "Schmit", "00000000001");
    Doctor::createDoctor("Gawel", "Pawel", "00000000002");
    Doctor::createDoctor("Jan", "Poniatowski", "00000000003");
    auto expected_doctor = Clinic::getDoctors().at(3);

    EXPECT_EQ(Doctor::getDoctor("Jan", "Poniatowski"), expected_doctor);
}

} // namespace