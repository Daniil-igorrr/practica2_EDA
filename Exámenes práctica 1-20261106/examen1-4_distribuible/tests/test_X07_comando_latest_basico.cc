#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include <cstdlib>

TEST_CASE("X07: comando LATEST basico") {
    escribirFichero("tests/output/tmp_X7_in.txt",
        "LOAD data/sample_ok.txt\n"
        "LATEST 2 0\n"
        "LATEST 2 1\n"
        "EXIT\n");

    int rc = std::system("./catalog < tests/output/tmp_X7_in.txt > tests/output/tmp_X7_out.txt 2>&1");
    CHECK(rc == 0);

    std::string salida = leerFichero("tests/output/tmp_X7_out.txt");

    // Las lineas van en formato de fichero (toFileLine), no en el de
    // operator<<
    CHECK(mismaSalida(salida,
        "OK 6\n"
        "COUNT 2\n"
        "bk06|2020|Modern C++|cpp,programming\n"
        "bk03|2015|Design Patterns|design,oop,patterns\n"
        "COUNT 2\n"
        "bk03|2015|Design Patterns|design,oop,patterns\n"
        "bk05|2011|Structure and Interpretation|cs,lisp,programming\n"));
}
