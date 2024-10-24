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


// Thuộc tính dùng để Bật/Tắt việc hiển thị LOG khi thực hiện eKYC
@property (nonatomic) BOOL isPrintLogRequest;



// Phương thức thực hiện khởi tạo hoặc Cài đặt lại giá trị cho các thuộc tính
- (void) resetOrInitAllData;



// Dữ liệu bóc tách thông tin giấy tờ OCR - Optical character recognition (Nhận dạng ký tự quang học)
@property (nonatomic) NSString *ocrResult;


// Giá trị các ngưỡng cắt ảnh giấy tờ. Giá trị dạng (x,y) trong đó x là tỉ lệ từ TOP đến điểm cắt, y là tỉ lệ từ BOTTOM đến điểm cắt
@property (nonatomic) NSString *cropedParam;


// Dữ liệu kiểm tra ảnh giấy tờ MẶT TRƯỚC chụp trực tiếp hay không
@property (nonatomic) NSString *livenessCardFrontResult;


// Dữ liệu kiểm tra ảnh giấy tờ MẶT SAU chụp trực tiếp hay không
@property (nonatomic) NSString *livenessCardBackResult;


// Dữ liệu việc QUÉT mã QR
@property (nonatomic) NSString *scanQRCodeResult;


// Dữ liệu thực hiện SO SÁNH khuôn mặt (lấy từ mặt trước ảnh giấy tờ hoặc ảnh thẻ)
@property (nonatomic) NSString *compareFaceResult;


// Dữ liệu kiểm tra ảnh CHÂN DUNG chụp trực tiếp hay không
@property (nonatomic) NSString *livenessFaceResult;


// Dữ liệu XÁC THỰC ảnh CHÂN DUNG và SỐ GIẤY TỜ
@property (nonatomic) NSString *verifyFaceResult;


// Dữ liệu kiểm tra ảnh CHÂN DUNG có bị che mặt hay không
@property (nonatomic) NSString *maskedFaceResult;


// Dữ liệu kết quả đăng ký thông tin KHUÔN MẶT
@property (nonatomic) NSString *addFaceResult;


// Dữ liệu kết quả đăng ký thông tin THẺ
@property (nonatomic) NSString *addCardIDResult;


// Dữ liệu thực hiện TÌM KIẾM khuôn mặt
@property (nonatomic) NSString *searchFaceResult;


// Dữ liệu đoạn mã khi ứng dụng bật chức năng WaterMark
@property (nonatomic) NSString *tokenWaterMark;


// Dữ liệu để xác định cách giao dịch (yêu cầu) cùng nằm trong cùng một phiên
@property (nonatomic) NSString *clientSessionResult;


// Phiên bản hiện tại của SDK
@property (nonatomic) NSString *versionICEkycSdk;


// Trả ra kết quả khi kết nối mạng gặp Vấn đề phát sinh khi thực hiện eKYC
@property (nonatomic) NSString *networkProblem;


// [Thông tin ảnh ở bước quét mã QR]
// Ảnh đầy đủ khi quét thành công mã QR
@property (nonatomic) UIImage *imageQRCode;
// Đường dẫn Ảnh đầy đủ khi quét thành công mã QR
@property (nonatomic) NSURL *pathImageQRCode;
// Ảnh [mã QR đã được cắt] khi quét thành công
@property (nonatomic) UIImage *imageCropedQRCode;
// Đường dẫn Ảnh [mã QR đã được cắt] khi quét thành công
@property (nonatomic) NSURL *pathImageCropedQRCode;
// Mã ảnh đầy đủ khi quét thành công mã QR sau khi tải lên máy chủ
@property (nonatomic) NSString *hashImageQRCode;


