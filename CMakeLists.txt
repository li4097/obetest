cmake_minimum_required(VERSION 2.8)
project(ObjTest)


configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)

#option(USE_NRV "use named return value" ON)

#if (USE_NRV)
#	add_definitions(-DUSE_NRV)
#	message("--------use nrv")
#else()
#	message("-------- no nrv")
#endif(USE_NRV)

#set(CMAKE_BUILE_TYPE DEBUG)
#set(CMAKE_BUILE_TYPE RELEASE)
#set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
#set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_CXX_COMPILER g++)
add_compile_options(-std=c++11 -g -Wall)
#add_compile_options(-std=c++11)
#set(CMAKE_CXX_STANDARD 11)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#add_executable(test main.cpp utility.cpp utility.h)

#aux_source_directory(${SRC_DIR} DIR_SRCS)

add_subdirectory( ${SRC_DIR}/utility)
add_subdirectory( ${SRC_DIR}/nrv)
add_subdirectory( ${SRC_DIR}/binarytree)
add_subdirectory( ${SRC_DIR}/avltree)

include_directories(
	${SRC_DIR}/utility
	${SRC_DIR}/nrv
	${SRC_DIR}/binarytree
	${SRC_DIR}/avltree
	)

add_executable(main ${SRC_DIR}/main.cpp)
target_link_libraries(main Utility Nrv BiT AvlT)
#link_directories(${LIBRARY_OUTPUT_PATH})
