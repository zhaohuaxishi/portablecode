#include <cstdlib>
#include <memory>

#include "backend.h"
#include "mqtt_backend.h"
#include "mcu_backend.h"

std::unique_ptr<IBackend> CreateNewBackend() {
    const char* backend_mqtt = std::getenv("BACKEND_MQTT");

    if (backend_mqtt != nullptr) {
        return std::unique_ptr<IBackend>(new MqttBackend);
    } else {
        return std::unique_ptr<IBackend>(new McuBackend);
    }
}
