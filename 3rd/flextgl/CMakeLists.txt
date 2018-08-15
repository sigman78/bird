#

set(SRC_FILES flextGL.c flextGL.h)

add_library(flextgl ${SRC_FILES})

target_include_directories(flextgl INTERFACE ".")

if (WIN32)
  target_link_libraries(flextgl opengl32)
endif()

set_target_properties(flextgl PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})
