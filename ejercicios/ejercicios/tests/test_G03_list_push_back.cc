#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G03_list_push_back/List.h"

TEST_CASE("G3: anadir a una lista vacia") {
    List l;
    l.push_back(5);
    CHECK(l.count() == 1);
    CHECK(l.at(0) == 5);
    CHECK(l.at(1) == 0);
}

TEST_CASE("G3: el orden se conserva") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    CHECK(l.count() == 3);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 3);
    CHECK(l.at(3) == 0);
}

TEST_CASE("G3: combinado con insertar al principio") {
    List l;
    l.push_back(2);
    l.push_front(1);
    l.push_back(3);
    l.push_front(0);
    CHECK(l.count() == 4);
    CHECK(l.at(0) == 0);
    CHECK(l.at(1) == 1);
    CHECK(l.at(2) == 2);
    CHECK(l.at(3) == 3);
}

TEST_CASE("G3: anadir despues de una sola insercion al principio") {
    List l;
    l.push_front(1);
    l.push_back(2);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
}

TEST_CASE("G3: muchos elementos") {
    List l;
    for (int i = 0; i < 100; i++) {
        l.push_back(i);
    }
    CHECK(l.count() == 100);
    CHECK(l.at(0) == 0);
    CHECK(l.at(50) == 50);
    CHECK(l.at(99) == 99);
    CHECK(l.at(100) == 0);
}

TEST_CASE("G3: un nodo por elemento y sin fugas") {
    long antes = g_bloques_objeto;
    long dentro = 0;
    {
        List l;
        l.push_back(1);
        l.push_back(2);
        l.push_front(0);
        dentro = g_bloques_objeto;
    }
    long despues = g_bloques_objeto;
    CHECK(dentro == antes + 3);
    CHECK(despues == antes);
}
