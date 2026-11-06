#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D07_vector_erase_first.cc"

TEST_CASE("D7: elimina solo la primera aparicion") {
    vector<int> v = {1, 2, 3, 2};
    CHECK(erase_first(v, 2));
    CHECK(v == vector<int>{1, 3, 2});
}

TEST_CASE("D7: primer y ultimo elemento") {
    vector<int> v = {1, 2, 3};
    CHECK(erase_first(v, 1));
    CHECK(erase_first(v, 3));
    CHECK(v == vector<int>{2});
}

TEST_CASE("D7: no encontrado") {
    vector<int> v = {1, 2, 3};
    CHECK_FALSE(erase_first(v, 9));
    CHECK(v == vector<int>{1, 2, 3});
}
