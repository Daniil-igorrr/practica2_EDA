#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A07_ref_string.cc"

TEST_CASE("A7: modifica el original") {
    string s = "hola";
    string suf = "_1";
    append_suffix(s, suf);
    CHECK(s == "hola_1");
}

TEST_CASE("A7: varias llamadas y sufijo intacto") {
    string s = "hola";
    string suf = "_1";
    append_suffix(s, suf);
    append_suffix(s, suf);
    CHECK(s == "hola_1_1");
    CHECK(suf == "_1");
}

TEST_CASE("A7: texto vacio") {
    string s = "";
    string suf = "abc";
    append_suffix(s, suf);
    CHECK(s == "abc");
}
