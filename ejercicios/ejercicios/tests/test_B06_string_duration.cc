#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "B06_string_duration.cc"

TEST_CASE("B6: formato m:ss") {
    int a = 0;
    int b = 5;
    int c = 60;
    int d = 187;
    CHECK(format_duration(a) == "0:00");
    CHECK(format_duration(b) == "0:05");
    CHECK(format_duration(c) == "1:00");
    CHECK(format_duration(d) == "3:07");
}

TEST_CASE("B6: segundos con dos cifras") {
    int a = 9;
    int b = 10;
    int c = 59;
    int d = 61;
    CHECK(format_duration(a) == "0:09");
    CHECK(format_duration(b) == "0:10");
    CHECK(format_duration(c) == "0:59");
    CHECK(format_duration(d) == "1:01");
}

TEST_CASE("B6: los minutos no tienen limite") {
    int a = 3900;
    int b = 354;
    int c = 36000;
    CHECK(format_duration(a) == "65:00");
    CHECK(format_duration(b) == "5:54");
    CHECK(format_duration(c) == "600:00");
}

TEST_CASE("B6: valor negativo") {
    int a = -4;
    CHECK(format_duration(a) == "0:00");
}
