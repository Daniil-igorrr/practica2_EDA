#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X06: Catalog::renameTag filtra por year minimo") {
    Catalog c;
    Resource r1("bk01", 1994, "Antiguo");
    r1.addTag("craft");
    Resource r2("bk02", 2010, "Reciente");
    r2.addTag("craft");
    Resource r3("bk03", 2000, "Intermedio");
    r3.addTag("craft");
    c.add(r1);
    c.add(r2);
    c.add(r3);

    // Solo bk02 (2010) y bk03 (2000) cumplen year >= 2000; bk01 (1994) no
    std::vector<std::string> ids = c.renameTag("craft", "legacy", 2000);
    REQUIRE(ids.size() == 2);
    CHECK(ids[0] == "bk02");
    CHECK(ids[1] == "bk03");

    Resource bk01 = c.findById("bk01");
    Resource bk02 = c.findById("bk02");
    Resource bk03 = c.findById("bk03");
    CHECK(bk01.hasTag("craft") == true);
    CHECK(bk02.hasTag("legacy") == true);
    CHECK(bk03.hasTag("legacy") == true);

    // Un umbral que excluye a todos los recursos restantes con la tag
    // devuelve un vector vacio y no modifica nada
    std::vector<std::string> ninguno = c.renameTag("legacy", "modern", 2020);
    CHECK(ninguno.empty());
    bk02 = c.findById("bk02");
    bk03 = c.findById("bk03");
    CHECK(bk02.hasTag("legacy") == true);
    CHECK(bk03.hasTag("legacy") == true);
}
