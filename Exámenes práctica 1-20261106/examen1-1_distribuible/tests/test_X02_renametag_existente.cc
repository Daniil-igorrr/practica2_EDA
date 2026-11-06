#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "Resource.h"

TEST_CASE("X02: renameTag hacia una etiqueta ya presente no duplica") {
    Resource r("bk01", 1999, "Clean Code");
    r.addTag("software");
    r.addTag("craft");
    CHECK(r.renameTag("craft", "SOFTWARE") == true);
    std::vector<std::string> tags = r.getTags();
    REQUIRE(tags.size() == 1);
    CHECK(tags[0] == "software");
}
