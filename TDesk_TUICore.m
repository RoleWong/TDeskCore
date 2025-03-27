
//  Created by Tencent on 2023/06/09.
//  Copyright © 2023 Tencent. All rights reserved.
#import "TDesk_TUICore.h"

#import <objc/runtime.h>

#import "TDesk_TUIDefine.h"
#import "TDesk_TUIThemeManager.h"
#import "TDesk_TUIWeakProxy.h"

@implementation TDeskCore

+ (void)initialize {
    TDeskRegisterThemeResourcePath(TDeskCoreThemePath, TUIThemeModuleCore);
    TDeskRegisterThemeResourcePath(TDeskBundlePath(@"TUICoreTheme_Minimalist", TUICoreBundle_Key_Class), TUIThemeModuleCore_Minimalist);
}

+ (void)registerService:(NSString *)serviceName object:(id<TDeskServiceProtocol>)object {
    [TDeskServiceManager.shareInstance registerService:serviceName service:object];
}

+ (void)unregisterService:(NSString *)serviceName {
    [TDeskServiceManager.shareInstance unregisterService:serviceName];
}

+ (id<TDeskServiceProtocol>)getService:(NSString *)serviceName {
    return [TDeskServiceManager.shareInstance getService:serviceName];
}

+ (id)callService:(NSString *)serviceName method:(NSString *)method param:(nullable NSDictionary *)param {
    return [TDeskServiceManager.shareInstance callService:serviceName method:method param:param resultCallback:nil];
}

+ (id)callService:(NSString *)serviceName
            method:(NSString *)method
             param:(nullable NSDictionary *)param
    resultCallback:(nullable TDeskCallServiceResultCallback)resultCallback {
    return [TDeskServiceManager.shareInstance callService:serviceName method:method param:param resultCallback:resultCallback];
}

+ (void)registerEvent:(NSString *)key subKey:(NSString *)subKey object:(id<TDeskNotificationProtocol>)object {
    [TDeskEventManager.shareInstance registerEvent:key subKey:subKey object:object];
}

+ (void)unRegisterEventByObject:(id<TDeskNotificationProtocol>)object {
    [TDeskEventManager.shareInstance unRegisterEvent:object];
}
+ (void)unRegisterEvent:(nullable NSString *)key subKey:(nullable NSString *)subKey object:(nullable id<TDeskNotificationProtocol>)object {
    [TDeskEventManager.shareInstance unRegisterEvent:key subKey:subKey object:object];
}

+ (void)notifyEvent:(NSString *)key subKey:(NSString *)subKey object:(nullable id)anObject param:(nullable NSDictionary *)param {
    [TDeskEventManager.shareInstance notifyEvent:key subKey:subKey object:anObject param:param];
}

+ (void)registerExtension:(NSString *)extensionID object:(id<TDeskExtensionProtocol>)object {
    [TDeskExtensionManager.shareInstance registerExtension:extensionID extension:object];
}

+ (void)unRegisterExtension:(NSString *)extensionID object:(id<TDeskExtensionProtocol>)object {
    [TDeskExtensionManager.shareInstance unRegisterExtension:extensionID extension:object];
}

+ (NSDictionary *)getExtensionInfo:(NSString *)extensionID param:(nullable NSDictionary *)param {
    return [TDeskExtensionManager.shareInstance getExtensionInfo:extensionID param:param];
}

+ (NSArray<TDeskExtensionInfo *> *)getExtensionList:(NSString *)extensionID param:(nullable NSDictionary *)param {
    return [TDeskExtensionManager.shareInstance getExtensionList:extensionID param:param];
}

+ (BOOL)raiseExtension:(NSString *)extensionID parentView:(UIView *)parentView param:(nullable NSDictionary *)param {
    return [TDeskExtensionManager.shareInstance raiseExtension:extensionID parentView:parentView param:param];
}

+ (void)registerObjectFactory:(NSString *)factoryName objectFactory:(id<TDeskObjectProtocol>)objectFactory {
    [TDeskObjectFactoryManager.shareInstance registerObjectFactory:factoryName objectFactory:objectFactory];
}

