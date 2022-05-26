//
//  RTCViewController.m
//  APIExample
//
//  Created by 窦博 on 2022/5/11.
//

#import "RTCViewController.h"
#import "ViewController.h"

@interface RTCViewController ()

@end

@implementation RTCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSString *appID = [NSUserDefaults.standardUserDefaults stringForKey:@"OmniRtcAppID"];
    _rtcEngine = [[RTCEngine alloc] initWithAppID:appID engineType:RTCEngineTypeOmniRtc roomID:self.roomID uid:self.userID delegate:self];
    [_rtcEngine setRole:RTCEngineClientRoleBroadcaster];
}

- (void)dealloc {
    [_rtcEngine leaveRoom];
    [_rtcEngine destroy];
}

@end
