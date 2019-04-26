//
//  PPTVSdk.h
//  PPTVSdk
//
//  Created by 张博bobzhang on 15/10/8.
//  Copyright © 2015年 PPTV. All rights reserved.
//

/*!
 @brief 实现初始化以及播放串相关操作
 @version 1.00 2015/11/20 Creation
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "PPTVSdk.h"
#import "PPTVPlayerSdk.h"
#import "PPTVDlnaSdk.h"
#import "PPTVAccountSdk.h"
#import "PPTVDownloadSdk.h"

/*! SDKType 默认使用sdk内部播放器 */
typedef NS_OPTIONS(NSUInteger, PPTVSdkType) {
    /*!  启用DMC */
    DLNA_DMC = 1,
    
    /*!  启用DMR */
    DLNA_DMR = 1<<1,
    
    /*!  启用DMS */
    DLNA_DMS = 1<<2,
    
    /*!  启用DMP */
    DLNA_DMP = 1<<3,
    
    /*!  不启用ppmediaplayer */
    NOPPMEDIAPLAYER = 1<<4
};

/**
 *  实现SDK基本功能,支持ios8.0及以上版本
 */
@interface PPTVSdk : NSObject

/*!
 @brief 单例化
 */
+ (instancetype)sharedPPTVSdk;

/*!
 @brief 初始化
 @discussion 注意params的格式以及里面的参数,其中tunnel必须有, 直播流畅率加入baseLogDir, baseLogMaxSize参数
 @param url 表示域名配置地址,默认为空
 @param params 如params = "sdktype=17&tunnel=xxx", 其中sdktype: SDKType的组合，例如sdktype 的值为 DLNA_DMC|DLNA_DMR|NOPPMEDIAPLAYER
 @param path 表示日志文件路径,默认传空
 @return 初始化成功之后返回YES,否则NO
 */
- (BOOL)initializeWithUrl:(NSString *)url params:(NSString *)params logPath:(NSString *)path;

/*!
 @brief 反初始化
 @discussion 释放sdk
 */
- (void)unit;

@end
