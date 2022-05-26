//
//  RTCMediaDelegate.h
//  RTCEngine
//
//  Created by xiang on 2019/3/27.
//  Copyright © 2019 RTCEngine. All rights reserved.
//

#ifndef RTCMediaDelegate_h
#define RTCMediaDelegate_h

#import "RTCVideoData.h"
#import "RTCAudioData.h"


@protocol RTCMediaVideoProcessDelegate <NSObject>

@optional
- (void)didCapturedVideoData:(RTCVideoData *)data;
// 声网建议是不要在异步线程中渲染，就在他们的数据回调线程里做渲染就行，在这个线程里数据不需要拷贝；如果单独起一个异步线程就需要拷贝数据
- (void)didRenderVideoData:(RTCVideoData *)data uid:(NSString*)uid;
@end



@protocol RTCMediaAudioProcessDelegate <NSObject>

@optional
- (void)didCapturedAudioData:(RTCAudioData *)data;
- (void)didRenderAudioData:(RTCAudioData *)data;
- (void)didMixedAudioFrame:(RTCAudioData *)data;
- (void)didRenderAudioData:(RTCAudioData *)data uid:(NSString*)uid;
@end


#endif /* RTCMediaDelegate_h */
