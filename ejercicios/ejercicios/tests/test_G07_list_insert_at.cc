#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G07_list_insert_at/List.h"

TEST_CASE("G7: insertar en el medio") {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    CHECK(l.insert_at(1, 9));
    CHECK(l.count() == 4);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 9);
    CHECK(l.at(2) == 2);
    CHECK(l.at(3) == 3);
}

TEST_CASE("G7: insertar al principio") {
    List l;
    l.push_back(1);
    l.push_back(2);
    CHECK(l.insert_at(0, 8));
    CHECK(l.count() == 3);
    CHECK(l.at(0) == 8);
    CHECK(l.at(1) == 1);
    CHECK(l.at(2) == 2);
}

TEST_CASE("G7: insertar al final equivale a push_back") {
    List l;
    l.push_back(1);
    l.push_back(2);
    CHECK(l.insert_at(2, 9));       // pos == count()
    CHECK(l.count() == 3);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 9);
}

TEST_CASE("G7: lista vacia") {
    List l;
    CHECK_FALSE(l.insert_at(1, 5));
    CHECK(l.count() == 0);
    CHECK(l.insert_at(0, 5));
    CHECK(l.count() == 1);
    CHECK(l.at(0) == 5);
}

TEST_CASE("G7: posicion invalida no inserta ni reserva memoria") {
    List l;
    l.push_back(1);
    l.push_back(2);
    long antes = g_bloques_objeto;
    CHECK_FALSE(l.insert_at(-1, 9));
    CHECK_FALSE(l.insert_at(3, 9));
    CHECK_FALSE(l.insert_at(99, 9));
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
}

TEST_CASE("G7: varias inserciones seguidas") {
    List l;
    CHECK(l.insert_at(0, 1));
    CHECK(l.insert_at(1, 3));
    CHECK(l.insert_at(1, 2));
    CHECK(l.insert_at(0, 0));
    CHECK(l.count() == 4);
    CHECK(l.at(0) == 0);
    CHECK(l.at(1) == 1);
    CHECK(l.at(2) == 2);
    CHECK(l.at(3) == 3);
}

TEST_CASE("G7: la lista sigue coherente despues de insertar") {
    List l;
    l.push_back(1);
    l.push_back(3);
    CHECK(l.insert_at(1, 2));
    const int* p = l.find(2);
    REQUIRE(p != nullptr);
    CHECK(*p == 2);
    CHECK(l.erase(2));
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 3);
}

TEST_CASE("G7: sin fugas") {
    long antes = g_bloques_objeto;
    long dentro = 0;
    {
        List l;
        l.insert_at(0, 1);
        l.insert_at(1, 3);
        l.insert_at(1, 2);
        dentro = g_bloques_objeto;
    }
    long despues = g_bloques_objeto;
    CHECK(dentro == antes + 3);
    CHECK(despues == antes);
}
