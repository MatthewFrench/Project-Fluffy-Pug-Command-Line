//
//  EnemyChampionManager.m
//  Fluffy Pug
//
//  Created by Matthew French on 5/27/15.
//  Copyright (c) 2015 Matthew French. All rights reserved.
//

#import "EnemyChampionManager.h"

//static int Debug_Draw_Red = 255, Debug_Draw_Green = 0, Debug_Draw_Blue = 255;
//static int Health_Bar_Width = 104, Health_Bar_Height = 9;
ImageData EnemyChampionManager::topLeftImageData = loadImage("Resources/Enemy Champion Health Bar/Top Left Corner.png");

ImageData EnemyChampionManager::bottomLeftImageData = loadImage("Resources/Enemy Champion Health Bar/Bottom Left Corner.png");
ImageData EnemyChampionManager::bottomRightImageData = loadImage("Resources/Enemy Champion Health Bar/Bottom Right Corner.png");
ImageData EnemyChampionManager::topRightImageData = loadImage("Resources/Enemy Champion Health Bar/Top Right Corner.png");
ImageData EnemyChampionManager::healthSegmentImageData = loadImage("Resources/Enemy Champion Health Bar/Health Segment.png");

EnemyChampionManager::EnemyChampionManager () {
    /*
    championBars = [NSMutableArray new];
    topRightDetect = [NSMutableArray new];
    topLeftDetect = [NSMutableArray new];
    bottomRightDetect = [NSMutableArray new];
    bottomLeftDetect = [NSMutableArray new];
     */
    

    
    //needsFullScreenUpdate = true;
    //fullScreenUpdateTime = clock();
    //lastUpdateTime = clock();
}

Champion* EnemyChampionManager::detectChampionBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y) {
    Champion* champ = NULL;
    //Look top left corner
    if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topLeftImageData, 0.8) >=  0.8) {
        int barTopLeftX = x + 3;
        int barTopLeftY = y + 3;
        champ = new Champion();
        champ->topLeft.x = barTopLeftX;
        champ->topLeft.y = barTopLeftY;
        champ->bottomLeft.x = barTopLeftX;
        champ->bottomLeft.y = barTopLeftY + 9;
        champ->topRight.x = barTopLeftX + 104;
        champ->topRight.y = barTopLeftY;
        champ->bottomRight.x = barTopLeftX + 104;
        champ->bottomRight.y = barTopLeftY + 9;
        champ->detectedTopLeft = true;
    } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, bottomLeftImageData, 0.8) >=  0.8) { // Look for bottom left corner
        int barTopLeftX = x + 3;
        int barTopLeftY = y - 8;
        champ = new Champion();
        champ->topLeft.x = barTopLeftX;
        champ->topLeft.y = barTopLeftY;
        champ->bottomLeft.x = barTopLeftX;
        champ->bottomLeft.y = barTopLeftY + 9;
        champ->topRight.x = barTopLeftX + 104;
        champ->topRight.y = barTopLeftY;
        champ->bottomRight.x = barTopLeftX + 104;
        champ->bottomRight.y = barTopLeftY + 9;
        champ->detectedBottomLeft = true;
    } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topRightImageData, 0.8) >=  0.8) { // Look for top right corner
        int barTopLeftX = x - 101 - 2;
        int barTopLeftY = y + 3;
        champ = new Champion();
        champ->topLeft.x = barTopLeftX;
        champ->topLeft.y = barTopLeftY;
        champ->bottomLeft.x = barTopLeftX;
        champ->bottomLeft.y = barTopLeftY + 9;
        champ->topRight.x = barTopLeftX + 104;
        champ->topRight.y = barTopLeftY;
        champ->bottomRight.x = barTopLeftX + 104;
        champ->bottomRight.y = barTopLeftY + 9;
        champ->detectedTopRight = true;
    } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, bottomRightImageData, 0.8) >=  0.8) { // Look for bottom right corner
        int barTopLeftX = x - 101 - 2;
        int barTopLeftY = y - 8;
        champ = new Champion();
        champ->topLeft.x = barTopLeftX;
        champ->topLeft.y = barTopLeftY;
        champ->bottomLeft.x = barTopLeftX;
        champ->bottomLeft.y = barTopLeftY + 9;
        champ->topRight.x = barTopLeftX + 104;
        champ->topRight.y = barTopLeftY;
        champ->bottomRight.x = barTopLeftX + 104;
        champ->bottomRight.y = barTopLeftY + 9;
        champ->detectedBottomRight = true;
    }
    //if (x == 364 + 101 + 2 && y == 310 - 3) {
    //    NSLog(@"Top Right corner test: %f", getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topRightImageData, 0.5));
    //}
    return champ;
}

//To Validate, at least 2 corners need detected then we detect the health percentage
std::vector<Champion> EnemyChampionManager::validateChampionBars(ImageData imageData, std::vector<Champion> detectedChampionBars) {
    /*
    NSMutableArray* championBars = [NSMutableArray new];
    
    while ([detectedChampionBars count] > 0) {
        Champion* champ = [detectedChampionBars lastObject];
        [detectedChampionBars removeLastObject];
        int detectedCorners = 1;
        for (int i = 0; i < [detectedChampionBars count]; i++) {
            Champion* champ2 = [detectedChampionBars objectAtIndex:i];
            if (champ2->topLeft.x == champ->topLeft.x && champ->topLeft.y == champ2-> topLeft.y) {
                [detectedChampionBars removeObjectAtIndex:i];
                i--;
                if (champ2->detectedBottomLeft) champ->detectedBottomLeft = true;
                if (champ2->detectedBottomRight) champ->detectedBottomRight = true;
                if (champ2->detectedTopLeft) champ->detectedTopLeft = true;
                if (champ2->detectedTopRight) champ->detectedTopRight = true;
                detectedCorners++;
            }
        }
        if (detectedCorners > 1) {
            champ->characterCenter.x = champ->topLeft.x+66; champ->characterCenter.y = champ->topLeft.y+104;
            [championBars addObject: champ];
        }// else {
        //    delete champ;
        //}
    }
    
    //Detect health
    for (int i = 0; i < [championBars count]; i++) {
        Champion* champ = [championBars objectAtIndex:i];
        champ->health = 0;
        for (int x = 103; x >= 0; x--) {
            for (int y = 0; y < healthSegmentImageData.imageHeight; y++) {
                if (x + champ->topLeft.x >= 0 && x + champ->topLeft.x < imageData.imageWidth &&
                    y + champ->topLeft.y >= 0 && y + champ->topLeft.y < imageData.imageHeight) {
                uint8_t* healthBarColor = getPixel2(healthSegmentImageData, 0, y);
                uint8_t*  p = getPixel2(imageData, x + champ->topLeft.x, y + champ->topLeft.y);
                if (getColorPercentage(healthBarColor, p) >= 0.95) {
                    champ->health = (float)x / 103 * 100;
                    y = healthSegmentImageData.imageHeight + 1;
                    x = -1;
                }
                }
            }
        }
    }
    
    return championBars;
     */
    return detectedChampionBars;
}