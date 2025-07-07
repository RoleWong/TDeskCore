//
//  THelper.m
//  TUIKit
//
//  Created by kennethmiao on 2018/11/1.
//  Copyright © 2018 Tencent. All rights reserved.
//

#import <SDWebImage/SDImageCoderHelper.h>
#import "TDesk_TUILogin.h"
#import "TDesk_TUIGlobalization.h"
#import "TDesk_TUIWeakProxy.h"
#import "TDesk_TUIDefine.h"
#import "TDesk_UIView+TUIToast.h"

@import ImSDK_Plus;

@implementation TDeskTool

static NSMutableDictionary * gIMErrorMsgMap = nil;

+ (void)initialize {
    [self setupIMErrorMap];
}
+ (void)configIMErrorMap {
    [self.class setupIMErrorMap];
}
+ (void)setupIMErrorMap {
    NSMutableDictionary *map = [NSMutableDictionary dictionary];
    gIMErrorMsgMap = map;
    
    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      （1）IM SDK
    //
    /////////////////////////////////////////////////////////////////////////////////

    //General error code
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInProcess) forKey:@(ERR_IN_PROGESS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInvalidParameters) forKey:@(ERR_INVALID_PARAMETERS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorIOOperateFaild) forKey:@(ERR_IO_OPERATION_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInvalidJson) forKey:@(ERR_INVALID_JSON)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorOutOfMemory) forKey:@(ERR_OUT_OF_MEMORY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorParseResponseFaild) forKey:@(ERR_PARSE_RESPONSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSerializeReqFaild) forKey:@(ERR_SERIALIZE_REQ_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNotInit) forKey:@(ERR_SDK_NOT_INITIALIZED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoadMsgFailed) forKey:@(ERR_LOADMSG_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorDatabaseOperateFailed) forKey:@(ERR_DATABASE_OPERATE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorCrossThread) forKey:@(ERR_SDK_COMM_CROSS_THREAD)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTinyIdEmpty) forKey:@(ERR_SDK_COMM_TINYID_EMPTY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInvalidIdentifier) forKey:@(ERR_SDK_COMM_INVALID_IDENTIFIER)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileNotFound) forKey:@(ERR_SDK_COMM_FILE_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileTooLarge) forKey:@(ERR_SDK_COMM_FILE_TOO_LARGE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorEmptyFile) forKey:@(ERR_SDK_COMM_FILE_SIZE_EMPTY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileOpenFailed) forKey:@(ERR_SDK_COMM_FILE_OPEN_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorUnsupporInterface) forKey:@(ERR_SDK_INTERFACE_NOT_SUPPORT)];
    
    // Account
    [map setObject:TDeskKitLocalizableString(TUIKitErrorNotLogin) forKey:@(ERR_SDK_NOT_LOGGED_IN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorNoPreviousLogin) forKey:@(ERR_NO_PREVIOUS_LOGIN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorUserSigExpired) forKey:@(ERR_USER_SIG_EXPIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginKickedOffByOther) forKey:@(ERR_LOGIN_KICKED_OFF_BY_OTHER)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKInit) forKey:@(ERR_SDK_ACCOUNT_TLS_INIT_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKUninit) forKey:@(ERR_SDK_ACCOUNT_TLS_NOT_INITIALIZED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKTRANSPackageFormat) forKey:@(ERR_SDK_ACCOUNT_TLS_TRANSPKG_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSDecrypt) forKey:@(ERR_SDK_ACCOUNT_TLS_DECRYPT_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKRequest) forKey:@(ERR_SDK_ACCOUNT_TLS_REQUEST_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKRequestTimeout) forKey:@(ERR_SDK_ACCOUNT_TLS_REQUEST_TIMEOUT)];
    
    // Message
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInvalidConveration) forKey:@(ERR_INVALID_CONVERSATION)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileTransAuthFailed) forKey:@(ERR_FILE_TRANS_AUTH_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileTransNoServer) forKey:@(ERR_FILE_TRANS_NO_SERVER)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileTransUploadFailed) forKey:@(ERR_FILE_TRANS_UPLOAD_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileTransUploadFailedNotImage) forKey:@(ERR_IMAGE_UPLOAD_FAILED_NOTIMAGE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFileTransDownloadFailed) forKey:@(ERR_FILE_TRANS_DOWNLOAD_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorHTTPRequestFailed) forKey:@(ERR_HTTP_REQ_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInvalidMsgElem) forKey:@(ERR_INVALID_MSG_ELEM)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorInvalidSDKObject) forKey:@(ERR_INVALID_SDK_OBJECT)];
    [map setObject:TDeskKitLocalizableString(TUIKitSDKMsgBodySizeLimit) forKey:@(ERR_SDK_MSG_BODY_SIZE_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKMsgKeyReqDifferRsp) forKey:@(ERR_SDK_MSG_KEY_REQ_DIFFER_RSP)];
    
    // Group
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInvalidID) forKey:@(ERR_SDK_GROUP_INVALID_ID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInvalidName) forKey:@(ERR_SDK_GROUP_INVALID_NAME)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInvalidIntroduction) forKey:@(ERR_SDK_GROUP_INVALID_INTRODUCTION)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInvalidNotification) forKey:@(ERR_SDK_GROUP_INVALID_NOTIFICATION)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInvalidFaceURL) forKey:@(ERR_SDK_GROUP_INVALID_FACE_URL)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInvalidNameCard) forKey:@(ERR_SDK_GROUP_INVALID_NAME_CARD)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupMemberCountLimit) forKey:@(ERR_SDK_GROUP_MEMBER_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupJoinPrivateGroupDeny) forKey:@(ERR_SDK_GROUP_JOIN_PRIVATE_GROUP_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInviteSuperDeny) forKey:@(ERR_SDK_GROUP_INVITE_SUPER_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKGroupInviteNoMember) forKey:@(ERR_SDK_GROUP_INVITE_NO_MEMBER)];
    
    // Relationship
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKFriendShipInvalidProfileKey) forKey:@(ERR_SDK_FRIENDSHIP_INVALID_PROFILE_KEY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKFriendshipInvalidAddRemark) forKey:@(ERR_SDK_FRIENDSHIP_INVALID_ADD_REMARK)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKFriendshipInvalidAddWording) forKey:@(ERR_SDK_FRIENDSHIP_INVALID_ADD_WORDING)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKFriendshipInvalidAddSource) forKey:@(ERR_SDK_FRIENDSHIP_INVALID_ADD_SOURCE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKFriendshipFriendGroupEmpty) forKey:@(ERR_SDK_FRIENDSHIP_FRIEND_GROUP_EMPTY)];
    
    // Network
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetEncodeFailed) forKey:@(ERR_SDK_NET_ENCODE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetDecodeFailed) forKey:@(ERR_SDK_NET_DECODE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetAuthInvalid) forKey:@(ERR_SDK_NET_AUTH_INVALID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetCompressFailed) forKey:@(ERR_SDK_NET_COMPRESS_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetUncompressFaile) forKey:@(ERR_SDK_NET_UNCOMPRESS_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetFreqLimit) forKey:@(ERR_SDK_NET_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKnetReqCountLimit) forKey:@(ERR_SDK_NET_REQ_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetDisconnect) forKey:@(ERR_SDK_NET_DISCONNECT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetAllreadyConn) forKey:@(ERR_SDK_NET_ALLREADY_CONN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetConnTimeout) forKey:@(ERR_SDK_NET_CONN_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetConnRefuse) forKey:@(ERR_SDK_NET_CONN_REFUSE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetNetUnreach) forKey:@(ERR_SDK_NET_NET_UNREACH)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetSocketNoBuff) forKey:@(ERR_SDK_NET_SOCKET_NO_BUFF)];
    [map setObject:TDeskKitLocalizableString(TUIKitERRORSDKNetResetByPeer) forKey:@(ERR_SDK_NET_RESET_BY_PEER)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetSOcketInvalid) forKey:@(ERR_SDK_NET_SOCKET_INVALID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetHostGetAddressFailed) forKey:@(ERR_SDK_NET_HOST_GETADDRINFO_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetConnectReset) forKey:@(ERR_SDK_NET_CONNECT_RESET)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetWaitInQueueTimeout) forKey:@(ERR_SDK_NET_WAIT_INQUEUE_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetWaitSendTimeout) forKey:@(ERR_SDK_NET_WAIT_SEND_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetWaitAckTimeut) forKey:@(ERR_SDK_NET_WAIT_ACK_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKWaitSendRemainingTimeout) forKey:@(ERR_SDK_NET_WAIT_SEND_REMAINING_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetPKGSizeLimit) 
            forKey:@(ERR_SDK_NET_PKG_SIZE_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetWaitSendTimeoutNoNetwork) forKey:@(ERR_SDK_NET_WAIT_SEND_TIMEOUT_NO_NETWORK)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetWaitAckTimeoutNoNetwork) forKey:@(ERR_SDK_NET_WAIT_ACK_TIMEOUT_NO_NETWORK)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKNetRemainingTimeoutNoNetwork) forKey:@(ERR_SDK_NET_SEND_REMAINING_TIMEOUT_NO_NETWORK)];

    
    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      （2）Server
    //
    /////////////////////////////////////////////////////////////////////////////////

    // SSO
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKSVRSSOConnectLimit) forKey:@(ERR_SVR_SSO_CONNECT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKSVRSSOVCode) forKey:@(ERR_SVR_SSO_VCODE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOEmpeyKey) forKey:@(ERR_SVR_SSO_EMPTY_KEY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOUinInvalid) forKey:@(ERR_SVR_SSO_UIN_INVALID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOVCodeTimeout) forKey:@(ERR_SVR_SSO_VCODE_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOCookieInvalid) forKey:@(ERR_SVR_SSO_COOKIE_INVALID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSODownTips) forKey:@(ERR_SVR_SSO_DOWN_TIP)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSODisconnect) forKey:@(ERR_SVR_SSO_DISCONNECT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOIdentifierInvalid) forKey:@(ERR_SVR_SSO_IDENTIFIER_INVALID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOClientClose) forKey:@(ERR_SVR_SSO_CLIENT_CLOSE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOMSFSDKQuit) forKey:@(ERR_SVR_SSO_MSFSDK_QUIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOUnsupport) forKey:@(ERR_SVR_SSO_UNSURPPORT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOPrepaidArrears) forKey:@(ERR_SVR_SSO_PREPAID_ARREARS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOPacketWrong) forKey:@(ERR_SVR_SSO_PACKET_WRONG)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOAppidBlackList) forKey:@(ERR_SVR_SSO_APPID_BLACK_LIST)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOCmdBlackList) forKey:@(ERR_SVR_SSO_CMD_BLACK_LIST)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOAppidWithoutUsing) forKey:@(ERR_SVR_SSO_APPID_WITHOUT_USING)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOFreqLimit) forKey:@(ERR_SVR_SSO_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRSSOOverload) forKey:@(ERR_SVR_SSO_OVERLOAD)];
    
    // Resource
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResNotFound) forKey:@(ERR_SVR_RES_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResAccessDeny) forKey:@(ERR_SVR_RES_ACCESS_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResSizeLimit) forKey:@(ERR_SVR_RES_SIZE_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResSendCancel) forKey:@(ERR_SVR_RES_SEND_CANCEL)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResReadFailed) forKey:@(ERR_SVR_RES_READ_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResTransferTimeout) forKey:@(ERR_SVR_RES_TRANSFER_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResInvalidParameters) forKey:@(ERR_SVR_RES_INVALID_PARAMETERS)];
    
    // Common
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidHttpUrl) forKey:@(ERR_SVR_COMM_INVALID_HTTP_URL)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommomReqJsonParseFailed) forKey:@(ERR_SVR_COMM_REQ_JSON_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidAccount) forKey:@(ERR_SVR_COMM_INVALID_ACCOUNT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidAccount) forKey:@(ERR_SVR_COMM_INVALID_ACCOUNT_EX)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidSdkappid) forKey:@(ERR_SVR_COMM_INVALID_SDKAPPID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonRestFreqLimit) forKey:@(ERR_SVR_COMM_REST_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonRequestTimeout) forKey:@(ERR_SVR_COMM_REQUEST_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidRes) forKey:@(ERR_SVR_COMM_INVALID_RES)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonIDNotAdmin) forKey:@(ERR_SVR_COMM_ID_NOT_ADMIN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonSdkappidFreqLimit) forKey:@(ERR_SVR_COMM_SDKAPPID_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonSdkappidMiss) forKey:@(ERR_SVR_COMM_SDKAPPID_MISS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonRspJsonParseFailed) forKey:@(ERR_SVR_COMM_RSP_JSON_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonExchangeAccountTimeout) forKey:@(ERR_SVR_COMM_EXCHANGE_ACCOUNT_TIMEUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidIdFormat) forKey:@(ERR_SVR_COMM_INVALID_ID_FORMAT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonSDkappidForbidden) forKey:@(ERR_SVR_COMM_SDKAPPID_FORBIDDEN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonReqForbidden) forKey:@(ERR_SVR_COMM_REQ_FORBIDDEN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonReqFreqLimit) forKey:@(ERR_SVR_COMM_REQ_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonReqFreqLimit) forKey:@(ERR_SVR_COMM_REQ_FREQ_LIMIT_EX)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonInvalidService) forKey:@(ERR_SVR_COMM_INVALID_SERVICE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonSensitiveText) forKey:@(ERR_SVR_COMM_SENSITIVE_TEXT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRCommonBodySizeLimit) forKey:@(ERR_SVR_COMM_BODY_SIZE_LIMIT)];
    
    // Account
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigExpired) forKey:@(ERR_SVR_ACCOUNT_USERSIG_EXPIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigEmpty) forKey:@(ERR_SVR_ACCOUNT_USERSIG_EMPTY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigCheckFailed) forKey:@(ERR_SVR_ACCOUNT_USERSIG_CHECK_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigCheckFailed) forKey:@(ERR_SVR_ACCOUNT_USERSIG_CHECK_FAILED_EX)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigMismatchPublicKey) forKey:@(ERR_SVR_ACCOUNT_USERSIG_MISMATCH_PUBLICKEY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigMismatchId) forKey:@(ERR_SVR_ACCOUNT_USERSIG_MISMATCH_ID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigMismatchSdkAppid) forKey:@(ERR_SVR_ACCOUNT_USERSIG_MISMATCH_SDKAPPID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigPublicKeyNotFound) forKey:@(ERR_SVR_ACCOUNT_USERSIG_PUBLICKEY_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountUserSigSdkAppidNotFount) forKey:@(ERR_SVR_ACCOUNT_SDKAPPID_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInvalidUserSig) forKey:@(ERR_SVR_ACCOUNT_INVALID_USERSIG)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountNotFound) forKey:@(ERR_SVR_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountSecRstr) forKey:@(ERR_SVR_ACCOUNT_SEC_RSTR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInternalTimeout) forKey:@(ERR_SVR_ACCOUNT_INTERNAL_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInvalidCount) forKey:@(ERR_SVR_ACCOUNT_INVALID_COUNT)];
    [map setObject:TDeskKitLocalizableString(TUIkitErrorSVRAccountINvalidParameters) forKey:@(ERR_SVR_ACCOUNT_INVALID_PARAMETERS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountAdminRequired) forKey:@(ERR_SVR_ACCOUNT_ADMIN_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountLowSDKVersion) forKey:@(ERR_SVR_ACCOUNT_LOW_SDK_VERSION)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountFreqLimit) forKey:@(ERR_SVR_ACCOUNT_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountBlackList) forKey:@(ERR_SVR_ACCOUNT_BLACKLIST)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountCountLimit) forKey:@(ERR_SVR_ACCOUNT_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInternalError) forKey:@(ERR_SVR_ACCOUNT_INTERNAL_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorEnableUserStatusOnConsole) forKey:@(ERR_SVR_ACCOUNT_USER_STATUS_DISABLED)];
    
    // Profile
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileInvalidParameters) forKey:@(ERR_SVR_PROFILE_INVALID_PARAMETERS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileAccountMiss) forKey:@(ERR_SVR_PROFILE_ACCOUNT_MISS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileAccountNotFound) forKey:@(ERR_SVR_PROFILE_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileAdminRequired) forKey:@(ERR_SVR_PROFILE_ADMIN_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileSensitiveText) forKey:@(ERR_SVR_PROFILE_SENSITIVE_TEXT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileInternalError) forKey:@(ERR_SVR_PROFILE_INTERNAL_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileReadWritePermissionRequired) forKey:@(ERR_SVR_PROFILE_READ_PERMISSION_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileReadWritePermissionRequired) forKey:@(ERR_SVR_PROFILE_WRITE_PERMISSION_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileTagNotFound) forKey:@(ERR_SVR_PROFILE_TAG_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileSizeLimit) forKey:@(ERR_SVR_PROFILE_SIZE_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileValueError) forKey:@(ERR_SVR_PROFILE_VALUE_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRProfileInvalidValueFormat) forKey:@(ERR_SVR_PROFILE_INVALID_VALUE_FORMAT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipInvalidParameters) forKey:@(ERR_SVR_FRIENDSHIP_INVALID_PARAMETERS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipInvalidSdkAppid) forKey:@(ERR_SVR_FRIENDSHIP_INVALID_SDKAPPID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAccountNotFound) forKey:@(ERR_SVR_FRIENDSHIP_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAdminRequired) forKey:@(ERR_SVR_FRIENDSHIP_ADMIN_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipSensitiveText) forKey:@(ERR_SVR_FRIENDSHIP_SENSITIVE_TEXT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInternalError) forKey:@(ERR_SVR_FRIENDSHIP_INTERNAL_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipNetTimeout) forKey:@(ERR_SVR_FRIENDSHIP_NET_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipWriteConflict) forKey:@(ERR_SVR_FRIENDSHIP_WRITE_CONFLICT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAddFriendDeny) forKey:@(ERR_SVR_FRIENDSHIP_ADD_FRIEND_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIkitErrorSVRFriendshipCountLimit) forKey:@(ERR_SVR_FRIENDSHIP_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipGroupCountLimit) forKey:@(ERR_SVR_FRIENDSHIP_GROUP_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipPendencyLimit) forKey:@(ERR_SVR_FRIENDSHIP_PENDENCY_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipBlacklistLimit) forKey:@(ERR_SVR_FRIENDSHIP_BLACKLIST_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipPeerFriendLimit) forKey:@(ERR_SVR_FRIENDSHIP_PEER_FRIEND_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAlreadyFriends) forKey:@(ERR_SVR_FRIENDSHIP_ALREADY_FRIENDS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipInSelfBlacklist) forKey:@(ERR_SVR_FRIENDSHIP_IN_SELF_BLACKLIST)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAllowTypeDenyAny) forKey:@(ERR_SVR_FRIENDSHIP_ALLOW_TYPE_DENY_ANY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipInPeerBlackList) forKey:@(ERR_SVR_FRIENDSHIP_IN_PEER_BLACKLIST)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAllowTypeNeedConfirm) forKey:@(ERR_SVR_FRIENDSHIP_ALLOW_TYPE_NEED_CONFIRM)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAddFriendSecRstr) forKey:@(ERR_SVR_FRIENDSHIP_ADD_FRIEND_SEC_RSTR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipPendencyNotFound) forKey:@(ERR_SVR_FRIENDSHIP_PENDENCY_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipDelFriendSecRstr) forKey:@(ERR_SVR_FRIENDSHIP_DEL_FRIEND_SEC_RSTR)];
    [map setObject:TDeskKitLocalizableString(TUIKirErrorSVRFriendAccountNotFoundEx) forKey:@(ERR_SVR_FRIENDSHIP_ACCOUNT_NOT_FOUND_EX)];
    // Conversation
    [map setObject:TDeskKitLocalizableString(TUIKirErrorSVRFriendAccountNotFoundEx) forKey:@(ERR_SVR_CONV_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipInvalidParameters) forKey:@(ERR_SVR_CONV_INVALID_PARAMETERS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipAdminRequired) forKey:@(ERR_SVR_CONV_ADMIN_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInternalError) forKey:@(ERR_SVR_CONV_INTERNAL_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRFriendshipNetTimeout) forKey:@(ERR_SVR_CONV_NET_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRConvGroupNameLengthLimit) forKey:@(ERR_SVR_CONV_CONV_GROUP_NAME_EXCEED_LENGTH)];
    
    // Message
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgPkgParseFailed) forKey:@(ERR_SVR_MSG_PKG_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInternalAuthFailed) forKey:@(ERR_SVR_MSG_INTERNAL_AUTH_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidId) forKey:@(ERR_SVR_MSG_INVALID_ID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgNetError) forKey:@(ERR_SVR_MSG_NET_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgPushDeny) forKey:@(ERR_SVR_MSG_PUSH_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInPeerBlackList) forKey:@(ERR_SVR_MSG_IN_PEER_BLACKLIST)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgBothNotFriend) forKey:@(ERR_SVR_MSG_BOTH_NOT_FRIEND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgNotPeerFriend) forKey:@(ERR_SVR_MSG_NOT_PEER_FRIEND)];
    [map setObject:TDeskKitLocalizableString(TUIkitErrorSVRMsgNotSelfFriend) forKey:@(ERR_SVR_MSG_NOT_SELF_FRIEND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgShutupDeny) forKey:@(ERR_SVR_MSG_SHUTUP_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgRevokeTimeLimit) forKey:@(ERR_SVR_MSG_REVOKE_TIME_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgDelRambleInternalError) forKey:@(ERR_SVR_MSG_DEL_RAMBLE_INTERNAL_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgJsonParseFailed) forKey:@(ERR_SVR_MSG_JSON_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidJsonBodyFormat) forKey:@(ERR_SVR_MSG_INVALID_JSON_BODY_FORMAT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidToAccount) forKey:@(ERR_SVR_MSG_INVALID_TO_ACCOUNT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidRand) forKey:@(ERR_SVR_MSG_INVALID_RAND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidTimestamp) forKey:@(ERR_SVR_MSG_INVALID_TIMESTAMP)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgBodyNotArray) forKey:@(ERR_SVR_MSG_BODY_NOT_ARRAY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountAdminRequired) forKey:@(ERR_SVR_MSG_ADMIN_REQUIRED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidJsonFormat) forKey:@(ERR_SVR_MSG_INVALID_JSON_FORMAT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgToAccountCountLimit) forKey:@(ERR_SVR_MSG_TO_ACCOUNT_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgToAccountNotFound) forKey:@(ERR_SVR_MSG_TO_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgTimeLimit) forKey:@(ERR_SVR_MSG_TIME_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgInvalidSyncOtherMachine) forKey:@(ERR_SVR_MSG_INVALID_SYNCOTHERMACHINE)];
    [map setObject:TDeskKitLocalizableString(TUIkitErrorSVRMsgInvalidMsgLifeTime) forKey:@(ERR_SVR_MSG_INVALID_MSGLIFETIME)];
    [map setObject:TDeskKitLocalizableString(TUIKirErrorSVRFriendAccountNotFoundEx) forKey:@(ERR_SVR_MSG_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRMsgBodySizeLimit) forKey:@(ERR_SVR_MSG_BODY_SIZE_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRmsgLongPollingCountLimit) forKey:@(ERR_SVR_MSG_LONGPOLLING_COUNT_LIMIT)];
    
    // Group
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRAccountInternalError) forKey:@(ERR_SVR_GROUP_INTERNAL_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupApiNameError) forKey:@(ERR_SVR_GROUP_API_NAME_ERROR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRResInvalidParameters) forKey:@(ERR_SVR_GROUP_INVALID_PARAMETERS)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupAccountCountLimit) forKey:@(ERR_SVR_GROUP_ACOUNT_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIkitErrorSVRGroupFreqLimit) forKey:@(ERR_SVR_GROUP_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupPermissionDeny) forKey:@(ERR_SVR_GROUP_PERMISSION_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupInvalidReq) forKey:@(ERR_SVR_GROUP_INVALID_REQ)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupSuperNotAllowQuit) forKey:@(ERR_SVR_GROUP_SUPER_NOT_ALLOW_QUIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupNotFound) forKey:@(ERR_SVR_GROUP_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupJsonParseFailed) forKey:@(ERR_SVR_GROUP_JSON_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupInvalidId) forKey:@(ERR_SVR_GROUP_INVALID_ID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupAllreadyMember) forKey:@(ERR_SVR_GROUP_ALLREADY_MEMBER)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupFullMemberCount) forKey:@(ERR_SVR_GROUP_FULL_MEMBER_COUNT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupInvalidGroupId) forKey:@(ERR_SVR_GROUP_INVALID_GROUPID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupRejectFromThirdParty) forKey:@(ERR_SVR_GROUP_REJECT_FROM_THIRDPARTY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupShutDeny) forKey:@(ERR_SVR_GROUP_SHUTUP_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupRspSizeLimit) forKey:@(ERR_SVR_GROUP_RSP_SIZE_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupAccountNotFound) forKey:@(ERR_SVR_GROUP_ACCOUNT_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupGroupIdInUse) forKey:@(ERR_SVR_GROUP_GROUPID_IN_USED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupSendMsgFreqLimit) forKey:@(ERR_SVR_GROUP_SEND_MSG_FREQ_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupReqAllreadyBeenProcessed) forKey:@(ERR_SVR_GROUP_REQ_ALLREADY_BEEN_PROCESSED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupGroupIdUserdForSuper) forKey:@(ERR_SVR_GROUP_GROUPID_IN_USED_FOR_SUPER)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupSDkAppidDeny) forKey:@(ERR_SVR_GROUP_SDKAPPID_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupRevokeMsgNotFound) forKey:@(ERR_SVR_GROUP_REVOKE_MSG_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupRevokeMsgTimeLimit) forKey:@(ERR_SVR_GROUP_REVOKE_MSG_TIME_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupRevokeMsgDeny) forKey:@(ERR_SVR_GROUP_REVOKE_MSG_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupNotAllowRevokeMsg) forKey:@(ERR_SVR_GROUP_NOT_ALLOW_REVOKE_MSG)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupRemoveMsgDeny) forKey:@(ERR_SVR_GROUP_REMOVE_MSG_DENY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupNotAllowRemoveMsg) forKey:@(ERR_SVR_GROUP_NOT_ALLOW_REMOVE_MSG)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupAvchatRoomCountLimit) forKey:@(ERR_SVR_GROUP_AVCHATROOM_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupCountLimit) forKey:@(ERR_SVR_GROUP_COUNT_LIMIT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRGroupMemberCountLimit) forKey:@(ERR_SVR_GROUP_MEMBER_COUNT_LIMIT)];
    
    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      （3）Version 3 deprecated
    //
    /////////////////////////////////////////////////////////////////////////////////
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRNoSuccessResult) forKey:@(ERR_NO_SUCC_RESULT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRToUserInvalid) forKey:@(ERR_TO_USER_INVALID)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRInitCoreFail) forKey:@(ERR_INIT_CORE_FAIL)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorExpiredSessionNode) forKey:@(ERR_EXPIRED_SESSION_NODE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoggedOutBeforeLoginFinished) forKey:@(ERR_LOGGED_OUT_BEFORE_LOGIN_FINISHED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKNotInitialized) forKey:@(ERR_TLSSDK_NOT_INITIALIZED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorTLSSDKUserNotFound) forKey:@(ERR_TLSSDK_USER_NOT_FOUND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorBindFaildRegTimeout) forKey:@(ERR_BIND_FAIL_REG_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorBindFaildIsBinding) forKey:@(ERR_BIND_FAIL_ISBINDING)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorPacketFailUnknown) forKey:@(ERR_PACKET_FAIL_UNKNOWN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorPacketFailReqNoNet) forKey:@(ERR_PACKET_FAIL_REQ_NO_NET)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorPacketFailRespNoNet) forKey:@(ERR_PACKET_FAIL_RESP_NO_NET)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorPacketFailReqNoAuth) forKey:@(ERR_PACKET_FAIL_REQ_NO_AUTH)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorPacketFailSSOErr) forKey:@(ERR_PACKET_FAIL_SSO_ERR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSVRRequestTimeout) forKey:@(ERR_PACKET_FAIL_REQ_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorPacketFailRespTimeout) forKey:@(ERR_PACKET_FAIL_RESP_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFriendshipProxySyncing) forKey:@(ERR_FRIENDSHIP_PROXY_SYNCING)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFriendshipProxySyncedFail) forKey:@(ERR_FRIENDSHIP_PROXY_SYNCED_FAIL)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorFriendshipProxyLocalCheckErr) forKey:@(ERR_FRIENDSHIP_PROXY_LOCAL_CHECK_ERR)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorGroupInvalidField) forKey:@(ERR_GROUP_INVALID_FIELD)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorGroupStoreageDisabled) forKey:@(ERR_GROUP_STORAGE_DISABLED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoadGrpInfoFailed) forKey:@(ERR_LOADGRPINFO_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqNoNetOnReq) forKey:@(ERR_REQ_NO_NET_ON_REQ)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqNoNetOnResp) forKey:@(ERR_REQ_NO_NET_ON_RSP)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorServiceNotReady) forKey:@(ERR_SERIVCE_NOT_READY)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginAuthFailed) forKey:@(ERR_LOGIN_AUTH_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorNeverConnectAfterLaunch) forKey:@(ERR_NEVER_CONNECT_AFTER_LAUNCH)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqFailed) forKey:@(ERR_REQ_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqInvaidReq) forKey:@(ERR_REQ_INVALID_REQ)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqOnverLoaded) forKey:@(ERR_REQ_OVERLOADED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqKickOff) forKey:@(ERR_REQ_KICK_OFF)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqServiceSuspend) forKey:@(ERR_REQ_SERVICE_SUSPEND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqInvalidSign) forKey:@(ERR_REQ_INVALID_SIGN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqInvalidCookie) forKey:@(ERR_REQ_INVALID_COOKIE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginTlsRspParseFailed) forKey:@(ERR_LOGIN_TLS_RSP_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginOpenMsgTimeout) forKey:@(ERR_LOGIN_OPENMSG_TIMEOUT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginOpenMsgRspParseFailed) forKey:@(ERR_LOGIN_OPENMSG_RSP_PARSE_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginTslDecryptFailed) forKey:@(ERR_LOGIN_TLS_DECRYPT_FAILED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorWifiNeedAuth) forKey:@(ERR_WIFI_NEED_AUTH)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorUserCanceled) forKey:@(ERR_USER_CANCELED)];
    [map setObject:TDeskKitLocalizableString(TUIkitErrorRevokeTimeLimitExceed) forKey:@(ERR_REVOKE_TIME_LIMIT_EXCEED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLackUGExt) forKey:@(ERR_LACK_UGC_EXT)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorAutoLoginNeedUserSig) forKey:@(ERR_AUTOLOGIN_NEED_USERSIG)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorQALNoShortConneAvailable) forKey:@(ERR_QAL_NO_SHORT_CONN_AVAILABLE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqContentAttach) forKey:@(ERR_REQ_CONTENT_ATTACK)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorLoginSigExpire) forKey:@(ERR_LOGIN_SIG_EXPIRE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorSDKHadInit) forKey:@(ERR_SDK_HAD_INITIALIZED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorOpenBDHBase) forKey:@(ERR_OPENBDH_BASE)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorRequestNoNetOnReq) forKey:@(ERR_REQUEST_NO_NET_ONREQ)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorRequestNoNetOnRsp) forKey:@(ERR_REQUEST_NO_NET_ONRSP)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorRequestOnverLoaded) forKey:@(ERR_REQUEST_OVERLOADED)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqKickOff) forKey:@(ERR_REQUEST_KICK_OFF)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqServiceSuspend) forKey:@(ERR_REQUEST_SERVICE_SUSPEND)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqInvalidSign) forKey:@(ERR_REQUEST_INVALID_SIGN)];
    [map setObject:TDeskKitLocalizableString(TUIKitErrorReqInvalidCookie) forKey:@(ERR_REQUEST_INVALID_COOKIE)];
}
+ (NSData *)dictionary2JsonData:(NSDictionary *)dict {
    if ([NSJSONSerialization isValidJSONObject:dict]) {
        NSError *error = nil;
        NSData *data = [NSJSONSerialization dataWithJSONObject:dict options:0 error:&error];
        if (error) {
            NSLog(@"[%@] Post Json Error", [self class]);
        }
        return data;
    } else {
        NSLog(@"[%@] Post Json is not valid", [self class]);
    }
    return nil;
}

