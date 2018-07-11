
set(YASL_BUILD_STATS_TOOL FALSE CACHE BOOL "Check if you want to build the statistics generator")

if(YASL_BUILD_STATS_TOOL)

file(GLOB TOOLS_STATS_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB TOOLS_STATS_HDR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(yasl-stats ${TOOLS_STATS_SRC_FILES} ${TOOLS_STATS_HDR_FILES})

target_link_libraries(yasl-stats Qt5::Core)
target_link_libraries(yasl-stats Qt5::Widgets)

set_target_properties(yasl-stats PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set_target_properties(yasl-stats PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

target_include_directories(yasl-stats PUBLIC "${CMAKE_SOURCE_DIR}/include")
add_dependencies(yasl-stats libscript)
add_dependencies(yasl-stats libyasl)
target_link_libraries(yasl-stats libscript)
target_link_libraries(yasl-stats libyasl)
target_include_directories(yasl-stats PUBLIC "${LIBSCRIPT_PROJECT_DIR}/include")
target_include_directories(yasl-stats PUBLIC "${CMAKE_SOURCE_DIR}/lib/libscript")

endif()