+ (void)unRegisterObjectFactory:(NSString *)factoryName {
    [TDeskObjectFactoryManager.shareInstance unRegisterObjectFactory:factoryName];
}

+ (id)createObject:(NSString *)factoryName key:(NSString *)key param:(NSDictionary *)param {
    return [TDeskObjectFactoryManager.shareInstance createObject:factoryName method:key param:param];
}

@end

#pragma mark - TDeskRoute

static const void *navigateValueCallback = @"navigateValueCallback";

@implementation NSObject (TDeskRoute)

- (void)setNavigateValueCallback:(TDeskValueResultCallback)callback {
    objc_setAssociatedObject(self, navigateValueCallback, callback, OBJC_ASSOCIATION_COPY_NONATOMIC);
}

- (TDeskValueResultCallback)navigateValueCallback {
    return objc_getAssociatedObject(self, navigateValueCallback);
}

@end

@implementation UIViewController (TDeskRoute)

- (void)pushViewControllerForTDesk:(NSString *)viewControllerKey param:(nullable NSDictionary *)param forResult:(nullable TDeskValueResultCallback)callback {
    NSAssert([self isKindOfClass:UINavigationController.class], @"self must be a navigation controller");
    UIViewController *vc = [TDeskObjectFactoryManager.shareInstance createObject:viewControllerKey param:param];
    if ([vc isKindOfClass:UIViewController.class]) {
        vc.navigateValueCallback = callback;
        [(UINavigationController *)self pushViewController:vc animated:YES];
    } else {
        NSAssert(false, @"viewControllerKey not exists or invalid");
    }
}

- (void)presentViewControllerForTDesk:(NSString *)viewControllerKey param:(nullable NSDictionary *)param forResult:(nullable TDeskValueResultCallback)callback {
    [self presentViewControllerForTDesk:viewControllerKey param:param embbedIn:nil forResult:callback];
}

- (void)presentViewControllerForTDesk:(NSString *)viewControllerKey
                        param:(nullable NSDictionary *)param
                     embbedIn:(nullable UINavigationController *)navigationVC
                    forResult:(nullable TDeskValueResultCallback)callback {
    UIViewController *vc = [TDeskObjectFactoryManager.shareInstance createObject:viewControllerKey param:param];
    if ([vc isKindOfClass:UIViewController.class]) {
        vc.navigateValueCallback = callback;
        if (navigationVC) {
            if ([navigationVC isKindOfClass:UINavigationController.class]) {
                NSMutableArray *arrayM = [NSMutableArray array];
                if (navigationVC.viewControllers.count > 0) {
                    [arrayM addObjectsFromArray:navigationVC.viewControllers];
                }
                [arrayM addObject:vc];
                navigationVC.viewControllers = [NSArray arrayWithArray:arrayM];
                [self presentViewController:navigationVC animated:YES completion:nil];
            } else {
                NSAssert(false, @"navigationVC must be a navigation controller");
            }
        } else {
            [self presentViewController:vc animated:YES completion:nil];
        }
    } else {
        NSAssert(false, @"viewControllerKey not exists or invalid");
    }
}

@end

#pragma mark - TUIService

@interface TDeskServiceManager ()

@property(nonatomic, strong) NSMapTable<NSString *, id<TDeskServiceProtocol>> *serviceMap;

@end

@implementation TDeskServiceManager

+ (instancetype)shareInstance {
    static id instance = nil;
    if (instance == nil) {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
          instance = [[self alloc] init];
        });
    }
    return instance;
}

- (void)registerService:(NSString *)serviceName service:(id<TDeskServiceProtocol>)service {
    NSAssert(serviceName.length > 0, @"invalid service name");
    NSAssert(service != nil, @"invalid service");

    if (serviceName && service) {
        @synchronized(self.serviceMap) {
            [self.serviceMap setObject:service forKey:serviceName];
        }
    }
}

- (void)unregisterService:(NSString *)serviceName {
    NSAssert(serviceName.length > 0, @"invalid service name");

    if (serviceName) {
        @synchronized(self.serviceMap) {
            [self.serviceMap removeObjectForKey:serviceName];
        }
    }
}

