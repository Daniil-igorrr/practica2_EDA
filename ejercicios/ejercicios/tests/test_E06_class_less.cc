#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <algorithm>
#include <vector>
#include "E06_class_less/Person.h"

TEST_CASE("E6: ordena por edad") {
    Person joven("Zoe", 20);
    Person mayor("Ana", 30);
    CHECK(joven < mayor);
    CHECK_FALSE(mayor < joven);
}

TEST_CASE("E6: misma edad, ordena por nombre") {
    Person a("Ana", 20);
    Person z("Zoe", 20);
    CHECK(a < z);
    CHECK_FALSE(z < a);
}

TEST_CASE("E6: iguales") {
    Person a("Ana", 20);
    Person b("Ana", 20);
    CHECK_FALSE(a < b);
    CHECK_FALSE(b < a);
}

TEST_CASE("E6: usable con sort") {
    vector<Person> v = {Person("Luis", 30), Person("Ana", 20), Person("Eva", 30), Person("Bea", 20)};
    sort(v.begin(), v.end());
    REQUIRE(v.size() == 4);
    CHECK(v[0].get_name() == "Ana");
    CHECK(v[1].get_name() == "Bea");
    CHECK(v[2].get_name() == "Eva");
    CHECK(v[3].get_name() == "Luis");
}
