#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <string>
#include <vector>
#include "Playlist.h"

// Requiere: Track, Playlist (constructor, add) y shorterThan.
// No usa: tracksAfterLast.

typedef std::vector<std::string> Ids;

TEST_CASE("X11: shorterThan devuelve los ids de las pistas más cortas, en orden") {
    SUBCASE("Referencia en medio") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 200));
        p.add(Track("t04", "Cuatro", 50));
        p.add(Track("t05", "Cinco", 400));

        Ids esperado = {"t02", "t04"};
        CHECK(p.shorterThan("t03") == esperado);
    }

    SUBCASE("Con la más larga, salen todas las demás") {
        Playlist p;
        p.add(Track("t01", "Uno", 300));
        p.add(Track("t02", "Dos", 100));
        p.add(Track("t03", "Tres", 900));
        p.add(Track("t04", "Cuatro", 50));

        Ids esperado = {"t01", "t02", "t04"};
        CHECK(p.shorterThan("t03") == esperado);
    }

    SUBCASE("Varias consultas seguidas sobre la misma lista") {
        Playlist p;
        p.add(Track("a", "A", 30));
        p.add(Track("b", "B", 10));
        p.add(Track("c", "C", 20));

        Ids ea = {"b", "c"};
        Ids ec = {"b"};
        Ids eb;
        CHECK(p.shorterThan("a") == ea);
        CHECK(p.shorterThan("c") == ec);
        CHECK(p.shorterThan("b") == eb);
        CHECK(p.shorterThan("a") == ea);
    }
}
