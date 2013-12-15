project( parser )
cmake_minimum_required(VERSION 2.8)

##########################################################################################
find_package(FLEX)
if( NOT FLEX_FOUND )
  message( FATAL_ERROR " Cannot find flex!" )
endif( NOT FLEX_FOUND )
##########################################################################################

##########################################################################################
find_package( BISON )
if( NOT BISON_FOUND )
  message( FATAL_ERROR " Cannot find bison!" )
endif( NOT BISON_FOUND )
##########################################################################################

##########################################################################################
set( Boost_USE_MULTITHREADED ON)
find_package( Boost COMPONENTS program_options unit_test_framework REQUIRED )
if( NOT Boost_FOUND )
  message( FATAL_ERROR " Cannot find boost!" )
endif( NOT Boost_FOUND )
include_directories( ${Boost_INCLUDE_DIRS} )
link_directories( ${Boost_LIBRARY_DIRS} )
##########################################################################################

add_definitions( -D_CRT_SECURE_NO_WARNINGS )

BISON_TARGET(CalcParser ${CMAKE_SOURCE_DIR}/calc.y ${CMAKE_SOURCE_DIR}/calc_parser.cpp)
FLEX_TARGET(CalcScanner ${CMAKE_SOURCE_DIR}/calc.lex  ${CMAKE_SOURCE_DIR}/calc_lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(CalcScanner CalcParser)

add_executable(calc
  calc.cpp
  
  calc_driver.hpp
  calc_driver.cpp
  
  calc.lex
  calc.y
  ${BISON_CalcParser_OUTPUTS}
  ${FLEX_CalcScanner_OUTPUTS}
)
