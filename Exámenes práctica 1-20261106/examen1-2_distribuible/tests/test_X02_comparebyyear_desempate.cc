#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X02: compareByYear desempata por id y devuelve 0 solo si coinciden year e id") {
    Resource a("aaa", 2000, "Uno");
    Resource b("bbb", 2000, "Dos");

    // Mismo anyo: desempata el id
    CHECK(a.compareByYear(b) == -1);
    CHECK(b.compareByYear(a) == 1);

    // Mismo anyo y mismo id: equivalentes, aunque cambie el titulo
    Resource mismoId("aaa", 2000, "Otro titulo");
    CHECK(a.compareByYear(mismoId) == 0);
    CHECK(a.compareByYear(a) == 0);

    // El anyo manda sobre el id
    Resource zzz("zzz", 1999, "Anterior");
    CHECK(zzz.compareByYear(a) == -1);
    CHECK(a.compareByYear(zzz) == 1);

    // El metodo es const y no modifica ninguno de los dos recursos
    const Resource& ca = a;
    const Resource& cb = b;
    CHECK(ca.compareByYear(cb) == -1);
    CHECK(a.getId() == "aaa");
    CHECK(a.getYear() == 2000);
    CHECK(a.getTitle() == "Uno");
    CHECK(b.getId() == "bbb");
}
