//
//  AllyMinionManager.h
//  Fluffy Pug
//
//  Created by Matthew French on 5/27/15.
//  Copyright (c) 2015 Matthew French. All rights reserved.
//

#include "../../Utility.h"
#include <time.h>
#include <vector>

class EnemyChampionManager {
public:
    static ImageData topLeftImageData, bottomLeftImageData,
    bottomRightImageData, topRightImageData, healthSegmentImageData;
    
    EnemyChampionManager();
    static Champion* detectChampionBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static void validateChampionBars(ImageData imageData, std::vector<Champion*>* detectedChampionBars);
};