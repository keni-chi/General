# proxy

## 概要
覚書である。順次記載予定。

### 詳細
■コンソール  
set HTTP_PROXY=http://{IP}:{port}  
set HTTPS_PROXY=http://{IP}:{port}　　

set HTTP_PROXY=http://{ユーザ名}:{パスワード}@{IP}:{port}  
set HTTPS_PROXY=http://{ユーザ名}:{パスワード}@{IP}:{port}　　

■Python  
pip install keras --proxy http://{ユーザ名}:{パスワード}@{IP}:{port}  

■npm  
npm config set http-proxy http://{ユーザ名}:{パスワード}@{IP}:{port}  
npm config set https-proxy http://{ユーザ名}:{パスワード}@{IP}:{port}  

■curl  
curl -v --cert deviceCertAndCACert.crt --key deviceCert.key -H "x-amzn-iot-thingname: xxx" https://xxx.credentials.iot.ap-northeast-1.amazonaws.com/role-aliases/xxx/credentials --proxy "http://{IP}:{port}"  

■Eclipse  
-Dhttp.proxyHost={IP} -Dhttp.proxyPort={port} -Dhttps.proxyHost={IP} -Dhttps.proxyPort={port} -Dhttp.nonProxyHosts=127.0.0.1
