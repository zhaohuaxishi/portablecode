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

#ifndef MCU_BACKEND_H_LO6E8FNY
#define MCU_BACKEND_H_LO6E8FNY

#include "backend.h"

class McuBackend : public IBackend {
private:
    void Dispatch(const Request&) override;
};

#endif /* end of include guard: MCU_BACKEND_H_LO6E8FNY */
