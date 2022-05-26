//
//  RTCViewController.h
//  APIExample
//
//  Created by 窦博 on 2022/5/11.
//

#import <UIKit/UIKit.h>
#import <RTCEngine/RTCEngine.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCViewController : UIViewController <RTCEngineDelegate>

@property (nonatomic, copy) NSString *roomID;
@property (nonatomic, copy) NSString *userID;

@property (nonatomic, strong) RTCEngine *rtcEngine;

@end

NS_ASSUME_NONNULL_END
