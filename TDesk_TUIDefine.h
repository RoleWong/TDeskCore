
//  Created by Tencent on 2023/06/09.
//  Copyright © 2023 Tencent. All rights reserved.

#ifndef THeader_h
#define THeader_h

#import <SDWebImage/SDWebImage.h>
#import "TDesk_NSDictionary+TUISafe.h"
#import "TDesk_TUICommonModel.h"
#import "TDesk_TUIConfig.h"
#import "TDesk_TUIDarkModel.h"
#import "TDesk_TUIGlobalization.h"
#import "TDesk_TUIThemeManager.h"
#import "TDesk_TUITool.h"
#import "TDesk_UIColor+TUIHexColor.h"
#import "TDesk_UIView+TUILayout.h"
#import "TDesk_UIView+TUIToast.h"
#import "TDesk_NSString+TUIUtil.h"
@import ImSDK_Plus;

#define tdesk_weakify(object) \
    autoreleasepool {}         \
    __weak typeof(object) weak##object = object;
#define tdesk_strongify(object) \
    autoreleasepool {}           \
    __strong typeof(weak##object) object = weak##object;

/////////////////////////////////////////////////////////////////////////////////
//
//    Custom message protocol version number
//
/////////////////////////////////////////////////////////////////////////////////
#define BussinessID @"businessID"
#define BussinessID_GroupCreate @"group_create"
#define BussinessID_TextLink @"text_link"
// Supported in 6.5 and later, created by web
#define BussinessID_Evaluation @"evaluation"
// Supported in 6.5 and later, created by web
#define BussinessID_Order @"order"
// Supported in 6.5 and later
#define BussinessID_Typing @"user_typing_status"
// Supported in 7.1 and later
#define BussinessID_GroupPoll @"group_poll"
#define BussinessID_GroupNote @"group_note"
#define BussinessID_GroupNoteTips @"group_note_tips"
#define BussinessID_GroupRoomMessage @"group_room_message"
// Supported in 7.6 and later
#define BussinessID_CustomerService @"customerServicePlugin"
#define BussinessID_Src_CustomerService @"src"
#define BussinessID_Src_CustomerService_Request @"7"
#define BussinessID_Src_CustomerService_Evaluation @"9"
#define BussinessID_Src_CustomerService_EvaluationSelected @"10"
#define BussinessID_Src_CustomerService_Typing @"12"
#define BussinessID_Src_CustomerService_Branch @"15"
#define BussinessID_Src_CustomerService_End @"19"
#define BussinessID_Src_CustomerService_Timeout @"20"
#define BussinessID_Src_CustomerService_Collection @"21"
#define BussinessID_Src_CustomerService_Card @"22"
#define BussinessID_Src_CustomerService_EvaluationRule @"23"
#define BussinessID_Src_CustomerService_EvaluationTrigger @"24"
#define BussinessID_Src_CustomerService_Bot_Welcome_Clarify @"29" // Supported in 8.1 and later
#define BussinessID_Src_CustomerService_Bot_Rich_Text @"30" // Supported in 8.1 and later
#define BussinessID_Src_CustomerService_Bot_Stream_Text @"31" // Supported in 8.1 and later
#define BussinessID_Src_CustomerService_TASK_BRANCH @"32"
#define BussinessID_Src_CustomerService_TASK_INFORMATION_COLLECTOR @"33"
#define GetCustomerServiceBussinessID(src) [NSString stringWithFormat:@"%@%@",BussinessID_CustomerService, src]

/**
 * The business version of "Group-creating custom message"
 */
#define GroupCreate_Version 4

/**
 * The business version of "custom cell" - click to jump to the official website
 */
#define TextLink_Version 4

/**
 *
 * The version of the protocol for the message reply
 * "Message Reply Protocol" version number in "Message Custom Field"
 */
#define kMessageReplyVersion 1

/**
 *
 * The version of the protocol for the message reply
 * "Message Reply Protocol" version number in "Draft Field"
 */
#define kDraftMessageReplyVersion 1

/////////////////////////////////////////////////////////////////////////////////
//
// The version number of the push service
//
/////////////////////////////////////////////////////////////////////////////////
/**
 * The version number of the push service
 */
#define APNs_Version 1

/**
 * General message push
 */
#define APNs_Business_NormalMsg 1

/**
 * Pushing of audio and video call
 */
#define APNs_Business_Call 2

/////////////////////////////////////////////////////////////////////////////////
//
//  Device & Platform
//
/////////////////////////////////////////////////////////////////////////////////
#define Screen_Width [UIScreen mainScreen].bounds.size.width
#define Screen_Height [UIScreen mainScreen].bounds.size.height
#define Is_Iphone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define Is_IPhoneX (Screen_Width >= 375.0f && Screen_Height >= 812.0f && Is_Iphone)
#define StatusBar_Height (Is_IPhoneX ? (44.0) : (20.0))
#define TabBar_Height (Is_IPhoneX ? (49.0 + 34.0) : (49.0))
#define NavBar_Height (44)
#define SearchBar_Height (55)
#define Bottom_SafeHeight (Is_IPhoneX ? (34.0) : (0))
#define RGBA(r, g, b, a) [UIColor colorWithRed:(r) / 255.0f green:(g) / 255.0f blue:(b) / 255.0f alpha:a]
#define RGB(r, g, b) [UIColor colorWithRed:(r) / 255.0f green:(g) / 255.0f blue:(b) / 255.0f alpha:1.f]
#define kScale390(x) (x * (UIScreen.mainScreen.bounds.size.width / 390.0))
#define kScale375(x) (x * (UIScreen.mainScreen.bounds.size.width / 375.0))
/////////////////////////////////////////////////////////////////////////////////
//
//                             Bundle
//
/////////////////////////////////////////////////////////////////////////////////
#define TUIDemoBundle @"TUIDemo"
#define TUICoreBundle @"TDeskCore"
#define TUIChatBundle @"TDeskChat"
#define TUIChatFaceBundle @"TUIChatFace"

#define TUIConversationBundle @"TUIConversation"
#define TUIConversationGroupBundle @"TUIConversationGroup"
#define TUIConversationMarkBundle @"TUIConversationMark"
#define TUIContactBundle @"TUIContact"
#define TUIGroupBundle @"TUIGroup"
#define TUISearchBundle @"TUISearch"
#define TUIPollBundle @"TUIPoll"
#define TUIGroupNoteBundle @"TUIGroupNote"
#define TIMCommonBundle @"TDeskCommon"
#define TUITranslationBundle @"TUITranslation"
#define TUIVoiceToTextBundle @"TUIVoiceToText"
#define TUICustomerServicePluginBundle @"TUICustomerServicePlugin"

#define TUIKitLocalizableBundle @"TDeskCoreLocalizable"
#define TUICoreLocalizableBundle TUIKitLocalizableBundle
#define TUIChatLocalizableBundle @"TDeskChatLocalizable"
#define TUIConversationLocalizableBundle @"TUIConversationLocalizable"
#define TUIContactLocalizableBundle @"TUIContactLocalizable"
#define TUIGroupLocalizableBundle @"TUIGroupLocalizable"
#define TUISearchLocalizableBundle @"TUISearchLocalizable"
#define TIMCommonLocalizableBundle @"TDeskCommonLocalizable"

#define TUIDemoBundle_Key_Class @"TUIKit"
#define TUICoreBundle_Key_Class @"TDeskCore"
#define TUIChatBundle_Key_Class @"TDeskChatService"
#define TUICallKitBundle_Key_Class @"TUICallingService"
#define TUIChatFaceBundle_Key_Class @"TDeskChatService"
#define TUIConversationBundle_Key_Class @"TUIConversationService"
#define TUIConversationGroupBundle_Key_Class @"TUIConversationGroupService"
#define TUIConversationMarkBundle_Key_Class @"TUIConversationMarkService"
#define TUIContactBundle_Key_Class @"TUIContactService"
#define TUIGroupBundle_Key_Class @"TUIGroupService"
#define TUISearchBundle_Key_Class @"TUISearchService"
#define TUIPollBundle_Key_Class @"TUIPollService"
#define TUIGroupNoteBundle_Key_Class @"TUIGroupNoteService"
#define TIMCommonBundle_Key_Class @"TDeskConfig"
#define TUITranslationBundle_Key_Class @"TUITranslationService"
#define TUIVoiceToTextBundle_Key_Class @"TUIVoiceToTextService"
#define TUIKitLocalizableBundle_Key_Class @"TDeskCore"
#define TUIChatLocalizableBundle_Key_Class @"TDeskChatService"
#define TIMCommonLocalizableBundle_Key_Class @"TDeskConfig"
#define TUICustomerServicePluginBundle_Key_Class @"TUICustomerServicePluginService"

static inline NSString *getTDeskFrameWorkName(NSString *bundleKeyClass) {
    if ([bundleKeyClass isEqualToString:TUICoreBundle_Key_Class] || [bundleKeyClass isEqualToString:TUIKitLocalizableBundle_Key_Class]) {
        return @"TDeskCore";
    }
    if ([bundleKeyClass isEqualToString:TUIChatBundle_Key_Class] || [bundleKeyClass isEqualToString:TUIChatFaceBundle_Key_Class] ||
        [bundleKeyClass isEqualToString:TUIChatLocalizableBundle_Key_Class]) {
        return @"TDeskChat";
    }

    if ([bundleKeyClass isEqualToString:TUIConversationBundle_Key_Class]) {
        return @"TUIConversation";
    }
    if ([bundleKeyClass isEqualToString:TUIConversationGroupBundle_Key_Class]) {
        return @"TUIConversationGroupPlugin";
    }
    if ([bundleKeyClass isEqualToString:TUIConversationMarkBundle_Key_Class]) {
        return @"TUIConversationMarkPlugin";
    }
    if ([bundleKeyClass isEqualToString:TUIContactBundle_Key_Class]) {
        return @"TUIContact";
    }
    if ([bundleKeyClass isEqualToString:TUIGroupBundle_Key_Class]) {
        return @"TUIGroup";
    }
    if ([bundleKeyClass isEqualToString:TUISearchBundle_Key_Class]) {
        return @"TUISearch";
    }
    if ([bundleKeyClass isEqualToString:TUIPollBundle_Key_Class]) {
        return @"TUIPullPlugin";
    }
    if ([bundleKeyClass isEqualToString:TUIGroupNoteBundle_Key_Class]) {
        return @"TUIGroupNotePlugin";
    }
    if ([bundleKeyClass isEqualToString:TIMCommonBundle_Key_Class]) {
        return @"TDeskCommon";
    }
    if ([bundleKeyClass isEqualToString:TUITranslationBundle_Key_Class]) {
        return @"TUITranslationPlugin";
    }
    if ([bundleKeyClass isEqualToString:TUIVoiceToTextBundle_Key_Class]) {
        return @"TUIVoiceToTextPlugin";
    }
    if ([bundleKeyClass isEqualToString:TUICustomerServicePluginBundle_Key_Class]) {
        return @"TDeskCustomerServicePlugin";
    }
    return @"";
}

static inline NSString *getTDeskGetBundlePath(NSString *bundleName, NSString *bundleKeyClass) {
    static NSMutableDictionary *bundlePathCache = nil;
    if (bundlePathCache == nil) {
        bundlePathCache = [NSMutableDictionary dictionary];
    }
    NSString *bundlePathKey = [NSString stringWithFormat:@"%@_%@", bundleName, bundleKeyClass];
    NSString *bundlePath = [bundlePathCache objectForKey:bundlePathKey];
    if (bundlePath == nil) {
        bundlePath = [[NSBundle mainBundle] pathForResource:bundleName ofType:@"bundle"];
    }
    if (bundlePath.length == 0) {
        bundlePath = [[NSBundle bundleForClass:NSClassFromString(bundleKeyClass)] pathForResource:bundleName ofType:@"bundle"];
    }
    if (bundlePath.length == 0) {
        bundlePath = [NSBundle mainBundle].bundlePath;
        bundlePath = [bundlePath stringByAppendingPathComponent:@"Frameworks"];
        bundlePath = [bundlePath stringByAppendingPathComponent:getTDeskFrameWorkName(bundleKeyClass)];
        bundlePath = [bundlePath stringByAppendingPathExtension:@"framework"];
        bundlePath = [bundlePath stringByAppendingPathComponent:bundleName];
        bundlePath = [bundlePath stringByAppendingPathExtension:@"bundle"];
    }
    if (bundlePath && bundlePathKey) {
        [bundlePathCache setObject:bundlePath forKey:bundlePathKey];
    }
    return bundlePath;
}

#define TDeskBundlePath(bundleName, bundleKeyClass) getTDeskGetBundlePath(bundleName, bundleKeyClass)

#define TDeskDemoThemePath TDeskBundlePath(@"TUIDemoTheme", TUIDemoBundle_Key_Class)
#define TDeskCoreThemePath TDeskBundlePath(@"TDeskCoreTheme", TUICoreBundle_Key_Class)
#define TUDeskChatThemePath TDeskBundlePath(@"TDeskChatTheme", TUIChatBundle_Key_Class)
#define TDeskConversationThemePath TDeskBundlePath(@"TUIConversationTheme", TUIConversationBundle_Key_Class)
#define TDeskConversationGroupTheme TDeskBundlePath(@"TDeskConversationGroupTheme", TUIConversationGroupBundle_Key_Class)
#define TDeskContactThemePath TDeskBundlePath(@"TUIContactTheme", TUIContactBundle_Key_Class)
#define TDeskGroupThemePath TDeskBundlePath(@"TUIGroupTheme", TUIGroupBundle_Key_Class)
#define TDeskSearchThemePath TDeskBundlePath(@"TUISearchTheme", TUISearchBundle_Key_Class)
#define TDeskPollThemePath TDeskBundlePath(@"TUIPollTheme", TUIPollBundle_Key_Class)
#define TDeskGroupNoteThemePath TDeskBundlePath(@"TUIGroupNoteTheme", TUIGroupNoteBundle_Key_Class)
#define TDeskCommonThemePath TDeskBundlePath(@"TDeskCommonTheme", TIMCommonBundle_Key_Class)
#define TDeskTranslationThemePath TDeskBundlePath(@"TUITranslationTheme", TUITranslationBundle_Key_Class)
#define TDeskVoiceToTextThemePath TDeskBundlePath(@"TUIVoiceToTextTheme", TUIVoiceToTextBundle_Key_Class)
#define TDeskCallKitThemePath TDeskBundlePath(@"TUICallKitTheme", TUICallKitBundle_Key_Class)
#define TDeskkCustomerServicePluginThemePath TDeskBundlePath(@"TUICustomerServicePluginTheme",TUICustomerServicePluginBundle_Key_Class)

static inline NSBundle *getTDeskGetLocalizable(NSString *bundleName) {
    if ([bundleName isEqualToString:TUIChatLocalizableBundle] || [bundleName isEqualToString:TUIChatFaceBundle]) {
        return [NSBundle bundleWithPath:TDeskBundlePath(bundleName, TUIChatLocalizableBundle_Key_Class)];
    } else if ([bundleName isEqualToString:TIMCommonLocalizableBundle]) {
        return [NSBundle bundleWithPath:TDeskBundlePath(bundleName, TIMCommonLocalizableBundle_Key_Class)];
    }
    else {
        return [NSBundle bundleWithPath:TDeskBundlePath(bundleName, TUIKitLocalizableBundle_Key_Class)];
    }
}
#define TUIKitLocalizable(bundleName) getTDeskGetLocalizable(bundleName)

#define TUIDemoImagePath(imageName) [TDeskBundlePath(TUIDemoBundle, TUIDemoBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUICoreImagePath(imageName) [TDeskBundlePath(TUICoreBundle, TUICoreBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIChatImagePath(imageName) [TDeskBundlePath(TUIChatBundle, TUIChatBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TDeskChatFaceImagePath(imageName) [TDeskBundlePath(TUIChatFaceBundle, TUIChatFaceBundle_Key_Class) stringByAppendingPathComponent:imageName]

#define TUIConversationImagePath(imageName) [TDeskBundlePath(TUIConversationBundle, TUIConversationBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIConversationGroupImagePath(imageName) \
    [TDeskBundlePath(TUIConversationGroupBundle, TUIConversationGroupBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIConversationMarkImagePath(imageName) \
    [TDeskBundlePath(TUIConversationMarkBundle, TUIConversationMarkBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIContactImagePath(imageName) [TDeskBundlePath(TUIContactBundle, TUIContactBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIGroupImagePath(imageName) [TDeskBundlePath(TUIGroupBundle, TUIGroupBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUISearchImagePath(imageName) [TDeskBundlePath(TUISearchBundle, TUISearchBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIPollImagePath(imageName) [TDeskBundlePath(TUIPollBundle, TUIPollBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIGroupNoteImagePath(imageName) [TDeskBundlePath(TUIGroupNoteBundle, TUIGroupNoteBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TIMCommonImagePath(imageName) [TDeskBundlePath(TIMCommonBundle, TIMCommonBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUITranslationImagePath(imageName) [TDeskBundlePath(TUITranslationBundle, TUITranslationBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIVoiceToTextImagePath(imageName) [TDeskBundlePath(TUIVoiceToTextBundle, TUIVoiceToTextBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUICustomerServicePluginImagePath(imageName) \
    [TDeskBundlePath(TUICustomerServicePluginBundle,TUICustomerServicePluginBundle_Key_Class) stringByAppendingPathComponent:imageName]

//-----Minimalist-------
#define TUIDemoBundle_Minimalist @"TUIDemo_Minimalist"
#define TUICoreBundle_Minimalist @"TDeskCore_Minimalist"
#define TUIChatBundle_Minimalist @"TUIChat_Minimalist"
#define TUIChatFaceBundle_Minimalist @"TUIChatFace_Minimalist"
#define TUIConversationBundle_Minimalist @"TUIConversation_Minimalist"
#define TUIContactBundle_Minimalist @"TUIContact_Minimalist"
#define TUIGroupBundle_Minimalist @"TUIGroup_Minimalist"
#define TUISearchBundle_Minimalist @"TUISearch_Minimalist"
#define TUIPollBundle_Minimalist @"TUIPoll_Minimalist"
#define TUIGroupNoteBundle_Minimalist @"TUIGroupNote_Minimalist"
#define TUITranslationBundle_Minimalist @"TUITranslation_Minimalist"
#define TUIVoiceToTextBundle_Minimalist @"TUIVoiceToText_Minimalist"
// #define TUIKitLocalizableBundle  @"TUIKitLocalizable"

// #define TUIKitLocalizable(bundleName) [NSBundle bundleWithPath:TDeskBundlePath(bundleName, TUIKitLocalizableBundle_Key_Class)]

#define TUIDemoImagePath_Minimalist(imageName) [TDeskBundlePath(TUIDemoBundle_Minimalist, TUIDemoBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUICoreImagePath_Minimalist(imageName) [TDeskBundlePath(TUICoreBundle_Minimalist, TUICoreBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIChatImagePath_Minimalist(imageName) [TDeskBundlePath(TUIChatBundle_Minimalist, TUIChatBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TDeskChatFaceImagePath_Minimalist(imageName) \
    [TDeskBundlePath(TUIChatFaceBundle_Minimalist, TUIChatFaceBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIConversationImagePath_Minimalist(imageName) \
    [TDeskBundlePath(TUIConversationBundle_Minimalist, TUIConversationBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIContactImagePath_Minimalist(imageName) \
    [TDeskBundlePath(TUIContactBundle_Minimalist, TUIContactBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIGroupImagePath_Minimalist(imageName) [TDeskBundlePath(TUIGroupBundle_Minimalist, TUIGroupBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUISearchImagePath_Minimalist(imageName) [TDeskBundlePath(TUISearchBundle_Minimalist, TUISearchBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIPollImagePath_Minimalist(imageName) [TDeskBundlePath(TUIPollBundle_Minimalist, TUIPollBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIGroupNoteImagePath_Minimalist(imageName) \
    [TDeskBundlePath(TUIGroupNoteBundle_Minimalist, TUIGroupNoteBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUITranslationImagePath_Minimalist(imageName) \
    [TDeskBundlePath(TUITranslationBundle_Minimalist, TUITranslationBundle_Key_Class) stringByAppendingPathComponent:imageName]
#define TUIVoiceToTextImagePath_Minimalist(imageName) \
    [TDeskBundlePath(TUIVoiceToTextBundle_Minimalist, TUIVoiceToTextBundle_Key_Class) stringByAppendingPathComponent:imageName]
//-----

/////////////////////////////////////////////////////////////////////////////////
//
//                             File Cache
//
/////////////////////////////////////////////////////////////////////////////////
#define TUIKit_DB_Path [NSHomeDirectory() stringByAppendingString:@"/Documents/com_tencent_imsdk_data/"]
#define TUIKit_Image_Path [NSHomeDirectory() stringByAppendingString:@"/Documents/com_tencent_imsdk_data/image/"]
#define TUIKit_Video_Path [NSHomeDirectory() stringByAppendingString:@"/Documents/com_tencent_imsdk_data/video/"]
#define TUIKit_Voice_Path [NSHomeDirectory() stringByAppendingString:@"/Documents/com_tencent_imsdk_data/voice/"]
#define TUIKit_File_Path [NSHomeDirectory() stringByAppendingString:@"/Documents/com_tencent_imsdk_data/file/"]

/////////////////////////////////////////////////////////////////////////////////
//
//                             Custom view
//
/////////////////////////////////////////////////////////////////////////////////
// input
#define TUIInputMoreCellKey_VideoCall @"TUIInputMoreCellKey_VideoCall"
#define TUIInputMoreCellKey_AudioCall @"TUIInputMoreCellKey_AudioCall"
#define TUIInputMoreCellKey_Link @"TUIInputMoreCellKey_Link"
#define TUIInputMoreCellKey_Poll @"TUIInputMoreCellKey_Poll"
#define TUIInputMoreCellKey_GroupNote @"TUIInputMoreCellKey_GroupNote"

// cell
#define TMessageCell_Name @"TMessageCell_Name"
#define TMessageCell_Data_Name @"TMessageCell_Data_Name"
#define TMessageCell_Head_Width 45
#define TMessageCell_Head_Height 45
#define TMessageCell_Head_Size CGSizeMake(45, 45)
#define TMessageCell_Padding 8
#define TMessageCell_Margin 8
#define TMessageCell_Indicator_Size CGSizeMake(20, 20)

// text cell
#define TTextMessageCell_ReuseId @"TTextMessageCell"
#define TTextMessageCell_Height_Min (TMessageCell_Head_Size.height + 2 * TMessageCell_Padding)
#define TTextMessageCell_Text_PADDING (160)
#define TTextMessageCell_Text_Width_Max (Screen_Width - TTextMessageCell_Text_PADDING)
#define TTextMessageCell_Margin 12

// system cell
#define TSystemMessageCell_ReuseId @"TSystemMessageCell"
#define TSystemMessageCell_Text_Width_Max (Screen_Width * 0.5)
#define TSystemMessageCell_Margin 5

// joinGroup cell
#define TJoinGroupMessageCell_ReuseId @"TJoinGroupMessageCell"
#define TJoinGroupMessageCell_Text_Width_Max (Screen_Width * 0.5)
#define TJoinGroupMessageCell_Margin 5

// image cell
#define TImageMessageCell_ReuseId @"TImageMessageCell"
#define TImageMessageCell_Image_Width_Max (Screen_Width * 0.4)
#define TImageMessageCell_Image_Height_Max TImageMessageCell_Image_Width_Max
#define TImageMessageCell_Margin_2 8
#define TImageMessageCell_Margin_1 16
#define TImageMessageCell_Progress_Color RGBA(0, 0, 0, 0.5)

// face cell
#define TFaceMessageCell_ReuseId @"TFaceMessageCell"
#define TFaceMessageCell_Image_Width_Max (Screen_Width * 0.25)
#define TFaceMessageCell_Image_Height_Max TFaceMessageCell_Image_Width_Max
#define TFaceMessageCell_Margin 16

// file cell
#define TFileMessageCell_ReuseId @"TFileMessageCell"
#define TFileMessageCell_Container_Size CGSizeMake((474 * 0.5), (124 * 0.5))
#define TFileMessageCell_Margin 10
#define TFileMessageCell_Progress_Color RGBA(0, 0, 0, 0.5)

// video cell
#define TVideoMessageCell_ReuseId @"TVideoMessageCell"
#define TVideoMessageCell_Image_Width_Max (Screen_Width * 0.4)
#define TVideoMessageCell_Image_Height_Max TVideoMessageCell_Image_Width_Max
#define TVideoMessageCell_Margin_3 4
#define TVideoMessageCell_Margin_2 8
#define TVideoMessageCell_Margin_1 16
#define TVideoMessageCell_Play_Size CGSizeMake(35, 35)
#define TVideoMessageCell_Progress_Color RGBA(0, 0, 0, 0.5)

// voice cell
#define TVoiceMessageCell_ReuseId @"TVoiceMessaageCell"
#define TVoiceMessageCell_Max_Duration 60.0
#define TVoiceMessageCell_Height TMessageCell_Head_Size.height
#define TVoiceMessageCell_Margin 12
#define TVoiceMessageCell_Back_Width_Max (Screen_Width * 0.4)
#define TVoiceMessageCell_Back_Width_Min 60
#define TVoiceMessageCell_Duration_Size CGSizeMake(33, 33)

// group live cell
#define TGroupLiveMessageCell_ReuseId @"TGroupLiveMessageCell"

// reply message cell
#define TReplyMessageCell_ReuseId @"TDeskReplyMessageCell"
#define TUIReferenceMessageCell_ReuseId @"TDeskReferenceMessageCell"
#define TReplyQuoteView_Max_Width 175
#define TReplyQuoteView_Margin_Width 35

// merge message cell
#define TMergeMessageCell_ReuserId @"TMergeMessageCell"
#define TMergeMessageCell_Width_Max 200
#define TMergeMessageCell_Height_Max 100

// rich text cell
#define TRichTextMessageCell_ReuserId @"TRichTextMessageCell"
#define TRichTextMessageCell_Width_Max (Screen_Width * 0.7)
#define TRichTextMessageCell_Height_Default (100)

// text view
#define TTextView_Height (52)
#define TTextView_Button_Size CGSizeMake(40, 40)
#define TTextView_Margin 6
#define TTextView_TextView_Height_Min (TTextView_Height - 2 * TTextView_Margin)
#define TTextView_TextView_Height_Max 80

// face view
#define TFaceView_Height 287
#define TFaceView_Margin 10
#define TFaceView_Page_Padding 20
#define TFaceView_Page_Height 30

// menu view
#define TMenuView_Send_Color RGBA(87, 190, 105, 1.0)
#define TMenuView_Margin 6
#define TMenuView_Menu_Height 59

// more view
#define TMoreView_Column_Count 4
#define TMoreView_Section_Padding 24
#define TMoreView_Margin 20
#define TMoreView_Page_Height 30

// menu item cell
#define TMenuCell_ReuseId @"TMenuCell"
#define TMenuCell_Margin 6
#define TMenuCell_Line_ReuseId @"TMenuLineCell"
#define TMenuCell_Background_Color RGBA(246, 246, 246, 1.0)
#define TMenuCell_Background_Color_Dark RGBA(30, 30, 30, 1.0)
#define TMenuCell_Selected_Background_Color RGBA(255, 255, 255, 1.0)
#define TMenuCell_Selected_Background_Color_Dark RGBA(41, 41, 41, 1.0)

// more item cell
#define TMoreCell_ReuseId @"TMoreCell"
#define TMoreCell_Margin 5
#define TMoreCell_Image_Size CGSizeMake(65, 65)
#define TMoreCell_Title_Height 20

// face item cell
#define TFaceCell_ReuseId @"TFaceCell"

// group member cell
#define TGroupMemberCell_ReuseId @"TGroupMemberCell"
#define TGroupMemberCell_Margin 5
#define TGroupMemberCell_Head_Size CGSizeMake(50, 50)
#define TGroupMemberCell_Name_Height 20

// conversation cell
#define TConversationCell_Height 72
#define TConversationCell_Margin 12
#define TConversationCell_Margin_Text 14
#define TConversationCell_Margin_Disturb 16
#define TConversationCell_Margin_Disturb_Dot 10

#define TConversationCell_Height_LiteMode 62

// AudioCall cell
#define TUIAudioCallUserCell_ReuseId @"TUIAudioCallUserCell"

// VideoCall cell
#define TUIVideoCallUserCell_ReuseId @"TUIVideoCallUserCell"

// pop view
#define TUIPopView_Arrow_Size CGSizeMake(15, 10)
#define TUIPopView_Background_Color RGBA(188, 188, 188, 0.5)
#define TUIPopView_Background_Color_Dark RGBA(76, 76, 76, 0.5)

// pop cell
#define TUIPopCell_ReuseId @"TDeskPopCell"
#define TUIPopCell_Height 45
#define TUIPopCell_Margin 18
#define TUIPopCell_Padding 12

// unRead
#define TUnReadView_Margin_TB 2
#define TUnReadView_Margin_LR 4

// message controller
#define TMessageController_Header_Height 40

// members controller
#define TGroupMembersController_Margin 20
#define TGroupMembersController_Row_Count 5

// add c2c controller
#define TAddC2CController_Margin 10

// add group controller
#define TAddGroupController_Margin 15

// add member controller
#define TAddMemberController_Margin 15

// delete member controller
#define TDeleteMemberController_Margin 15

// add cell
#define TAddCell_ReuseId @"TAddCell"
#define TAddCell_Height 55
#define TAddCell_Margin 10
#define TAddCell_Select_Size CGSizeMake(25, 25)
#define TAddCell_Head_Size CGSizeMake(38, 38)

// modify view
#define TModifyView_Background_Color RGBA(0, 0, 0, 0.5)
#define TModifyView_Background_Color_Dark RGBA(76, 76, 76, 0.5)
#define TModifyView_Confirm_Color RGBA(44, 145, 247, 1.0)

// record
#define Record_Background_Color RGBA(0, 0, 0, 0.6)
#define Record_Background_Size CGSizeMake(Screen_Width * 0.4, Screen_Width * 0.4)
#define Record_Title_Height 30
#define Record_Title_Background_Color RGBA(186, 60, 65, 1.0)
#define Record_Margin 8

// key value cell
#define TKeyValueCell_ReuseId @"TKeyValueCell"
#define TKeyValueCell_Indicator_Size CGSizeMake(15, 15)
#define TKeyValueCell_Margin 10
#define TKeyValueCell_Height 50

// button cell
#define TButtonCell_ReuseId @"TButtonCell"
#define TButtonCell_Height 56
#define TButtonCell_Margin 1

// switch cell
#define TSwitchCell_ReuseId @"TSwitchCell"
#define TSwitchCell_Height 50
#define TSwitchCell_Margin 10

// personal common cell
#define TPersonalCommonCell_Image_Size CGSizeMake(48, 48)
#define TPersonalCommonCell_Margin 20
#define TPersonalCommonCell_Indicator_Size CGSizeMake(15, 15)

// group common cell
#define TGroupCommonCell_ReuseId @"TGroupCommonCell"
#define TGroupCommonCell_Image_Size CGSizeMake(80, 80)
#define TGroupCommonCell_Margin 10
#define TGroupCommonCell_Indicator_Size CGSizeMake(15, 15)

// gropu member cell
#define TGroupMembersCell_ReuseId @"TGroupMembersCell"
#define TGroupMembersCell_Column_Count 5
#define TGroupMembersCell_Row_Count 2
#define TGroupMembersCell_Margin 10
#define TGroupMembersCell_Image_Size CGSizeMake(60, 60)

// navigationbar indicator view
#define TUINaviBarIndicatorView_Margin 5

// controller commom color
#define TController_Background_Color RGBA(255, 255, 255, 1.0)
#define TController_Background_Color_Dark RGBA(25, 25, 25, 1.0)

// title commom color
#define TText_Color [UIColor blackColor]
#define TText_Color_Dark RGB(217, 217, 217)
#define TText_OutMessage_Color_Dark RGB(0, 15, 0)

// cell commom color
#define TCell_Nomal [UIColor whiteColor]
#define TCell_Nomal_Dark RGB(35, 35, 35)
#define TCell_Touched RGB(219, 219, 219)
#define TCell_Touched_Dark RGB(47, 47, 47)
#define TCell_OnTop RGB(247, 247, 247)
#define TCell_OnTop_Dark RGB(47, 47, 47)

// line commom color
#define TLine_Color RGBA(188, 188, 188, 0.6)
#define TLine_Color_Dark RGBA(35, 35, 35, 0.6)
#define TLine_Heigh 0.5

// page commom color
#define TPage_Color RGBA(222, 222, 222, 1.0)
#define TPage_Color_Dark RGBA(55, 55, 55, 1.0)
#define TPage_Current_Color RGBA(125, 125, 125, 1.0)
#define TPage_Current_Color_Dark RGBA(140, 140, 140, 1.0)

// input view commom color
#define TInput_Background_Color RGBA(235, 240, 246, 1.0)
#define TInput_Background_Color_Dark RGBA(30, 30, 30, 1.0)

// rich
#define kDefaultRichCellHeight 50
#define kDefaultRichCellMargin 8
#define kRichCellDescColor [UIColor blackColor]
#define kRichCellValueColor [UIColor grayColor]
#define kRichCellTextFont [UIFont systemFontOfSize:14]

/////////////////////////////////////////////////////////////////////////////////
//
//                             Notification
//
/////////////////////////////////////////////////////////////////////////////////
/**
 * Notification of a change in message state
 */
#define TUIKitNotification_onMessageStatusChanged @"TUIKitNotification_onMessageStatusChanged"

/**
 * Received error notification that the package is not supported
 */
#define TUIKitNotification_onReceivedUnsupportInterfaceError @"TUIKitNotification_onReceivedUnsupportInterfaceError"

/**
 * Received error notification that the package is not supported, need contact to experience
 */
#define TUIKitNotification_onReceivedValueAddedUnsupportContactNeededError @"TUIKitNotification_onReceivedValueAddedUnsupportContactNeededError"

/**
 * Received error notification that the package is not supported, need to purchase
 */
#define TUIKitNotification_onReceivedValueAddedUnsupportPurchaseNeededError @"TUIKitNotification_onReceivedValueAddedUnsupportPurchaseNeededError"

/**
 * Unread update notifications received when the Conversation list is updated
 */
#define TUIKitNotification_onConversationMarkUnreadCountChanged @"TUIKitNotification_onConversationMarkUnreadCountChanged"
#define TUIKitNotification_onConversationMarkUnreadCountChanged_DataProvider @"dataProvider"
#define TUIKitNotification_onConversationMarkUnreadCountChanged_MarkUnreadCount @"markUnreadCount"
#define TUIKitNotification_onConversationMarkUnreadCountChanged_MarkHideUnreadCount @"markHideUnreadCount"
#define TUIKitNotification_onConversationMarkUnreadCountChanged_MarkUnreadMap @"markUnreadMap"

#define TUIKitNotification_onMessageVCBottomMarginChanged @"TUIKitNotification_onMessageVCBottomMarginChanged"
#define TUIKitNotification_onMessageVCBottomMarginChanged_Margin @"bottonMargin"
/////////////////////////////////////////////////////////////////////////////////
//
//                             TDeskCore
//
/////////////////////////////////////////////////////////////////////////////////

#pragma mark - TDeskCore_TUIChat_Service
#define TDeskCore_TUIChatService @"TDeskCore_TUIChatService"
#define TDeskCore_TUIChatService_Minimalist @"TDeskCore_TUIChatService_Minimalist"

#define TDeskCore_TUIChatService_GetDisplayStringMethod @"TDeskCore_TUIChatService_GetDisplayStringMethod"
#define TDeskCore_TUIChatService_GetDisplayStringMethod_MsgKey @"msg"

#define TDeskCore_TUIChatService_AsyncGetDisplayStringMethod @"TDeskCore_TUIChatService_AsyncGetDisplayStringMethod"
#define TDeskCore_TUIChatService_AsyncGetDisplayStringMethod_MsgListKey @"TDeskCore_TUIChatService_AsyncGetDisplayStringMethod_MsgListKey"

#define TDeskCore_TUIChatService_SendMessageMethod @"TDeskCore_TUIChatService_SendMessageMethod"
#define TDeskCore_TUIChatService_SendMessageMethod_MsgKey @"TDeskCore_TUIChatService_SendMessageMethod_MsgKey"

#define TDeskCore_TUIChatService_SendMessageMethodWithoutUpdateUI @"TDeskCore_TUIChatService_SendMessageMethodWithoutUpdateUI"
#define TDeskCore_TUIChatService_SendMessageMethodWithoutUpdateUI_MsgKey @"TDeskCore_TUIChatService_SendMessageMethodWithoutUpdateUI_MsgKey"

#define TDeskCore_TUIChatService_SetChatExtensionMethod @"TDeskCore_TUIChatService_SetChatExtensionMethod"
#define TDeskCore_TUIChatService_SetChatExtensionMethod_EnableVideoCallKey @"TDeskCore_TUIChatService_SetChatExtensionMethod_EnableVideoCallKey"
#define TDeskCore_TUIChatService_SetChatExtensionMethod_EnableAudioCallKey @"TDeskCore_TUIChatService_SetChatExtensionMethod_EnableAudioCallKey"
#define TDeskCore_TUIChatService_SetChatExtensionMethod_EnableLinkKey @"TDeskCore_TUIChatService_SetChatExtensionMethod_EnableLinkKey"

#define TDeskCore_TUIChatService_AppendCustomMessageMethod @"TDeskCore_TUIChatService_AppendCustomMessageMethod"
#define TDeskCore_TUIChatService_SetMaxTextSize @"TDeskCore_TUIChatService_SetMaxTextSize"


#pragma mark - TDeskCore_TUIChat_Notify
#define TDeskCore_TUIChatNotify @"TDeskCore_TUIChatNotify"
#define TDeskCore_TDeskNotify @"TDeskCore_TDeskNotify"
#define TDeskCore_TUIChatNotify_SendMessageSubKey @"TDeskCore_TUIChatNotify_SendMessageSubKey"
#define TDeskCore_TUIChatNotify_SendMessageSubKey_Code @"TDeskCore_TUIChatNotify_SendMessageSubKey_Code"
#define TDeskCore_TUIChatNotify_SendMessageSubKey_Desc @"TDeskCore_TUIChatNotify_SendMessageSubKey_Desc"
#define TDeskCore_TUIChatNotify_SendMessageSubKey_Message @"TDeskCore_TUIChatNotify_SendMessageSubKey_Message"
#define TDeskCore_TUIChatNotify_KeyboardWillHideSubKey @"TDeskCore_TUIChatNotify_KeyboardWillHideSubKey"
#define TDeskCore_TUIChatNotify_ChatVC_ViewDidLoadSubKey @"TDeskCore_TUIChatNotify_ChatVC_ViewDidLoadSubKey"
#define TDeskCore_TDeskNotify_ChatVC_ViewDidLoadSubKey @"TDeskCore_TDeskNotify_ChatVC_ViewDidLoadSubKey"
#define TDeskCore_TUIChatNotify_ChatVC_ViewDidLoadSubKey_UserID @"TDeskCore_TUIChatNotify_ChatVC_ViewDidLoadSubKey_UserID"
// The notification of displaying the message cell data
#define TDeskCore_TUIChatNotify_MessageDisplayedSubKey @"TDeskCore_TUIChatNotify_MessageDisplayedSubKey"

#pragma mark - TDeskCore_TUIChat_Extension
#define TDeskCore_TUIChatExtension_GetMoreCellInfo_VideoCall @"TDeskCore_TUIChatExtension_GetMoreCellInfo_VideoCall"
#define TDeskCore_TUIChatExtension_GetMoreCellInfo_AudioCall @"TDeskCore_TUIChatExtension_GetMoreCellInfo_AudioCall"
#define TDeskCore_TUIChatExtension_GetMoreCellInfo_UserID @"TDeskCore_TUIChatExtension_GetMoreCellInfo_UserID"
#define TDeskCore_TUIChatExtension_GetMoreCellInfo_GroupID @"TDeskCore_TUIChatExtension_GetMoreCellInfo_GroupID"
#define TDeskCore_TUIChatExtension_GetMoreCellInfo_View @"TDeskCore_TUIChatExtension_GetMoreCellInfo_View"

// Chat interface configuration extension
#define TDeskCore_TUIChatExtension_GetChatConversationModelParams @"TDeskCore_TUIChatExtension_GetChatConversationModelParams"
#define TDeskCore_TUIChatExtension_GetChatConversationModelParams_UserID @"TDeskCore_TUIChatExtension_GetChatConversationModelParams_UserID"
#define TDeskCore_TUIChatExtension_GetChatConversationModelParams_MsgNeedReadReceipt @"TDeskCore_TUIChatExtension_GetChatConversationModelParams_MsgNeedReadReceipt" //bool
#define TDeskCore_TUIChatExtension_GetChatConversationModelParams_EnableVideoCall @"TDeskCore_TUIChatExtension_GetChatConversationModelParams_EnableVideoCall" //bool
#define TDeskCore_TUIChatExtension_GetChatConversationModelParams_EnableAudioCall @"TDeskCore_TUIChatExtension_GetChatConversationModelParams_EnableAudioCall" //bool
#define TDeskCore_TUIChatExtension_GetChatConversationModelParams_EnableWelcomeCustomMessage @"TDeskCore_TUIChatExtension_GetChatConversationModelParams_EnableWelcomeCustomMessage" //bool

// Chat page top area expansion
#define TDeskCore_TUIChatExtension_ChatViewTopArea_ClassicExtensionID @"TDeskCore_TUIChatExtension_ChatViewTopArea_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_ChatViewTopArea_MinimalistExtensionID @"TDeskCore_TUIChatExtension_ChatViewTopArea_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_ChatViewTopArea_ChangedNotification @"TDeskCore_TUIChatExtension_ChatViewTopArea_ChangedNotification"
#define TDeskCore_TUIChatExtension_ChatViewTopArea_ViewType @"TDeskCore_TUIChatExtension_ChatViewTopArea_ViewType"
#define TDeskCore_TUIChatExtension_ChatViewTopArea_ChatID @"TDeskCore_TUIChatExtension_ChatViewTopArea_ChatID"
#define TDeskCore_TUIChatExtension_ChatViewTopArea_IsGroup @"TDeskCore_TUIChatExtension_ChatViewTopArea_IsGroup"

// UI extension when clicking the avatar in message list
#define TDeskCore_TUIChatExtension_ClickAvatar_ClassicExtensionID @"TDeskCore_TUIChatExtension_ClickAvatar_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_ClickAvatar_MinimalistExtensionID @"TDeskCore_TUIChatExtension_ClickAvatar_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_ClickAvatar_UserID @"TDeskCore_TUIChatExtension_ClickAvatar_UserID"
#define TDeskCore_TUIChatExtension_ClickAvatar_GroupID @"TDeskCore_TUIChatExtension_ClickAvatar_GroupID"
#define TDeskCore_TUIChatExtension_ClickAvatar_PushVC @"TDeskCore_TUIChatExtension_ClickAvatar_PushVC"

// UI extension on the right side of navigation bar in chat page
#define TDeskCore_TUIChatExtension_NavigationMoreItem_ClassicExtensionID @"TDeskCore_TUIChatExtension_NavigationMoreItem_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_MinimalistExtensionID @"TDeskCore_TUIChatExtension_NavigationMoreItem_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_UserID @"TDeskCore_TUIChatExtension_NavigationMoreItem_UserID"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_GroupID @"TDeskCore_TUIChatExtension_NavigationMoreItem_GroupID"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_FilterVideoCall @"TDeskCore_TUIChatExtension_NavigationMoreItem_FilterVideoCall"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_FilterAudioCall @"TDeskCore_TUIChatExtension_NavigationMoreItem_FilterAudioCall"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_ItemSize @"TDeskCore_TUIChatExtension_NavigationMoreItem_ItemSize"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_ItemImage @"TDeskCore_TUIChatExtension_NavigationMoreItem_ItemImage"
#define TDeskCore_TUIChatExtension_NavigationMoreItem_PushVC @"TDeskCore_TUIChatExtension_NavigationMoreItem_PushVC"

// UI extension for the input area at the bottom of the chat page
#define TDeskCore_TUIChatExtension_InputViewMoreItem_ClassicExtensionID @"TDeskCore_TUIChatExtension_InputViewMoreItem_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_MinimalistExtensionID @"TDeskCore_TUIChatExtension_InputViewMoreItem_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_UserID @"TDeskCore_TUIChatExtension_InputViewMoreItem_UserID"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_GroupID @"TDeskCore_TUIChatExtension_InputViewMoreItem_GroupID"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_FilterVideoCall @"TDeskCore_TUIChatExtension_InputViewMoreItem_FilterVideoCall"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_FilterAudioCall @"TDeskCore_TUIChatExtension_InputViewMoreItem_FilterAudioCall"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_FilterRoom @"TDeskCore_TUIChatExtension_InputViewMoreItem_FilterRoom"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_FilterPoll @"TDeskCore_TUIChatExtension_InputViewMoreItem_FilterPoll"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_FilterGroupNote @"TDeskCore_TUIChatExtension_InputViewMoreItem_FilterGroupNote"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_ItemSize @"TDeskCore_TUIChatExtension_InputViewMoreItem_ItemSize"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_ItemImage @"TDeskCore_TUIChatExtension_InputViewMoreItem_ItemImage"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_ItemTitle @"TDeskCore_TUIChatExtension_InputViewMoreItem_ItemTitle"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_PushVC @"TDeskCore_TUIChatExtension_InputViewMoreItem_PushVC"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_VC @"TDeskCore_TUIChatExtension_InputViewMoreItem_VC"
#define TDeskCore_TUIChatExtension_InputViewMoreItem_ActionVC @"TDeskCore_TUIChatExtension_InputViewMoreItem_ActionVC"

// Chat page message long press pop-up UI extension.
#define TDeskCore_TUIChatExtension_ChatPopMenuReactRecentView_ClassicExtensionID @"TDeskCore_TUIChatExtension_ChatPopMenuReactRecentView_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_ChatPopMenuReactRecentView_MinimalistExtensionID @"TDeskCore_TUIChatExtension_ChatPopMenuReactRecentView_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_ChatPopMenuReactRecentView_Delegate @"TDeskCore_TUIChatExtension_ChatPopMenuReactRecentView_Delegate"


#define TDeskCore_TUIChatExtension_ChatPopMenuReactDetailView_ClassicExtensionID @"TDeskCore_TUIChatExtension_ChatPopMenuReactDetailView_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_ChatPopMenuReactDetailView_MinimalistExtensionID @"TDeskCore_TUIChatExtension_ChatPopMenuReactDetailView_MinimalistExtensionID"

#define TDeskCore_TUIChatExtension_PopMenuActionItem_ClassicExtensionID @"TDeskCore_TUIChatExtension_PopMenuActionItem_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_PopMenuActionItem_MinimalistExtensionID @"TDeskCore_TUIChatExtension_PopMenuActionItem_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_PopMenuActionItem_TargetVC @"TDeskCore_TUIChatExtension_PopMenuActionItem_TargetVC"
#define TDeskCore_TUIChatExtension_PopMenuActionItem_ClickCell @"TDeskCore_TUIChatExtension_PopMenuActionItem_ClickCell"
// Chat message cell container UI extension.
#define TDeskCore_TUIChatExtension_ChatMessageReactPreview_ClassicExtensionID @"TDeskCore_TUIChatExtension_ChatMessageReactPreview_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_ChatMessageReactPreview_MinimalistExtensionID @"TDeskCore_TUIChatExtension_ChatMessageReactPreview_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_ChatMessageReactPreview_Delegate @"TDeskCore_TUIChatExtension_ChatMessageReactPreview_Delegate"

// Chat message cell bottom container UI extension.
#define TDeskCore_TUIChatExtension_BottomContainer_ClassicExtensionID @"TDeskCore_TUIChatExtension_BottomContainer_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_BottomContainer_MinimalistExtensionID @"TDeskCore_TUIChatExtension_BottomContainer_MinimalistExtensionID"
#define TDeskCore_TUIChatExtension_BottomContainer_CellData @"TDeskCore_TUIChatExtension_BottomContainer_CellData"
#define TDeskCore_TUIChatExtension_BottomContainer_VC @"TDeskCore_TUIChatExtension_BottomContainer_VC"
// Chat page UI extension below chatVC
#define TDeskCore_TUIChatExtension_ChatVCBottomContainer_ClassicExtensionID @"TDeskCore_TUIChatExtension_ChatVCBottomContainer_ClassicExtensionID"
#define TDeskCore_TUIChatExtension_ChatVCBottomContainer_VC @"TDeskCore_TUIChatExtension_ChatVCBottomContainer_VC"
#define TDeskCore_TUIChatExtension_ChatVCBottomContainer_UserID @"TDeskCore_TUIChatExtension_ChatVCBottomContainer_UserID"

#pragma mark - TDeskCore_TUIChat_ObjectFactory
#define TDeskCore_TUIChatObjectFactory @"TDeskCore_TUIChatObjectFactory"
#define TDeskCore_TUIChatObjectFactory_Minimalist @"TDeskCore_TUIChatObjectFactory_Minimalist"

#pragma mark - TDeskCore_TUIChat_ObjectFactory_Route
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Classic @"TDeskCore_TUIChatObjectFactory_ChatViewController_Classic"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Minimalist @"TDeskCore_TUIChatObjectFactory_ChatViewController_Minimalist"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Title @"TDeskCore_TUIChatObjectFactory_ChatViewController_Title"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_UserID @"TDeskCore_TUIChatObjectFactory_ChatViewController_UserID"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_GroupID @"TDeskCore_TUIChatObjectFactory_ChatViewController_GroupID"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_ConversationID @"TDeskCore_TUIChatObjectFactory_ChatViewController_ConversationID"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_AvatarImage @"TDeskCore_TUIChatObjectFactory_ChatViewController_AvatarImage"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_AvatarUrl @"TDeskCore_TUIChatObjectFactory_ChatViewController_AvatarUrl"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_HighlightKeyword @"TDeskCore_TUIChatObjectFactory_ChatViewController_HighlightKeyword"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_LocateMessage @"TDeskCore_TUIChatObjectFactory_ChatViewController_LocateMessage"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_AtTipsStr @"TDeskCore_TUIChatObjectFactory_ChatViewController_AtTipsStr"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_AtMsgSeqs @"TDeskCore_TUIChatObjectFactory_ChatViewController_AtMsgSeqs"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Draft @"TDeskCore_TUIChatObjectFactory_ChatViewController_Draft"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Video_Call @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Video_Call"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Audio_Call @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Audio_Call"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Room @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Room"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_WelcomeCustomMessage @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_WelcomeCustomMessage"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Limit_Portrait_Orientation @"TDeskCore_TUIChatObjectFactory_ChatViewController_Limit_Portrait_Orientation"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Poll @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Poll"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_GroupNote @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_GroupNote"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_TakePhoto @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_TakePhoto"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_RecordVideo @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_RecordVideo"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_File @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_File"
#define TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Album @"TDeskCore_TUIChatObjectFactory_ChatViewController_Enable_Album"

#pragma mark - TDeskCore_TUIConversation_Service
#define TDeskCore_TUIConversationService @"TDeskCore_TUIConversationService"
#define TDeskCore_TUIConversationService_Minimalist @"TDeskCore_TUIConversationService_Minimalist"

#pragma mark - TDeskCore_TUIConversation_Notify
#define TDeskCore_TUIConversationNotify @"TDeskCore_TUIConversationNotify"
#define TDeskCore_TUIConversationNotify_RemoveConversationSubKey @"TDeskCore_TUIConversationNotify_RemoveConversationSubKey"
#define TDeskCore_TUIConversationNotify_RemoveConversationSubKey_ConversationID @"TDeskCore_TUIConversationNotify_RemoveConversationSubKey_ConversationID"
#define TDeskCore_TUIConversationNotify_ClearConversationUIHistorySubKey @"TDeskCore_TUIConversationNotify_ClearConversationUIHistorySubKey"

#pragma mark - TDeskCore_TUIConversation_Extension
// UI extension for the banner in the conversation list page
#define TDeskCore_TUIConversationExtension_ConversationListBanner_ClassicExtensionID @"TDeskCore_TUIConversationExtension_ConversationListBanner_ClassicExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationListBanner_MinimalistExtensionID \
    @"TDeskCore_TUIConversationExtension_ConversationListBanner_MinimalistExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationListBanner_BannerSize @"TDeskCore_TUIConversationExtension_ConversationListBanner_BannerSize"
#define TDeskCore_TUIConversationExtension_ConversationListBanner_ModalVC @"TDeskCore_TUIConversationExtension_ConversationListBanner_ModalVC"

#pragma mark - TDeskCore_TUIConversation_ObjectFactory
#define TDeskCore_TUIConversationObjectFactory @"TDeskCore_TUIConversationObjectFactory"
#define TDeskCore_TUIConversationObjectFactory_Minimalist @"TDeskCore_TUIConversationObjectFactory_Minimalist"

#define TDeskCore_TUIConversationObjectFactory_GetConversationControllerMethod @"TDeskCore_TUIConversationObjectFactory_GetConversationControllerMethod"

#pragma mark - TDeskCore_TUIConversation_ObjectFactory_Route
// Route to conversation select page
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_Classic @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_Classic"
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_Minimalist @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_Minimalist"
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList"
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_ConversationID \
    @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_ConversationID"
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_Title @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_Title"
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_UserID \
    @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_UserID"
#define TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_GroupID \
    @"TDeskCore_TUIConversationObjectFactory_ConversationSelectVC_ResultList_GroupID"

// UI extension for the banner in the conversation group list
#define TDeskCore_TUIConversationExtension_ConversationGroupListBanner_ClassicExtensionID \
    @"TDeskCore_TUIConversationExtension_ConversationGroupListBanner_ClassicExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationGroupListBanner_GroupItemKey @"TDeskCore_TUIConversationExtension_ConversationGroupListBanner_GroupItemKey"

// UI extension for the conversation group manager
#define TDeskCore_TUIConversationExtension_ConversationGroupManagerContainer_ClassicExtensionID \
    @"TDeskCore_TUIConversationExtension_ConversationGroupManagerContainer_ClassicExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationGroupManagerContainer_ParentVCKey \
    @"TDeskCore_TUIConversationExtension_ConversationGroupManagerContainer_ParentVCKey"

// UI extension for the conversation list
#define TDeskCore_TUIConversationExtension_ConversationListContainer_ClassicExtensionID \
    @"TDeskCore_TUIConversationExtension_ConversationListContainer_ClassicExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationListContainer_GroupNameKey @"TDeskCore_TUIConversationExtension_ConversationListContainer_GroupNameKey"

// UI extension for the conversation cell upper right corner
#define TDeskCore_TUIConversationExtension_ConversationCellUpperRightCorner_ClassicExtensionID \
    @"TDeskCore_TUIConversationExtension_ConversationCellUpperRightCorner_ClassicExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationCellUpperRightCorner_GroupListKey \
    @"TDeskCore_TUIConversationExtension_ConversationCellUpperRightCorner_GroupListKey"
#define TDeskCore_TUIConversationExtension_ConversationCellUpperRightCorner_MarkListKey \
    @"TDeskCore_TUIConversationExtension_ConversationCellUpperRightCorner_MarkListKey"

// UI extension for click more
#define TDeskCore_TUIConversationExtension_ConversationCellMoreAction_ClassicExtensionID \
    @"TDeskCore_TUIConversationExtension_ConversationCellMoreAction_ClassicExtensionID"
#define TDeskCore_TUIConversationExtension_ConversationCellAction_ConversationIDKey @"TDeskCore_TUIConversationExtension_ConversationCellAction_ConversationIDKey"
#define TDeskCore_TUIConversationExtension_ConversationCellAction_MarkListKey @"TDeskCore_TUIConversationExtension_ConversationCellAction_MarkListKey"
#define TDeskCore_TUIConversationExtension_ConversationCellAction_GroupListKey @"TDeskCore_TUIConversationExtension_ConversationCellAction_GroupListKey"

#pragma mark - TDeskCore_TUIConversationGroupNotify
#define TDeskCore_TUIConversationGroupNotify @"TDeskCore_TUIConversationGroupNotify"
#define TDeskCore_TUIConversationGroupNotify_GroupListReloadKey @"TDeskCore_TUIConversationGroupNotify_GroupListReloadKey"
#define TDeskCore_TUIConversationGroupNotify_GroupAddKey @"TDeskCore_TUIConversationGroupNotify_GroupAddKey"
#define TDeskCore_TUIConversationGroupNotify_GroupUpdateKey @"TDeskCore_TUIConversationGroupNotify_GroupUpdateKey"
#define TDeskCore_TUIConversationGroupNotify_GroupRenameKey @"TDeskCore_TUIConversationGroupNotify_GroupRenameKey"
#define TDeskCore_TUIConversationGroupNotify_GroupDeleteKey @"TDeskCore_TUIConversationGroupNotify_GroupDeleteKey"

#pragma mark - UICore_TUIConversationGroupExtension
#define TDeskCore_TUIConversationGroupExtension_ConversationGroupListSort_ClassicExtensionID \
    @"TDeskCore_TUIConversationGroupExtension_ConversationGroupListSort_ClassicExtensionID"
#define TDeskCore_TUIConversationGroupExtension_ConversationGroupListSort_GroupItemKey \
    @"TDeskCore_TUIConversationGroupExtension_ConversationGroupListSort_GroupItemKey"

#pragma mark - TDeskCore_TUIConversationMarkNotify
#define TDeskCore_TUIConversationMarkNotify @"TDeskCore_TUIConversationMarkNotify"
#define TDeskCore_TUIConversationGroupNotify_MarkAddKey @"TDeskCore_TUIConversationGroupNotify_MarkAddKey"
#define TDeskCore_TUIConversationGroupNotify_MarkUpdateKey @"TDeskCore_TUIConversationGroupNotify_MarkUpdateKey"

#pragma mark - TDeskCore_TUIContact_Service
#define TDeskCore_TUIContactService @"TDeskCore_TUIContactService"
#define TDeskCore_TUIContactService_Minimalist @"TDeskCore_TUIContactService_Minimalist"

#pragma mark - TDeskCore_TUIContact_Notify
#define TDeskCore_TUIContactNotify @"TDeskCore_TUIContactNotify"

#define TDeskCore_TUIContactNotify_UpdateConversationBackgroundImageSubKey @"TDeskCore_TUIContactNotify_UpdateConversationBackgroundImageSubKey"
#define TDeskCore_TUIContactNotify_UpdateConversationBackgroundImageSubKey_ConversationID \
    @"TDeskCore_TUIContactNotify_UpdateConversationBackgroundImageSubKey_ConversationID"

#pragma mark - TDeskCore_TUIContact_Extension
// UI extension for the action menus in the friend profile page
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_ClassicExtensionID @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_ClassicExtensionID"
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_MinimalistExtensionID @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_MinimalistExtensionID"
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_UserID @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_UserID"
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_UserIcon @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_UserIcon"
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_UserName @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_UserName"

#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_FilterVideoCall @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_FilterVideoCall"
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_FilterAudioCall @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_FilterAudioCall"
#define TDeskCore_TUIContactExtension_FriendProfileActionMenu_PushVC @"TDeskCore_TUIContactExtension_FriendProfileActionMenu_PushVC"

// UI extension for the settings in the "Me" profile page
#define TDeskCore_TUIContactExtension_MeSettingMenu_ClassicExtensionID @"TDeskCore_TUIContactExtension_MeSettingMenu_ClassicExtensionID"
#define TDeskCore_TUIContactExtension_MeSettingMenu_MinimalistExtensionID @"TDeskCore_TUIContactExtension_MeSettingMenu_MinimalistExtensionID"
#define TDeskCore_TUIContactExtension_MeSettingMenu_Nav @"TDeskCore_TUIContactExtension_MeSettingMenu_Nav"
#define TDeskCore_TUIContactExtension_MeSettingMenu_Data @"TDeskCore_TUIContactExtension_MeSettingMenu_Data"
#define TDeskCore_TUIContactExtension_MeSettingMenu_View @"TDeskCore_TUIContactExtension_MeSettingMenu_View"
#define TDeskCore_TUIContactExtension_MeSettingMenu_Weight @"TDeskCore_TUIContactExtension_MeSettingMenu_Weight"

// UI extension for group type in the "Contact" page
#define TDeskCore_TUIContactExtension_ContactMenu_ClassicExtensionID @"TDeskCore_TUIContactExtension_ContactMenu_ClassicExtensionID"
#define TDeskCore_TUIContactExtension_ContactMenu_MinimalistExtensionID @"TDeskCore_TUIContactExtension_ContactMenu_MinimalistExtensionID"
#define TDeskCore_TUIContactExtension_ContactMenu_Nav @"TDeskCore_TUIContactExtension_ContactMenu_Nav"

#pragma mark - TDeskCore_TUIContact_ObjectFactory
#define TDeskCore_TUIContactObjectFactory @"TDeskCore_TUIContactObjectFactory"
#define TDeskCore_TUIContactObjectFactory_Minimalist @"TDeskCore_TUIContactObjectFactory_Minimalist"

#define TDeskCore_TUIContactObjectFactory_GetContactControllerMethod @"TDeskCore_TUIContactObjectFactory_GetContactControllerMethod"

#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod"
#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_TitleKey @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_TitleKey"
#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_MaxSelectCount \
    @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_MaxSelectCount"
#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_SourceIdsKey \
    @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_SourceIdsKey"
#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_DisableIdsKey \
    @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_DisableIdsKey"
#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_DisplayNamesKey \
    @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_DisplayNamesKey"
#define TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_CompletionKey \
    @"TDeskCore_TUIContactObjectFactory_GetContactSelectControllerMethod_CompletionKey"

#define TDeskCore_TUIContactObjectFactory_GetFriendProfileControllerMethod @"TDeskCore_TUIContactObjectFactory_GetFriendProfileControllerMethod"
#define TDeskCore_TUIContactObjectFactory_GetFriendProfileControllerMethod_FriendProfileKey \
    @"TDeskCore_TUIContactObjectFactory_GetFriendProfileControllerMethod_FriendProfileKey"

#define TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod @"TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod"
#define TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_TitleKey @"TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_TitleKey"
#define TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_GroupNameKey \
    @"TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_GroupNameKey"
#define TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_GroupTypeKey \
    @"TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_GroupTypeKey"
#define TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_ContactListKey \
    @"TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_ContactListKey"
#define TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_CompletionKey \
    @"TDeskCore_TUIContactObjectFactory_GetGroupCreateControllerMethod_CompletionKey"

#define TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod @"TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod"
#define TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod_UserIDKey @"TDeskCore_TUIContactService_etUserOrFriendProfileVCMethod_UserIDKey"
#define TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod_SuccKey @"TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod_SuccKey"
#define TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod_FailKey @"TDeskCore_TUIContactObjectFactory_GetUserOrFriendProfileVCMethod_FailKey"

#pragma mark - TDeskCore_TUIContact_ObjectFactory_Route
// Route to user profile page
#define TDeskCore_TUIContactObjectFactory_UserProfileController_Classic @"TDeskCore_TUIContactObjectFactory_UserProfileController_Classic"
#define TDeskCore_TUIContactObjectFactory_UserProfileController_Minimalist @"TDeskCore_TUIContactObjectFactory_UserProfileController_Minimalist"
#define TDeskCore_TUIContactObjectFactory_UserProfileController_UserProfile @"TDeskCore_TUIContactObjectFactory_UserProfileController_UserProfile"
#define TDeskCore_TUIContactObjectFactory_UserProfileController_PendencyData @"TDeskCore_TUIContactObjectFactory_UserProfileController_PendencyData"
#define TDeskCore_TUIContactObjectFactory_UserProfileController_ActionType @"TDeskCore_TUIContactObjectFactory_UserProfileController_ActionType"

#pragma mark - TDeskCore_TUIGroup_Service
#define TDeskCore_TUIGroupService @"TDeskCore_TUIGroupService"
#define TDeskCore_TUIGroupService_Minimalist @"TDeskCore_TUIGroupService_Minimalist"

#define TDeskCore_TUIGroupService_CreateGroupMethod @"TDeskCore_TUIGroupService_CreateGroupMethod"
#define TDeskCore_TUIGroupService_CreateGroupMethod_GroupTypeKey @"TDeskCore_TUIGroupService_CreateGroupMethod_GroupTypeKey"
#define TDeskCore_TUIGroupService_CreateGroupMethod_OptionKey @"TDeskCore_TUIGroupService_CreateGroupMethod_OptionKey"
#define TDeskCore_TUIGroupService_CreateGroupMethod_ContactsKey @"TDeskCore_TUIGroupService_CreateGroupMethod_ContactsKey"
#define TDeskCore_TUIGroupService_CreateGroupMethod_CompletionKey @"TDeskCore_TUIGroupService_CreateGroupMethod_CompletionKey"

#pragma mark - TDeskCore_TUIGroup_Notify
#define TDeskCore_TUIGroupNotify @"TDeskCore_TUIContactNotify"

#define TDeskCore_TUIGroupNotify_UpdateConversationBackgroundImageSubKey @"TDeskCore_TUIGroupNotify_UpdateConversationBackgroundImageSubKey"
#define TDeskCore_TUIGroupNotify_UpdateConversationBackgroundImageSubKey_ConversationID \
    @"TDeskCore_TUIGroupNotify_UpdateConversationBackgroundImageSubKey_ConversationID"

#pragma mark - TDeskCore_TUIGroup_Extension
// UI extension for the action menus in the group infomation page
#define TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_MinimalistExtensionID @"TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_MinimalistExtensionID"
#define TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_GroupID @"TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_GroupID"
#define TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_FilterVideoCall @"TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_FilterVideoCall"
#define TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_FilterAudioCall @"TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_FilterAudioCall"
#define TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_PushVC @"TDeskCore_TUIGroupExtension_GroupInfoCardActionMenu_PushVC"

#pragma mark - TDeskCore_TUIGroup_ObjectFactory
#define TDeskCore_TUIGroupObjectFactory @"TDeskCore_TUIGroupObjectFactory"
#define TDeskCore_TUIGroupObjectFactory_Minimalist @"TDeskCore_TUIGroupObjectFactory_Minimalist"

#define TDeskCore_TUIGroupObjectFactory_GetGroupRequestViewControllerMethod @"TDeskCore_TUIGroupObjectFactory_GetGroupRequestViewControllerMethod"
#define TDeskCore_TUIGroupObjectFactory_GetGroupRequestViewControllerMethod_GroupInfoKey \
    @"TDeskCore_TUIGroupObjectFactory_GetGroupRequestViewControllerMethod_GroupInfoKey"

#pragma mark - TDeskCore_TUIGroup_ObjectFactory_Route
// Route to the page for selecting group member
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_Classic @"TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_Classic"
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_Minimalist @"TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_Minimalist"
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_GroupID @"TDeskCore_TUIGroupService_GetSelectGroupMemberViewControllerMethod"
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_Name @"TDeskCore_TUIGroupService_GetSelectGroupMemberViewControllerMethod_NameKey"
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_OptionalStyle @"TDeskCore_TUIGroupService_GetSelectGroupMemberViewControllerMethod_optionalStyleKey"
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_SelectedUserIDList \
    @"TDeskCore_TUIGroupService_GetSelectGroupMemberViewControllerMethod_SelectedUserIDListKey"
#define TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_ResultUserList @"TDeskCore_TUIGroupObjectFactory_SelectGroupMemberVC_ResultUserList"

// Route to group info page
#define TDeskCore_TUIGroupObjectFactory_GetGroupInfoVC_Classic @"TDeskCore_TUIGroupObjectFactory_GetGroupInfoVC_Classic"
#define TDeskCore_TUIGroupObjectFactory_GetGroupInfoVC_Minimalist @"TDeskCore_TUIGroupObjectFactory_GetGroupInfoVC_Minimalist"
#define TDeskCore_TUIGroupObjectFactory_GetGroupInfoVC_GroupID @"TDeskCore_TUIGroupObjectFactory_GetGroupInfoVC_GroupID"

#pragma mark - TDeskCore_TUICallKit_TUICallingService
#define TDeskCore_TUICallingService @"TDeskCore_TUICallingService"

#define TDeskCore_TUICallingService_ShowCallingViewMethod @"TDeskCore_TUICallingService_ShowCallingViewMethod"

#define TDeskCore_TUICallingService_ShowCallingViewMethod_GroupIDKey @"TDeskCore_TUICallingService_ShowCallingViewMethod_GroupIDKey"
#define TDeskCore_TUICallingService_ShowCallingViewMethod_UserIDsKey @"TDeskCore_TUICallingService_ShowCallingViewMethod_UserIDsKey"
#define TDeskCore_TUICallingService_ShowCallingViewMethod_CallTypeKey @"TDeskCore_TUICallingService_ShowCallingViewMethod_CallTypeKey"

#define TDeskCore_TUICallingService_ReceivePushCallingMethod @"TDeskCore_TUICallingService_ReceivePushCallingMethod"
#define TDeskCore_TUICallingService_ShowCallingViewMethod_SignalingInfo @"TDeskCore_TUICallingService_ShowCallingViewMethod_SignalingInfo"

#define TDeskCore_TUICallingService_EnableMultiDeviceAbilityMethod @"TDeskCore_TUICallingService_EnableMultiDeviceAbilityMethod"
#define TDeskCore_TUICallingService_EnableMultiDeviceAbilityMethod_EnableMultiDeviceAbility \
    @"TDeskCore_TUICallingService_EnableMultiDeviceAbilityMethod_EnableMultiDeviceAbility"

#define TDeskCore_TUICallingService_EnableFloatWindowMethod @"TDeskCore_TUICallingService_EnableFloatWindowMethod"
#define TDeskCore_TUICallingService_EnableFloatWindowMethod_EnableFloatWindow @"TDeskCore_TUICallingService_EnableFloatWindowMethod_EnableFloatWindow"

#define TDeskCore_TUICallingService_SetAudioPlaybackDeviceMethod @"TDeskCore_TUICallingService_SetAudioPlaybackDeviceMethod"
#define TDeskCore_TUICallingService_SetAudioPlaybackDevice_AudioPlaybackDevice @"TDeskCore_TUICallingService_SetAudioPlaybackDevice_AudioPlaybackDevice"
#define TDeskCore_TUICallingService_SetIsMicMuteMethod @"TDeskCore_TUICallingService_SetIsMicMuteMethod"
#define TDeskCore_TUICallingService_SetIsMicMuteMethod_IsMicMute @"TDeskCore_TUICallingService_SetIsMicMuteMethod_IsMicMute"

#pragma mark - TDeskCore_TUICallKit_TUIAudioMessageRecordService
#define TDeskCore_TUIAudioMessageRecordService @"TUIAudioMessageRecordService"
#define TDeskCore_TUIAudioMessageRecordService_StartRecordAudioMessageMethod @"TDeskCore_TUIAudioMessageRecordService_StartRecordAudioMessageMethod"
#define TDeskCore_TUIAudioMessageRecordService_StopRecordAudioMessageMethod @"TDeskCore_TUIAudioMessageRecordService_StopRecordAudioMessageMethod"

#define TDeskCore_TUIAudioMessageRecordService_StartRecordAudioMessageMethod_SdkappidKey @"sdkappid"
#define TDeskCore_TUIAudioMessageRecordService_StartRecordAudioMessageMethod_SignatureKey @"signature"
#define TDeskCore_TUIAudioMessageRecordService_StartRecordAudioMessageMethod_PathKey @"path"

#pragma mark - TDeskCore_TUICallKit_TUICallingNotify
#define TDeskCore_RecordAudioMessageNotify @"TDeskCore_RecordAudioMessageNotify"
#define TDeskCore_RecordAudioMessageNotify_StartRecordAudioMessageSubKey @"TDeskCore_RecordAudioMessageNotify_StartRecordAudioMessageSubKey"
#define TDeskCore_RecordAudioMessageNotify_StopRecordAudioMessageSubKey @"TDeskCore_RecordAudioMessageNotify_StopRecordAudioMessageSubKey"

#define TDeskCore_RecordAudioMessageNotify_RecordAudioVoiceVolumeSubKey @"TDeskCore_RecordAudioMessageNotify_RecordAudioVoiceVolumeSubKey"
#define TDeskCore_RecordAudioMessageNotify_RecordAudioVoiceVolumeSubKey_VolumeKey @"volume"

#pragma mark - TDeskCore_TUICallKit_TUICallingObjectFactory
#define TDeskCore_TUICallingObjectFactory @"TDeskCore_TUICallingObjectFactory"

// Get the view controler for displaying call history
#define TDeskCore_TUICallingObjectFactory_RecordCallsVC @"TDeskCore_TUICallingObjectFactory_RecordCallsVC"
#define TDeskCore_TUICallingObjectFactory_RecordCallsVC_UIStyle @"TDeskCore_TUICallingObjectFactory_RecordCallsVC_UIStyle"
#define TDeskCore_TUICallingObjectFactory_RecordCallsVC_UIStyle_Classic @"TDeskCore_TUICallingObjectFactory_RecordCallsVC_UIStyle_Classic"
#define TDeskCore_TUICallingObjectFactory_RecordCallsVC_UIStyle_Minimalist @"TDeskCore_TUICallingObjectFactory_RecordCallsVC_UIStyle_Minimalist"

#pragma mark - TDeskCore_TUIPlugin_Notify
#define TDeskCore_TUIPluginNotify @"TDeskCore_TUIPluginNotify"
#define TDeskCore_TUIPluginNotify_PluginCustomCellClick @"TDeskCore_TUIPluginNotify_PluginCustomCellClick"
#define TDeskCore_TUIPluginNotify_PluginCustomCellClick_PushVC @"TDeskCore_TUIPluginNotify_PluginCustomCellClick_PushVC"
#define TDeskCore_TUIPluginNotify_PluginCustomCellClick_Cell @"TDeskCore_TUIPluginNotify_PluginCustomCellClick_Cell"

#define TDeskCore_TUIPluginNotify_PluginViewSizeChangedSubKey @"TDeskCore_TUIPluginNotify_PluginViewSizeChangedSubKey"
#define TDeskCore_TUIPluginNotify_PluginViewSizeChangedSubKey_Message @"TDeskCore_TUIPluginNotify_PluginViewSizeChangedSubKey_Message"

#define TDeskCore_TUIPluginNotify_PluginViewDidAddToSuperview @"TDeskCore_TUIPluginNotify_PluginViewDidAddToSuperview"
#define TDeskCore_TUIPluginNotify_PluginViewDidAddToSuperviewSubKey_PluginViewHeight @"TDeskCore_TUIPluginNotify_PluginViewDidAddToSuperviewSubKey_PluginViewHeight"

#define TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey @"TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey"
#define TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey_Data @"TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey_Data"
#define TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey_VC @"TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey_VC"
#define TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey_isAllowScroll2Bottom @"TDeskCore_TUIPluginNotify_DidChangePluginViewSubKey_isAllowScroll2Bottom"

#define TDeskCore_TUIPluginNotify_WillForwardTextSubKey @"TDeskCore_TUIPluginNotify_WillForwardTextSubKey"
#define TDeskCore_TUIPluginNotify_WillForwardTextSubKey_Text @"TDeskCore_TUIPluginNotify_WillForwardTextSubKey_Text"

// Initialization and recording successful, recording successful
#define TDeskCore_RecordAudioMessageNotifyError_None 0
// Parameter is empty
#define TDeskCore_RecordAudioMessageNotifyError_InvalidParam -1001
// Recording rejected, currently on a call
#define TDeskCore_RecordAudioMessageNotifyError_StatusInCall -1002
// The recording was rejected and the current recording has not ended.
#define TDeskCore_RecordAudioMessageNotifyError_StatusIsAudioRecording -1003
// Recording rejected, failed to obtain microphone permission
#define TDeskCore_RecordAudioMessageNotifyError_MicPermissionRefused -1004
// Recording rejected, failed to obtain audio focus
#define TDeskCore_RecordAudioMessageNotifyError_RequestAudioFocusFailed -1005

// -1, failed to initialize recording (onLocalRecordBegin)
#define TDeskCore_RecordAudioMessageNotifyError_RecordInitFailed -2001
// -2, wrong file extension (onLocalRecordBegin)
#define TDeskCore_RecordAudioMessageNotifyError_PathFormatNotSupport -2002
// -1, recording failed
#define TDeskCore_RecordAudioMessageNotifyError_RecordFailed -2003
// -3, the audio data or video data has not arrived and the formal recording has not started.
#define TDeskCore_RecordAudioMessageNotifyError_NoMessageToRecord -2004

// -4, signature error (onLocalRecordBegin)
#define TDeskCore_RecordAudioMessageNotifyError_SignatureError -3001
// -5, signature expired (onLocalRecordBegin)
#define TDeskCore_RecordAudioMessageNotifyError_SignatureExpired -3002

// Failed to open the microphone. For example, on Windows or Mac devices, the microphone configuration program (driver) is abnormal. Disable and then re-enable the device, or restart the machine, or update the configuration program.
#define TDeskCore_RecordAudioMessageNotifyError_MicStartFail -1302
// The microphone device is not authorized. It usually appears on mobile devices. The permission may be denied by the user.
#define TDeskCore_RecordAudioMessageNotifyError_MicNotAuthorized -1317
// Microphone setting parameters failed
#define TDeskCore_RecordAudioMessageNotifyError_MicSetParamFail -1318
// The microphone is occupied. For example, when the mobile device is making a call, opening the microphone will fail.
#define TDeskCore_RecordAudioMessageNotifyError_MicOccupy -1319

#pragma mark - TDeskCore_TUIGiftExtension
#define TDeskCore_TUIGiftExtension_GetEnterBtn @"TDeskCore_TUIGiftExtension_GetEnterBtn"
#define TDeskCore_TUIGiftExtension_GetLikeBtn @"TDeskCore_TUIGiftExtension_GetLikeBtn"
#define TDeskCore_TUIGiftExtension_GetTUIGiftListPanel @"TDeskCore_TUIGiftExtension_GetTUIGiftListPanel"
#define TDeskCore_TUIGiftExtension_GetTUIGiftPlayView @"TDeskCore_TUIGiftExtension_GetTUIGiftPlayView"

#pragma mark - TDeskCore_TUIGiftService
#define TDeskCore_TUIGiftService @"TDeskCore_TUIGiftService"
#define TDeskCore_TUIGiftService_SendLikeMethod @"TDeskCore_TUIGiftService_SendLikeMethod"

#pragma mark - TDeskCore_TUIBarrageExtension
#define TDeskCore_TUIBarrageExtension_GetEnterBtn @"TDeskCore_TUIBarrageExtension_GetEnterBtn"
#define TDeskCore_TUIBarrageExtension_GetTUIBarrageSendView @"TDeskCore_TUIBarrageExtension_GetTUIBarrageSendView"
#define TDeskCore_TUIBarrageExtension_TUIBarrageDisplayView @"TDeskCore_TUIBarrageExtension_GetTUIBarrageDisplayView"

#pragma mark - TDeskCore_TUIBeautyExtension
#define TDeskCore_TUIBeautyExtension_BeautyView @"TDeskCore_TUIBeautyExtension_BeautyView"
#define TDeskCore_TUIBeautyExtension_Extension @"TDeskCore_TUIBeautyExtension_Extension"

#define TDeskCore_TUIBeautyExtension_BeautyView_View @"TDeskCore_TUIBeautyExtension_BeautyView_View"
#define TDeskCore_TUIBeautyExtension_Extension_View @"TDeskCore_TUIBeautyExtension_Extension_View"

#define TDeskCore_TUIBeautyExtension_BeautyView_BeautyManager @"TDeskCore_TUIBeautyExtension_BeautyView_BeautyManager"
#define TDeskCore_TUIBeautyExtension_BeautyView_LicenseUrl @"TDeskCore_TUIBeautyExtension_BeautyView_LicenseUrl"
#define TDeskCore_TUIBeautyExtension_BeautyView_LicenseKey @"TDeskCore_TUIBeautyExtension_BeautyView_LicenseKey"
#define TDeskCore_TUIBeautyExtension_BeautyView_DataProcessDelegate @"TDeskCore_TUIBeautyExtension_BeautyView_DataProcessDelegate"

#pragma mark - TDeskCore_TUIBeautyService
#define TDeskCore_TUIBeautyService @"TDeskCore_TUIBeautyService"
#define TDeskCore_TUIBeautyService_SetLicense @"TDeskCore_TUIBeautyService_SetLicense"
#define TDeskCore_TUIBeautyService_ProcessVideoFrame @"TDeskCore_TUIBeautyService_ProcessVideoFrame"
#define TDeskCore_TUIBeautyService_ProcessVideoFrame_SRCTextureIdKey @"TDeskCore_TUIBeautyService_ProcessVideoFrame_SRCTextureIdKey"
#define TDeskCore_TUIBeautyService_ProcessVideoFrame_SRCFrameWidthKey @"TDeskCore_TUIBeautyService_ProcessVideoFrame_SRCFrameWidthKey"
#define TDeskCore_TUIBeautyService_ProcessVideoFrame_SRCFrameHeightKey @"TDeskCore_TUIBeautyService_ProcessVideoFrame_SRCFrameHeightKey"

#pragma mark - TDeskCore_TUIAudioEffectViewExtension
#define TDeskCore_TUIAudioEffectViewExtension_AudioEffectView @"TDeskCore_TUIAudioEffectViewExtension_AudioEffectView"
#define TDeskCore_TUIAudioEffectViewExtension_Extension @"TDeskCore_TUIAudioEffectViewExtension_Extension"

#define TDeskCore_TUIAudioEffectViewExtension_AudioEffectView_View @"TDeskCore_TUIAudioEffectViewExtension_AudioEffectView_View"
#define TDeskCore_TUIAudioEffectViewExtension_Extension_View @"TDeskCore_TUIAudioEffectViewExtension_Extension_View"

#define TDeskCore_TUIAudioEffectViewExtension_AudioEffectView_AudioEffectManager @"TDeskCore_TUIAudioEffectViewExtension_AudioEffectView_AudioEffectManager"

#pragma mark - TDeskCore_NetworkConnection_EVENT
#define TDeskCore_NetworkConnection_EVENT_CONNECTION_STATE_CHANGED @"eventConnectionStateChanged"
#define TDeskCore_NetworkConnection_EVENT_SUB_KEY_CONNECTING @"eventSubKeyConnecting"
#define TDeskCore_NetworkConnection_EVENT_SUB_KEY_CONNECT_SUCCESS @"eventSubKeyConnectSuccess"
#define TDeskCore_NetworkConnection_EVENT_SUB_KEY_CONNECT_FAILED @"eventSubKeyConnectFailed"

#pragma mark - TDeskCore_TUIRoomImAccessService
#define TDeskCore_TUIRoomImAccessService @"TDeskCore_TUIRoomImAccessService"
#define TDeskCore_TUIRoomImAccessService_EnableFloatWindowMethod @"TDeskCore_TUIRoomImAccessService_EnableFloatWindowMethod"
#define TDeskCore_TUIRoomImAccessService_EnableFloatWindowMethod_EnableFloatWindow @"TDeskCore_TUIRoomImAccessService_EnableFloatWindowMethod_EnableFloatWindow"

#pragma mark - TDeskCore_TUIRoomImAccessFactory
#define TDeskCore_TUIRoomImAccessFactory @"TDeskCore_TUIRoomImAccessFactory"
#define TDeskCore_TUIRoomImAccessFactory_GetRoomMessageViewMethod @"TDeskCore_TUIRoomImAccessFactory_GetRoomMessageViewMethod"
#define TDeskCore_TUIRoomImAccessFactory_GetRoomMessageViewMethod_Message @"TDeskCore_TUIRoomImAccessFactory_GetRoomMessageViewMethod_Message"

#pragma mark - TDeskCore_PrivacyService_ScreenShareAntifraudReminderService
#define TDeskCore_PrivacyService @"TDeskCore_PrivacyService"
#define TDeskCore_PrivacyService_ScreenShareAntifraudReminderMethod @"TDeskCore_PrivacyService_ScreenShareAntifraudReminderMethod"
#define TDeskCore_PrivacyService_EnableScreenShareAntifraudReminderMethod_Cancel -1
#define TDeskCore_PrivacyService_EnableScreenShareAntifraudReminderMethod_Continue 0

#define TDeskCore_PrivacyService_CallKitAntifraudReminderMethod @"TDeskCore_PrivacyService_CallKitAntifraudReminderMethod"

#pragma mark - TDeskCore_PrivacyService_COMMUNICATION_EVENT
#define TDeskCore_PrivacyService_ROOM_STATE_EVENT_CHANGED @"eventRoomStateChanged"
#define TDeskCore_PrivacyService_ROOM_STATE_EVENT_SUB_KEY_START @"eventSubKeyStart"
#define TDeskCore_PrivacyService_ROOM_STATE_EVENT_SUB_KEY_END @"eventSubKeyEnd"

#pragma mark - TDeskCore_TUICallKitVoIPExtension_Notify
#define TDeskCore_TUICallKitVoIPExtensionNotify @"TDeskCore_TUICallKitVoIPExtension_Notify"
#define TDeskCore_TUICore_TUICallKitVoIPExtensionNotify_OpenMicrophoneSubKey @"TDeskCore_TUICore_TUICallKitVoIPExtensionNotify_OpenMicrophoneSubKey"
#define TDeskCore_TUICore_TUICallKitVoIPExtensionNotify_CloseMicrophoneSubKey @"TDeskCore_TUICore_TUICallKitVoIPExtensionNotify_CloseMicrophoneSubKey"

/////////////////////////////////////////////////////////////////////////////////
//
//            TDeskOfflinePush
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * Set certificate IDs for VoIP
 */
#define TDeskOfflinePushCertificateIDForVoIP(value) \
    -(int)push_certificateIDForVoIP {             \
        return value;                             \
    }

/**
 * Set certificate IDs for APNs
 */
#define TDeskOfflinePushCertificateIDForAPNS(value) \
    -(int)push_certificateIDForAPNS {             \
        return value;                             \
    }

/**
 * Set TPNS configuration information
 */
#define TDeskOfflinePushConfigForTPNS(access_id, access_key, tpn_domain)                                       \
    -(void)push_accessID : (int *)accessID accessKey : (NSString **)accessKey domain : (NSString **)domain { \
        *accessID = access_id;                                                                               \
        *accessKey = access_key;                                                                             \
        *domain = tpn_domain;                                                                                \
    }

#endif /* THeader_h */

