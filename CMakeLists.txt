cmake_minimum_required(VERSION 3.9)
project(yasl)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBSCRIPT_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libscript" CACHE PATH "Provide the directory of the libscript library")

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
find_package(Qt5Gui)
find_package(Qt5Widgets)

##################################################################
###### libscript
##################################################################

add_subdirectory(lib)

##################################################################
###### common
##################################################################

file(GLOB_RECURSE SRC_COMMONS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.cpp)
file(GLOB_RECURSE HDR_COMMONS_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/yasl/common/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.h
)

add_library(commons STATIC ${HDR_COMMONS_FILES} ${SRC_COMMONS_FILES})
target_include_directories(commons PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_dependencies(commons libscript)
target_link_libraries(commons libscript)

foreach(_source IN ITEMS ${HDR_COMMONS_FILES} ${SRC_COMMONS_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

##################################################################
###### core
##################################################################

file(GLOB_RECURSE SRC_CORE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.cpp)
file(GLOB_RECURSE HDR_CORE_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/yasl/core/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.h
)

add_library(core STATIC ${HDR_CORE_FILES} ${SRC_CORE_FILES})
target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_dependencies(core commons)
target_link_libraries(core commons)

##################################################################
###### gui
##################################################################

file(GLOB_RECURSE SRC_GUI_MODULE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/*.cpp)
file(GLOB_RECURSE HDR_GUI_MODULE_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/yasl/gui/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/*.h
)

add_library(gui STATIC ${HDR_GUI_MODULE_FILES} ${SRC_GUI_MODULE_FILES})
target_include_directories(gui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_dependencies(gui core)
target_link_libraries(gui core)

##################################################################
###### widgets
##################################################################

file(GLOB_RECURSE SRC_WIDGETS_MODULE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/*.cpp)
file(GLOB_RECURSE HDR_WIDGETS_MODULE_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/yasl/widgets/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/*.h
)

add_library(widgets STATIC ${HDR_WIDGETS_MODULE_FILES} ${SRC_WIDGETS_MODULE_FILES})
target_include_directories(widgets PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_dependencies(widgets gui)
target_link_libraries(widgets gui)

##################################################################
###### Yasl
##################################################################

file(GLOB SRC_YASL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB HDR_YASL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/yasl/*.h)

add_executable(yasl ${SRC_YASL_FILES} ${HDR_YASL_FILES})
add_dependencies(yasl commons)
target_link_libraries(yasl commons)
add_dependencies(yasl core)
target_link_libraries(yasl core)
add_dependencies(yasl gui)
target_link_libraries(yasl gui)
add_dependencies(yasl widgets)
target_link_libraries(yasl widgets)

foreach(_source IN ITEMS ${HDR_FILES} ${SRC_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

##################################################################
###### Tests, tools & examples
##################################################################

add_subdirectory(tests)
add_subdirectory(tools)
#add_subdirectory(examples)

# Copy examples to build directory
file(GLOB_RECURSE YASL_EXAMPLES_FILES "examples/*.y")
file(COPY ${YASL_EXAMPLES_FILES} DESTINATION ${CMAKE_BINARY_DIR})
