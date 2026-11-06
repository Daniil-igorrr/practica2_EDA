#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A01_value_int.cc"

TEST_CASE("A1: incrementar copia devuelve n + 1") {
    int x = 5;
    int y = -1;
    CHECK(increment_copy(x) == 6);
    CHECK(increment_copy(y) == 0);
}

TEST_CASE("A1: incrementar copia no modifica el original") {
    int x = 5;
    int r = increment_copy(x);
    CHECK(r == 6);
    CHECK(x == 5);
}
