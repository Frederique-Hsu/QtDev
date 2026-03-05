cmake_minimum_required(VERSION 3.25)


find_package(Git REQUIRED)
if (NOT GIT_FOUND)
    message(FATAL_ERROR "Git not found.")
endif()
message(STATUS "git executable = ${GIT_EXECUTABLE}")

function(check_git_submodules_update_status repo_dir)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${repo_dir} submodule status
        OUTPUT_VARIABLE     submodules_list
        RESULT_VARIABLE     git_result
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT git_result EQUAL 0)
        message(STATUS "Failed to get submodule status")
    endif()

    # 逐行检查，精确匹配行首
    string(REPLACE "\n" ";" lines "${submodules_list}")
    foreach(line ${lines})
        string(REGEX MATCH "^[-+]" match "${line}")
        if (match)
            set(CHECK_SUBMODULES_RESULT 1 PARENT_SCOPE)        
            return()
        endif()
    endforeach()

    set(CHECK_SUBMODULES_RESULT 0 PARENT_SCOPE)
endfunction()

function(check_user_specified_branch_existed repo_dir user_specified_branch)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${repo_dir} branch
        OUTPUT_VARIABLE     branch_list
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message(STATUS "branch list on local repository: \n${branch_list}")

    string(REPLACE "\n" ";" branch_lines "${branch_list}")
    foreach(branch_line ${branch_lines})
        if (${branch_line} STREQUAL "  ${user_specified_branch}")
            set(USER_SPECIFIED_BRANCH_EXISTED 1 PARENT_SCOPE)
            return()
        endif()
    endforeach()
    set(USER_SPECIFIED_BRANCH_EXISTED 0 PARENT_SCOPE)
endfunction()

function(check_user_specified_tag_existed repo_dir user_specified_tag)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${repo_dir} tag
        OUTPUT_VARIABLE     tag_list
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message(STATUS "tag list on local repository: \n${tag_list}")

    # 逐行检查，精确匹配每个tag全字符串
    string(REPLACE "\n" ";" tag_lines "${tag_list}")
    foreach(tag_line ${tag_lines})
        if (${tag_line} STREQUAL ${user_specified_tag})
            set(USER_SPECIFIED_TAG_EXISTED 1 PARENT_SCOPE)
            return()
        endif()
    endforeach()
    set(USER_SPECIFIED_TAG_EXISTED 0 PARENT_SCOPE)
endfunction()

function(check_remote_tag_existed repo_dir remote_tag)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${repo_dir} ls-remote --tags origin
        OUTPUT_VARIABLE     remote_tags_list
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (remote_tags_list MATCHES "refs/tags/${remote_tag}")
        set(REMOTE_TAG_EXISTED 1 PARENT_SCOPE)
    else()
        set(REMOTE_TAG_EXISTED 0 PARENT_SCOPE)
    endif()
endfunction()

function(check_remote_branch_existed repo_dir remote_branch)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${repo_dir} ls-remote --heads origin
        OUTPUT_VARIABLE     remote_branch_list
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (remote_branch_list MATCHES "refs/heads/${remote_branch}")
        set(REMOTE_BRANCH_EXISTED 1 PARENT_SCOPE)
    else()
        set(REMOTE_BRANCH_EXISTED 0 PARENT_SCOPE)
    endif()
endfunction()




function(get_src_repo_checkout_branch src_dir git_branch git_repo_url git_repo_name)
    if (NOT EXISTS ${src_dir}/.git)
        message(STATUS "git clone shallowly the ${git_repo_name} repository...")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} clone --depth=10 --branch=${git_branch} ${git_repo_url} ${src_dir}            
            RESULT_VARIABLE     git_clone_result
        )
        if (NOT git_clone_result EQUAL 0)
            message(FATAL_ERROR "Failed to git clone the ${git_repo_name} repository!")
        endif()
        execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} checkout ${git_branch})
        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule
            OUTPUT_VARIABLE     submodule_list_result
        )
        message(STATUS "${git_repo_name} repository's submodule list = \n${submodule_list_result}")
        if (NOT submodule_list_result STREQUAL "")
            execute_process(
                COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10
            )
        endif()
    else()
        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${src_dir} rev-parse --abbrev-ref HEAD
            OUTPUT_VARIABLE     current_branch
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "current branch of ${git_repo_name} repository is: ${current_branch}")

        if (NOT ${current_branch} STREQUAL ${git_branch})
            message(STATUS "Switching ${git_repo_name} repository to ${git_branch} branch")

            check_remote_branch_existed(${src_dir} ${git_branch})
            if (REMOTE_BRANCH_EXISTED EQUAL 1)
                message(STATUS "remote branch ${git_branch} existed")
                execute_process(
                    COMMAND ${GIT_EXECUTABLE} -C ${src_dir} fetch --depth=10 origin ${git_branch}:${git_branch}
                    RESULT_VARIABLE     git_fetch_result
                )
                if (git_fetch_result EQUAL 0)
                    execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} checkout ${git_branch})
                    execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10)
                    check_git_submodules_update_status(${src_dir})
                    if (CHECK_SUBMODULES_RESULT EQUAL 0)
                        message(STATUS "${git_repo_name} repository had succeeded in updating submodules")
                    elseif(CHECK_SUBMODULES_RESULT EQUAL 1)
                        message(FATAL_ERROR "${git_repo_name} repository failed to update submodules")
                    endif()
                endif()
            elseif(REMOTE_BRANCH_EXISTED EQUAL 0)
                message(FATAL_ERROR "${git_repo_name} repository has no remote branch ${git_branch}")
            endif()
        else()
            message(STATUS "Git pull ${git_repo_name} repository, and update submodules")
            execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} pull origin ${git_branch})
            execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10)
            
            check_git_submodules_update_status(${src_dir})
            if (CHECK_SUBMODULES_RESULT EQUAL 0)
                message(STATUS "${git_repo_name} repository had succeeded in updating submodules")
            elseif(CHECK_SUBMODULES_RESULT EQUAL 1)
                message(FATAL_ERROR "${git_repo_name} repository failed to update submodules")
            endif()
        endif()
    endif()
    message(STATUS "\n")
