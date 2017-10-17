# dojo

**Tools directory**:

* c:\tools\mingw64
    * It's not must here, just keep bin directory in PATH environment.
* c:\tools\boost
    * bootstrap gcc
    * .\b2 --build-type=minimal toolset=gcc
* c:\tools\googletest
    * cd C:\tools\googletest\googlemock\make
    * mingw32-make
* C:\tools\wxWidgets
    * cd C:\tools\wxWidgets\build\msw
    * mingw32-make CXXFLAGS="-std=gnu++1y" -f makefile.gcc MONOLITHIC=1 BUILD=debug UNICODE=1 SHARED=0
    
    
