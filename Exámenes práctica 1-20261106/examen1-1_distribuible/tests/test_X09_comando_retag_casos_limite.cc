#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X09: casos limite del comando RETAG") {
    escribirFichero("tests/output/tmp_X9_in.txt",
        "LOAD data/sample_ok.txt\n"
        "RETAG craft CRAFT 0\n"
        "GET bk01\n"
        "RETAG craft c++ 0\n"
        "GET bk01\n"
        "RETAG CRAFT ARTESANIA 1995\n"
        "GET bk01\n"
        "GET bk04\n"
        "RETAG\n"
        "RETAG craft\n"
        "RETAG craft otra\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X9_in.txt > tests/output/tmp_X9_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X9_out.txt");

    // old y new normalizan igual (OK 0, sin cambios), y newTag "c++" es
    // invalido (OK 0, sin cambios); despues, renombrado valido con
    // mayusculas extremo a extremo combinado con el filtro de year (solo
    // bk01 1999 se renombra, bk04 1994 no); por ultimo, tres variantes de
    // RETAG con argumentos insuficientes
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "OK 0\n"
        "bk01 (1999) Clean Code [craft,software]\n"
        "OK 0\n"
        "bk01 (1999) Clean Code [craft,software]\n"
        "OK 1 bk01\n"
        "bk01 (1999) Clean Code [artesania,software]\n"
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"));
}
