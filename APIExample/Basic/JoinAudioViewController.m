//
//  JoinAudioViewController.m
//  APIExample
//
//  Created by 窦博 on 2022/5/16.
//

#import "JoinAudioViewController.h"
#import "ViewController.h"

@interface JoinAudioViewController ()

@property (weak, nonatomic) IBOutlet UILabel *labelRoomID;
@property (weak, nonatomic) IBOutlet UILabel *labelLocalUserID;
@property (weak, nonatomic) IBOutlet UILabel *labelRemoteUserID;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewLocalUser;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewRemoteUser;

@end

@implementation JoinAudioViewController

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
    [self.rtcEngine disableVideo];
    [self.rtcEngine joinRoom];
}

- (void)rtcEngine:(RTCEngine *)engine didOccurError:(RTCEngineErrorCode)code {
    [ViewController showToast:[NSString stringWithFormat:@"rtcEngine didOccurError: %@", @(code)] withView:self.view];
}

- (void)rtcEngine:(RTCEngine *)engine localUserJoindWithUid:(NSUInteger)uid {
    self.imageViewLocalUser.image = [UIImage imageNamed:@"audio_head"];
}

- (void)rtcEngine:(RTCEngine *)engine remoteUserJoinWithUid:(NSUInteger)uid {
    if (self.labelRemoteUserID.text.length > 0) {
        return;
    }
    
    self.labelRemoteUserID.text = [NSString stringWithFormat:@"%@", @(uid)];
    self.imageViewRemoteUser.image = [UIImage imageNamed:@"audio_head"];
}

- (void)rtcEngine:(RTCEngine *)engine didOfflineOfUid:(NSUInteger)uid {
    if (self.labelRemoteUserID.text.integerValue == uid) {
        self.labelRemoteUserID.text = @"";
        self.imageViewRemoteUser.image = [UIImage imageNamed:@"Avatar"];
    }
}

@end
