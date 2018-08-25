cmake_minimum_required(VERSION 3.9)
project(yasl)

set(LIBSCRIPT_PROJECT_DIR "" CACHE PATH "Provide the directory of the libscript library")

if ("${LIBSCRIPT_PROJECT_DIR}" STREQUAL "")
  message(FATAL_ERROR "The directory of the libscript project must be specified")  
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # disables warning about DLL export 
  # this is annoying when using C++ STL
  add_compile_options(/wd4251)  
endif()

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Widgets)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HDR_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
add_library(libyasl ${HDR_FILES} ${SRC_FILES})
target_include_directories(libyasl PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(libyasl Qt5::Core)
target_link_libraries(libyasl Qt5::Widgets)

add_executable(yasl "src/main.cpp")
target_link_libraries(yasl libyasl)

foreach(_source IN ITEMS ${HDR_FILES} ${SRC_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(tools)
#add_subdirectory(examples)

# Copy examples to build directory
file(GLOB_RECURSE YASL_EXAMPLES_FILES "examples/*.y")
file(COPY ${YASL_EXAMPLES_FILES} DESTINATION ${CMAKE_BINARY_DIR})

add_dependencies(libyasl libscript)
target_include_directories(libyasl PUBLIC "${LIBSCRIPT_PROJECT_DIR}/include")
target_include_directories(libyasl PUBLIC "../include")
target_include_directories(libyasl PUBLIC "lib/libscript")
target_link_libraries(libyasl libscript)