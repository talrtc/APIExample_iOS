//
//  RTCEngineChannel.h
//  RTCStream-ios
//
//  Created by 王文超 on 2020/5/26.
//  Copyright © 2020 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RTCRtmpConfig.h"
#import "RTCMediaStats.h"

NS_ASSUME_NONNULL_BEGIN

typedef UIView OmniRtcLiveView;

@protocol RTCEngineChannel;
@protocol RTCThirdPartEngineProtocol;
@class RTCStats;

/**
 * @apidoc
 * @name RTCEngineErrorCode
 * @fname RTCEngineErrorCode
 * @desc 引擎错误类型
 * @param RTCEngineErrorCodeUnkonwn NSInteger 未知
 * @param RTCEngineErrorCodeInvalidToken NSInteger 非法token
 * @param RTCEngineErrorCodeTokenExpired NSInteger token过期
 * @param RTCEngineErrorCodesAudioError NSInteger 音频错误
 * @param RTCEngineErrorCodePublishFailed NSInteger 发布失败
 * @param RTCEngineErrorCodeStartCamera NSInteger 启动摄像头错误
 * @param RTCEngineErrorCodeStartVideoRender NSInteger 启动渲染失败
 * @param RTCEngineErrorCodeParseTokenError NSInteger 解析token错误
 * @param RTCEngineErrorCodeSetRoleError NSInteger 设置角色错误
 * @param RTCEngineErrorCodeNoServerTime NSInteger 未获取到服务器时间
 * @param RTCEngineErrorCodeSEIFail NSInteger SEI错误
 * @param RTCEngineErrorCodeAdmInterruption NSInteger 音频模块打断
 * @param RTCEngineErrorCodeAdmExceptionInterruption NSInteger 音频模块异常
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineErrorCode) {
    RTCEngineErrorCodeUnkonwn = 0,
    RTCEngineErrorCodeInvalidToken = 1,
    RTCEngineErrorCodeTokenExpired = 2,
    RTCEngineErrorCodesAudioError = 4,
    RTCEngineErrorCodePublishFailed = 5,
    RTCEngineErrorCodeStartCamera = 6,
    RTCEngineErrorCodeStartVideoRender = 7,
    RTCEngineErrorCodeParseTokenError = 8,
    RTCEngineErrorCodeSetRoleError = 9,
    RTCEngineErrorCodeNoServerTime = 10,
    RTCEngineErrorCodeSEIFail = 11,
    RTCEngineErrorCodeAdmInterruption = 12,
    RTCEngineErrorCodeAdmExceptionInterruption = 13,
};

/**
 * @apidoc
 * @name RTCVideoRenderMode
 * @fname RTCVideoRenderMode
 * @desc 渲染模式
 * @param RTCVideoRenderModeFill NSInteger 拉伸填充模式
 * @param RTCVideoRenderModeHidden NSInteger 剪裁填充模式
 * @param RTCVideoRenderModeFit NSInteger 自适应模式，会保留黑边
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCVideoRenderMode) {
    RTCVideoRenderModeFill   = 0,
    RTCVideoRenderModeHidden = 1,
    RTCVideoRenderModeFit    = 2,
};

/**
 * @apidoc
 * @name RTCChannelClientRole
 * @fname RTCChannelClientRole
 * @desc 用户角色
 * @param RTCChannelClientRoleBroadcaster NSInteger 主播
 * @param RTCChannelClientRoleAudience NSInteger 关注
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCChannelClientRole)
{
    RTCChannelClientRoleBroadcaster = 1,                  // 主播
    RTCChannelClientRoleAudience = 2,                     // 观众
};

/**
 * @apidoc
 * @name RTCChannelVideoRemoteState
 * @fname RTCChannelVideoRemoteState
 * @desc 远端视频状态
 * @param RTCChannelVideoRemoteStateStopped NSInteger 远端视频默认初始状态
 * @param RTCChannelVideoRemoteStateStarting NSInteger 本地用户已接收远端视频首包
 * @param RTCChannelVideoRemoteStateDecoding NSInteger 远端视频流正在解码，正常播放
 * @param RTCChannelVideoRemoteStateFrozen NSInteger 远端视频流卡顿
 * @param RTCChannelVideoRemoteStateFailed NSInteger 远端视频流播放失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCChannelVideoRemoteState)
{
    RTCChannelVideoRemoteStateStopped = 0,              // 远端视频默认初始状态
    RTCChannelVideoRemoteStateStarting = 1,             // 本地用户已接收远端视频首包
    RTCChannelVideoRemoteStateDecoding = 2,             // 远端视频流正在解码，正常播放
    RTCChannelVideoRemoteStateFrozen = 3,               // 远端视频流卡顿
    RTCChannelVideoRemoteStateFailed = 4,               // 远端视频流播放失败
};

/**
 * @apidoc
 * @name RTCChannelVideoRemoteStateReason
 * @fname RTCChannelVideoRemoteStateReason
 * @desc 远端视频状态切换原因
 * @param RTCChannelVideoRemoteStateReasonInternal NSInteger 内部原因
 * @param RTCChannelVideoRemoteStateReasonNetworkCongestion NSInteger 网络拥塞
 * @param RTCChannelVideoRemoteStateReasonNetworkRecovery NSInteger 网络恢复
 * @param RTCChannelVideoRemoteStateReasonLocalMuted NSInteger 本地mute
 * @param RTCChannelVideoRemoteStateReasonLocalUnmuted NSInteger 本地unmute
 * @param RTCChannelVideoRemoteStateReasonRemoteOffline NSInteger 远端用户离线
 * @param RTCChannelVideoRemoteStateReasonRemoteMuted NSInteger 远端用户mute
 * @param RTCChannelVideoRemoteStateReasonRemoteUnmuted NSInteger 远端用户unmute
 * @param RTCChannelVideoRemoteStateReasonAudioFallback NSInteger 音频回退
 * @param RTCChannelVideoRemoteStateReasonAudioFallbackRecovery NSInteger 音频回退恢复
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCChannelVideoRemoteStateReason) {
    RTCChannelVideoRemoteStateReasonInternal = 0,
    RTCChannelVideoRemoteStateReasonNetworkCongestion = 1,
    RTCChannelVideoRemoteStateReasonNetworkRecovery = 2,
    RTCChannelVideoRemoteStateReasonLocalMuted = 3,
    RTCChannelVideoRemoteStateReasonLocalUnmuted = 4,
    RTCChannelVideoRemoteStateReasonRemoteMuted = 5,
    RTCChannelVideoRemoteStateReasonRemoteUnmuted = 6,
    RTCChannelVideoRemoteStateReasonRemoteOffline = 7,
    RTCChannelVideoRemoteStateReasonAudioFallback = 8,
    RTCChannelVideoRemoteStateReasonAudioFallbackRecovery = 9,
};

/**
 * @apidoc
 * @name RTCChannelUserOfflineReason
 * @fname RTCChannelUserOfflineReason
 * @desc 用户离线原因
 * @param RTCChannelUserOfflineReasonQuit NSInteger 用户主动离开
 * @param RTCChannelUserOfflineReasonDropped NSInteger 超时掉线
 * @param RTCChannelUserOfflineReasonBecomeAudience NSInteger 主播切换为观众时触发
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCChannelUserOfflineReason) {
    RTCChannelUserOfflineReasonQuit = 0,
    RTCChannelUserOfflineReasonDropped = 1,
    RTCChannelUserOfflineReasonBecomeAudience = 2,
};

/**
 * @apidoc
 * @name RTCChannelConnectionStateType
 * @fname RTCChannelConnectionStateType
 * @desc 网络连接状态
 * @param RTCChannelConnectionStateDisconnected NSInteger 网络连接断开
 * @param RTCChannelConnectionStateConnecting NSInteger 建立网络连接中
 * @param RTCChannelConnectionStateConnected NSInteger 网络已连接
 * @param RTCChannelConnectionStateReconnecting NSInteger 重新建立网络连接中，重试20分钟
 * @param RTCChannelConnectionStateFailed NSInteger 网络连接失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCChannelConnectionStateType) {
    RTCChannelConnectionStateDisconnected = 1,              // 网络连接断开
    RTCChannelConnectionStateConnecting = 2,                // 建立网络连接中
    RTCChannelConnectionStateConnected = 3,                 // 网络已连接
    RTCChannelConnectionStateReconnecting = 4,              // 重新建立网络连接中，重试20分钟
    RTCChannelConnectionStateFailed = 5,                    // 网络连接失败
};

/**
 * @apidoc
 * @name RTCChannelConnectionChangedReason
 * @fname RTCChannelConnectionChangedReason
 * @desc 网络状态变化原因
 * @param RTCChannelConnectionChangedConnecting NSInteger 建立网络连接中
 * @param RTCChannelConnectionChangedJoinSuccess NSInteger 成功加入频道
 * @param RTCChannelConnectionChangedInterrupted NSInteger 网络连接中断
 * @param RTCChannelConnectionChangedBannedByServer NSInteger 网络连接被服务器禁止
 * @param RTCChannelConnectionChangedJoinFailed NSInteger 加入频道失败，20分钟后还是没能加入频道，会返回该状态，并停止尝试重连
 * @param RTCChannelConnectionChangedLeaveChannel NSInteger 离开频道
 * @param RTCChannelConnectionChangedInvalidAppId NSInteger 不是有效的APPID
 * @param RTCChannelConnectionChangedInvalidChannelName NSInteger 不是有效的频道名
 * @param RTCChannelConnectionChangedInvalidToken NSInteger 生成的Token无效
 * @param RTCChannelConnectionChangedTokenExpired NSInteger 当前使用的Token过期
 * @param RTCChannelConnectionChangedSettingProxyServer NSInteger 由于设置了代理服务器，SDK尝试重连
 * @param RTCChannelConnectionChangedRenewToken NSInteger 更新Token引起网络连接状态改变
 * @param RTCChannelConnectionChangedClientIpAddressChanged NSInteger 客户端IP地址变更
 * @param RTCChannelConnectionChangedKeepAliveTimeout NSInteger SDK和服务器连接保活超时
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCChannelConnectionChangedReason) {
    RTCChannelConnectionChangedConnecting = 0,
    RTCChannelConnectionChangedJoinSuccess = 1,
    RTCChannelConnectionChangedInterrupted = 2,
    RTCChannelConnectionChangedBannedByServer = 3,
    RTCChannelConnectionChangedJoinFailed = 4,
    RTCChannelConnectionChangedLeaveChannel = 5,
    RTCChannelConnectionChangedInvalidAppId = 6,
    RTCChannelConnectionChangedInvalidChannelName = 7,
    RTCChannelConnectionChangedInvalidToken = 8,
    RTCChannelConnectionChangedTokenExpired = 9,
    RTCChannelConnectionChangedRejectedByServer = 10,
    RTCChannelConnectionChangedSettingProxyServer = 11,
    RTCChannelConnectionChangedRenewToken = 12,
    RTCChannelConnectionChangedClientIpAddressChanged = 13,
    RTCChannelConnectionChangedKeepAliveTimeout = 14,
};

/**
 * @apidoc
 * @name RTCLastMileQuality
 * @fname RTCLastMileQuality
 * @desc 最后一公里质量
 * @param RTC_QUALITY_UNKNOWN NSInteger 质量极好
 * @param RTC_QUALITY_EXCELLENT NSInteger 质量极好
 * @param RTC_QUALITY_GOOD NSInteger 用户主观感觉和极好差不多
 * @param RTC_QUALITY_POOR NSInteger 用户主观感受有瑕疵但不影响沟通
 * @param RTC_QUALITY_BAD NSInteger 勉强能沟通但不顺畅
 * @param RTC_QUALITY_VBAD NSInteger 网络质量非常差，基本不能沟通
 * @param RTC_QUALITY_DOWN NSInteger 完全无法沟
 * @param RTC_QUALITY_DETECTING NSInteger SDK正在探测网络质量
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCLastMileQuality)
{
    RTC_QUALITY_UNKNOWN = 0,    //have no idea of Quality of The network
    RTC_QUALITY_EXCELLENT =1,   //质量极好
    RTC_QUALITY_GOOD =2,        //用户主观感觉和极好差不多，但码率可能略低于极好
    RTC_QUALITY_POOR=3,        //用户主观感受有瑕疵但不影响沟通
    RTC_QUALITY_BAD=4,         //勉强能沟通但不顺畅
    RTC_QUALITY_VBAD=5,        //网络质量非常差，基本不能沟通
    RTC_QUALITY_DOWN=6,        //完全无法沟
    RTC_QUALITY_DETECTING=8   //SDK 正在探测网络质量
};

/**
 * @apidoc
 * @name RTCVideoStreamType
 * @fname RTCVideoStreamType
 * @desc 视频流类型
 * @param RTCVideoStreamTypeHigh NSInteger 高码率高分辨视频流
 * @param RTCVideoStreamTypeLow NSInteger 低码率低分辨率视频流
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCVideoStreamType) {
    /** High-bitrate, high-resolution video stream. */
    RTCVideoStreamTypeHigh = 0,
    /** Low-bitrate, low-resolution video stream. */
    RTCVideoStreamTypeLow = 1,
};

