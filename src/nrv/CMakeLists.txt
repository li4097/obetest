aux_source_directory(. DIR_NRV_SRC)

include_directories(
	/usr/local/include
	${SRC_DIR}/utility
	)

link_directories(
	/usr/local/lib
	)

if(USE_NRV)
	add_definitions(-DUSE_NRV)
	message("#$##### use")
endif(USE_NRV)
add_library(Nrv SHARED ${DIR_NRV_SRC})
