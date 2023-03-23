//
//                      Copyright (C) All Rights Reserved
//
//                      ██████╗██╗   ██╗████████╗███████╗
//                     ██╔════╝██║   ██║╚══██╔══╝██╔════╝
//                     ██║     ██║   ██║   ██║   █████╗
//                     ██║     ╚██╗ ██╔╝   ██║   ██╔══╝
//                     ╚██████╗ ╚████╔╝    ██║   ███████╗
//                      ╚═════╝  ╚═══╝     ╚═╝   ╚══════╝
//
//                          guorongfei@cvte.com
//

#include "random_uuid.h"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>

/**
 * code from https://stackoverflow.com/a/71826534
 */
std::string CreateRandomUUID() {
    std::srand(time(nullptr));
    char v[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    char buf[37] = {0};
    for (int i = 0; i < 36; ++i) {
        buf[i] = v[rand() % 16];
    }

    buf[8] = '-';
    buf[13] = '-';
    buf[18] = '-';
    buf[23] = '-';

    return buf;
}
