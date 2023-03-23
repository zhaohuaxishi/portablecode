# 构建说明

该项目使用 CMake 作为构建脚本生成工具，如果你需要使用 NDK 构建，可以通过下面这种方式：

```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/bin/build/cmake/android.toolchain.cmake -DANDROID_PLATFORM=21
```
