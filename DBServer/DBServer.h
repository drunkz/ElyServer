#ifndef ELYSERVER_DBSERVER_H
#define ELYSERVER_DBSERVER_H

#include "../engine/server_base.h"
#include <mysql++/mysql++.h>

namespace ElyServer {
class DBServer : public server_base {
  public:
    DBServer();

    virtual ~DBServer();

    virtual bool initialize(const char *xmlfile);

    void run();
};
} // namespace ElyServer
#endif // ELYSERVER_DBSERVER_H
