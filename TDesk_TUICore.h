
//  Created by Tencent on 2023/06/09.
//  Copyright © 2023 Tencent. All rights reserved.
/**
 *  TDeskCore
 *  This module is mainly responsible for data transfer, event notification and extension between TUI components.
 */

#import <UIKit/UIKit.h>

@protocol TDeskServiceProtocol;
@protocol TDeskObjectProtocol;
@protocol TDeskNotificationProtocol;
@protocol TDeskExtensionProtocol;
@class TDeskExtensionInfo;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TUICallServiceResultCallback)(NSInteger errorCode, NSString *errorMessage, NSDictionary *param);

#pragma mark - TDeskCore
/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of TDeskCore, APIs
//
/////////////////////////////////////////////////////////////////////////////////

@interface TDeskCore : NSObject

+ (void)registerService:(NSString *)serviceName object:(id<TDeskServiceProtocol>)object;
+ (void)unregisterService:(NSString *)serviceName;
+ (nullable id<TDeskServiceProtocol>)getService:(NSString *)serviceName;
+ (nullable id)callService:(NSString *)serviceName method:(NSString *)method param:(nullable NSDictionary *)param;
+ (nullable id)callService:(NSString *)serviceName
                    method:(NSString *)method
                     param:(nullable NSDictionary *)param
            resultCallback:(nullable TUICallServiceResultCallback)resultCallback;

+ (void)registerEvent:(NSString *)key subKey:(NSString *)subKey object:(id<TDeskNotificationProtocol>)object;
+ (void)unRegisterEventByObject:(id<TDeskNotificationProtocol>)object;
+ (void)unRegisterEvent:(nullable NSString *)key subKey:(nullable NSString *)subKey object:(nullable id<TDeskNotificationProtocol>)object;
+ (void)notifyEvent:(NSString *)key subKey:(nullable NSString *)subKey object:(nullable id)anObject param:(nullable NSDictionary *)param;

+ (void)registerExtension:(NSString *)extensionID object:(id<TDeskExtensionProtocol>)object;
+ (void)unRegisterExtension:(NSString *)extensionID object:(id<TDeskExtensionProtocol>)object;
+ (NSArray<TDeskExtensionInfo *> *)getExtensionList:(NSString *)extensionID param:(nullable NSDictionary *)param;
+ (BOOL)raiseExtension:(NSString *)extensionID parentView:(UIView *)parentView param:(nullable NSDictionary *)param;
// deprecated
+ (nullable NSDictionary *)getExtensionInfo:(NSString *)extensionID
                                      param:(nullable NSDictionary *)param __attribute__((deprecated("use getExtensionList:param: instead")));

+ (void)registerObjectFactory:(NSString *)factoryName objectFactory:(id<TDeskObjectProtocol>)objectFactory;
+ (void)unRegisterObjectFactory:(NSString *)factoryName;
+ (nullable id)createObject:(NSString *)factoryName key:(NSString *)method param:(nullable NSDictionary *)param;

@end

#pragma mark - TDeskRoute
/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of TDeskRoute, APIs
//
/////////////////////////////////////////////////////////////////////////////////

typedef void (^TUIValueResultCallback)(NSDictionary *param);

@interface NSObject (TDeskRoute)

@property(nonatomic, copy) TUIValueResultCallback navigateValueCallback;

@end

@interface UIViewController (TDeskRoute)

- (void)pushViewControllerForTDesk:(NSString *)viewControllerKey param:(nullable NSDictionary *)param forResult:(nullable TUIValueResultCallback)callback;

- (void)presentViewControllerForTDesk:(NSString *)viewControllerKey param:(nullable NSDictionary *)param forResult:(nullable TUIValueResultCallback)callback;
- (void)presentViewControllerForTDesk:(NSString *)viewControllerKey
                        param:(nullable NSDictionary *)param
                     embbedIn:(nullable UINavigationController *)navigationVC
                    forResult:(nullable TUIValueResultCallback)callback;

@end

#pragma mark - TUIService
/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of TUIService, APIs
//
/////////////////////////////////////////////////////////////////////////////////

@protocol TDeskServiceProtocol <NSObject>

@optional
- (nullable id)onCall:(NSString *)method param:(nullable NSDictionary *)param;
- (nullable id)onCall:(NSString *)method param:(nullable NSDictionary *)param resultCallback:(TUICallServiceResultCallback)resultCallback;

