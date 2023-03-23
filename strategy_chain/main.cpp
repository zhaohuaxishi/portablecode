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

#include <memory>
#include <vector>
#include <iostream>

#include "backend.h"
#include "mcu_backend.h"
#include "mqtt_backend.h"

int main() {
    std::unique_ptr<IBackend> backends[] = {
            std::unique_ptr<IBackend>(new McuBackend),
            std::unique_ptr<IBackend>(new MqttBackend),
    };

    auto request = Request({"POST", "/v1/udi/apis"});
    for (const auto& backend : backends) {
        if (backend->Dispatch(request)) {
            return EXIT_SUCCESS;
        }
    }

    std::cout << "non backend available, do fallback actions" << std::endl;
}
