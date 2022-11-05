cmake_minimum_required(VERSION 3.1...3.16)

# set the project name and version
project(SimpleRV VERSION 1.0)

set(LINKER_SCRIPT "${PROJECT_SOURCE_DIR}/link/link.ld")
set(CMAKE_C_COMPILER /opt/riscv/bin/riscv64-unknown-linux-gnu-gcc)
set(CMAKE_C_FLAGS "-march=rv64imfd -nostdlib -mabi=lp64 -nostartfiles -static -T${LINKER_SCRIPT}")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

#target_link_libraries(
#	${PROJECT_SOURCE_DIR}/link/link.ld
#)

configure_file(
	${PROJECT_SOURCE_DIR}/include/SimpleRVConfig.h.in
	${PROJECT_BINARY_DIR}/include/SimpleRVConfig.h
)

# The compiled library code is here
add_subdirectory(src)

add_executable(SimpleRV
	${PROJECT_SOURCE_DIR}/src/simple_rv.h
	${PROJECT_SOURCE_DIR}/src/simple_rv.c
	${PROJECT_SOURCE_DIR}/link/link.ld
)

#install(FILES ${PROJECT_SOURCE_DIR}/link/link.ld DESTINATION link/)

set_source_files_properties(
	${PROJECT_SOURCE_DIR}/src/simple_rv.c
	PROPERTIES LANGUAGE "C")

target_include_directories(SimpleRV  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(SimpleRV  PUBLIC ${PROJECT_BINARY_DIR}/include)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
