#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "E04_class_destructor/ArrayInt.h"

TEST_CASE("E4: el destructor libera la memoria") {
    long antes = g_bloques_array;
    long dentro = 0;
    {
        ArrayInt a(10, 1);
        ArrayInt b(5, 2);
        dentro = g_bloques_array;
    }
    long despues = g_bloques_array;
    CHECK(dentro == antes + 2);
    CHECK(despues == antes);
}

TEST_CASE("E4: muchos objetos sucesivos") {
    long antes = g_bloques_array;
    for (int i = 0; i < 100; i++) {
        ArrayInt t(1000, i);
        CHECK(t.get(999) == i);
    }
    long despues = g_bloques_array;
    CHECK(despues == antes);
}

TEST_CASE("E4: objeto en memoria dinamica") {
    long antes = g_bloques_array;
    ArrayInt* p = new ArrayInt(5, 0);
    delete p;
    long despues = g_bloques_array;
    CHECK(despues == antes);
}
