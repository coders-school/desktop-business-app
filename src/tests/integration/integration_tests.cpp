#include "integration_tests.hpp"

TEST_F(IntegratonFixture, IntegrationTest)
{
    prepareClinic();
    expectClinicWellPrepared();
    // new patient
    // check if patient has been created as expected
    // new visit for patient
    // check if visit data is correctly assigned
    // perform visit

    // check if visit status has been updated
    // check if visit info has been updated
    // check if debt has been assigned to patient
    // check if used materials have been removed correctly
    // check if visit was removed from doctor
    // patient pays
    // check if debt and status has been updated
}
