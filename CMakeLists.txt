cmake_minimum_required(VERSION 3.2)

project(string)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")

set(INCLUDE_DIRS "")
foreach(header_file ${HEADERS})
    get_filename_component(dir ${header_file} PATH)
    list(APPEND INCLUDE_DIRS ${dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE INCLUDE_DIRS)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
