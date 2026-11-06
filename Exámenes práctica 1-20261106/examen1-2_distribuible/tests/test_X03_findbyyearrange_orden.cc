#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X03: findByYearRange ordena por year y, a igualdad de year, por id") {
    Catalog c;

    // Se insertan en un orden que no coincide con el resultado esperado y
    // con un empate de anyo (2000: bk09 y bk02) para forzar el desempate.
    Resource r1("bk05", 2010, "Diez");
    Resource r2("bk09", 2000, "Nueve");
    Resource r3("bk02", 2000, "Dos");
    Resource r4("bk07", 1990, "Noventa");
    Resource r5("bk01", 2020, "Fuera de rango");
    c.add(r1);
    c.add(r2);
    c.add(r3);
    c.add(r4);
    c.add(r5);

    std::vector<Resource> res = c.findByYearRange(1990, 2010, "");
    REQUIRE(res.size() == 4);
    CHECK(res[0].getId() == "bk07");   // 1990
    CHECK(res[1].getId() == "bk02");   // 2000, id menor primero
    CHECK(res[2].getId() == "bk09");   // 2000
    CHECK(res[3].getId() == "bk05");   // 2010

    // Los extremos del rango estan incluidos
    std::vector<Resource> ext = c.findByYearRange(2000, 2010, "");
    REQUIRE(ext.size() == 3);
    CHECK(ext[0].getId() == "bk02");
    CHECK(ext[1].getId() == "bk09");
    CHECK(ext[2].getId() == "bk05");
}
