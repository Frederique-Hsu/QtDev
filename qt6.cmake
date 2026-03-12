cmake_minimum_required(VERSION 3.20)


set(QT6_SOURCE_DIR      ${CMAKE_SOURCE_DIR}/qt6_sources)
set(QT6_STATE_DIR       ${CMAKE_BINARY_DIR}/qt6_state)
set(QT6_INSTALL_DIR     ${CMAKE_BINARY_DIR}/qt6_install)


set(GIT_REPO_NAME       Qt6)
# set(GIT_REPO_URL        https://github.com/qt/qt5.git)
set(GIT_REPO_URL        https://code.qt.io/qt/qt5.git)
set(GIT_BRANCH          6.10.2)
set(GIT_TAG             v6.10.2)

get_src_repo_checkout_tag(${QT6_SOURCE_DIR} ${GIT_TAG} ${GIT_REPO_URL} ${GIT_REPO_NAME})

ExternalProject_Add(Qt6
    PREFIX                  ${QT6_STATE_DIR}
    SOURCE_DIR              ${QT6_SOURCE_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${QT6_SOURCE_DIR}"
    UPDATE_DISCONNECTED     TRUE
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
    BUILD_ALWAYS            ${BUILD_ALWAYS_FLAG}
    STEP_TARGETS            install
)
