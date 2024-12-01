#include <windows.h>
#include "drawingClass.h"

//image importing class creating constructor and 1 function called updateCordArrPosition.
imageImportingClass::imageImportingClass(const char* imgAdSet, int width, int height, HWND hwfh) {
	hwnd = hwfh;
	hdc = GetDC(hwnd);
	memdc = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImageA(NULL, imgAdSet, NULL, width, height, LR_LOADFROMFILE);
	SelectObject(memdc, hbitmap);
};
//Function for image coordinates(Where they can sit?)
void imageImportingClass::updateCordArrPosition(int xze, int yze) {
	corX = xze;
	corY = yze;
};