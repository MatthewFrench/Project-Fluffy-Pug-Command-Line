//
//  Tower.h
//  Fluffy Pug
//
//  Created by Matthew French on 9/10/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import "Position.h"

class Tower {
public:
    Position topLeft, topRight, bottomLeft, bottomRight, towerCenter;
    bool detectedTopLeft, detectedBottomLeft, detectedTopRight, detectedBottomRight;
    float health;
};