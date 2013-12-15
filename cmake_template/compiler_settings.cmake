
if( WIN32 )
	add_definitions( -D_WIN32_WINNT=0x0501 )
endif( WIN32  )	

if( MSVC )
    add_definitions( /MT )
    add_definitions( /W4 )
    add_definitions( -DNOMINMAX )
    add_definitions( /EHa ) # prevents warning from boost execution monitor
    add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif( MSVC )

if( MINGW )
	add_definitions ( "/MP$ENV{NUMBER_OF_PROCESSORS}" )
	add_definitions( -Wall -Wno-shadow -Wno-non-virtual-dtor )
endif( MINGW )
