#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <string>
#include <vector>
#include "Playlist.h"

// Requiere: Track, Playlist (constructor, add) y shorterThan.
// No usa: tracksAfterLast.

typedef std::vector<std::string> Ids;

TEST_CASE("X12: shorterThan con la referencia en los extremos y con empates") {
    Ids vacio;

    SUBCASE("Referencia en la primera pista") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 500));
        Ids esperado = {"t02"};
        CHECK(p.shorterThan("t01") == esperado);
    }

    SUBCASE("Referencia en la última pista") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 200));
        Ids esperado = {"t02"};
        CHECK(p.shorterThan("t03") == esperado);
        p.add(Track("t04", "Cuatro", 1000));
        Ids todas = {"t01", "t02", "t03"};
        CHECK(p.shorterThan("t04") == todas);
    }

    SUBCASE("La pista más corta: nada es más corto") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 200));
        CHECK(p.shorterThan("t02") == vacio);
    }

    SUBCASE("Las pistas de igual duración no entran, ni la propia referencia") {
        Playlist p;
        p.add(Track("t01", "Uno", 200));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 200));
        p.add(Track("t04", "Cuatro", 200));
        p.add(Track("t05", "Cinco", 50));
        Ids esperado = {"t02", "t05"};
        CHECK(p.shorterThan("t01") == esperado);
        CHECK(p.shorterThan("t03") == esperado);
        CHECK(p.shorterThan("t04") == esperado);
    }

    SUBCASE("Todas con la misma duración") {
        Playlist p;
        p.add(Track("t01", "Uno", 120));
        p.add(Track("t02", "Dos", 120));
        p.add(Track("t03", "Tres", 120));
        CHECK(p.shorterThan("t01") == vacio);
        CHECK(p.shorterThan("t02") == vacio);
        CHECK(p.shorterThan("t03") == vacio);
    }

    SUBCASE("Duraciones 0 (y negativas, almacenadas como 0)") {
        Playlist p;
        p.add(Track("t01", "Uno", 0));
        p.add(Track("t02", "Dos", -40));
        p.add(Track("t03", "Tres", 1));
        Ids esperado = {"t01", "t02"};
        CHECK(p.shorterThan("t03") == esperado);
        CHECK(p.shorterThan("t01") == vacio);
        CHECK(p.shorterThan("t02") == vacio);
    }

    SUBCASE("Una sola pista") {
        Playlist p;
        p.add(Track("t01", "Uno", 100));
        CHECK(p.shorterThan("t01") == vacio);
    }
}
