
set(GTEST_DIR "" CACHE PATH "Root directory for GoogleTest")

enable_testing()

add_executable(tests test_binding.cpp test_core.cpp test_widgets.cpp ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc)
add_dependencies(tests libyasl)
target_include_directories(tests PUBLIC "${GTEST_DIR}/include")
target_include_directories(tests PRIVATE "${GTEST_DIR}")
target_include_directories(tests PUBLIC "../include")
target_link_libraries(tests libyasl)

file(GLOB_RECURSE YASL_TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.y")
file(COPY ${YASL_TEST_FILES} DESTINATION ${CMAKE_BINARY_DIR})

add_test(Tests tests)

set_target_properties(tests PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")