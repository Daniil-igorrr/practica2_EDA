#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X06: findByYearRange sobre un catalogo cargado de fichero") {
    Catalog c;
    REQUIRE(c.loadFromFile("data/sample_ok.txt") == true);
    REQUIRE(c.size() == 6);

    // Reproduce el ejemplo de EXAMEN.md: bk03 (2015) y bk06 (2020) quedan
    // fuera del rango
    std::vector<Resource> rango = c.findByYearRange(1994, 2011, "");
    REQUIRE(rango.size() == 4);
    CHECK(rango[0].getId() == "bk04");   // 1994
    CHECK(rango[1].getId() == "bk01");   // 1999
    CHECK(rango[2].getId() == "bk02");   // 2008
    CHECK(rango[3].getId() == "bk05");   // 2011

    // Las etiquetas del fichero llegan normalizadas, asi que la busqueda
    // en mayusculas tambien encuentra los recursos
    std::vector<Resource> conTag = c.findByYearRange(1994, 2011, "CRAFT");
    REQUIRE(conTag.size() == 2);
    CHECK(conTag[0].getId() == "bk04");
    CHECK(conTag[1].getId() == "bk01");
    REQUIRE(conTag[0].getTags().size() == 2);
    CHECK(conTag[0].getTags()[0] == "craft");
    CHECK(conTag[0].getTags()[1] == "software");

    CHECK(c.findByYearRange(2011, 1994, "").empty());
    CHECK(c.size() == 6);
}
