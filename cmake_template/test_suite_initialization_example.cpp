#include <boost/test/unit_test.hpp>

#include <gmock/gmock.h>

boost::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    // The following line causes Google Mock to throw an exception on failure,
    // which will be interpreted by your testing framework as a test failure.
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);

    return 0;
}
