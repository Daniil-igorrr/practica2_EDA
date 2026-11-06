#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X02: toFileLine con una sola etiqueta, sin etiquetas y por defecto") {
    Resource una("bk02", 2020, "Modern C++");
    una.addTag("cpp");
    CHECK(una.toFileLine() == "bk02|2020|Modern C++|cpp");

    // Sin etiquetas el ultimo campo queda vacio: la linea termina en '|'
    Resource sinTags("bk03", 2020, "Empty Tags");
    CHECK(sinTags.toFileLine() == "bk03|2020|Empty Tags|");

    // Recurso construido con el constructor por defecto
    Resource defecto;
    CHECK(defecto.toFileLine() == "|0||");

    // El metodo es const y no modifica el recurso
    const Resource& c = una;
    CHECK(c.toFileLine() == "bk02|2020|Modern C++|cpp");
    CHECK(una.getTags().size() == 1);
    CHECK(una.getTitle() == "Modern C++");
}
