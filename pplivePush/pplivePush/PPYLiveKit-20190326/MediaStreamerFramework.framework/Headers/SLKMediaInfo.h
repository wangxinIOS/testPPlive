//
//  SLKMediaInfo.h
//  MediaStreamer
//
//  Created by Think on 2016/11/29.
//  Copyright © 2016年 Cell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SLKMediaProcesserCommon.h"

@protocol SLKMediaInfoDelegate <NSObject>
@required
- (void)gotMediaDetailInfoWithDuration:(int64_t)duration WithWidth:(int)width WithHeight:(int)height;
- (void)gotThumbnailWithCVPixelBuffer:(CVPixelBufferRef)outputThumbnailData;
- (void)gotErrorWithErrorType:(int)errorType;
- (void)gotInfoWithInfoType:(int)infoType InfoValue:(int)infoValue;
- (void)didEnd;
@optional
@end

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface SLKMediaDetailInfo : NSObject

@property (nonatomic) BOOL hasVideo;
@property (nonatomic) BOOL hasAudio;

@property (nonatomic) NSInteger width;
@property (nonatomic) NSInteger height;
@property (nonatomic) NSInteger fps;
@property (nonatomic) NSInteger kbps; //kbps
@property (nonatomic) NSTimeInterval durationMs; //ms
@property (nonatomic) NSInteger rotate;
@property (nonatomic) BOOL isH264Codec;
@property (nonatomic) BOOL isAACCodec;

@end

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface SLKMediaInfo : NSObject

+ (SLKMediaDetailInfo*)syncGetMediaDetailInfoWithInputFile:(NSString*)inputMediaFile;
+ (NSTimeInterval)syncGetMediaDurationWithInputFile:(NSString*)inputMediaFile;
+ (BOOL)syncGetCoverImageFileWithInputFile:(NSString*)inputMediaFile OutputWidth:(int)width OutputHeight:(int)height OutputPNGFile:(NSString*)outputPNGFile;
+ (BOOL)syncGetCoverImageFileWithInputFile:(NSString*)inputMediaFile Position:(NSTimeInterval)position OutputWidth:(int)width OutputHeight:(int)height OutputPNGFile:(NSString*)outputPNGFile;

- (instancetype) init;

- (void)initialize;

- (void)setThumbnailsOptionWithWidth:(int)width WithHeight:(int)height WithThumbnailCount:(int)thumbnailCount;

- (void)loadAsync:(NSString*)inputMediaFile;
- (void)loadAsync:(NSString*)inputMediaFile StartPos:(NSTimeInterval)startPos EndPos:(NSTimeInterval)endPos;
- (void)quit;

- (void)terminate;

@property (nonatomic, weak) id<SLKMediaInfoDelegate> delegate;


@end
