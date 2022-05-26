//
//  RTCChannel.h
//  RTCStream-ios
//
//  Created by 王文超 on 2020/6/2.
//  Copyright © 2020 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCEngine.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCChannel : NSObject

/**
 * @apidoc
 * @name initWithEngine:token:delegate:
 * @fname - (instancetype)initWithEngine:(RTCEngine*)engine token:(NSString *)token delegate:(id<RTCEngineChannelDelegate>)delegate
 * @desc 初始化Channel
 * @param engine RTCEngine* RTCEngine对象
 * @param token NSString* 令牌
 * @param delegate id<RTCEngineChannelDelegate 代理对象
 * @return 当前对象
 */
- (instancetype)initWithEngine:(RTCEngine*)engine token:(NSString *)token delegate:(id<RTCEngineChannelDelegate>)delegate;

/**
 * @apidoc
 * @name initWithEngine:AppID:engineType:roomID:uid:delegate:
 * @fname - (instancetype)initWithEngine:(RTCEngine*)engine AppID:(NSString*)appID engineType:(RTCEngineType)engineType roomID:(NSString*)roomID uid:(NSString*)userID delegate:(id<RTCEngineChannelDelegate>)delegate
 * @desc 初始化Channel，不使用token初始化（培优项目使用该初始化方式）
 * @param engine RTCEngine* RTCEngine对象
 * @param AppID NSString* 令牌
 * @param engineType RTCEngineType 引擎类型
 * @param roomID NSString* 房间号
 * @param userID NSString* 用户ID
 * @param delegate id<RTCEngineChannelDelegate 代理对象
 * @return 当前对象
 */
- (instancetype)initWithEngine:(RTCEngine*)engine AppID:(NSString*)appID engineType:(RTCEngineType)engineType roomID:(NSString*)roomID uid:(NSString*)userID delegate:(id<RTCEngineChannelDelegate>)delegate;

/**
 * @apidoc
 * @name joinChannel
 * @fname - (int)joinChannel
 * @desc 加入频道
 * @return 0表示成功
 */
- (int)joinChannel;

/**
 * @apidoc
 * @name leaveChannel
 * @fname - (int)leaveChannel
 * @desc 离开频道
 * @return 0表示成功
 */
- (int)leaveChannel;

/**
 * @apidoc
 * @name destroy
 * @fname - (int)destroy
 * @desc 销毁频道
 * @return 0表示成功
 */
- (int)destroy;

/**
 * @apidoc
 * @name setRole:
 * @fname - (int)setRole:(RTCChannelClientRole)role
 * @desc 设置用户角色
 * @param role RTCChannelClientRole 用户角色
 * @return 0表示成功
 */
- (int)setRole:(RTCChannelClientRole)role;

/**
 * @apidoc
 * @name muteLocalAudio:
 * @fname - (int)muteLocalAudio:(BOOL)isMute
 * @desc 本地音频切换
 * @param isMute BOOL 是否静音
 * @return 0表示成功
 */
- (int)muteLocalAudio:(BOOL)isMute;

/**
 * @apidoc
 * @name muteLocalVideo:
 * @fname - (int)muteLocalVideo:(BOOL)isMute
 * @desc 本地视频切换
 * @param isMute BOOL 开启或停止发送视频流
 * @return 0表示成功
 */
- (int)muteLocalVideo:(BOOL)isMute;

/**
 * @apidoc
 * @name obtainChannelID:
 * @fname - (NSString*)obtainChannelID
 * @desc 获取频道号
 * @return 频道名称
 */
- (NSString*)obtainChannelID;

/**
 * @apidoc
 * @name obtainUserID:
 * @fname - (NSUInteger)obtainUserID
 * @desc 获取用户的ID
 * @return 当前用户ID
 */
- (NSUInteger)obtainUserID;

/**
 * @apidoc
 * @name getTimeStampWithUid:
 * @fname - (long long)getTimeStampWithUid:(NSInteger)uid
 * @desc 获取时间戳
 * @param uid NSInteger 用户ID
 * @return 时间戳
 */
