//
//  PPYMediaInfo.h
//  PPYLiveKit
//
//  Created by jacksimjia on 2017/3/21.
//  Copyright © 2017年 PPTV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PPYMediaEffectType) {
    PPYMediaEffectTypeUnKnown = -1, //未知类型
    PPYMediaEffectTypeVideoAudio = 0, //音视频
    PPYMediaEffectTypeVideo = 1, //视频
    PPYMediaEffectTypeAudio, //音频
    PPYMediaEffectTypeText, //文字
    PPYMediaEffectTypePNG, //png图片
    PPYMediaEffectTypeJPEG, //jpeg图片
    PPYMediaEffectTypeFilter, //滤镜
    PPYMediaEffectTypeTransition //转场
};
/**滤镜类型*/
typedef NS_ENUM(NSInteger, PPYMediaEffectFilterType) {
    PPYMediaEffectFilterTypeNone = -1,  //无
    PPYMediaEffectFilterTypeRGB = 0,    //RGB
    PPYMediaEffectFilterTypeSketch = 1, //素描
    PPYMediaEffectFilterTypeAMARO = 2,
    PPYMediaEffectFilterTypeANTIQUE = 3,
    PPYMediaEffectFilterTypeBLACKCAT = 4,
    PPYMediaEffectFilterTypeBEAUTY = 5,
    PPYMediaEffectFilterTypeBRANNAN = 6,
    PPYMediaEffectFilterTypeN1977 = 7,
    PPYMediaEffectFilterTypeBROOKLYN = 8,
    PPYMediaEffectFilterTypeCOOL = 9,
    PPYMediaEffectFilterTypeCRAYON = 10,
};

/**图片类型*/
typedef NS_ENUM(NSInteger, PPYMediaEffectImageType) {
    PPYMediaEffectImageTypePNG,
    PPYMediaEffectImageTypeJPEG,
};

/** 媒体资源 */
@interface PPYMediaInfo : NSObject

@property (nonatomic, strong) NSString *mediaPath;
@property (nonatomic, assign) NSTimeInterval startPosition; /**<视频的开始时间 (毫秒)*/
@property (nonatomic, assign) NSTimeInterval endPosition; /**<视频的结束时间 (毫秒)*/
@property (nonatomic, assign) float speed; /**<视频的播放速度 (>=0)*/
@property (nonatomic, assign) float volume; /**<视频的音量 (0-1.0)*/
/**初始化 媒体文件资源路径*/
- (instancetype)initWithMediaPath:(NSString *)mediaPath;
@end

/** 各种特效父类 */
@interface PPYMediaEffect : NSObject
@property (nonatomic, readonly) PPYMediaEffectType effectType;
@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, assign) NSTimeInterval effectInTimePosition; /**<特效的开始时间位置 (毫秒)*/
@property (nonatomic, assign) NSTimeInterval effectOutTimePosition; /**<特效的结束时间位置 (毫秒)*/
@property (nonatomic, assign) float speed;

/**初始化 特效文件资源路径*/
- (instancetype)initWithFilePath:(NSString *)filePath;
@end

/** 滤镜 */
@interface PPYMediaEffectFilter : PPYMediaEffect
@property (nonatomic, assign) PPYMediaEffectFilterType filterType;
@end

/** 图片 */
@interface PPYMediaEffectImage : PPYMediaEffect
@property (nonatomic, assign) PPYMediaEffectImageType imageType; /**<图片类型(PNG,JPEG等)*/
@property (nonatomic, assign) CGPoint point; /**<图片的位置*/
@property (nonatomic, assign) CGFloat scale;
@end

/** 音频 */
@interface PPYMediaEffectAudio : PPYMediaEffect
@property (nonatomic, assign) float volume; /**<音频音量 0.0-1.0*/
@property (nonatomic, assign) NSTimeInterval startPosition; /**<音频的开始时间 (毫秒)*/
@property (nonatomic, assign) NSTimeInterval endPosition; /**<音频的结束时间 (毫秒)*/

@end

/** 转场 */
@interface PPYMediaEffectTranstion : PPYMediaEffect

@end

/** 文字 */
@interface PPYMediaEffectText : PPYMediaEffect

@end
