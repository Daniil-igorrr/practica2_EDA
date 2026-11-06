#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X01: renameTag renombra y mantiene el orden") {
    Resource r("bk01", 1999, "Clean Code");
    r.addTag("software");
    r.addTag("craft");
    CHECK(r.renameTag("craft", "artesania") == true);
    CHECK(r.hasTag("artesania") == true);
    CHECK(r.hasTag("craft") == false);
    std::vector<std::string> tags = r.getTags();
    REQUIRE(tags.size() == 2);
    CHECK(tags[0] == "artesania");
    CHECK(tags[1] == "software");
}