- (nullable id<TDeskServiceProtocol>)getService:(NSString *)serviceName {
    id<TDeskServiceProtocol> service = nil;
    @synchronized(self.serviceMap) {
        service = [self.serviceMap objectForKey:serviceName];
    }
    return service;
}

- (nullable id)callService:(NSString *)serviceName
                    method:(NSString *)method
                     param:(nullable NSDictionary *)param
            resultCallback:(nullable TDeskCallServiceResultCallback)resultCallback {
    NSAssert(serviceName.length > 0, @"invalid service name");
    NSAssert(method.length > 0, @"invalid method");

    id<TDeskServiceProtocol> service = [self getService:serviceName];
    id result = nil;
    if (resultCallback) {
        if (service && [service respondsToSelector:@selector(onCall:param:resultCallback:)]) {
            result = [service onCall:method param:param resultCallback:resultCallback];
        }
    } else {
        if (service && [service respondsToSelector:@selector(onCall:param:)]) {
            result = [service onCall:method param:param];
        }
    }

    return result;
}

- (NSMapTable<NSString *, id<TDeskServiceProtocol>> *)serviceMap {
    if (_serviceMap == nil) {
        _serviceMap = [NSMapTable strongToWeakObjectsMapTable];
    }
    return _serviceMap;
}

@end

#pragma mark - TDeskEvent

@interface TDeskEventManager ()

@property(nonatomic, strong) NSMutableArray<NSDictionary *> *eventList;

@end

@implementation TDeskEventManager

+ (instancetype)shareInstance {
    static id instance = nil;
    if (instance == nil) {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
          instance = [[self alloc] init];
        });
    }
    return instance;
}

- (void)registerEvent:(NSString *)key subKey:(NSString *)subKey object:(id<TDeskNotificationProtocol>)object {
    NSAssert(key.length > 0, @"invalid key");
    NSAssert(object != nil, @"invalid object");

    if (subKey.length == 0) {
        subKey = @"";
    }

    if (key && subKey && object) {
        NSDictionary *event = @{@"key" : [key copy], @"subKey" : [subKey copy], @"object" : [TDeskWeakProxy proxyWithTarget:object]};

        @synchronized(self.eventList) {
            [self.eventList addObject:event];
        }
    }
}

- (void)unRegisterEvent:(id<TDeskNotificationProtocol>)object {
    [self unRegisterEvent:nil subKey:nil object:object];
}

- (void)unRegisterEvent:(nullable NSString *)key subKey:(nullable NSString *)subKey object:(nullable id<TDeskNotificationProtocol>)object {
    @synchronized(self.eventList) {
        NSMutableArray *removeEventList = [NSMutableArray array];
        for (NSDictionary *event in self.eventList) {
            NSString *pkey = [event objectForKey:@"key"];
            NSString *pSubKey = [event objectForKey:@"subKey"];
            id pObject = [event objectForKey:@"object"];

            if (pObject == nil || [(TDeskWeakProxy *)pObject target] == nil) {
                [removeEventList addObject:event];
            }
            if (key == nil && subKey == nil && pObject == object) {
                [removeEventList addObject:event];
            } else if ([pkey isEqualToString:key] && subKey == nil && object == nil) {
                [removeEventList addObject:event];
            } else if ([pkey isEqualToString:key] && [subKey isEqualToString:pSubKey] && object == nil) {
                [removeEventList addObject:event];
            } else if ([pkey isEqualToString:key] && [subKey isEqualToString:pSubKey] && pObject == object) {
                [removeEventList addObject:event];
            }
        }
        [self.eventList removeObjectsInArray:removeEventList];
    }
}

