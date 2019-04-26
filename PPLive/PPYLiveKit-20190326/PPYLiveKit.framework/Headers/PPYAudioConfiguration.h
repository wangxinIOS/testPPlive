//
//  PPYAudioConfiguration.h
//  PPYLiveKit
//
//  Created by Jimmy on 16/8/22.
//  Copyright © 2016年 高国栋. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 音频码率
typedef NS_ENUM (NSUInteger, PPYAudioBitRate) {
    /// 32Kbps 音频码率
    PPYAudioBitRate_32Kbps = 32000,
    /// 64Kbps 音频码率
    PPYAudioBitRate_64Kbps = 64000,
    /// 96Kbps 音频码率
    PPYAudioBitRate_96Kbps = 96000,
    /// 128Kbps 音频码率
    PPYAudioBitRate_128Kbps = 128000,
    /// 默认音频码率，默认为 64Kbps
    PPYAudioBitRate_Default = PPYAudioBitRate_64Kbps
};

/// 采样率 (默认44.1Hz iphoneg6以上48Hz)
typedef NS_ENUM (NSUInteger, PPYAudioSampleRate){
    /// 44.1Hz 采样率
    PPYAudioSampleRate_44100Hz = 44100,
    /// 48Hz 采样率
    PPYAudioSampleRate_48000Hz = 48000,
    /// 默认音频码率，默认为 64Kbps
    PPYAudioSampleRate_Default = PPYAudioSampleRate_44100Hz
};

///  Audio Live quality（音频质量）
typedef NS_ENUM (NSUInteger, PPYAudioQuality){
    /// 高音频质量 audio sample rate: 44MHz(默认44.1Hz iphoneg6以上48Hz), audio bitrate: 32Kbps
    PPYAudioQuality_Low = 0,
    /// 高音频质量 audio sample rate: 44MHz(默认44.1Hz iphoneg6以上48Hz), audio bitrate: 64Kbps
    PPYAudioQuality_Medium = 1,
    /// 高音频质量 audio sample rate: 44MHz(默认44.1Hz iphoneg6以上48Hz), audio bitrate: 96Kbps
    PPYAudioQuality_High = 2,
    /// 高音频质量 audio sample rate: 44MHz(默认44.1Hz iphoneg6以上48Hz), audio bitrate: 128Kbps
    PPYAudioQuality_VeryHigh = 3,
    /// 默认音频质量 audio sample rate: 44MHz(默认44.1Hz iphoneg6以上48Hz), audio bitrate: 64Kbps
    PPYAudioQuality_Default = PPYAudioQuality_Medium
};


@interface PPYAudioConfiguration : NSObject

/**
 默认音频配置（采样率44MHz，码率64Kbps）
 */
+ (instancetype)defalutAudioConfiguration;

/**
 根据音频质量初始化配置
 @param audioQuality 音频质量
 */
+ (instancetype)audioConfigurationWithAudioQuality:(PPYAudioQuality)audioQuality;

/**
 根据详细参数初始化音频配置

 @param samplerate 采样率
 @param channelCount 信道数(默认2个)
 @param bitrate 码率
 */
+ (instancetype)audioConfigurationWithSamplerate:(PPYAudioSampleRate)samplerate
                                 andChannelCount:(int)channelCount
                                       andBirate:(PPYAudioBitRate)bitrate; //kbps


/**
 采样率
 */
@property (assign, nonatomic, readonly) PPYAudioSampleRate samplerate;

/**
 信道数
 */
@property (assign, nonatomic, readonly) int channelCount; //default is 2

/**
 码率
 */
@property (assign, nonatomic, readonly) PPYAudioBitRate bitrate;

@end
