#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "F01_ptr_read_write/Cell.h"

TEST_CASE("F1: escribir a traves del puntero") {
    Cell c(5);
    int* p = c.address();
    REQUIRE(p != nullptr);
    CHECK(*p == 5);
    *p = 9;
    CHECK(c.get() == 9);
}

TEST_CASE("F1: dos llamadas dan el mismo puntero") {
    Cell a(1);
    Cell b(1);
    CHECK(a.address() == a.address());
    CHECK(a.address() != b.address());
}

TEST_CASE("F1: sumar a una variable") {
    Cell c(5);
    int total = 100;
    c.add_to(&total);
    CHECK(total == 105);
    c.add_to(&total);
    CHECK(total == 110);
    CHECK(c.get() == 5);
}

TEST_CASE("F1: puntero nulo") {
    Cell c(5);
    c.add_to(nullptr);
    CHECK(c.get() == 5);
}
