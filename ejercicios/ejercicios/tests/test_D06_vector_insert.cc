#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D06_vector_insert.cc"

TEST_CASE("D6: insertar en el medio") {
    vector<int> v = {1, 2, 3};
    insert_at(v, 1, 9);
    CHECK(v == vector<int>{1, 9, 2, 3});
}

TEST_CASE("D6: insertar al principio y al final") {
    vector<int> v = {1, 2, 3};
    insert_at(v, 0, 9);
    CHECK(v == vector<int>{9, 1, 2, 3});
    insert_at(v, 4, 8);
    CHECK(v == vector<int>{9, 1, 2, 3, 8});
}

TEST_CASE("D6: posicion fuera de rango y vector vacio") {
    vector<int> v = {1, 2, 3};
    insert_at(v, 10, 9);
    CHECK(v == vector<int>{1, 2, 3, 9});
    vector<int> vacio;
    insert_at(vacio, 0, 5);
    CHECK(vacio == vector<int>{5});
}
