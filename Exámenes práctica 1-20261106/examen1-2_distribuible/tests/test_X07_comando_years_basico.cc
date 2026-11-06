#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X07: comando YEARS sin filtro de etiqueta") {
    escribirFichero("tests/output/tmp_X7_in.txt",
        "LOAD data/sample_ok.txt\n"
        "YEARS 1994 2011 -\n"
        "YEARS 2011 1994 -\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X7_in.txt > tests/output/tmp_X7_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X7_out.txt");

    // El guion significa "sin filtro de etiqueta"; el rango invertido no
    // devuelve nada
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "COUNT 4\n"
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"
        "bk01 (1999) Clean Code [craft,software]\n"
        "bk02 (2008) Introduction to Algorithms [algorithms,cs]\n"
        "bk05 (2011) Structure and Interpretation [cs,lisp,programming]\n"
        "COUNT 0\n"));
}
