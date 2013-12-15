for( i in 0..9 )
{
    new BoostBuildTimeBenchmark().run()
}

class BoostBuildTimeBenchmark
{
    //def buildOptions =  "-j8 toolset=msvc --build-type=complete --layout=tagged"
    def buildOptions =  "-j8 toolset=msvc --with-math --layout=tagged"

    def run(){
        println "Cleaning..." 
        clean();
        println "done"
        
        print "Building..."
        def buildTime = benchmark( {
            new AntBuilder().exec(executable: "bjam", outputproperty: "") {
                arg(line:buildOptions)
            }
        } )
        println "done"
        
        saveResults( buildTime, "boost_build_stats.txt" );
    }

    def clean(){
        new AntBuilder().sequential {
            exec(executable: "bjam", outputproperty: "") {
                arg(line:"--clean")
            }
            delete(dir: "stage")
            delete(dir: "bin.v2")
        }
    }

    def benchmark( closure ) {
        def start = System.currentTimeMillis()
        closure()
        def now = System.currentTimeMillis()  
        return now - start
    }

    def saveResults( time, fileName ){
        new File( fileName ).withWriterAppend({ w->
            w.writeLine( buildOptions )
            w.writeLine( "${time/1000} seconds" )
            w.writeLine( "---------------------------------------" )
        } )
    }
}
