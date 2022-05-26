//
//  RTCEngine.h
//  RTCEngine
//  小班课API：https://wiki.zhiyinlou.com/display/zbzt/iOS
//  Copyright © 2021 RTCEngine. All rights reserved.
//

#import <CoreMedia/CoreMedia.h>
#import "RTCMediaDelegate.h"
#import "RTCStats.h"
#import "RTCMediaStats.h"
#import "RTCEngineChannel.h"
#import "RTCRtmpConfig.h"
#import "RTCInspectModeConfig.h"

#import <UIKit/UIKit.h>

/**
 * @apidoc
 * @name OmniRtcLiveAudioFrame
 * @fname OmniRtcLiveAudioFrame
 * @desc 引擎类型
 * @param samplesPerChannel NSInteger 采样个数
 * @param bytesPerSample NSInteger 每个采样字节数
 * @param channels NSInteger 通道数
 * @param samplesPerSec NSInteger 采样率
 * @param buffer NSData* 音频数据
 * @param renderTimeMs int64_t 时间戳
 * @return 空
 */
@interface OmniRtcLiveAudioFrame: NSObject

@property (assign, nonatomic) NSInteger samplesPerChannel;
@property (assign, nonatomic) NSInteger bytesPerSample;
@property (assign, nonatomic) NSInteger channels;
@property (assign, nonatomic) NSInteger samplesPerSec;
@property (strong, nonatomic) NSData* _Nullable buffer;
@property (assign, nonatomic) int64_t renderTimeMs;

@end

//! Project version number for RTCEngine.
FOUNDATION_EXPORT double RTCEngineVersionNumber;

//! Project version string for RTCEngine.
FOUNDATION_EXPORT const unsigned char RTCEngineVersionString[];

@protocol RTCEngineDelegate;
@protocol RTCEngineChannelDelegate;
@protocol RTCEngineChannel;

/**
 * @apidoc
 * @name RTCEngineType
 * @fname RTCEngineType
 * @desc 引擎类型
 * @param RTCEngineTypeUnknown NSInteger 美声
 * @param RTCEngineTypeOmniRtc NSInteger OmniRtc
 * @param RTCEngineTypeAgora NSInteger 声网引擎
 * @param RTCEngineTypeTencent NSInteger 腾讯引擎
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineType) {
    RTCEngineTypeUnknown = 0,
    RTCEngineTypeOmniRtc = 1,
    RTCEngineTypeAgora   = 2,
    RTCEngineTypeTencent = 3,
};

/**
 * @apidoc
 * @name RTCFeature
 * @fname RTCFeature
 * @desc 特殊功能
 * @param RTCFeatureBeautyAudio NSInteger 美声
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCFeature) {
    RTCFeatureBeautyAudio = 1, // 美声
};

/**
 * @apidoc
 * @name RTCEngineState
 * @fname RTCEngineState
 * @desc 引擎状态
 * @param RTCEngineStateNew NSInteger 新建
 * @param RTCEngineStateConnected NSInteger 链接完成
 * @param RTCEngineStateDisConnected NSInteger 链接断开
 * @param RTCEngineStateFailed NSInteger 链接失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineState) {
    RTCEngineStateNew,
    RTCEngineStateConnected,
    RTCEngineStateDisConnected,
    RTCEngineStateFailed,
};

/**
 * @apidoc
 * @name RTCEngineAudioOutputRouting
 * @fname RTCEngineAudioOutputRouting
 * @desc 音频路由
 * @param RTCEngineAudioOutputRoutingDefault NSInteger 默认
 * @param RTCEngineAudioOutputRoutingHeadset NSInteger 头戴式耳机
 * @param RTCEngineAudioOutputRoutingEarpiece NSInteger 耳机
 * @param RTCEngineAudioOutputRoutingHeadsetNoMic NSInteger 未带麦克风耳机
 * @param RTCEngineAudioOutputRoutingSpeakerphone NSInteger 听筒
 * @param RTCEngineAudioOutputRoutingLoudspeaker NSInteger 扬声器
 * @param RTCEngineAudioOutputRoutingHeadsetBluetooth NSInteger 蓝牙
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineAudioOutputRouting)
{
    RTCEngineAudioOutputRoutingDefault = -1,
    RTCEngineAudioOutputRoutingHeadset = 0,
    RTCEngineAudioOutputRoutingEarpiece = 1,
    RTCEngineAudioOutputRoutingHeadsetNoMic = 2,
    RTCEngineAudioOutputRoutingSpeakerphone = 3,
    RTCEngineAudioOutputRoutingLoudspeaker = 4,
    RTCEngineAudioOutputRoutingHeadsetBluetooth = 5
};

/**
 * @apidoc
 * @name RTC_ENGINE_VIDEO_RESOLUTION
 * @fname RTC_ENGINE_VIDEO_RESOLUTION
 * @desc 视频分辨率
 * @param RTC_VIDEO_RESOLUTION_120P NSInteger 120p
 * @param RTC_VIDEO_RESOLUTION_180P NSInteger 180p
 * @param RTC_VIDEO_RESOLUTION_240P NSInteger 240p
 * @param RTC_VIDEO_RESOLUTION_360P NSInteger 360p
 * @param RTC_VIDEO_RESOLUTION_480P NSInteger 480p
 * @param RTC_VIDEO_RESOLUTION_640P NSInteger 640p
 * @param RTC_VIDEO_RESOLUTION_720P NSInteger 720p
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTC_ENGINE_VIDEO_RESOLUTION) {
    RTC_VIDEO_RESOLUTION_120P = 0,
    RTC_VIDEO_RESOLUTION_180P = 1,
    RTC_VIDEO_RESOLUTION_240P = 2,
    RTC_VIDEO_RESOLUTION_360P = 3,
    RTC_VIDEO_RESOLUTION_480P = 4,
    RTC_VIDEO_RESOLUTION_640P = 5,
    RTC_VIDEO_RESOLUTION_720P = 6,
};

/**
 * @apidoc
 * @name RTC_ENGINE_VIDEO_BITRATE
 * @fname RTC_ENGINE_VIDEO_BITRATE
 * @desc 视频码率
 * @param RTC_VIDEO_BITRATE_100 NSInteger 最大100kbps
 * @param RTC_VIDEO_BITRATE_120 NSInteger 最大120kbps
 * @param RTC_VIDEO_BITRATE_200 NSInteger 最大200kbps
 * @param RTC_VIDEO_BITRATE_350 NSInteger 最大350kbps
 * @param RTC_VIDEO_BITRATE_400 NSInteger 最大400kbps
 * @param RTC_VIDEO_BITRATE_600 NSInteger 最大600kbps
 * @param RTC_VIDEO_BITRATE_1000 NSInteger 最大1000kbps
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTC_ENGINE_VIDEO_BITRATE) {
    RTC_VIDEO_BITRATE_100 = 100, // MAX 100
    RTC_VIDEO_BITRATE_120 = 120, // MAX 120
    RTC_VIDEO_BITRATE_200 = 200, // MAX 200
    RTC_VIDEO_BITRATE_350 = 350, // MAX 350
    RTC_VIDEO_BITRATE_400 = 400, // MAX 400
    RTC_VIDEO_BITRATE_600 = 600, // MAX 600
    RTC_VIDEO_BITRATE_1000 = 1000,// MAX 1000
};

/// 已废弃，请使用RTCOrientationMode代替
typedef NS_ENUM(NSInteger,RTC_ORIENTATION_MODE) {
    RTC_OrientationModeAdaptative = 0,
    RTC_OrientationModeFixedLandscape = 1,
    RTC_OrientationModeFixedPortrait = 2,
};

/**
 * @apidoc
 * @name RTCOrientationMode
 * @fname RTCOrientationMode
 * @desc 视频方向
 * @param RTCOrientationModeAdaptative NSInteger 自适应
 * @param RTCOrientationModeFixedLandscape NSInteger 横屏
 * @param RTCOrientationModeFixedPortrait NSInteger 竖屏
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCOrientationMode) {
    RTCOrientationModeAdaptative = 0,
    RTCOrientationModeFixedLandscape = 1,
    RTCOrientationModeFixedPortrait = 2,
};

/**
 * @apidoc
 * @name RTCEngineLogLevelType
 * @fname RTCEngineLogLevelType
 * @desc 日志等级
 * @param RTCEngineLogLevelTypeOff NSInteger 不输出日志信息
 * @param RTCEngineLogLevelTypeDebug NSInteger 输出所有API日志信息
 * @param RTCEngineLogLevelTypeInfo NSInteger 输出CRITICAL、ERROR、WARNING和INFO级别的日志信息，推荐
 * @param RTCEngineLogLevelTypeWarning NSInteger 输出CRITICAL、ERROR和WARNING级别的日志信息
 * @param RTCEngineLogLevelTypeError NSInteger 输出CRITICAL和ERROR级别的日志信息
 * @param RTCEngineLogLevelTypeCritical NSInteger 输出CRITICAL级别的日志信息
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCEngineLogLevelType) {
    RTCEngineLogLevelTypeOff = 0,               // 不输出日志信息
    RTCEngineLogLevelTypeDebug = 0x080f,       // 输出所有 API 日志信息
    RTCEngineLogLevelTypeInfo = 0x000f,        // 输出 CRITICAL、ERROR、WARNING 和 INFO 级别的日志信息，推荐
    RTCEngineLogLevelTypeWarning = 0x000e,     // 输出 CRITICAL、ERROR 和 WARNING 级别的日志信息
    RTCEngineLogLevelTypeError = 0x000c,       // 输出 CRITICAL 和 ERROR 级别的日志信息
    RTCEngineLogLevelTypeCritical = 0x0008,    // 输出 CRITICAL 级别的日志信息
};

/**
 * @apidoc
 * @name RTCConnectionStateType
 * @fname RTCConnectionStateType
 * @desc 链接状态
 * @param RTCConnectionStateTypeDisconnected NSInteger 链接断开
 * @param RTCConnectionStateTypeConnecting NSInteger 链接中
 * @param RTCConnectionStateTypeConnected NSInteger 链接完成
 * @param RTCConnectionStateTypeReconnecting NSInteger 重新链接
 * @param RTCConnectionStateTypeFailed NSInteger 链接失败
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCConnectionStateType) {
    RTCConnectionStateTypeDisconnected  = 1,
    RTCConnectionStateTypeConnecting    = 2,
    RTCConnectionStateTypeConnected     = 3,
    RTCConnectionStateTypeReconnecting  = 4,
    RTCConnectionStateTypeFailed        = 5,
};

/**
 * @apidoc
 * @name RTCEngineMetadataType
 * @fname RTCEngineMetadataType
 * @desc 元数据类型
 * @param RTCEngineMetadataTypeUnknown NSInteger 未知
 * @param RTCEngineMetadataTypeVideo NSInteger 视频
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineMetadataType) {
    RTCEngineMetadataTypeUnknown = -1,
    RTCEngineMetadataTypeVideo   = 0,
};

/**
 * @apidoc
 * @name RTCAudioMixingStateCode
 * @fname RTCAudioMixingStateCode
 * @desc 音频混音状态
 * @param RTCAudioMixingStatePlaying NSInteger 播放
 * @param RTCAudioMixingStatePaused NSInteger 暂停
 * @param RTCAudioMixingStateStopped NSInteger 停止
 * @param RTCAudioMixingStateFailed NSInteger 失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCAudioMixingStateCode)
{
    RTCAudioMixingStatePlaying = 710,
    RTCAudioMixingStatePaused = 711,
    RTCAudioMixingStateStopped = 713,
    RTCAudioMixingStateFailed = 714
};

/**
 * @apidoc
 * @name RTCAudioMixingErrorCode
 * @fname RTCAudioMixingErrorCode
 * @desc 音频混音错误
 * @param RTCAudioMixingErrorCanNotOpen NSInteger 未打开
 * @param RTCAudioMixingErrorTooFrequentCall NSInteger 太过频繁
 * @param RTCAudioMixingErrorInterruptedEOF NSInteger 文件结束
 * @param RTCAudioMixingErrorOK NSInteger OK
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCAudioMixingErrorCode)
{
    RTCAudioMixingErrorCanNotOpen = 701,
    RTCAudioMixingErrorTooFrequentCall = 702,
    RTCAudioMixingErrorInterruptedEOF = 703,
    RTCAudioMixingErrorOK = 0
};

/**
 * @apidoc
 * @name RTCEngineClientRole
 * @fname RTCEngineClientRole
 * @desc 用户角色
 * @param RTCEngineClientRoleBroadcaster NSInteger 主播
 * @param RTCEngineClientRoleAudience NSInteger 观众
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineClientRole)
{
    RTCEngineClientRoleBroadcaster = 1,                  // 主播
    RTCEngineClientRoleAudience = 2,                     // 观众
};

/**
 * @apidoc
 * @name RTCEngineVideoRemoteState
 * @fname RTCEngineVideoRemoteState
 * @desc 远端视频状态
 * @param RTCEngineVideoRemoteStateStopped NSInteger 远端视频默认初始状态
 * @param RTCEngineVideoRemoteStateStarting NSInteger 本地用户已接收远端视频首包
 * @param RTCEngineVideoRemoteStateDecoding NSInteger 远端视频流正在解码，正常播放
 * @param RTCEngineVideoRemoteStateFrozen NSInteger 远端视频流卡顿
 * @param RTCEngineVideoRemoteStateFailed NSInteger 远端视频流播放失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCEngineVideoRemoteState)
{
    RTCEngineVideoRemoteStateStopped = 0,              // 远端视频默认初始状态
    RTCEngineVideoRemoteStateStarting = 1,             // 本地用户已接收远端视频首包
    RTCEngineVideoRemoteStateDecoding = 2,             // 远端视频流正在解码，正常播放
    RTCEngineVideoRemoteStateFrozen = 3,               // 远端视频流卡顿
    RTCEngineVideoRemoteStateFailed = 4,               // 远端视频流播放失败
};

/**
 * @apidoc
 * @name RTCEngineVideoRemoteStateReason
 * @fname RTCEngineVideoRemoteStateReason
 * @desc 远端视频状态切换原因
 * @param RTCEngineVideoRemoteStateReasonInternal NSInteger 内部原因
 * @param RTCEngineVideoRemoteStateReasonNetworkCongestion NSInteger 网络拥塞
 * @param RTCEngineVideoRemoteStateReasonNetworkRecovery NSInteger 网络恢复
 * @param RTCEngineVideoRemoteStateReasonLocalMuted NSInteger 本地mute
 * @param RTCEngineVideoRemoteStateReasonLocalUnmuted NSInteger 本地unmute
 * @param RTCEngineVideoRemoteStateReasonRemoteMuted NSInteger 远端mute
 * @param RTCEngineVideoRemoteStateReasonRemoteUnmuted NSInteger 远端unmute
 * @param RTCEngineVideoRemoteStateReasonRemoteOffline NSInteger 远端离线
 * @param RTCEngineVideoRemoteStateReasonAudioFallback NSInteger 音频回退
 * @param RTCEngineVideoRemoteStateReasonAudioFallbackRecovery NSInteger 音频回退恢复
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCEngineVideoRemoteStateReason) {
    RTCEngineVideoRemoteStateReasonInternal = 0,
    RTCEngineVideoRemoteStateReasonNetworkCongestion = 1,
    RTCEngineVideoRemoteStateReasonNetworkRecovery = 2,
    RTCEngineVideoRemoteStateReasonLocalMuted = 3,
    RTCEngineVideoRemoteStateReasonLocalUnmuted = 4,
    RTCEngineVideoRemoteStateReasonRemoteMuted = 5,
    RTCEngineVideoRemoteStateReasonRemoteUnmuted = 6,
    RTCEngineVideoRemoteStateReasonRemoteOffline = 7,
    RTCEngineVideoRemoteStateReasonAudioFallback = 8,
    RTCEngineVideoRemoteStateReasonAudioFallbackRecovery = 9,
};

/**
 * @apidoc
 * @name RTCAudioMode
 * @fname RTCAudioMode
 * @desc 通话模式
 * @param RTCAudioModeMedia NSInteger 媒体音量
 * @param RTCAudioModeChat NSInteger 通话音量
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCAudioMode) {
    RTCAudioModeMedia = 0,                   // 媒体音量
    RTCAudioModeChat = 1,                    // 通话音量
};

/**
 * @apidoc
 * @name RTCOutputPixelFormat
 * @fname RTCOutputPixelFormat
 * @desc 像素格式
 * @param RTCOutputPixelFormatI420 NSInteger I420
 * @param RTCOutputPixelFormatRGBA NSInteger RGBA
 * @param RTCOutputPixelFormatNV12 NSInteger NV12
 * @return 空
 */
