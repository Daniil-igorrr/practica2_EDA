#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "C03_io_tokenize.cc"

TEST_CASE("C3: tokenize") {
    CHECK(tokenize("a,b,c", ',') == vector<string>{"a", "b", "c"});
    CHECK(tokenize("uno dos", ' ') == vector<string>{"uno", "dos"});
    CHECK(tokenize("sinseparador", ',') == vector<string>{"sinseparador"});
}

TEST_CASE("C3: tokens vacios") {
    CHECK(tokenize("a,,c", ',') == vector<string>{"a", "", "c"});
    CHECK(tokenize("a,b,", ',') == vector<string>{"a", "b"});
    CHECK(tokenize("", ',').empty());
}
