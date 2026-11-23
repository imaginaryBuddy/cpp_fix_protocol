cmake_minimum_required(VERSION 3.20)

project(cpp_fix_protocol LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server server/server.cpp server/Application.cpp)
add_executable(client client/client.cpp client/Application.cpp)

target_link_directories(client PRIVATE /usr/local/lib)
target_link_libraries(client PRIVATE quickfix)

target_include_directories(client PRIVATE /usr/local/include)

target_link_directories(server PRIVATE /usr/local/lib)
target_link_libraries(server PRIVATE quickfix)

target_include_directories(server PRIVATE /usr/local/include)

target_compile_options(server PUBLIC -Wall)
target_compile_options(client PUBLIC -Wall)