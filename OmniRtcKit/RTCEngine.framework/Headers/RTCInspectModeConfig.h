//
//  RTCInspectModeConfig.h
//  RTCStream-ios
//
//  Created by 王文超 on 2021/3/10.
//  Copyright © 2021 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RTCContentInspectMode) {
    RTCContentInspectModePornCheck = 1 << 0,
    RTCContentInspectModeAICheck = 1 << 1,
};

@interface RTCInspectModeConfig : NSObject

@property (nonatomic, assign) NSInteger rate;
@property (nonatomic, assign) RTCContentInspectMode mode;

@end

NS_ASSUME_NONNULL_END
