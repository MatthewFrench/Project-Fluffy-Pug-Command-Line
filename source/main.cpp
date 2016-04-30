//#include "hellomake.h"

#define cimg_display 0
//#define cimg_use_png
#include "lib/CImg.h"
#import "Utility.h"
#import "Detection/DetectionManager.h"

using namespace cimg_library; 

int main() {
  // call a function in another file
  //myPrintHelloMake();
  //CImg<unsigned char> image("Test1.png");

  ImageData image = loadImage("Test1.png");

//printf("Spectrum: %d\n", image.spectrum());

//  printf("Loaded image! %d, %d, %d, %d\n", image.atXY(0, 0, 0), image.atXY(0, 0, 1), image.atXY(0, 0, 2), image.atXY(0, 0, 3));

    DetectionManager* detection = new DetectionManager();

    detection.processDetection(image);

    printf("Finished detection!\n");

  return(0);
}