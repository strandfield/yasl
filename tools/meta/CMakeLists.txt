
file(GLOB_RECURSE TOOLS_GEN_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TOOLS_GEN_HDR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

set(CMAKE_AUTORCC TRUE)
add_executable(yasl-meta ${TOOLS_GEN_HDR_FILES} ${TOOLS_GEN_SRC_FILES} res.qrc)

target_include_directories(yasl-meta PRIVATE ".")

target_link_libraries(yasl-meta Qt5::Core)
target_link_libraries(yasl-meta Qt5::Widgets)

set_target_properties(yasl-meta PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set_target_properties(yasl-meta PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")


#################################################################
###### Find libclang
#################################################################

function(find_clang_binary)
  unset(CLANG_BINARY CACHE)
  find_program(CLANG_BINARY "clang")
  if(NOT CLANG_BINARY)
    message("Could not find clang binary, yasl-meta will be built without support for importing C++ code")
    set(LIBCLANG_FOUND FALSE)
  else()
    message(STATUS "Found clang at ${CLANG_BINARY}")
  endif()
endfunction()

function(find_libclang)
  unset(clang_install_dir CACHE)
  unset(LIBCLANG_INCLUDE_DIR CACHE)
  unset(LIBCLANG_FOUND CACHE)

  execute_process(COMMAND ${CLANG_BINARY} --version
  OUTPUT_VARIABLE clang_version_output OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(REGEX MATCH "clang version ([0-9.]+)" clang_version ${clang_version_output})
  set(clang_version ${CMAKE_MATCH_1})
  message("clang version = ${clang_version}")
  string(REGEX MATCH "InstalledDir: (.*)$" clang_install_dir ${clang_version_output})
  set(clang_install_dir ${CMAKE_MATCH_1} CACHE PATH "clang install dir")
  message("clang install dir = ${clang_install_dir}")

  find_library(LIBCLANG NAMES "libclang" PATHS "{clang_install_dir}/" "{clang_install_dir}/.." "{clang_install_dir}/../lib")

  set(LIBCLANG_INCLUDE_DIR "${clang_install_dir}/../include" CACHE PATH "libclang include dir")

  set(LIBCLANG_FOUND TRUE CACHE BOOL "libclang was found")
endfunction()



find_clang_binary()

if(CLANG_BINARY)
  find_libclang()
endif()

set(YASL_BUILD_WITH_LIBCLANG TRUE CACHE BOOL "Build yasl-meta with libclang")

if(LIBCLANG_FOUND AND YASL_BUILD_WITH_LIBCLANG)
  target_include_directories(yasl-meta PRIVATE ${LIBCLANG_INCLUDE_DIR})
  target_compile_definitions(yasl-meta PUBLIC -DYASL_META_HAS_LIBCLANG)
  target_link_libraries(yasl-meta ${LIBCLANG})
endif()
