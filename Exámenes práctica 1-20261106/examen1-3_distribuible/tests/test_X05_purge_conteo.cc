#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X05: purge devuelve las etiquetas eliminadas y cuenta los recursos") {
    Catalog c;
    Resource r1("bk01", 2000, "Uno");
    r1.addTag("tmp1");
    r1.addTag("craft");
    Resource r2("bk02", 2001, "Dos");
    r2.addTag("tmpx");           // se quedara sin etiquetas
    Resource r3("bk03", 2002, "Tres");
    r3.addTag("craft");
    c.add(r1);
    c.add(r2);
    c.add(r3);

    int recursos = -1;
    int etiquetas = c.purge("tmp", recursos);

    CHECK(etiquetas == 2);       // tmp1 y tmpx
    CHECK(recursos == 1);        // solo bk02 se queda sin etiquetas
    CHECK(c.size() == 2);

    // bk02 ha desaparecido del catalogo
    CHECK(c.findById("bk02").getId() == "");

    // bk01 pierde tmp1 pero conserva craft
    Resource bk01 = c.findById("bk01");
    CHECK(bk01.getId() == "bk01");
    CHECK(bk01.hasTag("tmp1") == false);
    CHECK(bk01.hasTag("craft") == true);
    REQUIRE(bk01.getTags().size() == 1);
    CHECK(bk01.getTags()[0] == "craft");

    // bk03 no tenia ninguna etiqueta con ese prefijo
    CHECK(c.findById("bk03").hasTag("craft") == true);
}