/**
 * @apidoc
 * @name RTCVideoBufferingState
 * @fname RTCVideoBufferingState
 * @desc 视频卡顿状态
 * @param RTCVideoBufferingStateStart NSInteger 开始卡顿
 * @param RTCVideoBufferingStateEnd NSInteger 结束卡顿
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCVideoBufferingState) {
    RTCVideoBufferingStateStart = 0,            // 开始卡顿
    RTCVideoBufferingStateEnd = 1,              // 结束卡顿
};

/**
 * @apidoc
 * @name RTCAudioBufferingState
 * @fname RTCAudioBufferingState
 * @desc 音频卡顿状态
 * @param RTCAudioBufferingStateStart NSInteger 开始卡顿
 * @param RTCAudioBufferingStateEnd NSInteger 结束卡顿
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCAudioBufferingState) {
    RTCAudioBufferingStateStart = 0,            // 开始卡顿
    RTCAudioBufferingStateEnd = 1,              // 结束卡顿
};

/**
 * @apidoc
 * @name RTCRtmpStreamingState
 * @fname RTCRtmpStreamingState
 * @desc rtmp流状态
 * @param RTCRtmpStreamingStateIdle NSInteger 推流未开始或已结束
 * @param RTCRtmpStreamingStateConnecting NSInteger 正在连接推流服务器和CDN服务器
 * @param RTCRtmpStreamingStateRunning NSInteger 推流正在进行
 * @param RTCRtmpStreamingStateRecovering NSInteger 正在恢复推流
 * @param RTCRtmpStreamingStateFailure NSInteger 推流失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCRtmpStreamingState)
{
    RTCRtmpStreamingStateIdle = 0,
    RTCRtmpStreamingStateConnecting = 1,
    RTCRtmpStreamingStateRunning = 2,
    RTCRtmpStreamingStateRecovering = 3,       // 正在恢复推流，如服务器出错或 60 秒内未成功恢复，则进入状态 RTCRtmpStreamingStateFailure。如果觉得 60 秒太长，也可以主动调用 removePublishStreamUrl 和 addPublishStreamUrl 方法尝试重连
    RTCRtmpStreamingStateFailure = 4,
};

/**
 * @apidoc
 * @name RTCRtmpStreamingErrorCode
 * @fname RTCRtmpStreamingErrorCode
 * @desc rtmp推流错误码
 * @param RTCRtmpStreamingErrorCodeOK NSInteger 推流成功
 * @param RTCRtmpStreamingErrorCodeInvalidParameters NSInteger 参数无效
 * @param RTCRtmpStreamingErrorCodeEncryptedStreamNotAllowed NSInteger 推流已加密，不能推流
 * @param RTCRtmpStreamingErrorCodeConnectionTimeout NSInteger 推流超时未成功
 * @param RTCRtmpStreamingErrorCodeInternalServerError NSInteger 推流服务器出现错误
 * @param RTCRtmpStreamingErrorCodeRtmpServerError NSInteger CDN服务器出现错误
 * @param RTCRtmpStreamingErrorCodeTooOften NSInteger 预留参数
 * @param RTCRtmpStreamingErrorCodeReachLimit NSInteger 单个主播的推流地址数目达到上限10
 * @param RTCRtmpStreamingErrorCodeNotAuthorized NSInteger 主播操作不属于自己的流
 * @param RTCRtmpStreamingErrorCodeStreamNotFound NSInteger 服务器未找到这个流
 * @param RTCRtmpStreamingErrorCodeFormatNotSupported NSInteger 推流地址格式有错误
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCRtmpStreamingErrorCode)
{
    RTCRtmpStreamingErrorCodeOK = 0,
    RTCRtmpStreamingErrorCodeInvalidParameters = 1,
    RTCRtmpStreamingErrorCodeEncryptedStreamNotAllowed = 2,
    RTCRtmpStreamingErrorCodeConnectionTimeout = 3,
    RTCRtmpStreamingErrorCodeInternalServerError = 4,
    RTCRtmpStreamingErrorCodeRtmpServerError = 5,
    RTCRtmpStreamingErrorCodeTooOften = 6,
    RTCRtmpStreamingErrorCodeReachLimit = 7,
    RTCRtmpStreamingErrorCodeNotAuthorized = 8,
    RTCRtmpStreamingErrorCodeStreamNotFound = 9,
    RTCRtmpStreamingErrorCodeFormatNotSupported = 10,
};

/**
 * @apidoc
 * @name RTCRtmpErrorCode
 * @fname RTCRtmpErrorCode
 * @desc rtmp错误码
 * @param RTCRtmpErrorCodeNoError NSInteger 推流成功
 * @param RTCRtmpErrorCodeTimeOut NSInteger 推流超时未成功
 * @param RTCRtmpErrorCodeCDNError NSInteger CDN相关错误
 * @param RTCRtmpErrorCodeNumReachLimit NSInteger 单个主播的推流地址数目达到上限10
 * @param RTCRtmpErrorCodeNotAuthorized NSInteger 操作不属于主播自己的流
 * @param RTCRtmpErrorCodeInternalServerError NSInteger 推流服务器出现错误
 * @param RTCRtmpErrorCodeNotFound NSInteger 服务器未找到这个流
 * @param RTCRtmpErrorCodeFormatNotSuppported NSInteger 推流地址格式有错误
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCRtmpErrorCode) {
    RTCRtmpErrorCodeNoError = 0,                // 推流成功
    RTCRtmpErrorCodeTimeOut = 10,               // 推流超时未成功
    RTCRtmpErrorCodeCDNError = 151,             // CDN 相关错误。请调用 removePublishStreamUrl 方法删除原来的推流地址，然后调用 addPublishStreamUrl 方法重新推流到新地址
    RTCRtmpErrorCodeNumReachLimit = 152,        // 单个主播的推流地址数目达到上限 10
    RTCRtmpErrorCodeNotAuthorized = 153,        // 操作不属于主播自己的流
    RTCRtmpErrorCodeInternalServerError = 154,  // 推流服务器出现错误
    RTCRtmpErrorCodeNotFound = 155,             // 服务器未找到这个流
    RTCRtmpErrorCodeFormatNotSuppported = 156,  // 推流地址格式有错误
};

/**
 * @apidoc
 * @name RTCChannelMediaRelayState
 * @fname RTCChannelMediaRelayState
 * @desc 转推状态码
 * @param RTCChannelMediaRelayStateIdle NSInteger  初始状态
 * @param RTCChannelMediaRelayStateConnecting NSInteger SDK尝试跨频道
 * @param RTCChannelMediaRelayStateRunning NSInteger 源频道主播成功加入目标频道
 * @param RTCChannelMediaRelayStateFailure NSInteger 发生异常
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCChannelMediaRelayState) {
    RTCChannelMediaRelayStateIdle = 0,
    RTCChannelMediaRelayStateConnecting = 1,
    RTCChannelMediaRelayStateRunning = 2,
    RTCChannelMediaRelayStateFailure = 3,
};

/**
 * @apidoc
 * @name RTCChannelMediaRelayError
 * @fname RTCChannelMediaRelayError
 * @desc 转推错误码
 * @param RTCChannelMediaRelayErrorNone NSInteger 正常
 * @param RTCChannelMediaRelayErrorServerErrorResponse NSInteger 服务器回应出错
 * @param RTCChannelMediaRelayErrorServerNoResponse NSInteger 服务器无回应
 * @param RTCChannelMediaRelayErrorNoResourceAvailable NSInteger SDK无法获取服务
 * @param RTCChannelMediaRelayErrorFailedJoinSourceChannel NSInteger 发起跨频道转发媒体流请求失败
 * @param RTCChannelMediaRelayErrorFailedJoinDestinationChannel NSInteger 接受跨频道转发媒体流请求失败
 * @param RTCChannelMediaRelayErrorFailedPacketReceivedFromSource NSInteger 服务器接收跨频道转发媒体流失败
 * @param RTCChannelMediaRelayErrorFailedPacketSentToDestination NSInteger 服务器发送跨频道转发媒体流失败
 * @param RTCChannelMediaRelayErrorServerConnectionLost NSInteger SDK因网络质量不佳与服务器断开
 * @param RTCChannelMediaRelayErrorInternalError NSInteger 服务器内部出错
 * @param RTCChannelMediaRelayErrorSourceTokenExpired NSInteger 源频道的Token已过期
 * @param RTCChannelMediaRelayErrorDestinationTokenExpired NSInteger 目标频道的Token已过期
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCChannelMediaRelayError) {
    RTCChannelMediaRelayErrorNone = 0,
    RTCChannelMediaRelayErrorServerErrorResponse = 1,
    RTCChannelMediaRelayErrorServerNoResponse = 2,
    RTCChannelMediaRelayErrorNoResourceAvailable = 3,
    RTCChannelMediaRelayErrorFailedJoinSourceChannel = 4,
    RTCChannelMediaRelayErrorFailedJoinDestinationChannel = 5,
    RTCChannelMediaRelayErrorFailedPacketReceivedFromSource = 6,
    RTCChannelMediaRelayErrorFailedPacketSentToDestination = 7,
    RTCChannelMediaRelayErrorServerConnectionLost = 8,
    RTCChannelMediaRelayErrorInternalError = 9,
    RTCChannelMediaRelayErrorSourceTokenExpired = 10,
    RTCChannelMediaRelayErrorDestinationTokenExpired = 11,
};

/**
 * @apidoc
 * @name RTCChannelMediaRelayEvent
 * @fname RTCChannelMediaRelayEvent
 * @desc 转推事件
 * @param RTCChannelMediaRelayEventDisconnect NSInteger 与服务器连接断开
 * @param RTCChannelMediaRelayEventConnected NSInteger 与服务器建立连接
 * @param RTCChannelMediaRelayEventJoinedSourceChannel NSInteger 用户已加入源频道
 * @param RTCChannelMediaRelayEventJoinedDestinationChannel NSInteger 用户已加入目标频道
 * @param RTCChannelMediaRelayEventSentToDestinationChannel NSInteger SDK开始向目标频道发送数据包
 * @param RTCChannelMediaRelayEventReceivedVideoPacketFromSource NSInteger 服务器收到了源频道发送的视频流
 * @param RTCChannelMediaRelayEventReceivedAudioPacketFromSource NSInteger 服务器收到了源频道发送的音频流
 * @param RTCChannelMediaRelayEventUpdateDestinationChannel NSInteger 目标频道已更新
 * @param RTCChannelMediaRelayEventUpdateDestinationChannelRefused NSInteger 内部原因导致目标频道更新失败
 * @param RTCChannelMediaRelayEventUpdateDestinationChannelNotChange NSInteger 目标频道未发生改变，即目标频道更新失败
 * @param RTCChannelMediaRelayEventUpdateDestinationChannelIsNil NSInteger 目标频道名为nil
 * @param RTCChannelMediaRelayEventVideoProfileUpdate NSInteger 视频属性已发送至服务器
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCChannelMediaRelayEvent) {
    RTCChannelMediaRelayEventDisconnect = 0,
    RTCChannelMediaRelayEventConnected = 1,
    RTCChannelMediaRelayEventJoinedSourceChannel = 2,
    RTCChannelMediaRelayEventJoinedDestinationChannel = 3,
    RTCChannelMediaRelayEventSentToDestinationChannel = 4,
    RTCChannelMediaRelayEventReceivedVideoPacketFromSource = 5,
    RTCChannelMediaRelayEventReceivedAudioPacketFromSource = 6,
    RTCChannelMediaRelayEventUpdateDestinationChannel = 7,
    RTCChannelMediaRelayEventUpdateDestinationChannelRefused = 8,
    RTCChannelMediaRelayEventUpdateDestinationChannelNotChange = 9,
    RTCChannelMediaRelayEventUpdateDestinationChannelIsNil = 10,
    RTCChannelMediaRelayEventVideoProfileUpdate = 11,
};

/**
 * @apidoc
 * @name RTCUserPriority
 * @fname RTCUserPriority
 * @desc 用户优先级
 * @param RTCUserPriorityHigh NSInteger 用户需求优先级为高
 * @param RTCUserPriorityNormal NSInteger 用户需求优先级为正常（默认）
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCUserPriority ) {
    RTCUserPriorityHigh   = 50,  // 用户需求优先级为高
    RTCUserPriorityNormal = 100, // 用户需求优先级为正常（默认）
};

/**
 * @apidoc
 * @name OmniRtcLiveSubscriptionStreamType
 * @fname OmniRtcLiveSubscriptionStreamType
 * @desc 订阅流质量类型
 * @param OmniRtcLiveSubscribeStreamTypeHigh NSInteger 高质量流
 * @param OmniRtcLiveSubscribeStreamTypeLow NSInteger 低质量流
 * @param OmniRtcLiveSubscribeStreamTypeAudio NSInteger 音频流
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveSubscriptionStreamType) {
    OmniRtcLiveSubscribeStreamTypeHigh = 0,
    OmniRtcLiveSubscribeStreamTypeLow = 1,
    OmniRtcLiveSubscribeStreamTypeAudio = 2
};

/**
 * @apidoc
 * @name OmniRtcLiveStreamPublishState
 * @fname OmniRtcLiveStreamPublishState
 * @desc 音视频推流状态
 * @param OmniRtcLiveStreamPublishIdle NSInteger 初始状态
 * @param OmniRtcLiveStreamPublishNoPublished NSInteger 未发布状态
 * @param OmniRtcLiveStreamPublishPublishing NSInteger 尝试发布状态
 * @param OmniRtcLiveStreamPublishPublished NSInteger 发布状态
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveStreamPublishState) {
    OmniRtcLiveStreamPublishIdle = 0,
    OmniRtcLiveStreamPublishNoPublished = 1,
    OmniRtcLiveStreamPublishPublishing = 2,
    OmniRtcLiveStreamPublishPublished = 3,
};

/**
 * @apidoc
 * @name OmniRtcLiveStreamSubscribeState
 * @fname OmniRtcLiveStreamSubscribeState
 * @desc 音视频拉流状态
 * @param OmniRtcLiveStreamSubscribeIdle NSInteger 初始状态
 * @param OmniRtcLiveStreamSubscribeNoSubscribed NSInteger 未订阅状态
 * @param OmniRtcLiveStreamSubscribeSubscribing NSInteger 尝试订阅状态
 * @param OmniRtcLiveStreamSubscribeSubscribed NSInteger 订阅状态
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveStreamSubscribeState) {
    OmniRtcLiveStreamSubscribeIdle = 0,
    OmniRtcLiveStreamSubscribeNoSubscribed = 1,
    OmniRtcLiveStreamSubscribeSubscribing = 2,
    OmniRtcLiveStreamSubscribeSubscribed = 3,
};

/**
 * @apidoc
 * @name RTCChannelMediaRelayConfiguration
 * @fname RTCChannelMediaRelayConfiguration
 * @desc 转推配置
 * @param sourceInfo NSInteger 源信息
 * @param destinationInfos NSInteger 目的信息
 * @return 空
 */
