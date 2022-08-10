#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>

typedef WINAPI COLORREF (*GETPIXEL)(HDC, int, int);

int main(int argc, char** argv)
{

    HINSTANCE _hGDI = LoadLibrary("gdi32.dll");
    if(_hGDI)
    {
        while(true) { 
            GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {
                POINT _cursor;
                GetCursorPos(&_cursor);
                COLORREF _color = (*pGetPixel) (_hdc, _cursor.x, _cursor.y);
                int _red = GetRValue(_color);
                int _green = GetGValue(_color);
                int _blue = GetBValue(_color);

		std::cout << _red<< ", ";
		std::cout << _green << ", ";
		std::cout << _blue<<std::endl;
                
                if (_red == 212 && _green == 19 && _blue == 24)
                {
                	return 0;
                }

                if (_red == 24 && _green == 24 && _blue == 24)
                {
			std::cout<<"Key Pressed"<<std::endl;
			Sleep(500);
			keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
			Sleep(1);
			keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
                        Sleep(2000);
                } 
            }
            FreeLibrary(_hGDI);
        }
    }
    return 0;
}