+ (NSString *)dictionary2JsonStr:(NSDictionary *)dict {
    return [[NSString alloc] initWithData:[self dictionary2JsonData:dict] encoding:NSUTF8StringEncoding];
    ;
}

+ (NSDictionary *)jsonSring2Dictionary:(NSString *)jsonString {
    if (jsonString == nil) {
        return nil;
    }
    NSData *data = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err = nil;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:&err];
    if (err || ![dic isKindOfClass:[NSDictionary class]]) {
        NSLog(@"Json parse failed: %@", jsonString);
        return nil;
    }
    return dic;
}

+ (NSDictionary *)jsonData2Dictionary:(NSData *)jsonData {
    if (jsonData == nil) {
        return nil;
    }
    NSError *err = nil;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&err];
    if (err || ![dic isKindOfClass:[NSDictionary class]]) {
        NSLog(@"Json parse failed");
        return nil;
    }
    return dic;
}

+ (void)asyncDecodeImage:(NSString *)path complete:(TAsyncImageComplete)complete {
    static dispatch_queue_t deskQueue;
    static dispatch_once_t deskOnceToken;
    dispatch_once(&deskOnceToken, ^{
      deskQueue = dispatch_queue_create("com.tuikit.desk.asyncDecodeImage", DISPATCH_QUEUE_SERIAL);
    });

    // callback on main thread
    void (^callback)(NSString *, UIImage *) = ^(NSString *path, UIImage *image) {
      if (complete == nil) {
          return;
      }
      dispatch_async(dispatch_get_main_queue(), ^{
        complete(path, image);
      });
    };

    if (path == nil) {
        callback(nil, nil);
        return;
    }

    dispatch_async(deskQueue, ^{
      // The path ends with gif:
      if ([path tdesk_containsString:@".gif"]) {
          UIImage *image = [UIImage sd_imageWithGIFData:[NSData dataWithContentsOfFile:path]];
          callback(path, image);
          return;
      }

      // load origin image
      UIImage *image = [UIImage imageNamed:@"/xxx/xxx"];
      if (image == nil) {
          image = [UIImage imageWithContentsOfFile:path];
      }

      // There is no path ending, but it may actually be a gif image
      if (image == nil) {
         NSString *formatPath = [path stringByAppendingString:@".gif"];
         image = [UIImage sd_imageWithGIFData:[NSData dataWithContentsOfFile:formatPath]];
         callback(formatPath, image);
         return;
      }
        
      if (image == nil) {
          callback(path, image);
          return;
      }
      
      if (image.sd_imageFormat == SDImageFormatGIF) {
        image = [UIImage sd_imageWithGIFData:[NSData dataWithContentsOfFile:path]];
        callback(path, image);
        return;
      }

      // SDWebImage is priority
      UIImage *decodeImage = [SDImageCoderHelper decodedImageWithImage:image];
      if (decodeImage) {
          callback(path, decodeImage);
          return;
      }

      // Bitmap
      CGImageRef cgImage = image.CGImage;
      if (cgImage) {
          CGImageAlphaInfo alphaInfo = CGImageGetAlphaInfo(cgImage) & kCGBitmapAlphaInfoMask;
          BOOL hasAlpha = NO;
          if (alphaInfo == kCGImageAlphaPremultipliedLast || alphaInfo == kCGImageAlphaPremultipliedFirst || alphaInfo == kCGImageAlphaLast ||
              alphaInfo == kCGImageAlphaFirst) {
              hasAlpha = YES;
          }
          CGBitmapInfo bitmapInfo = kCGBitmapByteOrder32Host;
          bitmapInfo |= hasAlpha ? kCGImageAlphaPremultipliedFirst : kCGImageAlphaNoneSkipFirst;
          size_t width = CGImageGetWidth(cgImage);
          size_t height = CGImageGetHeight(cgImage);
          CGContextRef context = CGBitmapContextCreate(NULL, width, height, 8, 0, CGColorSpaceCreateDeviceRGB(), bitmapInfo);
          if (context) {
              CGContextDrawImage(context, CGRectMake(0, 0, width, height), cgImage);
              cgImage = CGBitmapContextCreateImage(context);
              decodeImage = [UIImage imageWithCGImage:cgImage scale:image.scale orientation:image.imageOrientation];
              CGContextRelease(context);
              CGImageRelease(cgImage);
          }
      }
      callback(path, decodeImage);
    });
}

