#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X01: compareByYear ordena por year ascendente") {
    Resource antiguo("bk04", 1994, "Antiguo");
    Resource reciente("bk01", 2020, "Reciente");

    CHECK(antiguo.compareByYear(reciente) == -1);
    CHECK(reciente.compareByYear(antiguo) == 1);

    // El resultado debe ser exactamente -1 o 1, no la diferencia de anyos
    Resource lejano("bk02", 1900, "Lejano");
    CHECK(lejano.compareByYear(reciente) == -1);
    CHECK(reciente.compareByYear(lejano) == 1);

    // Tambien con anyos negativos
    Resource ac("bk03", -50, "Antes de nuestra era");
    CHECK(ac.compareByYear(lejano) == -1);
    CHECK(lejano.compareByYear(ac) == 1);
}
