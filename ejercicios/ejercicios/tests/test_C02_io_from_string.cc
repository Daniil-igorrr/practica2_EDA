#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "C02_io_from_string.cc"

TEST_CASE("C2: string a datos primitivos") {
    string nombre;
    int edad = 0;
    double altura = 0;

    REQUIRE(string_to_person("Ana 30 1.75", nombre, edad, altura));
    CHECK(nombre == "Ana");
    CHECK(edad == 30);
    CHECK(altura == doctest::Approx(1.75));
}

TEST_CASE("C2: espacios extra") {
    string nombre;
    int edad = 0;
    double altura = 0;

    REQUIRE(string_to_person("  Luis   5   1.2 ", nombre, edad, altura));
    CHECK(nombre == "Luis");
    CHECK(edad == 5);
    CHECK(altura == doctest::Approx(1.2));
}

TEST_CASE("C2: datos invalidos") {
    string nombre;
    int edad = 0;
    double altura = 0;

    CHECK_FALSE(string_to_person("Ana treinta 1.75", nombre, edad, altura));
    CHECK_FALSE(string_to_person("Ana 30", nombre, edad, altura));
    CHECK_FALSE(string_to_person("", nombre, edad, altura));
}