+ (void)makeToast:(NSString *)str {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow makeToast:str];
    }
}

+ (void)makeToast:(NSString *)str duration:(NSTimeInterval)duration {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow makeToast:str duration:duration];
    }
}

+ (void)makeToast:(NSString *)str duration:(NSTimeInterval)duration position:(CGPoint)position {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow makeToast:str duration:duration position:[NSValue valueWithCGPoint:position]];
    }
}

+ (void)makeToast:(NSString *)str duration:(NSTimeInterval)duration idposition:(id)position {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow makeToast:str duration:duration position:position];
    }
}

+ (void)makeToastError:(NSInteger)error msg:(NSString *)msg {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow makeToast:[self convertIMError:error msg:msg]];
    }
}

+ (void)hideToast {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow hideToast];
    }
}

+ (void)makeToastActivity {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow makeToastActivity:TUICSToastPositionCenter];
    }
}

+ (void)hideToastActivity {
    if ([TDeskConfig defaultConfig].enableToast) {
        [[UIApplication sharedApplication].keyWindow hideToastActivity];
    }
}

+ (NSString *)convertDateToStr:(NSDate *)date {
    if (!date) {
        return nil;
    }

    if ([date isEqualToDate:[NSDate distantPast]]) {
        return @"";
    }

    static NSDateFormatter *dateFmt = nil;
    if (dateFmt == nil) {
        dateFmt = [[NSDateFormatter alloc] init];
    }
    dateFmt.locale = nil;

    NSCalendar *calendar = [NSCalendar currentCalendar];
    calendar.firstWeekday = 7;
    NSDateComponents *nowComponent = [calendar components:NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear | NSCalendarUnitWeekOfMonth
                                                 fromDate:NSDate.new];
    NSDateComponents *dateCompoent = [calendar components:NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear | NSCalendarUnitWeekOfMonth
                                                 fromDate:date];

    if (nowComponent.year == dateCompoent.year) {
        // Same year
        if (nowComponent.month == dateCompoent.month) {
            // Same month
            if (nowComponent.weekOfMonth == dateCompoent.weekOfMonth) {
                // Same week
                if (nowComponent.day == dateCompoent.day) {
                    // Same day
                    dateFmt.dateFormat = @"HH:mm";
                } else {
                    // Not same day
                    dateFmt.dateFormat = @"EEEE";
                    NSString *identifer = [TDeskGlobalization getPreferredLanguage];
                    dateFmt.locale = [NSLocale localeWithLocaleIdentifier:identifer];
                }
            } else {
                // Not same weeek
                dateFmt.dateFormat = @"MM/dd";
            }
        } else {
            // Not same month
            dateFmt.dateFormat = @"MM/dd";
        }
    } else {
        // Not same year
        dateFmt.dateFormat = @"yyyy/MM/dd";
    }

    NSString *str = [dateFmt stringFromDate:date];
    return str;
}

