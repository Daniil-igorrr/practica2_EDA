#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D14_vector_string_longest.cc"

TEST_CASE("D14: devuelve el mas largo") {
    CHECK(longest({"sol", "elefante", "gato"}) == "elefante");
    CHECK(longest({"a", "bb", "ccc"}) == "ccc");
    CHECK(longest({"largo", "b", "c"}) == "largo");
}

TEST_CASE("D14: empate, el primero") {
    CHECK(longest({"ab", "cd", "e"}) == "ab");
    CHECK(longest({"x", "y"}) == "x");
}

TEST_CASE("D14: un elemento y vacio") {
    CHECK(longest({"hola"}) == "hola");
    CHECK(longest({}) == "");
}
