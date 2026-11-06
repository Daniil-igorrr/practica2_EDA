#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X01: removeTagsWithPrefix elimina todas las etiquetas con ese prefijo") {
    Resource r("bk01", 2000, "Uno");
    r.addTag("tmp1");
    r.addTag("tmpviejo");
    r.addTag("craft");
    r.addTag("software");
    REQUIRE(r.getTags().size() == 4);

    CHECK(r.removeTagsWithPrefix("tmp") == 2);

    // Las etiquetas que quedan siguen en orden lexicografico
    std::vector<std::string> tags = r.getTags();
    REQUIRE(tags.size() == 2);
    CHECK(tags[0] == "craft");
    CHECK(tags[1] == "software");
    CHECK(r.hasTag("tmp1") == false);
    CHECK(r.hasTag("tmpviejo") == false);

    // El resto del recurso no se toca
    CHECK(r.getId() == "bk01");
    CHECK(r.getYear() == 2000);
    CHECK(r.getTitle() == "Uno");
}
