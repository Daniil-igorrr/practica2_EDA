#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include "Catalog.h"

TEST_CASE("X03: las lineas de toFileLine se pueden volver a cargar con loadFromFile") {
    Resource r("bk01", 1999, "Clean Code");
    r.addTag("craft");
    r.addTag("software");
    Resource sinTags("bk02", 2020, "Empty Tags");

    escribirFichero("tests/output/tmp_X03_ida.txt",
        r.toFileLine() + "\n" + sinTags.toFileLine() + "\n");

    Catalog c;
    REQUIRE(c.loadFromFile("tests/output/tmp_X03_ida.txt") == true);
    REQUIRE(c.size() == 2);

    Resource cargado = c.findById("bk01");
    CHECK(cargado.getId() == "bk01");
    CHECK(cargado.getYear() == 1999);
    CHECK(cargado.getTitle() == "Clean Code");
    REQUIRE(cargado.getTags().size() == 2);
    CHECK(cargado.getTags()[0] == "craft");
    CHECK(cargado.getTags()[1] == "software");
    CHECK(cargado.toFileLine() == r.toFileLine());

    // El recurso sin etiquetas tambien se recupera igual
    Resource vacio = c.findById("bk02");
    CHECK(vacio.getId() == "bk02");
    CHECK(vacio.getTitle() == "Empty Tags");
    CHECK(vacio.getTags().empty());
    CHECK(vacio.toFileLine() == sinTags.toFileLine());
}
