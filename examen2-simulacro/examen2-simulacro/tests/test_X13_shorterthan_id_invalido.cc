#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <string>
#include <vector>
#include "Playlist.h"

// Requiere: Track, Playlist (constructor, add) y shorterThan.
// No usa: tracksAfterLast.

typedef std::vector<std::string> Ids;

TEST_CASE("X13: shorterThan con una referencia que no existe") {
    Ids vacio;

    SUBCASE("Lista vacía") {
        Playlist p;
        CHECK(p.shorterThan("t01") == vacio);
        CHECK(p.shorterThan("") == vacio);
        CHECK(p.size() == 0);
    }

    SUBCASE("Id inexistente, prefijo, otras mayúsculas o vacío") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 200));
        CHECK(p.shorterThan("t04") == vacio);
        CHECK(p.shorterThan("t0") == vacio);
        CHECK(p.shorterThan("t011") == vacio);
        CHECK(p.shorterThan("T01") == vacio);
        CHECK(p.shorterThan("") == vacio);
    }

    SUBCASE("La referencia se busca por id, no por título") {
        Playlist p;
        p.add(Track("t01", "t03", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "t01", 200));
        Ids esperado = {"t02"};
        CHECK(p.shorterThan("t03") == esperado);
        Ids esperado1 = {"t02", "t03"};
        CHECK(p.shorterThan("t01") == esperado1);
    }

    SUBCASE("Una pista rechazada por add no cambia la referencia") {
        Playlist p;
        p.add(Track("t01", "Uno", 100));
        p.add(Track("t02", "Dos", 200));
        CHECK_FALSE(p.add(Track("t01", "Repetida", 900)));
        CHECK_FALSE(p.add(Track("", "Sin id", 1)));
        Ids esperado = {"t01"};
        CHECK(p.shorterThan("t02") == esperado);
        CHECK(p.shorterThan("t01") == vacio);
        CHECK(p.size() == 2);
    }

    SUBCASE("La consulta no modifica la lista") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.shorterThan("t01");
        p.shorterThan("nada");
        CHECK(p.size() == 2);
        CHECK_FALSE(p.add(Track("t01", "x", 1)));
        CHECK_FALSE(p.add(Track("t02", "x", 1)));
        CHECK(p.add(Track("t03", "Tres", 1)));
        CHECK(p.size() == 3);
    }

    SUBCASE("Se puede llamar sobre una lista const") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        const Playlist& c = p;
        Ids esperado = {"t02"};
        CHECK(c.shorterThan("t01") == esperado);
    }
}
