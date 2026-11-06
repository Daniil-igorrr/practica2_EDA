#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include "C04_io_read_lines.cc"

TEST_CASE("C4: lectura por lineas") {
    const string ruta = "tests/output/C04_entrada.txt";
    escribirFichero(ruta, "uno\ndos\ntres\n");
    CHECK(read_lines(ruta) == vector<string>{"uno", "dos", "tres"});
}

TEST_CASE("C4: lineas vacias y sin salto final") {
    const string ruta = "tests/output/C04_entrada.txt";
    escribirFichero(ruta, "uno\n\ntres");
    CHECK(read_lines(ruta) == vector<string>{"uno", "", "tres"});
}

TEST_CASE("C4: fichero vacio o inexistente") {
    const string ruta = "tests/output/C04_vacio.txt";
    escribirFichero(ruta, "");
    CHECK(read_lines(ruta).empty());
    CHECK(read_lines("tests/output/C04_no_existe.txt").empty());
}
