#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <sstream>
#include "E08_class_output/Person.h"

TEST_CASE("E8: escribe nombre y edad") {
    Person p("Ana", 30);
    ostringstream oss;
    oss << p;
    CHECK(oss.str() == "Ana (30)");
}

TEST_CASE("E8: se puede encadenar") {
    Person a("Luis", 5);
    Person b("Eva", 41);
    ostringstream oss;
    oss << a << " y " << b;
    CHECK(oss.str() == "Luis (5) y Eva (41)");
}

TEST_CASE("E8: devuelve el propio flujo") {
    Person p("Ana", 30);
    ostringstream oss;
    ostream& r = (oss << p);
    CHECK(&r == &oss);
}
