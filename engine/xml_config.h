#ifndef ELYSERVER_XML_CONFIG_H
#define ELYSERVER_XML_CONFIG_H

#include "../common/rapidxml.hpp"
#include <vector>

namespace ElyServer {
class xml_config {
  public:
    xml_config();
    bool initialize(const char *filename);
    char *get_xml_value(const char *nodename,
                        const char *attribute); // 根据节点名和属性名取得属性值
    virtual ~xml_config();

  private:
    std::vector<char> m_data;            // xml字节数据
    rapidxml::xml_document<> m_doc;      // xml_document
    bool loadfile(const char *filename); // 加载xml文件
};
} // namespace ElyServer

#endif // ELYSERVER_XML_CONFIG_H
