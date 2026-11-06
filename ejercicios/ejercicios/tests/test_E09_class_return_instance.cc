#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "E09_class_return_instance/AddressBook.h"

TEST_CASE("E9: devuelve la persona de mas edad") {
    AddressBook ag;
    ag.add(Person("Ana", 20));
    ag.add(Person("Eva", 45));
    ag.add(Person("Luis", 30));
    Person m = ag.oldest();
    CHECK(m.get_name() == "Eva");
    CHECK(m.get_age() == 45);
}

TEST_CASE("E9: en un empate, la primera") {
    AddressBook ag;
    ag.add(Person("Ana", 40));
    ag.add(Person("Eva", 40));
    CHECK(ag.oldest().get_name() == "Ana");
}

TEST_CASE("E9: un solo elemento y agenda vacia") {
    AddressBook ag;
    CHECK(ag.oldest().get_name() == "");
    CHECK(ag.oldest().get_age() == 0);
    ag.add(Person("Bea", 7));
    CHECK(ag.oldest().get_name() == "Bea");
}

TEST_CASE("E9: la instancia devuelta es una copia") {
    AddressBook ag;
    ag.add(Person("Ana", 20));
    Person m = ag.oldest();
    ag.add(Person("Eva", 45));
    CHECK(m.get_name() == "Ana");
    CHECK(ag.oldest().get_name() == "Eva");
}
