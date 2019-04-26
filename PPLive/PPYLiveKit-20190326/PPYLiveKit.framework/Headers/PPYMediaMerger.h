//
//  PPYMediaMerger.h
//  PPYLiveKit
//
//  Created by bobzhang on 16/12/29.
//  Copyright © 2016年 PPTV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PPYMediaInfo,PPYMediaEffect,PPYMediaEffectText,PPYMediaEffectImage,PPYMediaEffectFilter,PPYMediaEffectAudio;

@protocol PPYMediaMergerDelegate <NSObject>
@required
- (void)gotErrorWithErrorType:(int)errorType;
- (void)gotInfoWithInfoType:(int)infoType InfoValue:(int)infoValue;
- (void)didEnd;
@optional
@end



@interface PPYMediaMerger : NSObject

@property (nonatomic, weak) id<PPYMediaMergerDelegate> delegate;

//输出参数设置
@property (nonatomic, assign) CGSize videoSize;
@property (nonatomic, strong) NSString *outProductPath; /**<输出的路径*/

- (instancetype)initWithProductPath:(NSString *)path  andVideoSize:(CGSize)videoSize;

- (void)addMediaInfosFormArray:(NSArray <PPYMediaInfo *> *)medias;

- (void)addMediaInfo:(PPYMediaInfo *)mediaInfo;
- (void)addMediaEffect:(PPYMediaEffect *)mediaEffect;

- (void)startMergeAllMedia;
- (void)endMerge;
@end
