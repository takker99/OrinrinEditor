# Orinrin Editor

- Auther:
SikigamiHNQ
- License:
GPLv3:
- OS:
Windows2000 SP4 以上（多分）
- version:
Ver0.341 Aurora
- External libraries:
SQlite3、imgctlを使用

## Summary

OrinrinEditorは、ＡＡで綴るストーリー、いわゆる、やる夫スレの作成支援をします。
ＡＡの貼付、合成、MLT、ASTファイルによる頁作成に対応しています。
簡易的なトレス支援機能もあります。

OrinrinEditorはまだまだ開発中です。突然落ちることも良くあります。
こまめに保存をし、バックアップ設定も忘れないでね！どうなっても知らんぞー！

起動に必要なファイルは全て同梱してあります。
.NET Frameworkとかのランタイムは特に必要ないです。

ですが、スレ作成に当たってはＡＡを収録してあるファイルがほぼ必須です。
やる夫AA録２さん等からダウンロードしてください。


## ライセンスとか

OrinrinEditorは、GNU General Public License Version3 に従って配布します。
要するにフリーソフトです。誰でも、自由に使用する事が出来ます。
2ch、やる夫スレ、東方Project、ニコニコ動画を好きであればなおいいですとも！
SQlite3はこのソフトとは別なので、そちらのライセンスが適用されます。
パブリックドメインだけど。

ソースコードは、今のところGithubにおいてあります。OrinrinEditorで検索すれば
出てくるはずです。コンパイルの詳細とかはそっちを見てね。


## 特徴

AAを合成するときに、通常の全角・半角スペースでは対応出来ない空白幅がある場合、
自動的にユニコード空白を使用してズレないように合成します。（使わない設定も有り）
※ユニコードはかなりバイト数を消費するので、大きな合成をすると
通常の１レス限界である4096byteを超える場合が良くあります。

空白を、上書きではなく透過させて合成できます。窓の向こうにいる人物、といった
ＡＡ合成が簡単にできます。もちろんユニコード空白でズレも無し。
※以下、特に断らない限り、空白とは、全角・半角・ユニコード空白の全てを含みます。

最大２０セットの枠のデザインを登録でき、自在に使い分けられます。
もちろんズレないように合成できます。任意の位置に枠を挿入することもできます。

縦書き、ＡＡ文字の入力支援機能があります。そういうのを簡単に配置できます。

簡易的なトレス機能があります。PNG、JPEG、GIF、BMPを下絵にしてＡＡが作れます。



## 更新内容（Ver0.341）2015/01/26

```
枠編集で、幅０になるような指定がされるとアプリ毎ブッ飛ぶのを修正。ただし枠構造はおかしくなる。
ASTでもMLTでもなく、１００行以上あるファイル（多分ベタテキスト）について、分割して取り込む機能を追加
　（分割条件）４０行以降で４行以上の空きがあるか、１００行以降で１行以上の空きがあるか、２５６行以上続いている
MLT2HTMLを使ったHTMLエクスポート機能を追加
したらば仕様変更による文字化け文字の拡大に対応。
　設定でチェックＯＮにしたら、一旦ＯＥを再起動してね。既に開いてるファイルの再読み込みが必要なので。

※MLT2HTMLについては、一般設定から、実行ファイルを指定しておいてね
※デカファイル読み込みがちょっとバグってたの修正
```

## ファイル構成

```
OrinrinEditor.exe　　　実行ファイル
Today_Hint.txt 　　　　今日のヒントの内容ファイル
Utuho.ini　　　　　　　構成設定
Satori.ini 　　　　　　枠設定
sqlite3.dll　　　　　　データベースSQLite3ライブラリ
imgctl.dll 　　　　　　画像コントロールライブラリ
Templates/
├─UserItem.ast 　　　　挿入用テンプレートファイル
├─Preview.htm　　　　　プレビュー用のテンプレファイル
├─aabrush.txt　　　　　塗り潰し用テンプレートファイル※
├─aalist.txt 　　　　　壱行テンプレートファイル※
├─hantenX.txt　　　　　左右反転テンプレートファイル※
└─hantenY.txt　　　　　上下反転テンプレートファイル※
　※（´д｀）Edit用のがそのまま使えます
 ```

## 最初に

初めて起動する場合は、ウインドウサイズは割と小さい状態です。
作業しやすいようにサイズ変更と位置調整してください。
また、簡易的なAA説明書が開いている状態のはずです。一通り見てください。

