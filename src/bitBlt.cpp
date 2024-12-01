#include <windows.h>
#include "drawingClass.h"

//app line for x minimize button down
void lineM(HWND hwnd)
{
    const char* img = "C:/Users/ME/Desktop/Cpp/todo-list/todo-list/Assets/line.bmp";
    imageImportingClass lineMain(img, 500, 1, hwnd);
    lineMain.updateCordArrPosition(1, 45);

    while (true)
    {
        BitBlt(lineMain.hdc, lineMain.corX, lineMain.corY, 970, 1000, lineMain.memdc, 0, 0, SRCCOPY);
        Sleep(1);
    }
}
//todo image
void todo(HWND hwnd)
{
    const char* img = "C:/Users/ME/Desktop/Cpp/todo-list/todo-list/Assets/to-do.bmp";
    imageImportingClass todoLogo(img, 80, 40, hwnd);
    todoLogo.updateCordArrPosition(11, 5);

    while (true)
    {
        BitBlt(todoLogo.hdc, todoLogo.corX, todoLogo.corY, 970, 1000, todoLogo.memdc, 0, 0, SRCCOPY);
        Sleep(1);
    }
}
//----------------------------------------app top frame
void topBorder(HWND hwnd)
{
    const char* img = "C:/Users/ME/Desktop/Cpp/todo-list/todo-list/Assets/topBorder.bmp";
    imageImportingClass topFrame(img, 497, 4, hwnd);
    topFrame.updateCordArrPosition(1, 0);

    while (true)
    {
        BitBlt(topFrame.hdc, topFrame.corX, topFrame.corY, 970, 1000, topFrame.memdc, 0, 0, SRCCOPY);
        Sleep(1);
    }
}
//----------------------------------------app bottom frame
void bottomBorder(HWND hwnd)
{
    const char* img = "C:/Users/ME/Desktop/Cpp/todo-list/todo-list/Assets/downBorder.bmp";
    imageImportingClass bottomFrame(img, 497, 4, hwnd);
    bottomFrame.updateCordArrPosition(1, 445);

    while (true)
    {
        BitBlt(bottomFrame.hdc, bottomFrame.corX, bottomFrame.corY, 970, 1000, bottomFrame.memdc, 0, 0, SRCCOPY);
        Sleep(1);
    }
}
//----------------------------------------app left frame
void leftBorder(HWND hwnd)
{
    const char* img = "C:/Users/ME/Desktop/Cpp/todo-list/todo-list/Assets/leftBorder.bmp";
    imageImportingClass letfFrame(img, 1, 500, hwnd);
    letfFrame.updateCordArrPosition(0, 0);

    while (true)
    {
        BitBlt(letfFrame.hdc, letfFrame.corX, letfFrame.corY, 970, 1000, letfFrame.memdc, 0, 0, SRCCOPY);
        Sleep(1);
    }
}
//----------------------------------------app right frame
void rightBorder(HWND hwnd)
{
    const char* img = "C:/Users/ME/Desktop/Cpp/todo-list/todo-list/Assets/rightBorder.bmp";
    imageImportingClass rightFrame(img, 1, 500, hwnd);
    rightFrame.updateCordArrPosition(498, 0);

    while (true)
    {
        BitBlt(rightFrame.hdc, rightFrame.corX, rightFrame.corY, 970, 1000, rightFrame.memdc, 0, 0, SRCCOPY);
        Sleep(1);
    }
}