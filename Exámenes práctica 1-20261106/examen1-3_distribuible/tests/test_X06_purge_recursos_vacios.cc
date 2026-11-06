#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Catalog.h"

TEST_CASE("X06: purge no elimina los recursos que ya estaban sin etiquetas") {
    Catalog c;
    Resource vacio("bk01", 2000, "Nunca tuvo etiquetas");
    Resource soloTmp("bk02", 2001, "Solo tmp");
    soloTmp.addTag("tmpz");
    Resource otro("bk03", 2002, "Otro");
    otro.addTag("craft");
    c.add(vacio);
    c.add(soloTmp);
    c.add(otro);

    int recursos = -1;
    CHECK(c.purge("tmp", recursos) == 1);
    CHECK(recursos == 1);                          // solo bk02
    CHECK(c.size() == 2);
    CHECK(c.findById("bk01").getId() == "bk01");   // sigue en el catalogo
    CHECK(c.findById("bk02").getId() == "");       // eliminado
    CHECK(c.findById("bk03").getId() == "bk03");

    // Purga repetida: no queda nada que eliminar, pero removedResources
    // debe asignarse igualmente
    recursos = -1;
    CHECK(c.purge("tmp", recursos) == 0);
    CHECK(recursos == 0);
    CHECK(c.size() == 2);

    // Un prefijo que no coincide con ninguna etiqueta tampoco elimina el
    // recurso que esta vacio desde el principio
    recursos = -1;
    CHECK(c.purge("zzz", recursos) == 0);
    CHECK(recursos == 0);
    CHECK(c.size() == 2);
}
