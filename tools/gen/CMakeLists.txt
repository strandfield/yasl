
set(YASL_BUILD_GEN_TOOL FALSE CACHE BOOL "Check if you want to build the binding yasl-generator")

if(YASL_BUILD_GEN_TOOL)

set(LIBCLANG_INCLUDE_DIR "" CACHE PATH "libclang include directory")
set(LIBCLANG_LIB_DEBUG "" CACHE FILEPATH "Path to libclang (debug)")
set(LIBCLANG_LIB_RELEASE "" CACHE FILEPATH "Path to libclang (release)")

file(GLOB TOOLS_GEN_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB TOOLS_GEN_HDR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

set(CMAKE_AUTORCC TRUE)
add_executable(yasl-gen ${TOOLS_GEN_HDR_FILES} ${TOOLS_GEN_SRC_FILES} res.qrc)

target_link_libraries(yasl-gen Qt5::Core)
target_link_libraries(yasl-gen Qt5::Widgets)

set_target_properties(yasl-gen PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set_target_properties(yasl-gen PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

target_include_directories(yasl-gen PRIVATE ${LIBCLANG_INCLUDE_DIR})
target_include_directories(yasl-gen PUBLIC "../include")

target_link_libraries(yasl-gen debug ${LIBCLANG_LIB_DEBUG})
target_link_libraries(yasl-gen general ${LIBCLANG_LIB_RELEASE})

endif()


