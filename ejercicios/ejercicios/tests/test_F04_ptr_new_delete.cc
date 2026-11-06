#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/contador_memoria.h"
#include "F04_ptr_new_delete/Token.h"

TEST_CASE("F4: crear una ficha") {
    long antes = g_bloques_objeto;
    Token* f = create_token(7);
    long dentro = g_bloques_objeto;
    REQUIRE(f != nullptr);
    CHECK(f->value() == 7);
    CHECK(dentro == antes + 1);
    delete f;
}

TEST_CASE("F4: destruir libera la memoria") {
    Token* f = create_token(7);
    long antes = g_bloques_objeto;
    destroy_token(f);
    long despues = g_bloques_objeto;
    CHECK(despues == antes - 1);
}

TEST_CASE("F4: destruir nullptr es seguro") {
    destroy_token(nullptr);
    CHECK(true);
}

TEST_CASE("F4: consumir devuelve el valor y libera") {
    Token* g = create_token(3);
    long antes = g_bloques_objeto;
    int v = consume_token(g);
    long despues = g_bloques_objeto;
    CHECK(v == 3);
    CHECK(despues == antes - 1);
}

TEST_CASE("F4: varias fichas sin fugas") {
    long antes = g_bloques_objeto;
    Token* fichas[5];
    for (int i = 0; i < 5; i++) {
        fichas[i] = create_token(i);
    }
    long dentro = g_bloques_objeto;
    int suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += consume_token(fichas[i]);
    }
    long despues = g_bloques_objeto;
    CHECK(dentro == antes + 5);
    CHECK(suma == 10);
    CHECK(despues == antes);
}
