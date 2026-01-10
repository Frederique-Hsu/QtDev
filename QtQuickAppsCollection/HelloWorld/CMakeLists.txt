cmake_minimum_required(VERSION 3.16)

project(HelloWorld VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

#===================================================================================================

file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")
file(GLOB_RECURSE qmls "*.qml")
list(FILTER sources EXCLUDE REGEX "./build/*")
list(FILTER headers EXCLUDE REGEX "./build/*")
list(FILTER qmls EXCLUDE REGEX "./build/*")

message(STATUS "${PROJECT_NAME} project's code files list: ")
foreach(source ${sources})
    message(STATUS "\t\t ${source}")
endforeach()
foreach(header ${headers})
    message(STATUS "\t\t ${header}")
endforeach()
foreach(qml ${qmls})
    message(STATUS "\t\t ${qml}")
endforeach()

qt_add_executable(appHelloWorld
    ${sources}
    ${headers}
)

qt_add_qml_module(appHelloWorld
    URI         HelloWorld
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appHelloWorld PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appHelloWorld
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appHelloWorld PRIVATE
    Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appHelloWorld
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