+ (NSString *)convertDateToHMStr:(NSDate *)date {
    if (!date) {
        return nil;
    }

    if ([date isEqualToDate:[NSDate distantPast]]) {
        return @"";
    }

    NSDateFormatter *dateFmt = [[NSDateFormatter alloc] init];
    dateFmt.dateFormat = @"HH:mm";
    NSString *str = [dateFmt stringFromDate:date];
    return str;
}

+ (NSString *)convertIMError:(NSInteger)code msg:(NSString *)msg {
    NSString  *resultMsg = @"";
    resultMsg = gIMErrorMsgMap[@(code)];
    if (resultMsg.length > 0) {
        return resultMsg;
    }
    return msg;
}

+ (void)dispatchMainAsync:(dispatch_block_t)block {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

+ (NSString *)genImageName:(NSString *)uuid {
    NSString *identifier = [[V2TIMManager sharedInstance] getLoginUser];
    if (uuid == nil) {
        int value = arc4random() % 1000;
        uuid = [NSString stringWithFormat:@"%ld_%d", (long)[[NSDate date] timeIntervalSince1970], value];
    }

    NSString *name = [NSString stringWithFormat:@"%d_%@_image_%@", [TDeskLogin getSdkAppID], identifier, uuid];
    return name;
}

+ (NSString *)genSnapshotName:(NSString *)uuid {
    NSString *identifier = [[V2TIMManager sharedInstance] getLoginUser];
    if (uuid == nil) {
        uuid = [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]];
    }
    NSString *name = [NSString stringWithFormat:@"%d_%@_snapshot_%@", [TDeskLogin getSdkAppID], identifier, uuid];
    return name;
}

