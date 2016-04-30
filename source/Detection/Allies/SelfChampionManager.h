//
//  AllyMinionManager.h
//  Fluffy Pug
//
//  Created by Matthew French on 5/27/15.
//  Copyright (c) 2015 Matthew French. All rights reserved.
//

#import "../../Utility.h"
#import <time.h>
#import <vector>

class SelfChampionManager {
public:
    
    static ImageData topLeftImageData, bottomLeftImageData,
    bottomRightImageData, topRightImageData, healthSegmentImageData, bottomBarLeftSideImageData, bottomBarRightSideImageData,
    bottomBarAverageHealthColorImageData;
    
    SelfChampionManager();
    static Champion* detectChampionBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static void validateChampionBars(ImageData imageData, std::vector<Champion*>* detectedChampionBars);
    static SelfHealth* detectSelfHealthBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static void validateSelfHealthBars(ImageData imageData, std::vector<SelfHealth*>* detectedHealthBars);
};