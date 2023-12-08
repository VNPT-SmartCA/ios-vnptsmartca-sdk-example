# Tích hợp iOS

-    Yêu cầu iOS >= 13.0

## Bước 1: Tải SDK và cấu hình Project
-    Tải phiên bản SDK mới nhất từ link sau: https://github.com/VNPT-SmartCA/ios_vnptsmartca_sdk

-    Kéo thả toàn bộ file *.xcframework và *.framework vào trong project. Đi tới Targets Project -> General -> Frameworks, Libraries, and Embedded Content, ngoại trừ 2 thư viện FlutterPluginRegistrant.xcframework và permission_handler_apple.xcframework cấu hình Do not Embed, tất cả các thư viện còn lại cấu hình Embed & Sign

## Bước 2: Khởi tạo SDK tại nơi bắt đầu kết nối
- Code tại **ViewController**
```swift
// import thư viện
import SmartCASDK

//Khai báo biến
var vnptSmartCASDK: VNPTSmartCASDK?

// Khởi tạo SDK 
override func viewDidLoad() {
    super.viewDidLoad()
        
    self.vnptSmartCASDK = VNPTSmartCASDK(
        viewController: self,
        partnerId: "CLIENT_ID",
        environment: VNPTSmartCASDK.ENVIRONMENT.DEMO,
        lang: VNPTSmartCASDK.LANG.VI,
        isFlutterApp: false)
    //isFlutterApp: true nếu app của bạn là Flutter, false nếu app của bạn là native
    //... 
    //Code của project
}
```

## Bước 3: Sử dụng các hàm chính
<!-- - Đăng ký cấp chứng thư số -->
- Kích hoạt tài khoản /lấy thông tin xác thực người dùng (accessToken & credentiald)
- Xác nhận giao dịch ký số
- Xem thông tin khác: Lịch sử giao dịch, Thông tin chứng thư, Tài khoản
- Hủy kết nối SDK

### 📦 Hàm kích hoạt tài khoản, lấy accessToken và credentialId của người dùng

- SDK sẽ thực hiện kiểm tra trạng thái tài khoản và chứng thư của khách hàng như: đã kích hoạt hay chưa, chứng thư hợp lệ hay không, tự động làm mới token khi hết hạn. Thành công SDK sẽ trả về **accessToken** và **credentialId** của người dùng.
```swift
@objc func getAuthentication() {
    // SDK tự động xử lý các trường hợp về token: Hết hạn, chưa kích hoạt...
      self.vnptSmartCASDK?.getAuthentication(callback: { result in
            if result.status == SmartCAResultCode.SUCCESS_CODE {
                // Xử lý khi thành công
            } else {
                // Xử lý khi thất bại
            }
        });
}
```
### 📦 Hàm xác nhận giao dịch

- Sau khi lấy được **accessToken và credentialId** của người dùng từ **getAuthentication**, từ phía **Backend** của Đối tác tạo giao dịch ký số cho khách hàng, lấy **tranId** sau đó gọi hàm xác nhận ký số.

```swift
@objc func getWaitingTransaction() {
    self.tranId = "xxxx"; // tạo giao dịch từ backend, lấy tranId từ hệ thống VNPT SmartCA trả về

    self.vnptSmartCASDK?.getWaitingTransaction(tranId: self.tranId, callback: { result in
        if result.status == SmartCAResultCode.SUCCESS_CODE {
            print("Giao dịch thành công: \(result.status) - \(result.statusDesc) - \(result.data)");
        } else {
            print("Lỗi giao dịch: \(result.status) - \(result.statusDesc) - \(result.data)");
        }
    });
}
```

### 📦 Hàm xem: Lịch sử giao dịch, thông tin Chứng thư, thông tin Tài khoản

```swift
@objc func  getMainInfo(){
    self.vnptSmartCASDK?.getMainInfo(callback: { result in
        
    })
}
```

### 📦 Hàm hủy kết nối với SDK

```swift
override func viewDidDisappear(_ animated: Bool) {
    self.vnptSmartCASDK?.destroySDK();
}
```
