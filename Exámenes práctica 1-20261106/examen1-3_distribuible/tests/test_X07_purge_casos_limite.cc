#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X07: purge casos limite") {
    // Catalogo vacio
    Catalog vacio;
    int recursos = -1;
    CHECK(vacio.purge("tmp", recursos) == 0);
    CHECK(recursos == 0);
    CHECK(vacio.size() == 0);

    Catalog c;
    Resource r1("bk01", 2000, "Uno");
    r1.addTag("Tmp1");
    Resource r2("bk02", 2001, "Dos");
    r2.addTag("TMP2");
    c.add(r1);
    c.add(r2);

    // Prefijo vacio: no cambia nada
    recursos = -1;
    CHECK(c.purge("", recursos) == 0);
    CHECK(recursos == 0);
    CHECK(c.size() == 2);
    CHECK(c.findById("bk01").hasTag("tmp1") == true);

    // El prefijo se normaliza a minusculas; aqui la purga vacia el
    // catalogo entero
    recursos = -1;
    CHECK(c.purge("TMP", recursos) == 2);
    CHECK(recursos == 2);
    CHECK(c.size() == 0);
    CHECK(c.findById("bk01").getId() == "");
    CHECK(c.findById("bk02").getId() == "");

    // El catalogo sigue siendo usable despues de vaciarlo
    Resource nuevo("bk03", 2003, "Tres");
    nuevo.addTag("craft");
    CHECK(c.add(nuevo) == true);
    CHECK(c.size() == 1);
}
