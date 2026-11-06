#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "C01_io_to_string.cc"

TEST_CASE("C1: datos primitivos a cadena") {
    CHECK(person_to_string("Ana", 30, 1.75) == "Ana,30,1.75");
    CHECK(person_to_string("Luis", 5, 1.2) == "Luis,5,1.2");
}

TEST_CASE("C1: casos limite") {
    CHECK(person_to_string("", 0, 0) == ",0,0");
    CHECK(person_to_string("Eva", -1, 2.0) == "Eva,-1,2");
}
