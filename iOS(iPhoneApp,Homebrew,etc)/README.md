# iOS(iPhoneApp,Homebrew,etc)

## 概要
Macbookでの開発環境、iOS上でXcodeを用いてswiftによるiPhoneアプリの開発、などの覚書である。   

## iPhoneApp

### シミュレータでの開発手順
1. Xcodeをインストール  
1. プロジェクトを作成  
1. Main.storyboardをInterface Builderで編集する。  
1. ViewController.swiftを編集する。  
1. Main.storyboardを開き、ViewController.swift内にあるimageViewという変数と、Interface Builderのイメージビューを紐付け。  
1. 画像を登録  
1. ビルド    

### 実機での開発手順
1. AppleIDを取得。
1. Xcodeにて、AppleIDを追加。
1. Xcodeにて、証明書を作成。
1. MacとiPhoneをLightningUSBケーブルで接続する。Xcodeにて、Simulator以外に実機も選択できるようになることを確認。
1. Xcodeにて、「General」の「Signing」に戻りTeamを今設定したApple ID。
1. Xcodeにて、ビルド。※1
1. iPhoneにて、「設定」「一般」から「デバイス管理」に入り、信頼すると設定。※2
1. iPhoneにて、アプリが入っていることを確認。
1. iPhoneにて、タップして動作することを確認。  

※1 私の場合、以下のエラーに遭遇した。   
- iPhone側のiOSのバージョンが古い。  
これはiPhoneのiOSのバージョンを最新にすることで解決した。
注意点として、「バージョンアップに時間がかかる(私の場合は30分くらいかかった)」「途中でフリーズするといた記事も散見される」、といったことがある。そのため、実行する前に「作業時間に余裕があるか(電話やLineも一時的にできなくなる)」「Wi-Fi環境は安定しているか(バージョンアップ失敗の要因となる)」「iPhoneデータのバックアップは取っているか」「もう使っていないiPhoneで試せないか」などを考慮した方が良い。

- 「codesign ~~ キーチェーン ~~」 
これはMacBookのパスワードを入力すればOKだった。

- 「~~ is trusted on your device. ~~ to General -> Device Management, ~~」  
これはiPhone側で「信頼」を設定すれば解決した。※2  


## Homebrewインストール

1. 以下urlにて、インストールコマンドを確認して実行する。   
https://brew.sh/index_ja.html  
```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

2. 動作環境確認
```
brew doctor
```

3. Warnig対応  
.bash_profileにbrewコマンドのaliasを追加する。
```
alias brew="PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin brew"
```

4. バージョン確認
```
brew --version
```  

## yarn,nodeのインストール

### 失敗
brew install yarn  
.base_profile にPATHを通す。
```  
export PATH="$HOME/.yarn/bin:$PATH"
```  
```  
error angular-srcs@7.2.10: The engine "node" is incompatible with this module. Expected version ">=10.9.0 <11.0.0". Got "12.1.0"
error angular-srcs@7.2.10: The engine "yarn" is incompatible with this module. Expected version ">=1.12.1 <=1.14.0". Got "1.15.2"
error Found incompatible module
```  

npm install -g yarn@1.13  
npm install -g node@10.9.0

brew install node  
.bash_profile  
npm export PATH=“/usr/local/share/npm/bin:$PATH”


### 成功
[MacにNode.jsをインストール](https://qiita.com/kyosuke5_20/items/c5f68fc9d89b84c0df09)


brew install nodebrew  
nodebrew -v  
echo 'export PATH=$HOME/.nodebrew/current/bin:$PATH' >> ~/.bash_profile  
mkdir -p ~/.nodebrew/src  
nodebrew install-binary 10.9.0  

nodebrew ls  
nodebrew use v10.9.0  
node -v  

npm install -g yarn@1.13  




## 参考
[iPhoneアプリ](https://udemy.benesse.co.jp/development/ios/how-to-use-xcode.html)  
[実機1](https://i-app-tec.com/ios/device-test.html)  
[実機2](https://qiita.com/segur/items/bef54efa7764885173bb)  
[Homebrew1](https://qiita.com/krtsatoqiita/items/ba567acacb93a7a02dd9)  
[Homebrew2](https://qiita.com/takuya0301/items/695f42f6904e979f0152)  
[yarnを使ってみた](https://qiita.com/masterkey1009/items/50f95b1187646a7db385)  
[【2020年版】 React NativeでiOSアプリを作ってストアでリリースしてみた](https://qiita.com/ariiyu/items/93a2d829df684c02ea5d)  
[Windows機でiOSアプリの開発から実機インストールまで行ってみる【ReactNative】～開発編～](https://qiita.com/BanaoLihua/items/ef37009849917e3e56ff)  
[ReactNativeだとカメラアプリくらいなら1時間で作れた](https://qiita.com/yotsak/items/687c79b2108b1435a2bc)  
