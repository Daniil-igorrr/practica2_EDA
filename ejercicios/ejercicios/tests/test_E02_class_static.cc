#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "E02_class_static/Person.h"

TEST_CASE("E2: cuenta los objetos creados") {
    int antes = Person::total_created();
    Person a("Ana", 30);
    CHECK(Person::total_created() == antes + 1);
    Person b("Luis", 5);
    Person c("Eva", 41);
    CHECK(Person::total_created() == antes + 3);
}

TEST_CASE("E2: el contador es compartido por todos los objetos") {
    Person p("Ana", 30);
    int n = p.total_created();
    CHECK(n == Person::total_created());
    Person q("Luis", 5);
    CHECK(p.total_created() == n + 1);
    CHECK(q.total_created() == n + 1);
}

TEST_CASE("E2: los objetos destruidos siguen contando") {
    int antes = Person::total_created();
    {
        Person t("Temporal", 1);
    }
    CHECK(Person::total_created() == antes + 1);
}

TEST_CASE("E2: los objetos siguen funcionando") {
    Person p("Ana", 30);
    CHECK(p.get_name() == "Ana");
    CHECK(p.get_age() == 30);
}
