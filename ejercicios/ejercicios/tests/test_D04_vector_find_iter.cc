#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D04_vector_find_iter.cc"

TEST_CASE("D4: buscar con iteradores") {
    CHECK(find_iterator({5, 7, 9, 7}, 7) == 1);
    CHECK(find_iterator({5, 7, 9}, 5) == 0);
    CHECK(find_iterator({5, 7, 9}, 9) == 2);
}

TEST_CASE("D4: no encontrado") {
    CHECK(find_iterator({5, 7, 9}, 4) == -1);
    CHECK(find_iterator({}, 1) == -1);
}
