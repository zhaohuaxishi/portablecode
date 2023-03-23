#include "random_uuid.h"

#include <cstddef>
#include <iostream>
#include <sstream>

#include "combaseapi.h"

std::string CreateRandomUUID() {
    GUID guid;

    CoCreateGuid(&guid);

    std::stringstream sstream;
    sstream << std::hex << guid.Data1 << "-" << guid.Data2 << "-" << guid.Data3 << "-";
    sstream << (int) guid.Data4[0] << (int) guid.Data4[1] << "-";

    for (std::size_t i = 2; i < 8; ++i) {
        sstream << (int) guid.Data4[i];
    }

    return sstream.str();
}
