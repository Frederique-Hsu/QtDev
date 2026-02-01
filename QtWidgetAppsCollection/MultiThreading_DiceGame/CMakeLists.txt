cmake_minimum_required(VERSION  3.24)

set(CURRENT_PROJECT_NAME    MultiThreading_DiceGame)
project(${CURRENT_PROJECT_NAME})

set(CMAKE_AUTOUIC   ON)
set(CMAKE_AUTOMOC   ON)
set(CMAKE_AUTORCC   ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


file(GLOB_RECURSE cpp_sources "*.c*")
file(GLOB_RECURSE cpp_headers "*.h*")
list(FILTER cpp_sources EXCLUDE REGEX "build/*")
list(FILTER cpp_headers EXCLUDE REGEX "build/*")

message(STATUS "${CURRENT_PROJECT_NAME} project's code files list:")
foreach(source ${cpp_sources})
    message(STATUS "\t\t ${source}")
endforeach()
foreach(header ${cpp_headers})
    message(STATUS "\t\t ${header}")
endforeach()
message(STATUS "\n")


if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${CURRENT_PROJECT_NAME} MANUAL_FINALIZATION
        ${cpp_sources}
        ${cpp_headers}
        res.qrc
    )
else()
    add_executable(${CURRENT_PROJECT_NAME}
        ${cpp_sources}
        ${cpp_headers}
        res.qrc
    )
endif()

# if (${QT_VERSION_MAJOR} EQUAL 6)
#     qt_finalize_executable(${CURRENT_PROJECT_NAME})
# endif()

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          OFF
    CXX_STANDARD_REQUIRED   ON)

target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets)

