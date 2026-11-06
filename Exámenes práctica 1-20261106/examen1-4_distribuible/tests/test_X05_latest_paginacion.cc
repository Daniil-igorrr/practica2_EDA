#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"
#include <string>

TEST_CASE("X05: latest salta los skip primeros del ranking") {
    Catalog c;
    // bk01 (2001) ... bk05 (2005): el ranking es bk05, bk04, bk03, bk02, bk01
    for (int i = 1; i <= 5; ++i) {
        Resource r("bk0" + std::to_string(i), 2000 + i, "T");
        c.add(r);
    }

    std::vector<Resource> p1 = c.latest(2, 0);
    REQUIRE(p1.size() == 2);
    CHECK(p1[0].getId() == "bk05");
    CHECK(p1[1].getId() == "bk04");

    std::vector<Resource> p2 = c.latest(2, 2);
    REQUIRE(p2.size() == 2);
    CHECK(p2[0].getId() == "bk03");
    CHECK(p2[1].getId() == "bk02");

    // Ultima pagina incompleta: quedan menos de k
    std::vector<Resource> p3 = c.latest(2, 4);
    REQUIRE(p3.size() == 1);
    CHECK(p3[0].getId() == "bk01");

    // skip negativo se trata como 0
    std::vector<Resource> neg = c.latest(1, -3);
    REQUIRE(neg.size() == 1);
    CHECK(neg[0].getId() == "bk05");

    // El catalogo no se modifica
    CHECK(c.size() == 5);
}
