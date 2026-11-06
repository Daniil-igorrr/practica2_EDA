#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D10_vector_filter.cc"

TEST_CASE("D10: filtra los mayores que el umbral") {
    CHECK(filter_greater({1, 5, 3, 8, 2}, 3) == vector<int>{5, 8});
    CHECK(filter_greater({10, 20, 30}, 0) == vector<int>{10, 20, 30});
}

TEST_CASE("D10: ninguno cumple y vacio") {
    CHECK(filter_greater({1, 2}, 5).empty());
    CHECK(filter_greater({}, 0).empty());
}

TEST_CASE("D10: no modifica el original") {
    vector<int> v = {1, 5, 3, 8};
    vector<int> r = filter_greater(v, 3);
    CHECK(v == vector<int>{1, 5, 3, 8});
    CHECK(r.size() == 2);
}
