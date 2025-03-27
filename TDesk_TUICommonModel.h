//
//  TCommonCell.h
//  TXIMSDK_TUIKit_iOS
//
//  Created by annidyfeng on 2019/5/6.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TDesk_TUIDarkModel.h"

@import ImSDK_Plus;

NS_ASSUME_NONNULL_BEGIN
/////////////////////////////////////////////////////////////////////////////////
//
//                            TUIUserFullInfo
//
/////////////////////////////////////////////////////////////////////////////////
@interface V2TIMUserFullInfo (TUIUserFullInfo)
- (NSString *)showName;
- (NSString *)showGender;
- (NSString *)showSignature;
- (NSString *)showAllowType;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                            TDeskUserModel
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskUserModel : NSObject <NSCopying>
@property(nonatomic, copy) NSString *userId;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *avatar;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                           TDeskScrollView
//
/////////////////////////////////////////////////////////////////////////////////

@interface TDeskScrollView : UIScrollView
@property(strong, nonatomic) UIImageView *imageView;
@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskGroupAvatar
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskGroupAvatar : NSObject

/**
 *
 * Obtain the latest group avatar in real time according to the group id. After the avatar is updated, it will be cached locally. This interface will request
 * the network This interface will not use the cache. If you need to read the cache, please use getCacheGroupAvatar:imageCallback or getCacheAvatarForGroup:
 * number:
 */
+ (void)fetchGroupAvatars:(NSString *)groupID placeholder:(UIImage *)placeholder callback:(void (^)(BOOL success, UIImage *image, NSString *groupID))callback;

/**
 * Create a group avatar based on the given url array
 */
+ (void)createGroupAvatar:(NSArray *)group finished:(void (^)(UIImage *groupAvatar))finished;

/**
 * Cache avatars based on group ID and number of group members
 */
+ (void)cacheGroupAvatar:(UIImage *)avatar number:(UInt32)memberNum groupID:(NSString *)groupID;

/**
 * Get the cached avatar asynchronously, this interface will request the interface to get the current number of group members, and return the avatar
 * corresponding to the local cache
 */
+ (void)getCacheGroupAvatar:(NSString *)groupID callback:(void (^)(UIImage *, NSString *groupID))imageCallBack;

/**
 * Get the cached avatar synchronously, this interface does not request the network
 */
+ (UIImage *)getCacheAvatarForGroup:(NSString *)groupId number:(UInt32)memberNum;

/**
 * 
 * Clear the avatar cache of the specified group
 */
+ (void)asyncClearCacheAvatarForGroup:(NSString *)groupID;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskImageCache
//
/////////////////////////////////////////////////////////////////////////////////
@interface TDeskImageCache : NSObject

+ (instancetype)sharedInstance;

- (void)addResourceToCache:(NSString *)path;
- (UIImage *)getResourceFromCache:(NSString *)path;

- (void)addFaceToCache:(NSString *)path;
- (UIImage *)getFaceFromCache:(NSString *)path;

@end
/////////////////////////////////////////////////////////////////////////////////
//
//                          TDeskNavigationController
//
/////////////////////////////////////////////////////////////////////////////////
@class TDeskNavigationController;
@protocol TDeskNavigationControllerDelegate <NSObject>
@optional
- (void)navigationControllerDidClickLeftButton:(TDeskNavigationController *)controller;
- (void)navigationControllerDidSideSlideReturn:(TDeskNavigationController *)controller fromViewController:(UIViewController *)fromViewController;
@end

@interface TDeskNavigationController : UINavigationController <UINavigationControllerDelegate, UIGestureRecognizerDelegate>

@property(nonatomic, weak) UIViewController *currentShowVC;
@property(nonatomic, weak) id<TDeskNavigationControllerDelegate> uiNaviDelegate;
@property(nonatomic, strong) UIImage *navigationItemBackArrowImage;
@property(nonatomic, strong) UIColor *navigationBackColor;
@end

@interface UIAlertController (TDeskTheme)

- (void)tuitheme_addAction:(UIAlertAction *)action;

@end

typedef void (^TDeskValueCallbck)(NSDictionary *param);
typedef void (^TDeskNonValueCallbck)(void);

typedef NSString *TDeskExtVauleType;

@interface NSObject (TUIExtValue)

@property(nonatomic, copy) TDeskValueCallbck tdesk_valueCallback;

@property(nonatomic, copy) TDeskNonValueCallbck tdesk_nonValueCallback;

@property(nonatomic, strong) id tdesk_extValueObj;

@end

NS_ASSUME_NONNULL_END
