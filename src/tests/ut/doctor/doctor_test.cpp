#include "doctor_test.hpp"
#include "gender.hpp"
namespace
{

class DoctorAppendVisitFunction : public DoctorTestFixture
{
};

class DoctorRemoveVisitFunction : public DoctorTestFixture
{
};

TEST_F(DoctorTestFixture, CreatingDoctorViaCreateShouldAppendDoctorsToClinic)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    Doctor::createDoctor("Janusz", "Schmit", "70080149412", Gender::Male);
    Doctor::createDoctor("Gawel", "Pawel", "49042481257", Gender::Male);
    Doctor::createDoctor("Jan", "Poniatowski", "95071719638", Gender::Male);

    auto first_expected_doctor = Clinic::getDoctors().at(0);
    auto second_expected_doctor = Clinic::getDoctors().at(1);
    auto third_expected_doctor = Clinic::getDoctors().at(2);
    auto fourth_expected_doctor = Clinic::getDoctors().at(3);

    EXPECT_EQ(Doctor::getDoctor("Jan", "Kowalski").front(), first_expected_doctor);
    EXPECT_EQ(Doctor::getDoctor("Janusz", "Schmit").front(), second_expected_doctor);
    EXPECT_EQ(Doctor::getDoctor("Gawel", "Pawel").front(), third_expected_doctor);
    EXPECT_EQ(Doctor::getDoctor("Jan", "Poniatowski").front(), fourth_expected_doctor);
}

TEST_F(DoctorAppendVisitFunction, ShouldAppendGivenVisitToSpecifiedDoctor)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    Doctor::createDoctor("Jan", "Poniatowski", "70080149412", Gender::Male);

    auto doctor_tested = Clinic::getDoctors().at(0);
    auto irrelevant_doctor = Clinic::getDoctors().at(1);
    createThreeSimpleVisits(irrelevant_doctor);
    ASSERT_TRUE(doctor_tested->getVisits().empty());

    const auto visit_to_append = irrelevant_doctor->getVisits().at(1);
    doctor_tested->appendVisit(visit_to_append);
    checkIfDoctorHasVisits(doctor_tested, {"second visit"});
}

TEST_F(DoctorRemoveVisitFunction, ShouldRemoveFirstVisitFromDoctorsVisitContainer)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    auto doctor_tested = Clinic::getDoctors().at(0);
    createThreeSimpleVisits(doctor_tested);
    checkIfDoctorHasVisits(doctor_tested, {"first visit", "second visit", "third visit"});

    const auto visit_to_remove_ptr = doctor_tested->getVisits().at(0);
    doctor_tested->removeVisit(visit_to_remove_ptr);

    checkIfDoctorHasVisits(doctor_tested, {"second visit", "third visit"});
}

TEST_F(DoctorRemoveVisitFunction, ShouldRemoveMiddleVisitFromDoctorsVisitContainer)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    auto doctor_tested = Clinic::getDoctors().at(0);
    createThreeSimpleVisits(doctor_tested);
    checkIfDoctorHasVisits(doctor_tested, {"first visit", "second visit", "third visit"});

    const auto visit_to_remove_ptr = doctor_tested->getVisits().at(1);
    doctor_tested->removeVisit(visit_to_remove_ptr);

    checkIfDoctorHasVisits(doctor_tested, {"first visit", "third visit"});
}

TEST_F(DoctorRemoveVisitFunction, ShouldRemoveLastVisitFromDoctorsVisitContainer)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    auto doctor_tested = Clinic::getDoctors().at(0);
    createThreeSimpleVisits(doctor_tested);
    checkIfDoctorHasVisits(doctor_tested, {"first visit", "second visit", "third visit"});

    const auto visit_to_remove_ptr = doctor_tested->getVisits().at(2);
    doctor_tested->removeVisit(visit_to_remove_ptr);

    checkIfDoctorHasVisits(doctor_tested, {"first visit", "second visit"});
}

TEST_F(DoctorRemoveVisitFunction, ShouldNotRemoveVisitNotBelongingToSpecificDoctor)
{
    Doctor::createDoctor("Jan", "Kowalski", "80062378532", Gender::Male);
    Doctor::createDoctor("Jan", "Poniatowski", "70080149412", Gender::Male);

    auto doctor_tested = Clinic::getDoctors().at(0);
    auto irrelevant_doctor = Clinic::getDoctors().at(1);
    createThreeSimpleVisits(doctor_tested);
    createVisitWithInformation(irrelevant_doctor, "irrelevant visit");
    checkIfDoctorHasVisits(doctor_tested, {"first visit", "second visit", "third visit"});
    checkIfDoctorHasVisits(irrelevant_doctor, {"irrelevant visit"});

    const auto irrelevant_visit_to_remove_ptr = irrelevant_doctor->getVisits().at(0);
    doctor_tested->removeVisit(irrelevant_visit_to_remove_ptr);

    checkIfDoctorHasVisits(doctor_tested, {"first visit", "second visit", "third visit"});
    checkIfDoctorHasVisits(irrelevant_doctor, {"irrelevant visit"});
}

} // namespace
