
set(YASL_BUILD_GEN_TOOL FALSE CACHE BOOL "Check if you want to build the binding yasl-meta")

if(YASL_BUILD_GEN_TOOL)
add_subdirectory(meta)
endif()

add_subdirectory(stats)