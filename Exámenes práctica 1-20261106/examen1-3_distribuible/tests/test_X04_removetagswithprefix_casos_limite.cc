#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X04: removeTagsWithPrefix casos limite") {
    // Elimina todas las etiquetas del recurso
    Resource r("bk01", 2000, "Uno");
    r.addTag("tmpa");
    r.addTag("tmpb");
    r.addTag("tmpc");
    CHECK(r.removeTagsWithPrefix("tmp") == 3);
    CHECK(r.getTags().empty());

    // Repetir la operacion ya no elimina nada
    CHECK(r.removeTagsWithPrefix("tmp") == 0);
    CHECK(r.getTags().empty());

    // Recurso que nunca tuvo etiquetas
    Resource sinTags("bk02", 2001, "Dos");
    CHECK(sinTags.removeTagsWithPrefix("tmp") == 0);
    CHECK(sinTags.getTags().empty());

    // Varias etiquetas consecutivas con el prefijo, rodeadas de otras que
    // no lo tienen: eliminar mientras se recorre el vector no debe
    // saltarse ninguna
    Resource mix("bk03", 2002, "Tres");
    mix.addTag("aaa");
    mix.addTag("tmp1");
    mix.addTag("tmp2");
    mix.addTag("tmp3");
    mix.addTag("zzz");
    CHECK(mix.removeTagsWithPrefix("tmp") == 3);
    std::vector<std::string> tags = mix.getTags();
    REQUIRE(tags.size() == 2);
    CHECK(tags[0] == "aaa");
    CHECK(tags[1] == "zzz");
}
