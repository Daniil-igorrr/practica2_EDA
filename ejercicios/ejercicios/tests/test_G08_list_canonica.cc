#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "G08_list_canonica/List.h"

TEST_CASE("G8: la copia tiene los mismos valores") {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    List b(a);
    CHECK(b.count() == 3);
    CHECK(b.at(0) == 1);
    CHECK(b.at(1) == 2);
    CHECK(b.at(2) == 3);
}

TEST_CASE("G8: la copia es independiente del original") {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    List b(a);
    a.erase(1);
    a.push_back(4);
    CHECK(b.count() == 3);
    CHECK(b.at(0) == 1);
    b.push_front(0);
    CHECK(a.count() == 3);
    CHECK(a.at(0) == 2);
}

TEST_CASE("G8: la copia tiene nodos propios") {
    long antes = g_bloques_objeto;
    long dentro = 0;
    {
        List a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        List b(a);
        dentro = g_bloques_objeto;
    }
    long despues = g_bloques_objeto;
    CHECK(dentro == antes + 6);
    CHECK(despues == antes);
}

TEST_CASE("G8: copiar una lista vacia") {
    List a;
    List b(a);
    CHECK(b.count() == 0);
    b.push_back(5);
    CHECK(b.count() == 1);
    CHECK(a.count() == 0);
}

TEST_CASE("G8: copiar no modifica el original") {
    List a;
    a.push_back(4);
    a.push_back(5);
    List b(a);
    CHECK(a.count() == 2);
    CHECK(a.at(0) == 4);
    CHECK(a.at(1) == 5);
}

TEST_CASE("G8: la asignacion copia los valores") {
    List a;
    a.push_back(1);
    a.push_back(2);
    List b;
    b.push_back(9);
    b = a;
    CHECK(b.count() == 2);
    CHECK(b.at(0) == 1);
    CHECK(b.at(1) == 2);
    CHECK(b.find(9) == nullptr);
}

TEST_CASE("G8: la asignacion libera lo que hubiera antes") {
    List a;
    a.push_back(1);
    List b;
    b.push_back(7);
    b.push_back(8);
    b.push_back(9);
    long antes = g_bloques_objeto;
    b = a;                      // libera 3 nodos y reserva 1
    long despues = g_bloques_objeto;
    CHECK(despues == antes - 2);
    CHECK(b.count() == 1);
}

TEST_CASE("G8: la lista asignada es independiente") {
    List a;
    a.push_back(1);
    a.push_back(2);
    List b;
    b = a;
    a.clear();
    CHECK(b.count() == 2);
    CHECK(b.at(0) == 1);
    b.push_back(3);
    CHECK(a.count() == 0);
}

TEST_CASE("G8: asignar una lista vacia") {
    List a;
    List b;
    b.push_back(1);
    b.push_back(2);
    b = a;
    CHECK(b.count() == 0);
    CHECK(b.at(0) == 0);
    b.push_back(5);
    CHECK(b.count() == 1);
}

TEST_CASE("G8: autoasignacion") {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    long antes = g_bloques_objeto;
    a = a;
    long despues = g_bloques_objeto;
    CHECK(despues == antes);     // ni se pierden ni se reservan nodos
    CHECK(a.count() == 3);
    CHECK(a.at(0) == 1);
    CHECK(a.at(1) == 2);
    CHECK(a.at(2) == 3);
}

TEST_CASE("G8: la asignacion devuelve una referencia a la lista asignada") {
    List a;
    a.push_back(1);
    List b;
    List c;
    CHECK(&(b = a) == &b);
    c = b = a;                   // asignacion en cadena
    CHECK(c.count() == 1);
    CHECK(c.at(0) == 1);
    CHECK(b.count() == 1);
}

TEST_CASE("G8: sin fugas con copias y asignaciones") {
    long antes = g_bloques_objeto;
    {
        List a;
        a.push_back(1);
        a.push_back(2);
        List b(a);
        List c;
        c = a;
        c = c;
        a.clear();
        c = a;
    }
    long despues = g_bloques_objeto;
    CHECK(despues == antes);
}
