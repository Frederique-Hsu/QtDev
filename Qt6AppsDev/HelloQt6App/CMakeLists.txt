cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    HelloQt6App)
project(${CURRENT_PROJECT_NAME})

file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")
list(FILTER sources EXCLUDE REGEX "build/*")
list(FILTER headers EXCLUDE REGEX "build/*")

add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers})
add_dependencies(${CURRENT_PROJECT_NAME} Qt6)
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD    17
    CXX_EXTENSIONS  NO
    CXX_STANDARD_REQUIRED   YES)
target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC
    m)