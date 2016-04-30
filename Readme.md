• Install libpng
• Install imagemagick

I used brew to install libpng and imagemagick on Mac.


Creating make files
• Use the CMake application to create the make files

Creating Xcode files
• Use CMake application to create Xcode files

Running cmake:
cd build
cmake .. && make

Running through make 
• make
• ./artificialIntelligenceBenchmark


Every time a new source file is added, need to update CMakeList and update make and xcode files.

Setting up make on windows:
Install Chocolately from website
Open administrator command prompt
Install mingw through chocolatey: choco install mingw
Run command:
setx PATH "%PATH%;C:\tools\mingw64\bin"
copy C:\tools\mingw64\bin\mingw32-make.exe C:\tools\mingw64\bin\make.exe

Install CMake : https://cmake.org/download/

Install libpng : http://downloads.sourceforge.net/gnuwin32/libpng-1.2.37-setup.exe