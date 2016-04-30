//#include "hellomake.h"

#define cimg_display 0
#define cimg_use_png
#include "lib/CImg.h"
#import "Utility.h"
#import "DetectionManager.h"

using namespace cimg_library; 

int main() {
  // call a function in another file
  //myPrintHelloMake();
  //CImg<unsigned char> image = CImg("Test1.png");

  ImageData image = loadImage("Test1.png");


  printf("Loaded image!\n");



  return(0);
}