#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D11_vector_sort_manual.cc"

TEST_CASE("D11: ordena de menor a mayor") {
    CHECK(sorted_manual({5, 2, 9, 1, 5}) == vector<int>{1, 2, 5, 5, 9});
    CHECK(sorted_manual({3, 2, 1}) == vector<int>{1, 2, 3});
}

TEST_CASE("D11: ya ordenado, un elemento y vacio") {
    CHECK(sorted_manual({1, 2, 3}) == vector<int>{1, 2, 3});
    CHECK(sorted_manual({7}) == vector<int>{7});
    CHECK(sorted_manual({}).empty());
}

TEST_CASE("D11: no modifica el original") {
    vector<int> v = {3, 1, 2};
    vector<int> r = sorted_manual(v);
    CHECK(v == vector<int>{3, 1, 2});
    CHECK(r == vector<int>{1, 2, 3});
}
