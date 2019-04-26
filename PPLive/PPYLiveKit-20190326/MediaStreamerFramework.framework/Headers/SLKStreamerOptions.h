//
//  SLKStreamerOptions.h
//  MediaStreamer
//
//  Created by Think on 2016/12/6.
//  Copyright © 2016年 Cell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>

typedef enum VIDEO_ENCODE_TYPE{
    VIDEO_HARDWARE_ENCODE = 0,
    VIDEO_SOFTWARE_ENCODE = 1
}VIDEO_ENCODE_TYPE;

@interface SLKStreamerOptions : NSObject

@property (nonatomic, strong) NSString *publishUrl;
@property (nonatomic, strong) NSString *backupDir;

@property (nonatomic) BOOL hasVideo;
@property (nonatomic) VIDEO_ENCODE_TYPE videoEncodeType;
@property (nonatomic) CGSize videoSize;
@property (nonatomic) NSInteger fps;
@property (nonatomic) NSInteger videoBitrate;
@property (nonatomic) NSInteger maxKeyFrameIntervalMs;
@property (nonatomic) NSInteger networkAdaptiveMinFps;
@property (nonatomic) NSInteger networkAdaptiveMinVideoBitrate;
@property (nonatomic) BOOL isEnableNetworkAdaptive;

@property (nonatomic) BOOL hasAudio;
@property (nonatomic) NSInteger audioBitrate;

@end
