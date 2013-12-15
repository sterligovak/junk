sourceFiles = new FileNameByRegexFinder().getFileNames( ".", /^.*\.(java)$/ )

int numLines = 0

sourceFiles.each( { filename ->
	new File( filename ).eachLine( { line ->
		if ( line !=~ /^[ 	]*$/ )
			++numLines
	} )
} )
println "Totally ${numLines} non-empty lines"
