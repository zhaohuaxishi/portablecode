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

#include "mqtt_backend.h"

#include <iostream>

bool MqttBackend::Dispatch(const Request& request) {
    if (std::getenv("BACKEND_MQTT") == nullptr) {
        return false;
    }

    std::cout << "mqtt dispatch: " << request.method << " " << request.url << std::endl;
    return true;
}
