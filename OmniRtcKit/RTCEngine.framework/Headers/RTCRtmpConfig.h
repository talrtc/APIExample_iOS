//
//  RTCRtmpConfig.h
//  RTCStream-ios
//
//  Created by 王文超 on 2020/7/8.
//  Copyright © 2020 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class RTCRtmpUser, RTCRtmpBackgroundImage;

@interface RTCRtmpConfig : NSObject

@property (nonatomic, assign) NSInteger audioChannel;       // 1,2
@property (nonatomic, assign) NSInteger audioSampleRate;    // 32000,44100,48000
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger fps;
@property (nonatomic, assign) NSInteger gop;
@property (nonatomic, assign) NSInteger videoBitrate;       // kbps
@property (nonatomic, strong) NSString *backgroundImageId;
@property (nonatomic, strong) RTCRtmpBackgroundImage* backgroundImage;
@property (nonatomic, strong) UIColor* backgroundColor;
@property (nonatomic, strong) NSArray<RTCRtmpUser*>* users;

@end


@interface RTCRtmpUser : NSObject

@property (nonatomic, assign) NSInteger uid;
@property (nonatomic, assign) NSInteger x;
@property (nonatomic, assign) NSInteger y;
@property (nonatomic, assign) NSInteger zorder;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

@end


@interface RTCRtmpBackgroundImage : NSObject

@property (nonatomic, strong) NSURL* url;
@property (nonatomic, assign) NSInteger x;
@property (nonatomic, assign) NSInteger y;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

@end

NS_ASSUME_NONNULL_END
