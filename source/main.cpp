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

    detection->processDetection(image);

    printf("Detected: \n");
    if (detection->getAllyMinions().size() > 0) {
    	printf("\t%lu ally minions\n", detection->getAllyMinions().size());
    }
    if (detection->getAllyChampions().size() > 0) {
    	printf("\t%lu ally champions\n", detection->getAllyChampions().size());
    }
    if (detection->getSelfChampions().size() > 0) {
    	printf("\t%lu self champions\n", detection->getSelfChampions().size());
    }
    if (detection->getEnemyMinions().size() > 0) {
    	printf("\t%lu enemy minions\n", detection->getEnemyMinions().size());
    }
    if (detection->getEnemyChampions().size() > 0) {
    	printf("\t%lu enemy champions\n", detection->getEnemyChampions().size());
    }
    if (detection->getEnemyTowers().size() > 0) {
    	printf("\t%lu enemy towers\n", detection->getEnemyTowers().size());
    }
    if (detection->getSelfHealthBarVisible()) {
    	printf("\tCan see self health bar\n");
    	printf("\tSelf health: %f\n", detection->getSelfHealthBar()->health);
    }
    if (detection->getSpell1LevelUpVisible()) {
    	printf("\tLevel up spell 1 available\n");
    }
    if (detection->getSpell2LevelUpVisible()) {
    	printf("\tLevel up spell 2 available\n");
    }
    if (detection->getSpell3LevelUpVisible()) {
    	printf("\tLevel up spell 3 available\n");
    }
    if (detection->getSpell4LevelUpVisible()) {
    	printf("\tLevel up spell 4 available\n");
    }
    if (detection->getCurrentLevel() > 0) {
    	printf("\tDetected current level: %d\n", detection->getCurrentLevel());
    }
    if (detection->getSpell1Available()) {
    	printf("\tSpell 1 available\n");
    }
    if (detection->getSpell2Available()) {
    	printf("\tSpell 2 available\n");
    }
    if (detection->getSpell3Available()) {
    	printf("\tSpell 3 available\n");
    }
    if (detection->getSpell4Available()) {
    	printf("\tSpell 4 available\n");
    }
    if (detection->getSummonerSpell1Available()) {
    	printf("\tSummoner spell 1 available\n");
    }
    if (detection->getSummonerSpell2Available()) {
    	printf("\tSummoner spell 2 available\n");
    }
    if (detection->getTrinketActiveAvailable()) {
    	printf("\tTrinket active available\n");
    }
    if (detection->getItem1ActiveAvailable()) {
    	printf("\tItem 1 active available\n");
    }
    if (detection->getItem2ActiveAvailable()) {
    	printf("\tItem 2 active available\n");
    }
    if (detection->getItem3ActiveAvailable()) {
    	printf("\tItem 3 active available\n");
    }
    if (detection->getItem4ActiveAvailable()) {
    	printf("\tItem 4 active available\n");
    }
    if (detection->getItem5ActiveAvailable()) {
    	printf("\tItem 5 active available\n");
    }
    if (detection->getItem6ActiveAvailable()) {
    	printf("\tItem 6 active available\n");
    }
    if (detection->getPotionActiveAvailable()) {
    	printf("\tPotion active available\n");

    	printf("\t\tPotion in slot %d\n", detection->getPotionActiveItemSlot());
    }
    if (detection->getPotionBeingUsedVisible()) {
    	printf("\tPotion being used\n");
    }
    if (detection->getShopAvailable()) {
    	printf("\tShop is available\n");
    }
    if (detection->getShopTopLeftCornerVisible()) {
    	printf("\tShop top left corner is visible\n");
    }
    if (detection->getShopBottomLeftCornerVisible()) {
    	printf("\tShop bottom left corner is visible\n");
    }
    if (detection->getBuyableItems().size() > 0) {
    	printf("\tBuyable items: %lu\n", detection->getBuyableItems().size());
    }
    if (detection->getMapVisible()) {
    	printf("\tMap is visible\n");
    }
    if (detection->getMapShopVisible()) {
    	printf("\tShop on map is visible\n");
    }
    if (detection->getMapLocationVisible()) {
    	printf("\tLocation on map is visible\n");
    }
    if (detection->getSurrenderAvailable()) {
    	printf("\tSurrender is visible\n");
    }
    printf("-------------------\n");
    printf("Finished detection!\n");

  return(0);
}