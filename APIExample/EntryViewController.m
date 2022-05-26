//
//  EntryViewController.m
//  APIExample
//
//  Created by 窦博 on 2022/5/11.
//

#import "EntryViewController.h"
#import "ViewController.h"
#import "RTCViewController.h"

@interface EntryViewController ()

@property (weak, nonatomic) IBOutlet UITextField *textFieldRoomID;
@property (weak, nonatomic) IBOutlet UITextField *textFieldUserID;

@end

@implementation EntryViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.textFieldRoomID.text = [NSUserDefaults.standardUserDefaults stringForKey:@"OmniRtcRoomID"];
    self.textFieldUserID.text = [NSUserDefaults.standardUserDefaults stringForKey:@"OmniRtcUserID"];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)joinRoom:(id)sender {
    NSString *roomID = self.textFieldRoomID.text;
    NSString *userID = self.textFieldUserID.text;
    
    if (roomID.length < 1) {
        [ViewController showToast:@"“房间号”不能为空！" withView:self.view];
        return;
    }
    
    if (userID.length < 1) {
        [ViewController showToast:@"“用户ID”不能为空！" withView:self.view];
        return;
    }
    
    [NSUserDefaults.standardUserDefaults setValue:roomID forKey:@"OmniRtcRoomID"];
    [NSUserDefaults.standardUserDefaults setValue:userID forKey:@"OmniRtcUserID"];
    
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:self.storyboardName bundle:nil];
    RTCViewController *rtcViewController = [storyboard instantiateViewControllerWithIdentifier:self.controllerName];
    rtcViewController.roomID = roomID;
    rtcViewController.userID = userID;
    [self.navigationController pushViewController:rtcViewController animated:YES];
}

@end
