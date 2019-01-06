// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef IHTML_H
#define IHTML_H

#include "IImage.h"
#include "basetypes.h"

enum ButtonCode_t
{
	BUTTON_CODE_INVALID = -1,
	BUTTON_CODE_NONE = 0,
	KEY_FIRST = 0,
	KEY_NONE = KEY_FIRST,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_PAD_0,
	KEY_PAD_1,
	KEY_PAD_2,
	KEY_PAD_3,
	KEY_PAD_4,
	KEY_PAD_5,
	KEY_PAD_6,
	KEY_PAD_7,
	KEY_PAD_8,
	KEY_PAD_9,
	KEY_PAD_DIVIDE,
	KEY_PAD_MULTIPLY,
	KEY_PAD_MINUS,
	KEY_PAD_PLUS,
	KEY_PAD_ENTER,
	KEY_PAD_DECIMAL,
	KEY_LBRACKET,
	KEY_RBRACKET,
	KEY_SEMICOLON,
	KEY_APOSTROPHE,
	KEY_BACKQUOTE,
	KEY_COMMA,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_BACKSLASH,
	KEY_MINUS,
	KEY_EQUAL,
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_TAB,
	KEY_CAPSLOCK,
	KEY_NUMLOCK,
	KEY_ESCAPE,
	KEY_SCROLLLOCK,
	KEY_INSERT,
	KEY_DELETE,
	KEY_HOME,
	KEY_END,
	KEY_PAGEUP,
	KEY_PAGEDOWN,
	KEY_BREAK,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_LALT,
	KEY_RALT,
	KEY_LCONTROL,
	KEY_RCONTROL,
	KEY_LWIN,
	KEY_RWIN,
	KEY_APP,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_CAPSLOCKTOGGLE,
	KEY_NUMLOCKTOGGLE,
	KEY_SCROLLLOCKTOGGLE,
	KEY_LAST = KEY_SCROLLLOCKTOGGLE,
	KEY_COUNT = KEY_LAST - KEY_FIRST + 1,
	MOUSE_FIRST = KEY_LAST + 1,
	MOUSE_LEFT = MOUSE_FIRST,
	MOUSE_RIGHT,
	MOUSE_MIDDLE,
	MOUSE_4,
	MOUSE_5,
	MOUSE_WHEEL_UP,
	MOUSE_WHEEL_DOWN,
	MOUSE_LAST = MOUSE_WHEEL_DOWN,
	MOUSE_COUNT = MOUSE_LAST - MOUSE_FIRST + 1,
};

