#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D12_vector_sort_algorithm.cc"

TEST_CASE("D12: ordena de mayor a menor") {
    vector<int> v = {3, 1, 4, 1, 5};
    sort_desc(v);
    CHECK(v == vector<int>{5, 4, 3, 1, 1});
}

TEST_CASE("D12: ya ordenado, un elemento y vacio") {
    vector<int> v = {9, 5, 2};
    sort_desc(v);
    CHECK(v == vector<int>{9, 5, 2});
    vector<int> uno = {7};
    sort_desc(uno);
    CHECK(uno == vector<int>{7});
    vector<int> vacio;
    sort_desc(vacio);
    CHECK(vacio.empty());
}
