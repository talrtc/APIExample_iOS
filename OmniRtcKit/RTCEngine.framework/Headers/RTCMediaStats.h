//
//  RTCMediaStats.h
//  RTCStream-ios
//
//  Created by 王文超 on 2019/12/26.
//  Copyright © 2019 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - RTCLocalAudioStats

@interface RTCLocalAudioStats : NSObject

@property (nonatomic, assign) double audioLevel;
@property (nonatomic, assign) NSUInteger numChannels;
@property (nonatomic, assign) NSUInteger sentSampleRate;
@property (nonatomic, assign) NSUInteger packetsSent;
@property (nonatomic, assign) NSInteger  packetsLost;
@property (nonatomic, assign) NSUInteger sentBitrate;
@property (nonatomic, assign) NSInteger aRtt;

@end

#pragma mark - RTCLocalVideoStats

@interface RTCLocalVideoStats : NSObject

@property (nonatomic, assign) NSUInteger frameWidth;
@property (nonatomic, assign) NSUInteger frameHeight;
@property (nonatomic, assign) NSUInteger packetsSent;
@property (nonatomic, assign) NSInteger  packetsLost;
@property (nonatomic, assign) NSUInteger sentFrameRate;
@property (nonatomic, assign) NSUInteger sentBitrate;
@property (nonatomic, assign) NSUInteger videoTargetBps;
@property (nonatomic, assign) NSUInteger videoTargetFps;
@property (nonatomic, assign) NSUInteger delay;
@property (nonatomic, assign) NSUInteger encodedFrameRate;
@property (nonatomic, assign) NSInteger vRtt;

@end

#pragma mark - RTCRemoteAudioStats

@interface RTCRemoteAudioStats : NSObject

@property (assign, nonatomic) NSUInteger uid;
@property (nonatomic, assign) double audioLevel;
@property (nonatomic, assign) NSUInteger numChannels;
@property (nonatomic, assign) NSUInteger sampleRate;
@property (nonatomic, assign) NSInteger  packetsLost;
@property (nonatomic, assign) NSUInteger packetsReceived;
@property (nonatomic, assign) NSUInteger receivedBitrate;
@property (nonatomic, assign) NSUInteger audioDelay;
@property (nonatomic, assign) NSUInteger networkTransportDelay;
@property (nonatomic, assign) NSUInteger endToEndDelay;
@property (nonatomic, assign) NSInteger aJitter;
@property (nonatomic, assign) NSInteger aRtt;
@property (nonatomic, assign) NSInteger aDecodeDur;

@end

#pragma mark - RTCRemoteVideoStats

@interface RTCRemoteVideoStats : NSObject

@property (assign, nonatomic) NSUInteger uid;
@property (nonatomic, assign) NSUInteger frameWidth;
@property (nonatomic, assign) NSUInteger frameHeight;
@property (nonatomic, assign) NSInteger  packetsLost;
@property (nonatomic, assign) NSUInteger packetsReceived;
@property (nonatomic, assign) NSUInteger receivedBitrate;
@property (nonatomic, assign) NSUInteger receivedFrameRate;
@property (nonatomic, assign) NSUInteger decodedFrameRate;
@property (nonatomic, assign) NSUInteger videoDelay;
@property (nonatomic, assign) NSUInteger endToEndDelay;
@property (nonatomic, assign) NSInteger avSyncDeltaInMS;
@property (nonatomic, assign) NSInteger vJitter;
@property (nonatomic, assign) NSInteger vRtt;
@property (nonatomic, assign) NSInteger vDecodeDur;

@end

NS_ASSUME_NONNULL_END
