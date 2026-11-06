#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D01_vector_copy_push.cc"

TEST_CASE("D1: copia con elemento al final") {
    const vector<int> v = {1, 2, 3};
    vector<int> r = with_element(v, 4);
    CHECK(r == vector<int>{1, 2, 3, 4});
}

TEST_CASE("D1: no modifica el original") {
    vector<int> v = {1, 2, 3};
    vector<int> r = with_element(v, 4);
    CHECK(v == vector<int>{1, 2, 3});
    CHECK(r.size() == 4);
}

TEST_CASE("D1: vector vacio") {
    CHECK(with_element({}, 5) == vector<int>{5});
}
