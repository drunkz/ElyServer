#include "DBServer.h"
#include "../engine/ely_common.h"
#include <glog/logging.h>
#include <iostream>

namespace ElyServer {
DBServer::DBServer() {}

DBServer::~DBServer() {}

bool DBServer::initialize(const char *xmlfile) { return server_base::initialize(xmlfile); }

void DBServer::run() {
    mysqlpp::Connection conn(false);
    char *dbname   = m_xml_config.get_xml_value("Database", "dbname");
    char *dbip     = m_xml_config.get_xml_value("Database", "ip");
    char *dbport   = m_xml_config.get_xml_value("Database", "port");
    char *username = m_xml_config.get_xml_value("Database", "username");
    char *password = m_xml_config.get_xml_value("Database", "password");
    if (dbname != nullptr && dbip != nullptr && dbport != nullptr && username != nullptr &&
        password != nullptr) {
        bool t = conn.connect(dbname, dbip, username, password, atoi(dbport));
    }

    conn.disconnect();
}

} // namespace ElyServer

int main(int argc, char *argv[]) {
    using namespace ElyServer;
    DBServer d;
    d.initialize("DBServer.xml");
    d.run();
    ELOG("DBServer");
    return 0;
}
