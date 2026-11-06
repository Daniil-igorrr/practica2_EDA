#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A02_ref_int.cc"

TEST_CASE("A2: incrementar modifica el original") {
    int x = 5;
    increment(x);
    CHECK(x == 6);
}

TEST_CASE("A2: incrementar varias veces") {
    int x = 5;
    increment(x);
    increment(x);
    increment(x);
    CHECK(x == 8);
    int y = -1;
    increment(y);
    CHECK(y == 0);
}
