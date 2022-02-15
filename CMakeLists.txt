#

cmake_minimum_required(VERSION 3.10)
project(tcpserver VERSION 1.0.0 LANGUAGES CXX)

add_executable(tcpserver main.cpp tcpserver.cpp connection_handler.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)
add_compile_options(-Wall -Wextra -pedantic -Werror -O0)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
