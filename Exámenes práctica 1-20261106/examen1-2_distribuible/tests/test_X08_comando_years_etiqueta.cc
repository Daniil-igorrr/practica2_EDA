#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X08: comando YEARS con filtro de etiqueta") {
    escribirFichero("tests/output/tmp_X8_in.txt",
        "LOAD data/sample_ok.txt\n"
        "YEARS 1994 2011 CRAFT\n"
        "YEARS 1900 2100 programming\n"
        "YEARS 1900 2100 nope\n"
        "YEARS 2015 2015 -\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X8_in.txt > tests/output/tmp_X8_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X8_out.txt");

    // La etiqueta se busca en minusculas; el resultado sigue ordenado por
    // anyo ascendente; una etiqueta inexistente da COUNT 0; el ultimo
    // caso es un rango de un solo anyo
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "COUNT 2\n"
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"
        "bk01 (1999) Clean Code [craft,software]\n"
        "COUNT 2\n"
        "bk05 (2011) Structure and Interpretation [cs,lisp,programming]\n"
        "bk06 (2020) Modern C++ [cpp,programming]\n"
        "COUNT 0\n"
        "COUNT 1\n"
        "bk03 (2015) Design Patterns [design,oop,patterns]\n"));
}
