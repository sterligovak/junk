option( PROFILING "Enable profiling" ON )

if( NOT PROFILING )
	macro( profile TARGET_NAME )
	endmacro( profile )
endif( NOT PROFILING )

if( PROFILING )
	if( MINGW )
		add_definitions( -g -pg -O0 -fprofile-arcs -ftest-coverage )
		set( CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-pg -lgmon -fprofile-arcs -ftest-coverage" )
		
		macro( profile TARGET_NAME )	
			add_custom_command( TARGET ${TARGET_NAME}
							POST_BUILD 
							COMMAND ${TARGET_NAME}
							WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
							COMMENT "Running ${TARGET_NAME} for profiling" )
			get_target_property( EXECUTABLE_PATH ${TARGET_NAME} LOCATION )
			add_custom_command( TARGET ${TARGET_NAME}
							POST_BUILD 
							COMMAND gprof ${EXECUTABLE_PATH}>${TARGET_NAME}_profiling_results.txt
							WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
							COMMENT "Profiling ${TARGET_NAME}" )
		endmacro( profile )
	endif( MINGW )
	
	if( MSVC )
		macro( profile TARGET_NAME )
			# don't know how to do it
		endmacro( profile )
	endif( MSVC )
endif( PROFILING )

