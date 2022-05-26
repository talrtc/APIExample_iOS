//
//  ViewController.m
//  APIExample
//
//  Created by 窦博 on 2022/5/6.
//

#import "ViewController.h"
#import "SettingsViewController.h"
#import "EntryViewController.h"
#import <MBProgressHUD/MBProgressHUD.h>

#pragma mark - MenuItem

@interface MenuItem: NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *storyboard;
@property (nonatomic, copy) NSString *controller;

- (instancetype)initWithName:(NSString *)name storyboard:(NSString *)storyboard controller:(NSString *)controller;

@end

@implementation MenuItem

- (instancetype)initWithName:(NSString *)name storyboard:(NSString *)storyboard controller:(NSString *)controller {
    if (self = [super init]) {
        self.name = name;
        self.storyboard = storyboard;
        self.controller = controller;
    }
    return self;
}

@end

#pragma mark - MenuSection

@interface MenuSection: NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSMutableArray<MenuItem *> *rows;

- (instancetype)initWithName:(NSString *)name;

@end

@implementation MenuSection

- (instancetype)initWithName:(NSString *)name {
    if (self = [super init]) {
        self.name = name;
        self.rows = [NSMutableArray array];
    }
    return self;
}

@end

#pragma mark - ViewController

@interface ViewController ()

@property (nonatomic, strong) NSMutableArray<MenuSection *> *menus;

@end

@implementation ViewController

+ (void)showToast:(NSString *)title withView:(UIView *)view {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];
    hud.mode = MBProgressHUDModeText;
    hud.label.text = title;
    [hud hideAnimated:YES afterDelay:1];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
    _menus = [NSMutableArray array];
    MenuSection *menuSection1 = [[MenuSection alloc] initWithName:@"基础功能"];
    [menuSection1.rows addObject:[[MenuItem alloc] initWithName:@"实时音频通话" storyboard:@"Basic" controller:@"JoinAudio"]];
    [menuSection1.rows addObject:[[MenuItem alloc] initWithName:@"实时视频通话" storyboard:@"Basic" controller:@"JoinVideo"]];
    [_menus addObject:menuSection1];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return self.menus.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.menus[section].rows.count;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return self.menus[section].name;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *cellIdentifier = @"menuCell";
    //UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    
    // Configure the cell...
    //cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    cell.textLabel.text = self.menus[indexPath.section].rows[indexPath.row].name;
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *appID = [NSUserDefaults.standardUserDefaults stringForKey:@"OmniRtcAppID"];
    if (appID.length < 1) {
        [[self class] showToast:@"请首先设置“App ID”！" withView:self.view];
        return;
    }
    
    MenuItem *menuItem = self.menus[indexPath.section].rows[indexPath.row];
    EntryViewController *entryViewController = [self.storyboard instantiateViewControllerWithIdentifier:@"entry"];
    entryViewController.storyboardName = menuItem.storyboard;
    entryViewController.controllerName = menuItem.controller;
    entryViewController.title = menuItem.name;
    [self.navigationController pushViewController:entryViewController animated:YES];
}


- (IBAction)onSettings:(id)sender {
    SettingsViewController *settingsViewController = [self.storyboard instantiateViewControllerWithIdentifier:@"settings"];
    [self.navigationController pushViewController:settingsViewController animated:YES];
}

@end
