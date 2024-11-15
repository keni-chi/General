WSL と Ubuntu 24.04 LTS を Windows 11 にインストールする
https://qiita.com/studio_meowtoon/items/cd0c4a607d451dbf5430


'''
WSL と Ubuntu 24.04 LTS を Windows 11 にインストールする
    Microsoft Store、を開く
    Ubuntu 24.04 LTS、を検索。
    入手ボタン押下することで、インストールされる。
    開くボタンを押下することで、起動。


エラー発生対処
    エラー：WslRegisterDistribution failed with error: 0x8007019e
    https://1nux.com/archives/280
    Windows の機能の有効化または無効化
    wsl --install、で有効化。
    再起動する。


Ubuntu のセットアップ
    username
    password


Ubuntu で ハローワールド
    vim hello.sh
        #!/bin/bash
        echo "ハローワールド！"
    chmod +x hello.sh
    ./hello.sh