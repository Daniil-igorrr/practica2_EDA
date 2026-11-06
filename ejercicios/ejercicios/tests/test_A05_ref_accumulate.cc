#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A05_ref_accumulate.cc"

TEST_CASE("A5: acumula en el total") {
    double total = 0;
    double v1 = 0.5;
    double v2 = 1.25;
    add_to_total(v1, total);
    CHECK(total == doctest::Approx(0.5));
    add_to_total(v2, total);
    CHECK(total == doctest::Approx(1.75));
}

TEST_CASE("A5: no modifica el valor sumado") {
    double total = 10;
    double v = 2.5;
    add_to_total(v, total);
    CHECK(v == doctest::Approx(2.5));
    CHECK(total == doctest::Approx(12.5));
}

TEST_CASE("A5: valores negativos") {
    double total = 1;
    double v = -3;
    add_to_total(v, total);
    CHECK(total == doctest::Approx(-2));
}
