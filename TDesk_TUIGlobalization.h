//
//  NSBundle+TUIKIT.h
//  Pods
//
//  Created by harvy on 2020/10/9.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TDesk_TUIDefine.h"

/**
 * Get localized strings in TUIKit
 */
#define TDeskKitLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUIKitLocalizableBundle]

#define TDeskCoreLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUICoreLocalizableBundle]

#define TDeskChatLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUIChatLocalizableBundle]

#define TDeskConversationLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUIConversationLocalizableBundle]

#define TDeskContactLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUIContactLocalizableBundle]

#define TDeskGroupLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUIGroupLocalizableBundle]

#define TDeskSearchLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TUISearchLocalizableBundle]

#define TDeskIMCommonLocalizableString(key) [TDeskGlobalization getLocalizedStringForKey:@"" #key "" bundle:TIMCommonLocalizableBundle]

#define isRTL() [TDeskGlobalization getRTLOption]

#define TDeskCustomLanguageKey @"TDeskCustomLanguageKey"
#define TDeskChangeLanguageNotification @"TDeskChangeLanguageNotification"

#define TDeskKitGlobalizationRTLOptionKey @"TDeskKitGlobalizationRTLOptionKey"

@interface TDeskGlobalization : NSObject

/**
 * Get localized string
 */
+ (NSString *)getLocalizedStringForKey:(NSString *)key bundle:(NSString *)bundleName;

/**
 * Get preferred language
 */
+ (NSString *)getPreferredLanguage;

/**
 * Set the preferred language to the specified value.
 */
+ (void)setPreferredLanguage:(NSString *)language;

/**
 * Ignore traditional chinese and switch to simplified chinese
 */
+ (void)ignoreTraditionChinese:(BOOL)ignore;

+ (void)setRTLOption:(BOOL)op;

+ (BOOL)getRTLOption;

#pragma mark - Deprecated
+ (NSString *)g_localizedStringForKey:(NSString *)key bundle:(NSString *)bundleName __attribute__((deprecated("use getLocalizedStringForKey:bundle:")));
+ (NSString *)tk_localizableLanguageKey __attribute__((deprecated("use getPreferredLanguage")));

@end
