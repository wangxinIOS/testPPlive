//
//  SLKStreamer.h
//  MediaStreamer
//
//  Created by Think on 16/2/14.
//  Copyright © 2016年 Cell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

#import "SLKStreamerOptions.h"

enum slk_media_streamer_error_type {
    SLK_MEDIA_STREAMER_ERROR_UNKNOWN = -1,
    SLK_MEDIA_STREAMER_ERROR_CONNECT_FAIL = 0,
    SLK_MEDIA_STREAMER_ERROR_MUX_FAIL = 1,
    SLK_MEDIA_STREAMER_ERROR_COLORSPACECONVERT_FAIL = 2,
    SLK_MEDIA_STREAMER_ERROR_VIDEO_ENCODE_FAIL = 3,
    SLK_MEDIA_STREAMER_ERROR_AUDIO_CAPTURE_START_FAIL = 4,
    SLK_MEDIA_STREAMER_ERROR_AUDIO_ENCODE_FAIL = 5,
    SLK_MEDIA_STREAMER_ERROR_AUDIO_CAPTURE_STOP_FAIL = 6,
    SLK_MEDIA_STREAMER_ERROR_POOR_NETWORK = 7,
    SLK_MEDIA_STREAMER_ERROR_AUDIO_FILTER_FAIL = 8,
    SLK_MEDIA_STREAMER_ERROR_OPEN_VIDEO_ENCODER_FAIL = 9,
};

enum slk_media_streamer_info_type {
    SLK_MEDIA_STREAMER_INFO_ALREADY_CONNECTING = 1,
    SLK_MEDIA_STREAMER_INFO_PUBLISH_DELAY_TIME = 2,
    SLK_MEDIA_STREAMER_INFO_ALREADY_ENDING     = 3,
    SLK_MEDIA_STREAMER_INFO_PUBLISH_REAL_BITRATE = 4,
    SLK_MEDIA_STREAMER_INFO_PUBLISH_REAL_FPS = 5,
    SLK_MEDIA_STREAMER_INFO_PUBLISH_DOWN_BITRATE = 6,
    SLK_MEDIA_STREAMER_INFO_PUBLISH_UP_BITRATE = 7,
    SLK_MEDIA_STREAMER_INFO_PUBLISH_TIME = 8,
    
    SLK_MEDIA_STREAMER_INFO_AUDIO_INPUT_DATA_LOST = 100,
};

@protocol SLKStreamerDelegate <NSObject>
@required
- (void)gotConnecting;
- (void)didConnected;
- (void)gotStreaming;
- (void)didPaused;
- (void)gotStreamerErrorWithErrorType:(int)errorType;
- (void)gotStreamerInfoWithInfoType:(int)infoType InfoValue:(int)infoValue;
- (void)didEndStreaming;
@optional
@end

@interface SLKStreamer : NSObject

- (instancetype) init;

- (void)initializeWithOptions:(SLKStreamerOptions*)options;

- (void)pushPixelBuffer:(CVPixelBufferRef)pixelBuffer
                        Rotation:(int)rotation;

- (void)pushText:(NSString*)text;

- (void)start;
- (void)resume;
- (void)pause;
- (void)stop;

- (void)enableAudio:(BOOL)isEnable;

- (void)terminate;

@property (nonatomic, weak) id<SLKStreamerDelegate> delegate;

@end
