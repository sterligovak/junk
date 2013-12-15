include( version/version_helpers.cmake )

set( Riffle_VERSION_FILE "${CMAKE_SOURCE_DIR}/version/VERSION.txt" )

set_major_minor_version( ${Riffle_VERSION_FILE} 0 0 )

update_configuration_version( ${Riffle_VERSION_FILE} )
update_revision_version( ${Riffle_VERSION_FILE} ${Riffle_SOURCE_DIR} )

create_version_header( ${Riffle_VERSION_FILE} "${Riffle_SOURCE_DIR}/version/version_number.h" )

register_update_build_version( ${Riffle_VERSION_FILE} "${Riffle_SOURCE_DIR}/version/version_number.h" )

get_version( ${Riffle_VERSION_FILE} )
