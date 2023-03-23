#include "mcu_backend.h"

#include <iostream>

void McuBackend::Dispatch(const Request& request) {
    std::cout << "mcu dispatch: " << request.method << " " << request.url << std::endl;
}
