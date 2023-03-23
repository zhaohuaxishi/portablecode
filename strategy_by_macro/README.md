# 编译说明

默认使用 MCU BACKEND，如果需要使用 MQTT BACKEND，可以通过下面这种方式：

```bash
cmake .. -DCMAKE_CXX_FLAGS=-DBACKEND_MQTT
```
