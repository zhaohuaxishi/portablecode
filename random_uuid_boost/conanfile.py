from conans import ConanFile, CMake, tools


class RandomUUID(ConanFile):
    name = "random_uuid"
    version = "1.0"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake"
    exports_sources = "CMakeLists.txt", "*.cpp", "*.h"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC


    def requirements(self):
        self.requires("boost/1.75.0")

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CMAKE_BUILD_TYPE"] = self.settings.build_type
        cmake.configure()
        cmake.build()

        cmake.install()
