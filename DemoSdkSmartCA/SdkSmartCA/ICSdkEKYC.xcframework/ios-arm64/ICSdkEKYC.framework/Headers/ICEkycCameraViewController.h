//
//  ICEkycCameraViewController.h
//  ICSdkEKYC
//
//  Created by MinhMinh on 08/12/2022.
//  Copyright © 2022 iOS Team IC - VNPT IT. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ICEkycCameraProtocols.h"
#import "ICEkycCameraPresenter.h"
#import "ICEkycBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN


@protocol ICEkycCameraDelegate <NSObject>

@required
- (void) icEkycGetResult; // getResult => icEkycGetResult

@optional
- (void) icEkycCameraClosedWithType:(ScreenType)type; // closeSDK => icEkycCameraClosedWithType. ScreenType => StepType

@end


@interface ICEkycCameraViewController : ICEkycBaseViewController<ICEkycCameraViewProtocol>

// Giá trị này xác định phiên bản khi sử dụng Máy ảnh tại bước chụp ảnh chân dung. Mặc định là normal
@property (nonatomic) VersionSdk versionSdk; // đổi từ isVersion sang versionSdk

// Giá trị này xác định kiểu giấy tờ để sử dụng. Mặc định là IdentityCard
@property (nonatomic) TypeDocument documentType; // đổi từ isType sang documentType

/* Giá trị này xác định việc luồng làm việc khi OCR giấy tờ và ảnh chân dung, bao gồm:
 • full, // thực hiện eKYC đầy đủ các bước: chụp mặt trước, chụp mặt sau và chụp ảnh chân dung
 • ocrFront, // thực hiện OCR giấy tờ một bước: chụp mặt trước
 • ocrBack, // thực hiện OCR giấy tờ một bước: chụp mặt trước
 • ocrFrontAndBack, // thực hiện OCR giấy tờ đầy đủ các bước: chụp mặt trước, chụp mặt sau
 • compare, // thực hiện so sánh khuôn mặt với mã ảnh chân dung được truyền từ bên ngoài
 • verifyFace, // thực hiện xác thực khuôn mặt với số ID, kiểu giấy tờ được truyền từ bên ngoài
 • searchFace, // thực hiện tìm kiếm thông tin dựa vào khuôn mặt
 Mặc định là full
 */
@property (nonatomic) FlowType flowType;



/*========== CÁC GIÁ TRỊ CÀI ĐẶT CHUNG SDK ==========*/
// Giá trị này xác định ngôn ngữ được sử dụng trong SDK. Mặc định là vi
@property (nonatomic) NSString *languageSdk; // "vi" languageApplication => languageSdk

@property (nonatomic) NSBundle *languageBundle;

// Giá trị số ID được nhập vào để thực hiện chức năng xác thực khuôn mặt. Mặc định là ""
@property (nonatomic) NSString *verifyId;

// Giá trị được nhập vào để thực hiện chức năng xác thực khuôn mặt. Mặc định là "CARD_ID"
@property (nonatomic) NSString *idType;

// Giá trị này dùng để đảm bảo mỗi yêu cầu (request) từ phía khách hàng sẽ không bị thay đổi. Sau mỗi request, dữ liệu trả về sẽ bao gồm giá trị challengeCode. Mặc định là "11111"
@property (nonatomic) NSString *challengeCode; // "11111"

// Giá trị này xác định tên đơn vị, tên khách hàng sử dụng SDK eKYC. Mặc định ""
@property (nonatomic) NSString *unitCustomer;

// @property (nonatomic) NSString *resourceCustomer;
// @property (nonatomic) NSString *hashFrontCompareFace; bỏ

// Giá trị này được truyền vào để xác định nhiều luồng giao dịch trong một phiên. Mặc định ""
@property (nonatomic) NSString *inputClientSession; // clientSession => inputClientSession


@property (nonatomic) NSString *hashImageCompare; // hashFaceCompare => hashImageCompare


/**
 */
//@property (nonatomic) NSDictionary *objectAddFace; // bỏ
// @property (nonatomic) UIImage *imageFaceToCompare; bỏ


/**
 */
//@property (nonatomic) NSString *hashFaceVoice; // bỏ


/**
 */

// @property (nonatomic) BOOL isShowResult; bỏ
// @property (nonatomic) BOOL isShowResultCheckLiveness3DScan; bỏ


// Giá trị này xác định việc có hiển thị màn hình trợ giúp hay không. Mặc định là false
@property (nonatomic) BOOL isShowTutorial; // isShowHelp => isShowTutorial

