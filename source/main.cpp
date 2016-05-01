#define cimg_display 0
#define cimg_use_png
#include "lib/CImg.h"
#include "Utility.h"
#include "Detection/DetectionManager.h"

using namespace cimg_library; 

void printDetected(DetectionManager* detectionManager);
void outputImage(ImageData image, DetectionManager* detection);

int main() {
	ImageData image = loadImage("Test1.png");

	DetectionManager* detection = new DetectionManager();

	double simulation_time = read_timer( );

	detection->processDetection(&image);

	simulation_time = read_timer( ) - simulation_time;


	printDetected(detection);
	printf("-------------------\n");
	printf("Finished detection in %g seconds!\n", simulation_time);

	outputImage(image, detection);

	return(0);
}

void outputImage(ImageData image, DetectionManager* detectionManager) {
	CImg<unsigned char> render(image.imageWidth,image.imageHeight,1,4);

	render.fill(0);

	for (int i = 0; i < detectionManager->getAllyMinions()->size(); i++) {
		Minion* minion = (*(detectionManager->getAllyMinions()))[i];
		const unsigned char color[] = { 0,0,255, 255 };
		const unsigned char colorAlpha[] = { 0,0,255, 50 };
		render.draw_rectangle(minion->topLeft.x, minion->topLeft.y, minion->bottomRight.x, minion->bottomRight.y, colorAlpha);
 		render.draw_line(minion->topLeft.x, minion->topLeft.y, minion->topRight.x, minion->topRight.y,color);
 		render.draw_line(minion->bottomLeft.x, minion->bottomLeft.y, minion->bottomRight.x, minion->bottomRight.y,color);
 		render.draw_line(minion->topLeft.x, minion->topLeft.y, minion->bottomLeft.x, minion->bottomLeft.y,color);
 		render.draw_line(minion->topRight.x, minion->topRight.y, minion->bottomRight.x, minion->bottomRight.y,color);
	}

	for (int i = 0; i < detectionManager->getEnemyMinions()->size(); i++) {
		Minion* minion = (*(detectionManager->getEnemyMinions()))[i];
		const unsigned char color[] = { 255,0,0, 255 };
 		const unsigned char colorAlpha[] = { 255,0,0, 50 };
		render.draw_rectangle(minion->topLeft.x, minion->topLeft.y, minion->bottomRight.x, minion->bottomRight.y, colorAlpha);
 		render.draw_line(minion->topLeft.x, minion->topLeft.y, minion->topRight.x, minion->topRight.y,color);
 		render.draw_line(minion->bottomLeft.x, minion->bottomLeft.y, minion->bottomRight.x, minion->bottomRight.y,color);
 		render.draw_line(minion->topLeft.x, minion->topLeft.y, minion->bottomLeft.x, minion->bottomLeft.y,color);
 		render.draw_line(minion->topRight.x, minion->topRight.y, minion->bottomRight.x, minion->bottomRight.y,color);
	}

	for (int i = 0; i < detectionManager->getAllyChampions()->size(); i++) {
		Champion* champion = (*(detectionManager->getAllyChampions()))[i];
		const unsigned char color[] = { 0,0,255, 255 };
 		const unsigned char colorAlpha[] = { 0,0,255, 50 };
		render.draw_rectangle(champion->topLeft.x, champion->topLeft.y, champion->bottomRight.x, champion->bottomRight.y, colorAlpha);
 		render.draw_line(champion->topLeft.x, champion->topLeft.y, champion->topRight.x, champion->topRight.y,color);
 		render.draw_line(champion->bottomLeft.x, champion->bottomLeft.y, champion->bottomRight.x, champion->bottomRight.y,color);
 		render.draw_line(champion->topLeft.x, champion->topLeft.y, champion->bottomLeft.x, champion->bottomLeft.y,color);
 		render.draw_line(champion->topRight.x, champion->topRight.y, champion->bottomRight.x, champion->bottomRight.y,color);
	}

	for (int i = 0; i < detectionManager->getEnemyChampions()->size(); i++) {
		Champion* champion = (*(detectionManager->getEnemyChampions()))[i];
		const unsigned char color[] = { 255,0,0, 255 };
 		const unsigned char colorAlpha[] = { 255,0,0, 50 };
		render.draw_rectangle(champion->topLeft.x, champion->topLeft.y, champion->bottomRight.x, champion->bottomRight.y, colorAlpha);
 		render.draw_line(champion->topLeft.x, champion->topLeft.y, champion->topRight.x, champion->topRight.y,color);
 		render.draw_line(champion->bottomLeft.x, champion->bottomLeft.y, champion->bottomRight.x, champion->bottomRight.y,color);
 		render.draw_line(champion->topLeft.x, champion->topLeft.y, champion->bottomLeft.x, champion->bottomLeft.y,color);
 		render.draw_line(champion->topRight.x, champion->topRight.y, champion->bottomRight.x, champion->bottomRight.y,color);
	}
	for (int i = 0; i < detectionManager->getEnemyTowers()->size(); i++) {
		Tower* tower = (*(detectionManager->getEnemyTowers()))[i];
		const unsigned char color[] = { 255,0,0, 255 };
 		const unsigned char colorAlpha[] = { 255,0,0, 50 };
		render.draw_rectangle(tower->topLeft.x, tower->topLeft.y, tower->bottomRight.x, tower->bottomRight.y, colorAlpha);
 		render.draw_line(tower->topLeft.x, tower->topLeft.y, tower->topRight.x, tower->topRight.y,color);
 		render.draw_line(tower->bottomLeft.x, tower->bottomLeft.y, tower->bottomRight.x, tower->bottomRight.y,color);
 		render.draw_line(tower->topLeft.x, tower->topLeft.y, tower->bottomLeft.x, tower->bottomLeft.y,color);
 		render.draw_line(tower->topRight.x, tower->topRight.y, tower->bottomRight.x, tower->bottomRight.y,color);
	}
	for (int i = 0; i < detectionManager->getSelfChampions()->size(); i++) {
		Champion* champion = (*(detectionManager->getSelfChampions()))[i];
		const unsigned char color[] = { 0,255,0, 255 };
 		const unsigned char colorAlpha[] = { 0,255,0, 50 };
		render.draw_rectangle(champion->topLeft.x, champion->topLeft.y, champion->bottomRight.x, champion->bottomRight.y, colorAlpha);
 		render.draw_line(champion->topLeft.x, champion->topLeft.y, champion->topRight.x, champion->topRight.y,color);
 		render.draw_line(champion->bottomLeft.x, champion->bottomLeft.y, champion->bottomRight.x, champion->bottomRight.y,color);
 		render.draw_line(champion->topLeft.x, champion->topLeft.y, champion->bottomLeft.x, champion->bottomLeft.y,color);
 		render.draw_line(champion->topRight.x, champion->topRight.y, champion->bottomRight.x, champion->bottomRight.y,color);
	}


	render.save_png("Output.png");
}

void printDetected(DetectionManager* detection) {
	printf("Detected: \n");
	if (detection->getAllyMinions()->size() > 0) {
		printf("\t%lu ally minions\n", detection->getAllyMinions()->size());
	}
	if (detection->getAllyChampions()->size() > 0) {
		printf("\t%lu ally champions\n", detection->getAllyChampions()->size());
	}
	if (detection->getSelfChampions()->size() > 0) {
		printf("\t%lu self champions\n", detection->getSelfChampions()->size());
	}
	if (detection->getEnemyMinions()->size() > 0) {
		printf("\t%lu enemy minions\n", detection->getEnemyMinions()->size());
	}
	if (detection->getEnemyChampions()->size() > 0) {
		printf("\t%lu enemy champions\n", detection->getEnemyChampions()->size());
	}
	if (detection->getEnemyTowers()->size() > 0) {
		printf("\t%lu enemy towers\n", detection->getEnemyTowers()->size());
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
	if (detection->getBuyableItems()->size() > 0) {
		printf("\tBuyable items: %lu\n", detection->getBuyableItems()->size());
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
}