# Functions that are used for automatic version contol

# Sets major and minor version. Creates version file if needed
# VERSION_FILE - path to the file which will save the current version
# MAJOR - major version of the software
# MINOR - major version of the software
macro( set_major_minor_version VERSION_FILE MAJOR MINOR )
  IF( EXISTS ${VERSION_FILE} )
    # set new major/minor version if needed
    file( STRINGS ${VERSION_FILE} VERSION_NUMBER_STRING
	    REGEX "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" )
	string( REGEX MATCH "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" ${VERSION_NUMBER_STRING} ${VERSION_NUMBER_STRING} )
    IF( ${CMAKE_MATCH_1} EQUAL ${MAJOR} AND ${CMAKE_MATCH_2} EQUAL ${MINOR} )
	  #do nothing
    ELSE( ${CMAKE_MATCH_1} EQUAL ${MAJOR} AND ${CMAKE_MATCH_2} EQUAL ${MINOR} )
      file( WRITE ${VERSION_FILE} "${MAJOR}.${MINOR}.0.0.0" )
    ENDIF( ${CMAKE_MATCH_1} EQUAL ${MAJOR} AND ${CMAKE_MATCH_2} EQUAL ${MINOR} )
  ELSE( EXISTS ${VERSION_FILE} )
    file( WRITE ${VERSION_FILE} "${MAJOR}.${MINOR}.0.0.0" )
  ENDIF( EXISTS ${VERSION_FILE} )
endmacro( set_major_minor_version )

# update revision version number
# VERSION_FILE - path to the file which will save the current version
# SOURCE_DIR - path to the source repository to get revition from
macro( update_revision_version VERSION_FILE SOURCE_DIR )
  # get revision number
  FIND_PACKAGE(Subversion)
  IF(Subversion_FOUND)
    Subversion_WC_INFO(${SOURCE_DIR} Riffle)
  ELSE( Subversion_FOUND )
    MESSAGE( STATUS "Subversion was not found" )
	set( Riffle_WC_REVISION 0 )
  ENDIF(Subversion_FOUND)
  file( STRINGS ${VERSION_FILE} VERSION_NUMBER_STRING
	    REGEX "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" )
  string( REGEX MATCH "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" ${VERSION_NUMBER_STRING} ${VERSION_NUMBER_STRING} )
  if( ${CMAKE_MATCH_3} EQUAL ${Riffle_WC_REVISION} )
  else( ${CMAKE_MATCH_3} EQUAL ${Riffle_WC_REVISION} )
    file( WRITE ${VERSION_FILE} "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${Riffle_WC_REVISION}.0.0" )
  endif( ${CMAKE_MATCH_3} EQUAL ${Riffle_WC_REVISION} )
  #message( INFO " Revision number: ${Riffle_WC_REVISION}" )
endmacro( update_revision_version )

# update configuration version number
# VERSION_FILE - path to the file which will save the current version
macro( update_configuration_version VERSION_FILE )
  file( STRINGS ${VERSION_FILE} VERSION_NUMBER_STRING
	    REGEX "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" )
  string( REGEX MATCH "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" ${VERSION_NUMBER_STRING} ${VERSION_NUMBER_STRING} )
  math(EXPR CONFIGURATION_NUMBER "${CMAKE_MATCH_4} + 1" )
  file( WRITE ${VERSION_FILE} "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${CMAKE_MATCH_3}.${CONFIGURATION_NUMBER}.0" )
  #message( INFO " Configuration number: " ${CONFIGURATION_NUMBER} )
endmacro( update_configuration_version )

# update build version number
# VERSION_FILE - path to the file which will save the current version
macro( update_build_version VERSION_FILE )
  file( STRINGS ${VERSION_FILE} VERSION_NUMBER_STRING
	    REGEX "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" )
  string( REGEX MATCH "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" ${VERSION_NUMBER_STRING} ${VERSION_NUMBER_STRING} )
  math(EXPR BUILD_NUMBER "${CMAKE_MATCH_5} + 1" )
  file( WRITE ${VERSION_FILE} "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${CMAKE_MATCH_3}.${CMAKE_MATCH_4}.${BUILD_NUMBER}" )
  #message( INFO " Build number: " ${BUILD_NUMBER} )
endmacro( update_build_version )

# Register special target which uses CMake script to update build version number by update_build_version.
# Without such registration update_build_version won't be executed at every build
# VERSION_FILE - path to the file which will save the current version
# HEADER_FILE - file in which sources of the version number is stored
macro( register_update_build_version VERSION_FILE HEADER_FILE )
  #execute script at the build time
  add_custom_target( UPDATE_VERSION ALL
					COMMAND ${CMAKE_COMMAND}
							-DVERSION_FILE:FILEPATH=${VERSION_FILE}
							-DSOURCE_DIR:FILEPATH=${PROJECT_SOURCE_DIR}
							-DBINARY_DIR:FILEPATH=${CMAKE_BINARY_DIR}
							-DHEADER_FILE:FILEPATH=${HEADER_FILE}
							-DCMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}
							-DCMAKE_SYSTEM_VERSION=${CMAKE_SYSTEM_VERSION}
							-DCMAKE_SYSTEM_PROCESSOR=${CMAKE_SYSTEM_PROCESSOR}
							-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
							-P version/update_build_version.cmake 
					WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} )
endmacro( register_update_build_version )

#creates C++ file which contains constant with version number
macro( create_version_header VERSION_FILE HEADER_FILE )
  file( STRINGS ${VERSION_FILE} VERSION_NUMBER_STRING
	    REGEX "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" )
  file( WRITE ${HEADER_FILE} "#ifndef RIFFLE_VERSION\n"
							"#define RIFFLE_VERSION \"${VERSION_NUMBER_STRING}\"\n"
							"#endif\n" )
endmacro( create_version_header )

# creats variables Riffle_VERSION, Riffle_VERSION_MAJOR, Riffle_VERSION_MINOR, Riffle_VERSION_PATCH 
# which has version number of the project
macro( get_version VERSION_FILE )
  file( STRINGS ${VERSION_FILE} Riffle_VERSION
	    REGEX "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" )
		
  string( REGEX MATCH "^([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)\\.([1234567890]+)$" ${Riffle_VERSION} ${Riffle_VERSION} )
  
  set( Riffle_VERSION_MAJOR ${CMAKE_MATCH_1} )
  set( Riffle_VERSION_MINOR ${CMAKE_MATCH_2} )
  set( Riffle_VERSION_PATCH ${CMAKE_MATCH_3} )
endmacro( get_version )

	
	