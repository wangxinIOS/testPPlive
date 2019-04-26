//
//  SLKMediaMergeAlgorithm.h
//  MediaStreamer
//
//  Created by Think on 2016/11/22.
//  Copyright © 2016年 Cell. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum SLK_MEDIA_MERGE_ALGORITHM{
    SLK_MEDIA_MERGE_ALGORITHM_TIMELINE = 0,
    SLK_MEDIA_MERGE_ALGORITHM_REMUX = 1,
    SLK_MEDIA_MERGE_ALGORITHM_DEEP_REMUX = 2,
}SLK_MEDIA_MERGE_ALGORITHM;
