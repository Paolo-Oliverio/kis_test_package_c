#include <kis_test_package_c/kis_test_package_c.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Fake test that always passes") {
    kis::test_package_c::hello();
    CHECK(true);
}