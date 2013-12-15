VERSION.txt is file that contains information about current source and build version.
It has forman v.w.x.y.x
v - major number (specified by user)
w - minor number (specified by user)
x - svn revision number (filled automatically at every revision change)
y - configuration number (automatically filled every time CMake files changed)
z - build number (automatically filled every build)

In every build version number is updated if needed.

version_number.h contains macros definitions which is used for version library creation. Version library is used to check print unique versions of the executables.