次に、プロファイルの作成をします。
作成については、別途プロファイルについての説明ファイルを見てください。

ここまで出来たら、作成を始められますが、先に設定を見ておきましょう。
メニューの、「ファイル」＞「一般設定」にあります。


## 対応ファイルについて

編集できるのは、TXT、MLT、ASTファイルです。
複数行テンプレートでは、MLT、ASTファイルを使用出来ます。

文字コードはShiftJISである必要があります。
実体参照は、１０進数表記、１６進数表記、キーワード表記に対応しています。
&#9829;　　&#0x2665;　　&hearts;
> 読込は全部ＯＫですが、書出は１０進数表記もしくは１６進数表記になります。

## UTF8出力

オマケ的機能として、UTF8形式での書出ができます。「名前を付けて保存」で
保存ダイヤログを開き、ファイルの種類に入っているのでそっちを選択して保存します。

## 右クリックメニューの編集

編集エリアで右クリックすると出てくる、コンテキストメニューの内容を編集できます。
メニューの、「ファイル」＞「右クリックメニューの編集」から出来ます。


## 編集エリアの配色編集

背景色、文字色、ユニコード文字背景色等の、一部の配色を変更出来ます。
変更を有効にするには、一旦アプリを起動し直す必要があります。

## ShiftJISコピーとユニコードコピーについて

ユニコードコピーの場合は、ハートマーク等のユニコード文字もそのままコピーしますが、
ShiftJISコピーすると、ハートマークなら &#9829; の形にしてコピーします。
スレに投下する場合、ShiftJISコピーをする必要があります。
ユニコードコピーしちゃうと、ユニコード文字が ? になっちゃいます。

## 編集中のユニコードモードのON/OFFについて

普段はユニコード使わないが、特別なコマには使いたい、そんな時のために、
ツールバーに、ユニコード空白の使用／不使用トグルボタンがあります。
クリック一発で、いつでもモード変換できます。

## 機能詳細

### レイヤボックス [ Alt + Space ]

主にＡＡの合成を行えます。レイヤボックス内のテキストの簡易編集機能もあります。
半透明なので、位置合わせが簡単に行えます。複数同時に開くことができるので、
レイアウトの検討にもNice boat.　レイヤボックスの内容削除ボタンもついてます。

#### 透過について

レイヤボックス内の、透過させたい空白領域をダブルクリックすると、その行の
空白部分が灰色になります。右クリメニューから、全透過、透過キャンセルが出来ます。
この状態で上書すると、灰色の部分は上書せず、下絵のＡＡを表示します。
また、AAエリアに右クリメニューがあります。全ての空白を透過にしたり解除したりできます。


### 矩形選択 [ Ctrl Alt + B ]

選択範囲を、矩形に出来ます。


### ドラフトボード [ Ctrl + Space ]

クリップボード拡張のようなもので、AAを１５個までため込んでおくことができます。
（１６個目が追加されると、一番古いものが削除されます）
例えば、エフェクトαとエフェクトβ、どっちを使おうか、というときに、両方を
ドラフトボードに追加しておくと、探し直す手間がありません。
使い方はいろいろです。


### 複数行テンプレのサムネイル表示 [ Ctrl + T ]

複数行テンプレで開いているMLT(AST)の内容を、サムネイルの形式で表示します。
テンプレ窓、編集エリア、どちらでも表示させられます。


### 文字ＡＡ変換機能

入力した文字を、文字のＡＡに置き換えて挿入出来ます。
文字ＡＡを収録したファイルが必要です。

#### 設定方法 ：

まず、文字ＡＡ変換ボックスを開きます。メニューの「挿入」にあります。
次に、歯車のマークの「使用ファイル設定」をクリックします。
そうしたら、リストっぽい枠が出てくるので、そこに文字ＡＡファイルを
ドラッグ＆ドロッペします。何個でも登録出来ます。登録したら、リストの左端にある
チェックマークを付けます。これが、実際に変換のときに使うファイルになります。
字体の異なるファイルを登録しておき、必要に応じてチェックを入れ替える、とか出来ます。
チェックができたら、「使用ファイル更新」します。これで、文字ＡＡの内容が取り込まれます。
登録出来たら、「使用ファイル設定」をもう一度クリックすると元に戻ります。

####挿入方法 ：

