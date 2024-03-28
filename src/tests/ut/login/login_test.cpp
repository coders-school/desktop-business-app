#include "login_test.hpp"

namespace
{
TEST_F(LoginTestFixture, GivenHashedSHA512DataComparedToCalculatedHashedData)
{
    auto expected_value = "b109f3bbbc244eb82441917ed06d618b9008dd09b3befd1b5e07394c706a8bb980b1d7785e5976ec049b46df5f13"
                          "26af5a2ea6d103fd07c95385ffab0cacbc86";

    EXPECT_EQ(login.getPasswordHash(), expected_value);
}
} // namespace
