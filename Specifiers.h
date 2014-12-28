//
//  Specifiers.h
//  
//
//  Created by Milo Darling on 12/28/14.
//
//

#ifndef _Specifiers_h
#define _Specifiers_h


#endif

#define kSpecifiersBegin NSMutableArray *specifiers = [[NSMutableArray alloc] init]; \
PSSpecifier *spec

#define kBeginSwitchCell(cellName, cellKey, cellDefault) spec = [PSSpecifier preferenceSpecifierNamed:(cellName) \
                      target:self \
                         set:@selector(setPreferenceValue:specifier:) \
                         get:@selector(readPreferenceValue:) \
                      detail:Nil \
                        cell:PSSwitchCell \
                        edit:Nil]; \
[spec setProperty:(cellKey) forKey:@"key"]; \
[spec setProperty:(cellDefault) forKey:@"default"]

#define kBeginButtonCell(cellName, cellAction) spec = [PSSpecifier preferenceSpecifierNamed:(cellName) \
target:self \
set:NULL \
get:NULL \
detail:Nil \
cell:PSButtonCell \
edit:Nil]; \
spec->action = (cellAction)

#define kBeginLinkCell(cellName, newClass) spec = [PSSpecifier preferenceSpecifierNamed:(cellName) \
target:self \
set:NULL \
get:NULL \
detail:(newClass) \
cell:PSLinkCell \
edit:Nil]

#define kStateRemovedMethod [spec setProperty:NSStringFromSelector(@selector(removedSpecifier:)) forKey:PSDeletionActionKey]

#define kAddCellClass(class) [spec setProperty:NSClassFromString((class)) forKey:@"cellClass"]

#define kBeginGroupCell(header, footer) spec = [PSSpecifier groupSpecifierWithHeader:(header) footer:(footer)]

#define kBeginLinkListCell(name, key, default)  spec = [PSSpecifier preferenceSpecifierNamed:(name) \
target:self \
set:@selector(setPreferenceValue:specifier:) \
get:@selector(readPreferenceValue:) \
detail:NSClassFromString(@"PSListItemsController") \
cell:PSLinkListCell \
edit:Nil]; \
[spec setProperty:(key) forKey:@"key"]; \
[spec setProperty:NSStringFromSelector(@selector(titlesDataSource:)) forKey:@"titlesDataSource"]; \
[spec setProperty:NSStringFromSelector(@selector(valuesDataSource:)) forKey:@"valuesDataSource"]; \
[spec setProperty:(default) forKey:@"default"]

#define kFinishCell [specifiers addObject:spec]; \
spec = nil

#define kInitCoolTwitterCell(twitter) @interface CoolTwitterCell : PSTableCell { } \
@end \
@implementation CoolTwitterCell \
-(void)layoutSubviews { \
    [super layoutSubviews]; \
    self.accessoryType = UITableViewCellAccessoryNone; \
    self.detailTextLabel.text = (twitter); \
} \
@end

#define kCoolTwitterCell(cellName) spec = [PSSpecifier preferenceSpecifierNamed:(cellName) \
target:self \
set:NULL \
get:NULL \
detail:Nil \
cell:PSLinkCell \
edit:Nil]; \
spec->action = @selector(tweetSweetNothings); \
[spec setProperty:NSClassFromString(@"CoolTwitterCell") forKey:@"cellClass"]; \
[specifiers addObject:spec]; \
spec = nil

#define kFinishEverything _specifiers = [[specifiers copy] retain]; \
[specifiers dealloc]
