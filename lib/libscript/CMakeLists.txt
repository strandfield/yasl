

file(GLOB_RECURSE LIBSCRIPT_SRC_FILES ${LIBSCRIPT_PROJECT_DIR}/src/*.cpp)
file(GLOB_RECURSE LIBSCRIPT_HDR_FILES 
  ${LIBSCRIPT_PROJECT_DIR}/include/*.h
  ${LIBSCRIPT_PROJECT_DIR}/src/*.h
)

add_library(libscript SHARED ${LIBSCRIPT_HDR_FILES} ${LIBSCRIPT_SRC_FILES})
target_include_directories(libscript PRIVATE "${LIBSCRIPT_PROJECT_DIR}/include")
target_include_directories(libscript PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(libscript Qt5::Core)
target_link_libraries(libscript Qt5::Widgets)

foreach(_source IN ITEMS ${LIBSCRIPT_HDR_FILES} ${LIBSCRIPT_SRC_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

target_compile_definitions(libscript PUBLIC -DLIBSCRIPT_HAS_CONFIG)
target_compile_definitions(libscript PUBLIC -DLIBSCRIPT_CONFIG_HEADER="${CMAKE_CURRENT_SOURCE_DIR}/libscriptconfig.h")
target_compile_definitions(libscript PRIVATE -DLIBSCRIPT_COMPILE_LIBRARY)
set_target_properties(libscript PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set_target_properties(libscript PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

#message("${CMAKE_BINARY_DIR}")