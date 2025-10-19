cmake_minimum_required(VERSION  3.20)


set(QT_CREATOR_SOURCE_DIR       ${CMAKE_SOURCE_DIR}/qt_creator_sources)
set(QT_CREATOR_STATE_DIR        ${CMAKE_BINARY_DIR}/qt_creator_state)
set(QT_CREATOR_INSTALL_DIR      ${CMAKE_BINARY_DIR}/qt_creator_install)


set(GIT_REPO_NAME       "Qt Creator")
set(GIT_REPO_URL        http://code.qt.io/qt-creator/qt-creator.git)
set(GIT_BRANCH          17.0)
set(GIT_TAG             v17.0.2)
set(GIT_CLONE_DEPTH     10)


find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${QT_CREATOR_SOURCE_DIR}/.git)
    message(STATUS "It is now git-cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND     ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_BRANCH} ${GIT_REPO_URL} ${QT_CREATOR_SOURCE_DIR}
        WORKING_DIRECTORY       ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE         git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to clone the ${GIT_REPO_NAME} repository!")
    endif()

else()
    message(STATUS "\nIn ${GIT_REPO_NAME} repo, SELECT_BRANCH_OR_TAG = ${SELECT_BRANCH_OR_TAG}")

    if (${SELECT_BRANCH_OR_TAG} STREQUAL "Branch")

        message(STATUS "Checking current working branch ${GIT_BRANCH}...")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} rev-parse --abbrev-ref HEAD
            OUTPUT_VARIABLE     current_branch
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "current_branch = ${current_branch}")
        if (NOT current_branch STREQUAL ${GIT_BRANCH})
            message(STATUS "Checkout ${GIT_REPO_NAME} repo to branch ${GIT_BRANCH}")
            execute_process(
                COMMAND ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_BRANCH}:${GIT_BRANCH}
                COMMAND ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} checkout ${GIT_BRANCH}
                COMMAND ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} submodule update --init --recursive --depth ${GIT_CLONE_DEPTH}
                RESULT_VARIABLE     result
            )
            if (NOT result EQUAL 0)
                message(FATAL_ERROR "Failed to checkout to expected branch ${GIT_BRANCH}")
            endif()
        endif()

    elseif (${SELECT_BRANCH_OR_TAG} STREQUAL "Tag")

        message(STATUS "Checking current working tag ${GIT_TAG}...")
        execute_process(
            COMMAND     ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} describe --tags --exact-match HEAD
            OUTPUT_VARIABLE     current_tag
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "current_tag = ${current_tag}")
        if (NOT current_tag STREQUAL ${GIT_TAG})
            message(STATUS "Switching ${GIT_REPO_NAME} to tag ${GIT_TAG}")

            execute_process(
                COMMAND     ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG}:${GIT_TAG}
                COMMAND     ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} checkout ${GIT_TAG}
                COMMAND     ${GIT_EXECUTABLE} -C ${QT_CREATOR_SOURCE_DIR} submodule update --init --recursive --depth ${GIT_CLONE_DEPTH}
                RESULT_VARIABLE     result
            )
            if (NOT result EQUAL 0)
                message(FATAL_ERROR "Failed to switch to your expected tag ${GIT_TAG}")
            endif()
        endif()

    endif()
endif()



include(ExternalProject)

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
    BUILD_ALWAYS            TRUE
    # STEP_TARGETS            install
)

add_dependencies(Qt_Creator Qt6)