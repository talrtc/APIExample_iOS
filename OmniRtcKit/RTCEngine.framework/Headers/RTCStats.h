//
//  RTCStats.h
//  RTCEngine
//
//  Created by xiang on 2019/11/4.
//  Copyright © 2019 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCStats : NSObject


/** Total number of audio bytes sent (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger txAudioBytes;
/** Total number of video bytes sent (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger txVideoBytes;
/** Total number of audio bytes received (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger rxAudioBytes;
/** Total number of video bytes received (bytes), represented by an aggregate value.
 */
@property (assign, nonatomic) NSInteger rxVideoBytes;


/** Audio packet transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger txAudioKBitrate;
/** Audio receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger rxAudioKBitrate;
/** Video transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger txVideoKBitrate;
/** Video receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (assign, nonatomic) NSInteger rxVideoKBitrate;

/** Application CPU usage (%).
 */
@property (assign, nonatomic) double cpuAppUsage;
/** System CPU usage (%).
 */
@property (assign, nonatomic) double cpuTotalUsage;

/** The packet loss rate (%) from the local client to Agora's edge server, before network countermeasures.
 */
@property (assign, nonatomic) NSInteger txPacketLossRate;
/** The packet loss rate (%) from Agora's edge server to the local client, before network countermeasures.
 */
@property (assign, nonatomic) NSInteger rxPacketLossRate;

@property (assign, nonatomic) NSInteger lastMileDelay;

@property (assign, nonatomic) NSInteger gatewayRtt;

@end

NS_ASSUME_NONNULL_END
