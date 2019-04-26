//
//  PPYLiveKit.h
//  PPYLiveKit
//
//  Created by Jimmy on 16/8/22.
//  Copyright © 2016年 高国栋. All rights reserved.
//

#ifndef PPYLiveKit_h
#define PPYLiveKit_h
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//! Project version number for PPYLiveKit.
FOUNDATION_EXPORT double PPYLiveKitVersionNumber;

//! Project version string for PPYLiveKit.
FOUNDATION_EXPORT const unsigned char PPYLiveKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PPYLiveKit/PublicHeader.h>

#if __has_include(<PPYLiveKit/PPYLiveKit.h>)
    #import <PPYLiveKit/PPYLiveKit.h>
    #import <PPYLiveKit/PPYPushEngine.h>
    #import <PPYLiveKit/PPYPlayEngine.h>
    #import <PPYLiveKit/PPYVideoConfiguration.h>
    #import <PPYLiveKit/PPYAudioConfiguration.h>
    #import <PPYLiveKit/PPYMediaMerger.h>
    #import <PPYLiveKit/PPYThumbnailInfo.h>
    #import <PPYLiveKit/PPYMediaInfo.h>
    #import <PPYLiveKit/PPYDataInfo.h>
#else
    #import "PPYLiveKit.h"
    #import "PPYPushEngine.h"
    #import "PPYPlayEngine.h"
    #import "PPYVideoConfiguration.h"
    #import "PPYAudioConfiguration.h"
    #import "PPYMediaMerger.h"
    #import "PPYThumbnailInfo.h"
    #import "PPYMediaInfo.h"
    #import "PPYDataInfo.h"
#endif

#endif /* PPYLiveKit_h */

