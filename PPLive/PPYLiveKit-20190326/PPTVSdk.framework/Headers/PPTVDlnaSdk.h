//
//  PPTVDlnaSdk.h
//  PPTVSdkDemo
//
//  Created by 张艳艳 on 15/11/30.
//  Copyright © 2015年 PPTV. All rights reserved.
//

/*!
 @header PPTVDlnaSdk
 @brief 实现DLNA推送相关操作
 @version 1.00 2015/11/30 Creation
 */

#import <Foundation/Foundation.h>

/**设备名称*/
#define kPPDLNADeviceNameKey @"PPDLNADeviceName"
/**设备唯一标识*/
#define kPPDLNADeviceUUIDKey @"PPDLNADeviceUUID"

/*! PPTVDlnaPlayState DLNA设备当前状态 */
typedef NS_OPTIONS(NSUInteger, PPTVDlnaPlayState) {
    PPTVDlnaPlayStatePlaying            = 0,      /*!  dlna播放中 */
    PPTVDlnaPlayStateStop               = 1,      /*!  dlna播放停止 */
    PPTVDlnaPlayStatePause              = 2,      /*!  dlna播放暂停 */
    PPTVDlnaPlayStateBuffering          = 4,      /*!  dlna播放加载中 */
    PPTVDlnaPlayStateDeviceDisconnect   = 5,      /*!  dlna设备丢失 */
    PPTVDlnaPlayStateDeviceReconnect    = 6,      /*!  dlna设备重连 */
};

/**
 *  DLNA播放的回调
 */
@protocol PPTVDlnaDelegate <NSObject>
@required

/*!
 @brief DLNA请求play失败
 @param error 失败信息
 */
- (void)dlnaLoadPlaylinkFailed:(NSError *)error;

/*!
 @brief DLNA播放失败
 @discussion 通知用户, DLNA播放失败
 @param error 错误信息
 */
- (void)dlnaDevicePlayFailed:(NSError *)error;

/*!
 @brief DLNA开始播放
 @discussion 通知用户, DLNA开始播放
 */
- (void)dlnaDevicePlaying;

/*!
 @brief 更新DLNA播放进度
 @discussion  根据totalDuration获取视频总时间, curPosition获取当前播放时间, 然后更新DLNA播放信息
 @param totalDuration 视频总时间
 @param curPosition 当前播放时间
 */
- (void)dlnaUpdateTimeInfoWithTotalDuration:(NSInteger)totalDuration andCurPosition:(NSInteger)curPosition;

/*!
 @brief DLNA播放状态
 @discussion 根据playState,来判断当前的状态
 @param playState DLNA播放状态 PPTVDlnaPlayState
 */
- (void)dlnaPlayStateChangedWithState:(PPTVDlnaPlayState)playState;

/*!
 @brief DLNA播放结束回调
 */
- (void)dlnaPlayBackDidFinished;

@end

/**
 *  实现DLNA推送功能
 */
@interface PPTVDlnaSdk : NSObject

/*! 
 @brief 代理, 实现PPTVDlnaDelegate回调
 */
@property (nonatomic, weak) id<PPTVDlnaDelegate> dlnaDelegate;

/*!
 @brief 当前DLNA设备名称列表
 */
@property (nonatomic, strong, readonly) NSMutableArray<NSDictionary *> *deviceNameList;

/*!
 @brief 当前推送设备的名称
 */
@property (nonatomic, strong, readonly) NSDictionary *curDeviceInfo;

/*!
 @brief 所有支持的码流列表
 */
@property (nonatomic, readonly) NSArray<NSDictionary *> *ftList;

/*!
 @brief 当前的码流
 */
@property (nonatomic, readonly) NSString     *currentFt;

/*!
 @brief  设置dlna设备音量
 @discussion  范围:0.0~100.0
 */
@property (nonatomic, assign)  float        volume;

/*!
 @brief 播放总时长（单位：秒）
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/*!
 @brief 当前播放时间（单位：秒）
 */
@property (nonatomic, readonly) NSTimeInterval currentPlaybackTime;

/*!
 @brief 单例化
 */
+ (PPTVDlnaSdk *)sharedPPTVDlnaSdk;

/*!
 @brief 主动刷新DLNA设备
 @discussion  通过deviceNameList,假如没有获取到设备列表, 可以主动调用此接口来刷新. 正常情况不需要调用.
 */
- (void)refreshDevice;

/*!
 @brief 选择DLNA设备
 @discussion  通过deviceNameList获取设备列表, 然后选择列表中的设备
 @param index  deviceNameList获取的设备列表中的位置index
 */
- (void)selectedOneDevice:(NSInteger)index;

/*!
 @brief 设置DLNA播放信息, 进行DLNA推送播放
 @discussion 要先调用selectedOneDevice:方法,设置选择的dlna设备,同时注意params的格式以及参数
 @param params 例如 param: encodeurl=%@&ft=%@&playerType=%@&ppType=%@
 */
- (void)prepareToPlayWithDlnaInfo:(NSString *)params;

/*!
 @brief 开始播放
 */
- (void)play;

/*!
 @brief 暂停播放
 */
- (void)pause;

/*!
 @brief 停止播放
 @discussion 退出DLNA播放时, 需要调用
 */
- (void)stop;

/*!
 @brief 设置视频进度
 @param value  时间点,单位s
 */
- (void)seekToPosition:(float)value;

/*!
 @brief 切换码流
 @discussion 当前视频有多个码流的时候, 可以直接调用此接口切换码流播放
 @param ft 码流
 */
- (void)changeStreamWithFt:(NSString *)ft;


@end
