//
//  AllyMinionManager.h
//  Fluffy Pug
//
//  Created by Matthew French on 5/27/15.
//  Copyright (c) 2015 Matthew French. All rights reserved.
//

#include "../../Utility.h"
#include <vector>

class EnemyMinionManager {
public:
    
    static ImageData topLeftImageData, bottomLeftImageData,
    bottomRightImageData, topRightImageData, healthSegmentImageData;
    
    EnemyMinionManager();
    
    static Minion* detectMinionBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static void validateMinionBars(ImageData imageData, std::vector<Minion*>* detectedChampionBars);
};