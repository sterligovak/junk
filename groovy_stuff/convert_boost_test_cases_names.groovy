import static groovy.io.FileType.*;
import static groovy.io.FileVisitResult.*;

new File( "." ).traverse(
	type         : FILES,
	postRoot     : true,
	preDir       : { if (it.name == '.svn') return SKIP_SUBTREE },
	nameFilter   : ~/^.+\.cpp$/ ){ file->
	
	// replace test suite names
	fileContent = file.getText().replaceAll( ~/(BOOST_.+_TEST_SUITE)\(\s*([^\s,\)]+)(.*)/, { m->
		println( "${m[2]}" )
		"${m[1]}( ${CamelCaseToUnderscore(m[2])}${m[3]}"
	} )
	
	// replace test case names
	fileContent = fileContent.replaceAll( /(BOOST_.*_TEST_CASE)\(\s*([^\s,\)]+)(.*)/, { m->
		println( "\t${m[2]}" )
		"${m[1]}( ${CamelCaseToUnderscore(m[2])}${m[3]}"
	} )
	
	file.setText( fileContent )
}

def CamelCaseToUnderscore( name ){
	name = name[0].toLowerCase() + name.substring( 1, name.length() )
	return name.replaceAll( /\p{Upper}/, {
		"_" + it[0].toLowerCase()
	} )
}