+ (NSString *)genVideoName:(NSString *)uuid {
    NSString *identifier = [[V2TIMManager sharedInstance] getLoginUser];
    if (uuid == nil) {
        uuid = [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]];
    }
    NSString *name = [NSString stringWithFormat:@"%d_%@_video_%@", [TDeskLogin getSdkAppID], identifier, uuid];
    return name;
}

+ (NSString *)genVoiceName:(NSString *)uuid withExtension:(NSString *)extent {
    NSString *identifier = [[V2TIMManager sharedInstance] getLoginUser];
    if (uuid == nil) {
        uuid = [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]];
    }
    NSString *name = [NSString stringWithFormat:@"%d_%@_voice_%@.%@", [TDeskLogin getSdkAppID], identifier, uuid, extent];
    return name;
}

+ (NSString *)genFileName:(NSString *)uuid {
    NSString *identifier = [[V2TIMManager sharedInstance] getLoginUser];
    if (uuid == nil) {
        uuid = [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]];
    }
    NSString *name = [NSString stringWithFormat:@"%d_%@_file_%@", [TDeskLogin getSdkAppID], identifier, uuid];
    return name;
}

+ (NSString *)deviceModel {
    static NSString *deviceModel;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
      deviceModel = [[UIDevice currentDevice] model];
    });
    return deviceModel;
}

