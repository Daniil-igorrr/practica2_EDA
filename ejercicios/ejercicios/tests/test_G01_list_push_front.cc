#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G01_list_push_front/List.h"

TEST_CASE("G1: la lista empieza vacia") {
    List l;
    CHECK(l.count() == 0);
}

TEST_CASE("G1: contar tras insertar al principio") {
    List l;
    l.push_front(3);
    CHECK(l.count() == 1);
    l.push_front(5);
    l.push_front(7);
    CHECK(l.count() == 3);
}

TEST_CASE("G1: contar no destruye la lista") {
    List l;
    l.push_front(1);
    l.push_front(2);
    l.count();
    l.count();
    CHECK(l.count() == 2);
}

TEST_CASE("G1: cada insercion reserva un nodo y el destructor los libera") {
    long antes = g_bloques_objeto;
    long dentro = 0;
    {
        List l;
        l.push_front(1);
        l.push_front(2);
        l.push_front(3);
        dentro = g_bloques_objeto;
    }
    long despues = g_bloques_objeto;
    CHECK(dentro == antes + 3);
    CHECK(despues == antes);
}

TEST_CASE("G1: el destructor de una lista vacia no reserva ni libera nada") {
    long antes = g_bloques_objeto;
    {
        List l;
    }
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
}

TEST_CASE("G1: muchos elementos") {
    long antes = g_bloques_objeto;
    int n = 0;
    {
        List l;
        for (int i = 0; i < 100; i++) {
            l.push_front(i);
        }
        n = l.count();
    }
    long despues = g_bloques_objeto;
    CHECK(n == 100);
    CHECK(despues == antes);
}
