#ifndef ELYSERVER_ELY_COMMON_H
#define ELYSERVER_ELY_COMMON_H

#include "iostream"

namespace ElyServer {
#define ELOG(info) std::cout << (info) << std::endl;
#define ELY_SAFE_RELEASE(p)                                                                        \
    if (p) {                                                                                       \
        delete p;                                                                                  \
        p = NULL;                                                                                  \
    }
#define ELY_SAFE_RELEASE_ARRAY(p)                                                                  \
    if (p) {                                                                                       \
        delete[] p;                                                                                \
        p = NULL;                                                                                  \
    }
} // namespace ElyServer

#endif // ELYSERVER_ELY_COMMON_H
