# cmake version
cmake_minimum_required(VERSION 3.2.2)

set(PROJECT_NAME "bird")
project (${PROJECT_NAME})

option(CORE_WITH_TESTS "Build tests" ON)

# enable warnings
set(MSVC_BUILD_FLAGS "-W3 -GR -wd4996")
set(LINUX_BUILD_FLAGS "-Wall -pedantic")


# setup system specific
if(MSVC)
set(BUILD_FLAGS ${MSVC_BUILD_FLAGS})
else()
set(BUILD_FLAGS ${LINUX_BUILD_FLAGS})
endif()

# CXX global options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##############################

# Set some Win32 Specific Settings
if(WIN32)
set(GUI_TYPE WIN32)
endif(WIN32)

# Set some Apple MacOS Specific settings
if(APPLE)
set(GUI_TYPE MACOSX_BUNDLE)
endif(APPLE)



###############################

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "No examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "No tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "No docs")
set(GLFW_INSTALL OFF CACHE BOOL "No install")

set(GLM_TEST_ENABLE OFF CACHE BOOL "No tests")

add_subdirectory(3rd)
add_subdirectory(src)