// [Thông tin ảnh mặt trước]
// Ảnh đầy đủ khi chụp giấy tờ mặt trước
@property (nonatomic) UIImage *imageFront;
// Đường dẫn Ảnh đầy đủ khi chụp giấy tờ mặt trước
@property (nonatomic) NSURL *pathImageFront;
// Ảnh [chụp giấy tờ mặt trước] đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) UIImage *imageCropedFront;
// Đường dẫn Ảnh [chụp giấy tờ mặt trước] đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) NSURL *pathImageCropedFront;
// Mã ảnh giấy tờ mặt trước sau khi tải lên máy chủ
@property (nonatomic) NSString *hashImageFront;


// [Thông tin ảnh mặt sau]
// Ảnh đầy đủ khi chụp giấy tờ mặt sau
@property (nonatomic) UIImage *imageBack;
// Đường dẫn Ảnh đầy đủ khi chụp giấy tờ mặt trước
@property (nonatomic) NSURL *pathImageBack;
// Ảnh [chụp giấy tờ mặt sau] đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) UIImage *imageCropedBack;
// Đường dẫn Ảnh [chụp giấy tờ mặt trước] đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) NSURL *pathImageCropedBack;
// Mã ảnh giấy tờ mặt sau sau khi tải lên máy chủ
@property (nonatomic) NSString *hashImageBack;


// [Thông tin ảnh chân dung chụp thẳng 01 hướng]
// Ảnh đầy đủ khi chụp ảnh chân dung thẳng
@property (nonatomic) UIImage *imageFace;
// Đường dẫn Ảnh đầy đủ khi chụp ảnh chân dung thẳng
@property (nonatomic) NSURL *pathImageFace;
// Ảnh chân dung thẳng đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) UIImage *imageCropedFace;
// Đường dẫn Ảnh chân dung thẳng đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) NSURL *pathImageCropedFace;
// Mã ảnh chân dung chụp thẳng sau khi tải lên máy chủ
@property (nonatomic) NSString *hashImageFace;


// [Thông tin ảnh chân dung xa]
// Ảnh đầy đủ khi chụp ảnh chân dung xa
@property (nonatomic) UIImage *imageFaceFar;
// Đường dẫn Ảnh đầy đủ khi chụp ảnh chân dung xa
@property (nonatomic) NSURL *pathImageFaceFar;
// Ảnh chân dung chụp xa đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) UIImage *imageCropedFaceFar;
// Đường dẫn Ảnh chân dung chụp xa đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) NSURL *pathImageCropedFaceFar;
// Mã ảnh chân dung chụp xa sau khi tải lên máy chủ
@property (nonatomic) NSString *hashImageFar;


// [Thông tin ảnh chân dung gần]
// Ảnh đầy đủ khi chụp ảnh chân dung gần
@property (nonatomic) UIImage *imageFaceNear;
// Đường dẫn Ảnh đầy đủ khi chụp ảnh chân dung gần
@property (nonatomic) NSURL *pathImageFaceNear;
// Ảnh chân dung chụp gần đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) UIImage *imageCropedFaceNear;
// Đường dẫn Ảnh chân dung chụp gần đã cắt được trả ra để ứng dụng hiển thị
@property (nonatomic) NSURL *pathImageCropedFaceNear;
// Mã ảnh chân dung chụp gần sau khi tải lên máy chủ
@property (nonatomic) NSString *hashImageNear;


// [Thông tin Dữ liệu quét khuôn mặt]
// Dữ liệu quét khuôn mặt
@property (nonatomic) NSData *dataScan3D;
// Mã ảnh dữ liệu quét khuôn mặt sau khi tải lên máy chủ
@property (nonatomic) NSString *hashDataScan3D;


// [Đường dẫn VIDEO sau khi quay lại quá trình thao tác]
// Đường dẫn VIDEO quay lại quá trình quét mã QR
@property (nonatomic) NSURL *pathVideoRecordScanQRCode;
// Đường dẫn VIDEO quay lại quá trình chụp ảnh giấy tờ
@property (nonatomic) NSURL *pathVideoRecordDocument;
// Đường dẫn VIDEO quay lại quá trình chụp ảnh chân dung xa gần
@property (nonatomic) NSURL *pathVideoRecordFace;

@end

NS_ASSUME_NONNULL_END
