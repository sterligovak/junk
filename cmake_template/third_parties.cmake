################################ BOOST ################################
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(Boost_ADDITIONAL_VERSIONS "1.43" "1.44" "1.45" "1.46")
find_package( Boost COMPONENTS date_time filesystem system thread unit_test_framework regex )
if( Boost_FOUND )
    include_directories( SYSTEM ${Boost_INCLUDE_DIRS} )
    link_directories( ${Boost_LIBRARY_DIRS} )
else( Boost_FOUND )
    message( FATAL_ERROR "Boost was not found" )
endif( Boost_FOUND )
#########################################################################