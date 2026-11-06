#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G04_list_find/List.h"

TEST_CASE("G4: buscar en una lista vacia") {
    List l;
    CHECK(l.find(0) == nullptr);
    CHECK(l.find(1) == nullptr);
}

TEST_CASE("G4: encontrar el primero, uno del medio y el ultimo") {
    List l;
    l.push_back(4);
    l.push_back(7);
    l.push_back(9);
    const int* p = l.find(4);
    REQUIRE(p != nullptr);
    CHECK(*p == 4);
    const int* q = l.find(7);
    REQUIRE(q != nullptr);
    CHECK(*q == 7);
    const int* r = l.find(9);
    REQUIRE(r != nullptr);
    CHECK(*r == 9);
}

TEST_CASE("G4: valor inexistente") {
    List l;
    l.push_back(4);
    l.push_back(7);
    CHECK(l.find(5) == nullptr);
    CHECK(l.find(0) == nullptr);
}

TEST_CASE("G4: devuelve la direccion del dato, no una copia") {
    List l;
    l.push_back(4);
    l.push_back(7);
    CHECK(l.find(7) == l.find(7));
    CHECK(l.find(7) != l.find(4));
    const int* p = l.find(4);
    REQUIRE(p != nullptr);
    CHECK(*p == l.at(0));
}

TEST_CASE("G4: valores negativos y cero") {
    List l;
    l.push_back(0);
    l.push_back(-3);
    const int* cero = l.find(0);
    const int* neg = l.find(-3);
    REQUIRE(cero != nullptr);
    REQUIRE(neg != nullptr);
    CHECK(*cero == 0);
    CHECK(*neg == -3);
}

TEST_CASE("G4: devuelve la primera aparicion") {
    List l;
    l.push_back(5);
    l.push_back(6);
    l.push_back(5);
    CHECK(l.find(5) == l.find(5));
    CHECK(l.find(5) != l.find(6));
}

TEST_CASE("G4: buscar no modifica la lista ni reserva memoria") {
    List l;
    l.push_back(1);
    l.push_back(2);
    long antes = g_bloques_objeto;
    l.find(2);
    l.find(99);
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
    CHECK(l.count() == 2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
}
