#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X04: normalizacion asimetrica de oldTag, digitos en newTag, orden e inmutabilidad") {
    // addTag debe detectar duplicados aunque la variante combine espacios
    // y mayusculas a la vez (ambas normalizaciones a la vez)
    Resource rdup("bk00", 1999, "Dup");
    rdup.addTag("craft");
    CHECK(rdup.addTag("  CRAFT  ") == false);
    CHECK(rdup.getTags().size() == 1);

    // oldTag se pasa a minusculas (igual que removeTag), si encuentra
    Resource r1("bk01", 1999, "Clean Code");
    r1.addTag("craft");
    CHECK(r1.renameTag("CRAFT", "artesania") == true);
    CHECK(r1.hasTag("artesania") == true);
    CHECK(r1.hasTag("craft") == false);

    // oldTag NO se recorta: " craft " en minusculas sigue teniendo espacios
    // y no coincide con la tag almacenada "craft"
    Resource r2("bk02", 1999, "Otro");
    r2.addTag("craft");
    CHECK(r2.renameTag(" craft ", "otra") == false);
    CHECK(r2.hasTag("craft") == true);
    CHECK(r2.getTags().size() == 1);

    // newTag admite digitos
    Resource r3("bk03", 1999, "Cpp");
    r3.addTag("cpp");
    CHECK(r3.renameTag("cpp", "cpp11") == true);
    CHECK(r3.hasTag("cpp11") == true);

    // recurso sin ninguna etiqueta
    Resource r4("bk04", 1999, "Vacio");
    CHECK(r4.renameTag("craft", "artesania") == false);
    CHECK(r4.getTags().empty());

    // Orden lexicografico al insertar en distintas posiciones
    Resource r5("bk05", 1999, "Orden");
    r5.addTag("alpha");
    r5.addTag("craft");
    r5.addTag("zeta");

    // insercion en medio: alpha, craft, zeta -> alpha, beta, zeta
    CHECK(r5.renameTag("craft", "beta") == true);
    std::vector<std::string> tags = r5.getTags();
    REQUIRE(tags.size() == 3);
    CHECK(tags[0] == "alpha");
    CHECK(tags[1] == "beta");
    CHECK(tags[2] == "zeta");

    // insercion al principio: alpha, beta, zeta -> aaa, alpha, zeta
    CHECK(r5.renameTag("beta", "aaa") == true);
    tags = r5.getTags();
    REQUIRE(tags.size() == 3);
    CHECK(tags[0] == "aaa");
    CHECK(tags[1] == "alpha");
    CHECK(tags[2] == "zeta");

    // insercion al final: aaa, alpha, zeta -> aaa, alpha, zzz
    CHECK(r5.renameTag("zeta", "zzz") == true);
    tags = r5.getTags();
    REQUIRE(tags.size() == 3);
    CHECK(tags[0] == "aaa");
    CHECK(tags[1] == "alpha");
    CHECK(tags[2] == "zzz");

    // Las llamadas que fallan no modifican el vector de tags
    const std::vector<std::string> original = r5.getTags();
    CHECK(r5.renameTag("nope", "algo") == false);
    CHECK(r5.getTags() == original);
    CHECK(r5.renameTag("aaa", "a++") == false);
    CHECK(r5.getTags() == original);
    CHECK(r5.renameTag("alpha", "  ALPHA ") == false);
    CHECK(r5.getTags() == original);
}
