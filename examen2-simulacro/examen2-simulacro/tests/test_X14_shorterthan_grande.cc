#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include <string>
#include <vector>
#include "Playlist.h"

// Requiere: Track, Playlist (constructor, destructor, add) y shorterThan.
// No usa: tracksAfterLast.

typedef std::vector<std::string> Ids;

TEST_CASE("X14: shorterThan con una lista grande") {
    Playlist p;
    const int N = 1000;
    for (int i = 0; i < N; i++) {
        // duraciones 0..6 repetidas: muchos empates
        REQUIRE(p.add(Track("t" + std::to_string(i), "Pista", i % 7)));
    }
    REQUIRE(p.size() == N);

    // referencias al principio, en medio y al final de la lista
    const int refs[] = {0, 3, 6, 500, N - 1};
    for (int k = 0; k < 5; k++) {
        int ref = refs[k];
        Ids esperado;
        for (int i = 0; i < N; i++) {
            if (i % 7 < ref % 7) {
                esperado.push_back("t" + std::to_string(i));
            }
        }
        CHECK(p.shorterThan("t" + std::to_string(ref)) == esperado);
    }

    CHECK(p.size() == N);
}
