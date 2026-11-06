#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D03_vector_find_index.cc"

TEST_CASE("D3: buscar con indices") {
    CHECK(find_index({5, 7, 9, 7}, 7) == 1);
    CHECK(find_index({5, 7, 9}, 5) == 0);
    CHECK(find_index({5, 7, 9}, 9) == 2);
}

TEST_CASE("D3: no encontrado") {
    CHECK(find_index({5, 7, 9}, 4) == -1);
    CHECK(find_index({}, 1) == -1);
}
