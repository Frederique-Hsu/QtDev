cmake_minimum_required(VERSION 3.24)

project(NetworkHostInfo)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 Qt6 COMPONENTS Widgets)
message(STATUS "QT_VERSION = ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}")
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)


file(GLOB_RECURSE cpp_sources "*.c*")
file(GLOB_RECURSE cpp_headers "*.h*")
list(FILTER cpp_sources EXCLUDE REGEX "build/*")
list(FILTER cpp_headers EXCLUDE REGEX "build/*")

message(STATUS "${PROJECT_NAME} project's code files list:")
foreach(source ${cpp_sources})
    message(STATUS "\t\t ${source}")
endforeach()
foreach(header ${cpp_headers})
    message(STATUS "\t\t ${header}")
endforeach()
message(STATUS "\n")


if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION
        ${cpp_sources}
        ${cpp_headers})
else()
    add_executable(${PROJECT_NAME}
        ${cpp_sources}
        ${cpp_headers})
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD            20
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network)
