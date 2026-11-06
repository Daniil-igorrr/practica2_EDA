#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A04_ref_two_results.cc"

TEST_CASE("A4: cociente y resto") {
    int a = 17;
    int b = 5;
    int c = 0;
    int r = 0;
    divide(a, b, c, r);
    CHECK(c == 3);
    CHECK(r == 2);
}

TEST_CASE("A4: division exacta y operandos intactos") {
    int a = 20;
    int b = 4;
    int c = -1;
    int r = -1;
    divide(a, b, c, r);
    CHECK(c == 5);
    CHECK(r == 0);
    CHECK(a == 20);
    CHECK(b == 4);
}

TEST_CASE("A4: divisor cero") {
    int a = 9;
    int b = 0;
    int c = -1;
    int r = -1;
    divide(a, b, c, r);
    CHECK(c == 0);
    CHECK(r == 0);
}
