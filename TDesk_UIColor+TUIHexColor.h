//
//  UIColor+TUIHexColor.h
//  TDeskCore
//
//  Created by gg on 2021/10/9.
//  Copyright © 2023 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (TUIHexColor)

+ (UIColor *)tdesk_colorWithHex:(NSString *)hex;

+ (UIColor *)tdesk_colorWithHex:(NSString *)hex alpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
