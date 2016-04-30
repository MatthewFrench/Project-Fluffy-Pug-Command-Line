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

class AllyChampionManager {
public:
    static ImageData topLeftImageData, bottomLeftImageData,
    bottomRightImageData, topRightImageData, healthSegmentImageData;
    
    AllyChampionManager();
    static Champion* detectChampionBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static void validateChampionBars(ImageData imageData, std::vector<Champion*>* detectedChampionBars);
};