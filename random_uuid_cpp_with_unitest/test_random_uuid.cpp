#include <algorithm>
#include <regex>
#include <set>

#include "contrib/catch_amalgamated.hpp"

#include "random_uuid.h"

TEST_CASE("test random uuid") {
    std::regex uuid_regex("[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}");

    SECTION("check random") {
        std::set<std::string> generated;
        for (int i = 0; i < 1000; ++i) {
            const auto& uuid = CreateRandomUUID();
            REQUIRE(std::regex_search(uuid, uuid_regex));
            REQUIRE(generated.count(uuid) == 0);
            generated.insert(uuid);
        }
    }
}
