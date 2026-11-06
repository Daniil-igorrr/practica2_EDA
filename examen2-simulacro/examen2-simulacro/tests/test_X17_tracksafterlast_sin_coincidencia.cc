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

TEST_CASE("X17: tracksAfterLast cuando no hay ninguna pista seleccionada") {
    Playlist p;
    p.add(Track("t01", "Uno", 100));
    p.add(Track("t02", "Dos", 200));
    p.add(Track("t03", "Tres", 300));

    SUBCASE("Vector de ids vacío") {
        Ids ids;
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 0);
        CHECK(r.empty());
    }

    SUBCASE("Ids inexistentes") {
        Ids ids = {"zz", "t04", "nada"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 0);
        CHECK(r.empty());
    }

    SUBCASE("Prefijos, otras mayúsculas, id vacío y con espacios no coinciden") {
        Ids ids = {"t0", "T01", "", "t011", " t01", "t01 "};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 0);
        CHECK(r.empty());
    }

    SUBCASE("Se compara con el id, no con el título") {
        Playlist q;
        q.add(Track("a", "b", 1));
        q.add(Track("b", "a", 2));
        q.add(Track("c", "c", 3));
        Ids ids = {"a"};
        Playlist r = q.tracksAfterLast(ids);
        CHECK(r.size() == 2);              // b y c
        CHECK(contiene(r, "b"));
        CHECK(contiene(r, "c"));
        CHECK_FALSE(contiene(r, "a"));
    }

    SUBCASE("Lista original vacía") {
        Playlist vacia;
        Ids ids = {"t01", "t02"};
        Playlist r = vacia.tracksAfterLast(ids);
        CHECK(r.size() == 0);
        CHECK(r.empty());
        Ids ninguno;
        CHECK(vacia.tracksAfterLast(ninguno).empty());
        CHECK(vacia.size() == 0);
    }

    SUBCASE("El resultado vacío es utilizable") {
        Ids ids = {"zz"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.add(Track("n1", "Nueva", 10)));
        CHECK(r.add(Track("n2", "Nueva", 10)));
        CHECK_FALSE(r.add(Track("n1", "Repetida", 10)));
        CHECK(r.size() == 2);
        CHECK(p.size() == 3);
    }

    SUBCASE("Tras las consultas la lista original queda intacta") {
        Ids ids = {"zz"};
        p.tracksAfterLast(ids);
        CHECK(p.size() == 3);
        CHECK(contiene(p, "t01"));
        CHECK(contiene(p, "t02"));
        CHECK(contiene(p, "t03"));
        CHECK(p.size() == 3);
    }
}
