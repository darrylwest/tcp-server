#

cmake_minimum_required(VERSION 3.10)
project(tcp-server VERSION 1.0.0 LANGUAGES CXX)
add_executable(tcp-server main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.50 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")

find_package(Threads REQUIRED)
add_compile_options(-Wall -Wextra -pedantic -Werror -O3)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
