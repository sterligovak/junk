def size = 0;
def numFiles = 0;
new File( "." ).traverse( nameFilter   : ~/.*\.svn.*/ ){ file->
		size += file.size()
		++numFiles
	}

println "SVN uses ${size>>20}MB (${numFiles} files)"