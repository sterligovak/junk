
set(CPACK_PACKAGE_NAME "Riffle")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Riffle")

set(CPACK_PACKAGE_VENDOR "Riffle")

set(CPACK_PACKAGE_INSTALL_DIRECTORY "Riffle")

set( CPACK_PACKAGE_VERSION_MAJOR ${Hamster_VERSION_MAJOR} )
set( CPACK_PACKAGE_VERSION_MINOR ${Hamster_VERSION_MINOR} )
set( CPACK_PACKAGE_VERSION_PATCH ${Hamster_VERSION_PATCH})
set(CPACK_PACKAGE_FILE_NAME "Hamster-${CMAKE_SYSTEM_NAME}${CMAKE_SYSTEM_VERSION}-${CMAKE_SYSTEM_PROCESSOR}-${Riffle_VERSION}-${CMAKE_BUILD_TYPE}")

#set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}\\\\Riffle.ico" )
#set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}\\\\Riffle.ico" )
#nstall( FILES Riffle.ico DESTINATION . )

set( CPACK_PACKAGE_EXECUTABLES "Riffle;Riffle" )

include(InstallRequiredSystemLibraries)
include(CPack)

cpack_add_component_group( Runtime 
						DISPLAY_NAME Runtime
						DESCRIPTION "Riffle"
						EXPANDED 
						BOLD_TITLE
						)
						
cpack_add_component_group( Development 
						DISPLAY_NAME Development
						DESCRIPTION "Development tools"
						EXPANDED 
						)
						
cpack_add_component( Hamster
					DISPLAY_NAME "Riffle application"
					DESCRIPTION "Riffle application"
					GROUP "Runtime"
					)

cpack_add_component( tests
					DISPLAY_NAME "Tests"
					DESCRIPTION "Riffle's tests"
					GROUP "Development"
					)
