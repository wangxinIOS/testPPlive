//
//  PPYVideoConfiguration.h
//  PPYLiveKit
//
//  Created by Jimmy on 16/8/22.
//  Copyright © 2016年 高国栋. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
typedef NS_ENUM( NSUInteger, PPYCaptureSessionPreset){
    PPYCaptureSessionPreset360x640 = 0, //360P
    PPYCaptureSessionPreset540x960 = 1, //540P
    PPYCaptureSessionPreset720x1280 = 2, //720P
    PPYCaptureSessionPreset1080x1920 = 3, //1080P
    PPYCaptureSessionPresetDefault = PPYCaptureSessionPreset540x960, //默认540P
};

//视频帧率
typedef NS_ENUM(NSUInteger, PPYCaptureFPS){
    PPYCaptureFPSLow = 15,
    PPYCaptureFPSMedium = 20,
    PPYCaptureFPSHigh = 30
};

//视频质量
typedef NS_ENUM(NSUInteger, PPYVideoQuality){
    /// 分辨率： 360 *640 帧数：15 码率：600Kps
    PPYVideoQuality_Low1 = 0,
    /// 分辨率： 360 *640 帧数：20 码率：800Kps
    PPYVideoQuality_Low2 = 1,
    
    /// 分辨率： 540 *960 帧数：15 码率：750Kps
    PPYVideoQuality_Medium1 = 3,
    /// 分辨率： 540 *960 帧数：20 码率：1024Kps
    PPYVideoQuality_Medium2 = 4,
    
    /// 分辨率： 720 *1280 帧数：15 码率：1.0Mps
    PPYVideoQuality_High1 = 5,
    /// 分辨率： 720 *1280 帧数：20 码率：1.4Mps
    PPYVideoQuality_High2 = 6,
    
    ///分辨率： 1080 * 1920 帧数: 20 码率:2Mps
    PPYVideoQuality_High3 = 7,
    
    /// 默认配置
    PPYVideoQuality_Default = PPYVideoQuality_Low2
};

//编码模式
typedef NS_ENUM(NSInteger,PPYPublishEncodeMode) {
    ///硬编
    PPYPublishEncodeModeHardware = 0,
    ///软编
    PPYPublishEncodeModeSoftware,
};

@interface PPYVideoConfiguration : NSObject

/**
 默认初始化（分辨率： 360 *640 帧数：15 码率：800Kps）
 */
+ (instancetype)defalutVideoConfiguration;

/**
 根据视频质量来设置初始化
 @param videoQuality 视频质量
 */
+ (instancetype)videoConfigurationWithVideoQuality:(PPYVideoQuality)videoQuality;

/**
 设置详细参数初始化
 @param videoPreset 视频清晰度
 @param fps 帧率
 @param bitrate 码率 (单位kbps，1M = 1024kbps)
 */
+ (instancetype)videoConfigurationWithPreset:(PPYCaptureSessionPreset)videoPreset andFPS:(PPYCaptureFPS)fps andBirate:(int)bitrate; //kbps

///视频帧率
@property (nonatomic, assign, readonly) int fps;
///视频码率
@property (nonatomic, assign, readonly) int birate;
///视频捕获的清晰度
@property (nonatomic, assign, readonly) PPYCaptureSessionPreset capturePreset;
///视频分辨率大小
@property (nonatomic, assign, readonly) CGSize videoSize;
/**
 推流编码模式(默认硬编，请在推流之前设置)
 */
@property (nonatomic, assign) PPYPublishEncodeMode encodeMode;


- (instancetype)init NS_UNAVAILABLE;
@end
