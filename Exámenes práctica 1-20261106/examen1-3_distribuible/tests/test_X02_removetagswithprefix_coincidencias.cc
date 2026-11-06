#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X02: que cuenta como coincidencia de prefijo") {
    Resource r("bk01", 2000, "Uno");
    r.addTag("cpp");
    r.addTag("cpp11");
    r.addTag("java");

    // Un prefijo que no coincide con nada no elimina ni cuenta
    CHECK(r.removeTagsWithPrefix("zzz") == 0);
    CHECK(r.getTags().size() == 3);

    // Un prefijo mas largo que la etiqueta no coincide
    CHECK(r.removeTagsWithPrefix("javaxxx") == 0);
    CHECK(r.hasTag("java") == true);

    // Una etiqueta igual al prefijo tambien empieza por el: se eliminan
    // "cpp" y "cpp11"
    CHECK(r.removeTagsWithPrefix("cpp") == 2);
    std::vector<std::string> tags = r.getTags();
    REQUIRE(tags.size() == 1);
    CHECK(tags[0] == "java");

    // Prefijo que coincide exactamente con la unica etiqueta que queda
    CHECK(r.removeTagsWithPrefix("java") == 1);
    CHECK(r.getTags().empty());
}
