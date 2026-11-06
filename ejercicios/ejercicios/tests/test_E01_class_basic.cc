#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "E01_class_basic/Person.h"

TEST_CASE("E1: constructor y getters") {
    Person p("Ana", 30);
    CHECK(p.get_name() == "Ana");
    CHECK(p.get_age() == 30);
}

TEST_CASE("E1: objetos independientes") {
    Person a("Ana", 30);
    Person b("Luis", 5);
    CHECK(a.get_name() == "Ana");
    CHECK(a.get_age() == 30);
    CHECK(b.get_name() == "Luis");
    CHECK(b.get_age() == 5);
}

TEST_CASE("E1: getters sobre objeto constante") {
    const Person p("Eva", 41);
    CHECK(p.get_name() == "Eva");
    CHECK(p.get_age() == 41);
}
