#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "E10_class_return_subset/AddressBook.h"

TEST_CASE("E10: devuelve las personas mayores que la edad") {
    AddressBook ag;
    ag.add(Person("Ana", 20));
    ag.add(Person("Eva", 45));
    ag.add(Person("Luis", 30));
    vector<Person> r = ag.older_than(25);
    REQUIRE(r.size() == 2);
    CHECK(r[0].get_name() == "Eva");
    CHECK(r[0].get_age() == 45);
    CHECK(r[1].get_name() == "Luis");
}

TEST_CASE("E10: la edad exacta no entra") {
    AddressBook ag;
    ag.add(Person("Ana", 20));
    ag.add(Person("Eva", 45));
    CHECK(ag.older_than(45).empty());
    CHECK(ag.older_than(20).size() == 1);
}

TEST_CASE("E10: todas, ninguna y agenda vacia") {
    AddressBook ag;
    CHECK(ag.older_than(0).empty());
    ag.add(Person("Ana", 20));
    ag.add(Person("Eva", 45));
    CHECK(ag.older_than(0).size() == 2);
    CHECK(ag.older_than(100).empty());
}

TEST_CASE("E10: no modifica la agenda") {
    AddressBook ag;
    ag.add(Person("Ana", 20));
    ag.add(Person("Eva", 45));
    ag.older_than(30);
    CHECK(ag.older_than(0).size() == 2);
}
