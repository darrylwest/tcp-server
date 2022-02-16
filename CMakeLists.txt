#

cmake_minimum_required(VERSION 3.10)
project(tcp-server VERSION 1.0.0 LANGUAGES CXX)
add_executable(tcp-server main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.74 REQUIRED COMPONENTS filesystem)

if (Boost_FOUND)
  message(STATUS "Boost version: ${Boost_VERSION}")
  message("boost include dir: ${Boost_INCLUDE_DIR}")
  include_directories(${Boost_INCLUDE_DIR})
endif()

find_package(Threads REQUIRED)
add_compile_options(-Wall -Wextra -pedantic -Werror -O3)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
