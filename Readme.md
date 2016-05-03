If artificialIntelligenceBenchmark already exists in build2 folder, no need to re-make it.


• Install libpng
• Install imagemagick
• Install GCC

I used brew to install libpng, imagemagick and GCC on Mac.


(Optional: Creating make files)
• Use the CMake application to create the make files

Running and compiling
• cd into build2
• make
• ./artificialIntelligenceBenchmark


The code is cross platform but we had trouble figuring out how to get libpng and imagemagick working in Visual Studio.