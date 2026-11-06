#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A03_ref_swap.cc"

TEST_CASE("A3: intercambia dos enteros") {
    int x = 1;
    int y = 2;
    swap_ints(x, y);
    CHECK(x == 2);
    CHECK(y == 1);
}

TEST_CASE("A3: intercambiar dos veces deja los valores originales") {
    int x = 10;
    int y = -4;
    swap_ints(x, y);
    CHECK(x == -4);
    CHECK(y == 10);
    swap_ints(x, y);
    CHECK(x == 10);
    CHECK(y == -4);
}

TEST_CASE("A3: valores iguales") {
    int x = 7;
    int y = 7;
    swap_ints(x, y);
    CHECK(x == 7);
    CHECK(y == 7);
}