@end

@interface TDeskServiceManager : NSObject

+ (instancetype)shareInstance;

- (void)registerService:(NSString *)serviceName service:(id<TDeskServiceProtocol>)service;
- (void)unregisterService:(NSString *)serviceName;

- (nullable id<TDeskServiceProtocol>)getService:(NSString *)serviceName;

- (nullable id)callService:(NSString *)serviceName
                    method:(NSString *)method
                     param:(nullable NSDictionary *)param
            resultCallback:(nullable TUICallServiceResultCallback)resultCallback;

@end

#pragma mark - TUIEvent
/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of TUIEvent, APIs
//
/////////////////////////////////////////////////////////////////////////////////

@protocol TDeskNotificationProtocol <NSObject>
@optional
- (void)onNotifyEvent:(NSString *)key subKey:(NSString *)subKey object:(nullable id)anObject param:(nullable NSDictionary *)param;

@end

@interface TUIEventManager : NSObject

+ (instancetype)shareInstance;

- (void)registerEvent:(NSString *)key subKey:(NSString *)subKey object:(id<TDeskNotificationProtocol>)object;
- (void)unRegisterEvent:(id<TDeskNotificationProtocol>)object;
- (void)unRegisterEvent:(nullable NSString *)key subKey:(nullable NSString *)subKey object:(nullable id<TDeskNotificationProtocol>)object;

- (void)notifyEvent:(NSString *)key subKey:(nullable NSString *)subKey object:(nullable id)object param:(nullable NSDictionary *)param;

@end

#pragma mark - TUIExtension
/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of TUIExtension, APIs
//
/////////////////////////////////////////////////////////////////////////////////

typedef void (^TUIExtensionClickCallback)(NSDictionary *param);

@interface TDeskExtensionInfo : NSObject

@property(nonatomic, assign) NSInteger weight;
@property(nonatomic, strong, nullable) UIImage *icon;
@property(nonatomic, copy, nullable) NSString *text;
@property(nonatomic, strong, nullable) NSDictionary *data;
@property(nonatomic, copy, nullable) TUIExtensionClickCallback onClicked;

@end

@protocol TDeskExtensionProtocol <NSObject>
@optional

- (nullable NSArray<TDeskExtensionInfo *> *)onGetExtension:(NSString *)extensionID param:(nullable NSDictionary *)param;

// If there exist responser, return YES
- (BOOL)onRaiseExtension:(NSString *)extensionID parentView:(UIView *)parentView param:(nullable NSDictionary *)param;

// deprecated
- (nullable NSDictionary *)onGetExtensionInfo:(NSString *)extensionID
                                        param:(nullable NSDictionary *)param __attribute__((deprecated("use onGetExtension:param: instead")));

@end

@interface TDeskExtensionManager : NSObject

+ (instancetype)shareInstance;

- (void)registerExtension:(NSString *)extensionID extension:(id<TDeskExtensionProtocol>)extension;
- (void)unRegisterExtension:(NSString *)extensionID extension:(id<TDeskExtensionProtocol>)extension;

- (NSArray<TDeskExtensionInfo *> *)getExtensionList:(NSString *)extensionID param:(nullable NSDictionary *)param;

- (BOOL)raiseExtension:(NSString *)extensionID parentView:(UIView *)parentView param:(nullable NSDictionary *)param;

// deprecated
- (nullable NSDictionary *)getExtensionInfo:(NSString *)extensionID
                                      param:(nullable NSDictionary *)param __attribute__((deprecated("use getExtensionList:param: instead")));

@end

#pragma mark - TUIObjectFactory
/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of TUIObjectFactory, APIs
//
/////////////////////////////////////////////////////////////////////////////////

@protocol TDeskObjectProtocol <NSObject>
@optional
- (nullable id)onCreateObject:(NSString *)method param:(nullable NSDictionary *)param;

@end

@interface TDeskObjectFactoryManager : NSObject

+ (instancetype)shareInstance;

- (void)registerObjectFactory:(NSString *)factoryName objectFactory:(id<TDeskObjectProtocol>)objectFactory;
- (void)unRegisterObjectFactory:(NSString *)factoryName;

- (nullable id)createObject:(NSString *)factoryName method:(NSString *)method param:(nullable NSDictionary *)param;

- (nullable id)createObject:(NSString *)method param:(NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END