@property (nonatomic) ModelHelp modelHelpCard;

@property (nonatomic) ModelHelp modelHelpFace; // isVersionHelpVideoFullScreen => modelHelpFace

// bật/tắt chức năng hướng dẫn chụp ảnh thẻ nâng cao
// @property (nonatomic) BOOL isEnableTutorialCardAdvance; // bỏ

// Giá trị này xác định việc hiển thị nút bấm chức năng xoay máy ảnh trước sang máy ảnh sau. Mặc định false
@property (nonatomic) BOOL isShowSwitchCamera; // isShowRotateCamera => isShowSwitchCamera

// Giá trị này xác định việc sử dụng máy ảnh phía trước hoặc phía sau khi chụp ảnh mặt người. Mặc định PositionFront
@property (nonatomic) CameraPosition cameraPositionForPortrait; // BOOL isWantRotateCameraBack => CameraPosition cameraPositionForPortrait

// Giá trị này xác định việc có xác thực số ID với mã tỉnh thành, quận huyện, xã phường tương ứng hay không. Kiểm tra quy tắc của số ID. Mặc định là false
@property (nonatomic) BOOL isValidatePostcode;

// Giá trị này xác định việc có thực hiện so sánh khuôn mặt chân dung trong giấy tờ và mặt người. Mặc định false
@property (nonatomic) BOOL isEnableCompare; // đổi từ isCompare sang isEnableCompare

// Giá trị này xác định việc có tự động đăng ký khuôn mặt và thông tin lên hệ thống hay không. Mặc định là false
// @property (nonatomic) BOOL isAutoAddFace; // đổi từ isAddFace sang isAutoAddFace => Bỏ

@property (nonatomic) BOOL isCheckLivenessFace;

@property (nonatomic) BOOL isCheckLivenessCard;

@property (nonatomic) BOOL isCheckMaskedFace; // đổi từ isCheckMaskFace sang isCheckMaskedFace

@property (nonatomic) BOOL isEnableWaterMark;


@property (nonatomic) BOOL isCompareFaces;
@property (nonatomic) NSString *thresLevel;


@property (nonatomic) BOOL isEnableScanQRCode; // đổi isVersionQRCode sang isEnableScanQRCode

// Giá trị này xác định thời gian hết hạn quét mã QR, hết thời gian, SDK sẽ cảnh báo để thử lại hoặc bỏ qua. Mặc định là 30 (đơn vị giây)
@property (nonatomic) NSInteger timeOutScanQRCode;


// @property (nonatomic) BOOL isCustomize; bỏ

@property (nonatomic) BOOL isEnableGotIt; // isSkipVoiceVideo => isEnableGotIt

@property (nonatomic) TypeValidateDocument validateDocumentType;// BOOL isValidateDocument => TypeValidateDocument validateDocumentType

@property (nonatomic) NSInteger expriseTime; // thêm mới (chuyển từ savedata sang thành thuộc tính của camera)

@property (nonatomic) BOOL isTurnOffCallService; // isDisableCallAPI => isTurnOffCallService


// Record video
@property (nonatomic) BOOL isRecordVideoFace;
@property (nonatomic) BOOL isRecordVideoDocument;
@property (nonatomic) BOOL isRecordVideoScanQRCode;

@property (nonatomic) int videoRecordWidth;
@property (nonatomic) int videoRecordHeight;
@property (nonatomic) int videoRecordFPS;
@property (nonatomic) float videoScale;

// =====


@property (nonatomic) NSString *baseUrl;

@property (nonatomic) NSString *urlUploadImage;

@property (nonatomic) NSString *urlOcr;

@property (nonatomic) NSString *urlOcrFront;

@property (nonatomic) NSString *urlOcrBack;

@property (nonatomic) NSString *urlCompare;

@property (nonatomic) NSString *urlCompareGeneral;

@property (nonatomic) NSString *urlVerifyFace;

@property (nonatomic) NSString *urlAddFace;

@property (nonatomic) NSString *urlCheckLivenessCard;

@property (nonatomic) NSString *urlCheckMaskFace;

@property (nonatomic) NSString *urlSearchFace;

@property (nonatomic) NSString *urlLivenessFace;

@property (nonatomic) NSString *urlLivenessFace3D;

@property (nonatomic) NSString *keyHeaderRequest; // headerKey => keyHeaderRequest

@property (nonatomic) NSString *valueHeaderRequest; // headerValue => valueHeaderRequest


//Man
//=================================

