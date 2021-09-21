cmake_minimum_required(VERSION 3.17)
project(pregatest)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
find_package(Qt5Widgets REQUIRED)

add_executable(pregatest main.cpp GUI.cpp GUI.h Service.cpp Service.h Object.cpp Object.h Repository.cpp Repository.h)

target_link_libraries(pregatest Qt5::Widgets)

