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

TEST_CASE("X15: tracksAfterLast devuelve las pistas posteriores a la última seleccionada") {
    Playlist p;
    p.add(Track("t01", "Uno", 100));
    p.add(Track("t02", "Dos", 200));
    p.add(Track("t03", "Tres", 300));
    p.add(Track("t04", "Cuatro", 400));
    p.add(Track("t05", "Cinco", 500));

    SUBCASE("Un solo id en medio") {
        Ids ids = {"t03"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 2);
        CHECK_FALSE(r.empty());
        CHECK(contiene(r, "t04"));
        CHECK(contiene(r, "t05"));
        CHECK_FALSE(contiene(r, "t01"));   // no estaba: add la añade
        CHECK_FALSE(contiene(r, "t02"));
        CHECK_FALSE(contiene(r, "t03"));   // la marca no se incluye
    }

    SUBCASE("La marca es la primera pista") {
        Ids ids = {"t01"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 4);
        CHECK(contiene(r, "t02"));
        CHECK(contiene(r, "t03"));
        CHECK(contiene(r, "t04"));
        CHECK(contiene(r, "t05"));
        CHECK_FALSE(contiene(r, "t01"));
    }

    SUBCASE("La marca es la penúltima pista") {
        Ids ids = {"t04"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 1);
        CHECK(contiene(r, "t05"));
        CHECK_FALSE(contiene(r, "t04"));
    }

    SUBCASE("Varios ids: cuenta el que está más cerca del final") {
        Ids ids = {"t02", "t04"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 1);
        CHECK(contiene(r, "t05"));
        CHECK_FALSE(contiene(r, "t03"));
    }

    SUBCASE("La lista original no se modifica") {
        Ids ids = {"t02"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 3);
        CHECK(p.size() == 5);
        for (int i = 1; i <= 5; i++) {
            CHECK(contiene(p, "t0" + std::to_string(i)));
        }
        CHECK(p.size() == 5);
    }

    SUBCASE("Se puede llamar sobre una lista const") {
        const Playlist& c = p;
        Ids ids = {"t04"};
        Playlist r = c.tracksAfterLast(ids);
        CHECK(r.size() == 1);
    }
}