enum EHTMLCommands
{
	eHTMLCommands_KeyUp,
	eHTMLCommands_KeyDown,
	eHTMLCommands_KeyChar,
	eHTMLCommands_MouseDown,
	eHTMLCommands_MouseUp,
	eHTMLCommands_MouseDblClick,
	eHTMLCommands_MouseWheel,
	eHTMLCommands_MouseMove,
	eHTMLCommands_MouseLeave,
	eHTMLCommands_BrowserCreate,
	eHTMLCommands_BrowserRemove,
	eHTMLCommands_BrowserErrorStrings,
	eHTMLCommands_BrowserSize,
	eHTMLCommands_BrowserPosition,
	eHTMLCommands_PostURL,
	eHTMLCommands_StopLoad,
	eHTMLCommands_Reload,
	eHTMLCommands_GoForward,
	eHTMLCommands_GoBack,
	eHTMLCommands_Copy,
	eHTMLCommands_Paste,
	eHTMLCommands_ExecuteJavaScript,
	eHTMLCommands_SetFocus,
	eHTMLCommands_HorizontalScrollBarSize,
	eHTMLCommands_VerticalScrollBarSize,
	eHTMLCommands_Find,
	eHTMLCommands_StopFind,
	eHTMLCommands_SetHorizontalScroll,
	eHTMLCommands_SetVerticalScroll,
	eHTMLCommands_SetZoomLevel,
	eHTMLCommands_ViewSource,
	eHTMLCommands_NeedsPaintResponse,
	eHTMLCommands_AddHeader,
	eHTMLCommands_GetZoom,
	eHTMLCommands_FileLoadDialogResponse,
	eHTMLCommands_LinkAtPosition,
	eHTMLCommands_ZoomToElementAtPosition,
	eHTMLCommands_SavePageToJPEG,
	eHTMLCommands_JSAlert,
	eHTMLCommands_JSConfirm,
	eHTMLCommands_CanGoBackandForward,
	eHTMLCommands_OpenSteamURL,
	eHTMLCommands_SizePopup,
	eHTMLCommands_SetCookie,
	eHTMLCommands_SetTargetFrameRate,
	eHTMLCommands_FullRepaint,
	eHTMLCommands_SetPageScale,
	eHTMLCommands_RequestFullScreen,
	eHTMLCommands_ExitFullScreen,
	eHTMLCommands_GetCookiesForURL,
	eHTMLCommands_ZoomToCurrentlyFocusedNode,
	eHTMLCommands_CloseFullScreenFlashIfOpen,
	eHTMLCommands_PauseFullScreenFlashMovieIfOpen,
	eHTMLCommands_GetFocusedNodeValue,
	eHTMLCommands_BrowserCreateResponse,
	eHTMLCommands_BrowserReady,
	eHTMLCommands_URLChanged,
	eHTMLCommands_FinishedRequest,
	eHTMLCommands_StartRequest,
	eHTMLCommands_ShowPopup,
	eHTMLCommands_HidePopup,
	eHTMLCommands_OpenNewTab,
	eHTMLCommands_PopupHTMLWindow,
	eHTMLCommands_PopupHTMLWindowResponse,
	eHTMLCommands_SetHTMLTitle,
	eHTMLCommands_LoadingResource,
	eHTMLCommands_StatusText,
	eHTMLCommands_SetCursor,
	eHTMLCommands_FileLoadDialog,
	eHTMLCommands_ShowToolTip,
	eHTMLCommands_UpdateToolTip,
	eHTMLCommands_HideToolTip,
	eHTMLCommands_SearchResults,
	eHTMLCommands_Close,
	eHTMLCommands_VerticalScrollBarSizeResponse,
	eHTMLCommands_HorizontalScrollBarSizeResponse,
	eHTMLCommands_GetZoomResponse,
	eHTMLCommands_StartRequestResponse,
	eHTMLCommands_NeedsPaint,
	eHTMLCommands_LinkAtPositionResponse,
	eHTMLCommands_ZoomToElementAtPositionResponse,
	eHTMLCommands_JSDialogResponse,
	eHTMLCommands_ScaleToValueResponse,
	eHTMLCommands_RequestFullScreenResponse,
	eHTMLCommands_GetCookiesForURLResponse,
	eHTMLCommands_NodeGotFocus,
	eHTMLCommands_SavePageToJPEGResponse,
	eHTMLCommands_GetFocusedNodeValueResponse,
	eHTMLCommands_None,
};

typedef ButtonCode_t MouseCode;
typedef ButtonCode_t KeyCode;
typedef ButtonCode_t CursorCode;

class CUtlString;
class IHTMLResponses;
struct HTMLCommandBuffer_t;

class IHTML
{
public:
	virtual void OpenURL(const char *) = 0;
	virtual bool StopLoading() = 0;
	virtual bool Refresh() = 0;
	virtual bool Show(bool shown) = 0;
	virtual const char *GetOpenedPage() = 0;
	virtual void Obsolete_OnSize(int x, int y, int w, int h) = 0;
	virtual void GetHTMLSize(int &wide, int &tall) = 0;
	virtual void Clear() = 0;
	virtual void AddText(const char *text) = 0;
	enum MOUSE_STATE { UP, DOWN, MOVE, DBLCLICK };
	virtual void Obsolete_OnMouse(MouseCode code, MOUSE_STATE s, int x, int y) = 0;
	virtual void Obsolete_OnChar(wchar_t unichar) = 0;
	virtual void Obsolete_OnKeyDown(KeyCode code) = 0;
	virtual IImage *GetBitmap() = 0;
	virtual void SetVisible(bool state) = 0;
	virtual void SetSize(int wide, int tall) = 0;
	virtual void OnMouse(MouseCode code, MOUSE_STATE s, int x, int y, bool bPopupMenuMenu) = 0;
	virtual void OnChar(wchar_t unichar, bool bPopupMenu) = 0;
	virtual void OnKeyDown(KeyCode code, bool bPopupMenu) = 0;
	virtual void ScrollV(int nPixels) = 0;
	virtual void ScrollH(int nPixels) = 0;
	virtual void OnMouseWheeled(int delta, bool bPopupMenu) = 0;
	virtual void OnKeyUp(KeyCode code, bool bPopupMenu) = 0;
	virtual void PostURL(const char *pchURL, const char *pchPostData) = 0;
	virtual void RunJavascript(const char *pchScript) = 0;
	virtual void SetMousePosition(int x, int y, bool bPopupMenu) = 0;
	virtual void SetUserAgentInfo(const wchar_t *pwchUserAgent) = 0;
	virtual void AddHeader(const char *pchHeader, const char *pchValue) = 0;
	virtual void SetFileDialogChoice(const char *pchFileName) = 0;
	virtual void HidePopup() = 0;
	virtual void SetHTMLFocus() = 0;
	virtual void KillHTMLFocus() = 0;
	virtual void HorizontalScrollBarSize(int &x, int &y, int &wide, int &tall) = 0;
	virtual void VerticalScrollBarSize(int &x, int &y, int &wide, int &tall) = 0;
	virtual int HorizontalScroll() = 0;
	virtual int VerticalScroll() = 0;
	virtual int HorizontalScrollMax() = 0;
	virtual int VerticalScrollMax() = 0;
	virtual bool IsHorizontalScrollBarVisible() = 0;
	virtual bool IsVeritcalScrollBarVisible() = 0;
	virtual void SetHorizontalScroll(int scroll) = 0;
	virtual void SetVerticalScroll(int scroll) = 0;
	virtual void ViewSource() = 0;
	virtual void Copy() = 0;
	virtual void Paste() = 0;
	virtual bool IsIERender() = 0;
	virtual void GetIDispatchPtr(void **pIDispatch) = 0;
	virtual void GetHTMLScroll(int &top, int &left) = 0;
};

