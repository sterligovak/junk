project( gperf_template )
cmake_minimum_required(VERSION 2.8)

macro( GPERF_TARGET TARGET_NAME GPERF_INPUT GPERF_OUTPUT )
	find_program( GRPERF_EXE gperf )
	if( NOT GRPERF_EXE )
		message( FATAL_ERROR "Cannot find gperf" )
	endif( NOT GRPERF_EXE )
	
	add_custom_command( OUTPUT ${GPERF_OUTPUT}
						COMMAND ${GRPERF_EXE}
						ARGS -L C++ ${GPERF_INPUT} --output-file=${GPERF_OUTPUT}
						DEPENDS ${GPERF_INPUT}
						COMMENT "[GPERF][${TARGET_NAME}] Building hash table with gperf"
						WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
						)
endmacro( GPERF_TARGET GPERF_INPUT GPERF_OUTPUT )

GPERF_TARGET( months months.gperf ${CMAKE_CURRENT_SOURCE_DIR}/months.cpp )
add_executable( months 
				months.gperf
				${CMAKE_CURRENT_SOURCE_DIR}/months.cpp )