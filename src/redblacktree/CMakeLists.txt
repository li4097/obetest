aux_source_directory(. DIR_RBT_SRC)

message(${PROJET_SOURCE_DIR}/utility)
include_directories(
	/usr/local/include
	${SRC_DIR}/utility
	)

link_directories(
	/usr/local/lib
	)

add_library(RBT SHARED ${DIR_RBT_SRC})