- (long long)getTimeStampWithUid:(NSInteger)uid;

/**
 * @apidoc
 * @name setRemoteRenderMode:mode:
 * @fname - (int)setRemoteRenderMode:(NSUInteger)uid mode:(RTCVideoRenderMode)mode
 * @desc 设置远端视图显示模式
 * @param uid NSUInteger 用户ID
 * @param mode RTCVideoRenderMode 渲染模式
 * @return 0表示成功
 */
- (int)setRemoteRenderMode:(NSUInteger)uid mode:(RTCVideoRenderMode)mode;

/**
 * @apidoc
 * @name setDefaultMuteAllRemoteAudioStreams:
 * @fname - (int)setDefaultMuteAllRemoteAudioStreams:(BOOL)isMute
 * @desc 默认取消或恢复订阅远端用户的音频流
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return 0表示成功
 */
- (int)setDefaultMuteAllRemoteAudioStreams:(BOOL)isMute;

/**
 * @apidoc
 * @name setDefaultMuteAllRemoteVideoStreams:
 * @fname - (int)setDefaultMuteAllRemoteVideoStreams:(BOOL)isMute
 * @desc 默认取消或恢复订阅远端用户的视频流
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return 0表示成功
 */
- (int)setDefaultMuteAllRemoteVideoStreams:(BOOL)isMute;

/**
 * @apidoc
 * @name muteRemoteAudio:isMute:
 * @fname - (int)muteRemoteAudio:(NSUInteger)uid isMute:(BOOL)isMute
 * @desc 取消或恢复订阅指定远端用户的音频流
 * @param uid NSUInteger 用户ID
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return 0表示成功
 */
- (int)muteRemoteAudio:(NSUInteger)uid isMute:(BOOL)isMute;

/**
 * @apidoc
 * @name muteAllRemoteAudio:
 * @fname - (int)muteAllRemoteAudio:(BOOL)isMute
 * @desc 取消或恢复订阅所有远端用户的音频流
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return 0表示成功
 */
- (int)muteAllRemoteAudio:(BOOL)isMute;

/**
 * @apidoc
 * @name muteRemoteVideo:isMute:
 * @fname - (int)muteRemoteVideo:(NSUInteger)uid isMute:(BOOL)isMute
 * @desc 取消或恢复订阅指定远端用户的视频流
 * @param uid NSUInteger 用户ID
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return 0表示成功
 */
- (int)muteRemoteVideo:(NSUInteger)uid isMute:(BOOL)isMute;

/**
 * @apidoc
 * @name muteAllRemoteVideo:
 * @fname - (int)muteAllRemoteVideo:(BOOL)isMute
 * @desc 取消或恢复订阅所有远端用户的视频流
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return 0表示成功
 */
- (int)muteAllRemoteVideo:(BOOL)isMute;

/**
 * @apidoc
 * @name setupRemoteVideo:channelID:view:
 * @fname - (void)setupRemoteVideo:(NSUInteger)uid channelID:(NSString*)channelID view:(OmniRtcLiveView*)view
 * @desc 初始化远端用户视图
 * @param uid NSUInteger 用户ID
 * @param channelID NSString* 频道名称
 * @param view OmniRtcLiveView* 渲染视图
 * @return 空
 */
- (void)setupRemoteVideo:(NSUInteger)uid channelID:(NSString*)channelID view:(OmniRtcLiveView*)view;

/**
 * @apidoc
 * @name setVolume:volume:channelID:
 * @fname - (int)setVolume:(NSString* _Nonnull)userId volume:(NSUInteger)volume channelID:(NSString* _Nonnull)channelID
 * @desc 设置远端音量
 * @param userId NSString* 用户ID
 * @param volume NSUInteger 音量值
 * @param channelID NSString* 频道名称
 * @return 0表示成功
 */
- (int)setVolume:(NSString* _Nonnull)userId volume:(NSUInteger)volume channelID:(NSString* _Nonnull)channelID;

