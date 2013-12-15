include ( version/version_helpers.cmake NO_POLICY_SCOPE )

update_build_version( ${VERSION_FILE} )
update_revision_version( ${VERSION_FILE} ${SOURCE_DIR} )
create_version_header( ${VERSION_FILE} ${HEADER_FILE} )

get_version( ${VERSION_FILE} )
message( INFO " ${Riffle_VERSION}" )

# update in the CPackConfig.cmake
#SET(CPACK_PACKAGE_FILE_NAME "Riffle-Windows5.1-x86-0.0.957.6.0-Debug")
set( NEW_INSTALLER_NAME "Riffle-${CMAKE_SYSTEM_NAME}${CMAKE_SYSTEM_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${Riffle_VERSION}-${CMAKE_BUILD_TYPE}")
set( SET_NEW_INSTALLER_NAME "SET(CPACK_PACKAGE_FILE_NAME ${NEW_INSTALLER_NAME})\n" )
file( APPEND ${BINARY_DIR}/CPackConfig.cmake ${SET_NEW_INSTALLER_NAME} )

