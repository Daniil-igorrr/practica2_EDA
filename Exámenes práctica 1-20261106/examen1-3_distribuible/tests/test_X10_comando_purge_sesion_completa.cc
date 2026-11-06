#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

// Ejercita todos los comandos de la aplicacion (LOAD, ADD, DEL, GET,
// FINDTAG, PURGE, comando invalido, EXIT) en una unica sesion, sobre un
// fichero con lineas validas e invalidas.

TEST_CASE("X10: sesion completa con todos los comandos, incluyendo PURGE") {
    escribirFichero("tests/output/tmp_X10_in.txt",
        "LOAD data/sample_mixed.txt\n"
        "ADD bk09 2024 Solo_Temp tmp1,tmp2\n"
        "GET bk09\n"
        "PURGE tmp\n"
        "GET bk09\n"
        "PURGE tag\n"
        "GET bk04\n"
        "DEL bk01\n"
        "FINDTAG patterns\n"
        "BOGUS\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X10_in.txt > tests/output/tmp_X10_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X10_out.txt");

    // sample_mixed.txt tiene 3 lineas validas (bk01, bk03 y bk04).
    // bk09 y bk04 se quedan sin etiquetas tras su purga y desaparecen.
    CHECK(mismaSalida(salida,
        "OK 3\n"                                      // LOAD
        "OK\n"                                        // ADD bk09
        "bk09 (2024) Solo Temp [tmp1,tmp2]\n"         // GET bk09
        "OK 2 1\n"                                    // PURGE tmp
        "NOTFOUND\n"                                  // GET bk09
        "OK 1 1\n"                                    // PURGE tag -> bk04
        "NOTFOUND\n"                                  // GET bk04
        "OK\n"                                        // DEL bk01
        "COUNT 1\n"                                   // FINDTAG patterns
        "bk03 (2015) Design Patterns [oop,patterns]\n"
        "INVALIDCMD\n"));                             // BOGUS

    // EXIT corta la ejecucion: los comandos posteriores no se procesan
    escribirFichero("tests/output/tmp_X10_exit_in.txt",
        "ADD bk10 2000 Otro tmpx\n"
        "EXIT\n"
        "PURGE tmp\n");

    int rcExit = std::system("./catalog < tests/output/tmp_X10_exit_in.txt > tests/output/tmp_X10_exit_out.txt 2>&1");
    CHECK(rcExit == 0);

    std::string salidaExit = leerFichero("tests/output/tmp_X10_exit_out.txt");
    CHECK(mismaSalida(salidaExit, "OK\n"));
}
