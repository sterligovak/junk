
def excludePattern = /.*include.*/;

headerLines = CountLines(/.*\.(hpp)$/, excludePattern )
cppLines = CountLines(/.*\.(cpp)$/, excludePattern )
cmakeLines = CountLines(/.*\.(txt|cmake)$/, excludePattern )

println "${headerLines} header lines"
println "${cppLines} cpp lines"
println "${cmakeLines} cmake lines"
println "totally ${headerLines + cppLines + cmakeLines} lines"

def CountLines( fileNameRegex, excludeRegex ){
	def lineCount = 0;
	new File( "." ).traverse(
		nameFilter   : ~fileNameRegex,
		excludeFilter: ~excludeRegex ){ file->
			file.eachLine({ line->
				if ( line ==~ /^\s*(\S+\s*)+$/ ) {
					++lineCount;
				}
			} )
	}
	return lineCount;
}