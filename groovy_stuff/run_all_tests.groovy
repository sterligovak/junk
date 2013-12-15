import static groovy.io.FileType.*;

new File( "tests.log" ).withWriterAppend({w->
	int testCounter = 0
	int failureCounter = 0;

	w.writeLine( "---------------------------------------" )
	w.writeLine( "${new Date().getDateTimeString()}:" )
	
	new File( "." ).traverse(
		type         : FILES,
		postRoot     : true,
		nameFilter   : ~/^.+tests\.exe$/ ){file->
			ant = new AntBuilder()
			ant.exec(executable: file.path,
					outputproperty:"cmdOut",
					errorproperty: "cmdErr",
					resultproperty:"cmdExit" )
					
			if( (ant.project.properties.cmdErr =~ /No\serrors\sdetected/).count == 0 ){
				w.writeLine( ant.project.properties.cmdErr )
			}
				
			m = (ant.project.properties.cmdErr =~ /(\d+) failures detected/)
			if( m.count > 0 ) {			
				failureCounter += m[0][1].toInteger();
			}
			
			m = ( ant.project.properties.cmdOut =~ /Running\s(\d+)\stest\scases/ )
			testCounter += m[0][1].toInteger()
	}
	
	
	w.newLine();
	w.writeLine( "${testCounter} tests executed" );
	w.writeLine( "${failureCounter} failures found" );
	w.writeLine( "---------------------------------------" )
	
	println( "${testCounter} tests executed" )
	println( "${failureCounter} failures found" )
} )