typedef NS_ENUM(NSUInteger, RTCOutputPixelFormat) {
    RTCOutputPixelFormatI420 = 0,                   
    RTCOutputPixelFormatRGBA = 1,
    RTCOutputPixelFormatNV12 = 2,
};

/**
 * @apidoc
 * @name OmniRtcLiveAudioRawFrameOperationMode
 * @fname OmniRtcLiveAudioRawFrameOperationMode
 * @desc 音频裸数操作方式
 * @param OmniRtcLiveAudioRawFrameOperationModeReadOnly NSInteger 只读
 * @param OmniRtcLiveAudioRawFrameOperationModeWriteOnly NSInteger 只写
 * @param OmniRtcLiveAudioRawFrameOperationModeReadWrite NSInteger 可读写
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveAudioRawFrameOperationMode) {
    OmniRtcLiveAudioRawFrameOperationModeReadOnly = 0,
    OmniRtcLiveAudioRawFrameOperationModeWriteOnly = 1,
    OmniRtcLiveAudioRawFrameOperationModeReadWrite = 2,
};

/**
 * @apidoc
 * @name OmniRtcLiveAudioExternalSourceId
 * @fname OmniRtcLiveAudioExternalSourceId
 * @desc 混音方式
 * @param OmniRtcLiveAudioExternalPlayoutSource NSInteger 只本地播放，不做混音
 * @param OmniRtcLiveAudioExternalRecordSourcePreProcess NSInteger 在音频处理前做混音
 * @param OmniRtcLiveAudioExternalRecordSourcePostProcess NSInteger 在音频处理后做混音
 * @return 空
 */
typedef NS_ENUM(NSUInteger, OmniRtcLiveAudioExternalSourceId) {
    // 只本地播放，不做混音
    OmniRtcLiveAudioExternalPlayoutSource = 0,
    // 在音频处理前做混音
    OmniRtcLiveAudioExternalRecordSourcePreProcess = 1,
    // 在音频处理后做混音
    OmniRtcLiveAudioExternalRecordSourcePostProcess = 2,
};

/**
 * @apidoc
 * @name OmniRtcLiveBusinessUserRole
 * @fname OmniRtcLiveBusinessUserRole
 * @desc 业务类型
 * @param OmniRtcLiveBusinessUserRoleStudent NSInteger 学生
 * @param OmniRtcLiveBusinessUserRoleTeacher NSInteger 老师
 * @param OmniRtcLiveBusinessUserRoleTutor NSInteger 游客
 * @return 空
 */
typedef NS_ENUM(NSUInteger, OmniRtcLiveBusinessUserRole) {
    OmniRtcLiveBusinessUserRoleStudent = 0,
    OmniRtcLiveBusinessUserRoleTeacher = 1,
    OmniRtcLiveBusinessUserRoleTutor =   2,
};

/**
 * @apidoc
 * @name OmniRtcLiveStreamFallbackOptions
 * @fname OmniRtcLiveStreamFallbackOptions
 * @desc 大小流模式
 * @param OmniRtcLiveStreamFallbackOptionDisabled NSInteger 不自动切换
 * @param OmniRtcLiveStreamFallbackOptionVideoStreamLow NSInteger 切换视频小流
 * @param OmniRtcLiveStreamFallbackOptionAudioOnly NSInteger 切换为只有音频流
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveStreamFallbackOptions) {
    // 不自动切换
    OmniRtcLiveStreamFallbackOptionDisabled = 0,
    // 切换视频小流
    OmniRtcLiveStreamFallbackOptionVideoStreamLow = 1,
    // 切换为只有音频流
    OmniRtcLiveStreamFallbackOptionAudioOnly = 2,
};

/**
 * @apidoc
 * @name OmniRtcLiveCameraPosition
 * @fname OmniRtcLiveCameraPosition
 * @desc 摄像头位置
 * @param OmniRtcLiveCameraPositionBack NSInteger 后置摄像头
 * @param OmniRtcLiveCameraPositionFront NSInteger 前置摄像头
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveCameraPosition) {
    OmniRtcLiveCameraPositionBack  = 1, // 后置摄像头
    OmniRtcLiveCameraPositionFront = 2, // 前置摄像头
};

/**
 * @apidoc
 * @name OmniRtcLiveMirrorMode
 * @fname OmniRtcLiveMirrorMode
 * @desc 视频镜像莫斯
 * @param OmniRtcLiveMirrorModeNone NSInteger 不开启镜像，默认
 * @param OmniRtcLiveMirrorModePreview NSInteger 仅本地预览镜像
 * @param OmniRtcLiveMirrorModeRemote NSInteger 仅远端结果镜像
 * @param OmniRtcLiveMirrorModeBoth NSInteger 本地预览和远端结果均镜像
 * @return 空
 */
typedef NS_OPTIONS(NSInteger, OmniRtcLiveMirrorMode) {
    OmniRtcLiveMirrorModeNone    = 0,
    OmniRtcLiveMirrorModePreview = 1 << 0,
    OmniRtcLiveMirrorModeRemote  = 1 << 1,
    OmniRtcLiveMirrorModeBoth    = OmniRtcLiveMirrorModePreview | OmniRtcLiveMirrorModeRemote,
    OmniRtcLiveMirrorModeAuto    = 1 << 2,
};

/**
 * @apidoc
 * @name OmniRtcLiveVideoMirrorMode
 * @fname OmniRtcLiveVideoMirrorMode
 * @desc 视频镜像莫斯
 * @param OmniRtcLiveVideoMirrorModeAuto NSInteger 自动模式
 * @param OmniRtcLiveVideoMirrorModeEnabled NSInteger 设置镜像
 * @param OmniRtcLiveVideoMirrorModeDisabled NSInteger 设置非镜像
 * @return 空
 */
typedef NS_ENUM(NSUInteger, OmniRtcLiveVideoMirrorMode) {
    OmniRtcLiveVideoMirrorModeAuto = 0,
    OmniRtcLiveVideoMirrorModeEnabled = 1,
    OmniRtcLiveVideoMirrorModeDisabled = 2,
};

/**
 * @apidoc
 * @name RTCLocalVideoStreamState
 * @fname RTCLocalVideoStreamState
 * @desc 本地视频流状态
 * @param RTCLocalVideoStreamStateStopped NSInteger 视频流停止
 * @param RTCLocalVideoStreamStateCapturing NSInteger 视频流采集
 * @param RTCLocalVideoStreamStateEncoding NSInteger 视频流编码
 * @param RTCLocalVideoStreamStateFailed NSInteger 视频流失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCLocalVideoStreamState) {
    RTCLocalVideoStreamStateStopped = 0,
    RTCLocalVideoStreamStateCapturing = 1,
    RTCLocalVideoStreamStateEncoding = 2,
    RTCLocalVideoStreamStateFailed = 3,
};

/**
 * @apidoc
 * @name RTCLocalVideoStreamError
 * @fname RTCLocalVideoStreamError
 * @desc 本地视频流错误
 * @param RTCLocalVideoStreamErrorOK NSInteger OK
 * @param RTCLocalVideoStreamErrorFailure NSInteger 失败
 * @param RTCLocalVideoStreamErrorDeviceNoPermission NSInteger 未授权
 * @param RTCLocalVideoStreamErrorDeviceBusy NSInteger 设备繁忙
 * @param RTCLocalVideoStreamErrorCaptureFailure NSInteger 采集失败
 * @param RTCLocalVideoStreamErrorEncodeFailure NSInteger 编码失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCLocalVideoStreamError) {
    RTCLocalVideoStreamErrorOK = 0,
    RTCLocalVideoStreamErrorFailure = 1,
    RTCLocalVideoStreamErrorDeviceNoPermission = 2,
    RTCLocalVideoStreamErrorDeviceBusy = 3,
    RTCLocalVideoStreamErrorCaptureFailure = 4,
    RTCLocalVideoStreamErrorEncodeFailure = 5,
};

/**
 * @apidoc
 * @name RTCAudioProcessMode
 * @fname RTCAudioProcessMode
 * @desc 音频处理模式
 * @param RTCAudioProcessModeNormal NSInteger 默认
 * @param RTCAudioProcessModeFastProcessing NSInteger 音频处理环节使用16K
 * @param RTCAudioProcessModeFastRecording NSInteger 全流程16K
 * @return 空
 */
typedef NS_ENUM(NSInteger, RTCAudioProcessMode) {
    RTCAudioProcessModeNormal = 0,          // 默认
    RTCAudioProcessModeFastProcessing = 1,  // 音频处理环节使用16K
    RTCAudioProcessModeFastRecording = 2,   // 全流程16K
};

/**
 * @apidoc
 * @name OmniRtcLiveConnectionStateType
 * @fname OmniRtcLiveConnectionStateType
 * @desc 链接状态
 * @param OmniRtcLiveConnectionStateDisconnected NSInteger 断开链接
 * @param OmniRtcLiveConnectionStateConnecting NSInteger 链接中
 * @param OmniRtcLiveConnectionStateConnected NSInteger 链接成功
 * @param OmniRtcLiveConnectionStateReconnecting NSInteger 重新链接
 * @param OmniRtcLiveConnectionStateFailed NSInteger 链接失败
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveConnectionStateType) {
    OmniRtcLiveConnectionStateDisconnected = 1,
    OmniRtcLiveConnectionStateConnecting = 2,
    OmniRtcLiveConnectionStateConnected = 3,
    OmniRtcLiveConnectionStateReconnecting = 4,
    OmniRtcLiveConnectionStateFailed = 5,
};

/**
 * @apidoc
 * @name OmniRtcLiveAudioProfile
 * @fname OmniRtcLiveAudioProfile
 * @desc 音频配置
 * @param OmniRtcLiveAudioProfileDefault NSInteger 默认
 * @param OmniRtcLiveAudioProfileSpeechStandard NSInteger 演讲
 * @param OmniRtcLiveAudioProfileMusicStandard NSInteger 音乐
 * @param OmniRtcLiveAudioProfileMusicStandardStereo NSInteger 音乐双声道
 * @param OmniRtcLiveAudioProfileMusicHighQuality NSInteger 高质量
 * @param OmniRtcLiveAudioProfileMusicHighQualityStereo NSInteger 高质量双声道
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveAudioProfile) {
    OmniRtcLiveAudioProfileDefault = 0,
    OmniRtcLiveAudioProfileSpeechStandard = 1,
    OmniRtcLiveAudioProfileMusicStandard = 2,
    OmniRtcLiveAudioProfileMusicStandardStereo = 3,
    OmniRtcLiveAudioProfileMusicHighQuality = 4,
    OmniRtcLiveAudioProfileMusicHighQualityStereo = 5,
};

/**
 * @apidoc
 * @name OmniRtcLiveAudioScenario
 * @fname OmniRtcLiveAudioScenario
 * @desc 音频场景
 * @param OmniRtcLiveAudioScenarioDefault NSInteger 默认设置
 * @param OmniRtcLiveAudioScenarioChatRoomEntertainment NSInteger 娱乐场景，适用于用户需要频繁上下麦的场景
 * @param OmniRtcLiveAudioScenarioEducation NSInteger 教育场景，适用于需要高流畅度和稳定性的场景
 * @param OmniRtcLiveAudioScenarioGameStreaming NSInteger 高音质语聊房场景，适用于音乐为主的场景
 * @param OmniRtcLiveAudioScenarioShowRoom NSInteger 秀场场景，适用于需要高音质的单主播场景
 * @param OmniRtcLiveAudioScenarioChatRoomGaming NSInteger 游戏开黑场景，适用于只有人声的场景
 * @param OmniRtcLiveAudioScenarioIot NSInteger IoT（物联网）场景，适用于使用低功耗IoT设备的场景
 * @param OmniRtcLiveAudioScenarioCommunication NSInteger 通信场景
 * @param OmniRtcLiveAudioScenarioMeeting NSInteger 会议场景，适用于人声为主的多人会议
 * @return 空
 */
