#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "F05_ptr_vs_ref/Swapper.h"

TEST_CASE("F5: intercambiar con punteros") {
    Swapper inter;
    int x = 1;
    int y = 2;
    inter.with_pointers(&x, &y);
    CHECK(x == 2);
    CHECK(y == 1);
}

TEST_CASE("F5: intercambiar con referencias") {
    Swapper inter;
    int x = 1;
    int y = 2;
    inter.with_references(x, y);
    CHECK(x == 2);
    CHECK(y == 1);
}

TEST_CASE("F5: dos intercambios devuelven los valores originales") {
    Swapper inter;
    int x = 10;
    int y = -4;
    inter.with_pointers(&x, &y);
    inter.with_pointers(&x, &y);
    CHECK(x == 10);
    CHECK(y == -4);
    inter.with_references(x, y);
    inter.with_references(x, y);
    CHECK(x == 10);
    CHECK(y == -4);
}

TEST_CASE("F5: punteros nulos") {
    Swapper inter;
    int x = 1;
    inter.with_pointers(&x, nullptr);
    inter.with_pointers(nullptr, &x);
    inter.with_pointers(nullptr, nullptr);
    CHECK(x == 1);
}

TEST_CASE("F5: la misma variable dos veces") {
    Swapper inter;
    int x = 5;
    inter.with_pointers(&x, &x);
    CHECK(x == 5);
    inter.with_references(x, x);
    CHECK(x == 5);
}
