
def className = args[0]
def withTests = false
if( args.size() > 1 )
{
	withTests= (args[1] == "tests")
}

def filename = CamelToFilename( className )

def projectName = "streaming_system"
def cmakeFile = "CMakeLists.txt"
def testsSubdir = "tests\\"

def header = filename + ".hpp"
def cpp = filename + ".cpp"
def testCpp = filename + "_tests.cpp"

CreateHeaderFile( header, projectName, className )
CreateCppFile( cpp, header, projectName )
RegisterInCMake( cmakeFile, projectName, header, cpp )

if ( withTests ){
	CreateTestFile( testsSubdir + testCpp, className, header, projectName )
	RegisterInTestCMake( testsSubdir + cmakeFile, projectName + "_tests", testCpp )
}

def CamelToFilename( className ){
	def filename = className
	filename = filename[0].toLowerCase() + filename.substring( 1, filename.length() )
	return filename.replaceAll( /\p{Upper}/, {
		"_" + it[0].toLowerCase()
	} )
}

def CreateHeaderFile( header, projectName, className ){
	new File( header ).withWriter( { w->
		uuid =  "_" + UUID.randomUUID().toString().replaceAll( /-/, "_" )
		
		w.writeLine( "#pragma once" )
		w.writeLine( "#ifndef ${uuid}" )
		w.writeLine( "#define ${uuid}" )
		w.newLine()
		w.writeLine( "#include <boost/noncopyable.hpp>" )
		w.newLine()
		w.writeLine( "namespace mia" )
		w.writeLine( "{" )
		w.writeLine( "namespace ${projectName}" )
		w.writeLine( "{" )
		w.newLine()
		w.writeLine( "    class ${className} : boost::noncopyable" )
		w.writeLine( "    {" )
		w.writeLine( "    public:" )
		w.writeLine( "        virtual ~${className}()" )
		w.writeLine( "        {" )
		w.writeLine( "        }" )
		w.newLine()
		w.writeLine( "    };" )
		w.newLine();
		w.writeLine( "}" )
		w.writeLine( "}" )
		w.newLine()
		w.writeLine( "#endif /* ${uuid} */ " )
		w.newLine()
	} )
	println "${header} created"
}

def CreateCppFile( cpp, header, projectName ){
	new File( cpp ).withWriter( { w->
		w.writeLine( "#include \"${header}\"" )
		w.writeLine( "" )
		w.writeLine( "using namespace mia;" );
		w.writeLine( "using namespace ${projectName};" );
		w.newLine()
	} )
	println "${cpp} created"
}

def RegisterInCMake( cmakeFile, projectName, header, cpp ){
	cmakeFile = new File( cmakeFile )
	cmakeText = cmakeFile.getText().replaceFirst( /add_library\(\s*${projectName}/, 
						"add_library( ${projectName}\n\n    ${header}\n    ${cpp}" )
	cmakeFile.write( cmakeText )
	println "${header} and ${cpp} registered in ${projectName} project"  
}

def CreateTestFile( testCpp, className, header, projectName ){
	new File( testCpp ).withWriter( { w->
		w.writeLine( "#include <boost/test/unit_test.hpp>" )
		w.newLine()
		w.writeLine( "#include \"../${header}\"")
		w.newLine()
		w.writeLine( "using namespace mia;" )
		w.writeLine( "using namespace ${projectName};" )
		w.newLine()
		w.writeLine( "BOOST_AUTO_TEST_SUITE( ${className}TestSuite )" )
		w.newLine()
		w.writeLine( "BOOST_AUTO_TEST_CASE( Test )" )
		w.writeLine( "{" )
		w.writeLine( "}" )
		w.newLine()
		w.writeLine( "BOOST_AUTO_TEST_SUITE_END()" )
	} )
	println( "${testCpp} created" )
}

def RegisterInTestCMake( cmakeFile, projectName, testCpp ){
	cmakeTestFile = new File( cmakeFile )
	cmakeTestText = cmakeTestFile.getText().replaceAll( /add_boost_test_suite\(\s*${projectName}\s+(\p{Digit}+)/,{
														"add_boost_test_suite( $projectName ${it[1]}\n    ${testCpp}" 
						} )
	cmakeTestFile.write( cmakeTestText )
	println "${testCpp} registered in ${projectName} test project"  
}