typedef NS_ENUM(NSInteger, OmniRtcLiveAudioScenario) {
    OmniRtcLiveAudioScenarioDefault = 0,
    OmniRtcLiveAudioScenarioChatRoomEntertainment = 1,
    OmniRtcLiveAudioScenarioEducation = 2,
    OmniRtcLiveAudioScenarioGameStreaming = 3,
    OmniRtcLiveAudioScenarioShowRoom = 4,
    OmniRtcLiveAudioScenarioChatRoomGaming = 5,
    OmniRtcLiveAudioScenarioIot = 6,
    OmniRtcLiveAudioScenarioCommunication = 7,
    OmniRtcLiveAudioScenarioMeeting = 8,
};

/**
 * @apidoc
 * @name OmniRtcLiveEnterConfig
 * @fname OmniRtcLiveEnterConfig
 * @desc 进房间配置参数
 * @param roomId NSString* 房间号
 * @param uid long 用户ID
 * @param engineType RTCEngineType 引擎类型
 * @param appId NSString* 应用标识
 * @param planId NSString* planId
 * @param token NSString* 令牌
 * @return 空
 */
@interface OmniRtcLiveEnterConfig : NSObject

@property (nonatomic, copy) NSString* roomId;       // 可选
@property (nonatomic, assign) long long uid;        // 可选
@property (nonatomic, assign) RTCEngineType  engineType; // 必须
@property (nonatomic, copy) NSString* appId;        // 必须
@property (nonatomic, copy) NSString* planId;       // 课程Id. 可传空
@property (nonatomic, copy) NSString* token;        // 鉴权时需要, 不需要鉴权时可传空

@end

/**
 * @apidoc
 * @name OmniRtcLiveChannelMediaOptions
 * @fname OmniRtcLiveChannelMediaOptions
 * @desc 媒体选项
 * @param autoSubscribeAudio BOOL 是否自动订阅音频流
 * @param autoSubscribeVideo BOOL 是否自动订阅视频流
 * @param publishLocalAudio BOOL 是否发布音频流
 * @param publishLocalVideo BOOL 是否发布视频流
 * @return 空
 */
@interface OmniRtcLiveChannelMediaOptions : NSObject

@property(nonatomic, assign) BOOL autoSubscribeAudio;               // 默认是YES
@property(nonatomic, assign) BOOL autoSubscribeVideo;               // 默认是YES
@property(nonatomic, assign) BOOL publishLocalAudio;                // 默认是YES
@property(nonatomic, assign) BOOL publishLocalVideo;                // 默认是YES

@end

@interface RTCEngine : NSObject

/**
 * @apidoc
 * @name setDelegate
 * @fname - (void)setDelegate
 * @desc 设置Engine回调
 * @return 空
 */
@property (nonatomic,weak) id<RTCEngineDelegate> delegate;

/**
 * @apidoc
 * @name setVideoProcessDelegate
 * @fname - (void)setVideoProcessDelegate
 * @desc 设置视频数据回调
 * @return 空
 */
@property (nonatomic,weak) id<RTCMediaVideoProcessDelegate> videoProcessDelegate;

/**
 * @apidoc
 * @name setAudioProcessDelegate
 * @fname - (void)setAudioProcessDelegate
 * @desc 设置音频数据回调
 * @return 空
 */
@property (nonatomic,weak) id<RTCMediaAudioProcessDelegate> audioProcessDelegate;

/**
 * @apidoc
 * @name getVersion
 * @fname + (NSString *_Nonnull)getVersion
 * @desc 获取封装层版本号
 * @return SDK版本号
 */
+ (NSString *_Nonnull)getVersion;

/**
 * @apidoc
 * @name initWithToken:delegate:
 * @fname - (instancetype)initWithToken:(NSString*)token delegate:(id<RTCEngineDelegate>)delegate
 * @desc Engine 先进房间时，使用该方法初始化引擎，要跟创建 Channel 在同一个线程中调用
 * @param  token  NSString*  令牌
 * @param  delegate  id<RTCEngineDelegate>)  代理对象
 * @return 当前对象
 */
- (instancetype)initWithToken:(NSString*)token delegate:(id<RTCEngineDelegate>)delegate;

/**
 * @apidoc
 * @name initWithDelegate:
 * @fname - (instancetype)initWithDelegate:(id<RTCEngineDelegate>) delegate
 * @desc Channel 先进房间时，使用该方法初始化引擎，要跟创建 Channel 在同一个线程中调用
 * @param  delegate  id<RTCEngineDelegate>)  代理对象
 * @return 当前对象
 */
- (instancetype)initWithDelegate:(id<RTCEngineDelegate>) delegate;

/**
 * @apidoc
 * @name resetEngienWithToken:delegate:
 * @fname - (void)resetEngienWithToken:(NSString*)token delegate:(id<RTCEngineDelegate>)delegate
 * @desc 重置Engine房间的token，在通过 initWithDelegate: 方法先进入channel房间后，可通过该方法切换engine的token
 * @param  token  NSString*  令牌
 * @param  delegate  id<RTCEngineDelegate>  代理对象
 * @return 空
 */
- (void)resetEngienWithToken:(NSString*)token delegate:(id<RTCEngineDelegate>)delegate;

/**
 * @apidoc
 * @name createChannelWithToken:elegate:
 * @fname - (id<RTCEngineChannel>) createChannelWithToken:(NSString*)token delegate:(id<RTCEngineChannelDelegate>)delegate
 * @desc 创建 Channel，要跟创建 Engine 在同一个线程中，已废弃，请使用RTCChannel代替
 * @param  token  NSString*  令牌
 * @param  delegate  id<RTCEngineChannelDelegate>  代理对象
 * @return Channel对象
 */
- (id<RTCEngineChannel>) createChannelWithToken:(NSString*)token delegate:(id<RTCEngineChannelDelegate>)delegate DEPRECATED_MSG_ATTRIBUTE("Use RTCChannel instead.");

/**
 * @apidoc
 * @name initWithEnterConfig:delegate:
 * @fname - (instancetype)initWithEnterConfig:(OmniRtcLiveEnterConfig*)enterConfig delegate:(id<RTCEngineDelegate>)delegate
 * @desc 不使用token初始化
 * @param  enterConfig  OmniRtcLiveEnterConfig*  自定义参数
 * @param  delegate  id<RTCEngineDelegate>  代理对象
 * @return 当前对象
 */
- (instancetype)initWithEnterConfig:(OmniRtcLiveEnterConfig*)enterConfig delegate:(id<RTCEngineDelegate>)delegate;

/**
 * @apidoc
 * @name initWithAppID:engineType:roomID:uid:delegate:
 * @fname - (instancetype)initWithAppID:(NSString*)appID engineType:(RTCEngineType)engineType roomID:(NSString*)roomID uid:(NSString*)userID delegate:(id<RTCEngineDelegate>)delegate
 * @desc 不使用token初始化（培优项目使用初始化方式）
 * @param  appID  NSString*  应用程序标识
 * @param  engineType   NSString*  引擎类型
 * @param  roomID   NSString*  房间号
 * @param  userID   NSString*  用户ID
 * @param  delegate  id<RTCEngineDelegate>  代理对象
 * @return 当前对象
 */
- (instancetype)initWithAppID:(NSString*)appID engineType:(RTCEngineType)engineType roomID:(NSString*)roomID uid:(NSString*)userID delegate:(id<RTCEngineDelegate>)delegate;

/**
 * @apidoc
 * @name getEngineType
 * @fname - (RTCEngineType)getEngineType
 * @desc 获取引擎类型
 * @return 当前对象
 */
- (RTCEngineType)getEngineType;

/**
 * @name checkFeatureSupport:
 * @fname - (int)checkFeatureSupport:(RTCFeature)feature
 * @desc 检查是否支持某功能（1：支持；0：不支持；<0：错误）
 * @param  feature   RTCFeature  待检查特性
 * @return 返回int
 */
- (int)checkFeatureSupport:(RTCFeature)feature;

/**
 * @name setConfig:
 * @fname - (void)setConfig:(NSDictionary*)configure
 * @desc 自定义配置
 * @param  configure   NSDictionary*  自定义配置项
 * @return 空
 */
- (void)setConfig:(NSDictionary*)configure;

/**
 * @apidoc
 * @name setPrivateParameters:
 * @fname - (int)setPrivateParameters:(NSString*)param
 * @desc 设置私有参数，仅声网有效
 * @param  param   NSString*  私有参数
 * @return 0表示成功
 */
- (int)setPrivateParameters:(NSString*)param;

/**
 * @apidoc
 * @name setRole:
 * @fname - (int)setRole:(RTCEngineClientRole)role
 * @desc 设置用户角色
 * @param  role   RTCEngineClientRole  用户角色
 * @return 0表示成功
 */
- (int)setRole:(RTCEngineClientRole)role;

/**
 * @apidoc
 * @name destroy
 * @fname - (void)destroy
 * @desc 销毁引擎对象
 * @return 空
 */
- (void)destroy;

/**
 * @apidoc
 * @name joinRoom
 * @fname - (int)joinRoom
 * @desc 进入房间
 * @return  -1: 重复进入房间会包该错误 -2: 参数无效 -3: SDK 初始化失败，请尝试重新初始化 SDK -5：调用被拒绝。可能有如下两个原因：（1）已经创建了一个同名的Channel频道；（2）已经通过 Channel 加入了一个频道，并在该 Channel 频道中发布了音视频流
 */
- (int)joinRoom;

/**
 * @apidoc
 * @name joinRoomWithRealToken:channelId:info:uid:joinSuccess:
 * @fname - (int)joinRoomWithRealToken:(NSString* _Nullable)token channelId:(NSString* _Nonnull)channelId info:(NSString* _Nullable)info uid:(NSUInteger)uid joinSuccess:(void (^_Nullable)(NSString* _Nonnull channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock
 * @desc 进入房间
 * @param token NSString* 验证令牌
 * @param channelId NSString* 房间号
 * @param info NSString* 自定义附加信息，一般可设置为空字符串，或频道相关信息。该信息不会传递给频道内的其他用户
 * @param uid NSUInteger 用户ID
 * @param joinSuccessBlock block 成功加入频道回调，只有设置为nil， 才会触发 didJoinChannel 回调
 * @return  -1:重复进入房间会包该错误 -2:参数无效 -3:SDK 初始化失败，请尝试重新初始化 SDK -5:调用被拒绝。可能有如下两个原因：（1）已经创建了一个同名的Channel频道；（2）已经通过Channel加入了一个频道，并在该Channel频道中发布了音视频流
 */
