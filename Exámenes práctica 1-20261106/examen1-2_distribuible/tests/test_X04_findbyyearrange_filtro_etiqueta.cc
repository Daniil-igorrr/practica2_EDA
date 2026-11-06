#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X04: findByYearRange filtra por etiqueta con las reglas de hasTag") {
    Catalog c;
    Resource r1("bk01", 2000, "Uno");
    r1.addTag("craft");
    r1.addTag("software");
    Resource r2("bk02", 2005, "Dos");
    r2.addTag("software");
    Resource r3("bk03", 2010, "Tres");
    r3.addTag("craft");
    c.add(r1);
    c.add(r2);
    c.add(r3);

    std::vector<Resource> craft = c.findByYearRange(1900, 2100, "craft");
    REQUIRE(craft.size() == 2);
    CHECK(craft[0].getId() == "bk01");
    CHECK(craft[1].getId() == "bk03");

    // La etiqueta se normaliza a minusculas
    std::vector<Resource> mayus = c.findByYearRange(1900, 2100, "CRAFT");
    REQUIRE(mayus.size() == 2);
    CHECK(mayus[0].getId() == "bk01");
    CHECK(mayus[1].getId() == "bk03");

    // ...pero no se recortan los espacios, igual que en hasTag
    CHECK(c.findByYearRange(1900, 2100, " craft ").empty());

    // La cadena vacia significa "sin filtro de etiqueta"
    CHECK(c.findByYearRange(1900, 2100, "").size() == 3);

    // Los dos filtros (anyo y etiqueta) se aplican a la vez
    std::vector<Resource> ambos = c.findByYearRange(2001, 2100, "craft");
    REQUIRE(ambos.size() == 1);
    CHECK(ambos[0].getId() == "bk03");

    // Etiqueta que no tiene ningun recurso
    CHECK(c.findByYearRange(1900, 2100, "nope").empty());
}
