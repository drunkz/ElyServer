cmake_minimum_required(VERSION 3.18)
project(LoginGate)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)
link_libraries(glog)
add_executable(LoginGate LoginGate.cpp ../engine/xml_config.cpp ../engine/server_base.cpp)
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
        copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/LoginGate.xml ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/LoginGate.xml
        )
