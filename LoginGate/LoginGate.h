#ifndef ELYSERVER_LOGINGATE_H
#define ELYSERVER_LOGINGATE_H

#include "../engine/server_base.h"

namespace ElyServer {
class LoginGate : public server_base {
  public:
    LoginGate();

    virtual ~LoginGate();

    virtual bool initialize(const char *xmlfile);

  private:
    int b;
};
} // namespace ElyServer

#endif // ELYSERVER_LOGINGATE_H
