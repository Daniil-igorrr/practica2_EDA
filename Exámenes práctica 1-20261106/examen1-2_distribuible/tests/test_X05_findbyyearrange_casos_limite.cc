#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X05: findByYearRange casos limite") {
    // Catalogo vacio
    Catalog vacio;
    CHECK(vacio.findByYearRange(1900, 2100, "").empty());
    CHECK(vacio.findByYearRange(1900, 2100, "craft").empty());

    Catalog c;
    Resource r1("bk01", 2000, "Uno");
    r1.addTag("craft");
    Resource r2("bk02", 2005, "Dos");
    c.add(r1);
    c.add(r2);

    // from > to devuelve un vector vacio aunque haya coincidencias
    CHECK(c.findByYearRange(2100, 1900, "").empty());
    CHECK(c.findByYearRange(2005, 2000, "craft").empty());

    // Rango de un solo anyo
    std::vector<Resource> uno = c.findByYearRange(2000, 2000, "");
    REQUIRE(uno.size() == 1);
    CHECK(uno[0].getId() == "bk01");

    // Rango valido que no cubre ningun recurso
    CHECK(c.findByYearRange(2010, 2020, "").empty());

    // El metodo es const y no modifica el catalogo
    const Catalog& cc = c;
    CHECK(cc.findByYearRange(1900, 2100, "").size() == 2);
    CHECK(c.size() == 2);
    CHECK(c.findById("bk01").hasTag("craft") == true);
}
