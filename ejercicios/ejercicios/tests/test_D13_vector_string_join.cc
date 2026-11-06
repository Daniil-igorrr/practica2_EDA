#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "D13_vector_string_join.cc"

TEST_CASE("D13: une con separador") {
    CHECK(join({"a", "b", "c"}, ", ") == "a, b, c");
    CHECK(join({"uno", "dos"}, "-") == "uno-dos");
}

TEST_CASE("D13: casos limite") {
    CHECK(join({"solo"}, "-") == "solo");
    CHECK(join({}, ",") == "");
    CHECK(join({"a", "", "c"}, "/") == "a//c");
    CHECK(join({"a", "b"}, "") == "ab");
}

TEST_CASE("D13: no modifica el vector") {
    vector<string> v = {"x", "y"};
    string r = join(v, "+");
    CHECK(r == "x+y");
    CHECK(v == vector<string>{"x", "y"});
}
