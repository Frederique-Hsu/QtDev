cmake_minimum_required(VERSION  3.20)


set(QT_CREATOR_SOURCE_DIR       ${CMAKE_SOURCE_DIR}/qt_creator_sources)
set(QT_CREATOR_STATE_DIR        ${CMAKE_BINARY_DIR}/qt_creator_state)
set(QT_CREATOR_INSTALL_DIR      ${CMAKE_BINARY_DIR}/qt_creator_install)


set(GIT_REPO_NAME       "Qt Creator")
# set(GIT_REPO_URL        https://github.com/qt-creator/qt-creator.git)
SET(GIT_REPO_URL        https://code.qt.io/qt-creator/qt-creator.git)
set(GIT_TAG             v18.0.2)
set(GIT_BRANCH          18.0)


get_src_repo_checkout_tag(${QT_CREATOR_SOURCE_DIR} ${GIT_TAG} ${GIT_REPO_URL} ${GIT_REPO_NAME})
# get_src_repo_checkout_branch(${QT_CREATOR_SOURCE_DIR} ${GIT_BRANCH} ${GIT_REPO_URL} ${GIT_REPO_NAME})

ExternalProject_Add(Qt_Creator
    PREFIX                  ${QT_CREATOR_STATE_DIR}
    SOURCE_DIR              ${QT_CREATOR_SOURCE_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${QT_CREATOR_SOURCE_DIR}"
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX=${QT_CREATOR_INSTALL_DIR}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_PREFIX_PATH=${QT6_INSTALL_DIR}
        -DWITH_QMLDESIGNER=ON
        -DSHOW_BUILD_DATE=ON
        # -DBUILD_DESIGNSTUDIO=ON
    BUILD_ALWAYS            FALSE
    STEP_TARGETS            install
)

add_custom_command(TARGET Qt_Creator POST_BUILD
    COMMAND ${CMAKE_COMMAND} --install ${QT_CREATOR_STATE_DIR}/src/Qt_Creator-build --prefix ${QT_CREATOR_INSTALL_DIR} --component Dependencies
    COMMENT "Installing Qt Creator with dependencies"
)

add_dependencies(Qt_Creator Qt6)