+ (NSString *)deviceVersion {
    static NSString *deviceVersion;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
      deviceVersion = [[UIDevice currentDevice] systemVersion];
    });
    return deviceVersion;
}

+ (NSString *)deviceName {
    static NSString *deviceName;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
      deviceName = [[UIDevice currentDevice] name];
    });
    return deviceName;
}

+ (void)openLinkWithURL:(NSURL *)url {
    if (@available(iOS 10.0, *)) {
        [[UIApplication sharedApplication] openURL:url
                                           options:@{}
                                 completionHandler:^(BOOL success) {
                                   if (success) {
                                       NSLog(@"Opened url");
                                   }
                                 }];
    } else {
        [[UIApplication sharedApplication] openURL:url];
    }
}

+ (void)addUnsupportNotificationInVC:(UIViewController *)vc {
    [self addUnsupportNotificationInVC:vc debugOnly:YES];
}

+ (void)addUnsupportNotificationInVC:(UIViewController *)vc debugOnly:(BOOL)debugOnly {
    BOOL enable = YES;
    if (debugOnly) {
#if DEBUG
        enable = YES;
#else
        enable = NO;
#endif
    }

    if (!enable) {
        return;
    }
    TDeskWeakProxy *weakVC = [TDeskWeakProxy proxyWithTarget:vc];
    [[NSNotificationCenter defaultCenter] addObserverForName:TUIKitNotification_onReceivedUnsupportInterfaceError
                                                      object:nil
                                                       queue:nil
                                                  usingBlock:^(NSNotification *_Nonnull note) {
                                                    NSDictionary *userInfo = note.userInfo;
                                                    NSString *service = [userInfo objectForKey:@"service"];
                                                    NSString *serviceDesc = [userInfo objectForKey:@"serviceDesc"];
                                                    if (weakVC.target) {
                                                        [TDeskTool showUnsupportAlertOfService:service serviceDesc:serviceDesc onVC:weakVC.target];
                                                    }
                                                  }];
}

