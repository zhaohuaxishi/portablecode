#include <memory>
#include "backend.h"

#ifdef BACKEND_MQTT
#include "mqtt_backend.h"
#else
#include "mcu_backend.h"
#endif

int main() {
    std::unique_ptr<IBackend> backend = nullptr;

#ifdef BACKEND_MQTT
    backend.reset(new MqttBackend);
#else
    backend.reset(new McuBackend);
#endif

    backend->Dispatch({"POST", "/v1/udi/apis"});
}
