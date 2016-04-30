//
//  TurretManager.h
//  Fluffy Pug
//
//  Created by Matthew French on 6/12/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

#import "../../Utility.h"
#import <time.h>
#include <vector>

class EnemyTowerManager {
public:
    static ImageData topLeftImageData, bottomLeftImageData,
    bottomRightImageData, topRightImageData, healthSegmentImageData;
    EnemyTowerManager();
    static Tower* detectTowerBarAtPixel(ImageData imageData, uint8_t *pixel, int x, int y);
    static void validateTowerBars(ImageData imageData, std::vector<Tower*>* detectedTowerBars);
};