入力枠に、テキストを打ち込みます。編集エリア側にある、表示枠内に
反映されます。改行も反映されます。登録がない文字は、適当な大きさの空白になります。
大体入力した感じに配置されるので、適当に改行や空白で位置調整しましょう。
挿入したい位置に表示枠をおいて、「文字ＡＡ挿入」すると、その位置に文字ＡＡが挿入されます。

### 縦書き機能

入力した文字列を、縦書きで表示します。
設定が特に無い事以外は、文字ＡＡ変換と大体同じ感じです。


### 左右反転、上下反転

選択している範囲、もしくは頁全体を、左右反転、上下反転することが出来ます。
変換にもちいるのは、（´д｀）Editで使っている hantenX.txt、hantenY.txt です。
Templatesディレクトリに入れて使ってね。


### 枠挿入機能 [ Ctrl + W ]

あらかじめ２０種類の枠線を登録しておくことができます。
枠線を、レイヤボックスのような透過窓で、自在な位置に挿入することができます。
枠線のパーツは、上下左右と四隅でそれぞれ設定できます。
ただし、機械的に配置するだけなので、細かい修正は手で行なってね。


### 矩形貼付

通常のコピーした内容でも、キャレットの位置に、矩形として貼付（挿入）することが出来ます。


### 台詞挿入Enter機能 [ Shift + Enter ]

Enterした行の、最後の空白位置（≒台詞の始まり位置）に合わせて、
次の行をそこまで空白で埋めて、そこにキャレットを移動します。
台詞入力時のキャレット移動と位置合わせの支援です。


### ユーザ定義ファイル

「Templates」ディレクトリ内の「UserItem.ast」の内容を、１６個まで取り込んで
メニューに追加できます。ＡＳＴの、ＡＡ名がそのままメニューに表示されるので、
必ず名前を付けておいてください。決まり切ったテンプレ枠とかを登録するといいでしょう。


### 部分抽出モード

抽出したいＡＡの部分を選択範囲にし、その部分のみを、レイヤボックスまたは
クリップボードにコピーできます。開いている部分は空白で埋めます。もちろんズレ無し。

> ※既知のバグ：矩形選択と組み合わせると落ちます。

メニューの「編集」内の「部分抽出モード」を選ぶと、選択モードになります。
この状態で、切り取りたい領域を、マウスドラッグで範囲選択状態にします。
已に選択されている部分を選択すると、解除されます。離れているところだろうと
任意に選択できるので、欲しいところだけを選択範囲に含められます。
範囲選択が出来たら、通常コピーでクリップボードに取り込むか、レイヤボックス起動で
レイヤボックスに転送できます。（一旦どっかに貼り付けて、内容を確保しておきましょう）


### 通し番号機能

各コマの先頭に、通し番号を挿入できます。開始番号指定もできるので、
今回は１２４コマ目から、といったこともおっけ～ね。


### 各種整形機能・大体書いてある通りの機能です。

- 右揃え線
- 行頭に全角空白追加
- 行頭空白削除
- 行末空白削除
- 行末文字削除
- 選択範囲を空白にする
- 頁全体を空白で埋める


### 右に寄せる

頁全体もしくは選択範囲行を、一気に右にずらします。
右端ドット位置は、一般設定から変更出来ます。
ずらし範囲で、もっとも右にある部分が右端ドット位置に来るようにずらされます。


### ドット単位左右調整 [ Alt + ←/→ ]

キャレットが有る空白部分を、１ドットずつ増減出来ます。基本的に全角・半角空白を
使いますが、不可能な場合は自動的にユニコード空白を使います。


### 空白を表示

空白は、アンダーバーで表示されていますが、これの表示をON/OFF出来ます。


### グリッド線を表示
### 右ガイド線を表示

編集エリアのグリッド線と、右ガイド線の表示ON/OFFです。
グリッドの感覚、ガイド線の位置は、一般設定から変更出来ます。


### 壱行テンプレート
### 塗り潰しブラシ

「Templates」ディレクトリ内の「aalist.txt」「aabrush.txt」の内容を取り込んで、
壱行テンプレ、塗り潰しブラシとして使えます。
（´д｀）Editのがそのまま使えます。機能的も似たような感じです。

メイン窓にドッキングしている時に、タブのところで右クリックすると、表示・非表示が出来ます。


### ユニコード表

扱えるユニコード文字の全ての一覧です。ここから文字を選んで使用できます。
文字を選択してダブルクリックすることで、編集エリアのキャレットのところに
挿入されます。


### トレスモード

背景に画像ファイルを表示させることができます。トレスによるＡＡ作成を支援します。


