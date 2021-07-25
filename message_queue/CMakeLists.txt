cmake_minimum_required(VERSION 3.1)

set(TARGET1 msg_rec)
set(TARGET2 msg_send)

project(msg_project)

add_executable(${TARGET1} msg_receive.c)
add_executable(${TARGET2} msg_send.c)

