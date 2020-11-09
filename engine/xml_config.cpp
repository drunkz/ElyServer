#include "xml_config.h"
#include <fstream>
#include <iostream>

namespace ElyServer {
xml_config::xml_config() {}

xml_config::~xml_config() {
    m_doc.clear();
    m_data.clear();
    std::vector<char>().swap(m_data);
}

bool xml_config::initialize(const char *filename) {
    if (loadfile(filename)) {
        m_doc.parse<0>(&m_data.front());
        return true;
    } else {
        return false;
    }
}

bool xml_config::loadfile(const char *filename) {
    using namespace std;
    basic_ifstream<char> stream(filename, ios::binary);
    if (!stream) {
        cout << "cannot open file " << filename << std::endl;
        return false;
    }
    stream.unsetf(ios::skipws);
    stream.seekg(0, ios::end);
    size_t size = stream.tellg();
    stream.seekg(0);
    // 读取数据并添加终止符号0
    m_data.resize(size + 1);
    stream.read(&m_data.front(), static_cast<streamsize>(size));
    m_data[size] = 0;
    return true;
}

char *xml_config::get_xml_value(const char *nodename, const char *attribute) {
    rapidxml::xml_node<> *xroot         = m_doc.first_node();
    rapidxml::xml_node<> *xnode         = xroot->first_node(nodename);
    rapidxml::xml_attribute<char> *attr = xnode->first_attribute(attribute);
    if (attr != NULL) {
        return attr->value();
    }
    return NULL;
}

} // namespace ElyServer