@interface RTCChannelMediaRelayConfiguration : NSObject

@property (nonatomic, copy) NSString* sourceInfo;
@property (nonatomic, copy) NSArray<NSString*>* destinationInfos;

@end

@protocol RTCEngineChannelDelegate <NSObject>

/**
 * @apidoc
 * @name rtcChannel:didOccurError:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didOccurError:(RTCEngineErrorCode)errorCode
 * @desc 错误回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param errorCode RTCEngineErrorCode 错误信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel
                 didOccurError:(RTCEngineErrorCode)errorCode;

/**
 * @apidoc
 * @name rtcChannelDidJoinChannel:withUid:elapsed:
 * @fname - (void)rtcChannelDidJoinChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel withUid:(NSUInteger)uid elapsed:(NSInteger) elapsed
 * @desc 加入频道回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param elapsed NSUInteger 耗费时间
 * @return 空
 */
- (void)rtcChannelDidJoinChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel
                            withUid:(NSUInteger)uid
                            elapsed:(NSInteger) elapsed;

/**
 * @apidoc
 * @name rtcChannelDidLeaveChannel:
 * @fname - (void)rtcChannelDidLeaveChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel
 * @desc 已离开频道回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @return 空
 */
- (void)rtcChannelDidLeaveChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel;