- (void)notifyEvent:(NSString *)key subKey:(NSString *)subKey object:(nullable id)object param:(nullable NSDictionary *)param {
    NSAssert(key.length > 0, @"invalid key");

    if (subKey.length == 0) {
        subKey = @"";
    }

    @synchronized(self.eventList) {
        for (NSDictionary *event in self.eventList) {
            NSString *pkey = [event objectForKey:@"key"];
            NSString *pSubKey = [event objectForKey:@"subKey"];

            if ([pkey isEqualToString:key] && [pSubKey isEqualToString:subKey]) {
                id<TDeskNotificationProtocol> pObject = [event objectForKey:@"object"];
                if (pObject) {
                    [pObject onNotifyEvent:key subKey:subKey object:object param:param];
                }
            }
        }
    }
}

- (NSMutableArray<NSDictionary *> *)eventList {
    if (_eventList == nil) {
        _eventList = [NSMutableArray array];
    }
    return _eventList;
}

@end

#pragma mark - TUIExtension

@implementation TDeskExtensionInfo

@end

@interface TDeskExtensionManager ()

@property(nonatomic, strong) NSMutableDictionary<NSString *, NSHashTable<id<TDeskExtensionProtocol>> *> *extensionMap;

@end

@implementation TDeskExtensionManager

+ (instancetype)shareInstance {
    static id instance = nil;
    if (instance == nil) {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
          instance = [[self alloc] init];
        });
    }
    return instance;
}

- (void)registerExtension:(NSString *)extensionID extension:(id<TDeskExtensionProtocol>)extension {
    NSAssert(extensionID.length > 0, @"invalid extension id");
    NSAssert(extension != nil, @"invalid extension");

    if (extensionID && extension) {
        @synchronized(self.extensionMap) {
            NSHashTable *list = [self.extensionMap objectForKey:extensionID];
            if (list == nil) {
                list = [NSHashTable weakObjectsHashTable];
            }
            [list addObject:extension];
            [self.extensionMap setObject:list forKey:extensionID];
        }
    }
}

- (void)unRegisterExtension:(NSString *)extensionID extension:(id<TDeskExtensionProtocol>)extension {
    NSAssert(extensionID.length > 0, @"invalid extension id");
    NSAssert(extension != nil, @"invalid extension");

    if (extensionID && extension) {
        @synchronized(self.extensionMap) {
            NSHashTable *list = [self.extensionMap objectForKey:extensionID];
            if (list == nil) {
                list = [NSHashTable weakObjectsHashTable];
            }
            [list removeObject:extension];
            [self.extensionMap setObject:list forKey:extensionID];
        }
    }
}

- (NSArray<TDeskExtensionInfo *> *)getExtensionList:(NSString *)extensionID param:(nullable NSDictionary *)param {
    NSAssert(extensionID.length > 0, @"invalid extension id");

    NSHashTable *list = nil;
    @synchronized(self.extensionMap) {
        list = [self.extensionMap objectForKey:extensionID];
    }
    if (list == nil || list.count == 0) {
        return @[];
    }

    // get
    NSMutableArray *resultExtensionInfoList = [NSMutableArray array];
    for (id<TDeskExtensionProtocol> observer in list) {
        if (observer && [observer respondsToSelector:@selector(onGetExtension:param:)]) {
            NSArray<TDeskExtensionInfo *> *infoList = [observer onGetExtension:extensionID param:param];
            if (infoList) {
                [resultExtensionInfoList addObjectsFromArray:infoList];
            }
        }
    }

    // sort
    NSArray *result = [resultExtensionInfoList sortedArrayUsingComparator:^NSComparisonResult(TDeskExtensionInfo *obj1, TDeskExtensionInfo *obj2) {
      if (obj1.weight > obj2.weight) {
          return NSOrderedAscending;
      } else {
          return NSOrderedDescending;
      }
    }];

    return result;
}

- (BOOL)raiseExtension:(NSString *)extensionID parentView:(UIView *)parentView param:(nullable NSDictionary *)param {
    NSAssert(extensionID.length > 0, @"invalid extension id");
    NSAssert(parentView != nil, @"invalid parent view");

    NSHashTable *list = nil;
    @synchronized(self.extensionMap) {
        list = [self.extensionMap objectForKey:extensionID];
    }
    if (list == nil || list.count == 0) {
        return NO;
    }

    BOOL isResponserExist = NO;
    for (id<TDeskExtensionProtocol> observer in list) {
        if (observer && [observer respondsToSelector:@selector(onRaiseExtension:parentView:param:)]) {
            isResponserExist = [observer onRaiseExtension:extensionID parentView:parentView param:param];
            if (isResponserExist) {
                break;
            }
        }
    }
    return isResponserExist;
}

