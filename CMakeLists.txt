cmake_minimum_required(VERSION 3.0.0)
project(GravitySimulator VERSION 0.1.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_executable(GravitySimulator ${SOURCE_FILES} src/RenderSystem.cpp src/RenderSystem.hpp src/Entity.cpp src/Entity.hpp)
target_link_libraries(GravitySimulator ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
