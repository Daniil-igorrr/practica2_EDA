#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <string>
#include <vector>
#include "Playlist.h"

// Requiere: Track, Playlist (constructor, destructor, constructor de copia,
// add, size, empty) y tracksAfterLast.
// No usa: shorterThan. El orden del resultado no se comprueba.
// Con valgrind comprueba que el resultado tiene sus propios nodos (copia
// profunda) y que no hay fugas ni dobles liberaciones.

// Dice si la lista contiene el id usando solo add: si add devuelve false, el
// id ya estaba. Ojo: si el id NO estaba, add lo añade a la lista.
static bool contiene(Playlist& p, const std::string& id) {
    return !p.add(Track(id, "x", 1));
}

typedef std::vector<std::string> Ids;

TEST_CASE("X18: tracksAfterLast devuelve una copia independiente (y con listas grandes)") {
    SUBCASE("Añadir al resultado no afecta al original, ni al revés") {
        Playlist p;
        p.add(Track("t01", "Uno", 100));
        p.add(Track("t02", "Dos", 200));
        p.add(Track("t03", "Tres", 300));
        Ids ids = {"t01"};
        Playlist r = p.tracksAfterLast(ids);
        CHECK(r.size() == 2);
        CHECK(r.add(Track("t01", "Uno", 100)));   // en el original sí estaba
        CHECK(r.add(Track("t04", "Cuatro", 400)));
        CHECK(r.size() == 4);
        CHECK(p.size() == 3);
        CHECK(p.add(Track("t04", "Otra", 1)));    // el original no tenía t04
        CHECK(p.add(Track("t05", "Cinco", 500)));
        CHECK(r.size() == 4);
        CHECK(r.add(Track("t05", "Cinco", 500)));
    }

    SUBCASE("El resultado sobrevive a la destrucción del original") {
        Playlist* q = new Playlist();
        q->add(Track("a", "A", 1));
        q->add(Track("b", "B", 2));
        q->add(Track("c", "C", 3));
        Ids ids = {"a"};
        Playlist r = q->tracksAfterLast(ids);
        delete q;
        CHECK(r.size() == 2);
        CHECK(contiene(r, "b"));
        CHECK(contiene(r, "c"));
        CHECK_FALSE(contiene(r, "a"));
    }

    SUBCASE("El original sobrevive a la destrucción del resultado") {
        Playlist p;
        p.add(Track("a", "A", 1));
        p.add(Track("b", "B", 2));
        p.add(Track("c", "C", 3));
        {
            Ids ids = {"a"};
            Playlist r = p.tracksAfterLast(ids);
            CHECK(r.size() == 2);
        }
        CHECK(p.size() == 3);
        CHECK(contiene(p, "a"));
        CHECK(contiene(p, "b"));
        CHECK(contiene(p, "c"));
    }

    SUBCASE("Se puede encadenar sobre el resultado y asignar a otra lista") {
        Playlist p;
        for (int i = 1; i <= 6; i++) {
            p.add(Track("t" + std::to_string(i), "Pista", i));
        }
        Ids ids = {"t2"};
        Playlist r = p.tracksAfterLast(ids);          // t3..t6
        CHECK(r.size() == 4);
        Ids ids2 = {"t4"};
        Playlist s = r.tracksAfterLast(ids2);         // t5, t6
        CHECK(s.size() == 2);
        CHECK(r.size() == 4);
        Playlist x;
        x.add(Track("x1", "X", 1));
        x = s;
        CHECK(x.size() == 2);
        CHECK(contiene(x, "t5"));
        CHECK_FALSE(contiene(x, "x1"));
    }

    SUBCASE("Lista de 1000 pistas") {
        const int N = 1000;
        Playlist p;
        Ids todos;
        for (int i = 0; i < N; i++) {
            std::string id = "t" + std::to_string(i);
            REQUIRE(p.add(Track(id, "Pista", i)));
            todos.push_back(id);
        }

        Ids cerca = {"t10", "t990"};
        Playlist r1 = p.tracksAfterLast(cerca);
        CHECK(r1.size() == 9);                        // t991..t999
        CHECK(contiene(r1, "t991"));
        CHECK(contiene(r1, "t999"));
        CHECK_FALSE(contiene(r1, "t990"));

        Ids primera = {"t0"};
        CHECK(p.tracksAfterLast(primera).size() == N - 1);

        Ids ultima = {"t999"};
        CHECK(p.tracksAfterLast(ultima).empty());

        Ids todosIds = todos;
        CHECK(p.tracksAfterLast(todosIds).empty());

        Ids mitad(todos.begin(), todos.begin() + N / 2);   // t0..t499
        Playlist r2 = p.tracksAfterLast(mitad);
        CHECK(r2.size() == N / 2);                          // t500..t999
        CHECK(p.size() == N);
    }
}
