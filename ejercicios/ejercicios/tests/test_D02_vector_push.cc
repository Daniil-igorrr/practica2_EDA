#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D02_vector_push.cc"

TEST_CASE("D2: anade al final modificando el original") {
    vector<int> v = {1, 2};
    append_element(v, 3);
    CHECK(v == vector<int>{1, 2, 3});
}

TEST_CASE("D2: vector vacio y varias veces") {
    vector<int> v;
    append_element(v, 7);
    append_element(v, 8);
    CHECK(v == vector<int>{7, 8});
}
