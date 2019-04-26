//
//  SLKMediaEffectGroup.h
//  MediaStreamer
//
//  Created by PPTV on 2017/3/14.
//  Copyright © 2017年 bolome. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SLKMediaEffect.h"

@interface SLKMediaEffectGroup : NSObject

- (instancetype) init;

- (void)addMediaEffect:(SLKMediaEffect*)mediaEffect;

- (void)insertMediaEffect:(SLKMediaEffect*)mediaEffect atIndex:(NSUInteger)index;

- (void)removeMediaEffect:(SLKMediaEffect*)mediaEffect;

- (void)removeMediaEffectAtIndex:(NSUInteger)index;

- (void)removeAllMediaEffects;

- (NSUInteger)count;

- (SLKMediaEffect*)getMediaEffectAtIndex:(NSUInteger)index;

@end