endfunction()


function(get_src_repo_checkout_tag src_dir git_tag git_repo_url git_repo_name)
    message(STATUS "\n")
    if (NOT EXISTS ${src_dir}/.git)
        message(STATUS "git clone shallowly the ${git_repo_name} repository")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} clone --depth=10 --branch=${git_tag} ${git_repo_url} ${src_dir}
            RESULT_VARIABLE     git_clone_result
        )
        message(STATUS "git_clone_result = ${git_clone_result}")
        if (NOT git_clone_result EQUAL 0)
            message(FATAL_ERROR "Failed to git clone the ${git_repo_name} repository!")
        endif()

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${src_dir} switch -c ${git_tag} ${git_tag}
            COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule
            RESULT_VARIABLE     git_switch_result
            OUTPUT_VARIABLE     git_submodule_list
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "git_switch_result = ${git_switch_result}")
        message(STATUS "git_submodule_list = \n${git_submodule_list}")
        if (NOT git_switch_result EQUAL 0)
            message(FATAL_ERROR "Failed to switch to ${git_tag} branch.")
        endif()
        if (NOT ${git_submodule_list} STREQUAL "")
            execute_process(
                COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10
                RESULT_VARIABLE     git_submodule_result
            )
            message(STATUS "git_submodule_result = ${git_submodule_result}")
            if (NOT git_submodule_result EQUAL 0)
                message(FATAL_ERROR "Failed to fetch submodules of ${git_repo_name} repository.")
            endif()
        endif()
    else()
        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${src_dir} describe --tags --exact-match HEAD
            OUTPUT_VARIABLE     current_tag
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "current tag of ${git_repo_name} repository is: ${current_tag}")

        if (NOT ${current_tag} STREQUAL ${git_tag})
            message(STATUS "Switching ${git_repo_name} repository to ${git_tag} tag")

            check_user_specified_tag_existed(${src_dir} ${git_tag})
            if (USER_SPECIFIED_TAG_EXISTED EQUAL 1)
                message(STATUS "${git_tag} tag already existed.")
                
                check_user_specified_branch_existed(${src_dir} ${git_tag})
                if (USER_SPECIFIED_BRANCH_EXISTED EQUAL 1)
                    message(STATUS "${git_tag} branch already existed.")

                    execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} checkout ${git_tag})
                    execute_process(
                        COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10
                        RESULT_VARIABLE     git_checkout_submodule_update_result
                    )
                    if (NOT git_checkout_submodule_update_result EQUAL 0)
                        message(FATAL_ERROR "Failed to checkout to ${git_tag} branch and update submodules")
                    endif()
                elseif(USER_SPECIFIED_BRANCH_EXISTED EQUAL 0)
                    message(STATUS "${git_tag} branch does not exist")

                    execute_process(
                        COMMAND ${GIT_EXECUTABLE} -C ${src_dir} switch -c ${git_tag} ${git_tag}
                        COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10
                    )
                endif()
            elseif (USER_SPECIFIED_TAG_EXISTED EQUAL 0)
                check_remote_tag_existed(${src_dir} ${git_tag})
                if (REMOTE_TAG_EXISTED EQUAL 1)
                    message(STATUS "remote tag ${git_tag} exists, and fetch/switch to local repository.")
                    execute_process(
                        COMMAND ${GIT_EXECUTABLE} -C ${src_dir} fetch --depth=10 origin tag ${git_tag}
                        RESULT_VARIABLE     git_fetch_remote_tag_result
                    )
                    if (git_fetch_remote_tag_result EQUAL 0)
                        execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} switch -c ${git_tag} ${git_tag})
                        execute_process(COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10)
                    endif()
                elseif(REMOTE_TAG_EXISTED EQUAL 0)
                    message(FATAL_ERROR "remote tag ${git_tag} does not exist.")
                endif()
            endif()
        endif()

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule status
            OUTPUT_VARIABLE     git_submodule_list
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        message(STATUS "git_submodule_list = \n${git_submodule_list}")

        if (NOT ${git_submodule_list} STREQUAL "")
            check_git_submodules_update_status(${src_dir})
            if (CHECK_SUBMODULES_RESULT EQUAL 1)
                message(STATUS "${git_repo_name} repository submodules have not yet updated.")
                message(STATUS "Now update ${git_repo_name} repository submodules")

                execute_process(
                    COMMAND ${GIT_EXECUTABLE} -C ${src_dir} submodule update --init --recursive --depth=10
                    RESULT_VARIABLE     git_submodule_update_result
                )
                if (NOT git_submodule_update_result EQUAL 0)
                    message(FATAL_ERROR "Failed to update the ${git_repo_name} repository's submodules!")
                endif()
            elseif(CHECK_SUBMODULES_RESULT EQUAL 0)
                message(STATUS "Now already updated ${git_repo_name} repository submodules.")
            endif()
        endif()

    endif()
    message(STATUS "\n")
endfunction()
