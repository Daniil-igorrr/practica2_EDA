#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X09: el comando LATEST con argumentos invalidos responde INVALIDCMD") {
    escribirFichero("tests/output/tmp_X9_in.txt",
        "LATEST\n"
        "LATEST 3\n"
        "LATEST x 0\n"
        "LATEST 3 y\n"
        "LOAD data/sample_ok.txt\n"
        "LATEST 1 0\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X9_in.txt > tests/output/tmp_X9_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X9_out.txt");

    // Sin argumentos, con uno solo, y con k o skip no enteros; despues una
    // consulta valida para comprobar que el programa sigue vivo
    CHECK(mismaSalida(salida,
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "INVALIDCMD\n"
        "OK 6\n"
        "COUNT 1\n"
        "bk06|2020|Modern C++|cpp,programming\n"));
}
