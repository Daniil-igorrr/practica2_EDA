#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "B05_string_stoi.cc"

TEST_CASE("B5: enteros validos") {
    string a = "42";
    string b = "-7";
    string c = "0";
    int n = 0;
    CHECK(to_int(a, n));
    CHECK(n == 42);
    CHECK(to_int(b, n));
    CHECK(n == -7);
    CHECK(to_int(c, n));
    CHECK(n == 0);
}

TEST_CASE("B5: texto no numerico") {
    string a = "abc";
    string b = "";
    string c = "x12";
    int n = 99;
    CHECK_FALSE(to_int(a, n));
    CHECK_FALSE(to_int(b, n));
    CHECK_FALSE(to_int(c, n));
    CHECK(n == 99);
}

TEST_CASE("B5: fuera de rango") {
    string a = "99999999999999";
    string b = "-99999999999999";
    int n = 5;
    CHECK_FALSE(to_int(a, n));
    CHECK_FALSE(to_int(b, n));
    CHECK(n == 5);
}

TEST_CASE("B5: comportamiento de stoi con texto detras") {
    string a = "12abc";
    int n = 0;
    CHECK(to_int(a, n));
    CHECK(n == 12);
}
