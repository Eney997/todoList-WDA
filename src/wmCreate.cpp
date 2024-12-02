#include <windows.h>
#include "defines.h"

void wmCreateForWindowElements(HWND hwnd)
{
	static HWND elemntCreation[10] = {0};
	static HFONT hf = {0};
	static DWORD winStls = WS_VISIBLE | WS_CHILD;
	hf = CreateFontA(32, 10, 0, 0, 400, 0, 0, 0, 0, 0, 0, 320, 320, "impact");

	elemntCreation[0] = CreateWindowA("button","X",winStls|BS_OWNERDRAW|WS_BORDER,450,8,30,30,hwnd,(HMENU)exit_Button,0,0);
	elemntCreation[1] = CreateWindowA("button","_",winStls|BS_OWNERDRAW|WS_BORDER,420,8,30,30,hwnd,(HMENU)minimize_Button,0,0);

	elemntCreation[2] = CreateWindowA("Edit","",winStls|WS_BORDER,35,70,350,40,hwnd,(HMENU)todoIn_EditBox,0,0);
	SendMessageA(elemntCreation[2],WM_SETFONT,(UINT)hf,0);

	elemntCreation[3] = CreateWindowA("button","",winStls|WS_BORDER|BS_OWNERDRAW,400,70,60,40,hwnd,(HMENU)todoSave_Button,0,0);

	elemntCreation[4] = CreateWindowA("Edit","",winStls|ES_MULTILINE|WS_VSCROLL,35,120,425,300,hwnd,(HMENU)todoSetter_EditBox,0,0);
	SendMessageA(elemntCreation[4], WM_SETFONT, (UINT)hf, 0);
}
