cmake_minimum_required(VERSION 3.25)

project(Qt)


option(BUILD_QT_FROM_SRC
       "Git clone the Qt6 repository, and built them from source"
       ON)
if (BUILD_QT_FROM_SRC)
    include(ExternalProject)

    # 设置安装路径到 build 目录
    set(QT6_SOURCE_DIR          ${CMAKE_SOURCE_DIR}/qt6_sources)
    set(QT6_BUILD_DIR           ${CMAKE_BINARY_DIR}/qt6_build)
    set(QT6_INSTALL_DIR         ${CMAKE_BINARY_DIR}/qt6_install)
    set(QT6_DOWNLOAD_DIR        ${CMAKE_BINARY_DIR}/qt6_download)
    set(QTCREATOR_SOURCE_DIR    ${CMAKE_SOURCE_DIR}/qt_creator_sources)
    set(QTCREATOR_BUILD_DIR     ${CMAKE_BINARY_DIR}/qt_creator_build)
    set(QTCREATOR_INSTALL_DIR   ${CMAKE_BINARY_DIR}/qt_creator_install)
    set(QTCREATOR_DOWNLOAD_DIR  ${CMAKE_BINARY_DIR}/qt_creator_download)

    ExternalProject_Add(Qt6
        GIT_REPOSITORY      http://code.qt.io/qt/qt5.git
        GIT_TAG             v6.9.0
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        UPDATE_DISCONNECTED TRUE
        SOURCE_DIR          ${QT6_SOURCE_DIR}
        BINARY_DIR          ${QT6_BUILD_DIR}
        DOWNLOAD_DIR        ${QT6_DOWNLOAD_DIR}
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DCMAKE_INSTALL_PREFIX=${QT6_INSTALL_DIR}
            -DQT_BUILD_EXAMPLES=OFF
            -DBUILD_SHARED_LIBS=ON
            # 选择禁用某些模块
            -DBUILD_qtwebengine=OFF     # qtwebengine模块需要编译整个chromium内核，其编译非常耗时，且极易失败。所以禁用该模块。
            -DBUILD_qtdoc=OFF
            -DBUILD_qtwebview=OFF
            -DBUILD_qtwebchannel=OFF    # qtdoc, qtwebview, qtwebchannel三个模块都依赖于qtwebengine，跟随着禁用这三个模块。
            -DBUILD_qtgrpc=OFF          # qtgrpc模块依赖于外部的protobuf，因在实际开发中用不到该模块而跳过编译该模块。
            -DBUILD_qtquick3dphysics=OFF    # qtquick3dphysics依赖于图形渲染引擎，不同OS平台实现不一样，无法做到统一。故禁用该模块。
            -DQT_FEATURE_ssl=ON     # 该选项必须启用, 否则在Qt_Creator项目编译时，QNetworkQuery/QSslError会报错。
        BUILD_ALWAYS        FALSE
        STEP_TARGETS        install)

    if (TRUE)
        ExternalProject_Add(Qt_Creator
            GIT_REPOSITORY      http://code.qt.io/qt-creator/qt-creator.git
            GIT_TAG             v16.0.0
            GIT_SHALLOW         TRUE
            GIT_PROGRESS        TRUE
            UPDATE_DISCONNECTED TRUE
            SOURCE_DIR          ${QTCREATOR_SOURCE_DIR}
            BINARY_DIR          ${QTCREATOR_BUILD_DIR}
            DOWNLOAD_DIR        ${QTCREATOR_DOWNLOAD_DIR}
            CMAKE_ARGS
                -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                -DCMAKE_INSTALL_PREFIX=${QTCREATOR_INSTALL_DIR}
                -DBUILD_SHARED_LIBS=ON
                -DCMAKE_PREFIX_PATH=${QT6_INSTALL_DIR}
            BUILD_ALWAYS        FALSE
            DEPENDS             Qt6)
    else()
    endif()

    # add_dependencies(Qt_Creator Qt6)
    # add_custom_target(build_all ALL
    #     DEPENDS
    #         Qt6
    #         Qt_Creator)

    message(STATUS "Qt6 将安装到: ${QT6_INSTALL_DIR}")
    message(STATUS "Qt Creator 将安装到： ${QTCREATOR_INSTALL_DIR}")
endif()


# add_subdirectory(Qt6AppsDev)