/**
 * @apidoc
 * @name rtcChannel:didJoinedOfUid:elapsed:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didJoinedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed
 * @desc 远端用户/主播加入回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param elapsed NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel
                didJoinedOfUid:(NSUInteger)uid
                       elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcChannel:didOfflineOfUid:reason:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didOfflineOfUid:(NSUInteger)uid reason:(RTCChannelUserOfflineReason)reason
 * @desc 远端用户（通信场景）/主播（直播场景）离开当前频道回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param reason RTCChannelUserOfflineReason 离开原因
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel
               didOfflineOfUid:(NSUInteger)uid
                        reason:(RTCChannelUserOfflineReason)reason;

/**
 * @apidoc
 * @name rtcChannel:connectionChangedToState:reason:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel connectionChangedToState:(RTCChannelConnectionStateType)state reason:(RTCChannelConnectionChangedReason)reason
 * @desc 网络连接状态已改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param state NSUInteger 网络状态
 * @param reason RTCChannelConnectionChangedReason 改变原因
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel
      connectionChangedToState:(RTCChannelConnectionStateType)state
                        reason:(RTCChannelConnectionChangedReason)reason;

/**
 * @apidoc
 * @name rtcChannelDidLost:
 * @fname - (void)rtcChannelDidLost:(id<RTCEngineChannel> _Nonnull)rtcChannel
 * @desc 网络连接中断，且 SDK 无法在 10 秒内连接服务器回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @return 空
 */
