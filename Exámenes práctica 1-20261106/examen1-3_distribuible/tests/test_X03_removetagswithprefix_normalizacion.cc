#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X03: removeTagsWithPrefix normaliza a minusculas pero no recorta espacios") {
    Resource r("bk01", 2000, "Uno");
    r.addTag("Software");
    r.addTag("SOLID");
    r.addTag("craft");

    // El prefijo se pasa a minusculas, igual que en removeTag
    CHECK(r.removeTagsWithPrefix("SO") == 2);   // software y solid
    std::vector<std::string> tags = r.getTags();
    REQUIRE(tags.size() == 1);
    CHECK(tags[0] == "craft");

    // Los espacios no se recortan: " cr" no coincide con "craft"
    CHECK(r.removeTagsWithPrefix(" cr") == 0);
    CHECK(r.hasTag("craft") == true);

    // Un prefijo de solo espacios tampoco coincide con nada
    CHECK(r.removeTagsWithPrefix("   ") == 0);
    CHECK(r.getTags().size() == 1);

    // Prefijo vacio: devuelve 0 y no modifica el recurso
    CHECK(r.removeTagsWithPrefix("") == 0);
    CHECK(r.getTags().size() == 1);
    CHECK(r.hasTag("craft") == true);
}
