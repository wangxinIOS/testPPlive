//
//  PPYPlayEngine.h
//  PPYLiveKit
//
//  Created by Jimmy on 16/9/19.
//  Copyright © 2016年 高国栋. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//资源类型
typedef NS_ENUM(int,PPYSourceType){
    PPYSourceType_VOD = 1,    //m3u8
    PPYSourceType_Live = 2,   //rtmp, flv-http,
    PPYSourceType_RTSP = 3
};
//错误类型
typedef NS_ENUM (int,PPYPlayEngineErrorType)  {
    PPYPlayEngineError_InvalidSourceURL,//无效的播放地址
    PPYPlayEngineError_ConnectFailed, //视频连接出错
    PPYPlayEngineError_TransferFailed, //视频转码失败
    PPYPlayEngineError_FatalError, //视频内部错误
};
//播放信息类型
typedef NS_ENUM (int,PPYPlayEngineInfoType)  {
    PPYPlayEngineInfo_BufferingDuration, //视频缓冲时长
    PPYPlayEngineInfo_RealBirate, //视频码率
    PPYPlayEngineInfo_RealFPS,  //视频帧率
    PPYPlayEngineInfo_BufferingUpdatePercent, //VOD only，缓冲百分比
    PPYPlayEngineInfo_Duration,               //视频准备完成，获取到视频时长
    PPYPlayEngineInfo_CurrentPlayBackTime,    //VOD only，视频当前播放时间
};
//播放状态
typedef NS_ENUM(NSUInteger, PPYPlayEngineStatus){
    PPYPlayEngineStatus_StartCaching, //开始缓冲
    PPYPlayEngineStatus_EndCaching, //结束缓冲
    PPYPlayEngineStatus_FisrtKeyFrameComing, //获取到视频首帧
    PPYPlayEngineStatus_RenderingStart,//开始播放
    PPYPlayEngineStatus_ReceiveEOF, //播放结束 tmp: receive eof to end, need reconnect;
    PPYPlayEngineStatus_SeekComplete,  //VOD only，VOD播放模式下seek完成
};
//视频缩放模式
typedef NS_ENUM(NSUInteger, PPYPlayEngineScaleMode){
    PPYPlayEngineScaleModeScaleToFill = 0,
    PPYPlayEngineScaleModeScaleAspectFit = 1, //等比缩放
    PPYPlayEngineScaleModeScaleFitWidthCroping = 2  // 全屏铺满 (部分画面会被裁剪)
};
//播放器回调
@protocol PPYPlayEngineDelegate <NSObject>
//播放器异常回调
- (void)didPPYPlayEngineErrorOccured:(PPYPlayEngineErrorType)error;
//播放器信息回调
- (void)didPPYPlayEngineInfoThrowOut:(PPYPlayEngineInfoType)type andValue:(int)value;
//播放器状态回调
- (void)didPPYPlayEngineStateChanged:(PPYPlayEngineStatus)state;
//播放器视频大小发生变化
- (void)didPPYPlayEngineVideoResolutionCaptured:(int)width VideoHeight:(int)height;
@end

@interface PPYPlayEngine : NSObject

@property (copy, readonly, nonatomic) NSString *playURL;
@property (assign, nonatomic ,readonly) PPYSourceType sourceType;
@property (assign, nonatomic) CGRect previewRect;

@property (weak, nonatomic) id<PPYPlayEngineDelegate> delegate;

/**
    设置视频宽高自适应，默认 PPYPlayEngineScaleModeScaleFitWidthCroping
 */
@property (assign, nonatomic) PPYPlayEngineScaleMode scaleMode;
///单例方法
+ (instancetype)shareInstance;


/**
 设置播放地址

 @param url 播放地址(在线地址，或本地地址)
 @param sourceType 播放的类型
 */
- (void)startPlayFromURL:(NSString *)url WithType:(PPYSourceType)sourceType;

/**
 停止播放
 @param yesOrNo 是否显示黑屏
 */
- (void)stopPlayerBlackDisplayNeeded:(BOOL)yesOrNo;

/**
 把视频画面展示在指定的view
 @param view 需要显示视频的视图
 */
- (void)presentPreviewOnView:(UIView *)view;

/**
 取消视频预览到指定的视图上
 */
- (void)disappearPreview;

/*** VOD only **/
///视频时长
@property (nonatomic, readonly) NSTimeInterval duration;
///当前播放时间
@property (nonatomic, readonly) NSTimeInterval currentPlaybackTime;

///暂停
- (void)pause;
///继续
- (void)resume;

/**
 seek视频到指定时间
 @param seekTime seek时间，单位毫秒
 */
- (void)seekToPosition:(NSTimeInterval)seekTime;



//test
@property (nonatomic, assign) long vid;
@property (nonatomic, assign) NSInteger pt;
@property (nonatomic, assign) NSInteger protocol;
@property (nonatomic, assign) NSInteger dt;
@property (nonatomic, strong) NSString *clent;
@end
