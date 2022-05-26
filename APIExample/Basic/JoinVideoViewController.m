//
//  JoinVideoViewController.m
//  APIExample
//
//  Created by 窦博 on 2022/5/18.
//

#import "JoinVideoViewController.h"
#import "ViewController.h"

@interface JoinVideoViewController ()

@property (weak, nonatomic) IBOutlet UILabel *labelRoomID;
@property (weak, nonatomic) IBOutlet UILabel *labelLocalUserID;
@property (weak, nonatomic) IBOutlet UILabel *labelRemoteUserID;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewLocalUser;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewRemoteUser;

@end

@implementation JoinVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.labelRoomID.text = self.roomID;
    self.labelLocalUserID.text = self.userID;
    self.labelRemoteUserID.text = @"";
    self.imageViewLocalUser.image = [UIImage imageNamed:@"Avatar"];
    self.imageViewRemoteUser.image = [UIImage imageNamed:@"Avatar"];

    [self.rtcEngine enableAudio:YES];
    [self.rtcEngine enableLocalAudio:YES];
    [self.rtcEngine enableVideo];
    [self.rtcEngine enableLocalVideo:YES];
    [self.rtcEngine setVideoResolution:RTC_VIDEO_RESOLUTION_360P];
    [self.rtcEngine setupLocalVideo:self.imageViewLocalUser];
    [self.rtcEngine setLocalRenderMode:RTCVideoRenderModeFit];
    [self.rtcEngine startPreview];
    [self.rtcEngine joinRoom];
}

- (void)rtcEngine:(RTCEngine *)engine didOccurError:(RTCEngineErrorCode)code {
    [ViewController showToast:[NSString stringWithFormat:@"rtcEngine didOccurError: %@", @(code)] withView:self.view];
}

- (void)rtcEngine:(RTCEngine *)engine localUserJoindWithUid:(NSUInteger)uid {
}

- (void)rtcEngine:(RTCEngine *)engine remoteUserJoinWithUid:(NSUInteger)uid {
    if (self.labelRemoteUserID.text.length > 0) {
        return;
    }
    
    self.labelRemoteUserID.text = [NSString stringWithFormat:@"%@", @(uid)];
    [self.rtcEngine setupRemoteVideo:uid view:self.imageViewRemoteUser];
    [self.rtcEngine setRemoteRenderMode:uid mode:RTCVideoRenderModeFit];
}

- (void)rtcEngine:(RTCEngine *)engine didOfflineOfUid:(NSUInteger)uid {
    if (self.labelRemoteUserID.text.integerValue == uid) {
        self.labelRemoteUserID.text = @"";
    }
}

@end
