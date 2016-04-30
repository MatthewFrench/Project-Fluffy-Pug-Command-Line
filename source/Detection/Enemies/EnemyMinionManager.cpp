//
//  EnemyMinionManager.m
//  Fluffy Pug
//
//  Created by Matthew French on 5/27/15.
//  Copyright (c) 2015 Matthew French. All rights reserved.
//

#import "EnemyMinionManager.h"

//static int Debug_Draw_Red = 255, Debug_Draw_Green = 0, Debug_Draw_Blue = 0;
//static int Health_Bar_Width = 62, Health_Bar_Height = 4;
ImageData EnemyMinionManager::topLeftImageData = loadImage("Resources/Enemy Minion Health Bar/Top Left Corner.png");
ImageData EnemyMinionManager::bottomLeftImageData = loadImage("Resources/Enemy Minion Health Bar/Bottom Left Corner.png");
ImageData EnemyMinionManager::bottomRightImageData = loadImage("Resources/Enemy Minion Health Bar/Bottom Right Corner.png");
ImageData EnemyMinionManager::topRightImageData = loadImage("Resources/Enemy Minion Health Bar/Top Right Corner.png");
ImageData EnemyMinionManager::healthSegmentImageData = loadImage("Resources/Enemy Minion Health Bar/Health Segment.png");

EnemyMinionManager::EnemyMinionManager () {
    /*
     minionBars = [NSMutableArray new];
     topRightDetect = [NSMutableArray new];
     topLeftDetect = [NSMutableArray new];
     bottomRightDetect = [NSMutableArray new];
     bottomLeftDetect = [NSMutableArray new];
     
     topLeftImageData = makeImageDataFrom([[NSBundle mainBundle] pathForResource:@"Resources/Enemy Minion Health Bar/Top Left Corner" ofType:@"png"]);
     
     bottomLeftImageData = makeImageDataFrom([[NSBundle mainBundle] pathForResource:@"Resources/Enemy Minion Health Bar/Bottom Left Corner" ofType:@"png"]);
     bottomRightImageData = makeImageDataFrom([[NSBundle mainBundle] pathForResource:@"Resources/Enemy Minion Health Bar/Bottom Right Corner" ofType:@"png"]);
     topRightImageData = makeImageDataFrom([[NSBundle mainBundle] pathForResource:@"Resources/Enemy Minion Health Bar/Top Right Corner" ofType:@"png"]);
     healthSegmentImageData = makeImageDataFrom([[NSBundle mainBundle] pathForResource:@"Resources/Enemy Minion Health Bar/Health Segment" ofType:@"png"]);
     
     needsFullScreenUpdate = true;
     fullScreenUpdateTime = clock();
     lastUpdateTime = clock();
     */
}
const float coloredPixelPrecision = 0.96; //0.97
const float overalImagePrecision = 0.96; //0.97
const float minionHealthMatch = 0.80; //0.87
Minion* EnemyMinionManager::detectMinionBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y) {
    Minion* minion = NULL;
    if (isColor3(pixel, 0, 0, 0)) {
        //Look top left corner
        if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topLeftImageData, coloredPixelPrecision) >=  overalImagePrecision) {
            int barTopLeftX = x + 1;
            int barTopLeftY = y + 1;
            minion = new Minion();
            minion->topLeft.x = barTopLeftX;
            minion->topLeft.y = barTopLeftY;
            minion->bottomLeft.x = barTopLeftX;
            minion->bottomLeft.y = barTopLeftY + 4;
            minion->topRight.x = barTopLeftX + 62;
            minion->topRight.y = barTopLeftY;
            minion->bottomRight.x = barTopLeftX + 62;
            minion->bottomRight.y = barTopLeftY + 4;
            minion->health = 0;
            minion->detectedTopLeft = true;
            //NSLog(@"Top left at %d %d", barTopLeftX, barTopLeftY);
        } else if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, bottomLeftImageData, coloredPixelPrecision) >=  overalImagePrecision) { // Look for bottom left corner
            int barTopLeftX = x + 1;
            int barTopLeftY = y - 3;
            minion = new Minion();
            minion->topLeft.x = barTopLeftX;
            minion->topLeft.y = barTopLeftY;
            minion->bottomLeft.x = barTopLeftX;
            minion->bottomLeft.y = barTopLeftY + 4;
            minion->topRight.x = barTopLeftX + 62;
            minion->topRight.y = barTopLeftY;
            minion->bottomRight.x = barTopLeftX + 62;
            minion->bottomRight.y = barTopLeftY + 4;
            minion->detectedBottomLeft = true;
            minion->health = 0;
            //NSLog(@"Bottom left at %d %d", barTopLeftX, barTopLeftY);
        }
    }/* else {
      
      bool detectedCorner = false;
      if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, topRightImageData, 1.0) >=  1.0) { // Look for top right corner
      int barTopLeftX = x - 61;
      int barTopLeftY = y + 1;
      //Now scan backwards by 61 pixels, looking for minion health bar
      for (int x = 61; x >= 0; x--) {
      for (int y = 0; y < healthSegmentImageData.imageHeight; y++) {
      uint8_t* healthBarColor = getPixel2(healthSegmentImageData, 0, y);
      uint8_t*  p = getPixel2(imageData, x + barTopLeftX, y + barTopLeftY);
      if (getColorPercentage(healthBarColor, p) >= 0.95) {
      minion = [Minion new];
      minion->health = (float)x / 61 * 100;
      detectedCorner = true;
      minion->topLeft.x = barTopLeftX;
      minion->topLeft.y = barTopLeftY;
      minion->bottomLeft.x = barTopLeftX;
      minion->bottomLeft.y = barTopLeftY + 4;
      minion->topRight.x = barTopLeftX + 62;
      minion->topRight.y = barTopLeftY;
      minion->bottomRight.x = barTopLeftX + 62;
      minion->bottomRight.y = barTopLeftY + 4;
      minion->detectedTopRight = true;
      y = healthSegmentImageData.imageHeight + 1;
      x = -1;
      }
      }
      }
      }
      if (detectedCorner == false) {
      if (getImageAtPixelPercentageOptimizedExact(pixel, x, y, imageData.imageWidth, imageData.imageHeight, bottomRightImageData, 1.0) >=  1.0) { // Look for bottom right corner
      int barTopLeftX = x - 61;
      int barTopLeftY = y - 3;
      
      //Now scan backwards by 61 pixels, looking for minion health bar
      for (int x = 61; x >= 0; x--) {
      for (int y = 0; y < healthSegmentImageData.imageHeight; y++) {
      uint8_t* healthBarColor = getPixel2(healthSegmentImageData, 0, y);
      uint8_t*  p = getPixel2(imageData, x + barTopLeftX, y + barTopLeftY);
      if (getColorPercentage(healthBarColor, p) >= 0.95) {
      minion = [Minion new];
      minion->health = (float)x / 61 * 100;
      minion->topLeft.x = barTopLeftX;
      minion->topLeft.y = barTopLeftY;
      minion->bottomLeft.x = barTopLeftX;
      minion->bottomLeft.y = barTopLeftY + 4;
      minion->topRight.x = barTopLeftX + 62;
      minion->topRight.y = barTopLeftY;
      minion->bottomRight.x = barTopLeftX + 62;
      minion->bottomRight.y = barTopLeftY + 4;
      minion->detectedBottomRight = true;
      y = healthSegmentImageData.imageHeight + 1;
      x = -1;
      }
      }
      }
      }
      }
      }*/
    return minion;
}

