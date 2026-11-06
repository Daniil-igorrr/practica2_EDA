#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X08: paginacion y casos vacios del comando LATEST") {
    escribirFichero("tests/output/tmp_X8_in.txt",
        "LOAD data/sample_ok.txt\n"
        "LATEST 5 4\n"
        "LATEST 3 10\n"
        "LATEST 0 0\n"
        "LATEST 10 0\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X8_in.txt > tests/output/tmp_X8_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X8_out.txt");

    // Se piden 5 saltando 4, pero solo quedan 2; con skip mayor que el
    // total o k = 0 la respuesta es COUNT 0; con k mayor que el total se
    // devuelve el catalogo completo
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "COUNT 2\n"
        "bk01|1999|Clean Code|craft,software\n"
        "bk04|1994|The Pragmatic Programmer|craft,software\n"
        "COUNT 0\n"
        "COUNT 0\n"
        "COUNT 6\n"
        "bk06|2020|Modern C++|cpp,programming\n"
        "bk03|2015|Design Patterns|design,oop,patterns\n"
        "bk05|2011|Structure and Interpretation|cs,lisp,programming\n"
        "bk02|2008|Introduction to Algorithms|algorithms,cs\n"
        "bk01|1999|Clean Code|craft,software\n"
        "bk04|1994|The Pragmatic Programmer|craft,software\n"));
}