- (NSDictionary *)getExtensionInfo:(NSString *)extensionID param:(nullable NSDictionary *)param {
    NSAssert(extensionID.length > 0, @"invalid extension id");

    NSHashTable *list = nil;
    @synchronized(self.extensionMap) {
        list = [self.extensionMap objectForKey:extensionID];
    }
    if (list == nil || list.count == 0) {
        return nil;
    }

    for (id<TDeskExtensionProtocol> observer in list) {
        if (observer && [observer respondsToSelector:@selector(onGetExtensionInfo:param:)]) {
            NSDictionary *info = [observer onGetExtensionInfo:extensionID param:param];
            if (info) {
                return info;
            }
        }
    }
    return nil;
}

- (NSMutableDictionary<NSString *, NSHashTable<id<TDeskExtensionProtocol>> *> *)extensionMap {
    if (_extensionMap == nil) {
        _extensionMap = [NSMutableDictionary dictionary];
    }
    return _extensionMap;
}
@end

#pragma mark - TUIObjectFactory

@interface TDeskObjectFactoryManager ()

@property(nonatomic, strong) NSMapTable<NSString *, id<TDeskObjectProtocol>> *objectFactoryMap;

@end

@implementation TDeskObjectFactoryManager : NSObject

+ (instancetype)shareInstance {
    static id instance = nil;
    if (instance == nil) {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
          instance = [[self alloc] init];
        });
    }
    return instance;
}

- (void)registerObjectFactory:(NSString *)factoryName objectFactory:(id<TDeskObjectProtocol>)objectFactory {
    NSAssert(factoryName.length > 0, @"invalid factory name");
    NSAssert(objectFactory != nil, @"invalid object factory");

    if (factoryName && objectFactory) {
        @synchronized(self.objectFactoryMap) {
            [self.objectFactoryMap setObject:objectFactory forKey:factoryName];
        }
    }
}

- (void)unRegisterObjectFactory:(NSString *)factoryName {
    NSAssert(factoryName.length > 0, @"invalid factory name");

    if (factoryName) {
        @synchronized(self.objectFactoryMap) {
            [self.objectFactoryMap removeObjectForKey:factoryName];
        }
    }
}

- (nullable id)createObject:(NSString *)factoryName method:(NSString *)method param:(nullable NSDictionary *)param {
    NSAssert(factoryName.length > 0, @"invalid factory name");
    NSAssert(method.length > 0, @"invalid method");

    id<TDeskObjectProtocol> factory = nil;
    @synchronized(self.objectFactoryMap) {
        factory = [self.objectFactoryMap objectForKey:factoryName];
    }

    if (factory && [factory respondsToSelector:@selector(onCreateObject:param:)]) {
        return [factory onCreateObject:method param:param];
    }

    return nil;
}

- (nullable id)createObject:(NSString *)method param:(NSDictionary *)param {
    NSAssert(method.length > 0, @"invalid method");

    NSArray<id<TDeskObjectProtocol>> *list = nil;
    @synchronized(self.objectFactoryMap) {
        list = self.objectFactoryMap.objectEnumerator.allObjects;
    }
    if (list == nil || list.count == 0) {
        return nil;
    }

    for (id<TDeskObjectProtocol> factory in list) {
        if (factory && [factory respondsToSelector:@selector(onCreateObject:param:)]) {
            id obj = [factory onCreateObject:method param:param];
            if (obj) {
                return obj;
            }
        }
    }

    return nil;
}

- (NSMapTable<NSString *, id<TDeskObjectProtocol>> *)objectFactoryMap {
    if (_objectFactoryMap == nil) {
        _objectFactoryMap = [NSMapTable strongToWeakObjectsMapTable];
    }
    return _objectFactoryMap;
}

@end
