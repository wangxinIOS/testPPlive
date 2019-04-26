//
//  PPTVPlayerSdk.h
//  PPTVSdkDemo
//
//  Created by bobzhang on 15/11/30.
//  Copyright © 2015年 PPTV. All rights reserved.
//

/*!
 @header PPTVPlayerSdk
 @brief 实现视频播放相关操作
 @version 1.00 2015/11/30 Creation
 */

//重新播放通知, 接收到通知后需要调用reReadyPlay接口重新播放
#define PPTVPlayInfoNeedRetryNotification        @"PPTVPlayInfoNeedRetryNotification"  //alive失效后, 重新请求播放串

#import <Foundation/Foundation.h>

@class PPTVDownloadInfo;
@class AVPlayerLayer;


/*! 播放类型 */
typedef NS_OPTIONS(NSUInteger, PPTVPlayType) {
    PPTVPlayTypeUnknown     = 0,        /*!  未知 */
    
    PPTVPlayTypeVod         = 1,        /*!  点播 */
    PPTVPlayTypeLive        = 2,        /*!  直播 */
    PPTVPlayTypeRtmp        = 3,        /*!  RTMP 直播 */
    PPTVPlayTypeLocal       = 4,        /*!  本地播放 */
    
    PPTVPlayTypeDlnaVod     = 11,       /*!  DLNA点播 */
    PPTVPlayTypeDlnaLive    = 12,       /*!  DLNA直播 */
    PPTVPlayTypeDlnaRtmp    = 13,       /*!  DLNA RTMP直播 */
    PPTVPlayTypeDlnaLocal   = 14        /*!  DLNA推送本地播放 */
};

/*! 视频填充模式 */
typedef NS_ENUM(NSUInteger, PPTVVideoFillModel) {
    PPTVVideoFillModelBothFill,         /*!  视频宽度和高度全部填充满 */
    PPTVVideoFillModelWidthFill,        /*!  视频宽度填充满 */
    PPTVVideoFillModelHeightFill,       /*!  视频高度填充满 */
    PPTVVideoFillModelOriginalFill,     /*!  原始视频填充模式 */
};

typedef NS_ENUM(NSUInteger, PPTVAdType) {
    PPTVAdTypeBuffer,               /*!  前贴广告 */
    PPTVAdTypePause,                /*!  暂停广告 */
};

/**
 *  广告回调
 */
@protocol PPTVADViewDelegate <NSObject>
@optional

/*!
 @brief 广告开始
 @param adType 广告类型
 @discussion 包含前贴,暂停广告
 */
- (void)adViewDidShow:(PPTVAdType)adType;

/*!
 @brief 广告结束
 @param adType 广告类型
 @discussion 包含前贴,暂停广告
 */
- (void)adViewDidFinish:(PPTVAdType)adType;

@end


/**
 *  自有播放器播放的回调
 */
@protocol PPTVMediaPlayerDelegate <NSObject>
@optional
/*!
 @brief 请求播放串失败
 @param error 错误信息
 */
- (void)playerLoadPlaylinkFailed:(NSError *)error;

/*!
 @brief 视频加载失败
 @param error 错误信息
 */
- (void)playerLoadFailedWithError:(NSError *)error;

/*!
 @brief 加载完成
 @discussion  表示播放加载完成
 */
- (void)playerLoadFinished;

/*!
 @brief 缓冲中
 @discussion  每一次卡顿,缓冲
 */
- (void)playerBuffering;

/*!
 @brief 缓冲完成
 @discussion  每一次卡顿,缓冲完成
 */
- (void)playerBufferFinished;

/*!
 @brief 播放结束
 */
- (void)playBackDidFinished;

/*!
 @brief 节目总时间
 @discussion  只有点播才能获取节目总时间
 @param duration 节目总时间(单位秒)
 */
- (void)playerDurationAvailable:(NSTimeInterval)duration;

/*!
 @brief 播放状态
 @param isPlaying 当前视频是否正在播放中
 */
- (void)playBackStateChanged:(BOOL)isPlaying;

/*!
 @brief airPlay状态
 @discussion  根据isActive的值, 来判断当前时候是AirPlay状态
 @param isActive 是否是airPlay状态
 */
- (void)playerShowOnAirPlay:(BOOL)isActive;

@end


//扩展信息
@interface PPTVExtendInfo : NSObject

@property (nonatomic, strong) NSString *category;        //分类
@property (nonatomic, strong) NSString *source;          //播放来源
@property (nonatomic, strong) NSString *pushID;          //推送id
@property (nonatomic, strong) NSString *tokenID;         //个推client id
@property (nonatomic, strong) NSString *isCharge;        //是否收费
@property (nonatomic, strong) NSString *programType;     //节目性质
@property (nonatomic, strong) NSString *carrierSet;      //运营商套餐

