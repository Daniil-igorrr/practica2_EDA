#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "B04_string_count.cc"

TEST_CASE("B4: string count") {
    CHECK(string_count("abcabcabc", "abc") == 3);
    CHECK(string_count("hola", "x") == 0);
    CHECK(string_count("hola", "hola") == 1);
    CHECK(string_count("", "a") == 0);
}

TEST_CASE("B4: string count sin solapar") {
    CHECK(string_count("aaaa", "aa") == 2);
    CHECK(string_count("aaa", "aa") == 1);
}

TEST_CASE("B4: string count subcadena vacia") {
    CHECK(string_count("hola", "") == 0);
}
