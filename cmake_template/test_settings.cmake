include( test_helpers.cmake )

enable_testing( ON )
INCLUDE(CTest)
add_custom_target( PUBLISH_TESTS 
				COMMAND ${CMAKE_CTEST_COMMAND} ${CMAKE_BINARY_DIR} --dashboard Experimental --output-on-failure --force-new-ctest-process
				WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
				)
