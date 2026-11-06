#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "B03_string_find.cc"

TEST_CASE("B3: string find") {
    CHECK(string_find("hola mundo", "mundo") == 5);
    CHECK(string_find("abcabc", "bc") == 1);
    CHECK(string_find("abc", "abc") == 0);
    CHECK(string_find("abc", "c") == 2);
}

TEST_CASE("B3: string find no encontrado") {
    CHECK(string_find("abc", "xyz") == -1);
    CHECK(string_find("abc", "abcd") == -1);
    CHECK(string_find("", "a") == -1);
}
