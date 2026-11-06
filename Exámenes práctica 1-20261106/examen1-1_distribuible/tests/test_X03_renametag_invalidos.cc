#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X03: casos invalidos de renameTag") {
    Resource r("bk01", 1999, "Clean Code");
    r.addTag("craft");

    // addTag tambien debe rechazar caracteres no permitidos directamente
    CHECK(r.addTag("c++") == false);
    CHECK(r.hasTag("c++") == false);

    // oldTag no existe
    CHECK(r.renameTag("nope", "algo") == false);
    // newTag invalida (caracteres no permitidos)
    CHECK(r.renameTag("craft", "c++") == false);
    CHECK(r.hasTag("craft") == true);
    // newTag vacia tras recorte
    CHECK(r.renameTag("craft", "   ") == false);
    CHECK(r.hasTag("craft") == true);
    // old y new normalizan igual
    CHECK(r.renameTag("craft", "  CRAFT ") == false);
    CHECK(r.getTags().size() == 1);
}
