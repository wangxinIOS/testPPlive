//
//  PPYPushEngine.h
//  PPYLiveKit
//
//  Created by Jimmy on 16/8/22.
//  Copyright © 2016年 高国栋. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "PPYVideoConfiguration.h"
#import "PPYAudioConfiguration.h"

typedef NS_ENUM(NSUInteger, PPYPushEngineStreamStatus){
    PPYConnectionState_Connecting, //连接中
    PPYConnectionState_Connected, //连接成功
    PPYConnectionStatus_Started, //开始推流
    PPYConnectionStatus_Ended, //推流结束
    PPYConnectionStatus_ReConnecting, //推流已中断，重新推流中
};
//错误类型
typedef NS_ENUM (int,PPYPushEngineErrorType)  {
    PPYPushEngineError_Unknow = -1, //未知错误
    PPYPushEngineError_ConnectFailed = 0, //连接失败
    PPYPushEngineError_TransferFailed = 1, //数据包发送失败
    PPYPushEngineError_ColorSpaceConverFail, //图像转化失败
    PPYPushEngineError_VideoEncodeFail = 3, // 视频编码失败
    PPYPushEngineError_AudioCaptureStartFail = 4, //音频捕获开启失败
    PPYPushEngineError_AudioEncodeFail = 5, //音频编码失败
    PPYPushEngineError_AudioCaptureStopFail, //音频捕获停止失败
    PPYPushEngineError_PoorNetwork = 7, //网络不稳定
    PPYPushEngineError_AudioFilterFail = 8, //音频过滤失败
    PPYPushEngineError_OpenVideoEncoderFail = 9, //打开视频编码器失败
};

typedef NS_ENUM(int,PPYPushEngineStreamInfoType){
    PPYPushEngineInfo_PublishDelayTime = 1, //推流延时
    PPYPushEngineInfo_RealBirate, //实时码率
    PPYPushEngineInfo_RealFPS, //实时帧率
    PPYPushEngineInfo_DowngradeBitrate, //降低码率
    PPYPUshEngineInfo_UpgradeBitrate, //提升码率
    PPYPushEngineInfo_PublishTime, //录制时长(录制模式下返回)
    PPYPushEngineInfo_AudioInputDataLost, //音频流丢失
};
typedef NS_ENUM(NSInteger,PPYPushEngineStreamNetworkState){
    ///网络正常,流畅(几乎没有延时或延时比较小)
    PPYPushEngineStreamNetworkStateNormal,
    ///网络比较慢(延时超过2秒)
    PPYPushEngineStreamNetworkStateSlow,
    ///网络非常慢(延时超过4秒)
    PPYPushEngineStreamNetworkStateVerSlow,
    ///网络故障(延时超过8秒)
    PPYPushEngineStreamNetworkStateFailure,
    
};
@class PPYDataInfo;

@protocol  PPYPushEngineDelegate <NSObject>
@optional

/**
 推流状态更新回调
 */
- (void)didStreamStateChanged:(PPYPushEngineStreamStatus)status;

/**
 推流出错
 */
- (void)didStreamErrorOccured:(PPYPushEngineErrorType)error;

/**
 推流信息更新回调
 @param type 更新的数据类型
 @param value 数据的值
 */
- (void)didStreamInfoThrowOut:(PPYPushEngineStreamInfoType)type infoValue:(int)value;

/**
 数据统计更新回调 (每分钟回调一次)
 @param dataInfo 统计信息
 */
- (void)didUpdateDataInfo:(PPYDataInfo *)dataInfo;

/**
 推流网络状态变化
 */
- (void)didStreamPublishNetworkStateChanged:(PPYPushEngineStreamNetworkState)networkState;
@end


///推流引擎
@interface PPYPushEngine : NSObject

@property (nonatomic, weak) id<PPYPushEngineDelegate> delegate;
#pragma --Capture Interface--
/**
 相机是否开启运行
 */
@property (nonatomic, assign, getter=isRunning) BOOL running;
/**
 摄像头位置 （前置摄像头或后置摄像头）
 */
@property (nonatomic, assign) AVCaptureDevicePosition cameraPosition;
/**
 预览的视图
 */
@property (nonatomic, strong) UIView *preview;