+ (void)postUnsupportNotificationOfService:(NSString *)service {
    [self postUnsupportNotificationOfService:service serviceDesc:nil debugOnly:YES];
}

+ (void)postUnsupportNotificationOfService:(NSString *)service serviceDesc:(NSString *)serviceDesc debugOnly:(BOOL)debugOnly {
    BOOL enable = YES;
    if (debugOnly) {
#if DEBUG
        enable = YES;
#else
        enable = NO;
#endif
    }

    if (!enable) {
        return;
    }

    if (!service) {
        NSLog(@"postNotificationOfService, service is nil");
        return;
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:TUIKitNotification_onReceivedUnsupportInterfaceError
                                                        object:nil
                                                      userInfo:@{@"service" : service ?: @"", @"serviceDesc" : serviceDesc ?: @""}];
}

+ (void)showUnsupportAlertOfService:(NSString *)service serviceDesc:(NSString *)serviceDesc onVC:(UIViewController *)vc {
    NSString *key = [NSString stringWithFormat:@"show_unsupport_alert_%@", service];
    BOOL isShown = [[NSUserDefaults standardUserDefaults] boolForKey:key];
    if (isShown) {
        return;
    }
    NSString *desc = [NSString stringWithFormat:@"%@%@%@", service, TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceDesc), serviceDesc ?: @""];
    NSArray *buttons = @[ TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceIGotIt), TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceNoMoreAlert) ];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceTitle)
                                                                             message:desc
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    NSMutableAttributedString *attrStr = [[NSMutableAttributedString alloc] initWithString:desc];
    [attrStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:14] range:NSMakeRange(0, desc.length)];
    [attrStr addAttribute:NSLinkAttributeName value:@"https://" range:[desc rangeOfString:TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceGuidelines)]];
    [alertController setValue:attrStr forKey:@"attributedMessage"];
    UILabel *msgLabel = [TDeskTool messageLabelInAlertController:alertController];
    msgLabel.userInteractionEnabled = YES;
    msgLabel.textAlignment = NSTextAlignmentLeft;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:TDeskTool.class action:@selector(onTapLabel:)];
    [msgLabel addGestureRecognizer:tap];

    UIAlertAction *left = [UIAlertAction actionWithTitle:buttons[0]
                                                   style:UIAlertActionStyleDefault
                                                 handler:^(UIAlertAction *_Nonnull action){
                                                 }];
    UIAlertAction *right = [UIAlertAction actionWithTitle:buttons[1]
                                                    style:UIAlertActionStyleDefault
                                                  handler:^(UIAlertAction *_Nonnull action) {
                                                    [[NSUserDefaults standardUserDefaults] setBool:YES forKey:key];
                                                    [[NSUserDefaults standardUserDefaults] synchronize];
                                                  }];
    [alertController tuitheme_addAction:left];
    [alertController tuitheme_addAction:right];
    [vc presentViewController:alertController animated:NO completion:nil];
}

+ (void)onTapLabel:(UIGestureRecognizer *)ges {
    NSString *chinesePurchase = @"https://cloud.tencent.com/document/product/269/11673#.E5.9F.BA.E7.A1.80.E6.9C.8D.E5.8A.A1.E8.AF.A6.E6.83.85";
    NSString *englishPurchase = @"https://intl.cloud.tencent.com/document/product/1047/36021?lang=en&pg=#changing-configuration";
    NSString *language = [TDeskGlobalization tk_localizableLanguageKey];
    NSURL *url = [NSURL URLWithString:chinesePurchase];
    if (![language tdesk_containsString:@"zh-"]) {
        url = [NSURL URLWithString:englishPurchase];
    }
    [TDeskTool openLinkWithURL:url];
}

+ (void)addValueAddedUnsupportNeedContactNotificationInVC:(UIViewController *)vc debugOnly:(BOOL)debugOnly {
    BOOL enable = YES;
    if (debugOnly) {
#if DEBUG
        enable = YES;
#else
        enable = NO;
#endif
    }
    if (!enable) {
        return;
    }

    [[NSNotificationCenter defaultCenter] addObserverForName:TUIKitNotification_onReceivedValueAddedUnsupportContactNeededError
                                                      object:nil
                                                       queue:nil
                                                  usingBlock:^(NSNotification *_Nonnull note) {
        NSDictionary *userInfo = note.userInfo;
        NSString *service = [userInfo objectForKey:@"service"];
        [TDeskTool showValueAddedUnsupportNeedContactAlertOfService:service onVC:vc];
    }];
}

+ (void)addValueAddedUnsupportNeedPurchaseNotificationInVC:(UIViewController *)vc debugOnly:(BOOL)debugOnly {
    BOOL enable = YES;
    if (debugOnly) {
#if DEBUG
        enable = YES;
#else
        enable = NO;
#endif
    }
    if (!enable) {
        return;
    }

    __weak __typeof(vc) weakVC = vc;
    [[NSNotificationCenter defaultCenter] addObserverForName:TUIKitNotification_onReceivedValueAddedUnsupportPurchaseNeededError
                                                      object:nil
                                                       queue:nil
                                                  usingBlock:^(NSNotification *_Nonnull note) {
        __strong __typeof(weakVC) strongVC = weakVC;
        NSDictionary *userInfo = note.userInfo;
        NSString *service = [userInfo objectForKey:@"service"];
        [TDeskTool showValueAddedUnsupportNeedPurchaseAlertOfService:service onVC:strongVC];
    }];
}

