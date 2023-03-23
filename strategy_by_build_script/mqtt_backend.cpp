#include "mqtt_backend.h"

#include <iostream>

void MqttBackend::Dispatch(const Request& request) {
    std::cout << "mqtt dispatch: " << request.method << " " << request.url << std::endl;
}

std::unique_ptr<IBackend> CreateNewBackend() {
    return std::unique_ptr<IBackend>(new MqttBackend);
}
