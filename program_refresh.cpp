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
		Sleep(10);
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
    else if (_red == 212 && _green == 19 && _blue == 24) // enter RGB values u want program to press F5
    {
		std::cout<<"Key Pressed 'high traffic'"<<std::endl;
		Sleep(500);
		keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
		Sleep(1);
		keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
        Sleep(5000);
    }   
    else if (_red == 32 && _green == 33 && _blue == 36) // enter RGB values u want program to press F5
    {
	    std::cout<<"Key Pressed F5 "<<std::endl;
	    Sleep(500);
	    keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
	    Sleep(1);
	    keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
        Sleep(5000);
    }
    else if (_red == 255 && _green == 255 && _blue == 255) // enter RGB values u want program to press F5
    {                                                      //If white screen appears it waits half a second and presses F5
        i = i+1;
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
    else
    {
         std::cout<<"unknown color"<<std::endl;
    }
    

}

void SelectProduct(int ilosc, int coal){ // ilocs turned off
/*
if (ilosc == 2)
{
    //DownClick(10+(coal*3)-3);      // Comented because site turned off ability to change ammount of products to add to cart || look at
    //Sleep(250);
    //LeftClick(1350,440);      // 1350, 440 working 28-08-2022
    //Sleep(250);              
    //LeftClick(1350,485);     
    //Sleep(250);              
    LeftClick(1410,440);
}
else if (ilosc == 1)
{
    //DownClick(10+(coal*3)-3); 
    //Sleep(250);
    //LeftClick(1350,440);
    //Sleep(250);              
    //LeftClick(1350,470);     
    //Sleep(250);              
    LeftClick(1410,440);
}
*/
Sleep(250); 
DownClick(10+(coal*3)-3); 

if (coal == 5)
{
    LeftClick(1410,690); // quick addition for pal
} 
else{
LeftClick(1410,440);
}
}

void MistakeOption(int& opcja){
if (opcja > 2 || opcja < 1)
{
    std::cout << "Wybierz Poprawna opcje!"<< std::endl;
    std::cout << "Wybierz opcje dzialania programu:"<< std::endl;
    std::cout<< "1. Tylko odswierzanie" << std::endl;
    std::cout<< "2. Odswierzanie z dodawaniem do koszyka" << std::endl;    
    std::cin >> opcja;
    MistakeOption(opcja);
}
}

void MistakeCoal(int& coal){
if (coal > 5 || coal < 1)
{
    std::cout << "Wybierz Poprawna opcje!"<< std::endl;
    std::cout<< "Wybierz opcje dodania do koszyka: " << std::endl;
    std::cout<< "1. Pieklorz Ekogroszek Paleta 1000 kg (50 workow x 20 kg)" << std::endl;
    std::cout<< "2. Karlik Ekogroszek Paleta 1000 kg (50 workow x 20 kg)" << std::endl;
    std::cout<< "3. Karlik Ekogroszek Paleta 750 kg (30 workow x 25 kg)" << std::endl;
    std::cout<< "4. Karlik Ekogroszek Big Bag 1000 kg (wegiel luzem)" << std::endl;
    std::cout<< "5. Pieklorz Ekogroszek 1000 kg luz (wegiel luzem)" << std::endl;
    std::cin >> coal;
    MistakeCoal(coal);
}
}
// Comented because site turned off ability to change ammount of products to add to cart
/*
void Mistakeilosc(int& ilosc){
if (ilosc > 2 || ilosc < 1)
{
    std::cout << "Wybierz Poprawna opcje!"<< std::endl;
    std::cout<< "Wybierz ilosc " << std::endl;
    std::cout<< "1. 1 " << std::endl;
    std::cout<< "2. 2 " << std::endl;
    std::cin >> ilosc;
    Mistakeilosc(ilosc);
}
}
*/
int main(int argc, char** argv)
{
int i = 0;
int refresh = 1;
int coal;
int opcja;
int ilosc;
std::cout << "Wybierz opcje dzialania programu:"<< std::endl;
std::cout<< "1. Tylko odswierzanie" << std::endl;
std::cout<< "2. Odswierzanie z dodawaniem do koszyka" << std::endl;                
std::cin >> opcja;

MistakeOption(opcja);

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
    break;
case 2:
std::cout<< "Wybierz opcje dodania do koszyka: " << std::endl;
std::cout<< "1. Pieklorz Ekogroszek Paleta 1000 kg (50 workow x 20 kg)" << std::endl;
std::cout<< "2. Karlik Ekogroszek Paleta 1000 kg (50 workow x 20 kg)" << std::endl;
std::cout<< "3. Karlik Ekogroszek Paleta 750 kg (30 workow x 25 kg)" << std::endl;
std::cout<< "4. Karlik Ekogroszek Big Bag 1000 kg (wegiel luzem)" << std::endl;
std::cout<< "5. Pieklorz Ekogroszek 1000 kg luz (wegiel luzem)" << std::endl;
//add more for more options
std::cin >> coal;
MistakeCoal(coal);

// Comented because site turned off ability to change ammount of products to add to cart
//std::cout<< "Wybierz ilosc " << std::endl;
//std::cout<< "1. 1 " << std::endl;
//std::cout<< "2. 2 " << std::endl;
//add more for more options 
//std::cin >> ilosc;
//Mistakeilosc(ilosc);

std::cout<< "start za: ";
Sleep(250);
std::cout<< "3 ";
Sleep(1000);
std::cout<< "2 ";
Sleep(1000);
std::cout<< "1 ";
Sleep(1000);
std::cout << std::endl;
    break;
default:
    break;
}
	HINSTANCE _hGDI = LoadLibrary("gdi32.dll");
    if(_hGDI)
    {
        while(true) { 
            GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
            HDC _hdc = ::GetDC(NULL);
            if(_hdc)
            {
                //POINT _cursor;
                //GetCursorPos(&_cursor); //Get cursor position
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
                //Sleep(2500);                                              /Write out cursos pos
                //std::cout << _cursor.x << ", "<<_cursor.y <<std::endl;

                switch (opcja)
                {
                case 1:
                
                    if (refresh == 1)
                    {
                    funkcja_refresh(_red, _green, _blue, i, refresh);
                    }
                    else if (refresh == 0)
                    {
                        return 0;
                    }
                break;
                case 2:
                
                    if (refresh == 1)
                    {
                    funkcja_refresh(_red, _green, _blue, i, refresh);
                    }
                    else if (refresh == 0)
                    {
                   switch (coal)
                    {
                    case 1:
                        SelectProduct(ilosc, coal);
                        return 0;
                    break;
                    case 2:
                        SelectProduct(ilosc, coal);
                        return 0;
                    break;
                    case 3:
                        SelectProduct(ilosc, coal);
                        return 0;
                    break;
                    case 4:
                        SelectProduct(ilosc, coal);
                        return 0;
                    break;
                    case 5:
                        SelectProduct(ilosc, coal);
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
            ReleaseDC(NULL, _hdc);
            FreeLibrary(_hGDI);
        }
    }
    return 0;
}
// TODO add comments, add more user preferences etc
