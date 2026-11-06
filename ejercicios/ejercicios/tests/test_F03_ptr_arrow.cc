#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "F03_ptr_arrow/Point.h"

TEST_CASE("F3: desplazar modifica el punto apuntado") {
    Point a(3, 4);
    move_by(&a, 1, 1);
    CHECK(a.x == 4);
    CHECK(a.y == 5);
    move_by(&a, -4, -5);
    CHECK(a.x == 0);
    CHECK(a.y == 0);
}

TEST_CASE("F3: is_origin") {
    Point o(0, 0);
    Point p(0, 1);
    CHECK(is_origin(&o));
    CHECK_FALSE(is_origin(&p));
    CHECK_FALSE(is_origin(nullptr));
}

TEST_CASE("F3: farthest devuelve uno de los punteros") {
    Point a(3, 4);
    Point b(1, 1);
    Point c(-6, 0);
    CHECK(farthest(&a, &b) == &a);
    CHECK(farthest(&b, &a) == &a);
    CHECK(farthest(&a, &c) == &c);
}

TEST_CASE("F3: empate y punteros nulos") {
    Point a(3, 4);
    Point b(-4, 3);
    CHECK(farthest(&a, &b) == &a);
    CHECK(farthest(nullptr, &b) == &b);
    CHECK(farthest(&a, nullptr) == &a);
    CHECK(farthest(nullptr, nullptr) == nullptr);
}

TEST_CASE("F3: desplazar con puntero nulo no falla") {
    move_by(nullptr, 1, 1);
    CHECK(true);
}
