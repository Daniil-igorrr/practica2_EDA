#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G05_list_clear/List.h"

TEST_CASE("G5: vaciar libera todos los nodos") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    long antes = g_bloques_objeto;
    l.clear();
    long despues = g_bloques_objeto;
    CHECK(despues == antes - 3);
    CHECK(l.count() == 0);
    CHECK(l.at(0) == 0);
    CHECK(l.find(1) == nullptr);
}

TEST_CASE("G5: la lista se puede reutilizar tras vaciar") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.clear();
    l.push_back(9);
    l.push_front(8);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 8);
    CHECK(l.at(1) == 9);
}

TEST_CASE("G5: vaciar una lista vacia y vaciar dos veces seguidas") {
    List l;
    l.clear();
    CHECK(l.count() == 0);
    l.push_back(1);
    l.clear();
    l.clear();
    CHECK(l.count() == 0);
    CHECK(l.at(0) == 0);
}

TEST_CASE("G5: el destructor tras vaciar no libera dos veces") {
    long antes = g_bloques_objeto;
    {
        List l;
        l.push_back(1);
        l.push_back(2);
        l.clear();
    }
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
}

TEST_CASE("G5: el destructor sigue liberando la lista") {
    long antes = g_bloques_objeto;
    long dentro = 0;
    {
        List l;
        for (int i = 0; i < 5; i++) {
            l.push_back(i);
        }
        dentro = g_bloques_objeto;
    }
    long despues = g_bloques_objeto;
    CHECK(dentro == antes + 5);
    CHECK(despues == antes);
}

TEST_CASE("G5: vaciar y volver a llenar varias veces") {
    long antes = g_bloques_objeto;
    int n = 0;
    {
        List l;
        for (int vuelta = 0; vuelta < 3; vuelta++) {
            for (int i = 0; i < 4; i++) {
                l.push_back(i);
            }
            l.clear();
        }
        l.push_back(7);
        n = l.count();
    }
    long despues = g_bloques_objeto;
    CHECK(n == 1);
    CHECK(despues == antes);
}