+ (void)postValueAddedUnsupportNeedContactNotification:(NSString *)service {
    [self postValueAddedUnsupportNotification:TUIKitNotification_onReceivedValueAddedUnsupportContactNeededError
                                      service:service
                                  serviceDesc:nil
                                    debugOnly:YES];
}

+ (void)postValueAddedUnsupportNeedPurchaseNotification:(NSString *)service {
    [self postValueAddedUnsupportNotification:TUIKitNotification_onReceivedValueAddedUnsupportPurchaseNeededError
                                      service:service
                                  serviceDesc:nil
                                    debugOnly:YES];
}

+ (void)postValueAddedUnsupportNotification:(NSString *)notification service:(NSString *)service serviceDesc:(NSString *)serviceDesc debugOnly:(BOOL)debugOnly {
    BOOL enable = YES;
    if (debugOnly) {
#if DEBUG
        enable = YES;
#else
        enable = NO;
#endif
    }

    if (!enable) {
        return;
    }

    if (!service) {
        NSLog(@"postNotificationOfService, service is nil");
        return;
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:notification
                                                        object:nil
                                                      userInfo:@{@"service" : service ?: @"",
                                                                 @"serviceDesc" : serviceDesc ?: @""}];
}

+ (void)showValueAddedUnsupportNeedContactAlertOfService:(NSString *)service onVC:(UIViewController *)vc {
    [self showValueAddedUnsupportAlertOfService:service
                                    serviceDesc:TDeskKitLocalizableString(TUIKitErrorValueAddedUnsupportIntefaceContactDesc)
                                           onVC:vc
                                  highlightText:TDeskKitLocalizableString(TUIKitErrorValueAddedUnsupportIntefaceContactDescHighlight)
                                            sel:@selector(onTapValueAddedContactLabel)];
}

+ (void)showValueAddedUnsupportNeedPurchaseAlertOfService:(NSString *)service onVC:(UIViewController *)vc {
    [self showValueAddedUnsupportAlertOfService:service
                                    serviceDesc:TDeskKitLocalizableString(TUIKitErrorValueAddedUnsupportIntefacePurchaseDesc)
                                           onVC:vc
                                  highlightText:TDeskKitLocalizableString(TUIKitErrorValueAddedUnsupportIntefacePurchaseDescHighlight)
                                            sel:@selector(onTapValueAddedPurchaseLabel)];
}

+ (void)showValueAddedUnsupportAlertOfService:(NSString *)service serviceDesc:(NSString *)serviceDesc onVC:(UIViewController *)vc 
                                highlightText:(NSString *)text sel:(SEL)selector {
    NSString *desc = [NSString stringWithFormat:@"%@%@", service, serviceDesc ?: @""];
    NSString *button = TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceIGotIt);
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:TDeskKitLocalizableString(TUIKitErrorUnsupportIntefaceTitle)
                                                                             message:desc
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    
    NSMutableAttributedString *attrStr = [[NSMutableAttributedString alloc] initWithString:desc];
    [attrStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:14] range:NSMakeRange(0, desc.length)];
    [attrStr addAttribute:NSLinkAttributeName value:@"https://" range:[desc rangeOfString:text]];
    [alertController setValue:attrStr forKey:@"attributedMessage"];
    
    UILabel *msgLabel = [TDeskTool messageLabelInAlertController:alertController];
    msgLabel.userInteractionEnabled = YES;
    msgLabel.textAlignment = NSTextAlignmentLeft;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:TDeskTool.class action:selector];
    [msgLabel addGestureRecognizer:tap];
    
    UIAlertAction *ok = [UIAlertAction actionWithTitle:button
                                                 style:UIAlertActionStyleDefault
                                               handler:^(UIAlertAction *_Nonnull action){
                                               }];
    [alertController tuitheme_addAction:ok];
    [vc presentViewController:alertController animated:NO completion:nil];
}

+ (void)onTapValueAddedContactLabel {
    NSURL *url = [NSURL URLWithString:@"https://zhiliao.qq.com"];
    [TDeskTool openLinkWithURL:url];
}

+ (void)onTapValueAddedPurchaseLabel {
    NSURL *url = [NSURL URLWithString:@"https://buy.cloud.tencent.com/avc?activeId=plugin&regionId=1"];
    [TDeskTool openLinkWithURL:url];
}

+ (void)checkCommercialAbility:(long long)param succ:(void (^)(BOOL enabled))succ fail:(void (^)(int code, NSString *desc))fail {
    NSLog(@"checkCommercialAbility param: %lld", param);
    dispatch_async(dispatch_get_main_queue(), ^{
      NSNumber *paramNum = [NSNumber numberWithLongLong:param];
      [[V2TIMManager sharedInstance] callExperimentalAPI:@"isCommercialAbilityEnabled"
          param:paramNum
          succ:^(NSObject *result) {
            dispatch_async(dispatch_get_main_queue(), ^{
              BOOL isEnabled = [(NSNumber *)result boolValue];
              NSLog(@"checkCommercialAbility enabled: %d", isEnabled);
              if (succ) {
                  succ(isEnabled);
              }
            });
          }
          fail:^(int code, NSString *desc) {
            dispatch_async(dispatch_get_main_queue(), ^{
              NSLog(@"checkCommercialAbility error, code:%d, desc:%@", code, desc);
              if (fail) {
                  fail(code, desc);
              }
            });
          }];
    });
}

+ (UILabel *)messageLabelInAlertController:(UIAlertController *)alert {
    UIView *target = [TDeskTool targetSubviewInAlertController:alert];
    NSArray *subviews = [target subviews];
    if (subviews.count == 0) {
        return nil;
    }
    for (UIView *view in subviews) {
        if ([view isKindOfClass:UILabel.class]) {
            UILabel *label = (UILabel *)view;
            if (label.text.length > 10) {
                return label;
            }
        }
    }
    return nil;
}

+ (UIView *)targetSubviewInAlertController:(UIAlertController *)alert {
    UIView *view = alert.view;
    for (int i = 0; i < 5; i++) {
        view = view.subviews.firstObject;
    }
    return view;
}

+ (UIWindow *)applicationKeywindow {
    UIWindow *keywindow = UIApplication.sharedApplication.keyWindow;
    if (keywindow == nil) {
        if (@available(iOS 13.0, *)) {
            for (UIWindowScene *scene in UIApplication.sharedApplication.connectedScenes) {
                if (scene.activationState == UISceneActivationStateForegroundActive) {
                    UIWindow *tmpWindow = nil;
                    if (@available(iOS 15.0, *)) {
                        tmpWindow = scene.keyWindow;
                    }
                    if (tmpWindow == nil) {
                        for (UIWindow *window in scene.windows) {
                            if (window.windowLevel == UIWindowLevelNormal && window.hidden == NO &&
                                CGRectEqualToRect(window.bounds, UIScreen.mainScreen.bounds)) {
                                tmpWindow = window;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (keywindow == nil) {
        for (UIWindow *window in UIApplication.sharedApplication.windows) {
            if (window.windowLevel == UIWindowLevelNormal && window.hidden == NO && CGRectEqualToRect(window.bounds, UIScreen.mainScreen.bounds)) {
                keywindow = window;
                break;
            }
        }
    }
    return keywindow;
}

@end
