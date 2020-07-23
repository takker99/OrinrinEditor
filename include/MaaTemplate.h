/*! @file
	@brief 複数行テンプレで使う定数や函数です
	このファイルは MaaTemplate.h です。
	@author	SikigamiHNQ
	@date	2011/00/00
*/

/*
Orinrin Editor : AsciiArt Story Editor for Japanese Only
Copyright (C) 2011 - 2013 Orinrin/SikigamiHNQ

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/
//-------------------------------------------------------------------------------------------------


#pragma once


#include "../resource.h"
//-------------------------------------------------------------------------------------------------

#define EXTRA_NODE_STYLE
//	追加ノード機能

#define EXTRA_NODE	TEXT("[*追加項目*]")

#define WMP_PROF_ACT	(WM_APP+100)	

constexpr auto TREE_WIDTH = 170;	//!<	MAAのツリービューの標準幅
constexpr auto LSSCL_WIDTH = 15;	//!<	MAAのAA一覧のスクロールバーの幅

//	ステータスバーのアイテム内容
constexpr auto SBMAA_PROFNAME = 0;
constexpr auto SBMAA_AXIS = 1;
constexpr auto SBMAA_FILENAME = 2;

//	開けてる
constexpr auto ACT_ALLTREE = 0;
constexpr auto ACT_FAVLIST = 1;
constexpr auto ACT_SUBITEM = 2;	//	２以降に割当

using BUFFERBACK = LRESULT (CALLBACK*)(UINT_PTR, UINT_PTR, UINT_PTR, LPCVOID);
//-------------------------------------------------------------------------------------------------


// このコード モジュールに含まれる関数の宣言
UINT_PTR		Maa_OnMouseWheel( HWND, INT_PTR, INT_PTR, INT_PTR, UINT_PTR );	//!<	
VOID		Maa_OnContextMenu( HWND, HWND, UINT_PTR, UINT_PTR );	//!<	
VOID		Maa_OnChar( HWND , TCHAR, INT_PTR );				//!<	
VOID		Maa_OnSize( HWND , UINT_PTR, INT_PTR, INT_PTR );			//!<	
VOID		Maa_OnCommand( HWND , INT_PTR, HWND, UINT_PTR );		//!<	WM_COMMAND の処理

#ifdef _ORRVW
INT_PTR	CALLBACK OptionDlgProc( HWND, UINT, WPARAM, LPARAM );	//!<	
#endif

VOID		StatusBarMsgSet( UINT_PTR, LPTSTR );	//!<	

LRESULT		TabBarNotify( HWND, LPNMHDR );		//!<	
VOID		TabBarResize( HWND, LPRECT );		//!<	

HRESULT		TreeInitialise( HWND, HINSTANCE, LPRECT );	//!<	
HRESULT		TreeResize( HWND , LPRECT );				//!<	
HRESULT		TreeConstruct( HWND, LPCTSTR, BOOLEAN );	//!<	
LRESULT		TreeNotify( HWND, LPNMTREEVIEW );			//!<	
LPTSTR		TreeBaseNameGet( VOID );					//!<	
UINT_PTR		TreeFavIsUnderCursor( HWND, HWND, INT_PTR, INT_PTR, INT_PTR, UINT_PTR );	//!<	
LPARAM		TreeItemInfoGet( HTREEITEM, LPTSTR, size_t );	//!<	
INT_PTR			TreeSelItemProc( HWND, HTREEITEM, UINT_PTR );	//!<	
UINT_PTR		TreeNodePathGet( HTREEITEM, LPTSTR );	//!<	

HRESULT		TreeMaaFileFind( HWND );	//!<	

LRESULT		CALLBACK FavListFolderNameBack( UINT_PTR, UINT_PTR, UINT_PTR, LPCVOID );	//!<	
HRESULT		FavListSelected( HWND, UINT_PTR );		//!<	
HRESULT		FavContsRedrawRequest( HWND );		//!<	

HRESULT		TabMultipleSelDelete( HWND );		//!<	
HRESULT		TabMultipleDeleteAll( HWND );		//!<	
HRESULT		TabMultipleStore( HWND );			//!<	
INT_PTR			TabMultipleTopMemory( INT_PTR );		//!<	
INT_PTR			TabMultipleNowSel( VOID );			//!<	
HRESULT		TabMultipleDropAdd( HWND, LPCTSTR );	//!<	

HRESULT		TabMultipleCtrlFromFind( HWND );	//!<	


HRESULT		AaItemsInitialise( HWND, HINSTANCE, LPRECT );		//!<	
VOID		AaItemsResize( HWND, LPRECT );						//!<	
VOID		AaItemsDrawItem( HWND, CONST DRAWITEMSTRUCT * );	//!<	
//VOID		AaItemsMeasureItem( HWND, LPMEASUREITEMSTRUCT );	//!<	
HRESULT		AaItemsDoShow( HWND, LPTSTR, UINT_PTR );		//!<	
HRESULT		AaItemsFavUpload( LPSTR, UINT_PTR );			//!<	
UINT_PTR		AaItemsIsUnderCursor( HWND, HWND, INT_PTR );	//!<	
VOID		AaTitleClear( VOID );
INT_PTR			AaTitleAddString( UINT_PTR, LPSTR );			//!<	
VOID		AaTitleSelect( HWND, UINT_PTR );
UINT_PTR		AaItemsDoSelect( HWND, UINT_PTR, UINT_PTR );		//!<	

VOID		Aai_OnKey( HWND, UINT_PTR, BOOL, INT_PTR, UINT_PTR );	//!<	
VOID		Aai_OnVScroll( HWND , HWND, UINT_PTR, INT_PTR );	//!<	

DWORD		AacAssembleFile( HWND, LPTSTR );		//!<	
HRESULT		AacMatrixClear( VOID  );				//!<	
DWORD		AacAssembleSql( HWND, LPCTSTR );		//!<	

#ifdef MAA_TEXT_FIND
HRESULT		AacFindTextEntry( HWND , UINT_PTR );	//!<	
#endif

HRESULT		OpenProfileLoad( HWND, INT_PTR );			//!<	
HRESULT		OpenProfileLogging( HWND, LPCTSTR );	//!<	

#ifndef _ORRVW
  #ifdef MAA_IADD_PLUS
HRESULT		AacItemInsert( HWND, LONG );
  #else
HRESULT		AacItemAdding( HWND, LPTSTR );
  #endif
HRESULT		AacItemDelete( HWND, LONG );
#endif

HRESULT		SqlDatabaseOpenClose( BYTE, LPCTSTR );	//!<	

HRESULT		SqlFavFolderEnum( BUFFERBACK );	//!<	
UINT_PTR		SqlFavCount( LPCTSTR, PUINT_PTR );	//!<	
HRESULT		SqlFavArtEnum( LPCTSTR, BUFFERBACK );	//!<	
HRESULT		SqlFavUpload( LPTSTR, DWORD, LPSTR, UINT_PTR );	//!<	
HRESULT		SqlFavDelete( LPTSTR, DWORD );	//!<	
HRESULT		SqlFavFolderDelete( LPTSTR );	//!<	

INT_PTR			TreeProfileMake( HWND, LPTSTR );
INT_PTR			TreeProfileOpen( HWND );
INT_PTR			TreeProfileRebuild( HWND );
HRESULT		TreeLoadDirCheck( HWND, HWND );

HTREEITEM	MaaSearchTreeItem( INT_PTR );
HTREEITEM	MaaSelectIDfile( HWND, INT_PTR );

HRESULT		MaaBackColourChoose( HWND );

INT_PTR			MaaSearchTreeID( HTREEITEM );

//HRESULT		SqlTreeOpenClose( BYTE, LPCTSTR );
HRESULT		SqlTransactionOnOff( BYTE );

HRESULT		SqlTreeTableCreate( LPTSTR );
UINT_PTR		SqlTreeCount( UINT_PTR, PUINT_PTR );
HRESULT		SqlTreeProfUpdate( LPCTSTR, LPCTSTR );
HRESULT		SqlTreeProfSelect( LPTSTR, UINT_PTR, LPTSTR, UINT_PTR );

UINT_PTR		SqlTreeNodeInsert( UINT_PTR, UINT_PTR, UINT_PTR, LPTSTR );
HRESULT		SqlTreeNodeAllDelete( UINT_PTR );
//HRESULT		SqlTreeNodeEnum( UINT_PTR, BUFFERBACK );
UINT_PTR		SqlTreeNodePickUpID( UINT_PTR, PUINT_PTR, PUINT_PTR, LPTSTR, UINT_PTR );
//UINT_PTR		SqlTreeNodeRootSearch( LPTSTR );
UINT_PTR		SqlChildNodePickUpID( UINT_PTR, UINT_PTR, PUINT_PTR, LPTSTR );

UINT_PTR		SqlTreeFileSearch( LPTSTR, UINT_PTR );
UINT_PTR		SqlTreeFileGetOnParent( LPTSTR, UINT_PTR );

HRESULT		SqlTreeCacheOpenClose( UINT_PTR );
HRESULT		SqlTreeCacheDelID( INT_PTR );
UINT_PTR		SqlTreeCacheInsert( UINT_PTR, UINT_PTR, LPTSTR );


UINT_PTR		SqlMultiTabInsert( LPCTSTR, LPCTSTR, LPCTSTR );
UINT_PTR		SqlMultiTabSelect( INT_PTR, LPTSTR, LPTSTR, LPTSTR );
HRESULT		SqlMultiTabDelete( VOID );

#ifdef EXTRA_NODE_STYLE
UINT_PTR		SqlTreeNodeExtraInsert( UINT_PTR, LPCTSTR );
UINT_PTR		SqlTreeNodeExtraDelete( UINT_PTR );
UINT_PTR		SqlTreeNodeExtraSelect( UINT_PTR, UINT_PTR, LPTSTR );
UINT_PTR		SqlTreeNodeExtraIsFileExist( LPCTSTR );

#endif

