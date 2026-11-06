#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "F02_ptr_return_null/Series.h"

TEST_CASE("F2: maximo de una serie") {
    Series s;
    s.add(3);
    s.add(9);
    s.add(2);
    const int* m = s.maximum();
    REQUIRE(m != nullptr);
    CHECK(*m == 9);
}

TEST_CASE("F2: devuelve un puntero al dato interno") {
    Series s;
    s.add(3);
    s.add(9);
    s.add(2);
    CHECK(s.maximum() == s.element(1));
}

TEST_CASE("F2: empate, el primero") {
    Series s;
    s.add(9);
    s.add(3);
    s.add(9);
    CHECK(s.maximum() == s.element(0));
}

TEST_CASE("F2: serie vacia y un elemento") {
    Series s;
    CHECK(s.maximum() == nullptr);
    s.add(-5);
    const int* m = s.maximum();
    REQUIRE(m != nullptr);
    CHECK(*m == -5);
}
