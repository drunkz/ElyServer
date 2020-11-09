#include "LoginGate.h"
#include "../engine/ely_common.h"
#include "../engine/xml_config.h"
#include <iostream>

namespace ElyServer {
LoginGate::LoginGate() {}

LoginGate::~LoginGate() {}

bool LoginGate::initialize(const char *xmlfile) { return server_base::initialize(xmlfile); }

} // namespace ElyServer

int main(int argc, char *argv[]) {
    using namespace ElyServer;
    using namespace std;
    return 0;
}
