#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "E05_class_assign/ArrayInt.h"

TEST_CASE("E5: asigna tamano y valores") {
    ArrayInt a(3, 7);
    ArrayInt b(2, 1);
    b = a;
    CHECK(b.size() == 3);
    CHECK(b.get(0) == 7);
    CHECK(b.get(2) == 7);
}

TEST_CASE("E5: copia profunda") {
    ArrayInt a(3, 7);
    ArrayInt b(2, 1);
    b = a;
    b.set(0, 99);
    CHECK(a.get(0) == 7);
    CHECK(b.get(0) == 99);
}

TEST_CASE("E5: no pierde memoria") {
    long antes = g_bloques_array;
    {
        ArrayInt x(4, 1);
        ArrayInt y(6, 2);
        x = y;
    }
    long despues = g_bloques_array;
    CHECK(despues == antes);
}

TEST_CASE("E5: autoasignacion") {
    ArrayInt c(3, 5);
    ArrayInt& ref = c;
    c = ref;
    CHECK(c.size() == 3);
    CHECK(c.get(0) == 5);
    CHECK(c.get(2) == 5);
}

TEST_CASE("E5: asignacion encadenada") {
    ArrayInt p(1, 0);
    ArrayInt q(1, 0);
    ArrayInt r(3, 9);
    p = q = r;
    CHECK(p.size() == 3);
    CHECK(q.size() == 3);
    CHECK(p.get(1) == 9);
}