//To Validate, at least 2 corners need detected then we detect the health percentage
std::vector<Minion> EnemyMinionManager::validateMinionBars(ImageData imageData, std::vector<Minion> detectedMinionBars) {
    //NSLog(@"Detected minions: %lu", (unsigned long)[detectedMinionBars count]);
    /*
    NSMutableArray* minionBars = [NSMutableArray new];
    
    while ([detectedMinionBars count] > 0) {
        Minion* minion = [detectedMinionBars lastObject];
        [detectedMinionBars removeLastObject];
        int detectedCorners = 1;
        for (int i = 0; i < [detectedMinionBars count]; i++) {
            Minion* minion2 = [detectedMinionBars objectAtIndex:i];
            if (minion2->topLeft.x == minion->topLeft.x && minion->topLeft.y == minion2-> topLeft.y) {
                [detectedMinionBars removeObjectAtIndex:i];
                i--;
                if (minion2->detectedBottomLeft) minion->detectedBottomLeft = true;
                if (minion2->detectedBottomRight) minion->detectedBottomRight = true;
                if (minion2->detectedTopLeft) minion->detectedTopLeft = true;
                if (minion2->detectedTopRight) minion->detectedTopRight = true;
                if (minion2->health > minion->health) minion->health = minion2->health;
                detectedCorners++;
            }
        }
        //if (detectedCorners > 1) {
        minion->characterCenter.x = minion->topLeft.x+30; minion->characterCenter.y = minion->topLeft.y+32;
        [minionBars addObject: minion];
        //}
    }
    
    //Detect health
    for (int i = 0; i < [minionBars count]; i++) {
        Minion* minion = [minionBars objectAtIndex:i];
        if (minion->health == 0) {
            for (int x = 61; x >= 0; x--) {
                for (int y = 0; y < healthSegmentImageData.imageHeight; y++) {
                    if (x + minion->topLeft.x >= 0 && x + minion->topLeft.x < imageData.imageWidth &&
                        y + minion->topLeft.y >= 0 && y + minion->topLeft.y < imageData.imageHeight) {
                        uint8_t* healthBarColor = getPixel2(healthSegmentImageData, 0, y);
                        uint8_t*  p = getPixel2(imageData, x + minion->topLeft.x, y + minion->topLeft.y);
                        if (getColorPercentage(healthBarColor, p) >= minionHealthMatch) {
                            minion->health = (float)x / 61 * 100;
                            y = healthSegmentImageData.imageHeight + 1;
                            x = -1;
                        }
                    }
                }
            }
        }
        if (minion->health == 0) { //Not a minion
            [minionBars removeObjectAtIndex:i];
            i--;
            //delete minion;
        }
    }
    
    //Detect if ward
    //Ward is 193, 193, 193
    for (int i = 0; i < [minionBars count]; i++) {
        Minion* minion = [minionBars objectAtIndex:i];
        bool isWard = false;
        for (int x = 61; x >= 0; x--) {
            for (int yOffset = -3; yOffset <= 1; yOffset++) {
                if (x + minion->topLeft.x >= 0 && x + minion->topLeft.x < imageData.imageWidth &&
                    yOffset + minion->topLeft.y >= 0 && yOffset + minion->topLeft.y < imageData.imageHeight) {
                    uint8_t*  p = getPixel2(imageData, x + minion->topLeft.x, yOffset + minion->topLeft.y);
                    if (isColor(p, 220, 220, 220, 45)) {
                        isWard = true;
                        x = -1;
                        yOffset = 4;
                    }
                }
            }
        }
        if (isWard) {
            [minionBars removeObjectAtIndex:i];
            i--;
        }
    }
    
    return minionBars;
     */
    return NULL;
}