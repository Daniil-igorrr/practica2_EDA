#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

// Ejercita todos los comandos de la aplicacion (LOAD, ADD, DEL, GET,
// FINDTAG, RETAG, comando invalido, EXIT) en una unica sesion, verificando
// el formato "OK <n> <id1>,<id2>,..." cuando RETAG modifica varios recursos.

TEST_CASE("X10: sesion completa con todos los comandos, incluyendo RETAG") {
    escribirFichero("tests/output/tmp_X10_in.txt",
        "LOAD data/sample_ok.txt\n"
        "ADD bk07 2022 New_Book craft,extra\n"
        "RETAG craft artesania 1999\n"
        "GET bk07\n"
        "DEL bk02\n"
        "FINDTAG artesania\n"
        "GET bk02\n"
        "BOGUS\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X10_in.txt > tests/output/tmp_X10_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X10_out.txt");

    // year >= 1999 deja fuera a bk04 (1994); bk01 y bk07 (anadido) si entran
    CHECK(mismaSalida(salida,
        "OK 6\n"                                       // LOAD
        "OK\n"                                          // ADD bk07
        "OK 2 bk01,bk07\n"                               // RETAG
        "bk07 (2022) New Book [artesania,extra]\n"       // GET bk07
        "OK\n"                                           // DEL bk02
        "COUNT 2\n"                                      // FINDTAG artesania
        "bk01 (1999) Clean Code [artesania,software]\n"
        "bk07 (2022) New Book [artesania,extra]\n"
        "NOTFOUND\n"                                     // GET bk02 tras DEL
        "INVALIDCMD\n"));                                // BOGUS

    // EXIT corta la ejecucion: los comandos posteriores no se procesan
    escribirFichero("tests/output/tmp_X10_exit_in.txt",
        "ADD bk09 2000 Otro -\n"
        "EXIT\n"
        "GET bk09\n");

    int rcExit = std::system("./catalog < tests/output/tmp_X10_exit_in.txt > tests/output/tmp_X10_exit_out.txt 2>&1");
    CHECK(rcExit == 0);

    std::string salidaExit = leerFichero("tests/output/tmp_X10_exit_out.txt");
    CHECK(mismaSalida(salidaExit, "OK\n")); // el GET tras EXIT no llega a ejecutarse
}
