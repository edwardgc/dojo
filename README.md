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
    * mingw32-make SHELL=CMD.exe -f makefile.gcc CXXFLAGS="-std=gnu++1y" MONOLITHIC=1 SHARED=1 UNICODE=1 BUILD=release