/**
 * @apidoc
 * @name setRemoteVideoStream:type:
 * @fname - (int)setRemoteVideoStream:(NSUInteger)uid type:(RTCVideoStreamType)streamType
 * @desc 切换大小流，设置大小流可能会导致接收到的码率、帧率、分辨率都会变化
 * @param uid NSUInteger 用户ID
 * @param streamType RTCVideoStreamType 流类型
 * @return 0表示成功
 */
- (int)setRemoteVideoStream:(NSUInteger)uid type:(RTCVideoStreamType)streamType;

/**
 * @apidoc
 * @name startChannelMediaRelay:
 * @fname - (int)startChannelMediaRelay:(RTCChannelMediaRelayConfiguration *_Nonnull)config
 * @desc 跨频道转发
 * @param config RTCChannelMediaRelayConfiguration* 转发配置
 * @return 0表示成功
 */
- (int)startChannelMediaRelay:(RTCChannelMediaRelayConfiguration *_Nonnull)config;

/**
 * @apidoc
 * @name updateChannelMediaRelay:
 * @fname - (int)updateChannelMediaRelay:(RTCChannelMediaRelayConfiguration * _Nonnull)config
 * @desc 更新媒体流转发的频道
 * @param config RTCChannelMediaRelayConfiguration* 转发配置
 * @return 0表示成功
 */
- (int)updateChannelMediaRelay:(RTCChannelMediaRelayConfiguration * _Nonnull)config;

/**
 * @apidoc
 * @name stopChannelMediaRelay
 * @fname - (int)stopChannelMediaRelay
 * @desc 停止跨频道媒体流转发
 * @return 0表示成功
 */
- (int)stopChannelMediaRelay;

/**
 * @apidoc
 * @name applyRemoteStreamSubscribeAdvice:type:
 * @fname - (int)applyRemoteStreamSubscribeAdvice:(NSUInteger)userID type:(OmniRtcLiveSubscriptionStreamType)type
 * @desc 手动切换大小流
 * @param userID NSUInteger 转发配置
 * @param type OmniRtcLiveSubscriptionStreamType 流类型
 * @return 0表示成功
 */
- (int)applyRemoteStreamSubscribeAdvice:(NSUInteger)userID type:(OmniRtcLiveSubscriptionStreamType)type;

/**
 * @apidoc
 * @name sendStreamMessage:timeStamp:
 * @fname - (int)sendStreamMessage:(NSData*)data timeStamp:(long long)timeStamp;
 * @desc 发送消息
 * @param data NSData* 消息数据
 * @param timeStamp long 时间戳
 * @return 0表示成功
 */
- (int)sendStreamMessage:(NSData*)data timeStamp:(long long)timeStamp;

/**
 * @apidoc
 * @name addPublishStreamUrl:transcodingEnabled:
 * @fname - (int)addPublishStreamUrl:(NSString *)streamUrl transcodingEnabled:(BOOL)transcodingEnabled;
 * @desc 添加 rtmp 推流地址
 * @param streamUrl NSString* 推流地址
 * @param transcodingEnabled BOOL 是否开启转码
 * @return 0表示成功
 */
- (int)addPublishStreamUrl:(NSString *)streamUrl transcodingEnabled:(BOOL)transcodingEnabled;

/**
 * @apidoc
 * @name removePublishStreamUrl:
 * @fname - (int)removePublishStreamUrl:(NSString *)streamUrl;
 * @desc  删除 rtmp 推流地址，不要 removePublishStreamUrl 以后马上调用 addPublishStreamUrl，一定要等停止推流成功后再重新推流
 * @param streamUrl NSString* 推流地址
 * @return 0表示成功
 */
- (int)removePublishStreamUrl:(NSString *)streamUrl;

/**
 * @apidoc
 * @name removePublishStreamUrl:
 * @fname - (int)setRtmpConfig:(RTCRtmpConfig *)rtmpConfig;
 * @desc 设置rtmp流的配置信息
 * @param rtmpConfig RTCRtmpConfig* 推流配置
 * @return 0表示成功
 */
- (int)setRtmpConfig:(RTCRtmpConfig *)rtmpConfig;

@end

NS_ASSUME_NONNULL_END
