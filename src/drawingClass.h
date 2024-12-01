#pragma once
//image importing class
class imageImportingClass {
public:
    HWND hwnd = { 0 };
    HDC hdc = { 0 }, memdc = { 0 };
    HBITMAP hbitmap = { 0 };
    int corX = { 0 };
    int corY = { 0 };
    //Constructor for loadimage

    imageImportingClass(const char* imgAdSet, int width, int height, HWND hwfh);
    //Function for image coordinates(Where they can sit?)
    void updateCordArrPosition(int xze, int yze);
};
