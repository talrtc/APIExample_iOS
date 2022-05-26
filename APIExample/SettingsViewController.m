//
//  SettingsViewController.m
//  APIExample
//
//  Created by 窦博 on 2022/5/11.
//

#import "SettingsViewController.h"
#import <RTCEngine/RTCEngine.h>

@interface SettingsViewController ()

@property (weak, nonatomic) IBOutlet UILabel *labelVersion;
@property (weak, nonatomic) IBOutlet UITextField *textFieldAppID;

@end

@implementation SettingsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
    self.labelVersion.text = [NSString stringWithFormat:@"OmniRtc_iOS_V%@", [RTCEngine getVersion]];
    self.textFieldAppID.text = [NSUserDefaults.standardUserDefaults stringForKey:@"OmniRtcAppID"];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [NSUserDefaults.standardUserDefaults setValue:self.textFieldAppID.text forKey:@"OmniRtcAppID"];
}

#pragma mark - Table view data source

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [super tableView:tableView cellForRowAtIndexPath:indexPath];
    
    // Configure the cell...
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    return cell;
}

@end
