#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X06: latest casos limite") {
    // Catalogo vacio
    Catalog vacio;
    CHECK(vacio.latest(3, 0).empty());
    CHECK(vacio.latest(0, 0).empty());
    CHECK(vacio.latest(3, 5).empty());

    Catalog c;
    Resource r1("bk01", 2000, "Uno");
    Resource r2("bk02", 2010, "Dos");
    c.add(r1);
    c.add(r2);

    // k <= 0
    CHECK(c.latest(0, 0).empty());
    CHECK(c.latest(-5, 0).empty());

    // skip justo en el limite y mas alla
    CHECK(c.latest(3, 2).empty());
    CHECK(c.latest(3, 99).empty());

    // k mayor que el total devuelve todos los recursos
    std::vector<Resource> todos = c.latest(10, 0);
    REQUIRE(todos.size() == 2);
    CHECK(todos[0].getId() == "bk02");
    CHECK(todos[1].getId() == "bk01");

    // El metodo es const y no modifica el catalogo
    const Catalog& cc = c;
    CHECK(cc.latest(1, 0).size() == 1);
    CHECK(c.size() == 2);
}
