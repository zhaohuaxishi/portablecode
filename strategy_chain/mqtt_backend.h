#ifndef MQTT_BACKEND_H_WMN7OLWA
#define MQTT_BACKEND_H_WMN7OLWA

#include "backend.h"

class MqttBackend : public IBackend {
private:
    bool Dispatch(const Request&) override;
};

#endif /* end of include guard: MQTT_BACKEND_H_WMN7OLWA */
