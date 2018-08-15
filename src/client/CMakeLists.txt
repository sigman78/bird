#

file(GLOB SRC_FILES "*.cpp" "*.h")

add_executable(${PROJECT_NAME}_client ${GUI_TYPE} ${SRC_FILES})

set_target_properties(${PROJECT_NAME}_client PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})

target_link_libraries(${PROJECT_NAME}_client glfw ${GLFW_LIBRARIES} flextgl glm headers)

# move bin to toplevel\bin directory
# install(TARGETS folex_main DESTINATION "${PROJECT_SOURCE_DIR}\\bin")