### プレビュー

ＩＥコンポーネントを使用して、実際の見え方を確認出来ます。
一応合っているはず。単コマ表示と、全レス表示を切り替えられます。
「Templates」ディレクトリ内の「Preview.htm」がデザイン元です。


### アクセラレータキーの編集機能

Ctrl+Cとかの、キーボードでの機能のキーバインドを変更できます。



## 投下用頁送りコピー [ Ctrl + Shift + D ] ホットキー

これは、投下時に使うショートカットで、アプリが裏になっていても、このキーは有効です。
今開いている頁全体をShiftJISコピーし、次のコピー頁を、次の頁にします。
つまり、投下時に、いちいちEditorを前にもってこなくても、ブラウザを見ているままで、
次々コピーできるわけです。



## キーボードショートカット

```
        CONTROL        N	ファイル新規作成
        CONTROL        O	ファイル開く
        CONTROL        S	ファイル上書保存
        CONTROL   ALT  S	ファイル名前を付けて保存
        CONTROL        F4	フォーカスしてるファイル閉じる

        CONTROL        A	全選択
        CONTROL        C	Unicodeコピー
SHIFT   CONTROL        C	SJISコピー
        CONTROL        V	貼付
        CONTROL        X	切り取り
        CONTROL        Y	操作やり直し
SHIFT   CONTROL        Z	操作やり直し
        CONTROL        Z	操作取消

        CONTROL   ALT  B	矩形選択ON/OFF
SHIFT   CONTROL        W	空白表示 ON/OFF

                  ALT  H	トレス中に、画像の表示・非表示

        CONTROL        T	複数行テンプレサムネイル表示
        CONTROL        W	枠挿入ＢＯＸ開く
                  ALT  SPACE	レイヤボックス開く
        CONTROL        SPACE	ドラフトボード開く

        CONTROL        F	文字列検索ＢＯＸ開く（予定）
SHIFT   CONTROL        F	検索ヒットハイライト消す（予定）

SHIFT   CONTROL        G	行末文字削除
        CONTROL        G	行末空白削除
        CONTROL   ALT  G	選択領域を空白で埋める
        CONTROL        I	行頭に全角空白追加
        CONTROL   ALT  R	右揃え線挿入
        CONTROL        U	行頭空白削除
                  ALT  →	１ドット増やす
                  ALT  ←	１ドット減らす
SHIFT             ALT  →	全体を１ドット右へ
SHIFT             ALT  ←	全体を１ドット左へ
        CONTROL   ALT  E	ドットずれ調整：調整実行
        CONTROL   ALT  W	ドットずれ調整：基準位置ロック
                       F5	編集エリアの表示をリフレッシュ

        CONTROL        →	壱行テンプレのグリッド増やす
        CONTROL        ←	壱行テンプレのグリッド減らす
        CONTROL        ↑	壱行テンプレのグループ変更
        CONTROL        ↓	壱行テンプレのグループ変更

        CONTROL        TAB	フロート窓フォーカス移動
SHIFT   CONTROL        TAB	フロート窓フォーカス移動

        CONTROL        PageUp	前のファイルへ移動
        CONTROL        PageDown	次のファイルへ移動

                  ALT  C	選択頁を複製
                  ALT  D	選択頁を削除
                  ALT  G	次の頁と統合
                  ALT  I	選択頁の次に新規作成
SHIFT             ALT  I	末尾に頁新規作成
                  ALT  J	頁を下へ移動
                  ALT  N	頁名称の変更
                  ALT  U	頁を上へ移動
                  ALT  ↑	前の頁へ移動
                  ALT  ↓	次の頁へ移動
```


## 変更履歴

