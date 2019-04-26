//
//  PPYDataInfo.h
//  PPYLiveKit
//
//  Created by jacksimjia on 2019/1/18.
//  Copyright © 2019年 PPTV. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PPYDataInfo;
@protocol PPYDataInfoDelegate <NSObject>
@optional
//更新统计信息，每分钟回调一次
- (void)dataInfoDidUpdate:(PPYDataInfo *)dataInfo;
@end

@interface PPYDataInfo : NSObject
/**
 推拉默认码率(推流时选择的默认码率)
 */
@property (nonatomic, assign, readonly) NSInteger bitrate;

/**
 推流默认帧率(流时选择的默认帧率)
 */
@property (nonatomic, assign, readonly) NSInteger fps;

/**
 平均码率(每分钟)
 */
@property (nonatomic, assign, readonly) NSInteger bitrateAvg;

/**
 平均帧率（每分钟）
 */
@property (nonatomic, assign, readonly) NSInteger fpsAvg;

/**
 推流延时
 */
@property (nonatomic, assign, readonly) NSInteger publishDelay;

/**
 推流清晰度（推流时选择的清晰度1=流畅档、2=高清档、3=超清档）
 */
@property (nonatomic, assign, readonly) NSInteger publishDt;

/**
 推流网络（推流的网络条件1=WiFi、2=4G、3=3G、4=2G）
 */
@property (nonatomic, assign, readonly) NSInteger networkState;
/**
 推流时长（毫秒）
 */
@property (nonatomic, assign, readonly) NSInteger publishDuration;

/**
 推流错误（错误码参照wiki-pplive-sdk:http://wiki.cnsuning.com/pages/viewpage.action?pageId=33402049）
 */
@property (nonatomic, assign, readonly) NSInteger publishErrorCode;

@property (nonatomic, weak) id <PPYDataInfoDelegate> delegate;
@end

