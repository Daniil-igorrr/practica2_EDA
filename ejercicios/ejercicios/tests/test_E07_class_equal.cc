#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <algorithm>
#include <vector>
#include "E07_class_equal/Person.h"

TEST_CASE("E7: personas iguales") {
    Person a("Ana", 30);
    Person b("Ana", 30);
    CHECK(a == b);
    CHECK(a == a);
}

TEST_CASE("E7: personas distintas") {
    Person a("Ana", 30);
    CHECK_FALSE(a == Person("Ana", 31));
    CHECK_FALSE(a == Person("Eva", 30));
    CHECK_FALSE(a == Person("Eva", 31));
}

TEST_CASE("E7: usable con find") {
    vector<Person> v = {Person("Ana", 30), Person("Luis", 5), Person("Eva", 41)};
    auto it = find(v.begin(), v.end(), Person("Luis", 5));
    REQUIRE(it != v.end());
    CHECK(it - v.begin() == 1);
    CHECK(find(v.begin(), v.end(), Person("Luis", 6)) == v.end());
}
