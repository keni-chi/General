# Sphinx  

## 概要  
覚書である。順次記載予定。  

### 構築   
pip install sphinx  
フォルダを作成して移動し、"sphinx-quickstart"を打つ  

### ビルド    
cd docs  
make html  (sphinx-build -b html source build と同じ)  
ブラウザでdocs/build/html/index.htmlを開く

### カスタム   
docs/source配下にmyroomフォルダを作成  
docs/source/index.rstを編集  
docs/source/myroom/index.rstを作成  
make html  

### 参考   
https://qiita.com/louvre2489/items/14271139626341f3fb27


## SAMでのビルド
pip install sphinx_rtd_theme
make html
