#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X09: casos limite del comando PURGE") {
    escribirFichero("tests/output/tmp_X9_in.txt",
        "LOAD data/sample_ok.txt\n"
        "PURGE zzz\n"
        "PURGE CRAFT\n"
        "FINDTAG craft\n"
        "PURGE craft\n"
        "GET bk01\n"
        "PURGE\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X9_in.txt > tests/output/tmp_X9_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X9_out.txt");

    // Un prefijo sin coincidencias da OK 0 0; el prefijo en mayusculas si
    // encuentra las etiquetas (bk01 y bk04), que conservan "software" y
    // por tanto no se eliminan; repetir la purga ya no cambia nada; sin
    // argumento, INVALIDCMD
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "OK 0 0\n"
        "OK 2 0\n"
        "COUNT 0\n"
        "OK 0 0\n"
        "bk01 (1999) Clean Code [software]\n"
        "INVALIDCMD\n"));
}
