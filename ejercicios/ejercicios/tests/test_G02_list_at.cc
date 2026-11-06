#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G02_list_at/List.h"

TEST_CASE("G2: at en una lista vacia") {
    List l;
    CHECK(l.at(0) == 0);
    CHECK(l.at(1) == 0);
    CHECK(l.at(-1) == 0);
}

TEST_CASE("G2: el ultimo insertado queda en la posicion 0") {
    List l;
    l.push_front(3);
    l.push_front(5);
    l.push_front(7);
    CHECK(l.at(0) == 7);
    CHECK(l.at(1) == 5);
    CHECK(l.at(2) == 3);
}

TEST_CASE("G2: posiciones que no existen") {
    List l;
    l.push_front(1);
    l.push_front(2);
    CHECK(l.count() == 2);
    CHECK(l.at(2) == 0);     // at(count()) no existe
    CHECK(l.at(7) == 0);
    CHECK(l.at(-1) == 0);
    CHECK(l.at(-5) == 0);
}

TEST_CASE("G2: un solo elemento") {
    List l;
    l.push_front(9);
    CHECK(l.at(0) == 9);
    CHECK(l.at(1) == 0);
}

TEST_CASE("G2: at no modifica la lista") {
    List l;
    l.push_front(1);
    l.push_front(2);
    l.at(0);
    l.at(1);
    l.at(99);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 2);
    CHECK(l.at(0) == 2);
    CHECK(l.at(1) == 1);
}

TEST_CASE("G2: valores negativos y cero") {
    List l;
    l.push_front(0);
    l.push_front(-3);
    CHECK(l.at(0) == -3);
    CHECK(l.at(1) == 0);
}

TEST_CASE("G2: sin fugas") {
    long antes = g_bloques_objeto;
    {
        List l;
        for (int i = 0; i < 20; i++) {
            l.push_front(i);
        }
        l.at(19);
    }
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
}
