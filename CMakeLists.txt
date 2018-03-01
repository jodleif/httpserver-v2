cmake_minimum_required(VERSION 3.9)
project(httpserver_v2)
message("test")
MESSAGE("Project_name:  ${PROJECT_NAME}")

find_package(Boost REQUIRED COMPONENTS system coroutine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wextra -Wall -Winvalid-pch -Wredundant-decls -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral")
set(CMAKE_CXX_FLAGS_RELEASE "-march=native -O3")
#ignore warnings for included libraries
include_directories(SYSTEM asio/include beast/include date/include)
include_directories(include)


set(HEADERS include/binary_file.h include/hash_literal.h)
set(SOURCES src/main.cpp src/binary_file.cpp)
set(OBJECTS index.o)

#add_custom_target(index_object
#                  COMMAND makesite.sh
#                  BYPRODUCTS index.o index.html.gz
#                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#                  USES_TERMINAL)


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${OBJECTS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} pthread)
add_custom_command(OUTPUT index_o
        COMMAND "./makesite.sh"
        OUTPUT "${CMAKE_SOURCE_DIR}/index.o"
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
        USES_TERMINAL
        VERBATIM)
