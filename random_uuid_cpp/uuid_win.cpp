#include "random_uuid.h"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "combaseapi.h"

std::string CreateRandomUUID() {
    GUID guid;

    CoCreateGuid(&guid);

    char uuid[40] = {0};
    sprintf(uuid,
            "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
            guid.Data1,
            guid.Data2,
            guid.Data3,
            guid.Data4[0],
            guid.Data4[1],
            guid.Data4[2],
            guid.Data4[3],
            guid.Data4[4],
            guid.Data4[5],
            guid.Data4[6],
            guid.Data4[7]);
    return std::string(uuid);
}
