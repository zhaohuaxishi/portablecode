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

#ifndef BACKEND_H_EAZ5FYOL
#define BACKEND_H_EAZ5FYOL

#include <string>

struct Request {
    std::string method;
    std::string url;
};

class IBackend {
public:
    virtual ~IBackend() = default;

public:
    virtual void Dispatch(const Request&) = 0;
};

#endif /* end of include guard: BACKEND_H_EAZ5FYOL */
