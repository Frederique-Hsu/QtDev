cmake_minimum_required(VERSION 3.20)


set(QT6_SOURCE_DIR      ${CMAKE_SOURCE_DIR}/qt6_sources)
set(QT6_STATE_DIR       ${CMAKE_BINARY_DIR}/qt6_state)
set(QT6_INSTALL_DIR     ${CMAKE_BINARY_DIR}/qt6_install)


set(GIT_REPO_NAME       Qt6)
set(GIT_REPO_URL        http://code.qt.io/qt/qt5.git)
set(GIT_BRANCH          6.10.0)
set(GIT_TAG             v6.10.0)
set(GIT_CLONE_DEPTH     10)

message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    find_program(GIT_EXECUTABLE "C:\\Program Files\\Git\\mingw64\\bin\\git.exe" REQUIRED)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    find_program(GIT_EXECUTABLE git REQUIRED)
endif()
message(STATUS "GIT_EXECUTABLE = ${GIT_EXECUTABLE}")

if (NOT EXISTS ${QT6_SOURCE_DIR}/.git)
    message(STATUS "It is now git-cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND     ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_BRANCH} ${GIT_REPO_URL} ${QT6_SOURCE_DIR}
        WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE     git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to clone the ${GIT_REPO_NAME} repository!")
    endif()

else()
    message(STATUS "\nIn ${GIT_REPO_NAME} repo, SELECT_BRANCH_OR_TAG = ${SELECT_BRANCH_OR_TAG}")

    if (${SELECT_BRANCH_OR_TAG} STREQUAL "Branch")
        message(STATUS "Checking current working branch ${GIT_BRANCH}...")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} rev-parse --abbrev-ref HEAD
            OUTPUT_VARIABLE     current_branch
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "current_branch = ${current_branch}")
        if (NOT current_branch STREQUAL ${GIT_BRANCH})
            message(STATUS "Checkout ${GIT_REPO_NAME} to to branch ${GIT_BRANCH}")

            execute_process(
                COMMAND ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_BRANCH}:${GIT_BRANCH}
                COMMAND ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} checkout ${GIT_BRANCH}
                COMMAND ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} submodule update --init --recursive --depth ${GIT_CLONE_DEPTH}
                RESULT_VARIABLE     result
            )
            if (NOT result EQUAL 0)
                message(FATAL_ERROR "Failed to checkout to expected branch ${GIT_BRANCH}")
            endif()
        endif()


    elseif (${SELECT_BRANCH_OR_TAG} STREQUAL "Tag")

        message(STATUS "Checking current working tag ${GIT_TAG}...")
        execute_process(
            COMMAND     ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} describe --tags --exact-match HEAD
            OUTPUT_VARIABLE     current_tag
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "current_tag = ${current_tag}")
        if (NOT current_tag STREQUAL ${GIT_TAG})
            message(STATUS "Switching ${GIT_REPO_NAME} to tag/branch ${GIT_TAG}")

            execute_process(
                COMMAND     ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG}:${GIT_TAG}
                COMMAND     ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} checkout ${GIT_TAG}
                COMMAND     ${GIT_EXECUTABLE} -C ${QT6_SOURCE_DIR} submodule update --init --recursive --depth ${GIT_CLONE_DEPTH}
                RESULT_VARIABLE     result
            )
            if (NOT result EQUAL 0)
                message(STATUS "Failed to switch to your expected tag/branch ${GIT_TAG}")
            endif()
        endif()

    endif()
endif()


include(ExternalProject)

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
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)