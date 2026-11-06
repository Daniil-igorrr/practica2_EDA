#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X09: el comando YEARS con argumentos invalidos responde INVALIDCMD") {
    escribirFichero("tests/output/tmp_X9_in.txt",
        "YEARS\n"
        "YEARS 1990\n"
        "YEARS 1990 2000\n"
        "YEARS x 2000 -\n"
        "YEARS 1990 y -\n"
        "LOAD data/sample_ok.txt\n"
        "YEARS 2015 2020 -\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X9_in.txt > tests/output/tmp_X9_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X9_out.txt");

    // Faltan argumentos (ninguno, uno, dos) y anyos no enteros; despues,
    // una consulta valida para comprobar que el programa sigue vivo
    CHECK(mismaSalida(salida,
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "OK 6\n"
        "COUNT 2\n"
        "bk03 (2015) Design Patterns [design,oop,patterns]\n"
        "bk06 (2020) Modern C++ [cpp,programming]\n"));
}
