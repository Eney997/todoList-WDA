#include <iostream>
#include <windows.h>
#include "defines.h"

using namespace std;
//-------------------------------------------- externs for build
extern void wmCreateForWindowElements(HWND hwnd);//wm create function
extern void lineM(HWND hwnd);//line bmp
extern void todo(HWND hwnd);//todo bmp
extern void topBorder(HWND hwnd);//topFrame
extern void bottomBorder(HWND hwnd);//bottomFrame
extern void leftBorder(HWND hwnd);//leftFrame
extern void rightBorder(HWND hwnd);//rightFrame
//--------------------------------------------------------------------------------app main window proc control function
long mainWindowProcCOntro(HWND hwnd,unsigned int message,unsigned int wparam,long lparam)
{
    static RECT moveApp = { 0, 0, 500, 50 };//coordinate variable for moveing app
    static HWND remover = {0};
    switch (message)
    {
    //-------------------------------------------- WMCREATE
    case WM_CREATE:
        wmCreateForWindowElements(hwnd);
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)lineM,hwnd,0,0);
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)todo,hwnd,0,0);
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)topBorder,hwnd,0,0);
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)bottomBorder,hwnd,0,0);
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)leftBorder,hwnd,0,0);
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)rightBorder,hwnd,0,0);
    break;
    //-------------------------------------------- WMCOMMAND
    case WM_COMMAND:
    {
        switch ((short)wparam)
        {
        //minimize click
        case minimize_Button:
            ShowWindow(hwnd, SW_MINIMIZE);
        break;
        //exit click
        case exit_Button:
            exit(0);
        break;
        //save todo in editbox
        case todoSave_Button:
        {
            char currentText[5000] = ""; // Buffer for the existing text
            char newTodo[1000] = "";    // Buffer for the new TODO text

            // Get the current text from the output edit box
            SendDlgItemMessageA(hwnd, todoSetter_EditBox, WM_GETTEXT, sizeof(currentText), (LPARAM)currentText);

            // Get the new TODO text from the input edit box
            SendDlgItemMessageA(hwnd, todoIn_EditBox, WM_GETTEXT, sizeof(newTodo), (LPARAM)newTodo);

            //remover = CreateWindowA("button","Remove",WS_CHILD|WS_VISIBLE,200,5,40,40,hwnd,(HMENU)removeTodo_button,0,0);

            // Check if there is already text in the output box
            if (strlen(currentText) > 0) {
                strcat_s(currentText, "\r\n"); // Add newline only if there's existing text
            }

            // Append the new TODO text
            strcat_s(currentText, newTodo);

            // Update the output edit box with the appended text
            SendDlgItemMessageA(hwnd, todoSetter_EditBox, WM_SETTEXT, 0, (LPARAM)currentText);
        }
        break;
        }
    }
    break;
    //-------------------------------------------- LBUTTONDOWN
    case WM_LBUTTONDOWN:
    {
        //main window MOVE onclick
        POINT pt = { LOWORD(lparam),HIWORD(lparam) };
        if (PtInRect(&moveApp, pt))
        {
            SendMessageA(hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
        }
    }
    break;
    //-------------------------------------------- btnStyles
    case WM_CTLCOLORBTN:
    {
        HDC hdc = (HDC)wparam;
        if ((HWND)lparam == GetDlgItem(hwnd, exit_Button))
        {
            SetBkColor(hdc, RGB(30, 30, 30));
            SetTextColor(hdc, RGB(255, 42, 109));
            TextOutA(hdc, 10, 5, "X", 1);
            return (LONG)CreateSolidBrush(RGB(30, 30, 30));
        }
        if ((HWND)lparam == GetDlgItem(hwnd, minimize_Button))
        {
            SetBkColor(hdc, RGB(30, 30, 30));
            SetTextColor(hdc, RGB(255, 0, 109));
            TextOutA(hdc, 10, 3, "_", 1);
            return (LONG)CreateSolidBrush(RGB(30, 30, 30));
        }
        if ((HWND)lparam == GetDlgItem(hwnd, todoSave_Button))
        {
            SetBkColor(hdc, RGB(30, 30, 30));
            SetTextColor(hdc, RGB(255, 0, 109));
            TextOutA(hdc, 13, 9, "Save", 4);
            return (LONG)CreateSolidBrush(RGB(30, 30, 30));
        }
    }
    break;
    //-------------------------------------------- btnStyles
    case WM_CTLCOLOREDIT:
    {
        HDC hdc = (HDC)wparam;
        SetBkColor(hdc, RGB(30, 30, 30));
        SetTextColor(hdc, RGB(255, 0, 109));
        return (LONG)CreateSolidBrush(RGB(30, 30, 30));
    }
    break;
    //-------------------------------------------- ESC
    case WM_KEYDOWN:
    {
        switch ((short)wparam)
        {
        case VK_ESCAPE:
            exit(0);
        break;
        }
    }
    break;
    //-------------------------------------------- POSTQUITMESSAGE
    case WM_DESTROY:
       PostQuitMessage(0);
    break;

    }
    return DefWindowProcA(hwnd, message, wparam, lparam);
}
//--------------------------------------------------------------------------------app main window class creation
int APIENTRY wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
    WNDCLASSA fw = {0};
    DWORD winSt = WS_POPUP | WS_VISIBLE;
    int x = 500, y = 250, wid = 500, hei = 450;
    HWND hwnd = {0};

    fw.hbrBackground = CreateSolidBrush(RGB(12,12,12));
    fw.lpszClassName = "todoClass";
    fw.lpfnWndProc = (WNDPROC)mainWindowProcCOntro;

    if(!RegisterClassA(&fw))
    {
        cout << "creation failed" << endl;
    }

    hwnd = CreateWindowA(fw.lpszClassName,"windowTtl",winSt,x,y,wid,hei,0,0,0,0);
    HRGN hrgn = CreateRoundRectRgn(0,0,500,450,6,6);
    SetWindowRgn(hwnd,hrgn,1);

    MSG msg = {0};
    while (GetMessageA(&msg,0,0,0))
    {
        DispatchMessageA(&msg);
        TranslateMessage(&msg);
    }
}