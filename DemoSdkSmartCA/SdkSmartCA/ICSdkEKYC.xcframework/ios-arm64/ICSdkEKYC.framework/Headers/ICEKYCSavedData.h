//
//  ICEKYCSavedData.h
//  ICSdkEKYC
//
//  Created by Minh Nguyễn on 9/1/20.
//  Copyright © 2020 Minh Nguyễn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface ICEKYCSavedData : NSObject

+ (ICEKYCSavedData *)shared;

@property (nonatomic) NSString *authorization; // bo SD : SDAuthorization => authorization

@property (nonatomic) NSString *tokenId; // bo SD : SDTokenId => tokenId

@property (nonatomic) NSString *tokenKey; // bo SD : SDTokenKey => tokenKey

@property (nonatomic) BOOL isPrintLogRequest; // bo SD : SDTokenKey => tokenKey


- (void) resetOrInitAllData;


@property (nonatomic) NSString *ocrResult; // trả ra ngoài jsonInfo => infoResult (ocrResult)

@property (nonatomic) NSString *cropedParam; // trả ra ngoài

@property (nonatomic) NSString *livenessCardFrontResult; // trả ra ngoài // jsonCheckLivenessFrontCard livenessCardFrontResult

@property (nonatomic) NSString *livenessCardBackResult; // trả ra ngoài // jsonCheckLivenessBackCard livenessCardBackResult

@property (nonatomic) NSString *scanQRCodeResult; // trả ra ngoài scanQRCode=>scanQRCodeResult

@property (nonatomic) NSString *compareFaceResult; // trả ra ngoài // jsonCompareFace =>compareFaceResult

@property (nonatomic) NSString *livenessFaceResult; // trả ra ngoài //jsonLivenessFace livenessFaceResult

@property (nonatomic) NSString *verifyFaceResult; // trả ra ngoài //jsonVerifyFace verifyFaceResult

@property (nonatomic) NSString *maskedFaceResult; // trả ra ngoài // jsonCheckMask maskedFaceResult

@property (nonatomic) NSString *addFaceResult; // trả ra ngoài //jsonAddFace addFaceResult

@property (nonatomic) NSString *searchFaceResult; // trả ra ngoài //jsonSearchFace searchFaceResult

@property (nonatomic) NSString *tokenWaterMark; // trả ra ngoài

@property (nonatomic) NSString *clientSessionResult; // trả ra ngoài SDClientSession => clientSessionResult

@property (nonatomic) NSString *versionICEkycSdk; // trả ra ngoài

@property (nonatomic) NSString *networkProblem; // trả ra ngoài

// ảnh mã qr
@property (nonatomic) UIImage *imageQRCode; // trả ra ngoài
@property (nonatomic) NSURL *pathImageQRCode; // trả ra ngoài
@property (nonatomic) UIImage *imageCropedQRCode; // trả ra ngoài
@property (nonatomic) NSURL *pathImageCropedQRCode; // trả ra ngoài
@property (nonatomic) NSString *hashImageQRCode; // trả ra ngoài

// ảnh mặt trước
@property (nonatomic) UIImage *imageFront; // trả ra ngoài
@property (nonatomic) NSURL *pathImageFront; // trả ra ngoài
@property (nonatomic) UIImage *imageCropedFront; // trả ra ngoài
@property (nonatomic) NSURL *pathImageCropedFront; // trả ra ngoài
@property (nonatomic) NSString *hashImageFront; // trả ra ngoài

// ảnh mặt sau
@property (nonatomic) UIImage *imageBack; // trả ra ngoài
@property (nonatomic) NSURL *pathImageBack; // trả ra ngoài
@property (nonatomic) UIImage *imageCropedBack; // trả ra ngoài
@property (nonatomic) NSURL *pathImageCropedBack; // trả ra ngoài
@property (nonatomic) NSString *hashImageBack; // trả ra ngoài

// ảnh mặt thẳng
@property (nonatomic) UIImage *imageFace; // trả ra ngoài
@property (nonatomic) NSURL *pathImageFace; // trả ra ngoài
@property (nonatomic) UIImage *imageCropedFace; // trả ra ngoài
@property (nonatomic) NSURL *pathImageCropedFace; // trả ra ngoài
@property (nonatomic) NSString *hashImageFace; // trả ra ngoài

// ảnh mặt quay trái
@property (nonatomic) UIImage *imageFaceLeft; // trả ra ngoài
@property (nonatomic) NSURL *pathImageFaceLeft; // trả ra ngoài
@property (nonatomic) NSString *hashImageFaceLeft; // trả ra ngoài

// ảnh mặt quay phải
@property (nonatomic) UIImage *imageFaceRight; // trả ra ngoài
@property (nonatomic) NSURL *pathImageFaceRight; // trả ra ngoài
@property (nonatomic) NSString *hashImageFaceRight; // trả ra ngoài

// ảnh xa
@property (nonatomic) UIImage *imageFaceFar; // trả ra ngoài
@property (nonatomic) NSURL *pathImageFaceFar; // trả ra ngoài
@property (nonatomic) UIImage *imageCropedFaceFar; // trả ra ngoài
@property (nonatomic) NSURL *pathImageCropedFaceFar; // trả ra ngoài
@property (nonatomic) NSString *hashImageFar; // trả ra ngoài

// ảnh gần
@property (nonatomic) UIImage *imageFaceNear; // trả ra ngoài
@property (nonatomic) NSURL *pathImageFaceNear; // trả ra ngoài
@property (nonatomic) UIImage *imageCropedFaceNear; // trả ra ngoài
@property (nonatomic) NSURL *pathImageCropedFaceNear; // trả ra ngoài
@property (nonatomic) NSString *hashImageNear; // trả ra ngoài

// dữ liệu thực hiện quét chụp chân dung
@property (nonatomic) NSString *hashLogData; // trả ra ngoài

// record video
@property (nonatomic) NSURL *pathVideoRecordScanQRCode; // trả ra ngoài
@property (nonatomic) NSURL *pathVideoRecordDocument; // trả ra ngoài
@property (nonatomic) NSURL *pathVideoRecordFace; // trả ra ngoài

@end

NS_ASSUME_NONNULL_END
