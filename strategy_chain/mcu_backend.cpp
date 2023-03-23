#include "mcu_backend.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include "backend.h"

bool McuBackend::Dispatch(const Request& request) {
    if (std::getenv("BACKEND_MCU") == nullptr) {
        return false;
    }

    std::cout << "mcu dispatch: " << request.method << " " << request.url << std::endl;
    return true;
}
