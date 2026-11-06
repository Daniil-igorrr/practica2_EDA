#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X08: comando PURGE basico") {
    escribirFichero("tests/output/tmp_X8_in.txt",
        "LOAD data/sample_ok.txt\n"
        "ADD bk07 2022 Temporal tempo\n"
        "PURGE temp\n"
        "GET bk07\n"
        "PURGE cs\n"
        "GET bk02\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X8_in.txt > tests/output/tmp_X8_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X8_out.txt");

    // bk07 solo tenia la etiqueta "tempo": al eliminarla se queda sin
    // etiquetas y desaparece del catalogo. bk02 y bk05 pierden "cs" pero
    // conservan otras etiquetas, asi que no se eliminan.
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "OK\n"
        "OK 1 1\n"
        "NOTFOUND\n"
        "OK 2 0\n"
        "bk02 (2008) Introduction to Algorithms [algorithms]\n"));
}
