//
//  RTCVideoData.h
//  RTCEngine
//
//  Created by xiang on 2019/3/27.
//  Copyright © 2019 RTCEngine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RTCVideoDataPixelFormat) {
    RTCVideoDataPixelFormatNV12,                // 此种格式裸数据使用 pixelBuffer
    RTCVideoDataPixelFormatNV21,
    RTCVideoDataPixelFormatYV21,
    RTCVideoDataPixelFormatBGRA,
    RTCVideoDataPixelFormatRGBA,
    RTCVideoDataPixelFormatI420,                // 此种格式裸数据使用 yBuffer、uBuffer、vBuffer
};

@interface RTCVideoData : NSObject

@property (nonatomic, assign) RTCVideoDataPixelFormat pixelFormat;
@property (nonatomic, assign) int width;  //width of video frame
@property (nonatomic, assign) int height;  //height of video frame
@property (nonatomic, assign) int yStride;  //stride of Y data buffer
@property (nonatomic, assign) int uStride;  //stride of U data buffer
@property (nonatomic, assign) int vStride;  //stride of V data buffer
@property (nonatomic, assign) int rotation; // rotation of this frame (0, 90, 180, 270)
@property (nonatomic, assign) int64_t renderTimeMs; // timestamp
@property (nonatomic, assign) char* yBuffer;  //Y data buffer
@property (nonatomic, assign) char* uBuffer;  //U data buffer
@property (nonatomic, assign) char* vBuffer;  //V data buffer
@property (nonatomic, assign) CVPixelBufferRef pixelBuffer;

@end

NS_ASSUME_NONNULL_END
