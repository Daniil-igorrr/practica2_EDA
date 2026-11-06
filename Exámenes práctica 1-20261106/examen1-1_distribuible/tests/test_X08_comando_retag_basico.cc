#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X08: comando RETAG basico con filtro por year") {
    escribirFichero("tests/output/tmp_X8_in.txt",
        "LOAD data/sample_ok.txt\n"
        "RETAG craft artesania 1995\n"
        "GET bk01\n"
        "GET bk04\n"
        "FINDTAG craft\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X8_in.txt > tests/output/tmp_X8_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X8_out.txt");

    // Solo bk01 (1999) cumple year >= 1995; bk04 (1994) no se renombra
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "OK 1 bk01\n"
        "bk01 (1999) Clean Code [artesania,software]\n"
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"
        "COUNT 1\n"
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"));
}
