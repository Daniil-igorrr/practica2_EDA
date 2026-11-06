#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <string>
#include <vector>
#include "Playlist.h"

// Requiere: Track, Playlist (constructor, destructor, constructor de copia,
// add, size, empty) y tracksAfterLast.
// No usa: shorterThan. El orden del resultado no se comprueba.

// Dice si la lista contiene el id usando solo add: si add devuelve false, el
// id ya estaba. Ojo: si el id NO estaba, add lo añade a la lista.
static bool contiene(Playlist& p, const std::string& id) {
    return !p.add(Track(id, "x", 1));
}

typedef std::vector<std::string> Ids;

TEST_CASE("X16: tracksAfterLast con varias coincidencias y con la marca al final") {
    Playlist p;
    p.add(Track("t01", "Uno", 100));
    p.add(Track("t02", "Dos", 200));
    p.add(Track("t03", "Tres", 300));
    p.add(Track("t04", "Cuatro", 400));
    p.add(Track("t05", "Cinco", 500));

    SUBCASE("La marca es la última pista: resultado vacío") {
        Ids ids = {"t05"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 0);
        CHECK(r.empty());
    }

    SUBCASE("Todos los ids a la vez: la última pista es la marca") {
        Ids ids = {"t01", "t02", "t03", "t04", "t05"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 0);
        CHECK(r.empty());
    }

    SUBCASE("El orden de los ids no importa") {
        Ids a = {"t01", "t04"};
        Ids b = {"t04", "t01"};
        Playlist ra = p.tracksAfterLast(a);
        Playlist rb = p.tracksAfterLast(b);
        CHECK(ra.size() == 1);
        CHECK(rb.size() == 1);
        CHECK(contiene(ra, "t05"));
        CHECK(contiene(rb, "t05"));
    }

    SUBCASE("Con ids en orden inverso al de la lista") {
        Ids ids = {"t05", "t03", "t01"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.empty());                  // t05 es la última
        Ids ids2 = {"t03", "t01"};
        Playlist r2 = p.tracksAfterLast(ids2);
        CHECK(r2.size() == 2);             // t04 y t05
        CHECK(contiene(r2, "t04"));
        CHECK(contiene(r2, "t05"));
    }

    SUBCASE("Ids repetidos") {
        Ids ids = {"t02", "t02", "t02"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 3);
        CHECK(contiene(r, "t03"));
        CHECK(contiene(r, "t04"));
        CHECK(contiene(r, "t05"));
    }

    SUBCASE("Ids existentes mezclados con inexistentes") {
        Ids ids = {"zz", "t02", "nada", "t03", "otro"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 2);              // marca t03: quedan t04 y t05
        CHECK(contiene(r, "t04"));
        CHECK(contiene(r, "t05"));
    }

    SUBCASE("Lista de una sola pista: la marca es la última") {
        Playlist q;
        q.add(Track("solo", "Solo", 10));
        Ids ids = {"solo"};
        CHECK(q.tracksAfterLast(ids).empty());
    }

    SUBCASE("Lista de dos pistas") {
        Playlist q;
        q.add(Track("a", "A", 1));
        q.add(Track("b", "B", 2));
        Ids ia = {"a"};
        Playlist r = q.tracksAfterLast(ia);
        CHECK(r.size() == 1);
        CHECK(contiene(r, "b"));
        CHECK_FALSE(contiene(r, "a"));
        Ids ib = {"b"};
        CHECK(q.tracksAfterLast(ib).empty());
    }
}
