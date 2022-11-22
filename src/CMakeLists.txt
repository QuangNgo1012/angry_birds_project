file(GLOB SOURCES ./*.?pp)
set(PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})
include_directories("${PROJECT_BINARY_DIR}")
add_executable(example_exe ${SOURCES})
target_link_libraries(example_exe PRIVATE sfml-graphics)
target_link_libraries(example_exe PRIVATE box2d)
add_custom_command(TARGET example_exe PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:example_exe>)