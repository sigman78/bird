#

set(SRC_FILES imgui.cpp imgui.h imgui_internal.h imconfig.h)

add_library(imgui ${SRC_FILES})

target_include_directories(imgui INTERFACE ".")
target_link_libraries(imgui headers)


set_target_properties(imgui PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})
