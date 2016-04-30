//
//  ShopManager.h
//  Fluffy Pug
//
//  Created by Matthew French on 6/12/15.
//  Copyright © 2015 Matthew French. All rights reserved.
//

#import "../../Utility.h"
#import <time.h>

class ShopManager {
public:
    static ImageData shopTopLeftCornerImageData, shopAvailableImageData, shopBottomLeftCornerImageData, shopBuyableItemTopLeftCornerImageData, shopBuyableItemBottomLeftCornerImageData, shopBuyableItemTopRightCornerImageData, shopBuyableItemBottomRightCornerImageData;
    ShopManager();
    static GenericObject* detectShopAvailable(ImageData imageData, uint8_t *pixel, int x, int y);
    static GenericObject* detectShopTopLeftCorner(ImageData imageData, uint8_t *pixel, int x, int y);
    static GenericObject* detectShopBottomLeftCorner(ImageData imageData, uint8_t *pixel, int x, int y);
    static GenericObject* detectBuyableItems(ImageData imageData, uint8_t *pixel, int x, int y);
};