cmake_minimum_required(VERSION 3.25)

project(Qt)


option(BUILD_QT_FROM_SRC
       "Git clone the Qt6 repository, and built them from source"
       ON)
if (BUILD_QT_FROM_SRC)
    include(ExternalProject)

    # 设置安装路径到 build 目录
    set(QT6_SOURCE_DIR          "${CMAKE_SOURCE_DIR}/qt6_sources")
    set(QT6_BUILD_DIR           "${CMAKE_BINARY_DIR}/qt6_build")
    set(QT6_INSTALL_DIR         "${CMAKE_BINARY_DIR}/qt6_install")
    set(QTCREATOR_SOURCE_DIR    "${CMAKE_SOURCE_DIR}/qt_creator_sources")
    set(QTCREATOR_BUILD_DIR     "${CMAKE_BINARY_DIR}/qt_creator_build")
    set(QTCREATOR_INSTALL_DIR   "${CMAKE_BINARY_DIR}/qt_creator_install")

    # 定义 Qt6 的编译选项
    set(QT6_CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${QT6_INSTALL_DIR}
        -DQT_BUILD_EXAMPLES=ON
        -DQT_BUILD_TESTS=OFF
        -DBUILD_SHARED_LIBS=ON
        # 启用必要的模块（根据需要调整）
        -DQT_AVOID_CMAKE_ARCHIVING_API=ON
        -DFEATURE_system_zlib=ON
        -DFEATURE_system_sqlite=ON)

    ExternalProject_Add(Qt6
        GIT_REPOSITORY      http://code.qt.io/qt/qt5.git
        GIT_TAG             v6.9.0
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          "${QT6_SOURCE_DIR}"
        BINARY_DIR          "${QT6_BUILD_DIR}"
        INSTALL_DIR         "${QT6_INSTALL_DIR}"
        CMAKE_ARGS          ${QT6_CMAKE_ARGS}
        BUILD_ALWAYS        FALSE
        UPDATE_COMMAND      ""
        UPDATE_DISCONNECTED FALSE
        STEP_TARGETS        install)

    # 定义 Qt Creator 的编译选项
    set(QTCREATOR_CMAKE_ARGS
        -DCMAKE_PREFIX_PATH=${QT6_INSTALL_DIR}
        -DCMAKE_INSTALL_PREFIX=${QTCREATOR_INSTALL_DIR}
        -DBUILD_DEVELOPER_BUILD=OFF
        -DLLVM_INSTALL_DIR=/usr/lib/llvm-18)

    ExternalProject_Add(QtCreator
        GIT_REPOSITORY      http://code.qt.io/qt-creator/qt-creator.git
        GIT_TAG             v16.0.0
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          "${QTCREATOR_SOURCE_DIR}"
        BINARY_DIR          "${QTCREATOR_BUILD_DIR}"
        INSTALL_DIR         "${QTCREATOR_INSTALL_DIR}"
        CMAKE_ARGS          ${QTCREATOR_CMAKE_ARGS}
        BUILD_ALWAYS        FALSE
        UPDATE_COMMAND      ""
        UPDATE_DISCONNECTED FALSE
        DEPENDS             Qt6)

    # 添加自定义目标以运行构建
    add_custom_target(build_all
        DEPENDS
            Qt6
            QtCreator)

    message(STATUS "Qt6 将安装到: ${QT6_INSTALL_DIR}")
    message(STATUS "Qt Creator 将安装到： ${QTCREATOR_INSTALL_DIR}")
endif()


add_subdirectory(Qt6AppsDev)
