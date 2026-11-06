#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

// Ejercita todos los comandos de la aplicacion (LOAD, ADD, DEL, GET,
// FINDTAG, LATEST, comando invalido, EXIT) en una unica sesion, sobre un
// fichero con lineas validas e invalidas.

TEST_CASE("X10: sesion completa con todos los comandos, incluyendo LATEST") {
    escribirFichero("tests/output/tmp_X10_in.txt",
        "LOAD data/sample_mixed.txt\n"
        "ADD bk09 2024 Nuevo_Libro cpp,Extra\n"
        "LATEST 2 0\n"
        "DEL bk03\n"
        "LATEST 3 0\n"
        "GET bk03\n"
        "FINDTAG cpp\n"
        "BOGUS\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X10_in.txt > tests/output/tmp_X10_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X10_out.txt");

    // sample_mixed.txt tiene 3 lineas validas (bk01 1999, bk03 2015 y
    // bk04 2010); el recurso anyadido (2024) encabeza el ranking
    CHECK(mismaSalida(salida,
        "OK 3\n"                                          // LOAD
        "OK\n"                                            // ADD bk09
        "COUNT 2\n"                                       // LATEST 2 0
        "bk09|2024|Nuevo Libro|cpp,extra\n"
        "bk03|2015|Design Patterns|oop,patterns\n"
        "OK\n"                                            // DEL bk03
        "COUNT 3\n"                                       // LATEST 3 0
        "bk09|2024|Nuevo Libro|cpp,extra\n"
        "bk04|2010|Valid Book|tags\n"
        "bk01|1999|Clean Code|craft,software\n"
        "NOTFOUND\n"                                      // GET bk03 tras DEL
        "COUNT 1\n"                                       // FINDTAG cpp
        "bk09 (2024) Nuevo Libro [cpp,extra]\n"
        "INVALIDCMD\n"));                                 // BOGUS

    // EXIT corta la ejecucion: los comandos posteriores no se procesan
    escribirFichero("tests/output/tmp_X10_exit_in.txt",
        "ADD bk10 2000 Otro -\n"
        "EXIT\n"
        "LATEST 5 0\n");

    int rcExit = std::system("./catalog < tests/output/tmp_X10_exit_in.txt > tests/output/tmp_X10_exit_out.txt 2>&1");
    CHECK(rcExit == 0);

    std::string salidaExit = leerFichero("tests/output/tmp_X10_exit_out.txt");
    CHECK(mismaSalida(salidaExit, "OK\n"));
}
