TODO:
	• Make it more accurate
	• Make it run on Windows
	• Increase speed from 0.9 seconds to 0.05 seconds
	• Parallelize it with OpenMP
	• Make it output 2 result images, one with image highlighting objects it sees and the other black with only highlighting areas it sees
	• Make it more accurate, it seems off

END TODO

USING -Ofast makes it go from 0.9 seconds to 0.37 seconds
Using -03 makes it 0.42 seconds
Using -02 makes it 0.40 seconds
Using -O1 makes it 0.539053 seconds
Using -O0 makes it 0.909023 seconds


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


Done:
	• Make it run all the tests and show average
	• Make it draw all the output