
#######
# Usage PIN_TARGET( MyPinTool <Sources> )
#
#
#######
macro( USE_PIN )
    set( PIN_ROOT "" CACHE PATH "Path to PIN directory" )
	
	set( PIN_INCLUDES_PATHS
		${PIN_ROOT}/source/include
		${PIN_ROOT}/source/include/gen
		${PIN_ROOT}/extras/components/include
		${PIN_ROOT}/extras/xed2-ia32/include
	)
	set( PIN_LIB_PATHS
		${PIN_ROOT}/ia32/lib
		${PIN_ROOT}/ia32/lib-ext
		${PIN_ROOT}/extras/xed2-ia32/lib
	)
	
	include_directories( ${PIN_INCLUDES_PATHS} )
	link_directories( ${PIN_LIB_PATHS} )
endmacro( USE_PIN )

macro( SET_PIN_FLAGS TARGET_NAME )
    if( MSVC )
        ########## compiler flags ##########
        set( PIN_COMMON_CXXFLAGS "/MT /EHs- /EHa- /wd4530 /DTARGET_WINDOWS /DBIGARRAY_MULTIPLIER=1 /DUSING_XED /D_CRT_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /D_ITERATOR_DEBUG_LEVEL=0" )
        set( PIN_IA32_CXXFLAGS  "/DTARGET_IA32 /DHOST_IA32" ) 	#ia32 architecture
        set( PIN_IA32E_CXXFLAGS "/DTARGET_IA32E /DHOST_IA32E" )	#intel64 architecture

        ########## linker flags ##########
        set( PIN_COMMON_LDFLAGS      "/DLL /EXPORT:main /NODEFAULTLIB" )
        set( PIN_IA32_LDFLAGS        "/MACHINE:x86 /ENTRY:Ptrace_DllMainCRTStartup@12 /BASE:0x55000000" ) #ia32 architecture
        set( PIN_IA32E_LDFLAGS       "/MACHINE:x64 /ENTRY:Ptrace_DllMainCRTStartup /BASE:0xC5000000" ) #intel64 architecture
        set( PIN_COMMON_LIBS         pin.lib libxed.lib libcpmt.lib libcmt.lib pinvm.lib kernel32.lib )
        set( PIN_IA32_LIBS           ntdll-32.lib ) #ia32 architecture
        set( PIN_IA32E_LIBS          ntdll-64.lib ) #ia32 architecture

        option( INTEL_64 "x86-64 build" )
        
        if( INTEL_64 )
          set( COMPILE_FLAGS "${PIN_COMMON_CXXFLAGS} ${PIN_IA32E_CXXFLAGS}" )			
          set( LINK_FLAGS "${PIN_COMMON_LDFLAGS} ${PIN_IA32E_LDFLAGS}" )
          set( PIN_LIBRARIES ${PIN_COMMON_LIBS} ${PIN_IA32E_LIBS} )
        else( INTEL_64 )
          set( COMPILE_FLAGS "${PIN_COMMON_CXXFLAGS} ${PIN_IA32_CXXFLAGS}" )			
          set( LINK_FLAGS "${PIN_COMMON_LDFLAGS} ${PIN_IA32_LDFLAGS}" )
          set( PIN_LIBRARIES ${PIN_COMMON_LIBS} ${PIN_IA32_LIBS} )
        endif( INTEL_64 )
    endif( MSVC )
	
	set_target_properties( ${TARGET_NAME}
							PROPERTIES 
								COMPILE_FLAGS ${COMPILE_FLAGS}
								LINK_FLAGS ${LINK_FLAGS}
						)
	target_link_libraries( ${TARGET_NAME} ${PIN_LIBRARIES} )
endmacro( SET_PIN_FLAGS )

macro( PIN_TARGET TARGET_NAME )
    set( ${TARGET_NAME}_SOURCES ${ARGN} )
    
	USE_PIN()
	
	add_library( ${TARGET_NAME} SHARED
				${${TARGET_NAME}_SOURCES} )
	SET_PIN_FLAGS( ${TARGET_NAME} )
	
endmacro( PIN_TARGET )