@end

/**
 *  实现基本播放功能
 */
@interface PPTVPlayerSdk : NSObject

/*!
 @brief 使用内置播放器时, 设置Player回调函数
 */
@property (nonatomic, weak) id<PPTVMediaPlayerDelegate> playerDelegate;

/*!
 @brief 使用内置播放器时, 设置广告回调函数
 */
@property (nonatomic, weak) id<PPTVADViewDelegate> ADViewDelegate;

/*!
 @brief 播放页面视图, 主要是为了处理播放器的UI部分
 */
@property (nonatomic, strong) UIView          *playerView;

/*!
 @brief 播放图层, 主要是为了上层配合AVPictureInPictureController实现画中画功能
 */
@property (nonatomic, strong) AVPlayerLayer   *playerLayer;

/*!
 @brief 是否支持autolayout布局, 默认为NO
 */
@property (nonatomic, assign) BOOL             isSupportAutolayout;

/*!
 @brief 所有支持的码流列表
 */
@property (nonatomic, readonly) NSArray       *ftList;

/*!
 @brief 当前的码流数据 
 */
@property (nonatomic, readonly) NSString      *currentFt;

/*!
 @brief 当前速度
 @discussion 单位 byte
 */
@property (nonatomic, readonly) long           curSpeed;

/*!
 @brief 播放器声音
 @discussion 默认值1, 范围: 0.0 ~ 1.0f, 需要在播放开始调用
 */
@property (nonatomic, assign)  float           volume;

/*!
 @brief 是否正在播放 
 */
@property (nonatomic, readonly) BOOL           isPlaying;

/*!
 @brief 是否准备完成
 */
@property (nonatomic, readonly) BOOL           isPreparedToPlay;

/*!
 @brief 网络缓存到的位置（单位：秒）
 */
@property (nonatomic, readonly) NSTimeInterval bufferedSecondsPosition;

/*!
 @brief 播放总时长（单位：秒）
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/*!
 @brief 当前播放时间（单位：秒）
 */
@property (nonatomic, readonly) NSTimeInterval currentPlaybackTime;


/*!
 @brief 初始化播放器SDK
 @return instancetype
 */
- (instancetype)initPlayer;

/*!
 @brief 设置播放信息, 准备播放
 @discussion 注意params的格式以及参数, 
    其中playType为PPTVPlayTypeVod/PPTVPlayTypeLive时正常初始化,
    playType为PPTVPlayTypeLocal为本地播放，可播放下载的视频
 @param params 例如 param: vid=%@&ft=%@&playType=%@&ppType=%@
 */
- (void)prepareToPlayWithInfo:(NSString *)params;

/**
 *  @brief 重新请求播放
 *  @discussion 当网络状态变化, 比如3G/wifi切换时, 或者是长进入后台导致alive失败(需要添加PPTVPlayInfoNeedRetryNotification监听), 开始播放正片后才可以调用
 */
- (void)reReadyPlay;

/*!
 @brief 设置播放扩展信息
 @param extendInfo PPTVExtendInfo对象
 */
- (void)setPlayExtendInfo:(PPTVExtendInfo *)extendInfo;

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
 */
- (void)stop;

/*!
 @brief 清空播放相关
 @discussion 退出播放页面或者释放播放器时调用
 */
- (void)clearPlayer;

/*!
 @brief 按时间点检索
 @discussion 设置视频进度
 @param position 时间点s
 */
- (void)seekToPosition:(float)position;

/*!
 @brief 切换码流
 @discussion 当前视频有多个码流的时候, 可以直接调用此接口切换码流播放
 @param ft 码流
 @param seekTime 点播时表示当前播放时间, 直播时表示当前播放时间点与最新时间的差值, 单位s
 */
- (void)changeStreamWithFt:(NSString *)ft andSeekTime:(float)seekTime;

/*!
 @brief 修改视频屏幕填充模式 PPTVVideoFillModel
 @param model 视频页面填充模式
 */
- (void)changeVideoFillModel:(PPTVVideoFillModel)model;

/*!
 @brief 根据下载任务信息播放
 @param showInfo PPTVDownloadInfo:已有的PPTVDownloadInfo对象
 */
- (void)prepareToPlayWithDownloadInfo:(PPTVDownloadInfo *)showInfo;

/*!
 @brief 设备倍数播放
 @param playrate 区间[0.5,2]，1为正常播放
 */
- (void)setPlayRate:(NSTimeInterval)playrate;

@end
