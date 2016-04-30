//
//  Champion.m
//  Fluffy Pug
//
//  Created by Matthew French on 9/10/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

#import "Champion.h"
//#import "Utility.h"

Champion::Champion () {
    //Position topLeft, topRight, bottomLeft, bottomRight, characterCenter;
    detectedTopLeft = false;
    detectedBottomLeft = false;
    detectedTopRight = false;
    detectedBottomRight = false;
    health = 0;
}