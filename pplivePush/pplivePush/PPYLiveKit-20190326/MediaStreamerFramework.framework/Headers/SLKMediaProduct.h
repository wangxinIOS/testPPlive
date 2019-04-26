//
//  SLKMediaProduct.h
//  MediaStreamer
//
//  Created by Think on 2016/11/22.
//  Copyright © 2016年 Cell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>

typedef enum SLK_MEDIA_PRODUCT_TYPE{
    SLK_MEDIA_PRODUCT_TYPE_UNKNOWN     = -1,
    SLK_MEDIA_PRODUCT_TYPE_MP4 = 0,
    SLK_MEDIA_PRODUCT_TYPE_GIF = 1,
}SLK_MEDIA_PRODUCT_TYPE;

@interface SLKMediaProduct : NSObject

- (instancetype) init;

@property (nonatomic) NSInteger iD;
@property (nonatomic, strong) NSString *url;

@property (nonatomic) SLK_MEDIA_PRODUCT_TYPE slk_media_product_type;

//Video Option
@property (nonatomic) BOOL hasVideo;
@property (nonatomic) CGSize videoSize;

//Audio Option
@property (nonatomic) BOOL hasAudio;

//AV Option
@property (nonatomic) NSInteger bps;

@end
