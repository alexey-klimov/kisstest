cmake_minimum_required(VERSION 3.5)

project(kisstest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DEMO ${PROJECT_NAME}_demo)
add_executable(${PROJECT_DEMO} ${CMAKE_CURRENT_SOURCE_DIR}/demo/demo.cpp)

target_include_directories(${PROJECT_DEMO} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
