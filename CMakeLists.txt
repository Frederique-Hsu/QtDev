cmake_minimum_required(VERSION 3.25)

project(Qt)

include(${CMAKE_SOURCE_DIR}/get_src_repo.cmake)

include(ExternalProject)

include(qt6.cmake)
include(qt_creator.cmake)
