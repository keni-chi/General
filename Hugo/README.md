# HUGO  

## 概要  
覚書である。順次記載予定。  

### 構築   
setx path "PATH=%PATH%;C:\Hugo\bin"  
hugo version  

### 初期設定  
hugo new site quickstart   
cd quickstart  
git init  
git clone https://github.com/budparr/gohugo-theme-ananke.git themes/ananke  
echo theme = "ananke" >> config.toml  

### サンプル作成  
hugo new posts/my-first-post.md  
hugo server -D  
http://localhost:1313/  

### テーマ変更  
git clone https://github.com/mismith0227/hugo_theme_pickles.git themes/hugo_theme_pickles　　
hugo new posts/2回めの投稿.md　　
hugo server -t hugo_theme_pickles -w -D　　
http://localhost:1313/　　

### 参考   
https://www.imuza.com/entry/2018/02/09/164628   
https://qiita.com/spiegel-im-spiegel/items/eac7bf2a3c0fc19afcbf   
