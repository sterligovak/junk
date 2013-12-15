add_library( version
			version.h
			version.cpp )
add_dependencies( version UPDATE_VERSION )