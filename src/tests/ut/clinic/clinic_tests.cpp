#include "clinic_facade.hpp"
#include "gtest/gtest.h"

class ClinicTestFixture : public ::testing::Test
{
    template <typename T> void removeObjects()
    {
        for (const auto& object : Clinic::getObjects<T>())
        {
            Clinic::removeObject(object);
        }
    }

  protected:
    void TearDown() override
    {
        removeObjects<Doctor>();
        removeObjects<Receptionist>();
        removeObjects<Visit>();
    }
    void createDoctor()
    {
        Doctor{"Jan", "Pawel", "00000012345"};
    }
    void ExpectSize(const size_t doctor_size, const size_t receptionist_size, const size_t visit_size)
    {
        EXPECT_EQ(Clinic::getObjects<Doctor>().size(), doctor_size);
        EXPECT_EQ(Clinic::getObjects<Receptionist>().size(), receptionist_size);
        EXPECT_EQ(Clinic::getObjects<Visit>().size(), visit_size);
    }
};

TEST_F(ClinicTestFixture, GivenObjectConstructedExpectExtentSizeIncreased)
{
    Doctor doc{"Jan", "Pawel", "00000012345"};

    ExpectSize(1, 0, 0);
}

TEST_F(ClinicTestFixture, GivenObjectConstructedThenRemovedExpectEmptyExtent)
{
    Doctor doc{"Jan", "Pawel", "00000012345"};

    const std::string name{"Jan"};
    auto doc_it = std::find_if(Clinic::getObjects<Doctor>().begin(), Clinic::getObjects<Doctor>().end(),
                               [&name](const auto& doc) { return doc.getFirstName() == name; });
    Clinic::removeObject(*doc_it);

    ExpectSize(0, 0, 0);
}

TEST_F(ClinicTestFixture, GivenObjectConstructedThenRemovedExpectEmptyExtent2)
{
    createDoctor();
    const std::string name{"Jan"};
    auto doc_it = std::find_if(Clinic::getObjects<Doctor>().begin(), Clinic::getObjects<Doctor>().end(),
                               [&name](const auto& doc) { return doc.getFirstName() == name; });

    Clinic::removeObject(doc_it);

    ExpectSize(0, 0, 0);
}

TEST_F(ClinicTestFixture, test3)
{
    createDoctor();
    const std::string name{"Jan"};

    auto doc_it = std::find_if(Clinic::getObjects<Doctor>().begin(), Clinic::getObjects<Doctor>().end(),
                               [&name](const auto& doc) { return doc.getFirstName() == name; });
    Visit{*doc_it};
    ExpectSize(1, 0, 1);
}