```
2011/12/22	0.26	ドラフトボード機能（Viewer込み）
					MAAサムネイル機能（Viewer込み）
					MAAの使用のグループ一括削除（Viewer込み）
					配色変更をＧＵＩで出来るようにした
					オーポン記録がなければ、説明ASTを表示するようにした
					ファイル毎のCaret位置を保存するようにした
					起動したまま、壱行テンプレ、ブラシテンプレのリロードできるようんした
					起動するとき、最後に開けてたファイルを開くとか選択できるようにした
2012/01/16	0.27	編集窓のファイルタブで、マウスオーバーでフルパス表示
					ＭＡＡとドラフトボードで、中クルックの場合処理を増やした（Viewer込み）
					台詞用Enter機能。Shift+Enterで、改行挿入ではなく次の行に空白とかで台詞位置合わせできる
					縦書き機能
					バグ修正いろいろ
2012/02/29	0.28	ＵＴＦ８でエクスポート出来るようにした
					フォント変更機能
					頁削除のAlt+D追加
					サムネから使ったら、使用タブに追加されないのを修正
					リバーの位置記憶と初期状態に戻す実装
					ファイル開いた履歴を保持できるようにした
					MAA部分に↑↓PageUpDownとか追加できたかもしれない
					MAAのリストアップ対象にTXTを追加
					改行が多いとパフォーマンスが落ちるのが少し改善できた気がする
					終了時の確認メッセージ変更
					IEプレビューのCSSを少し変更・行間について
					バグ修正いろいろ
2012/03/22	0.29	台詞改行、空白行で実行した場合は、キャレット位置で次の行を確保するようにした
					Editorで効いてなかったプロファイル履歴を修正
					右揃え線、ユニコードに対応
					行頭半角空白をユニコード空白に置き換える機能搭載
					Ctrl+Bでプレビュー開くようにした
					壱行、ブラシテンプレの表示/非表示ができる
					アクセラキー編集機能を搭載
					アンドゥリドゥをするときは選択範囲解除するようにした
					已に開いているファイルを開こうとしたら、そのタブに移るようにした
					バグ修正いろいろ
2012/05/15	0.30	MAA窓でENTER押したら、そのときトップに見えてるAAを左クリック動作するようにした
					文字列若しくは空白列でダブルクルックすると、その範囲を選択状態にする
					選択範囲をドラッグ移動出来るようにした・ちゅっと挙動怪しいかも？
					プレビュー開いてたら、保存したときに再描画するようにした
					枠作成に、複数行使えるようにした
					枠の個数を２０個保持できるようにした
					ツールバーに、ユニコード空白の使用／不使用トグルボタンつけた
					左右反転、上下反転機能を追加
					レイヤボックスに、内容削除ボタンを追加
					4096byte超えたら、ステータスバーのバイト表示位置が赤くなる。
					頁挿入ダイヤログのチェックボックス覚えておくようにした
					キャレットの位置に矩形貼付機能を追加
					壱行テンプレで中クルックしたらレイヤボックスが開く
					MAAツリーでファイル名を中クリックしたら、副タブに追加できる
					バグ修正いろいろ
2012/09/06	0.31	MAAに、ファイルの途中にアイテムを追加できるようにした
					MAAの内容表示側にＤ＆Ｄすると、そのファイルを副タブで開く（Viewer込み）
					※使用には入らないし復元もされない
					MAAツリーにＤ＆Ｄすると、追加アイテムとしてツリーに追加（Viewer込み）
					※再構築すると消える
					MAAの使用で、複数のMLTに同じAAが有る場合にキョドるのを修正。多分（Viewer込み）
					枠挿入BOXを縮めすぎるとエラーになるのを修正
					台詞改行で、単独スペースはノーカンにした
					ユーザアイテムを右クリメニューに追加できるようにした
					ドラッグ移動させたらキャレット位置がおかしくなるのを修正
					MAA窓と頁一覧で、選択したらフォーカスを編集窓に戻す機能
					ドラフトボード・サムネイルの窓を移動出来るようにした
					ツールチップがチラつくのをなんとか出来た気がする
					副タブの名称変更を出来るようにした（Viewer込み）
					ファイルオーポンを高速化出来た気がする
					空白の表示/非表示状態を覚えておくようにした。
					レイヤボックス貼付に白ヌキ機能追加
					中クリックで、MAAの副タブや編集ファイルを閉じれるようにした（Viewer込み）
					行数ルーラーを付けた
					バイト数オーバー警告のバイト数を設定できるようにした
					ユニコード表に、使用履歴をつけた
					ＭＡＡ窓の背景色変更出来るようにした
2012/11/05	0.32	MAAのツリー側のAA頁を削除出来るようにした
					新規保存時の拡張子を、MLTかASTを適用するようにした
					ドラフトボード・サムネイルのサイズを４段階で変えれるようにした
					MAA窓に、開いてる頁内の文字列検索を付けた・
					ASTに追加するとセパレータがおかしくなるのを修正
					頁切り替えた時、最後の頁のところまで頁一覧をスクロール
					任意の場所から右の部分を、左右にずらす機能
					MAAテンプレにアイテム追加したら全アイテムに改行が増えるのを修正
```