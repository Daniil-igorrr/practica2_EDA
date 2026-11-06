#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A09_ref_return_string.cc"

TEST_CASE("A9: recorta hasta el caracter") {
    string s = "clave=valor";
    int p = trim_until(s, '=');
    CHECK(p == 5);
    CHECK(s == "valor");
}

TEST_CASE("A9: solo la primera aparicion") {
    string s = "a=b=c";
    int p = trim_until(s, '=');
    CHECK(p == 1);
    CHECK(s == "b=c");
}

TEST_CASE("A9: caracter no encontrado") {
    string s = "sinigual";
    int p = trim_until(s, '=');
    CHECK(p == -1);
    CHECK(s == "sinigual");
}

TEST_CASE("A9: caracter al final y al principio") {
    string s = "abc=";
    CHECK(trim_until(s, '=') == 3);
    CHECK(s == "");
    string t = "=abc";
    CHECK(trim_until(t, '=') == 0);
    CHECK(t == "abc");
}
