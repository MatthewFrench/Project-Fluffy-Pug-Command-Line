TODO:
	• Fix self health bar not detecting
	• Fix percentage match displaying
	• Put it back in Xcode and run
	• Make it run on Windows
	• Add memory management code

END TODO

5.6 times faster

New Code with OpenMP on GCC compiler : 0.0883386 seconds
Old code full screen serial on GCC compiler: 0.49335 seconds

New Code with Grand Central Dispatch on Clang : 0.125543 seconds
Old Code full screen scan serial on Clang : 0.391021 seconds




New Code In the AI takes 0.23 seconds on a single core

Time on Fluffy Pug: 0.38 seconds
Scanning full screen with grand central dispatch but uses full CPU

Time on Fluffy Pug is: 0.040749 seconds
That's only scanning 1/60th of the screen.

4 core machine

Getting 0.095 seconds but only using 2 cores. Full screen scanning.

Replacing struct pass with pointer pass: 0.106355

Pulling the heavy detection out of separate functions: 0.110222

Using small pixel increment optimization: 0.136431

Using 256 threads: 0.148011
Using 128 threads: 0.14607
Using 64 threads: 0.146292
Using 32 threads: 0.146848
Using 16 threads: 0.147312
Using 8 threads : 0.149097
Using 7 threads : 0.150353
Using 6 threads : 0.149025
Using 5 threads : 0.1542
Using 4 threads on OpenMP down to 0.162659 seconds

Now down to 0.27 seconds from basic loop optimization

USING -Ofast makes it go from 0.9 seconds to 0.37 seconds
Using -03 makes it 0.42 seconds
Using -02 makes it 0.40 seconds
Using -O1 makes it 0.539053 seconds
Using -O0 makes it 0.909023 seconds


• Install libpng
• Install imagemagick

On Mac install clang-omp using brew.
When running CMake, set the compiler to the clang-omp. /usr/local/Cellar/clang-omp/2015-04-01

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
	• Make it output 2 result images, one with image highlighting objects it sees and the other black with only highlighting areas it sees
	• Make it more accurate, it seems off
	• Increase speed from 0.9 seconds to 0.05 seconds
	• Parallelize it with OpenMP


Detection times for functions:
1: 0.03624
2: 0.038837
3: 0.175876
4: 0.167454
5: 0.195984
6: 0.189339
7: 0.126035
8: 6.3e-05
9: 0.000252
10: 4.4e-05
11: 6.3e-05
12: 5.8e-05
13: 2.1e-05
14: 0.001172
15: 0
16: 0
17: 9.2e-05
18: 3.9e-05
19: 5e-05
20: 8e-06
21: 0.00041