#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D05_vector_find_modify.cc"

TEST_CASE("D5: reemplaza solo la primera aparicion") {
    vector<int> v = {5, 7, 9, 7};
    CHECK(replace_first(v, 7, 0));
    CHECK(v == vector<int>{5, 0, 9, 7});
}

TEST_CASE("D5: no encontrado") {
    vector<int> v = {5, 7};
    CHECK_FALSE(replace_first(v, 4, 0));
    CHECK(v == vector<int>{5, 7});
}