class IHTMLEvents
{
public:
	virtual bool Obsolete_OnStartURL(const char *url, const char *target, bool first) = 0;
	virtual void Obsolete_OnFinishURL(const char *url) = 0;
	virtual void Obsolete_OnProgressURL(long current, long maximum) = 0;
	virtual void Obsolete_OnSetStatusText(const char *text) = 0;
	virtual void Obsolete_OnUpdate() = 0;
	virtual void Obsolete_OnLink() = 0;
	virtual void Obsolete_OffLink() = 0;
	virtual void OnURLChanged(const char *url, const char *pchPostData, bool bIsRedirect) = 0;
	virtual void OnFinishRequest(const char *url, const char *pageTitle) = 0;
	virtual bool OnStartRequestInternal(const char *url, const char *target, const char *pchPostData, bool bIsRedirect) = 0;
	virtual void ShowPopup(int x, int y, int wide, int tall) = 0;
	virtual void HidePopup() = 0;
	virtual bool OnPopupHTMLWindow(const char *pchURL, int x, int y, int wide, int tall) = 0;
	virtual void SetHTMLTitle(const char *pchTitle) = 0;
	virtual void OnLoadingResource(const char *pchURL) = 0;
	virtual void OnSetStatusText(const char *text) = 0;
	virtual void OnSetCursor(CursorCode cursor) = 0;
	virtual void OnFileLoadDialog(const char *pchTitle, const char *pchInitialFile) = 0;
	virtual void OnShowToolTip(const char *pchText) = 0;
	virtual void OnUpdateToolTip(const char *pchText) = 0;
	virtual void OnHideToolTip() = 0;
	virtual bool BOnCreateNewWindow(void **ppDispatch) = 0;
	virtual void OnLink() = 0;
	virtual void OffLink() = 0;
	virtual void OnCloseWindow() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnProgressRequest(long current, long maximum) = 0;
	virtual bool OnOpenNewTab(const char *pchURL, bool bForeground) = 0;
};

class IHTMLChromeController
{
public:
	virtual ~IHTMLChromeController() {}
	virtual bool Init(const char *pchHTMLCacheDir, const char *pchCookiePath) = 0;
	virtual void Shutdown() = 0;
	virtual bool RunFrame() = 0;
	virtual void SetWebCookie(const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath, RTime32 nExpires = 0) = 0;
	virtual void GetWebCookiesForURL(CUtlString *pstrValue, const char *pchURL, const char *pchName) = 0;
	virtual void SetClientBuildID(uint64 ulBuildID) = 0;
	virtual bool BHasPendingMessages() = 0;
	virtual void CreateBrowser(IHTMLResponses *pBrowser, bool bPopupWindow, const char *pchUserAgentIdentifier) = 0;
	virtual void RemoveBrowser(IHTMLResponses *pBrowser) = 0;
	virtual void WakeThread() = 0;
	virtual HTMLCommandBuffer_t *GetFreeCommandBuffer(EHTMLCommands eCmd, int iBrowser) = 0;
	virtual void PushCommand(HTMLCommandBuffer_t *) = 0;
	virtual void SetCefThreadTargetFrameRate(uint32 nFPS) = 0;
};

#endif