/**
 镜像模式（defalut is NO;）
 */
@property (assign, nonatomic,getter=isMirror)   BOOL mirror;
/**
 是否支持闪光灯
 */
@property (assign, nonatomic, readonly) BOOL hasTorch;
/**
 闪光灯是否开启
 */
@property (assign, nonatomic,getter=isTorch)    BOOL torch;  //default is NO;
/**
 是否支持自动对焦
 */
@property (assign, nonatomic, readonly) BOOL hasFocus;
/**
 是否自动对焦（if no focus func, ignored!）
 */
@property (assign, nonatomic,getter=isAutoFocus) BOOL autoFocus;
/**
 是否开启美颜 defalut is YES
 */
@property (assign, nonatomic,getter=isBeautify) BOOL beautify;
/**
 美颜参数（default is 0.5, range 0~1;）
 */
@property (nonatomic, assign) CGFloat beautyLevel;
/**
 亮度参数（default is 0.5, range 0~1;）
 */
@property (nonatomic, assign) CGFloat brightLevel;
/**
 色调（default is 0.5, range 0~1;）
 */
@property (nonatomic, assign) CGFloat toneLevel;
///静音
@property (nonatomic, assign, getter=isMute) BOOL mute; //default is NO;
//对焦
- (void)doFocusOnPoint:(CGPoint)aPoint onView:(UIView*)view needDisplayLocation:(BOOL)isNeeded;

/**
 * 网络适应的最低码率 (单位kbps)
 * @discussion 网络不稳定的时候，会引起降码率，设置一个可允许的最低码率，默认值 800kbps
 */
@property (nonatomic, assign) NSInteger networkAdaptiveMinVideoBitrate;
/**
 * 网络适应的最低帧率 (单位fps)
 * @discussion 网络不稳定的时候，会引起降帧率，设置一个可允许的最低码率，默认值 18 fps
 */
@property (nonatomic, assign) NSInteger networkAdaptiveMinFps;
/**
 是否开启网络自适应 (默认NO 关闭)
 */
@property (nonatomic, assign) BOOL isEnableNetworkAdaptive;
#pragma -- Interface--

/**
 初始化方法
 @param audioConfig 音频配置
 @param videoConfig 视频配置
 */
- (instancetype)initWithAudioConfiguration:(PPYAudioConfiguration *)audioConfig
                     andVideoConfiguration:(PPYVideoConfiguration *)videoConfig;

/**
 *  设置推流引擎 (只需要设置一次即可)
 *   @param pushAddress 推流地址(若为远程地址，请设置支持RTMP协议的地址；若为本地地址，则会录制视频到本地)
 */
- (void)setupPublishEngineWithAddress:(NSString *)publishAddress;

#pragma --Push Interface--
///开始推流
- (void)start;
///停止推流
- (void)stop;


///暂停(录制模式下使用，推流模式下不可用)
- (void)pause;
///继续(录制模式下使用，与pause方法对应，推流模式下不可用)
- (void)resume;

/**
 获取指定视频的时长(注意：此方法为同步方法)
 @param inputMediaFile 视频本地路径
 @return 返回视频的时长，毫秒
 */
- (NSTimeInterval)syncGetMediaDurationWithInputFile:(NSString*)inputMediaFile;

/**
 *  截屏，获取当前相机捕获的画面
 */
- (UIImage *)screenshot;

/**
 指定区域截图
 
 @param rect 区域坐标 (此坐标为相对预览画面(preview)的坐标)
 @return 指定区域的截图图片
 */
- (UIImage *)screenshotFromRect:(CGRect)rect;

/**
 统计数据信息
 */
- (PPYDataInfo *)getDataInfo;

/**
 上传推流日志
 @param message 上传日志的消息内容
 @param completion 上传完成的回调（code==0表示成功）
 */
- (void)uploadLogsWithMessage:(NSString *)message
                   completion:(void (^)(NSInteger code, NSString *msg, NSError *error))completion;

- (instancetype)init NS_UNAVAILABLE;

//for DAC
@property (nonatomic, assign) long vid;
@property (nonatomic, assign) NSInteger protocol;
@property (nonatomic, assign) NSInteger dt;
@property (nonatomic, strong) NSString *clent;
@end
