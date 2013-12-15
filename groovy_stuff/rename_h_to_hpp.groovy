import static groovy.io.FileType.*;
import static groovy.io.FileVisitResult.*;

def renamedFiles = [];

new File( "." ).traverse(
	type         : FILES,
	postRoot     : true,
	preDir       : { if (it.name == '.svn') return SKIP_SUBTREE },
	nameFilter   : ~/^.+\.h$/,
	excludeFilter: ~/.*include.*/ ){ file->
	def newPath = file.path.replaceAll( /^(.*)\.h$/, { m->
		m[1] + ".hpp"
	} )
	renamedFiles.add( [ old:file.path, new:newPath] )
}

reader = new InputStreamReader(System.in);

renamedFiles.each( { renaming->
	println( "Rename ${renaming.old} to ${renaming.new}?" )
	if ( reader.readLine() == "y" ) {
		println "renaming..."
	}
} )