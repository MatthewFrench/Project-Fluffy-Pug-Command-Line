//
//  Champion.m
//  Fluffy Pug
//
//  Created by Matthew French on 9/10/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

#include "Champion.h"

Champion::Champion () {
    detectedTopLeft = false;
    detectedBottomLeft = false;
    detectedTopRight = false;
    detectedBottomRight = false;
    health = 0;
    lowestPercentageMatch = 1.0;
}