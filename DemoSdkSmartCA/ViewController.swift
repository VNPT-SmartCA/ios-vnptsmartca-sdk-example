//
//  ViewController.swift
//  DemoSdkSmartCA
//
//  Created by AlwaysSmile on 06/12/2023.
//

import UIKit
import SmartCASDK
import FlutterPluginRegistrant

class ViewController: UIViewController {
    
    @IBOutlet weak var txtTranID: UITextField!
    
    var vnptSmartCASDK: VNPTSmartCASDK?
    var tranId = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.vnptSmartCASDK = VNPTSmartCASDK(
            viewController: self,
            partnerId: "CLIENT_ID",
            environment: VNPTSmartCASDK.ENVIRONMENT.DEMO,
            lang: VNPTSmartCASDK.LANG.VI,
            isFlutterApp: false)
        
        GeneratedPluginRegistrant.register(with: self.vnptSmartCASDK?.flutterEngine as! FlutterPluginRegistry);

        
        self.hideKeyboardWhenTappedAround()
    }
    
    // Lấy thông tin về AccessToken & Credential
    @IBAction func getAuthentication(_ sender: Any) {
        // SDK tự động xử lý các trường hợp về token: Hết hạn, chưa kích hoạt...
        self.vnptSmartCASDK?.getAuthentication(callback: { authResult in
            if authResult.status == SmartCAResultCode.SUCCESS_CODE {
                self.showDialog(title: "Đã kích hoạt thành công", message: "\(authResult.data)")
                // SDK trả lại token, credential của khách hàng
                // Đối tác tạo transaction cho khách hàng để lấy transId, sau đó gọi getWaitingTransaction
            } else {
                // SDK tự động hiển thị giao diện
            }
        });
    }
    
    @IBAction func getMainInfo(_ sender: Any) {
        self.vnptSmartCASDK?.getMainInfo(callback: { result in
            print(result)
        })
    }
    
    // Khách hàng xác nhận / hủy giao dịch.
    @IBAction func getWaitingTransaction(_ sender: Any) {
        if self.txtTranID.text != "" {
            self.tranId = self.txtTranID.text ?? ""
            
            self.vnptSmartCASDK?.getWaitingTransaction(tranId: self.tranId, callback: { wtResult in
                if wtResult.status == SmartCAResultCode.SUCCESS_CODE {
                    print("Giao dịch thành công: \(wtResult.status) - \(wtResult.statusDesc)")
                    DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                        self.showDialog(title: "Giao dịch thành công", message: wtResult.statusDesc)
                    }
                } else {
                    print("Lỗi giao dịch: \(wtResult.status) - \(wtResult.statusDesc)")
                    DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                        self.showDialog(title: "Lỗi giao dịch", message: wtResult.statusDesc)
                    }
                }
            })
        } else {
            self.showDialog(title: "Có lỗi xảy ra", message: "Vui lòng điền Transaction ID")
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        self.vnptSmartCASDK?.destroySDK()
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


