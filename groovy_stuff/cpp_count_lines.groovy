sourceFiles = new FileNameByRegexFinder().getFileNames( ".", /^.*\.(cpp|cxx|ñ|hpp|hxx|h)$/ )

int headerLines = 0;
int cppLines = 0;

largestHeader = ["name":"", "length":0]
largestCpp = ["name":"", "length":0]

sourceFiles.each( { filename ->

	int fileLines = 0

	new File( filename ).eachLine( { line ->
		if ( line !=~ /^[ 	]*$/ )
			++fileLines
	} )
	
	if( filename ==~ /^.*\.(hpp|hxx|h)$/ ) {
		if( fileLines > largestHeader.length ){
			largestHeader.length = fileLines
			largestHeader.name = filename
		}
		headerLines += fileLines
	} else { 
		if( fileLines > largestCpp.length ){
			largestCpp.length = fileLines
			largestCpp.name = filename
		}
		cppLines += fileLines
	}

} )

println "${sourceFiles.size()} files processed";
println ""
println "Largest header:"
println "${largestHeader.name} ${largestHeader.length} lines"
println ""
println "Largest cpp:"
println "${largestCpp.name} ${largestCpp.length} lines"
println ""
println "${headerLines} header lines"
println "${cppLines} cpp lines"
println "Totally ${headerLines + cppLines} non-empty lines"
