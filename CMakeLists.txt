cmake_minimum_required(VERSION 3.9)
project(httpserver_v2)

find_package(Boost REQUIRED COMPONENTS system coroutine)
set(CMAKE_CXX_STANDARD 17)
include_directories(asio/include beast/include)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} pthread)