cmake_minimum_required(VERSION 3.25)

project(Qt)

set(SELECT_BRANCH_OR_TAG "Tag" CACHE STRING "Select to fetch out the git_branch or git_tag corresponding")
set_property(CACHE SELECT_BRANCH_OR_TAG PROPERTY STRINGS "Branch" "Tag")

include(qt6.cmake)
include(qt_creator.cmake)

# add_subdirectory(Qt6AppsDev)
