#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "B02_string_remove.cc"

TEST_CASE("B2: string remove") {
    CHECK(string_remove("banana", 'a') == "bnn");
    CHECK(string_remove("hola mundo", ' ') == "holamundo");
    CHECK(string_remove("abc", 'z') == "abc");
    CHECK(string_remove("aaa", 'a') == "");
    CHECK(string_remove("", 'a') == "");
}

TEST_CASE("B2: string remove no modifica el original") {
    string s = "banana";
    string r = string_remove(s, 'n');
    CHECK(r == "baaa");
    CHECK(s == "banana");
}
