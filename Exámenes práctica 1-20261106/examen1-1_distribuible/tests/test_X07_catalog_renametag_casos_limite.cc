#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include "Catalog.h"

TEST_CASE("X07: Catalog::renameTag casos limite y carga desde fichero") {
    // Catalogo vacio
    Catalog vacio;
    CHECK(vacio.renameTag("craft", "artesania", 0).empty());

    // Catalogo no vacio sin ninguna coincidencia
    Catalog c;
    Resource r1("bk01", 1999, "Uno");
    r1.addTag("software");
    c.add(r1);
    CHECK(c.renameTag("craft", "artesania", 0).empty());
    const Resource& bk01c = c.findById("bk01");
    CHECK(bk01c.hasTag("software") == true);

    // Integracion con loadFromFile, reproduciendo el ejemplo de EXAMEN.md:
    // bk01 (1999) y bk04 (1994) tienen "craft"; con minYear=1995 solo bk01
    // se renombra.
    Catalog real;
    REQUIRE(real.loadFromFile("data/sample_ok.txt") == true);
    std::vector<std::string> ids = real.renameTag("craft", "artesania", 1995);
    REQUIRE(ids.size() == 1);
    CHECK(ids[0] == "bk01");
    const Resource& bk01 = real.findById("bk01");
    const Resource& bk04 = real.findById("bk04");
    CHECK(bk01.hasTag("artesania") == true);
    CHECK(bk04.hasTag("craft") == true);
    CHECK(bk04.hasTag("artesania") == false);

    // loadFromFile: si el id se repite en el fichero, solo se guarda el primero
    escribirFichero("tests/output/tmp_X07_duplicados.txt",
        "bk01|1999|Primera Version|craft\n"
        "bk01|2020|Segunda Version|otro\n");
    Catalog dup;
    CHECK(dup.loadFromFile("tests/output/tmp_X07_duplicados.txt") == true);
    CHECK(dup.size() == 1);
    const Resource& primero = dup.findById("bk01");
    CHECK(primero.getTitle() == "Primera Version");
    CHECK(primero.getYear() == 1999);
}
