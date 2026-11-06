#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D08_vector_erase_all.cc"

TEST_CASE("D8: elimina todas las apariciones") {
    vector<int> v = {1, 2, 1, 3, 1};
    CHECK(erase_all(v, 1) == 3);
    CHECK(v == vector<int>{2, 3});
}

TEST_CASE("D8: apariciones consecutivas") {
    vector<int> v = {1, 1, 2, 1, 1};
    CHECK(erase_all(v, 1) == 4);
    CHECK(v == vector<int>{2});
}

TEST_CASE("D8: todo igual, ninguno y vacio") {
    vector<int> v = {4, 4, 4};
    CHECK(erase_all(v, 4) == 3);
    CHECK(v.empty());
    vector<int> w = {1, 2};
    CHECK(erase_all(w, 5) == 0);
    CHECK(w == vector<int>{1, 2});
    vector<int> vacio;
    CHECK(erase_all(vacio, 1) == 0);
}
