#include "server_base.h"
#include "../engine/ely_common.h"
#include "arpa/inet.h"
#include <filesystem>
#include <glog/logging.h>
#include <sys/epoll.h>
#include <sys/socket.h>

namespace ElyServer {
server_base::server_base() : m_is_initialize(false) {}

server_base::~server_base() {
    if (m_is_initialize) {
        google::ShutdownGoogleLogging();
    }
}

bool server_base::initialize(const char *xmlfile) {
    if (m_xml_config.initialize(xmlfile)) {
        if (init_log()) {
            init_socket();
            m_is_initialize = true;
            return true;
        }
    }
    m_is_initialize = false;
    return false;
}

bool server_base::init_socket() {
    int skt = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family      = AF_INET;
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_sockaddr.sin_port        = htons(8080);
    socklen_t server_len            = sizeof(server_sockaddr);
    bind(skt, (struct sockaddr *)&server_sockaddr, server_len);
    listen(skt, 0);
    return false;
}

bool server_base::init_log() {
    char *name      = m_xml_config.get_xml_value("Log", "name");
    char *directory = m_xml_config.get_xml_value("Log", "directory");
    google::InitGoogleLogging(name); // 日志文件名前缀
    FLAGS_log_dir = directory;       // 日志保存文件夹
    // 创建日志输出目录
    if (!std::filesystem::exists(directory)) {
        if (!std::filesystem::create_directory(directory)) {
            ELOG("日志文件夹创建失败");
            return false;
        }
    }
    FLAGS_colorlogtostderr          = true; // 控制台输出根据日志等级显示不同颜色
    FLAGS_stop_logging_if_full_disk = true; // 磁盘满时停止写出
    FLAGS_minloglevel               = atoi(m_xml_config.get_xml_value("Log", "minloglevel"));
    FLAGS_logtostderr               = atoi(m_xml_config.get_xml_value("Log", "logtostderr"));
    FLAGS_alsologtostderr           = atoi(m_xml_config.get_xml_value("Log", "alsologtostderr"));
    FLAGS_max_log_size              = atoi(m_xml_config.get_xml_value("Log", "max_log_size"));
    FLAGS_stderrthreshold           = atoi(m_xml_config.get_xml_value("Log", "stderrthreshold"));
    FLAGS_logbuflevel               = atoi(m_xml_config.get_xml_value("Log", "logbuflevel"));
    FLAGS_logbufsecs                = atoi(m_xml_config.get_xml_value("Log", "logbufsecs"));
    // google::InstallFailureSignalHandler();    // 64位Linux系统可能出现死锁问题，需配合libunwind
    // google::InstallFailureWriter();
    return true;
}

} // namespace ElyServer
