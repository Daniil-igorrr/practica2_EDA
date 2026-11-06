#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "common/test_utils.h"
#include "C05_io_write_lines.cc"

TEST_CASE("C5: escritura de fichero") {
    const string ruta = "tests/output/C05_salida.txt";
    CHECK(write_lines(ruta, {"uno", "dos"}));
    CHECK(leerFichero(ruta) == "uno\ndos\n");
}

TEST_CASE("C5: sustituye el contenido anterior") {
    const string ruta = "tests/output/C05_salida.txt";
    escribirFichero(ruta, "contenido anterior que debe desaparecer\n");
    CHECK(write_lines(ruta, {"nuevo"}));
    CHECK(leerFichero(ruta) == "nuevo\n");
}

TEST_CASE("C5: vector vacio") {
    const string ruta = "tests/output/C05_salida.txt";
    escribirFichero(ruta, "algo\n");
    CHECK(write_lines(ruta, {}));
    CHECK(leerFichero(ruta) == "");
}

TEST_CASE("C5: ruta no valida") {
    CHECK_FALSE(write_lines("tests/output/carpeta_inexistente/x.txt", {"x"}));
}
