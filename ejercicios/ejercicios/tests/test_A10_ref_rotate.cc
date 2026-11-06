#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A10_ref_rotate.cc"

TEST_CASE("A10: rota tres strings") {
    string x = "uno";
    string y = "dos";
    string z = "tres";
    rotate_three(x, y, z);
    CHECK(x == "dos");
    CHECK(y == "tres");
    CHECK(z == "uno");
}

TEST_CASE("A10: tres rotaciones devuelven el estado inicial") {
    string x = "uno";
    string y = "dos";
    string z = "tres";
    rotate_three(x, y, z);
    rotate_three(x, y, z);
    rotate_three(x, y, z);
    CHECK(x == "uno");
    CHECK(y == "dos");
    CHECK(z == "tres");
}

TEST_CASE("A10: valores repetidos y vacios") {
    string x = "a";
    string y = "";
    string z = "a";
    rotate_three(x, y, z);
    CHECK(x == "");
    CHECK(y == "a");
    CHECK(z == "a");
}
