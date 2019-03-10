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
1. Xcodeにて、でAppleIDを追加。
1. Xcodeにて、証明書を作成。
1. Mac とiPhone をLightning USB ケーブルで接続する。Xcodeにて、Simulator以外に実機も選択できるようになることを確認。
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

## 参考
[iPhoneアプリ](https://udemy.benesse.co.jp/development/ios/how-to-use-xcode.html)  
[実機1](https://i-app-tec.com/ios/device-test.html)  
[実機2](https://qiita.com/segur/items/bef54efa7764885173bb)  
[Homebrew1](https://qiita.com/krtsatoqiita/items/ba567acacb93a7a02dd9)  
[Homebrew2](https://qiita.com/takuya0301/items/695f42f6904e979f0152)
