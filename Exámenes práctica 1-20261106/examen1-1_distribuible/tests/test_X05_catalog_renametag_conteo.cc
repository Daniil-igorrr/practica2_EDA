#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X05: Catalog::renameTag devuelve los ids modificados ordenados lexicograficamente") {
    Catalog c;

    // Se insertan en un orden que NO coincide con el orden alfabetico de
    // los ids, para forzar que el resultado tenga que ordenarse.
    Resource r3("bk03", 2000, "Tres");
    r3.addTag("craft");
    Resource r1("bk01", 2000, "Uno");
    r1.addTag("craft");
    r1.addTag("software");
    Resource r2("bk02", 2000, "Dos");
    r2.addTag("python");

    c.add(r3);
    c.add(r1);
    c.add(r2);

    // bk03: crea la tag "software" (no la tenia)
    // bk01: funde con "software" (ya la tenia)
    // bk02: no tiene "craft", no se modifica
    std::vector<std::string> ids = c.renameTag("craft", "software", 0);

    REQUIRE(ids.size() == 2);
    CHECK(ids[0] == "bk01");
    CHECK(ids[1] == "bk03");

    Resource r1_found = c.findById("bk01");
    CHECK(r1_found.hasTag("software") == true);
    CHECK(r1_found.getTags().size() == 1);
    
    Resource r3_found = c.findById("bk03");
    CHECK(r3_found.hasTag("software") == true);
    CHECK(r3_found.hasTag("craft") == false);
    
    Resource r2_found = c.findById("bk02");
    CHECK(r2_found.hasTag("python") == true);
}
