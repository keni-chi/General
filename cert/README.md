# 証明書

## 概要
覚書である。順次記載予定。

### 認証局
- 秘密鍵(CAroot.key)
openssl genrsa -out CAroot.key 2048
- 証明書(CAroot.pem)
openssl req -x509 -new -nodes -key CAroot.key -sha256 -days 365 -out CAroot.pem

### 中間証明書
- 秘密鍵(Verify.key)  
openssl genrsa -out Verify.key 2048  
- 証明書署名要求(Verify.csr)  
openssl req -new -key Verify.key -out Verify.csr  
- 証明書(署名の実行)(Verify.crt)  
openssl x509 -req -in Verify.csr -CA CAroot.pem -CAkey CAroot.key -CAcreateserial -out Verify.crt -days 365 -sha256  
証明書=署名付き公開鍵。公開鍵が誰の公開鍵であるかを証明している。  

### 作成した証明書をAWS IoTへ登録
- 証明書をAWS IoTへ登録  
aws iot register-ca-certificate --ca-certificate file://CAroot.pem --verification-certificate file://Verify.crt  
- statusとautoRegistrationStatusが有効化されていないので、これらを以下のコマンド有効にする。  
aws iot update-ca-certificate --certificate-id $YOUR_CA_CERT_ID --new-status ACTIVE  
aws iot update-ca-certificate --certificate-id $YOUR_CA_CERT_ID --new-auto-registration-status ENABLE  

### Device用証明書
- 秘密鍵(deviceCert.key)  
openssl genrsa -out deviceCert.key 2048  
- 証明書署名要求(deviceCert.csr)  
openssl req -new -key deviceCert.key -out deviceCert.csr  
- 証明書(署名の実行)(deviceCert.crt)  
openssl x509 -req -in deviceCert.csr -CA ../CA/CAroot.pem -CAkey ../CA/CAroot.key -CAcreateserial -out deviceCert.crt -days 365 -sha256  
- Just in Timeで利用する証明書を作成
cat deviceCert.crt ../CA/CAroot.pem > deviceCertAndCA.crt


## 参考
[AWS IoT 証明書のJust In Time登録](https://qiita.com/TakashiKOYANAGAWA/items/b3b679e2a7d56f144a8e)
[RSA鍵、証明書のファイルフォーマットについて](https://qiita.com/kunichiko/items/12cbccaadcbf41c72735)
