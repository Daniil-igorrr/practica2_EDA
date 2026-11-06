#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

// Ejercita todos los comandos de la aplicacion (LOAD, ADD, DEL, GET,
// FINDTAG, YEARS, comando invalido, EXIT) en una unica sesion.

TEST_CASE("X10: sesion completa con todos los comandos, incluyendo YEARS") {
    escribirFichero("tests/output/tmp_X10_in.txt",
        "LOAD data/sample_ok.txt\n"
        "ADD bk07 2005 New_Book craft\n"
        "YEARS 2000 2010 craft\n"
        "DEL bk02\n"
        "YEARS 1994 2011 -\n"
        "GET bk02\n"
        "FINDTAG craft\n"
        "BOGUS\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X10_in.txt > tests/output/tmp_X10_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X10_out.txt");

    // El recurso anyadido entra en las consultas; tras DEL bk02 ya no
    // aparece en el rango; FINDTAG sigue ordenando por id, no por anyo
    CHECK(mismaSalida(salida,
        "OK 6\n"                                            // LOAD
        "OK\n"                                              // ADD bk07
        "COUNT 1\n"                                         // YEARS 2000 2010 craft
        "bk07 (2005) New Book [craft]\n"
        "OK\n"                                              // DEL bk02
        "COUNT 4\n"                                         // YEARS 1994 2011 -
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"
        "bk01 (1999) Clean Code [craft,software]\n"
        "bk07 (2005) New Book [craft]\n"
        "bk05 (2011) Structure and Interpretation [cs,lisp,programming]\n"
        "NOTFOUND\n"                                        // GET bk02 tras DEL
        "COUNT 3\n"                                         // FINDTAG craft
        "bk01 (1999) Clean Code [craft,software]\n"
        "bk04 (1994) The Pragmatic Programmer [craft,software]\n"
        "bk07 (2005) New Book [craft]\n"
        "INVALIDCMD\n"));                                   // BOGUS

    // EXIT corta la ejecucion: los comandos posteriores no se procesan
    escribirFichero("tests/output/tmp_X10_exit_in.txt",
        "ADD bk09 2000 Otro -\n"
        "EXIT\n"
        "YEARS 1900 2100 -\n");

    int rcExit = std::system("./catalog < tests/output/tmp_X10_exit_in.txt > tests/output/tmp_X10_exit_out.txt 2>&1");
    CHECK(rcExit == 0);

    std::string salidaExit = leerFichero("tests/output/tmp_X10_exit_out.txt");
    CHECK(mismaSalida(salidaExit, "OK\n"));
}
