#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X04: latest ordena por year descendente y desempata por id ascendente") {
    Catalog c;

    // Se insertan desordenados y con un empate de anyo (2000: bk09 y bk02)
    Resource r1("bk05", 2010, "Diez");
    Resource r2("bk09", 2000, "Nueve");
    Resource r3("bk02", 2000, "Dos");
    Resource r4("bk07", 1990, "Noventa");
    c.add(r1);
    c.add(r2);
    c.add(r3);
    c.add(r4);

    std::vector<Resource> todos = c.latest(4, 0);
    REQUIRE(todos.size() == 4);
    CHECK(todos[0].getId() == "bk05");   // 2010
    CHECK(todos[1].getId() == "bk02");   // 2000, id menor primero
    CHECK(todos[2].getId() == "bk09");   // 2000
    CHECK(todos[3].getId() == "bk07");   // 1990

    // Los k primeros del ranking
    std::vector<Resource> dos = c.latest(2, 0);
    REQUIRE(dos.size() == 2);
    CHECK(dos[0].getId() == "bk05");
    CHECK(dos[1].getId() == "bk02");
}
