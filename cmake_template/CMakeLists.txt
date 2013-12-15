cmake_minimum_required( VERSION 2.8 )
cmake_policy( VERSION 2.8 )
project( Riffle )

include( compiler_settings.cmake )
include( test_settings.cmake )
include( third_parties.cmake )
include( profiling_settings.cmake )
include( version/update_version.cmake )

include_directories( ${CMAKE_SOURCE_DIR} ) 

add_subdirectory( version )

include( installation.cmake )
