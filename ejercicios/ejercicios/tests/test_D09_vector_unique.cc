#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D09_vector_unique.cc"

TEST_CASE("D9: elimina duplicados conservando el orden") {
    vector<int> v = {1, 2, 1, 3, 2, 1};
    remove_duplicates(v);
    CHECK(v == vector<int>{1, 2, 3});
}

TEST_CASE("D9: todos iguales") {
    vector<int> v = {4, 4, 4};
    remove_duplicates(v);
    CHECK(v == vector<int>{4});
}

TEST_CASE("D9: sin duplicados y vacio") {
    vector<int> v = {3, 1, 2};
    remove_duplicates(v);
    CHECK(v == vector<int>{3, 1, 2});
    vector<int> vacio;
    remove_duplicates(vacio);
    CHECK(vacio.empty());
}