- (void)rtcChannelDidLost:(id<RTCEngineChannel> _Nonnull)rtcChannel;

/**
 * @apidoc
 * @name rtcChannel:firstRemoteVideoFrameDecodedOfUid:elapsed:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel firstRemoteVideoFrameDecodedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed
 * @desc 已解码远端视频首帧回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param elapsed NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel firstRemoteVideoFrameDecodedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcChannel:firstRemoteVideoFrameOfUid:elapsed:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel firstRemoteVideoFrameOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed
 * @desc 已显示远端视频首帧回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param elapsed NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel firstRemoteVideoFrameOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcChannel:firstRemoteAudioFrameOfUid:elapsed:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel firstRemoteAudioFrameOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed
 * @desc 远端用户的音频首帧回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param elapsed NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel firstRemoteAudioFrameOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcChannel:remoteVideoStateChangedOfUid:state:reason:elapsed:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel remoteVideoStateChangedOfUid:(NSUInteger)uid state:(RTCChannelVideoRemoteState)state reason:(RTCChannelVideoRemoteStateReason)reason elapsed:(NSInteger)elapsed
 * @desc 远端视频状态改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param state RTCChannelVideoRemoteState 视频状态
 * @param reason RTCChannelVideoRemoteStateReason 改变原因
 * @param elapsed NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel remoteVideoStateChangedOfUid:(NSUInteger)uid state:(RTCChannelVideoRemoteState)state reason:(RTCChannelVideoRemoteStateReason)reason elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcChannel:reportRtcStats:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel reportRtcStats:(RTCStats * _Nonnull)stats
 * @desc 统计回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param stats RTCStats* 统计信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel reportRtcStats:(RTCStats * _Nonnull)stats;

/**
 * @apidoc
 * @name rtcChannel:reportRemoteAudioStats:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel reportRemoteAudioStats:(RTCRemoteAudioStats * _Nonnull)stats
 * @desc 远端音频统计回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param stats RTCRemoteAudioStats* 统计信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel reportRemoteAudioStats:(RTCRemoteAudioStats * _Nonnull)stats;

/**
 * @apidoc
 * @name rtcChannel:reportRemoteVideoStats:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel reportRemoteVideoStats:(RTCRemoteVideoStats * _Nonnull)stats
 * @desc 远端视频统计回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param stats RTCRemoteVideoStats* 统计信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel reportRemoteVideoStats:(RTCRemoteVideoStats * _Nonnull)stats;

/**
 * @apidoc
 * @name rtcChannel:networkQuality:txQuality:rxQuality:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel networkQuality:(NSUInteger)uid txQuality:(RTCLastMileQuality)txQuality rxQuality:(RTCLastMileQuality)rxQuality
 * @desc 网络质量回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param txQuality RTCLastMileQuality 网络质量
 * @param rxQuality RTCLastMileQuality 网络质量
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel networkQuality:(NSUInteger)uid txQuality:(RTCLastMileQuality)txQuality rxQuality:(RTCLastMileQuality)rxQuality;

/**
 * @apidoc
 * @name rtcChannel:didAudioMuted:byUid:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid
 * @desc 音频静音回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param muted BOOL 是否静音
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcChannel:didVideoMuted:byUid:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid
 * @desc 视频切换回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param muted BOOL 是否停止发送视频流
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcChannel:videoBufferingStateChangedOfUid:state:timestampInMs:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel videoBufferingStateChangedOfUid:(NSUInteger)uid state:(RTCVideoBufferingState)state timestampInMs:(NSInteger)timestampInMs
 * @desc 视频卡顿回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param muted BOOL 是否停止发送视频流
 * @param uid NSUInteger 用户ID
 * @param state RTCVideoBufferingState 卡顿状态
 * @param timestampInMs NSInteger 时间戳
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel videoBufferingStateChangedOfUid:(NSUInteger)uid state:(RTCVideoBufferingState)state timestampInMs:(NSInteger)timestampInMs;

/**
 * @apidoc
 * @name rtcChannel:audioBufferingStateChangedOfUid:state:timestampInMs:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel audioBufferingStateChangedOfUid:(NSUInteger)uid state:(RTCAudioBufferingState)state timestampInMs:(NSInteger)timestampInMs
 * @desc 音频卡顿回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param muted BOOL 是否停止发送视频流
 * @param uid NSUInteger 用户ID
 * @param state RTCAudioBufferingState 卡顿状态
 * @param timestampInMs NSInteger 时间戳
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel audioBufferingStateChangedOfUid:(NSUInteger)uid state:(RTCAudioBufferingState)state timestampInMs:(NSInteger)timestampInMs;

/**
 * @apidoc
 * @name rtcChannel:receiveStreamMessageFromUid:data:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel receiveStreamMessageFromUid:(NSString *)uid data:(NSData *)data
 * @desc 接收到消息回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSString* 用户ID
 * @param data NSData* 消息数据
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel receiveStreamMessageFromUid:(NSString *)uid data:(NSData *)data;

/**
 * @apidoc
 * @name rtcChannel:channelMediaRelayStateDidChange:error:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel channelMediaRelayStateDidChange:(RTCChannelMediaRelayState)state error:(RTCChannelMediaRelayError)error
 * @desc  跨频道推流状态回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param state RTCChannelMediaRelayState 推流状态
 * @param error RTCChannelMediaRelayError 错误信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel channelMediaRelayStateDidChange:(RTCChannelMediaRelayState)state error:(RTCChannelMediaRelayError)error;

/**
 * @apidoc
 * @name rtcChannel:didReceiveChannelMediaRelayEvent:
 * @fname -(void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didReceiveChannelMediaRelayEvent:(RTCChannelMediaRelayEvent)event
 * @desc  跨频道推流事件回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param event RTCChannelMediaRelayEvent 推流事件
 * @return 空
 */