- (int)joinRoomWithRealToken:(NSString* _Nullable)token channelId:(NSString* _Nonnull)channelId info:(NSString* _Nullable)info uid:(NSUInteger)uid joinSuccess:(void (^_Nullable)(NSString* _Nonnull channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock;

/**
 * @apidoc
 * @name switchChannelWithRealToken:channelId:joinSuccess:
 * @fname - (int)switchChannelWithRealToken:(NSString* _Nullable)token channelId:(NSString* _Nonnull)channelId joinSuccess:(void (^_Nullable)(NSString* _Nonnull channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock
 * @desc 切换房间
 * @param token NSString* 验证令牌
 * @param channelId NSString* 房间号
 * @param joinSuccess block 成功加入频道回调，只有设置为nil， 才会触发 didJoinChannel 回调
 * @return 0:成功
 */
- (int)switchChannelWithRealToken:(NSString* _Nullable)token channelId:(NSString* _Nonnull)channelId joinSuccess:(void (^_Nullable)(NSString* _Nonnull channel, NSUInteger uid, NSInteger elapsed))joinSuccessBlock;

/**
 * @apidoc
 * @name switchChannelWithRealToken:channelId:options:
 * @fname - (int)switchChannelWithRealToken:(NSString* _Nullable)token channelId:(NSString* _Nonnull)channelId options:(OmniRtcLiveChannelMediaOptions* _Nonnull)options
 * @desc 切换房间
 * @param token NSString* 验证令牌
 * @param channelId NSString* 房间号
 * @param options OmniRtcLiveChannelMediaOptions* 选项参数
 * @return 0:成功
 */
- (int)switchChannelWithRealToken:(NSString* _Nullable)token channelId:(NSString* _Nonnull)channelId options:(OmniRtcLiveChannelMediaOptions* _Nonnull)options;

/**
 * @apidoc
 * @name leaveRoom
 * @fname - (void)leaveRoom
 * @desc 离开房间
 * @return  空
 */
- (void)leaveRoom;

/**
 * @name switchRoomWithToken:
 * @fname - (int)switchRoomWithToken:(NSString*) token
 * @desc Switch room，已经废弃，不要再继续使用该接口
 * @param  token   NSString*  令牌
 * @return  空
 */
- (int)switchRoomWithToken:(NSString*) token DEPRECATED_ATTRIBUTE;

/**
 * @apidoc
 * @name enableLocalVideo:
 * @fname - (void)enableLocalVideo:(BOOL)enable
 * @desc 开关本地视频采集
 * @param enable BOOL  YES:开启本地视频采集和渲染（默认）；NO:关闭使用本地摄像头设备
 * @return  空
 */
- (void)enableLocalVideo:(BOOL)enable;

/**
 * @apidoc
 * @name enableLocalAudio:
 * @fname - (void)enableLocalAudio:(BOOL)enable
 * @desc 开关本地音频采集
 * @param enable BOOL YES:开启本地语音采集（默认）；NO:停止本地语音采集或处理
 * @return  空
 */
- (void)enableLocalAudio:(BOOL)enable;

/**
 * @apidoc
 * @name enableVideo
 * @fname - (int)enableVideo
 * @desc 开启视频模式，可以在加入频道前或者通话中调用，在加入频道前调用，则自动开启视频模式，在通话中调用则由音频模式切换为视频模式
 * @return 0:方法调用成功，<0:方法调用失败。
 */
- (int)enableVideo;

/**
 * @apidoc
 * @name disableVideo
 * @fname - (int)disableVideo
 * @desc 关闭视频，开启纯音频模式，可以在加入频道前或者通话中调用，在加入频道前调用，则自动开启纯音频模式，在通话中调用则由视频模式切换为纯音频频模式
 * @return 0:方法调用成功，<0:方法调用失败。
 */
- (int)disableVideo;

/**
 * @apidoc
 * @name enableAudio:
 * @fname - (int)enableAudio:(BOOL)enable
 * @desc 开关启用音频模块
 * @param enable YES:启用音频模块（默认）；NO:关闭音频模块
 * @return  0表示成功
 */
- (int)enableAudio:(BOOL)enable;

/**
 * @apidoc
 * @name resumeAudio:
 * @fname - (int)resumeAudio
 * @desc 恢复音频模块
 * @return  0表示成功
 */
- (int)resumeAudio DEPRECATED_MSG_ATTRIBUTE("Use enableAudio: instead.");

/**
 * @apidoc
 * @name muteLocalVideo:
 * @fname - (void)muteLocalVideo:(BOOL)isMute
 * @desc 取消或恢复发布本地视频流
 * @param isMute BOOL YES:取消发布；NO:发布
 * @return  空
 */
- (void)muteLocalVideo:(BOOL)isMute;

/**
 * @apidoc
 * @name muteLocalAudio:
 * @fname - (void)muteLocalAudio:(BOOL)isMute
 * @desc 取消或恢复发布本地音频流
 * @param isMute BOOL YES:取消发布；NO:发布
 * @return  空
 */
- (void)muteLocalAudio:(BOOL)isMute;

/**
 * @apidoc
 * @name setDefaultMuteAllRemoteVideoStreams:
 * @fname - (int)setDefaultMuteAllRemoteVideoStreams:(BOOL)isMute
 * @desc 默认取消或恢复订阅远端用户的视频流
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return  0表示成功
 */
- (int)setDefaultMuteAllRemoteVideoStreams:(BOOL)isMute;

/**
 * @apidoc
 * @name setDefaultMuteAllRemoteAudioStreams:
 * @fname - (int)setDefaultMuteAllRemoteAudioStreams:(BOOL)isMute
 * @desc 默认取消或恢复订阅远端用户的音频流
 * @param isMute BOOL YES:默认取消订阅；NO:（默认）默认订阅
 * @return  0表示成功
 */
- (int)setDefaultMuteAllRemoteAudioStreams:(BOOL)isMute;

/**
 * @apidoc
 * @name muteRemoteVideo:isMute:
 * @fname - (void)muteRemoteVideo:(NSUInteger)uid isMute:(BOOL)isMute
 * @desc 取消或恢复订阅指定远端用户的视频流
 * @param uid NSUInteger 远端用户ID
 * @param isMute BOOL YES:取消订阅；NO:（默认）订阅
 * @return  空
 */
- (void)muteRemoteVideo:(NSUInteger)uid isMute:(BOOL)isMute;

/**
 * @apidoc
 * @name muteRemoteAudio:isMute:
 * @fname - (void)muteRemoteAudio:(NSUInteger)uid isMute:(BOOL)isMute
 * @desc 取消或恢复订阅指定远端用户的音频流
 * @param uid NSUInteger 远端用户ID
 * @param isMute BOOL YES:取消订阅；NO:（默认）订阅
 * @return  空
 */
- (void)muteRemoteAudio:(NSUInteger)uid isMute:(BOOL)isMute;

- (void)muteRemoteVideo:(NSUInteger)uid enable:(BOOL)isMute DEPRECATED_MSG_ATTRIBUTE("Use muteRemoteVideo:isMute: instead.");
- (void)muteRemoteAuido:(NSUInteger)uid enable:(BOOL)isMute DEPRECATED_MSG_ATTRIBUTE("Use muteRemoteAudio:isMute: instead.");

/**
 * @apidoc
 * @name muteAllRemoteVideo:
 * @fname - (void)muteAllRemoteVideo:(BOOL)isMute
 * @desc 取消或恢复订阅所有远端用户的视频流
 * @param isMute BOOL YES:取消订阅；NO:（默认）订阅
 * @return  空
 */
- (void)muteAllRemoteVideo:(BOOL)isMute;

/**
 * @apidoc
 * @name muteAllRemoteAudio:
 * @fname - (void)muteAllRemoteAudio:(BOOL)isMute
 * @desc 取消或恢复订阅所有远端用户的音频流
 * @param isMute BOOL YES:取消订阅；NO:（默认）订阅
 * @return  空
 */
- (void)muteAllRemoteAudio:(BOOL)isMute;

- (void)muteAllRemoteAuido:(BOOL)isMute DEPRECATED_MSG_ATTRIBUTE("Use muteAllRemoteAudio: instead.");

/**
 * @apidoc
 * @name setupLocalVideo:
 * @fname - (void)setupLocalVideo:(OmniRtcLiveView*)view
 * @desc 设置本地视图
 * @param view OmniRtcLiveView 本地渲染视图
 * @return  空
 */
- (void)setupLocalVideo:(OmniRtcLiveView*)view;

/**
 * @apidoc
 * @name setLocalRenderMode:
 * @fname - (void)setLocalRenderMode:(RTCVideoRenderMode)mode
 * @desc 设置本地视图显示模式
 * @param mode RTCVideoRenderMode 视图显示模式
 * @return  空
 */
- (void)setLocalRenderMode:(RTCVideoRenderMode)mode;

/**
 * @apidoc
 * @name setupRemoteVideo:view:
 * @fname - (void)setupRemoteVideo:(NSUInteger)uid view:(OmniRtcLiveView*)view
 * @desc 设置远端用户视图
 * @param uid NSUInteger 远端用户ID
 * @param view OmniRtcLiveView* 渲染视图
 * @return  空
 */
- (void)setupRemoteVideo:(NSUInteger)uid view:(OmniRtcLiveView*)view;

/**
 * @apidoc
 * @name setupRemoteVideo:channelID:view:
 * @fname - (void)setupRemoteVideo:(NSUInteger)uid channelID:(NSString*)channelID view:(OmniRtcLiveView*)view
 * @desc 设置Channel的渲染视图，已废弃，请使用RTCChannel代替
 * @param uid NSUInteger 远端用户ID
 * @param channelID NSString* 频道名称
 * @param view OmniRtcLiveView* 渲染视图
 * @return  空
 */
- (void)setupRemoteVideo:(NSUInteger)uid channelID:(NSString*)channelID view:(OmniRtcLiveView*)view DEPRECATED_MSG_ATTRIBUTE("Use RTCChannel instead.");

/**
 * @apidoc
 * @name setRemoteRenderMode:mode:
 * @fname - (void)setRemoteRenderMode:(NSUInteger)uid mode:(RTCVideoRenderMode)mode
 * @desc 设置远端视图显示模式
 * @param uid NSUInteger 远端用户ID
 * @param mode RTCVideoRenderMode 视图显示模式
 * @return  空
 */
- (void)setRemoteRenderMode:(NSUInteger)uid mode:(RTCVideoRenderMode)mode;

/**
 * @apidoc
 * @name setRemoteRenderMode:renderMode:mirrorMode:
 * @fname - (int)setRemoteRenderMode:(NSUInteger)uid renderMode:(RTCVideoRenderMode)renderMode mirrorMode:(OmniRtcLiveVideoMirrorMode)mirrorMode
 * @desc 设置远端视图显示模式
 * @param uid NSUInteger 远端用户ID
 * @param mode RTCVideoRenderMode 视图显示模式
 * @param mirrorMode RTCVideoRenderMode 视图显示模式
 * @return  空
 */
- (int)setRemoteRenderMode:(NSUInteger)uid renderMode:(RTCVideoRenderMode)renderMode mirrorMode:(OmniRtcLiveVideoMirrorMode)mirrorMode;

/**
 * @apidoc
 * @name startPreview
 * @fname - (void)startPreview
 * @desc 开启本地视频预览
 * @return  空
 */
- (void)startPreview;

/**
 * @apidoc
 * @name stopPreview
 * @fname - (void)stopPreview
 * @desc 停止本地视频预览
 * @return  空
 */
- (void)stopPreview;

/**
 * @apidoc
 * @name setPreviewResolution:
 * @fname - (void)setPreviewResolution:(CGSize)previewResolution
 * @desc 设置预览分辨率
 * @param previewResolution CGSize 预览分辨率
 * @return  空
 */
- (void)setPreviewResolution:(CGSize)previewResolution;

/**
 * @apidoc
 * @name setVideoBitrate:
 * @fname - (void)setVideoBitrate:(RTC_ENGINE_VIDEO_BITRATE)videoBitrate
 * @desc 设置视频编码码率
 * @param videoBitrate RTC_ENGINE_VIDEO_BITRATE 视频码率
 * @return  空
 */
- (void)setVideoBitrate:(RTC_ENGINE_VIDEO_BITRATE)videoBitrate;

/**
 * @apidoc
 * @name setVideoResolution:
 * @fname - (void)setVideoResolution:(RTC_ENGINE_VIDEO_RESOLUTION)videoResolution
 * @desc 设置视频编码分辨率
 * @param videoResolution RTC_ENGINE_VIDEO_RESOLUTION 视频分辨率
 * @return  空
 */
- (void)setVideoResolution:(RTC_ENGINE_VIDEO_RESOLUTION)videoResolution;

- (void)setVideoEncoderConfiguration:(int)width height:(int)height fps:(int)fps bitrate:(int)bitrate oritention:(RTC_ORIENTATION_MODE)orientation DEPRECATED_MSG_ATTRIBUTE("Use setVideoEncoderConfiguration:height:fps:bitrate:orientation: instead.");

/**
 * @apidoc
 * @name setVideoEncoderConfiguration:height:fps:bitrate:orientation:
 * @fname - (void)setVideoEncoderConfiguration:(int)width height:(int)height fps:(int)fps bitrate:(int)bitrate orientation:(RTCOrientationMode)orientation
 * @desc 设置视频编码配置
 * @param width int 宽度
 * @param height int 高度
 * @param fps int 帧率
 * @param bitrate int 码率（kbps）
 * @param orientation RTCOrientationMode 输出方向
 * @return  空
 */
- (void)setVideoEncoderConfiguration:(int)width height:(int)height fps:(int)fps bitrate:(int)bitrate orientation:(RTCOrientationMode)orientation;

/**
 * @apidoc
 * @name switchCamera
 * @fname - (void)switchCamera
 * @desc 切换前置/后置摄像头
 * @return  空
 */
- (void)switchCamera;

/**
 * @apidoc
 * @name getCameraPosition
 * @fname - (OmniRtcLiveCameraPosition)getCameraPosition
 * @desc 获取采集摄像头位置
 * @return  cameraPosition 前后置摄像头
 */
- (OmniRtcLiveCameraPosition)getCameraPosition;

/**
 * @apidoc
 * @name setCameraPosition:
 * @fname - (BOOL)setCameraPosition:(OmniRtcLiveCameraPosition)cameraPosition
 * @desc 设置采集摄像头位置
 * @param cameraPosition OmniRtcLiveCameraPosition 前后置摄像头
 * @return YES表示成功，NO表示失败
 */
- (BOOL)setCameraPosition:(OmniRtcLiveCameraPosition)cameraPosition;

/**
 * @apidoc
 * @name setMirror:
 * @fname - (void)setMirror:(BOOL)isMirror
 * @desc 设置本地镜像
 * @param isMirror BOOL 前后置摄像头
 * @return 空
 */
- (void)setMirror:(BOOL)isMirror;

/**
 * @apidoc
 * @name setRemoteMirror:mirror:
 * @fname - (void)setRemoteMirror:(NSUInteger)uid mirror:(BOOL)isMirror
 * @desc 设置远端镜像
 * @param uid NSUInteger 远端用户ID
 * @param isMirror BOOL 前后置摄像头
 * @return 空
 */
- (void)setRemoteMirror:(NSUInteger)uid mirror:(BOOL)isMirror;

/**
 * @apidoc
 * @name setMirrorMode:
 * @fname - (void)setMirrorMode:(OmniRtcLiveMirrorMode)mode
 * @desc 设置预览的镜像模式
 * @param mode OmniRtcLiveMirrorMode 预览的镜像模式
 * @return 空
 */
- (void)setMirrorMode:(OmniRtcLiveMirrorMode)mode;

/**
 * @apidoc
 * @name setEnableSpeakerphone:
 * @fname - (int)setEnableSpeakerphone:(BOOL)enableSpeaker
 * @desc 启用/关闭扬声器播放
 * @param enableSpeaker BOOL YES:切换到外放；NO:切换到听筒
 * @return 0表示成功
 */
- (int)setEnableSpeakerphone:(BOOL)enableSpeaker;

/**
 * @apidoc
 * @name isSpeakerphoneEnabled:
 * @fname - (BOOL)isSpeakerphoneEnabled
 * @desc 查询扬声器启用状态
 * @return YES表示扬声器已开启，NO表示未开启
 */
- (BOOL)isSpeakerphoneEnabled;

/**
 * @apidoc
 * @name enableLastmileProbeTest:
 * @fname - (void)enableLastmileProbeTest
 * @desc 启动网络连接质量测试，直播场景下，主播在加入频道后请勿调用该方法
 * @return 空
 */
- (void)enableLastmileProbeTest;
        
/**
 * @apidoc
 * @name disableLastmileProbeTest:
 * @fname - (void)disableLastmileProbeTest
 * @desc 关闭网络测试
 * @return 空
 */
- (void)disableLastmileProbeTest;

/**
 * @apidoc
 * @name enableExternalVideo:useTexture:
 * @fname - (void)enableExternalVideo:(BOOL)enable useTexture:(BOOL)useTexture
 * @desc 开启外部视频推流，需要在进房间之前调用
 * @param enable BOOL YES:开启；NO:关闭
 * @param useTexture BOOL YES:使用纹理数据；NO:不使用纹理数据
 * @return 空
 */
- (void)enableExternalVideo:(BOOL)enable useTexture:(BOOL)useTexture;

/**
 * @apidoc
 * @name pushExternalVideoFrame:
 * @fname - (void)pushExternalVideoFrame:(CMSampleBufferRef)sampleBuffer
 * @desc 推送外部视频帧
 * @param sampleBuffer CMSampleBufferRef 纹理数据
 * @return 空
 */
- (void)pushExternalVideoFrame:(CMSampleBufferRef)sampleBuffer;

/**
 * @apidoc
 * @name pushExternalVideoFrameWithData:size:format:
 * @fname - (void)pushExternalVideoFrameWithData:(NSData*)data size:(CGSize)size format:(int)format
 * @desc 推送外部视频数据
 * @param data NSData* 视频数据
 * @param size CGSize 数据尺寸
 * @param format int 数据格式，1: I420; 2: BGRA; 3: NV21; 4: RGBA; 7: ARGB; 8: NV12（NV12只支持texture）
 * @return 空
 */
- (void)pushExternalVideoFrameWithData:(NSData*)data size:(CGSize)size format:(int)format;

/** If you use an external audio source,"enableExternalAudio" switch to open or close.
 together with ”pushExternalAudioFrameRawData“ or pushExternalAudioFrameSampleBuffer
 @param enable switch to use external audio or not  enable:TRUE mean open ;FALSE mean closed
 @param sampleRate  audio parameter to init
 @param channelsPerFrame audio parameter  to init;
 */

/**
 * @apidoc
 * @name enableExternalAudio:SampleRate:channelsPerFrame:
 * @fname - (void)enableExternalAudio:(BOOL)enable SampleRate:(NSUInteger)sampleRate channelsPerFrame:(NSUInteger)channelsPerFrame
 * @desc 开启外部音频推流
 * @param enable BOOL YES:开启；NO:关闭
 * @param sampleRate NSUInteger 采样率
 * @param channelsPerFrame NSUInteger 声道数
 * @return 空
 */
- (void)enableExternalAudio:(BOOL)enable SampleRate:(NSUInteger)sampleRate channelsPerFrame:(NSUInteger)channelsPerFrame;

/**
 * @apidoc
 * @name pushExternalAudioFrameRawData:samples:timestamp:
 * @fname - (void)pushExternalAudioFrameRawData:(void *_Nonnull)data samples:(NSUInteger)samples timestamp:(NSTimeInterval)timestamp
 * @desc 推送外部音频裸数据
 * @param data void* 音频数据
 * @param samples NSUInteger 采样数
 * @param timestamp NSTimeInterval 时间戳
 * @return 空
 */
- (void)pushExternalAudioFrameRawData:(void *_Nonnull)data samples:(NSUInteger)samples timestamp:(NSTimeInterval)timestamp;

/**
 * @apidoc
 * @name pushExternalAudioFrameSampleBuffer:
 * @fname - (void)pushExternalAudioFrameSampleBuffer:(CMSampleBufferRef _Nonnull)sampleBuffer
 * @desc 推送外部音频裸数据
 * @param sampleBuffer CMSampleBufferRef 音频数据
 * @return 空
 */
- (void)pushExternalAudioFrameSampleBuffer:(CMSampleBufferRef _Nonnull)sampleBuffer;

/**
 * @apidoc
 * @name setAudioBitrate:
 * @fname - (int)setAudioBitrate:(int)bitrate
 * @desc 设置音频编码码率
 * @param bitrate int 码率
 * @return 0表示成功
 */
- (int)setAudioBitrate:(int)bitrate;

/**
 * @apidoc
 * @name setRecordingAudioParameters:channel:
 * @fname - (int)setRecordingAudioParameters:(NSUInteger)sample channel:(NSUInteger)nchannel
 * @desc 设置音频采集参数
 * @param sample NSUInteger 采样率
 * @param nchannel NSUInteger 通道数
 * @return 0表示成功
 */
- (int)setRecordingAudioParameters:(NSUInteger)sample channel:(NSUInteger)nchannel;

/**
 * @apidoc
 * @name setRecordingAudioParameters:channel:mode:samplesPerCall:
 * @fname - (int)setRecordingAudioParameters:(NSUInteger)sampleRate channel:(NSUInteger)channel mode:(OmniRtcLiveAudioRawFrameOperationMode)mode samplesPerCall:(NSInteger)samplesPerCall
 * @desc 设置音频采集参数
 * @param sampleRate NSUInteger 采样率
 * @param channel NSUInteger 通道数
 * @param mode OmniRtcLiveAudioRawFrameOperationMode 读写模式
 * @param samplesPerCall NSInteger 每次回调的采样数
 * @return 0表示成功
 */
- (int)setRecordingAudioParameters:(NSUInteger)sampleRate channel:(NSUInteger)channel mode:(OmniRtcLiveAudioRawFrameOperationMode)mode samplesPerCall:(NSInteger)samplesPerCall;

/// 该接口逐渐废弃，请使用 setPlaybackAudioParameters:channel:mode:代替
- (int)setPlaybackAudioParameters:(NSUInteger)sample channel:(NSUInteger)nchannel DEPRECATED_MSG_ATTRIBUTE("Use setPlaybackAudioParameters:channel:mode: instead.");

/**
 * @apidoc
 * @name setPlaybackAudioParameters:channel:mode:samplesPerCall:
 * @fname - (int)setPlaybackAudioParameters:(NSUInteger)sample channel:(NSUInteger)nchannel mode:(OmniRtcLiveAudioRawFrameOperationMode)mode samplesPerCall:(NSInteger)samples
 * @desc 设置音频播放参数
 * @param sample NSUInteger 采样率
 * @param nchannel NSUInteger 通道数
 * @param mode OmniRtcLiveAudioRawFrameOperationMode 读写模式
 * @param samplesPerCall NSInteger 每次回调的采样数
 * @return 0表示成功
 */
- (int)setPlaybackAudioParameters:(NSUInteger)sample channel:(NSUInteger)nchannel mode:(OmniRtcLiveAudioRawFrameOperationMode)mode samplesPerCall:(NSInteger)samples;

/**
 * @apidoc
 * @name adjustPlaybackSignalVolume:
 * @fname - (int)adjustPlaybackSignalVolume:(NSInteger)volume
 * @desc 调节播放音量，volume 范围是[0,400]，注意不能跟 setVolume 混用
 * @param volume NSUInteger 音量值，范围是[0,400]
 * @return 0表示成功
 */
- (int)adjustPlaybackSignalVolume:(NSInteger)volume;

/**
 * @apidoc
 * @name setVolume:volume:
 * @fname - (int)setVolume:(NSString* _Nonnull)userId volume:(NSUInteger)volume
 * @desc 设置指定用户播放音量，注意不能跟 setVolume 混用
 * @param userId NSString* 用户ID
 * @param volume NSUInteger 音量值，范围是[0,400]
 * @return 0表示成功
 */
- (int)setVolume:(NSString* _Nonnull)userId volume:(NSUInteger)volume;

/**
 * @apidoc
 * @name setVolume:volume:channelID:
 * @fname - (int)setVolume:(NSString* _Nonnull)userId volume:(NSUInteger)volume channelID:(NSString* _Nonnull)channelID
 * @desc 设置 Channel 音量，已废弃，请使用RTCChannel代替
 * @param userId NSString* 用户ID
 * @param volume NSUInteger 音量值，范围是[0,400]
 * @param channelID NSString* 频道名称
 * @return 0表示成功
 */
- (int)setVolume:(NSString* _Nonnull)userId volume:(NSUInteger)volume channelID:(NSString* _Nonnull)channelID DEPRECATED_MSG_ATTRIBUTE("Use RTCChannel instead.");

/**
 * @apidoc
 * @name setAllRemoteVolume:
 * @fname - (int)setAllRemoteVolume:(NSUInteger)volume
 * @desc 设置远端所有用户的播放音量
 * @param volume NSUInteger 音量值，范围是[0,400]
 * @return 0表示成功
 */
- (int)setAllRemoteVolume:(NSUInteger)volume;

/**
 * @apidoc
 * @name setLogFileWithPath:logLevel:
 * @fname - (int)setLogFileWithPath:(NSString* _Nonnull)logFilePath logLevel:(RTCEngineLogLevelType)logLevel
 * @desc 设置日志的文件路径和等级
 * @param logFilePath NSString* 日志文件路径
 * @param logLevel RTCEngineLogLevelType 日志等级
 * @return 0表示成功
 */
- (int)setLogFileWithPath:(NSString* _Nonnull)logFilePath logLevel:(RTCEngineLogLevelType)logLevel;

/**
 * @apidoc
 * @name setLimitLogFileSize:
 * @fname - (int)setLimitLogFileSize:(NSUInteger)fileSizeInKBytes
 * @desc 设置日志大小
 * @param fileSizeInKBytes NSUInteger 日志大小，单位KB
 * @return 0表示成功
 */
- (int)setLimitLogFileSize:(NSUInteger)fileSizeInKBytes;

/**
 * @name openFluentMode:
 * @fname - (void)openFluentMode:(BOOL)mode
 * @desc 是否开启流程模式
 * @param mode BOOL YES表示开启；NO表示不开启
 * @return 空
 */
- (void)openFluentMode:(BOOL)mode;

/**
 * @apidoc
 * @name setTimeStamp:
 * @fname - (int)setTimeStamp:(long long)timeStamp
 * @desc 设置时间戳，返回 -2 表示创建发送SEI的数据通道失败
 * @param timeStamp long YES表示开启；NO表示不开启
 * @return 0表示成功
 */
- (int)setTimeStamp:(long long)timeStamp;

/**
 * @apidoc
 * @name getTimeStampWithUid:
 * @fname - (long long)getTimeStampWithUid:(NSInteger)uid
 * @desc 获取时间戳
 * @param uid lNSInteger 远端用户ID
 * @return 时间戳
 */
- (long long)getTimeStampWithUid:(NSInteger)uid;

/**
 * @apidoc
 * @name sendStreamMessage:timeStamp:
 * @fname - (int)sendStreamMessage:(NSData*)data timeStamp:(long long)timeStamp
 * @desc 发送自定义消息
 * @param data NSData* 自定义消息数据
 * @param timeStamp long 时间戳
 * @return 0表示成功
 */
- (int)sendStreamMessage:(NSData*)data timeStamp:(long long)timeStamp;

/**
 * @apidoc
 * @name addPublishStreamUrl:transCoding:
 * @fname - (int)addPublishStreamUrl:(NSString* _Nullable)streamUrl transCoding:(BOOL)transCode
 * @desc 添加 rtmp 推流地址
 * @param streamUrl NSString*  推流地址
 * @param transCode BOOL 是否启用转码，YES表示转码，NO表示不转吗
 * @return 0表示成功
 */
- (int)addPublishStreamUrl:(NSString* _Nullable)streamUrl transCoding:(BOOL)transCode;

/**
 * @apidoc
 * @name removePublishStreamUrl:
 * @fname - (int)removePublishStreamUrl:(NSString* _Nullable)streamUrl
 * @desc 删除 rtmp 推流地址，不要 removePublishStreamUrl 以后马上调用 addPublishStreamUrl，一定要等停止推流成功后再重新推流
 * @param streamUrl NSString*  推流地址
 * @return 0表示成功
 */
- (int)removePublishStreamUrl:(NSString* _Nullable)streamUrl;

/**
 * @apidoc
 * @name setRtmpConfig:
 * @fname - (int)setRtmpConfig:(RTCRtmpConfig* _Nullable)rtmpConfig
 * @desc 设置rtmp流的配置信息
 * @param rtmpConfig RTCRtmpConfig*  推流配置
 * @return 0表示成功
 */
- (int)setRtmpConfig:(RTCRtmpConfig* _Nullable)rtmpConfig;

/**
 * @apidoc
 * @name startPlayMusic:loopback:replace:cycle:
 * @fname - (int)startPlayMusic:(NSString* _Nullable)filePath loopback:(BOOL)loopback replace:(BOOL)replace cycle:(NSInteger)cycle
 * @desc 音乐文件播放及混音设置，支持以下音频格式: mp3，aac，m4a，3gp，wav。通过 rtcEngine:playMusicStateChanged:errorCode: 返回播放状态，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @param filePath NSString* 播放文件的路径
 * @param loopback BOOL YES:只有本地可以听到混音或替换后的音频流；NO:本地和对方都可以听到混音或替换后的音频流
 * @param replace BOOL YES:只推送设置的本地音频文件或者线上音频文件，不传输麦克风收录的音频；NO:音频文件内容将会和麦克风采集的音频流进行混音
 * @param cycle NSInteger 正整数: 循环的次数；-1：无限循环
 * @return 0表示成功
 */
- (int)startPlayMusic:(NSString* _Nullable)filePath loopback:(BOOL)loopback replace:(BOOL)replace cycle:(NSInteger)cycle;

/**
 * @apidoc
 * @name stopPlayMusic
 * @fname - (int)stopPlayMusic
 * @desc 停止播放音乐文件，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @return 0表示成功
 */
- (int)stopPlayMusic;

/**
 * @apidoc
 * @name pauseAudioMusic
 * @fname - (int)pauseAudioMusic
 * @desc 暂停播放，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @return 0表示成功
 */
- (int)pauseAudioMusic;

/**
 * @apidoc
 * @name resumeAudioMusic
 * @fname - (int)resumeAudioMusic
 * @desc 恢复播放，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @return 0表示成功
 */
- (int)resumeAudioMusic;

/**
 * @apidoc
 * @name getAudioMusicDuration
 * @fname - (int)getAudioMusicDuration
 * @desc 获取总时长，单位ms，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @return 0表示成功
 */
- (int)getAudioMusicDuration;

/**
 * @apidoc
 * @name getAudioMusicCurrentPosition
 * @fname - (int)getAudioMusicCurrentPosition
 * @desc 获取播放位置，单位ms，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @return 0表示成功
 */
- (int)getAudioMusicCurrentPosition;

/**
 * @apidoc
 * @name setAudioMusicPosition:
 * @fname - (int)setAudioMusicPosition:(NSInteger)pos
 * @desc 设置播放位置，单位ms，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @param pos NSInteger 播放位置
 * @return 0表示成功
 */
- (int)setAudioMusicPosition:(NSInteger)pos;

/**
 * @apidoc
 * @name adjustPlayMusicVolume:
 * @fname - (int)adjustPlayMusicVolume:(NSInteger)volume
 * @desc 调整播放音乐的音量，音乐文件播放音量范围为 0~100，默认 100 为原始文件音量，不要在主线程调用，不能多线程调用，播放网络音频会存在卡住线程问题，建议不要播放网络音频，网络音频是系统API实现，控制权限少
 * @param volume NSInteger 播放音量[0,100]
 * @return 0表示成功
 */
- (int)adjustPlayMusicVolume:(NSInteger)volume;

/**
 * @apidoc
 * @name obtainSDKVersion:
 * @fname - (NSString* _Nonnull)obtainSDKVersion
 * @desc 获取SDK版本号
 * @return SDK版本号
 */
- (NSString* _Nonnull)obtainSDKVersion;

/**
 * @name enableContentInspect:
 * @fname - (int)enableContentInspect:(BOOL)enable
 * @desc 鉴黄接口，已废弃，请使用enableContentInspect:interval:方法代替
 * @param enable BOOL 是否开启截图上传，YES表示开启，NO表示不开启
 * @return 0表示成功
 */
- (int)enableContentInspect:(BOOL)enable DEPRECATED_MSG_ATTRIBUTE("Use enableContentInspect:interval: instead.");

/**
 * @apidoc
 * @name enableContentInspect:interval:
 * @fname - (int)enableContentInspect:(BOOL)enable interval:(NSInteger)interval
 * @desc 鉴黄接口，最小时间间隔为5秒
 * @param enable BOOL 是否开启截图上传，YES表示开启，NO表示不开启
 * @param interval NSInteger 截图间隔
 * @return 0表示成功
 */
- (int)enableContentInspect:(BOOL)enable interval:(NSInteger)interval;

/**
 * @apidoc
 * @name contentInspectExtra:inspectMode:
 * @fname - (int)contentInspectExtra:(NSString*)arguments inspectMode:(NSArray<RTCInspectModeConfig*>*)modes
 * @desc 鉴黄参数，开启的功能必须同时设置，比如截图鉴黄功能和AI监课功能要一起设置，不能单次设置
 * @param arguments NSString* 自定义参数
 * @param modes NSArray<RTCInspectModeConfig*>* 截图上传配置
 * @return 0表示成功
 */
- (int)contentInspectExtra:(NSString*)arguments inspectMode:(NSArray<RTCInspectModeConfig*>*)modes;

/**
 * @name setAVSyncSource:uid:
 * @fname - (int)setAVSyncSource:(long long)channelId uid:(NSUInteger)uid
 * @desc 不同设备同步
 * @param channelId long 频道名称
 * @param uid NSUInteger 用户ID
 * @return 0表示成功
 */
- (int)setAVSyncSource:(long long)channelId uid:(NSUInteger)uid;

/**
 * @apidoc
 * @name setRemoteVideoStream:type:
 * @fname - (int)setRemoteVideoStream:(NSUInteger)uid type:(RTCVideoStreamType)streamType
 * @desc 切换大小流，设置大小流可能会导致接收到的码率、帧率、分辨率都会变化
 * @param uid NSUInteger 远端用户ID
 * @param streamType RTCVideoStreamTyp 流类型
 * @return 0表示成功
 */
- (int)setRemoteVideoStream:(NSUInteger)uid type:(RTCVideoStreamType)streamType;

/**
 * @apidoc
 * @name switchAudioMode:
 * @fname - (int)switchAudioMode:(RTCAudioMode)mode
 * @desc 切换媒体音量和通话音量（根据是否在投屏决定是否启用）
 * @param mode RTCAudioMode 通话模式
 * @return 0表示成功
 */
- (int)switchAudioMode:(RTCAudioMode)mode;

/**
 * @apidoc
 * @name updateOutputPixelFormat:
 * @fname - (int)updateOutputPixelFormat:(RTCOutputPixelFormat)pixelFormat
 * @desc 设置回调的裸数据格式，需要在进房间之前设置，返回-1表示设置失败，使用默认值 RTCOutputPixelFormatI420
 * @param pixelFormat RTCOutputPixelFormat 输出裸数据格式
 * @return 0表示成功
 */
- (int)updateOutputPixelFormat:(RTCOutputPixelFormat)pixelFormat;

/**
 * @name debugEnableRecordAudio:
 * @fname - (int)debugEnableRecordAudio:(NSString *_Nonnull)mode
 * @desc 启动录制音频（用于调试），参数 mode：“all”，表示启动，并录制全部类别；"none”，表示全部停止。请注意合理控制录制音频的时间
 * @param mode NSString* 模式，参数 mode：“all”，表示启动，并录制全部类别；"none”
 * @return 0表示成功
 */
- (int)debugEnableRecordAudio:(NSString *_Nonnull)mode;

/**
 * @apidoc
 * @name adjustRecordingSignalVolume:
 * @fname - (int)adjustRecordingSignalVolume:(NSInteger)volume
 * @desc 调节麦克风采集信号音量，需要在进房间之前设置，返回-1表示设置失败，使用默认值 RTCOutputPixelFormatI420
 * @param volume NSInteger 麦克风采集信号音量。取值范围为 [0,100]。默认值为 100，表示原始音量。
 * @return 0表示成功
 */
- (int)adjustRecordingSignalVolume:(NSInteger)volume;

/**
 * @apidoc
 * @name enable3Amodule:
 * @fname - (int)enable3Amodule:(BOOL)enable
 * @desc 是否开启3A模块
 * @param enable BOOL 是否开启3A，YES表示开启，NO表示不开启
 * @return 0表示成功
 */
- (int)enable3Amodule:(BOOL)enable;

/**
 * @apidoc
 * @name startChannelMediaRelay:
 * @fname - (int)startChannelMediaRelay:(RTCChannelMediaRelayConfiguration *_Nonnull)config
 * @desc 跨频道转发，跨频道媒体流转发最多支持 4 个目标频道，请在成功加入频道后调用该方法，成功调用该方法后，若你想再次调用该方法，必须先调用 stopChannelMediaRelay 方法退出当前的转发状态，成功调用该方法后，SDK 会触发 channelMediaRelayStateDidChange 和 didReceiveChannelMediaRelayEvent 回调，并在回调中报告当前的跨频道媒体流转发状态和事件。如果 channelMediaRelayStateDidChange 回调报告 RTCChannelMediaRelayStateRunning(2) 和 RTCChannelMediaRelayStateIdle(0)，且 didReceiveChannelMediaRelayEvent 回调报告 RTCChannelMediaRelayEventSentToDestinationChannel(4)，则表示 SDK 开始在源频道和目标频道之间转发媒体流。如果 channelMediaRelayStateDidChange 回调报告 RTCChannelMediaRelayStateFailure(3)，则表示跨频道媒体流转发出现异常。
 * @param config RTCChannelMediaRelayConfiguration* 转推配置
 * @return 0表示成功
 */
- (int)startChannelMediaRelay:(RTCChannelMediaRelayConfiguration *_Nonnull)config;

/**
 * @apidoc
 * @name updateChannelMediaRelay:
 * @fname - (int)updateChannelMediaRelay:(RTCChannelMediaRelayConfiguration * _Nonnull)config
 * @desc 更新媒体流转发的频道，跨频道媒体流转发最多支持 4 个目标频道，请在 startChannelMediaRelay 方法后调用该方法，更新媒体流转发的频道，成功调用该方法后，SDK 会触发 didReceiveChannelMediaRelayEvent 回调，并在回调中报告状态码 RTCChannelMediaRelayEventUpdateDestinationChannel(7)
 * @param config RTCChannelMediaRelayConfiguration* 转推配置
 * @return 0表示成功
 */
- (int)updateChannelMediaRelay:(RTCChannelMediaRelayConfiguration * _Nonnull)config;

/**
 * @apidoc
 * @name stopChannelMediaRelay
 * @fname - (int)stopChannelMediaRelay
 * @desc 停止跨频道媒体流转发，成功调用该方法后，SDK 会触发 channelMediaRelayStateDidChange 回调。如果报告 RTCChannelMediaRelayStateIdle(0) 和 RTCChannelMediaRelayErrorNone(0)，则表示已停止转发媒体流。如果该方法调用不成功，SDK 会触发 channelMediaRelayStateDidChange 回调，并报告状态码 RTCChannelMediaRelayErrorServerNoResponse(2) 或 RTCChannelMediaRelayEventUpdateDestinationChannelRefused(8)。你可以调用 leaveChannel 方法离开频道，跨频道媒体流转发会自动停止。
 * @return 0表示成功
 */
- (int)stopChannelMediaRelay;

/**
 * @apidoc
 * @name setRemoteUserPriority:type:
 * @fname - (int)setRemoteUserPriority:(NSUInteger)uid type:(RTCUserPriority)priority
 * @desc 设置远端用户流的优先级
 * @param uid NSUInteger 远端用户的ID
 * @param type RTCUserPriority 远端用户的优先级
 * @return 0表示成功
 */
- (int)setRemoteUserPriority:(NSUInteger)uid type:(RTCUserPriority)priority;

/**
 * @name openAutoDegrade:
 * @fname - (void)openAutoDegrade:(BOOL)flag
 * @desc 只有销毁引擎，该设置才会失效，该接口已经废弃
 * @param flag BOOL 是否开启自动降级
 * @return 0表示成功
 */
- (void)openAutoDegrade:(BOOL)flag;

/**
 * @apidoc
 * @name setExternalAudioSourceVolume:volume:
 * @fname - (void)setExternalAudioSourceVolume:(OmniRtcLiveAudioExternalSourceId)sourceId volume:(NSUInteger)volume
 * @desc 设置外部音频的音量
 * @param sourceId OmniRtcLiveAudioExternalSourceId 音频合入方式
 * @param volume NSUInteger 音量值
 * @return 0表示成功
 */
- (void)setExternalAudioSourceVolume:(OmniRtcLiveAudioExternalSourceId)sourceId volume:(NSUInteger)volume;

/**
 * @apidoc
 * @name pushExternalAudioFrameRawData:sourceId:
 * @fname - (BOOL)pushExternalAudioFrameRawData:(OmniRtcLiveAudioFrame* _Nonnull)frame sourceId:(OmniRtcLiveAudioExternalSourceId)sourceId
 * @desc 推送外部音频合入
 * @param frame OmniRtcLiveAudioFrame* 音频数据
 * @param sourceId OmniRtcLiveAudioExternalSourceId 音频合入方式
 * @return YES表示成功
 */
- (BOOL)pushExternalAudioFrameRawData:(OmniRtcLiveAudioFrame* _Nonnull)frame sourceId:(OmniRtcLiveAudioExternalSourceId)sourceId;

/**
 * @apidoc
 * @name pushExternalAudioFrameSampleBuffer:sourceId:
 * @fname - (BOOL)pushExternalAudioFrameSampleBuffer:(CMSampleBufferRef)sampleBuffer sourceId:(OmniRtcLiveAudioExternalSourceId)sourceId
 * @desc 推送外部音频合入
 * @param sampleBuffer CMSampleBufferRef 音频数据
 * @param sourceId OmniRtcLiveAudioExternalSourceId 音频合入方式
 * @return YES表示成功
 */
- (BOOL)pushExternalAudioFrameSampleBuffer:(CMSampleBufferRef)sampleBuffer sourceId:(OmniRtcLiveAudioExternalSourceId)sourceId;

/**
 * @apidoc
 * @name setBusinessUserRole:sourceId:
 * @fname - (int)setBusinessUserRole:(OmniRtcLiveBusinessUserRole)role
 * @desc 设置业务类型
 * @param role OmniRtcLiveBusinessUserRole 业务类型
 * @return YES表示成功
 */
- (int)setBusinessUserRole:(OmniRtcLiveBusinessUserRole)role;

/**
 * @apidoc
 * @name setRemoteSubscribeFallbackOption:
 * @fname - (int)setRemoteSubscribeFallbackOption:(OmniRtcLiveStreamFallbackOptions)option
 * @desc 设置自动切换大小流选项
 * @param option OmniRtcLiveStreamFallbackOptions 切换方式，https://wiki.zhiyinlou.com/pages/viewpage.action?pageId=155224972
 * @return 0表示成功
 */
- (int)setRemoteSubscribeFallbackOption:(OmniRtcLiveStreamFallbackOptions)option;

/**
 * @apidoc
 * @name applyRemoteStreamSubscribeAdvice:type:
 * @fname - (int)applyRemoteStreamSubscribeAdvice:(NSUInteger)userID type:(OmniRtcLiveSubscriptionStreamType)type
 * @desc 手动切换大小流
 * @param userID NSUInteger 目标用户ID
 * @param type OmniRtcLiveSubscriptionStreamType 目标流类型
 * @return 0表示成功
 */
- (int)applyRemoteStreamSubscribeAdvice:(NSUInteger)userID type:(OmniRtcLiveSubscriptionStreamType)type;

/**
 * @apidoc
 * @name takeLocalViewSnapshot
 * @fname - (BOOL)takeLocalViewSnapshot
 * @desc 截取本地预览视频图像
 * @return YES表示成功
 */
- (BOOL)takeLocalViewSnapshot;

/**
 * @apidoc
 * @name takeRemoteViewSnapshot:
 * @fname - (BOOL)takeRemoteViewSnapshot:(NSUInteger)uid
 * @desc 截取远端用户视频图像
 * @param uid NSUInteger 用户ID
 * @return YES表示成功
 */
- (BOOL)takeRemoteViewSnapshot:(NSUInteger)uid;

/**
 * @apidoc
 * @name setAudioEncoderConfiguration:processMode:
 * @fname - (int)setAudioEncoderConfiguration:(NSInteger)bitrate processMode:(RTCAudioProcessMode)mode
 * @desc 设置音频码率和处理模式
 * @param bitrate NSInteger 码率，单位kbps
 * @param mode RTCAudioProcessMode 音频处理模式
 * @return 0表示成功
 */
- (int)setAudioEncoderConfiguration:(NSInteger)bitrate processMode:(RTCAudioProcessMode)mode;

/**
 * @apidoc
 * @name getErrorDescription:
 * @fname - (NSString*_Nullable)getErrorDescription:(NSInteger)code
 * @desc 根据错误码获取对应的错误描述
 * @param code NSInteger 错误码
 * @return 0表示成功
 */
- (NSString*_Nullable)getErrorDescription:(NSInteger)code;

/**
 * @apidoc
 * @name getConnectionState
 * @fname - (OmniRtcLiveConnectionStateType)getConnectionState
 * @desc 获取链接状态
 * @return 链接状态
 */
- (OmniRtcLiveConnectionStateType)getConnectionState;

/**
 * @apidoc
 * @name setAudioProfile:scenario:
 * @fname - (int)setAudioProfile:(OmniRtcLiveAudioProfile)profile scenario:(OmniRtcLiveAudioScenario)scenario
 * @desc 设置音频配置
 * @param profile OmniRtcLiveAudioProfile 音频配置
 * @param scenario OmniRtcLiveAudioScenario 音频场景
 * @return 链接状态
 */
- (int)setAudioProfile:(OmniRtcLiveAudioProfile)profile scenario:(OmniRtcLiveAudioScenario)scenario;

@end



@protocol RTCEngineDelegate <NSObject>

#ifdef DEBUG
- (void)takePreEncodeSnapshot;
#endif

@optional

/**
 * @apidoc
 * @name rtcEngine:didOccurError:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine didOccurError:(RTCEngineErrorCode)code
 * @desc 发生错误回调
 * @param engine RTCEngine* 引擎对象
 * @param code  RTCEngineErrorCode 错误值
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine didOccurError:(RTCEngineErrorCode)code;

/**
 * @apidoc
 * @name rtcEngine:didCreateEngineErrorWithType:reason:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine didCreateEngineErrorWithType:(NSInteger)type reason:(NSString*_Nonnull)reason
 * @desc 创建引擎失败回调
 * @param engine RTCEngine* 引擎对象
 * @param type NSInteger 引擎类型
 * @param reason NSString* 失败原因
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine didCreateEngineErrorWithType:(NSInteger)type reason:(NSString*_Nonnull)reason;

/**
 * @apidoc
 * @name rtcEngine:localUserJoindWithUid:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine localUserJoindWithUid:(NSUInteger)uid
 * @desc 本地用户进入房间回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine localUserJoindWithUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:localUserDidLeavedWithUid:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine localUserDidLeavedWithUid:(NSUInteger)uid
 * @desc 本地用户离开房间回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine localUserDidLeavedWithUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:localUserReJoindWithUid:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine localUserReJoindWithUid:(NSUInteger)uid
 * @desc 本地用户重新进入房间回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine localUserReJoindWithUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:localVideoStateChange:error:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine localVideoStateChange:(RTCLocalVideoStreamState)state error:(RTCLocalVideoStreamError)error
 * @desc 本地视频状态发生改变
 * @param engine RTCEngine* 引擎对象
 * @param state RTCLocalVideoStreamState 视频状态
 * @param error RTCLocalVideoStreamError 错误值
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine localVideoStateChange:(RTCLocalVideoStreamState)state error:(RTCLocalVideoStreamError)error;

/**
 * @apidoc
 * @name rtcEngine:remoteUserJoinWithUid:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine remoteUserJoinWithUid:(NSUInteger)uid
 * @desc 远端用户进入房间回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 远端用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine remoteUserJoinWithUid:(NSUInteger)uid;
- (void)rtcEngine:(RTCEngine*_Nonnull)engine remoteUserJoinWitnUid:(NSUInteger)uid DEPRECATED_MSG_ATTRIBUTE("Use rtcEngine:remoteUserJoinWithUid: instead.");

/**
 * @apidoc
 * @name rtcEngine:remotefirstAudioRecvWithUid:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull )engine remotefirstAudioRecvWithUid:(NSUInteger)uid
 * @desc 已接收远端音频首帧的回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 远端用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull )engine remotefirstAudioRecvWithUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:remotefirstVideoRecvWithUid:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull )engine remotefirstVideoRecvWithUid:(NSUInteger)uid
 * @desc 已完成远端视频首帧解码回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 远端用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull )engine remotefirstVideoRecvWithUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:remotefirstVideoFrameOfUid:size:elapsed:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull )engine remotefirstVideoFrameOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed
 * @desc 已显示远端视频首帧回调
 * @param engine RTCEngine* 引擎对象
 * @param uid  NSUInteger 远端用户ID
 * @param size CGSize 视频尺寸（宽和高）
 * @param elapsed NSInteger 从本地用户调用joinChannelByToken到发生此事件消耗的时间（ms）
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull )engine remotefirstVideoFrameOfUid:(NSUInteger)uid size:(CGSize)size elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcEngine:remoteVideoStateChangedOfUid:state:reason:elapsed:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull )engine remoteVideoStateChangedOfUid:(NSUInteger)uid state:(RTCEngineVideoRemoteState)state reason:(RTCEngineVideoRemoteStateReason)reason elapsed:(NSInteger)elapsed
 * @desc 远端视频状态发生改变回调
 * @param engine RTCEngine* 引擎对象
 * @param uid  NSUInteger 远端用户ID
 * @param state RTCEngineVideoRemoteState 视频状态
 * @param reason RTCEngineVideoRemoteStateReason 改变原因
 * @param elapsed NSInteger 耗费时间
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull )engine remoteVideoStateChangedOfUid:(NSUInteger)uid state:(RTCEngineVideoRemoteState)state reason:(RTCEngineVideoRemoteStateReason)reason elapsed:(NSInteger)elapsed;

/**
 * @apidoc
 * @name rtcEngine:didOfflineOfUid:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine didOfflineOfUid:(NSUInteger)uid
 * @desc 远端用户离开当前房间回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 远端用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine didOfflineOfUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:didOfflineOfUid:
 * @fname - (void)rtcEngine:(RTCEngine*_Nonnull)engine didOfflineOfUid:(NSUInteger)uid reason:(RTCChannelUserOfflineReason)reason
 * @desc 远端用户离开当前房间回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 远端用户ID
 * @param reason RTCChannelUserOfflineReason 离开原因
 * @return 空
 */
- (void)rtcEngine:(RTCEngine*_Nonnull)engine didOfflineOfUid:(NSUInteger)uid reason:(RTCChannelUserOfflineReason)reason;

/**
 * @apidoc
 * @name rtcEngine:didOfflineOfUid:
 * @fname - (void)rtcEngineConnectionDidLost:(RTCEngine*_Nonnull)engine
 * @desc 网络连接中断，且 SDK 无法在 10 秒内连接服务器回调
 * @param engine RTCEngine* 引擎对象
 * @return 空
 */
- (void)rtcEngineConnectionDidLost:(RTCEngine*_Nonnull)engine;

/**
 * @apidoc
 * @name rtcEngine:connectionChangedToState:reason:
 * @fname - (void)rtcEngine:(RTCEngine * _Nonnull)engine connectionChangedToState:(RTCConnectionStateType)state reason:(NSString*)reason
 * @desc 网络连接状态已改变回调（该回调在网络连接状态发生改变的时候触发，并告知用户当前的网络连接状态，和引起网络状态改变的原因）
 * @param engine RTCEngine* 引擎对象
 * @param state RTCConnectionStateType  当前的网络连接状态
 * @param reason NSString* 引起网络连接状态发生改变的原因
 * @return 空
 */
- (void)rtcEngine:(RTCEngine * _Nonnull)engine connectionChangedToState:(RTCConnectionStateType)state reason:(NSString*)reason;

/**
 * @apidoc
 * @name rtcEngine:didAudioMuted:byUid:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid
 * @desc 远端用户音频静音回调
 * @param engine RTCEngine* 引擎对象
 * @param muted BOOL 远端用户是否静音，YES:静音；NO:取消静音
 * @param uid NSUInteger 远端用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:didVideoMuted:byUid:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid
 * @desc 远端用户暂停/重新发送视频回调
 * @param engine RTCEngine* 引擎对象
 * @param muted BOOL 远端用户是否停止发送视频，YES:该用户已暂停发送其视频流；NO:该用户已恢复发送其视频流
 * @param uid NSUInteger 远端用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:reportAudioVolumeOfSpeaker:volume:
 * @fname - (void)rtcEngine:(RTCEngine * _Nonnull)engine reportAudioVolumeOfSpeaker:(NSUInteger)uid volume:(NSInteger)volume
 * @desc 远端用户暂停/重新发送视频回调
 * @param engine RTCEngine* 引擎对象
 * @param uid  NSUInteger  用户ID
 * @param volume NSInteger 混音后的总音量，取值范围为 [0,255]
 * @return 空
 */
- (void)rtcEngine:(RTCEngine * _Nonnull)engine reportAudioVolumeOfSpeaker:(NSUInteger)uid volume:(NSInteger)volume;
 
 /**
  * @apidoc
  * @name rtcEngine:didAudioSpeakerChanged:
  * @fname - (void)rtcEngine:(RTCEngine * _Nonnull)engine didAudioSpeakerChanged:(RTCEngineAudioOutputRouting)routetype
  * @desc 音频路由已发生变化回调
  * @param engine RTCEngine* 引擎对象
  * @param routetype RTCEngineAudioOutputRouting 当前的音频路由
  * @return 空
  */
- (void)rtcEngine:(RTCEngine * _Nonnull)engine didAudioSpeakerChanged:(RTCEngineAudioOutputRouting)routetype;

/**
 * @apidoc
 * @name rtcEngine:onOnceLastMileQuality:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine onOnceLastMileQuality:(RTCLastMileQuality) quality
 * @desc 通话前网络上下行 last mile 质量报告回调
 * @param engine RTCEngine* 引擎对象
 * @param quality RTCLastMileQuality 网络上下行质量，基于上下行网络的丢包率和抖动计算，探测结果主要反映上行网络的状态
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine onOnceLastMileQuality:(RTCLastMileQuality) quality;

/**
 * @apidoc
 * @name rtcEngine:networkQuality:txQuality:rxQuality:
 * @fname - (void)rtcEngine:(RTCEngine *  _Nonnull)engine networkQuality:(NSUInteger)uid txQuality:(RTCLastMileQuality)txQuality rxQuality:(RTCLastMileQuality)rxQuality
 * @desc 网络质量回调
 * @param engine RTCEngine* 引擎对象
 * @param uid RTCEngine* 引擎对象
 * @param txQuality RTCLastMileQuality 发送端网络质量
 * @param rxQuality RTCLastMileQuality 接收端网络质量
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *  _Nonnull)engine networkQuality:(NSUInteger)uid txQuality:(RTCLastMileQuality)txQuality rxQuality:(RTCLastMileQuality)rxQuality;

/**
 * @apidoc
 * @name rtcEngine:reportRtcStats:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine reportRtcStats:(RTCStats* _Nonnull)stats
 * @desc 当前通话统计回调。 该回调在通话或直播中每两秒触发一次
 * @param engine RTCEngine* 引擎对象
 * @param stats RTCStats* 统计信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine reportRtcStats:(RTCStats* _Nonnull)stats;

/**
 * @apidoc
 * @name rtcEngine:reportLocalAudioStats:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine reportLocalAudioStats:(RTCLocalAudioStats *_Nullable)stats
 * @desc 本地音频统计回调
 * @param engine RTCEngine* 引擎对象
 * @param stats RTCLocalAudioStats* 统计信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine reportLocalAudioStats:(RTCLocalAudioStats *_Nullable)stats;

/**
 * @apidoc
 * @name rtcEngine:reportLocalVideoStats:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine reportLocalVideoStats:(RTCLocalVideoStats *_Nullable)stats
 * @desc 本地视频统计回调
 * @param engine RTCEngine* 引擎对象
 * @param stats RTCLocalVideoStats* 统计信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine reportLocalVideoStats:(RTCLocalVideoStats *_Nullable)stats;

/**
 * @apidoc
 * @name rtcEngine:reportRemoteAudioStats:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine reportRemoteAudioStats:(RTCRemoteAudioStats * _Nonnull)stats
 * @desc 远端音频统计回调
 * @param engine RTCEngine* 引擎对象
 * @param stats RTCRemoteAudioStats* 统计信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine reportRemoteAudioStats:(RTCRemoteAudioStats * _Nonnull)stats;

/**
 * @apidoc
 * @name rtcEngine:reportRemoteVideoStats:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine reportRemoteVideoStats:(RTCRemoteVideoStats * _Nonnull)stats
 * @desc 远端视频统计回调
 * @param engine RTCEngine* 引擎对象
 * @param stats RTCRemoteVideoStats* 统计信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine reportRemoteVideoStats:(RTCRemoteVideoStats * _Nonnull)stats;

/**
 * @apidoc
 * @name rtcEngine:rtmpStreamingChangedToState:state:errorCode:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine rtmpStreamingChangedToState:(NSString *_Nonnull)url state:(RTCRtmpStreamingState)state errorCode:(RTCRtmpStreamingErrorCode)errorCode
 * @desc rtmp 推流状态改变回调
 * @param engine RTCEngine* 引擎对象
 * @param url NSString* 推流地址
 * @param state RTCRtmpStreamingState 推流状态
 * @param errorCode RTCRtmpStreamingErrorCode 错误信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine rtmpStreamingChangedToState:(NSString *_Nonnull)url state:(RTCRtmpStreamingState)state errorCode:(RTCRtmpStreamingErrorCode)errorCode;

/**
 * @apidoc
 * @name rtcEngine:streamPublishedWithUrl:errorCode:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine streamPublishedWithUrl:(NSString *_Nonnull)url errorCode:(RTCRtmpErrorCode)errorCode
 * @desc rtmp 发布回调
 * @param engine RTCEngine* 引擎对象
 * @param url NSString* 推流地址
 * @param errorCode RTCRtmpErrorCode 如果发现任意一个错误码：ERR_TIMEDOUT = 10 或者 ERR_PUBLISH_STREAM_INTERNAL_SERVER_ERROR = 154 则调用：removePublishStreamUrl停止推流
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine streamPublishedWithUrl:(NSString *_Nonnull)url errorCode:(RTCRtmpErrorCode)errorCode;

/**
 * @apidoc
 * @name rtcEngine:streamUnpublishedWithUrl:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine streamUnpublishedWithUrl:(NSString *_Nonnull)url
 * @desc rtmp 取消发布回调，应用层监控到：rtcEngine:streamUnpublishedWithUrl:表示停止推流成功，应用层可再调用：addPublishStreamUrl重新推流
 * @param engine RTCEngine* 引擎对象
 * @param url NSString* 推流地址
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine streamUnpublishedWithUrl:(NSString *_Nonnull)url;

/**
 * @apidoc
 * @name rtcEngineTranscodingUpdated:
 * @fname - (void)rtcEngineTranscodingUpdated:(RTCEngine* _Nonnull)engine
 * @desc rtmp 改变编码回调
 * @param engine RTCEngine* 引擎对象
 * @return 空
 */
- (void)rtcEngineTranscodingUpdated:(RTCEngine* _Nonnull)engine;

/**
 * @apidoc
 * @name rtcEngine:playMusicStateChanged:errorCode:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine playMusicStateChanged:(RTCAudioMixingStateCode)state errorCode:(RTCAudioMixingErrorCode)errorCode
 * @desc 播放音乐文件回调
 * @param engine RTCEngine* 引擎对象
 * @param state RTCAudioMixingStateCode 播放状态
 * @param errorCode RTCAudioMixingErrorCode 错误信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine playMusicStateChanged:(RTCAudioMixingStateCode)state errorCode:(RTCAudioMixingErrorCode)errorCode;

/**
 * @apidoc
 * @name rtcEnginePlayMusicDidFinish:
 * @fname - (void)rtcEnginePlayMusicDidFinish:(RTCEngine* _Nonnull)engine
 * @desc 播放音乐文件结束回调
 * @param engine RTCEngine* 引擎对象
 * @return 空
 */
- (void)rtcEnginePlayMusicDidFinish:(RTCEngine* _Nonnull)engine;

/**
 * @apidoc
 * @name rtcEngineChangedNotify:
 * @fname - (void)rtcEngineChangedNotify:(RTCEngine* _Nonnull)engine
 * @desc 切换引擎通知
 * @param engine RTCEngine* 引擎对象
 * @return 空
 */
- (void)rtcEngineChangedNotify:(RTCEngine* _Nonnull)engine;

/**
 * @apidoc
 * @name rtcEngine:videoBufferingStateChangedOfUid:state:timestampInMs:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine videoBufferingStateChangedOfUid:(NSUInteger)uid state:(RTCVideoBufferingState)state timestampInMs:(NSInteger)timestampInMs
 * @desc 卡顿回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 用户ID
 * @param state RTCVideoBufferingState 卡顿状态
 * @param timestampInMs NSInteger 时间戳
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine videoBufferingStateChangedOfUid:(NSUInteger)uid state:(RTCVideoBufferingState)state timestampInMs:(NSInteger)timestampInMs;

/**
 * @apidoc
 * @name rtcEngineDestroyed:
 * @fname - (void)rtcEngineDestroyed:(RTCEngine* _Nonnull)engine
 * @desc RTCEngine销毁回调，建议在收到该回调后再创建新的引擎
 * @param engine RTCEngine* 引擎对象
 * @return 空
 */
- (void)rtcEngineDestroyed:(RTCEngine* _Nonnull)engine;

/**
 * @apidoc
 * @name rtcEngine:receiveStreamMessageFromUid:data:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine receiveStreamMessageFromUid:(NSString *)uid data:(NSData *)data
 * @desc 接收到消息回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSString* 用户ID
 * @param data NSData* 消息数据
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine receiveStreamMessageFromUid:(NSString *)uid data:(NSData *)data;

/**
 * @apidoc
 * @name rtcEngine:channelMediaRelayStateDidChange:error:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine channelMediaRelayStateDidChange:(RTCChannelMediaRelayState)state error:(RTCChannelMediaRelayError)error
 * @desc 跨频道媒体流转发状态发生改变
 * @param engine RTCEngine* 引擎对象
 * @param state RTCChannelMediaRelayState 流转发状态
 * @param error RTCChannelMediaRelayError 错误信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine channelMediaRelayStateDidChange:(RTCChannelMediaRelayState)state error:(RTCChannelMediaRelayError)error;

/**
 * @apidoc
 * @name rtcEngine:didReceiveChannelMediaRelayEvent:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine didReceiveChannelMediaRelayEvent:(RTCChannelMediaRelayEvent)event
 * @desc 跨频道媒体流转发事件回调
 * @param engine RTCEngine* 引擎对象
 * @param event RTCChannelMediaRelayEvent 流转发事件
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine didReceiveChannelMediaRelayEvent:(RTCChannelMediaRelayEvent)event;

/**
 * @apidoc
 * @name rtcEngine:didRemoteStreamSubscribeAdvice:withUid:currentStream:suitableStream:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine didRemoteStreamSubscribeAdvice:(NSString *)channel withUid:(NSUInteger)uid currentStream:(OmniRtcLiveSubscriptionStreamType)currentStream suitableStream:(OmniRtcLiveSubscriptionStreamType)suitableStream
 * @desc 大小流切换建议回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 用户ID
 * @param currentStream OmniRtcLiveSubscriptionStreamType 当前流类型
 * @param suitableStream OmniRtcLiveSubscriptionStreamType 建议流类型
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine didRemoteStreamSubscribeAdvice:(NSString *)channel withUid:(NSUInteger)uid currentStream:(OmniRtcLiveSubscriptionStreamType)currentStream suitableStream:(OmniRtcLiveSubscriptionStreamType)suitableStream;

/**
 * @apidoc
 * @name rtcEngine:didRemoteSubscribeFallbackToAudioOnly:byUid:
 * @fname - (void)rtcEngine:(RTCEngine* _Nonnull)engine didRemoteSubscribeFallbackToAudioOnly:(BOOL)isFallbackOrRecover byUid:(NSUInteger)uid
 * @desc 切换大小流流状态回调
 * @param engine RTCEngine* 引擎对象
 * @param isFallbackOrRecover BOOL 是否回退到音频
 * @param uid NSUInteger 用户ID
 * @return 空
 */
- (void)rtcEngine:(RTCEngine* _Nonnull)engine didRemoteSubscribeFallbackToAudioOnly:(BOOL)isFallbackOrRecover byUid:(NSUInteger)uid;

/**
 * @apidoc
 * @name rtcEngine:localViewSnapshot:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine localViewSnapshot:(CGImageRef _Nonnull)image
 * @desc 本地视频帧的预览图像回调
 * @param engine RTCEngine* 引擎对象
 * @param image CGImageRef 图像信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine localViewSnapshot:(CGImageRef _Nonnull)image;

/**
 * @apidoc
 * @name rtcEngine:remoteViewSnapshot:image:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine remoteViewSnapshot:(NSUInteger)uid image:(CGImageRef _Nonnull)image
 * @desc 远端视频帧的预览图像回调
 * @param engine RTCEngine* 引擎对象
 * @param uid NSUInteger 用户id
 * @param image CGImageRef 图像信息
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine remoteViewSnapshot:(NSUInteger)uid image:(CGImageRef _Nonnull)image;

/**
 * @apidoc
 * @name rtcEngine:didPublishAudioStateChanged:oldState:newState:elapseSinceLastState:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine didPublishAudioStateChanged:(NSString *_Nonnull)channel oldState:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc 音频推流状态改变回调
 * @param engine RTCEngine* 引擎对象
 * @param channel NSString* 频道ID
 * @param oldState OmniRtcLiveStreamPublishState 发布状态
 * @param newState OmniRtcLiveStreamPublishState 发布状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine didPublishAudioStateChanged:(NSString *_Nonnull)channel oldState:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

/**
 * @apidoc
 * @name rtcEngine:didPublishVideoStateChanged:oldState:newState:elapseSinceLastState:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine didPublishVideoStateChanged:(NSString *_Nonnull)channel oldState:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc 视频推流状态改变回调
 * @param engine RTCEngine* 引擎对象
 * @param channel NSString* 频道ID
 * @param oldState OmniRtcLiveStreamPublishState 发布状态
 * @param newState OmniRtcLiveStreamPublishState 发布状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine didPublishVideoStateChanged:(NSString *_Nonnull)channel oldState:(OmniRtcLiveStreamPublishState)oldState newState:(OmniRtcLiveStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

/**
 * @apidoc
 * @name rtcEngine:didSubscribeAudioStateChanged:withUid:oldState:newState:elapseSinceLastState:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine didSubscribeAudioStateChanged:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc 音频拉流状态改变回调
 * @param engine RTCEngine* 引擎对象
 * @param channel NSString* 频道ID
 * @param uid NSUInteger 用户ID
 * @param oldState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param newState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine didSubscribeAudioStateChanged:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

/**
 * @apidoc
 * @name rtcEngine:didSubscribeVideoStateChanged:withUid:oldState:newState:elapseSinceLastState:
 * @fname - (void)rtcEngine:(RTCEngine *_Nonnull)engine didSubscribeVideoStateChanged:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState
 * @desc 视频拉流状态改变回调
 * @param engine RTCEngine* 引擎对象
 * @param channel NSString* 频道ID
 * @param uid NSUInteger 用户ID
 * @param oldState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param newState OmniRtcLiveStreamSubscribeState 拉流状态
 * @param elapseSinceLastState NSInteger 耗费时间
 * @return 空
 */
- (void)rtcEngine:(RTCEngine *_Nonnull)engine didSubscribeVideoStateChanged:(NSString *_Nonnull)channel withUid:(NSUInteger)uid oldState:(OmniRtcLiveStreamSubscribeState)oldState newState:(OmniRtcLiveStreamSubscribeState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

@end

