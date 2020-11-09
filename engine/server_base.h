#ifndef ELYSERVER_SERVER_BASE_H
#define ELYSERVER_SERVER_BASE_H

#include "xml_config.h"

namespace ElyServer {
class server_base {
  public:
    server_base();
    virtual ~server_base();
    virtual bool initialize(const char *xmlfile);

  protected:
    xml_config m_xml_config;

  private:
    bool m_is_initialize; // server_base是否成功初始化
    bool init_log();      // 初始化日志系统
    bool init_socket();   // 初始化socket
};
} // namespace ElyServer

#endif // ELYSERVER_SERVER_BASE_H
