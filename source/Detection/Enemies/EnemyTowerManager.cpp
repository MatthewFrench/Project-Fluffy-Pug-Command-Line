//
//  TurretManager.m
//  Fluffy Pug
//
//  Created by Matthew French on 6/12/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

#import "EnemyTowerManager.h"

ImageData EnemyTowerManager::topLeftImageData = loadImage("Resources/Enemy Tower Health Bar/Top Left Corner.png");

ImageData EnemyTowerManager::bottomLeftImageData = loadImage("Resources/Enemy Tower Health Bar/Bottom Left Corner.png");
ImageData EnemyTowerManager::bottomRightImageData = loadImage("Resources/Enemy Tower Health Bar/Bottom Right Corner.png");
ImageData EnemyTowerManager::topRightImageData = loadImage("Resources/Enemy Tower Health Bar/Top Right Corner.png");
ImageData EnemyTowerManager::healthSegmentImageData = loadImage("Resources/Enemy Tower Health Bar/Health Segment.png");

EnemyTowerManager::EnemyTowerManager () {}


Tower* EnemyTowerManager::detectTowerBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y) {
    Tower* tower = NULL;
    //Look top left corner
    if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topLeftImageData, 0.7) >=  0.7) {
        int barTopLeftX = x + 3;
        int barTopLeftY = y + 3;
        tower = new Tower();
        tower->topLeft.x = barTopLeftX;
        tower->topLeft.y = barTopLeftY;
        tower->bottomLeft.x = barTopLeftX;
        tower->bottomLeft.y = barTopLeftY + 8;
        tower->topRight.x = barTopLeftX + 126;
        tower->topRight.y = barTopLeftY;
        tower->bottomRight.x = barTopLeftX + 126;
        tower->bottomRight.y = barTopLeftY + 8;
        tower->detectedTopLeft = true;
    } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, bottomLeftImageData, 0.7) >=  0.7) { // Look for bottom left corner
        int barTopLeftX = x + 3;
        int barTopLeftY = y - 7;
        tower = new Tower();
        tower->topLeft.x = barTopLeftX;
        tower->topLeft.y = barTopLeftY;
        tower->bottomLeft.x = barTopLeftX;
        tower->bottomLeft.y = barTopLeftY + 8;
        tower->topRight.x = barTopLeftX + 126;
        tower->topRight.y = barTopLeftY;
        tower->bottomRight.x = barTopLeftX + 126;
        tower->bottomRight.y = barTopLeftY + 8;
        tower->detectedBottomLeft = true;
    } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topRightImageData, 0.7) >=  0.7) { // Look for top right corner
        int barTopLeftX = x - 126 + 1;
        int barTopLeftY = y + 3;
        tower = new Tower();
        tower->topLeft.x = barTopLeftX;
        tower->topLeft.y = barTopLeftY;
        tower->bottomLeft.x = barTopLeftX;
        tower->bottomLeft.y = barTopLeftY + 8;
        tower->topRight.x = barTopLeftX + 126;
        tower->topRight.y = barTopLeftY;
        tower->bottomRight.x = barTopLeftX + 126;
        tower->bottomRight.y = barTopLeftY + 8;
        tower->detectedTopRight = true;
    } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, bottomRightImageData, 0.7) >=  0.7) { // Look for bottom right corner
        int barTopLeftX = x - 126 + 1;
        int barTopLeftY = y - 7;
        tower = new Tower();
        tower->topLeft.x = barTopLeftX;
        tower->topLeft.y = barTopLeftY;
        tower->bottomLeft.x = barTopLeftX;
        tower->bottomLeft.y = barTopLeftY + 8;
        tower->topRight.x = barTopLeftX + 126;
        tower->topRight.y = barTopLeftY;
        tower->bottomRight.x = barTopLeftX + 126;
        tower->bottomRight.y = barTopLeftY + 8;
        tower->detectedBottomRight = true;
    }
    //if (x == 364 + 101 + 2 && y == 310 - 3) {
    //    NSLog(@"Top Right corner test: %f", getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topRightImageData, 0.5));
    //}
    return tower;
}

//To Validate, at least 2 corners need detected then we detect the health percentage
void EnemyTowerManager::validateTowerBars(ImageData imageData, std::vector<Tower*>* detectedTowerBars) {
    //Remove duplicates
    for (int i = 0; i < detectedTowerBars->size(); i++) {
        Tower* tower = (*detectedTowerBars)[i];
        int detectedCorners = 1;
        for (int j = 0; j < detectedTowerBars->size(); j++) {
            if (j != i) {
                Tower* tower2 = (*detectedTowerBars)[i];
                if (tower2->topLeft.x == tower->topLeft.x && tower->topLeft.y == tower2-> topLeft.y) {
                    detectedTowerBars->erase(detectedTowerBars->begin() + j);
                    j--;
                    if (tower2->detectedBottomLeft) tower->detectedBottomLeft = true;
                    if (tower2->detectedBottomRight) tower->detectedBottomRight = true;
                    if (tower2->detectedTopLeft) tower->detectedTopLeft = true;
                    if (tower2->detectedTopRight) tower->detectedTopRight = true;
                    detectedCorners++;
                }
            }
        }
        if (detectedCorners < 2) {
            detectedTowerBars->erase(detectedTowerBars->begin() + i);
            i--;
        }
        tower->towerCenter.x = tower->topLeft.x+126/2; tower->towerCenter.y = tower->topLeft.y+200;
    }
    
    //Detect health
    for (int i = 0; i < detectedTowerBars->size(); i++) {
        Tower* tower = (*detectedTowerBars)[i];
        tower->health = 0;
        for (int x = 125; x >= 0; x--) {
            for (int y = 0; y < healthSegmentImageData.imageHeight; y++) {
                if (x + tower->topLeft.x >= 0 && x + tower->topLeft.x < imageData.imageWidth &&
                    y + tower->topLeft.y >= 0 && y + tower->topLeft.y < imageData.imageHeight) {
                uint8_t* healthBarColor = getPixel2(healthSegmentImageData, 0, y);
                uint8_t*  p = getPixel2(imageData, x + tower->topLeft.x, y + tower->topLeft.y);
                if (getColorPercentage(healthBarColor, p) >= 0.85) {
                    tower->health = (float)x / 125 * 100;
                    y = healthSegmentImageData.imageHeight + 1;
                    x = -1;
                }
                }
            }
        }
        if (tower->health == 0) {
            detectedTowerBars->erase(detectedTowerBars->begin() + i);
            i--;
        }
    }
}