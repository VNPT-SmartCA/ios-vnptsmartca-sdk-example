//
//  ViewController.swift
//  DemoSmartCASDK
//
//  Created by AlwaysSmile on 04/12/2023.
//  Copyright © 2023 quannm. All rights reserved.
//

import UIKit
import SmartCASDK
import FlutterPluginRegistrant

class ViewController: UIViewController {
    
    @IBOutlet weak var txtTranID: UITextField!
    
    var vnptSmartCASDK: VNPTSmartCASDK?
    var tranId = ""
    var accessToken = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.hideKeyboardWhenTappedAround()
        
        let customParams = CustomParams(
            customerId: "",                 // Số CCCD, giấy tờ của KH
            borderRadiusBtn: 0,             // Border radius của button
            colorSecondBtn: "",             // Màu background nút phụ
            colorPrimaryBtn: "",            // Màu background nút chính
            featuresLink: "",               // Đường dẫn tới trang hướng dẫn sử dụng các tính năng sdk
            customerPhone: "",              // Số ĐT của KH
            packageDefault: "",             // Gói mặc định hiển thị khi mua Chứng thư số
            password: "",                   // Password đăng nhập mặc định khi Kích hoạt tài khoản
            logoCustom: "",                 // Logo của đối tác theo mã hoá Base64
            backgroundLogin: ""             // Background của đối tác theo mã hoá Base64
        )
        
        let config = SDKConfig(
            clientId: "4185-637127995547330633.apps.signserviceapi.com",                   // clientId tương ứng với môi trường được cấp qua email
            clientSecret: "NGNhMzdmOGE-OGM2Mi00MTg0",               // clientSecret tương ứng với môi trường được cấp qua email
            environment: ENVIRONMENT.DEMO,  // Môi trường kết nối DEMO/PROD
            lang: LANG.VI,                  // Ngôn ngữ vi/en
            isFlutterApp: false,            // true nếu app là Flutter
            customParams: customParams
        )
        
        self.vnptSmartCASDK = VNPTSmartCASDK(viewController: self, config: config)
        
        guard let flutterEngine = vnptSmartCASDK?.flutterEngine else { return }
        GeneratedPluginRegistrant.register(with: flutterEngine)
    }
    
    // Lấy thông tin về AccessToken & Credential
    @IBAction func getAuthentication(_ sender: Any) {
        // SDK tự động xử lý các trường hợp về token: Hết hạn, chưa kích hoạt...
        self.vnptSmartCASDK?.getAuthentication(callback: { authResult in
            if authResult.status == SmartCAResultCode.SUCCESS_CODE {
                // Xử lý khi thành công
                self.showDialog(title: "Đã kích hoạt thành công", message: "\(authResult.data)")
                // SDK trả lại token, credential của khách hàng
                guard let data = self.getJsonFromString(str: authResult.data) else { return }
                self.accessToken = data["accessToken"] as? String ?? ""
                // Đối tác tạo transaction cho khách hàng để lấy transId, sau đó gọi getWaitingTransaction
            } else {
                // Xử lý khi có lỗi
                // SDK tự động hiển thị giao diện
            }
        })
    }
    
    // Quản lý tài khoản
    @IBAction func getMainInfo(_ sender: Any) {
        self.vnptSmartCASDK?.getMainInfo(callback: { result in
            if result.status == SmartCAResultCode.SUCCESS_CODE {
                // Xử lý khi thành công
            } else {
                // Xử lý khi có lỗi
                print("Thông tin lỗi: \(result.status) - \(result.statusDesc) - \(result.data)")
            }
        })
    }
    
    // Khách hàng xác nhận / hủy giao dịch.
    @IBAction func getWaitingTransaction(_ sender: Any) {
        if self.txtTranID.text != "" {
            self.tranId = self.txtTranID.text ?? ""
            
            self.vnptSmartCASDK?.getWaitingTransaction(tranId: self.tranId, callback: { result in
                if result.status == SmartCAResultCode.SUCCESS_CODE {
                    // Xử lý khi thành công
                    print("Giao dịch thành công: \(result.status) - \(result.statusDesc) - \(result.data)")
                    DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                        self.showDialog(title: "Giao dịch thành công", message: result.statusDesc)
                    }
                } else {
                    // Xử lý khi có lỗi
                    print("Thông tin lỗi: \(result.status) - \(result.statusDesc) - \(result.data)")
                    DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                        self.showDialog(title: "Lỗi giao dịch", message: result.statusDesc)
                    }
                }
            })
        } else {
            self.showDialog(title: "Có lỗi xảy ra", message: "Vui lòng điền Transaction ID")
        }
    }
    
    // Hiển thị màn hình tạo tài khoản
    @IBAction func createAccount(_ sender: Any) {
        self.vnptSmartCASDK?.createAccount(callback: { result in
            if result.status == SmartCAResultCode.SUCCESS_CODE {
                // Xử lý khi thành công
            } else {
                // Xử lý khi có lỗi
                print("Thông tin lỗi: \(result.status) - \(result.statusDesc) - \(result.data)")
            }
        })
    }
    
    // Logout
    @IBAction func signOut(_ sender: Any) {
        self.vnptSmartCASDK?.signOut(callback: { result in
            if result.status == SmartCAResultCode.SUCCESS_CODE {
                // Xử lý khi thành công
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                    self.showDialog(title: "Thông báo", message: "Đăng xuất thành công")
                }
            } else {
                // Xử lý khi có lỗi
                print("Thông tin lỗi: \(result.status) - \(result.statusDesc) - \(result.data)")
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                    self.showDialog(title: "Thông báo", message: "Đăng xuất không thành công")
                }
            }
        })
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        self.vnptSmartCASDK?.destroySDK()
    }
    
    func getJsonFromString(str: String) -> [String: Any]? {
        guard let data = str.data(using: .utf8) else { return nil }
        var json: [String: Any]? = nil
        do {
            json = try JSONSerialization.jsonObject(with: data, options : .allowFragments) as? [String: Any]
        } catch let error as NSError {
            print(error)
        }
        return json
    }
}

extension UIViewController {
    func showDialog(title: String, message: String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: NSLocalizedString("OK", comment: "Default action"), style: .default, handler: { _ in
            alert.dismiss(animated: true, completion: nil)
        }))
        self.present(alert, animated: true, completion: nil)
    }
    
    func hideKeyboardWhenTappedAround() {
        let tap = UITapGestureRecognizer(target: self, action: #selector(UIViewController.dismissKeyboard))
        tap.cancelsTouchesInView = false
        view.addGestureRecognizer(tap)
    }
    
    @objc func dismissKeyboard() {
        view.endEditing(true)
    }
}
