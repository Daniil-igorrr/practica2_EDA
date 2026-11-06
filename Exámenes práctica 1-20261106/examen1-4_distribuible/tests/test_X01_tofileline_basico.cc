#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X01: toFileLine usa el formato de fichero de la practica") {
    Resource r("bk01", 1999, "Clean Code");
    r.addTag("Software");
    r.addTag("CRAFT");

    // Las etiquetas salen normalizadas y ordenadas, separadas por comas
    // sin espacios
    CHECK(r.toFileLine() == "bk01|1999|Clean Code|craft,software");

    // No anyade salto de linea al final
    std::string linea = r.toFileLine();
    REQUIRE(linea.empty() == false);
    CHECK(linea[linea.size() - 1] != '\n');

    // Tres etiquetas
    Resource tres("bk03", 2015, "Design Patterns");
    tres.addTag("patterns");
    tres.addTag("OOP");
    tres.addTag("design");
    CHECK(tres.toFileLine() == "bk03|2015|Design Patterns|design,oop,patterns");
}