// @property (nonatomic) BOOL isProVoiceOval;

// ================================= ANIMATION NANE
//
@property (nonatomic) NSString *nameOvalAnimation;
//
@property (nonatomic) NSString *nameFeedbackAnimation;
//
@property (nonatomic) NSString *nameScanQRCodeAnimation;
//
@property (nonatomic) NSString *namePreviewDocumentAnimation;
//
// tên. mặc định ""
@property (nonatomic) NSString *nameLoadSuccessAnimation;


// ================================= VIDEO NANE
@property (nonatomic) NSString *nameHelpVideoFace;
@property (nonatomic) NSString *nameHelpVideoDocument;


// Thanh header: PA 1 nút đóng bên phải. PA 2 nút đóng bên trái. mặc định là 1
@property (nonatomic) NSInteger styleHeader;

// Họa tiết dưới nền mặc định có hiện
@property (nonatomic) BOOL isUsingUnderBackground;

// màu nội dung Thanh header: Màu chữ và màu nút đóng. mặc định là FFFFFF
@property (nonatomic) UIColor *colorContentHeader;

// màu nen Thanh header. mặc định là trong suốt
@property (nonatomic) UIColor *colorBackgroundHeader;

// Màu văn bản chính - Tiêu đề & Văn bản phụ. mặc định là FFFFFF
@property (nonatomic) UIColor *colorContentMain;

// Màu nền: dùng cho màn help + preview
@property (nonatomic) UIColor *colorBackgroundMain;

// Đường line trên hướng dẫn chụp GTTT. mặc định D9D9D9
@property (nonatomic) UIColor *colorLine;

// Button và Thanh hướng dẫn khi đưa mặt vào khung oval. mặc định 18D696. hiện đang thừa (Thanh hướng dẫn khi đưa mặt vào khung oval)
@property (nonatomic) UIColor *colorBackgroundButton;

//Màu text cho button và thanh hướng dẫn khi đưa mặt vào khung oval. mặc định 142730
@property (nonatomic) UIColor *colorEkycTextButton;

// Màu nền chụp. document thì alpha = 0.5. face thì alpha = 1.0. mặc định 142730
@property (nonatomic) UIColor *colorEkycCaptureBackground;

// Màu hiệu ứng hiện đang thiếu (Thanh hướng dẫn khi đưa mặt vào khung oval). mặc định 18D696
@property (nonatomic) UIColor *colorEkycEffect;

// Màu nút chụp ảnh. mặc định là FFFFFF
@property (nonatomic) UIColor *colorEkycButtonCapture;

// Màu đường viền khung chụp mặt Oval. mặc định là FFFFFF
@property (nonatomic) UIColor *colorEkycOval;


// màu Họa tiết dưới nền. mặc định 18D696
@property (nonatomic) UIColor *colorEkycUnderBackgound;

// hiển thị logo
@property (nonatomic) BOOL isShowTrademark;

// Logo mặc định là logo vnpt
@property (nonatomic) UIImage *imageTrademark;

// Kích thước logo mặc định 38x12
@property (nonatomic) CGSize sizeLogo;

// Màu nền cho pop up mặc định FFFFFF
@property (nonatomic) UIColor *colorBackgroundPopup;

// Màu văn bản trên popup. mặc định 142730
@property (nonatomic) UIColor *colorEkycTextPopup;


// Ngưỡng cho phép khi tìm kiếm khuôn mặt
@property (nonatomic) NSInteger threshold;

// Số lượng kết quả tối đa khi tìm kiếm khuôn mặt
@property (nonatomic) NSInteger maxResult;

/* camera Delegate */
@property (weak, nonatomic) id<ICEkycCameraDelegate> cameraDelegate;

@property (nonatomic) ICEkycCameraPresenter *presenter;

#pragma mark - Các phương thức

/** Phương thức thực hiện Đăng ký THÔNG TIN CÁ NHÂN và Mã ảnh chân dung lên máy chủ
 @param object - là thông tin thực hiện đăng ký
 Dữ liệu được trả về thông qua phương thức icEkycGetResult
 */
- (void) addFaceWithObject:(NSDictionary *)object;

/** Phương thức thực hiện tìm kiếm THÔNG TIN CÁ NHÂN dựa vào Mã ảnh chân dung
 @param hashImage - là mã ảnh chân dung
 Dữ liệu được trả về thông qua phương thức icEkycGetResult
 */
- (void) searchFaceWithImage:(NSString *)hashImage;

@end

NS_ASSUME_NONNULL_END
