#include <memory>

#include "backend.h"

int main() {
    std::unique_ptr<IBackend> backend = CreateNewBackend();
    backend->Dispatch({"POST", "/v1/udi/apis"});
}
