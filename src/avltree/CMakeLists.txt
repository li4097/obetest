aux_source_directory(. DIR_AVLT_SRC)

message(${PROJET_SOURCE_DIR}/utility)
include_directories(
	/usr/local/include
	${SRC_DIR}/utility
	${SRC_DIR}/binarytree
	)

link_directories(
	/usr/local/lib
	)

add_library(AvlT SHARED ${DIR_AVLT_SRC})