-(void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didReceiveChannelMediaRelayEvent:(RTCChannelMediaRelayEvent)event;

/**
 * @apidoc
 * @name rtcChannel:didRemoteStreamSubscribeAdvice:currentStream:suitableStream:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)engine didRemoteStreamSubscribeAdvice:(NSUInteger)uid currentStream:(OmniRtcLiveSubscriptionStreamType)currentStream suitableStream:(OmniRtcLiveSubscriptionStreamType)suitableStream;
 * @desc  大小流切换建议回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param currentStream OmniRtcLiveSubscriptionStreamType 当前流类型
 * @param suitableStream OmniRtcLiveSubscriptionStreamType 建议流类型
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)engine didRemoteStreamSubscribeAdvice:(NSUInteger)uid currentStream:(OmniRtcLiveSubscriptionStreamType)currentStream suitableStream:(OmniRtcLiveSubscriptionStreamType)suitableStream;

/**
 * @apidoc
 * @name rtcChannel:didRemoteSubscribeFallbackToAudioOnly:byUid:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didRemoteSubscribeFallbackToAudioOnly:(BOOL)isFallbackOrRecover byUid:(NSUInteger)uid
 * @desc  切换大小流流状态回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param isFallbackOrRecover BOOL 是否只有音频
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel> _Nonnull)rtcChannel didRemoteSubscribeFallbackToAudioOnly:(BOOL)isFallbackOrRecover byUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcChannel:rtmpStreamingChangedToState:state:errorCode:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel rtmpStreamingChangedToState:(NSString *)url state:(RTCRtmpStreamingState)state errorCode:(RTCRtmpStreamingErrorCode)errorCode
 * @desc  RTMP推流状态发生改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param url NSString* 推流地址
 * @param state RTCRtmpStreamingState 推流状态
 * @param errorCode RTCRtmpStreamingErrorCode 错误信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel rtmpStreamingChangedToState:(NSString *)url state:(RTCRtmpStreamingState)state errorCode:(RTCRtmpStreamingErrorCode)errorCode;

/**
 * @apidoc
 * @name rtcChannel:streamPublishedWithUrl:errorCode:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel streamPublishedWithUrl:(NSString *)url errorCode:(RTCRtmpErrorCode)errorCode
 * @desc  RTMP推流回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param url NSString* 推流地址
 * @param errorCode RTCRtmpErrorCode 错误信息
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel streamPublishedWithUrl:(NSString *)url errorCode:(RTCRtmpErrorCode)errorCode;

/**
 * @apidoc
 * @name rtcChannel:streamPublishedWithUrl:errorCode:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel streamUnpublishedWithUrl:(NSString *)url
 * @desc  删除RTMP推流回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param url NSString* 推流地址
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel streamUnpublishedWithUrl:(NSString *)url;

/**
 * @apidoc
 * @name rtcChannelTranscodingUpdated:
 * @fname - (void)rtcChannelTranscodingUpdated:(id<RTCEngineChannel>)rtcChannel
 * @desc  推流参数发生改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @return 空
 */
- (void)rtcChannelTranscodingUpdated:(id<RTCEngineChannel>)rtcChannel;

/**
 * @apidoc
 * @name rtcChannel:didPublishAudioStateChanged:newState:elapseSinceLastState:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didPublishAudioStateChanged:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc  音频推流状态改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param oldState OmniRtcLiveStreamPublishState 推流状态
 * @param newState OmniRtcLiveStreamPublishState 推流状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didPublishAudioStateChanged:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

/**
 * @apidoc
 * @name rtcChannel:didPublishVideoStateChanged:newState:elapseSinceLastState:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didPublishVideoStateChanged:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc  视频推流状态改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param oldState OmniRtcLiveStreamPublishState 推流状态
 * @param newState OmniRtcLiveStreamPublishState 推流状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didPublishVideoStateChanged:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

/**
 * @apidoc
 * @name rtcChannel:didSubscribeAudioStateChanged:oldState:newState:elapseSinceLastState:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didSubscribeAudioStateChanged:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc  音频拉流状态改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param oldState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param newState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didSubscribeAudioStateChanged:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

/**
 * @apidoc
 * @name rtcChannel:didSubscribeVideoStateChanged:oldState:newState:elapseSinceLastState:
 * @fname - (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didSubscribeVideoStateChanged:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc  视频拉流状态改变回调
 * @param rtcChannel id<RTCEngineChannel> Channel对象
 * @param uid NSUInteger 用户ID
 * @param oldState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param newState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcChannel:(id<RTCEngineChannel>)rtcChannel didSubscribeVideoStateChanged:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

@end


@protocol RTCEngineChannel <NSObject>

/**
 * @apidoc
 * @name initWithEngine:token:delegate:
 * @fname - (id<RTCEngineChannel>)initWithEngine:(id<RTCThirdPartEngineProtocol>)engine token:(NSString *)token delegate:(id<RTCEngineChannelDelegate>)delegate
 * @desc 初始化Channel
 * @param engine id<RTCThirdPartEngineProtocol> RTCEngine对象
 * @param token NSString* 令牌
 * @param delegate id<RTCEngineChannelDelegate 代理对象
 * @return 当前对象
 */
- (id<RTCEngineChannel>)initWithEngine:(id<RTCThirdPartEngineProtocol>)engine token:(NSString *)token delegate:(id<RTCEngineChannelDelegate>)delegate;

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
 * @name publish
 * @fname - (int)publish
 * @desc 发布音视频流
 * @return 0表示成功
 */
- (int)publish;

/**
 * @name publish
 * @fname - (int)unpublish
 * @desc 停止发布音视频流
 * @return 0表示成功
 */
- (int)unpublish;

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
 * @name muteRemoteAudioStream:mute:
 * @fname - (int)muteRemoteAudioStream:(NSUInteger)uid mute:(BOOL)isMute
 * @desc 音频静音切换
 * @param uid NSUInteger 用户ID
 * @param isMute BOOL 是否静音
 * @return 0表示成功
 */
- (int)muteRemoteAudioStream:(NSUInteger)uid mute:(BOOL)isMute;

/**
 * @apidoc
 * @name muteAllRemoteAudioStreams:
 * @fname - (int)muteAllRemoteAudioStreams:(BOOL)isMute
 * @desc 静音所有音频
 * @param isMute BOOL 是否静音
 * @return 0表示成功
 */
- (int)muteAllRemoteAudioStreams:(BOOL)isMute;

/**
 * @apidoc
 * @name muteRemoteVideoStream:mute:
 * @fname - (int)muteRemoteVideoStream:(NSUInteger)uid mute:(BOOL)isMute
 * @desc 静音视频切换
 * @param uid NSUInteger 用户ID
 * @param isMute BOOL 开启或停止发送视频流
 * @return 0表示成功
 */
- (int)muteRemoteVideoStream:(NSUInteger)uid mute:(BOOL)isMute;

/**
 * @apidoc
 * @name muteAllRemoteVideoStreams:
 * @fname - (int)muteAllRemoteVideoStreams:(BOOL)isMute
 * @desc 静音所有视频
 * @param isMute BOOL 开启或停止发送视频流
 * @return 0表示成功
 */
- (int)muteAllRemoteVideoStreams:(BOOL)isMute;

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
