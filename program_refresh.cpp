#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>

typedef WINAPI COLORREF (*GETPIXEL)(HDC, int, int);

void DownClick(int j){
    for (size_t i = 0; i < j; i++)
    {
        std::cout<<"Key down Pressed "<<std::endl;
		Sleep(50);
		keybd_event(VK_DOWN, 0, KEYEVENTF_EXTENDEDKEY, 0);
		Sleep(1);
		keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
        Sleep(50);
    }
    
}

void LeftClick(int x,int y)
{
	SetCursorPos(x,y);
	mouse_event(MOUSEEVENTF_LEFTDOWN,x,y,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,x,y,0,0);
}

int funkcja_refresh(int _red,int _green,int _blue, int& i, int& refresh){
    
    if (_red == 24 && _green == 24 && _blue == 24) // enter RGB values u want program to close on detecting
                {
                        std::cout << "strona zaladowana"<<std::endl;
                        refresh = 0;
                }

                if (_red == 212 && _green == 19 && _blue == 24) // enter RGB values u want program to press F5
                {
			            std::cout<<"Key Pressed 'high traffic'"<<std::endl;
			            Sleep(500);
			            keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
			            Sleep(1);
			            keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
                        Sleep(5000);
                }
                
                if (_red == 32 && _green == 33 && _blue == 36) // enter RGB values u want program to press F5
                {
			            std::cout<<"Key Pressed F5 "<<std::endl;
			            Sleep(500);
			            keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
			            Sleep(1);
			            keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
                        Sleep(5000);
                }
            
                if (_red == 255 && _green == 255 && _blue == 255) // enter RGB values u want program to press F5
                {                    
                    i = i+1;
                    std::cout << i << std::endl;
                    if (i == 550)
                    {
                        std::cout<<"Key Pressed F5 'witryna nieosiogalna'"<<std::endl;
			            Sleep(500);
			            keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
			            Sleep(1);
			            keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
                        Sleep(5000);
                        i = 0;
                    }
                }
}

int main(int argc, char** argv)
{
int i = 0;
int refresh = 1;
int coal;
int opcja;
std::cout << "Wybierz opcje dzialania programu:"<< std::endl;
std::cout<< "1. Tylko odswierzanie" << std::endl;
std::cout<< "2. Odswierzanie z dodawaniem do koszyka" << std::endl;
std::cin >> opcja;
//system("cls");
    HINSTANCE _hGDI = LoadLibrary("gdi32.dll");
    if(_hGDI)
    {
        while(true) { 
            GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {
                POINT _cursor;
                GetCursorPos(&_cursor); //Get cursor position
                COLORREF _color = (*pGetPixel) (_hdc, 820, 130); //_cursor.x, _cursor.y); // 2 monitor 2800, 170);
                int _red = GetRValue(_color);
                int _green = GetGValue(_color);
                int _blue = GetBValue(_color); //Get RGB values from cursor postion

				//std::cout << _red<< ", ";
				//std::cout << _green << ", ";    //Print RGB values on cursor postion
				//std::cout << _blue<<std::endl;
                //std::cout <<std::endl;
                //Sleep(2500);
                //std::cout << _cursor.x << ", "<<_cursor.y <<std::endl;
                //Sleep(2500);
                //std::cout << _cursor.x << ", "<<_cursor.y <<std::endl

                //poziom 1410 dodaj do koszyka // 375 pion 1 opcja po 10 strzałek w dół
                //poziom 1360 zmien ilość ton
                //27 rodzaji
                
                switch (opcja)
                {
                case 1:
                std::cout<< "start za: ";
                Sleep(250);
                std::cout<< "3 ";
                Sleep(1000);
                std::cout<< "2 ";
                Sleep(1000);
                std::cout<< "1 ";
                Sleep(1000);
                std::cout << std::endl;
                    if (refresh == 1)
                    {
                    funkcja_refresh(_red, _green, _blue, i, refresh);
                    }
                    return 0;
                break;

                case 2:

                std::cout<< "Wybierz opcje dodania do koszyka: " << std::endl;
                std::cout<< "1. Pieklorz Ekogroszek Paleta 1000 kg" << std::endl;
                std::cout<< "2. Karlik Ekogroszek Paleta 1000 kg" << std::endl;
                std::cout<< "3. Karlik Ekogroszek Paleta 750 kg" << std::endl;
                std::cout<< "4. Karlik Ekogroszek Big Bag 1000 kg" << std::endl;
                //add more for more options
                std::cin >> coal;

                std::cout<< "start za: ";
                Sleep(250);
                std::cout<< "3 ";
                Sleep(1000);
                std::cout<< "2 ";
                Sleep(1000);
                std::cout<< "1 ";
                Sleep(1000);
                std::cout << std::endl;
                    if (refresh == 1)
                    {
                    funkcja_refresh(_red, _green, _blue, i, refresh);
                    }

                    if (refresh == 0)
                {
                   switch (coal)
                    {
                    case 1:
                        DownClick(10);
                        Sleep(250);
                        LeftClick(1350,375);
                        Sleep(250);              // zmiana ilosci ton 1350 //625 zeby zienic na 2 tony bez spacji //420 zeby zmienic tony na 2
                        LeftClick(1350,420);     //1410  1350
                        Sleep(250);              //375   420
                        LeftClick(1410,375);
                        return 0;
                    break;
                    case 2:
                        DownClick(13);
                        Sleep(250);
                        LeftClick(1350,375);
                        Sleep(250);              // zmiana ilosci ton 1350 //625 zeby zienic na 2 tony bez spacji //420 zeby zmienic tony na 2
                        LeftClick(1350,420);     //1410  1350
                        Sleep(250);              //375   420
                        LeftClick(1410,375);    //120 pixeli w dół następne opcje
                        return 0;
                    break;

                    case 3:
                        DownClick(16);
                        Sleep(250);
                        LeftClick(1350,375);
                        Sleep(250);              // zmiana ilosci ton 1350 //625 zeby zienic na 2 tony bez spacji //420 zeby zmienic tony na 2
                        LeftClick(1350,420);     //1410  1350
                        Sleep(250);              //375   420
                        LeftClick(1410,375);    //120 pixeli w dół następne opcje
                        return 0;
                    break;

                    case 4:
                        DownClick(19);
                        Sleep(250);
                        LeftClick(1350,375);
                        Sleep(250);              // zmiana ilosci ton 1350 //625 zeby zienic na 2 tony bez spacji //420 zeby zmienic tony na 2
                        LeftClick(1350,420);     //1410  1350
                        Sleep(250);              //375   420
                        LeftClick(1410,375);    //120 pixeli w dół następne opcje
                        return 0;
                    break;

                    default:
                    break;
                    } 
                }
                break;
                
                default:
                    break;
                }
            }
            FreeLibrary(_hGDI);
        }
    }
    return 0;
}
// TODO add comments, add more user preferences etc
