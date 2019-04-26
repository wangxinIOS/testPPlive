//
//  SLKMediaEffect.h
//  MediaStreamer
//
//  Created by Think on 2017/3/14.
//  Copyright © 2017年 Cell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum SLK_MEDIA_EFFECT_TYPE{
    SLK_MEDIA_EFFECT_TYPE_UNKNOWN     = -1,
    SLK_MEDIA_EFFECT_TYPE_VIDEO_AUDIO = 0,
    SLK_MEDIA_EFFECT_TYPE_VIDEO       = 1,
    SLK_MEDIA_EFFECT_TYPE_AUDIO       = 2,
    SLK_MEDIA_EFFECT_TYPE_TEXT        = 3,
    SLK_MEDIA_EFFECT_TYPE_PNG         = 4,
    SLK_MEDIA_EFFECT_TYPE_JPEG        = 5,
    SLK_MEDIA_EFFECT_TYPE_FILTER      = 6,
    SLK_MEDIA_EFFECT_TYPE_TRANSITION  = 7,
    SLK_MEDIA_EFFECT_TYPE_WEBP        = 8,
    SLK_MEDIA_EFFECT_TYPE_GIF         = 9,
}SLK_MEDIA_EFFECT_TYPE;

typedef enum SLK_GPU_IMAGE_FILTER_TYPE{
    SLK_GPU_IMAGE_FILTER_RGB = 0,
    SLK_GPU_IMAGE_FILTER_SKETCH = 1,
    SLK_GPU_IMAGE_FILTER_AMARO = 2,
    SLK_GPU_IMAGE_FILTER_ANTIQUE = 3,
    SLK_GPU_IMAGE_FILTER_BLACKCAT = 4,
    SLK_GPU_IMAGE_FILTER_BEAUTY = 5,
    SLK_GPU_IMAGE_FILTER_BRANNAN = 6,
    SLK_GPU_IMAGE_FILTER_N1977 = 7,
    SLK_GPU_IMAGE_FILTER_BROOKLYN = 8,
    SLK_GPU_IMAGE_FILTER_COOL = 9,
    SLK_GPU_IMAGE_FILTER_CRAYON = 10,
}SLK_GPU_IMAGE_FILTER_TYPE;

typedef enum SLK_GPU_IMAGE_TRANSITION_TYPE{
    SLK_GPU_IMAGE_TRANSITION_NONE = -1,
    SLK_GPU_IMAGE_TRANSITION_SLIDE = 0,
}SLK_GPU_IMAGE_TRANSITION_TYPE;

typedef enum SLK_TEXT_ANIMATION_TYPE{
    SLK_TEXT_ANIMATION_NONE = 0,
}SLK_TEXT_ANIMATION_TYPE;

@interface SLKMediaEffect : NSObject

- (instancetype) init;

@property (nonatomic) NSInteger iD;
@property (nonatomic, strong) NSString *url;
@property (nonatomic) SLK_MEDIA_EFFECT_TYPE slk_media_effect_type;
@property (nonatomic) NSTimeInterval effect_in_pos;
@property (nonatomic) NSTimeInterval effect_out_pos;
@property (nonatomic) NSTimeInterval startPos;
@property (nonatomic) NSTimeInterval endPos;
@property (nonatomic) NSTimeInterval volume; //for audio mix
@property (nonatomic) NSTimeInterval speed;

//for overlay
@property (nonatomic) NSInteger x;
@property (nonatomic) NSInteger y;
@property (nonatomic) NSInteger rotation;
@property (nonatomic) NSTimeInterval scale;
@property (nonatomic) BOOL flipHorizontal;
@property (nonatomic) BOOL flipVertical;

//for text
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *fontLibPath;
@property (nonatomic) NSInteger fontSize;
@property (nonatomic, strong) UIColor *fontColor;
@property (nonatomic) NSInteger leftMargin;
@property (nonatomic) NSInteger rightMargin;
@property (nonatomic) NSInteger topMargin;
@property (nonatomic) NSInteger bottomMargin;
@property (nonatomic) NSInteger lineSpace;
@property (nonatomic) NSInteger wordSpace;
@property (nonatomic) SLK_TEXT_ANIMATION_TYPE slk_text_animation_type;

@property (nonatomic) SLK_GPU_IMAGE_FILTER_TYPE slk_gpu_image_filter_type; //for filter
@property (nonatomic) SLK_GPU_IMAGE_TRANSITION_TYPE slk_gpu_image_transition_type; //for transition
@property (nonatomic) NSInteger transition_source_id; //for transition

@end
