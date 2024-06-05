#include "PeselValidatorFixture.hpp"

namespace common
{
namespace validators
{
namespace
{

TEST_F(PeselValidatorFixture, GivenValidPeselWhenValidateThenNoThrowException)
{
    const std::string pesel = "80062378532";

    ExpectNoThrow(pesel);
}

TEST_F(PeselValidatorFixture, GivenInvalidPeselWhenValidateThenThrowException)
{
    const std::string pesel = "12345678901";

    ExpectThrow(pesel);
}

} // namespace
} // namespace validators
} // namespace common
