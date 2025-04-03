cmake_minimum_required(VERSION 3.20)

project(Qt)


option(BUILD_QT_FROM_SRC
       "Git clone the Qt6 repository, and built them from source"
       ON)
if (BUILD_QT_FROM_SRC)
    include(ExternalProject)

    set(Qt6_SOURCE_DIR      ${CMAKE_SOURCE_DIR}/qt6_sources)
    set(Qt6_BINARY_DIR      ${CMAKE_BINARY_DIR}/qt6_build)
    set(Qt6_INSTALL_DIR     ${CMAKE_BINARY_DIR}/qt6_install)

    ExternalProject_Add(Qt6
        GIT_REPOSITORY      http://code.qt.io/qt/qt5.git
        GIT_TAG             v6.9.0
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${Qt6_SOURCE_DIR}
        BINARY_DIR          ${Qt6_BINARY_DIR}
        INSTALL_DIR         ${Qt6_INSTALL_DIR}
        BUILD_ALWAYS        FALSE
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${Qt6_INSTALL_DIR}
            -DBUILD_LIBRARY_TYPE=Shared
        UPDATE_COMMAND      ""
        UPDATE_DISCONNECTED TRUE)
    
    include_directories(${Qt6_INSTALL_DIR}/include)
    link_directories(${Qt6_INSTALL_DIR}/lib)
endif()


add_executable(${PROJECT_NAME}
    main.cpp)
add_dependencies(${PROJECT_NAME} Qt6)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD    17
    CXX_EXTENSIONS  NO
    CXX_STANDARD_REQUIRED   YES)
target_link_libraries(${PROJECT_NAME} PUBLIC
    )
