#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "E03_class_copy_ctor/ArrayInt.h"

TEST_CASE("E3: la copia tiene los mismos valores") {
    ArrayInt a(3, 7);
    ArrayInt b(a);
    CHECK(b.size() == 3);
    CHECK(b.get(0) == 7);
    CHECK(b.get(1) == 7);
    CHECK(b.get(2) == 7);
}

TEST_CASE("E3: copia profunda (independiente del original)") {
    ArrayInt a(3, 7);
    ArrayInt b(a);
    b.set(0, 99);
    a.set(2, 55);
    CHECK(a.get(0) == 7);
    CHECK(b.get(0) == 99);
    CHECK(b.get(2) == 7);
    CHECK(a.get(2) == 55);
}

TEST_CASE("E3: la copia sobrevive al original") {
    ArrayInt* p = new ArrayInt(3, 5);
    ArrayInt b(*p);
    delete p;
    CHECK(b.get(0) == 5);
    CHECK(b.get(2) == 5);
}

TEST_CASE("E3: cada objeto tiene su propio array") {
    long antes = g_bloques_array;
    long dentro = 0;
    {
        ArrayInt a(4, 1);
        ArrayInt b(a);
        dentro = g_bloques_array;
    }
    long despues = g_bloques_array;
    CHECK(dentro == antes + 2);
    CHECK(despues == antes);
}
