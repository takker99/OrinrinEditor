/*! @file
	@brief アプリ全体で使う定数や函数です
	このファイルは OrinrinEditor.h です。
	@author	SikigamiHNQ
	@date	2011/00/00
*/

/*
Orinrin Editor : AsciiArt Story Editor for Japanese Only
Copyright (C) 2011 - 2014 Orinrin/SikigamiHNQ

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/
//-------------------------------------------------------------------------------------------------

#pragma once

#define STRICT

#include "../resource.h"
//-------------------------------------------------------------------------------------------------

#include "SplitBar.h"
//-------------------------------------------------------------------------------------------------

//!	MLTの区切り文字列
#define MLT_SEPARATERW	TEXT("[SPLIT]")
#define MLT_SEPARATERA	("[SPLIT]")
#define MLT_SPRT_CCH	7

//!	ASTの区切り文字列
#define AST_SEPARATERW	TEXT("[AA]")
#define AST_SEPARATERA	("[AA]")
#define AST_SPRT_CCH	4

//!	テンプレのアレ
#define TMPLE_BEGINW	TEXT("[ListName=")
#define TMPLE_ENDW		TEXT("[end]")

//!	改行
#define CH_CRLFW	TEXT("\r\n")
#define CH_CRLFA	("\r\n")
#define CH_CRLF_CCH	2

//!	EOFマーク
#define EOF_SIZE	5
CONST  TCHAR	gatEOF[] = TEXT("[EOF]");
#define EOF_WIDTH	39


#define YY2_CRLF	6	//!<	ＹＹカキコの改行バイト数
#define STRB_CRLF	4	//!<	したらば板の改行バイト数

#define PAGE_BYTE_MAX	4096	//!<	１頁の最大バイト数・ただし板による

#define MODIFY_MSG	TEXT("[変更]")
//-------------------------------------------------------------------------------------------------

//	したらば用色指定タグ
#define COLOUR_TAG_WHITE	TEXT("<jbbs fontcolor=\"#ffffff\">")	//!<	したらば色指定：白
#define COLOUR_TAG_BLUE		TEXT("<jbbs fontcolor=\"#0000ff\">")	//!<	したらば色指定：蒼
#define COLOUR_TAG_BLACK	TEXT("<jbbs fontcolor=\"#000000\">")	//!<	したらば色指定：黒
#define COLOUR_TAG_RED		TEXT("<jbbs fontcolor=\"#ff0000\">")	//!<	したらば色指定：紅
#define COLOUR_TAG_GREEN	TEXT("<jbbs fontcolor=\"#00ff00\">")	//!<	したらば色指定：翠

//-------------------------------------------------------------------------------------------------



#define CC_TAB	0x09
#define CC_CR	0x0D
#define CC_LF	0x0A

//-----------------------------------------------------------------------------------------------------------------------------------------

//アンドゥ用COMMANDO
#define DO_INSERT	1	//!<	アンドゥ用COMMANDO　文字入力・ペーストとか
#define DO_DELETE	2	//!<	アンドゥ用COMMANDO　文字削除・切り取りとか

//-----------------------------------------------------------------------------------------------------------------------------------------


#define LINE_HEIGHT	18	//!<	ＡＡの壱行の高さドット

#define RULER_AREA	13	//!<	編集窓のルーラーエリア高さ

#define LINENUM_WID	37	//!<	編集窓の行番号表示エリアの幅
#define LINENUM_COLOUR		0xFF8000	//!<	編集窓の行番号表示エリアの色

#define RUL_LNNUM_COLOURBK	0xC0C0C0
//-------------------------------------------------------------------------------------------------

//	スペースの幅
#define SPACE_HAN	5	//!<	半角スペースの幅ドット
#define SPACE_ZEN	11	//!<	全角スペースの幅ドット
//-------------------------------------------------------------------------------------------------

#define CLR_BLACK	0x000000
#define CLR_MAROON	0x000080
#define CLR_GREEN	0x008000
#define CLR_OLIVE	0x008080
#define CLR_NAVY	0x800000
#define CLR_PURPLE	0x800080
#define CLR_TEAL	0x808000
#define CLR_GRAY	0x808080
#define CLR_SILVER	0xC0C0C0
#define CLR_RED		0x0000FF
#define CLR_LIME	0x00FF00
#define CLR_YELLOW	0x00FFFF
#define CLR_BLUE	0xFF0000
#define CLR_FUCHSIA	0xFF00FF
#define CLR_AQUA	0xFFFF00
#define CLR_WHITE	0xFFFFFF

//-------------------------------------------------------------------------------------------------

//	描画文字のアレ
#define CT_NORMAL	0x0000	//!<	普通の文字列
#define CT_WARNING	0x0001	//!<	連続半角空白のような警告
#define CT_SPACE	0x0002	//!<	空白
#define CT_SELECT	0x0004	//!<	選択状態である
#define CT_CANTSJIS	0x0008	//!<	シフトJISに変換できない文字
#define CT_LYR_TRNC	0x0010	//!<	レイヤボックスで透過範囲
#define CT_FINDED	0x0020	//!<	検索ヒット文字列

#define CT_SELRTN	0x0100	//!<	行末改行も選択状態
#define CT_LASTSP	0x0200	//!<	行末が空白である
#define CT_RETURN	0x0400	//!<	改行が必要
#define CT_EOF		0x0800	//!<	末端である
#define CT_FINDRTN	0x1000	//!<	行末改行が検索ヒット
//-------------------------------------------------------------------------------------------------



#define OPENHIST_MAX	12
//!	開いた履歴用・プロファイルにも使う
typedef struct tagOPENHISTORY
{
	TCHAR	atFile[MAX_PATH];	//!<	ファイルパス
	DWORD	dMenuNumber;		//!<	メニュー番号の割当

} OPENHIST, *LPOPENHIST;
typedef list<OPENHIST>::iterator	OPHIS_ITR;
//----------------

//!	壱文字の情報・受け渡しにも使う
typedef struct tagLETTER
{
	TCHAR	cchMozi;	//!<	文字
	INT_PTR		rdWidth;	//!<	この文字の幅
	UINT_PTR	mzStyle;	//!<	文字のタイプ・空白とかそういうの
	CHAR	acSjis[10];	//!<	シフトJISコード、もしくは「&#dddd;」形式をいれる
	INT_PTR	mzByte;		//!<	SJISバイトサイズ

} LETTER, *LPLETTER;
typedef vector<LETTER>::iterator	LETR_ITR;
//-----------------------------

#ifndef _ORRVW

#define PARTS_CCH	130

//!	枠パーツデータ	20120105	複数行に向けて調整
typedef struct tagFRAMEITEM
{
	TCHAR	atParts[PARTS_CCH];	//!<	パーツ文字列・９字まで
	INT_PTR		dDot;	//!<	横幅ドット数
	INT_PTR		iLine;	//!<	使用行数
	INT_PTR		iNowLn;	//!<	使用行番号・配置時に使う

} FRAMEITEM, *LPFRAMEITEM;
//----------------
//!	枠処理用
typedef struct tagFRAMEINFO
{
	TCHAR	atFrameName[MAX_STRING];	//!<	名前・未使用

	FRAMEITEM	stDaybreak;	//!<	左		│
	FRAMEITEM	stMorning;	//!<	左上	┌
	FRAMEITEM	stNoon;		//!<	上		─
	FRAMEITEM	stAfternoon;//!<	右上	┐
	FRAMEITEM	stNightfall;//!<	右		│
	FRAMEITEM	stTwilight;	//!<	右下	┘
	FRAMEITEM	stMidnight;	//!<	下		─
	FRAMEITEM	stDawn;		//!<	左下	└

	INT_PTR		dLeftOffset;	//!<	左壁の配置オフセット・０は左上の始点
	INT_PTR		dRightOffset;	//!<	右壁の配置オフセット・０は右上の始点

	UINT_PTR	dRestPadd;		//!<	あまりを埋めるかどうか・

} FRAMEINFO, *LPFRAMEINFO;
//-----------------------------

//!	トレスモード用Parameter保持
typedef struct tagTRACEPARAM
{
	POINT	stOffsetPt;	//!<	位置合わせ
	INT_PTR		dContrast;	//!<	コントラスト
	INT_PTR		dGamma;		//!<	ガンマ
	INT_PTR		dGrayMoph;	//!<	淡色
	INT_PTR		dZooming;	//!<	拡大縮小
	INT_PTR		dTurning;	//!<	回転

	UINT_PTR	bUpset;		//!<	
	UINT_PTR	bMirror;	//!<	

	COLORREF	dMoziColour;	//!<	文字色について

} TRACEPARAM, *LPTRACEPARAM;
//----------------


//!	操作ログ本体
typedef struct tagOPERATELOG
{
	UINT_PTR	dCommando;	//!<	操作タイプ
	UINT_PTR	ixSequence;	//!<	操作番号・ふりきったらどうしよ
	UINT_PTR	ixGroup;	//!<	操作グループ・１回の処理・１インデックス

	INT_PTR		rdXdot;		//!<	操作のあったドット・文字位置とどっちが良い？
//	INT_PTR		rdXmozi;	//!<	操作のあったドキュメント文字位置
	INT_PTR		rdYline;	//!<	操作のあったドキュメント行

	LPTSTR	ptText;		//!<	操作された文字列
	UINT_PTR	cchSize;	//!<	文字列の文字数

} OPERATELOG, *LPOPERATELOG;
typedef vector<OPERATELOG>::iterator	OPSQ_ITR;
//-----------------------------

//!	アンドゥバッファ
typedef struct tagUNDOBUFF
{
	UINT_PTR	dNowSqn;	//!<	参章中の操作位置？
	UINT_PTR		dTopSqn;	//!<	最新の操作番号１インデックス・追加はインクリしてから
	UINT_PTR		dGrpSqn;	//!<	操作グループ・１インデックス

	vector<OPERATELOG>	vcOpeSqn;	//!<	操作ログ本体

} UNDOBUFF, *LPUNDOBUFF;
//-----------------------------

//壱文字の情報構造体宣言を↑に移動

//!	壱行の管理
typedef struct tagONELINE
{
	INT_PTR		iDotCnt;		//!<	ドット数
	INT_PTR		iByteSz;		//!<	バイト数
	UINT_PTR	dStyle;			//!<	この行の特殊状態
	BOOLEAN	bBadSpace;		//!<	警告付き空白があるか

	vector<LETTER>	vcLine;	//!<	この行の内容・改行は含まない

	//	レイヤボックス用
	INT_PTR		dFrtSpDot;		//!<	前の空白ドット
	INT_PTR		dFrtSpMozi;		//!<	前の空白文字数

} ONELINE, *LPONELINE;
typedef list<ONELINE>::iterator		LINE_ITR;
//-----------------------------

//!	SPLITページ壱分
typedef struct tagONEPAGE
{
	TCHAR	atPageName[SUB_STRING];	//!<	

	INT_PTR		dByteSz;		//!<	バイト数

	//	選択状態について
	INT_PTR		dSelLineTop;	//!<	一番上の選択がある行
	INT_PTR		dSelLineBottom;	//!<	一番下の選択がある行
	UNDOBUFF	stUndoLog;	//!<	操作履歴・アンドゥに使う

	list<ONELINE>	ltPage;	//!<	行全体

	LPTSTR	ptRawData;		//!<	頁の生データ
	INT_PTR		iLineCnt;		//!<	行数・生データ用
	INT_PTR		iMoziCnt;		//!<	文字数・生データ用

} ONEPAGE, *LPONEPAGE;
typedef vector<ONEPAGE>::iterator	PAGE_ITR;
//-----------------------------

//!	一つのファイル保持
typedef struct tagONEFILE
{
	TCHAR	atFileName[MAX_PATH];	//!<	ファイル名
	//	頁数はヴェクタルをカウンツすればＯＫ？
	UINT_PTR	dModify;		//!<	変更したかどうか

	LPARAM	dUnique;		//!<	通し番号・１インデックス
	TCHAR	atDummyName[MAX_PATH];	//!<	ファイル名ないときの仮名称

	INT_PTR		dNowPage;		//!<	見てる頁

	POINT	stCaret;		//!<	Caret位置・ドット、行数

	vector<ONEPAGE>	vcCont;	//!<	ページを保持する

} ONEFILE, *LPONEFILE;

typedef list<ONEFILE>::iterator	FILES_ITR;
//-----------------------------

//	複数ファイル扱うなら、さらにコレを包含すればいい？

//!	壱行・ブラシテンプレ用・カテゴリ名保持のアレ
typedef struct tagAATEMPLATE
{
	TCHAR	atCtgryName[SUB_STRING];	//!<	セットの名前

	vector<wstring>	vcItems;	//!<	テンプレ文字列本体

} AATEMPLATE, *LPAATEMPLATE;
typedef vector<AATEMPLATE>::iterator	TEMPL_ITR;	
//-----------------------------

//!	リバーの位置確定用
typedef struct tagREBARLAYOUTINFO
{
	UINT_PTR	wID;
	UINT_PTR	cx;
	UINT_PTR	fStyle;

} REBARLAYOUTINFO, *LPREBARLAYOUTINFO;
//-----------------------------


//!	頁情報確保用
typedef struct tagPAGEINFOS
{
	UINT_PTR	dMasqus;	//!<	必要な情報のアレ

	INT_PTR	iLines;	//!<	行数
	INT_PTR	iBytes;	//!<	使用バイト数
	INT_PTR	iMozis;	//!<	使用文字数

	TCHAR	atPageName[SUB_STRING];	//!<	

} PAGEINFOS, *LPPAGEINFOS;
#define PI_LINES	0x01
#define PI_BYTES	0x02
#define PI_MOZIS	0x04
#define PI_NAME		0x08
#define PI_RECALC	0x80000000
//-----------------------------

//-------------------------------------------------------------------------------------------------

typedef UINT_PTR (CALLBACK* PAGELOAD)(LPTSTR, LPCTSTR, INT_PTR);	//!<	頁ロード用コールバック関数の型宣言

#endif	//	NOT _ORRVW


//	MaaCatalogue.cppから移動
//!	MLTの保持
typedef struct tagAAMATRIX
{
	CHAR	acAstName[MAX_STRING];	//!<	ASTの場合、頁名称を持っておく

	UINT_PTR	ixNum;	//!<	通し番号０インデックス
	DWORD	cbItem;	//!<	AAの文字バイト数・

	LPSTR	pcItem;	//!<	読み込んだAAを保持しておくポインタ・SJIS形式のままでいいか？

	INT_PTR		iByteSize;	//!<	
	//	サムネ用
	INT_PTR		iMaxDot;	//!<	横幅最大ドット数
	INT_PTR		iLines;		//!<	使用行数

	SIZE	stSize;		//!<	ピクセルサイズ
	HBITMAP	hThumbBmp;	//!<	サムネイル用ビットマップハンドル

} AAMATRIX, *LPAAMATRIX;
typedef vector<AAMATRIX>::iterator	MAAM_ITR;	
//-----------------------------


#ifdef USE_HOVERTIP

//!	HoverTip用の表示内容確保・内容は増やすかも
//typedef struct tagHOVERTIPINFO
//{
//	LPTSTR	ptInfo;	//	文字列内容を示すポインタ
//
//} HOVERTIPINFO, *LPHOVERTIPINFO;

//!	HoverTip用コールバック函数
typedef LPTSTR (CALLBACK* HOVERTIPDISP)( LPVOID );	//!<	HoverTipコールバック関数の型宣言


HRESULT	HoverTipInitialise( HINSTANCE, HWND );	//!<	
HRESULT	HoverTipResist( HWND  );	//!<	
HRESULT	HoverTipSizeChange( INT_PTR );	//!<	
LRESULT	HoverTipOnMouseHover( HWND, WPARAM, LPARAM, HOVERTIPDISP );	//!<	
LRESULT	HoverTipOnMouseLeave( HWND );	//!<	


#endif
//-------------------------------------------------------------------------------------------------


//	このコード モジュールに含まれる関数の宣言
INT_PTR		CALLBACK About( HWND, UINT_PTR, WPARAM, LPARAM );	//!<	

INT_PTR		MessageBoxCheckBox( HWND, HINSTANCE, UINT_PTR );	//!<	

VOID		WndTagSet( HWND, LONG_PTR );	//!<	
LONG_PTR	WndTagGet( HWND );	//!<	

#ifdef SPMOZI_ENCODE
UINT_PTR		IsSpMozi( TCHAR );
#endif

HRESULT		InitWindowPos( UINT_PTR, UINT_PTR, LPRECT );	//!<	
INT_PTR			InitParamValue( UINT_PTR, UINT_PTR, INT_PTR );		//!<	
HRESULT		InitParamString( UINT_PTR, UINT_PTR, LPTSTR );	//!<	

HRESULT		OpenProfileInitialise( HWND );	//!<	
HRESULT		InitProfHistory( UINT_PTR, UINT_PTR, LPTSTR );	//!<	
  #ifdef _ORRVW
HRESULT		OpenProfMenuModify( HWND );	//!<	
  #endif

BOOLEAN		SelectDirectoryDlg( HWND, LPTSTR, UINT_PTR );	//!<	

UINT_PTR		ViewMaaMaterialise( HWND, LPSTR, UINT_PTR, UINT_PTR );	//!<	
INT_PTR			ViewStringWidthGet( LPCTSTR );	//!<	
INT_PTR			ViewLetterWidthGet( TCHAR );	//!<	

UINT_PTR		ViewMaaItemsModeGet( PUINT_PTR );	//!<	

LPTSTR		SjisDecodeAlloc( LPSTR );	//!<	
LPSTR		SjisEntityExchange( LPCSTR );	//!<	
BOOLEAN		HtmlEntityCheckA( TCHAR, LPSTR , UINT_PTR );	//!<	
BOOLEAN		HtmlEntityCheckW( TCHAR, LPTSTR, UINT_PTR );	//!<	

BOOLEAN		DocIsSjisTrance( TCHAR, LPSTR );	//!<	
INT_PTR		DocLetterByteCheck( LPLETTER );	//!<	
INT_PTR		DocLetterDataCheck( LPLETTER, TCHAR );

BOOLEAN		FileExtensionCheck( LPTSTR, LPTSTR );	//!<	

HWND		MaaTmpltInitialise( HINSTANCE, HWND, LPRECT );	//!<	
HRESULT		MaaTmpltPositionReset( HWND );	//!<	
VOID		MaaTabBarSizeGet( LPRECT  );	//!<	

HRESULT		AaItemsTipSizeChange( INT_PTR, UINT_PTR );	//!<	

HRESULT		ViewingFontGet( LPLOGFONT );	//!<	

LPTSTR		FindStringProc( LPTSTR, LPTSTR, PINT_PTR );	//!<	


#ifndef _ORRVW

VOID		AacBackupDirectoryInit( LPTSTR );	//!<	

BOOLEAN		MaaViewToggle( UINT_PTR );				//!<	

UINT_PTR		UnicodeUseToggle( LPVOID  );		//!<	

LPSTR		SjisEncodeAlloc( LPCTSTR  );		//!<	

ATOM		InitWndwClass( HINSTANCE  );		//!<	
BOOL		InitInstance( HINSTANCE , INT_PTR, LPTSTR );	//!<	
LRESULT		CALLBACK WndProc( HWND , UINT, WPARAM, LPARAM );	//!<	

HRESULT		MainStatusBarSetText( INT_PTR, LPCTSTR );	//!<	
HRESULT		MainSttBarSetByteCount( UINT_PTR  );	//!<	

HRESULT		WindowPositionReset( HWND );		//!<	

HRESULT		MenuItemCheckOnOff( UINT_PTR, UINT_PTR );	//!<	
HRESULT		NotifyBalloonExist( LPTSTR, LPTSTR, DWORD );	//!<	

HRESULT		BrushModeToggle( VOID );		//!<	

HRESULT		WindowFocusChange( INT_PTR, INT_PTR );	//!<	

HRESULT		OptionDialogueOpen( VOID  );	//!<	

COLORREF	InitColourValue( UINT_PTR, UINT_PTR, COLORREF );	//!<	
INT_PTR			InitTraceValue( UINT_PTR, LPTRACEPARAM );	//!<	
//HRESULT	InitLastOpen( UINT_PTR, LPTSTR );			//	
INT_PTR			InitWindowTopMost( UINT_PTR, UINT_PTR, INT_PTR );	//!<	
HRESULT		InitToolBarLayout( UINT_PTR, INT_PTR, LPREBARLAYOUTINFO );	//!<	

UINT_PTR		DocHugeFileTreatment( UINT_PTR );

#ifdef ACCELERATOR_EDIT
LPACCEL		AccelKeyTableGetAlloc( PINT_PTR  );	//!<	
LPACCEL		AccelKeyTableLoadAlloc( PINT_PTR );	//!<	
HRESULT		AccelKeyDlgOpen( HWND );			//!<	
HACCEL		AccelKeyHandleGet( HINSTANCE  );	//!<	

HACCEL		AccelKeyTableCreate( LPACCEL, INT_PTR );	//!<	
HRESULT		AccelKeyMenuRewrite( HWND, LPACCEL, CONST INT_PTR );	//!<	
#endif

HRESULT		OpenHistoryInitialise( HWND );			//!<	
HRESULT		OpenHistoryLogging( HWND , LPTSTR );	//!<	
HRESULT		OpenHistoryLoad( HWND, INT_PTR );			//!<	

VOID		ToolBarCreate( HWND, HINSTANCE );		//!<	
HRESULT		ToolBarInfoChange( LPACCEL, INT_PTR );		//!<	
VOID		ToolBarDestroy( VOID  );				//!<	
HRESULT		ToolBarSizeGet( LPRECT );				//!<	
HRESULT		ToolBarCheckOnOff( UINT_PTR, UINT_PTR );		//!<	
HRESULT		ToolBarOnSize( HWND, UINT_PTR, INT_PTR, INT_PTR );	//!<	
LRESULT		ToolBarOnNotify( HWND, INT_PTR, LPNMHDR );	//!<	
LRESULT		ToolBarOnContextMenu( HWND , HWND, LONG, LONG );	//!<	
VOID		ToolBarPseudoDropDown( HWND , INT_PTR );	//!<	
UINT_PTR		ToolBarBandInfoGet( LPVOID );			//!<	
HRESULT		ToolBarBandReset( HWND );				//!<	

UINT_PTR		AppClientAreaCalc( LPRECT );	//!<	

HRESULT		AppTitleChange( LPTSTR );	//!<	
HRESULT		AppTitleTrace( UINT_PTR );		//!<	

LPTSTR		ExePathGet( VOID  );		//!<	

HRESULT		UniDlgInitialise( HWND , UINT_PTR );	//!<	
HRESULT		UniDialogueEntry( HINSTANCE, HWND );		//!<	

HRESULT		FrameInitialise( LPTSTR, HINSTANCE );		//!<	枠設定のINIファイル名確保・アプリ起動後すぐ呼ばれる
HRESULT		FrameNameModifyPopUp( HMENU, UINT_PTR );		//!<	
INT_PTR		FrameEditDialogue( HINSTANCE, HWND, UINT_PTR );	//!<	
HRESULT		FrameNameLoad( UINT_PTR, LPTSTR, UINT_PTR );	//!<	指定された枠の名前を返す

HWND		FrameInsBoxCreate( HINSTANCE, HWND );	//!<	
HRESULT		FrameMoveFromView( HWND, UINT_PTR );		//!<	

HRESULT		CntxEditInitialise( LPTSTR, HINSTANCE );	//!<	
HRESULT		CntxEditDlgOpen( HWND );	//!<	
HMENU		CntxMenuGet( VOID );		//!<	

HRESULT		AccelKeyTextBuild( LPTSTR, UINT_PTR, DWORD, LPACCEL, INT_PTR );

HRESULT		MultiFileTabFirst( LPTSTR );	//!<	
HRESULT		MultiFileTabAppend( LPARAM, LPTSTR );	//!<	
HRESULT		MultiFileTabSelect( LPARAM );	//!<	
HRESULT		MultiFileTabSlide( INT_PTR );		//!<	
HRESULT		MultiFileTabRename( LPARAM, LPTSTR );	//!<	
HRESULT		MultiFileTabClose( INT_PTR );		//!<	
INT_PTR			MultiFileTabSearch( LPARAM );	//!<	
INT_PTR			InitMultiFileTabOpen( UINT_PTR, INT_PTR, LPTSTR );	//!<	

VOID		OperationOnCommand( HWND, INT_PTR, HWND, UINT_PTR );	//!<	

VOID		AaFontCreate( UINT_PTR );	//!<	

#ifdef TODAY_HINT_STYLE
VOID		TodayHintPopup( HWND, HINSTANCE, LPTSTR );
#endif

HWND		ViewInitialise( HINSTANCE, HWND, LPRECT, LPTSTR );	//!<	
HRESULT		ViewSizeMove( HWND, LPRECT );	//!<	
HRESULT		ViewFocusSet( VOID );			//!<	

BOOL		ViewShowCaret( VOID );			//!<	
VOID		ViewHideCaret( VOID );			//!<	
INT_PTR			ViewCaretPosGet( PINT_PTR, PINT_PTR );	//!<	

HRESULT		ViewFrameInsert( INT_PTR  );		//!<	
HRESULT		ViewMaaItemsModeSet( UINT_PTR, UINT_PTR );	//!<	

HRESULT		ViewNowPosStatus( VOID );		//!<	

HRESULT		ViewRedrawSetLine( INT_PTR );		//!<	
HRESULT		ViewRedrawSetRect( LPRECT );	//!<	
HRESULT		ViewRedrawSetVartRuler( INT_PTR );	//!<	
HRESULT		ViewRulerRedraw( INT_PTR, INT_PTR );	//!<	
HRESULT		ViewEditReset( VOID );			//!<	

COLORREF	ViewMoziColourGet( LPCOLORREF );	//!<	
COLORREF	ViewBackColourGet( LPVOID );	//!<	

HRESULT		ViewCaretCreate( HWND, COLORREF, COLORREF );	//!<	
HRESULT		ViewCaretDelete( VOID );		//!<	
BOOLEAN		ViewDrawCaret( INT_PTR, INT_PTR , BOOLEAN );	//!<	本当はドローじゃなくてポジションチェンジだけ
BOOLEAN		ViewPosResetCaret( INT_PTR, INT_PTR );	//!<	
HRESULT		ViewCaretReColour( COLORREF );	//!<	

HRESULT		ViewPositionTransform( PINT_PTR, PINT_PTR, BOOLEAN );	//!<	
BOOLEAN		ViewIsPosOnFrame( INT_PTR, INT_PTR );	//!<	
INT_PTR			ViewAreaSizeGet( PINT_PTR );

HRESULT		ViewSelPositionSet( LPVOID );	//!<	
HRESULT		ViewSelMoveCheck( UINT_PTR );		//!<	
UINT_PTR		ViewSelRangeCheck( UINT_PTR );		//!<	
UINT_PTR		ViewSelBackCheck( INT_PTR );		//!<	
INT_PTR			ViewSelPageAll( INT_PTR );			//!<	
UINT_PTR		ViewSqSelModeToggle( UINT_PTR, LPVOID );	//!<	
HRESULT		ViewSelAreaSelect( LPVOID );	//!<	

INT_PTR			ViewInsertUniSpace( UINT_PTR );	//!<	
INT_PTR			ViewInsertColourTag( UINT_PTR );	//!<	
INT_PTR			ViewInsertTmpleString( LPCTSTR );	//!<	

HRESULT		ViewBrushStyleSetting( UINT_PTR, LPTSTR );	//!<	

VOID		Evw_OnMouseMove( HWND, INT_PTR, INT_PTR, UINT_PTR );	//!<	
VOID		Evw_OnLButtonDown( HWND, BOOL, INT_PTR, INT_PTR, UINT_PTR );	//!<	
VOID		Evw_OnLButtonUp( HWND, INT_PTR, INT_PTR, UINT_PTR );	//!<	
VOID		Evw_OnRButtonDown( HWND, BOOL, INT_PTR, INT_PTR, UINT_PTR );	//!<	

VOID		Evw_OnKey( HWND, UINT_PTR, BOOL, INT_PTR, UINT_PTR );	//!<	
VOID		Evw_OnChar( HWND, TCHAR, INT_PTR );				//!<	
VOID		Evw_OnMouseWheel( HWND, INT_PTR, INT_PTR, INT_PTR, UINT_PTR );	//!<	

VOID		Evw_OnImeComposition( HWND, WPARAM, LPARAM );	//!<	

BOOLEAN		IsSelecting( PUINT_PTR );	//!<	

HRESULT		OperationOnStatusBar( VOID );	//!<	

HWND		PageListInitialise( HINSTANCE, HWND, LPRECT );	//!<	
VOID		PageListResize( HWND , LPRECT );	//!<	
HRESULT		PageListClear( VOID );	//!<	
HRESULT		PageListInsert( INT_PTR );	//!<	
HRESULT		PageListDelete( INT_PTR );	//!<	
HRESULT		PageListViewChange( INT_PTR , INT_PTR );	//!<	
HRESULT		PageListInfoSet( INT_PTR, INT_PTR, INT_PTR );	//!<	
HRESULT		PageListNameSet( INT_PTR , LPTSTR );	//!<	
HRESULT		PageListNameRewrite( LPTSTR );	//!<	
INT_PTR			PageListIsNamed( FILES_ITR );	//!<	
HRESULT		PageListPositionReset( HWND );	//!<	

HRESULT		PageListViewRewrite( INT_PTR  );	//!<	
HRESULT		PageListBuild( LPVOID );	//!<	


HRESULT		TemplateItemLoad( LPTSTR, PAGELOAD );	//!<	
UINT_PTR		TemplateGridFluctuate( HWND , INT_PTR );	//!<	

HWND		LineTmpleInitialise( HINSTANCE , HWND, LPRECT );	//!<	
VOID		LineTmpleResize( HWND, LPRECT );	//!<	
HRESULT		LineTmplePositionReset( HWND  );		//!<	

VOID		DockingTabSizeGet( LPRECT );	//!<	
HRESULT		DockingTabContextMenu( HWND, HWND, LONG, LONG );	//!<	
HWND		DockingTabGet( VOID );			//!<	
HRESULT		DockingTmplViewToggle( UINT_PTR );	//!<	函数の場所違うから注意

HWND		BrushTmpleInitialise( HINSTANCE, HWND, LPRECT, HWND );	//!<	
LPTSTR		BrushStringMake( INT_PTR , LPTSTR );	//!<	
VOID		BrushTmpleResize( HWND, LPRECT );	//!<	
HRESULT		BrushTmplePositionReset( HWND );	//!<	

INT_PTR			UserDefInitialise( HWND, UINT_PTR );	//!<	
HRESULT		UserDefItemInsert( HWND, UINT_PTR );	//!<	
HRESULT		UserDefMenuWrite( HMENU, UINT_PTR );	//!<	ユーザ定義メニューの中身をくっつける
HRESULT		UserDefItemNameget( UINT_PTR, LPTSTR, UINT_PTR );	//!<	アイテムの名前を引っ張る
HRESULT		UserDefSetString( vector<ONELINE> *, LPCTSTR, UINT_PTR );	//!<	保持構造体に文字列を記録する

HRESULT		FrameNameModifyMenu( HWND );	//!<	

VOID		PreviewInitialise( HINSTANCE, HWND );	//!<	
HRESULT		PreviewVisibalise( INT_PTR, BOOLEAN );	//!<	

INT_PTR			TraceInitialise( HWND, UINT_PTR );	//!<	
HRESULT		TraceDialogueOpen( HINSTANCE, HWND );	//!<	
HRESULT		TraceImgViewTglExt( VOID );	//!<	
UINT_PTR		TraceImageAppear( HDC, INT_PTR, INT_PTR );	//!<	
UINT_PTR		TraceMoziColourGet( LPCOLORREF );	//!<	

HRESULT		ImageFileSaveDC( HDC, LPTSTR, INT_PTR );	//!<	


VOID		LayerBoxInitialise( HINSTANCE, LPRECT );	//!<	
HRESULT		LayerBoxAlphaSet( UINT_PTR );	//!<	
HRESULT		LayerMoveFromView( HWND, UINT_PTR );	//!<	
HWND		LayerBoxVisibalise( HINSTANCE, LPCTSTR, UINT_PTR );	//!<	
INT_PTR			LayerHeadSpaceCheck( vector<LETTER> *, PINT_PTR );	//!<	
HRESULT		LayerTransparentToggle( HWND, UINT_PTR );			//!<	
HRESULT		LayerContentsImportable( HWND, UINT_PTR, PINT_PTR, PINT_PTR, UINT_PTR );	//!<	
HRESULT		LayerBoxPositionChange( HWND , LONG, LONG );	//!<	
HRESULT		LayerStringReplace( HWND , LPTSTR );	//!<	



HRESULT		DocInitialise( UINT_PTR );	//!<	

BOOLEAN		DocRangeIsError( FILES_ITR , INT_PTR, INT_PTR );	//!<	

UINT_PTR	DocNowFilePageCount( VOID );	//!<	
UINT_PTR	DocNowFilePageLineCount( VOID );	//!<	

UINT_PTR		DocRawDataParamGet( LPCTSTR, PINT_PTR, PINT_PTR );	//!<	

VOID		DocCaretPosMemory( UINT_PTR , LPPOINT );	//!<	

HRESULT		DocOpenFromNull( HWND );	//!<	

UINT_PTR		DocPageParamGet( PINT_PTR, PINT_PTR );	//!<	
UINT_PTR		DocPageByteCount( FILES_ITR , INT_PTR, PINT_PTR, PINT_PTR );	//!<	
HRESULT		DocPageInfoRenew( INT_PTR, UINT_PTR );	//!<	
INT_PTR			DocPageMaxDotGet( INT_PTR, INT_PTR );	//!<	
HRESULT		DocPageNameSet( LPTSTR );	//!<	

INT_PTR			DocPageCreate( INT_PTR );	//!<	
HRESULT		DocPageDelete( INT_PTR, INT_PTR );	//!<	
HRESULT		DocPageChange( INT_PTR );	//!<	

UINT_PTR		DocDelayPageLoad( FILES_ITR , INT_PTR );	//!<	ディレイ頁のロード

HRESULT		DocModifyContent( UINT_PTR );	//!<	

LPARAM		DocMultiFileCreate( LPTSTR );	//!<	
HRESULT		DocActivateEmptyCreate( LPTSTR );	//!<	

INT_PTR			DocLineParamGet( INT_PTR , PINT_PTR, PINT_PTR );	//!<	

UINT_PTR		DocBadSpaceCheck( INT_PTR );	//!<	
BOOLEAN		DocBadSpaceIsExist( INT_PTR );	//!<	

HRESULT		DocPageDivide( HWND, HINSTANCE, INT_PTR );	//!<	

INT_PTR			DocInputLetter( INT_PTR, INT_PTR, TCHAR );	//!<	
INT_PTR			DocInputBkSpace( PINT_PTR, PINT_PTR );	//!<	
INT_PTR			DocInputDelete( INT_PTR , INT_PTR );	//!<	
INT_PTR			DocInputFromClipboard( PINT_PTR, PINT_PTR, PINT_PTR, UINT_PTR );	//!<	

INT_PTR			DocAdditionalLine( INT_PTR, PBOOLEAN );	//!<	

INT_PTR			DocStringAdd( PINT_PTR, PINT_PTR, LPCTSTR, INT_PTR );	//!<	
HRESULT		DocCrLfAdd( INT_PTR, INT_PTR, BOOLEAN );	//!<	
INT_PTR			DocSquareAdd( PINT_PTR, PINT_PTR, LPCTSTR, INT_PTR, LPPOINT * );	//!<	
INT_PTR			DocStringErase( INT_PTR, INT_PTR, LPTSTR, INT_PTR );	//!<	

INT_PTR			DocInsertLetter( PINT_PTR, INT_PTR, TCHAR );	//!<	
INT_PTR			DocInsertString( PINT_PTR, PINT_PTR, PINT_PTR, LPCTSTR, UINT_PTR, BOOLEAN );	//!<	

INT_PTR			DocIterateDelete( LETR_ITR, INT_PTR );	//!<	
HRESULT		DocLineCombine( INT_PTR );	//!<	

HRESULT		DocLineErase( INT_PTR, PBOOLEAN );	//!<	


HRESULT		DocFrameInsert( INT_PTR, INT_PTR );	//!<	
HRESULT		DocScreenFill( LPTSTR );	//!<	

HRESULT		DocPageNumInsert( HINSTANCE, HWND );	//!<	

INT_PTR			DocExClipSelect( UINT_PTR );	//!<	
HRESULT		DocPageAllCopy( UINT_PTR );	//!<	

INT_PTR			DocLetterShiftPos( INT_PTR, INT_PTR, INT_PTR, PINT_PTR, PBOOLEAN );	//!<	
INT_PTR			DocLetterPosGetAdjust( PINT_PTR, INT_PTR, INT_PTR);	//!<	

HRESULT		DocReturnSelStateToggle( INT_PTR, INT_PTR );	//!<	
INT_PTR			DocRangeSelStateToggle( INT_PTR, INT_PTR, INT_PTR, INT_PTR );	//!<	
UINT_PTR		DocLetterSelStateGet( INT_PTR, INT_PTR );	//!<	
INT_PTR			DocPageSelStateToggle( INT_PTR );	//!<	
HRESULT		DocSelRangeSet( INT_PTR, INT_PTR );	//!<	
HRESULT		DocSelRangeGet( PINT_PTR, PINT_PTR );	//!<	
HRESULT		DocSelRangeReset( PINT_PTR, PINT_PTR );	//!<	
VOID		DocSelByteSet( INT_PTR );	//!<	
//BOOLEAN		DocIsSelecting( VOID );

HRESULT		DocSelText2PageName( VOID );	//!<	

LPTSTR		DocClipboardDataGet( PUINT_PTR );	//!<	
HRESULT		DocClipboardDataSet( LPVOID, INT_PTR, UINT_PTR );	//!<	

INT_PTR			DocLineDataGetAlloc( INT_PTR, INT_PTR, LPLETTER *, PINT_PTR, PUINT_PTR );	//!<	
LPSTR		DocPageTextPreviewAlloc( INT_PTR, PINT_PTR );	//!<	

HRESULT		DocThreadDropCopy( VOID );	//!<	

INT_PTR			DocPageTextGetAlloc( FILES_ITR, INT_PTR, UINT_PTR, LPVOID *, BOOLEAN );	//!<	
INT_PTR			DocPageGetAlloc( UINT_PTR, LPVOID * );	//!<	

INT_PTR			DocLineTextGetAlloc( FILES_ITR, INT_PTR, UINT_PTR, UINT_PTR, LPVOID * );	//!<	

INT_PTR			DocSelectedDelete( PINT_PTR, PINT_PTR, UINT_PTR, BOOLEAN );	//!<	
INT_PTR			DocSelectedBrushFilling( LPTSTR, PINT_PTR, PINT_PTR );	//!<	
INT_PTR			DocSelectTextGetAlloc( UINT_PTR, LPVOID *, LPPOINT * );	//!<	

HRESULT		DocExtractExecute( HINSTANCE  );	//!<	

LPARAM		DocOpendFileCheck( LPTSTR );		//!<	
HRESULT		DocFileSave( HWND, UINT_PTR );			//!<	
HRESULT		DocFileOpen( HWND );				//!<	
HRESULT		DocDoOpenFile( HWND, LPTSTR );		//!<	
HRESULT		DocImageSave( HWND, UINT_PTR, HFONT );	//!<	

HRESULT		DocHtmlExport( HWND );

UINT_PTR		DocStringSplitMLT( LPTSTR, INT_PTR, PAGELOAD );	//!<	
UINT_PTR		DocStringSplitAST( LPTSTR, INT_PTR, PAGELOAD );	//!<	

UINT_PTR		DocImportSplitASD( LPSTR, INT_PTR, PAGELOAD );	//!<	


INT_PTR			DocLineStateCheckWithDot( INT_PTR, INT_PTR, PINT_PTR, PINT_PTR, PINT_PTR, PINT_PTR, PBOOLEAN );	//!<	
HRESULT		DocRightGuideline( LPVOID );			//!<	
INT_PTR			DocSpaceShiftProc( UINT_PTR, PINT_PTR, INT_PTR );	//!<	
LPTSTR		DocPaddingSpaceMake( INT_PTR  );			//!<	
LPTSTR		DocPaddingSpaceUni( INT_PTR, PINT_PTR, PINT_PTR, PINT_PTR );	//!<	
LPTSTR		DocPaddingSpaceWithGap( INT_PTR, PINT_PTR, PINT_PTR );	//!<	
LPTSTR		DocPaddingSpaceWithPeriod( INT_PTR, PINT_PTR, PINT_PTR, PINT_PTR, BOOLEAN );	//!<	
HRESULT		DocLastSpaceErase( PINT_PTR , INT_PTR );		//!<	
HRESULT		DocTopLetterInsert( TCHAR, PINT_PTR, INT_PTR );	//!<	
HRESULT		DocLastLetterErase( PINT_PTR, INT_PTR );		//!<	
HRESULT		DocTopSpaceErase( PINT_PTR, INT_PTR );			//!<	
HRESULT		DocRightSlide( PINT_PTR , INT_PTR );			//!<	

HRESULT		DocPositionShift( UINT_PTR, PINT_PTR, INT_PTR );	//!<	
#ifdef DOT_SPLIT_MODE
HRESULT		DocCentreWidthShift( UINT_PTR vk, PINT_PTR, INT_PTR );	//!<	
#endif
HRESULT		DocHeadHalfSpaceExchange( HWND );	//!<	

LPTSTR		DocLastSpDel( vector<LETTER> * );	//!<	

INT_PTR			DocDiffAdjBaseSet( INT_PTR );		//!<	
INT_PTR			DocDiffAdjExec( PINT_PTR, INT_PTR );	//!<	

VOID		ZeroONELINE( LPONELINE );		//!<	
INT_PTR			DocStringInfoCount( LPCTSTR, UINT_PTR, PINT_PTR, PINT_PTR );	//!<	

BOOLEAN		NowPageInfoGet( UINT_PTR, LPPAGEINFOS );	//!<	

BOOLEAN		PageIsDelayed( FILES_ITR, UINT_PTR );	//!<	

UINT_PTR		DocRangeDeleteByMozi( INT_PTR, INT_PTR, INT_PTR, INT_PTR, PBOOLEAN );	//!<	

INT_PTR			DocUndoExecute( PINT_PTR, PINT_PTR );		//!<	
INT_PTR			DocRedoExecute( PINT_PTR, PINT_PTR );		//!<	

LPARAM		DocFileInflate( LPTSTR );			//!<	
INT_PTR			DocFileCloseCheck( HWND, UINT_PTR );	//!<	
HRESULT		DocClipLetter( TCHAR  );			//!<	
VOID		DocBackupDirectoryInit( LPTSTR );	//!<	
HRESULT		DocFileBackup( HWND );				//!<	

HRESULT		DocMultiFileCloseAll( VOID );		//!<	
LPARAM		DocMultiFileClose( HWND, LPARAM );	//!<	
HRESULT		DocMultiFileSelect( LPARAM );		//!<	
HRESULT		DocMultiFileModify( UINT_PTR  );		//!<	
HRESULT		DocMultiFileStore( LPTSTR );		//!<	
INT_PTR			DocMultiFileFetch( INT_PTR, LPTSTR, LPTSTR );	//!<	
LPTSTR		DocMultiFileNameGet( INT_PTR  );		//!<	

HRESULT		DocInverseInit( UINT_PTR  );	//!<	
HRESULT		DocInverseTransform( UINT_PTR, UINT_PTR, PINT_PTR, INT_PTR );	//!<	

HRESULT		SqnInitialise( LPUNDOBUFF );	//!<	
HRESULT		SqnFreeAll( LPUNDOBUFF );		//!<	
HRESULT		SqnSetting( VOID  );			//!<	
UINT_PTR		SqnAppendLetter( LPUNDOBUFF, UINT_PTR, TCHAR, INT_PTR, INT_PTR, UINT_PTR );	//!<	
UINT_PTR		SqnAppendString( LPUNDOBUFF, UINT_PTR, LPCTSTR, INT_PTR, INT_PTR, UINT_PTR );	//!<	
UINT_PTR		SqnAppendSquare( LPUNDOBUFF, UINT_PTR, LPCTSTR, LPPOINT, INT_PTR, UINT_PTR );	//!<	

HRESULT		UnicodeRadixExchange( LPVOID  );		//!<	

INT_PTR			MoziInitialise( LPTSTR, HINSTANCE );	//!<	
HWND		MoziScripterCreate( HINSTANCE, HWND );	//!<	
HRESULT		MoziMoveFromView( HWND , UINT_PTR );		//!<	

INT_PTR			VertInitialise( LPTSTR, HINSTANCE );	//!<	
HWND		VertScripterCreate( HINSTANCE, HWND );	//!<	
HRESULT		VertMoveFromView( HWND , UINT_PTR );		//!<	

#ifdef FIND_STRINGS
HRESULT		FindDialogueOpen( HINSTANCE, HWND );		//!<	
HRESULT		FindDirectly( HINSTANCE, HWND, INT_PTR );
//INT			FindStringJump( UINT_PTR, PINT_PTR, PINT_PTR, PINT_PTR );	//!<	
#ifdef SEARCH_HIGHLIGHT
HRESULT		FindNowPageReSearch( VOID );				//!<	
HRESULT		FindDelayPageReSearch( INT_PTR );				//!<	
HRESULT		FindHighlightOff( VOID );					//!<	
#endif
#endif

#endif	//	NOT _ORRVW

LPCTSTR		NextLineW( LPCTSTR );	//!<	
LPTSTR		NextLineW( LPTSTR );	//!<	

LPSTR		NextLineA( LPSTR  );	//!<	


//Viewerも有り
HRESULT	DraughtInitialise( HINSTANCE, HWND );	//!<	
HWND	DraughtWindowCreate( HINSTANCE, HWND, UINT_PTR );	//!<	

UINT_PTR	DraughtItemAddFromSelect( HWND , UINT_PTR );	//!<	
UINT_PTR	DraughtItemAdding( HWND, LPSTR );		//!<	

UINT_PTR	DraughtAaImageing( HWND, LPAAMATRIX );	//!<	


INT_PTR		TextViewSizeGet( LPCTSTR, PINT_PTR );	//!<	

INT_PTR	AacItemCount( UINT_PTR );				//!<	
HBITMAP	AacArtImageGet( HWND, INT_PTR, LPSIZE, LPSIZE );	//!<	

LPSTR	AacAsciiArtGet( DWORD );			//!<	
INT_PTR		AacArtSizeGet( DWORD, PINT_PTR, PINT_PTR );

VOID DocPageUndelay(VOID);