aux_source_directory(. DIR_UTILITY_SRC)

include_directories(
	/usr/local/include
	${SRC_DIR}/utility
	)

link_directories(
	/usr/local/lib
	)

add_library(Utility SHARED ${DIR_UTILITY_SRC})
