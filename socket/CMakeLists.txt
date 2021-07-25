cmake_minimum_required(VERSION 3.1)

project(scoket_test)

set(TARGET1 sock_server)
set(TARGET2 sock_client)

add_executable(${TARGET2} sock_client.c)
add_executable(${TARGET1} sock_server.c)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

target_link_libraries(${TARGET1} pthread)

target_link_libraries(${TARGET2} pthread)