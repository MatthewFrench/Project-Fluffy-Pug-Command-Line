//
//  AbilityManager.h
//  Fluffy Pug
//
//  Created by Matthew French on 6/11/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import "../../Utility.h"
#import <vector>
//#import "InteractiveEvents.h"

class AbilityManager {
    
    /*
    void processPixelLevelUp(ImageData imageData, uint8_t *pixel, int x, int y);
    bool containsPosition(NSMutableArray* array, Position p);
    void detectLevelUp(ImageData imageData);
    void detectLevelUpCount(ImageData imageData);
    void processPixelLevelUpCount(ImageData imageData, uint8_t *pixel, int x, int y);
    void detectAbilities(ImageData imageData);
    void processPixelAbilities(ImageData imageData, uint8_t *pixel, int x, int y);
    void detectSummonerSpells(ImageData imageData);
    
    bool needsFullScreenUpdate;
    */
    //double fullScreenUpdateTime, lastUpdateTime;
    /*
     , topLeftImageData, bottomLeftImageData,
     bottomRightImageData, topRightImageData, healthSegmentImageData;
     
     void scanSection(int xStart, int yStart, int xEnd, int yEnd);
     void processMinionsLocations();
     void processMinionsHealth();
     void processPixel(uint8_t *pixel, int x, int y);
     void processTopLeftDetect(); void processBottomLeftDetect(); void processTopRightDetect(); void processBottomRightDetect();
     bool containsPosition(NSMutableArray* array, Position p);
     
     const double minionSpeed = 2000; //100 pixels per second
     */
public:
    static ImageData levelUpImageData, levelDotImageData, levelUpDisabledImageData, abilityEnabledImageData, abilityDisabledImageData, enabledSummonerSpellImageData;
    AbilityManager();
    
    static GenericObject* detectLevelUpAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static GenericObject* detectLevelDotAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static GenericObject* detectEnabledAbilityAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static GenericObject* detectEnabledSummonerSpellAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
};