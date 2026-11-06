#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G06_list_erase/List.h"

TEST_CASE("G6: eliminar en el medio") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    long antes = g_bloques_objeto;
    bool r = l.erase(2);
    long despues = g_bloques_objeto;
    CHECK(r);
    CHECK(despues == antes - 1);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 3);
    CHECK(l.at(2) == 0);
}

TEST_CASE("G6: eliminar el primero") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    CHECK(l.erase(1));
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 2);
    CHECK(l.at(1) == 3);
}

TEST_CASE("G6: eliminar el ultimo") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    CHECK(l.erase(3));
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 0);
    l.push_back(4);
    CHECK(l.at(2) == 4);
}

TEST_CASE("G6: eliminar el unico elemento") {
    List l;
    l.push_back(7);
    CHECK(l.erase(7));
    CHECK(l.count() == 0);
    CHECK(l.at(0) == 0);
    CHECK(l.find(7) == nullptr);
    l.push_back(8);
    CHECK(l.count() == 1);
    CHECK(l.at(0) == 8);
}

TEST_CASE("G6: valor inexistente y lista vacia") {
    List l;
    CHECK_FALSE(l.erase(1));
    CHECK(l.count() == 0);
    l.push_back(1);
    l.push_back(2);
    long antes = g_bloques_objeto;
    bool r = l.erase(9);
    long despues = g_bloques_objeto;
    CHECK_FALSE(r);
    CHECK(despues == antes);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
}

TEST_CASE("G6: solo se elimina la primera aparicion") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    CHECK(l.erase(1));
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 2);
    CHECK(l.at(1) == 1);
}

TEST_CASE("G6: solo la primera aparicion, aunque no sea el primer nodo") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(2);
    CHECK(l.erase(2));
    CHECK(l.count() == 3);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 3);
    CHECK(l.at(2) == 2);
}

TEST_CASE("G6: eliminar todos los elementos uno a uno") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    CHECK(l.erase(2));
    CHECK(l.erase(3));
    CHECK(l.erase(1));
    CHECK(l.count() == 0);
    CHECK(l.at(0) == 0);
    l.push_front(5);
    CHECK(l.count() == 1);
    CHECK(l.at(0) == 5);
}

TEST_CASE("G6: no quedan fugas") {
    long antes = g_bloques_objeto;
    {
        List l;
        for (int i = 0; i < 6; i++) {
            l.push_back(i);
        }
        l.erase(0);
        l.erase(3);
        l.erase(5);
        l.erase(99);
    }
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
}
