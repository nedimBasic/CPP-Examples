/* Filename:  29winAPIsimpleDrawing.cpp

   Programmers:  Nedim Basic

   Date:  November 14, 2017

   This graphical program places a window on the screen and sequences through a few
   simple calculations of circumferences or perimeters or area or radius of the circle when the user clicks with the mouse.

   Project: Open access to Knowledge

   Project Sponsor: Academic Portal

   Version: 2.0

   Copyright: All rights are reserved
//============================================================================
//	Task        : Made program with follow requirements:
                  Window with title 'Circle Calculator v 2.0'
                  Text label Choose a Calculation
                  Text combobox for three options of calculation
                  Text label r side by side of text input r
                  Text input r
                  Text label Units* side by side of text input Units
                  Text combobox for Units cm, mm, m, in, yd, ft,
                  Start button for calculation based on given r with loaded images start button
                  Restart button for clearing content of text input
// Learn terms : 1. windows.h, commctrl.h
                 2. WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
                 3. CreateWindow(lpszClassName,lpszTitleName,TypeofWindow,startXposition,startYposition,weight,height,HWND,HMENU,HINSTANCE,NULL)
                 4. WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam))
                 5. GetMessage(&msg, NULL, 0, 0)
                 6. HWND
                 7. WNDCLASS (attributes hbrBackground,hCursor,hInstance,lpszClassName,lpszClassName)
                 9. RegisterClass(&WNDCLASS)
                 10. user inline function stringLength (char *String),stringToInt (char *String),char *tochar(long int i, char *p)
                 11. loadImages() user function for loading images when WM_CREATE window is called
                 12. AddControls(HWND) user function for adding text label, text input, combobox, buttons
                 13. atof(const char*) user function for convert string into double from string.h
                 14. pow(int,int) user function for calculate exponent of int number from cmath
//============================================================================
*/

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <commctrl.h>
#include <wingdi.h>
#include <gdiplus.h>


#define CALCULATE_BUTTON 0
#define PRINT_BUTTON 1
#define PI 3.141592 // Precision is set on 6 decimal places
// Global handler:

 HWND hMainWnd,hLogo,hProjectSponsor,hEditRadius,hEditAnswer,hCalculateButton,hEditUnits;
 HBITMAP hLogoImage, hRestartImage, hStartImage;

// Function prototype:

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void AddControls(HWND);
void loadImages();

inline int
stringLength (char *String)
    {
    int Count = 0;
    while (*String ++) ++ Count;
    return Count;
    }

inline int
stringToInt (char *String)
    {
    long int Integer = 0;
    long int Length = stringLength(String);
    for (int Caret = Length - 1, Digit = 1; Caret >= 0; -- Caret, Digit *= 10)
        {
        if (String[Caret] == '-') return Integer * -1;
        Integer += (String[Caret] - '0') * Digit;
        }

    return Integer;
    }
char *tochar(long int i, char *p)
{
    if (i / 10 == 0) {
        // No more digits.
        *p++ = i + '0';
        *p = '\0';
        return p;
    }
    p = tochar(i / 10, p);
    *p++ = i % 10 + '0';
    *p = '\0';
    return p;
}

// A Win32 app uses a WinMain function instead of main.

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, INT iCmdShow)
   {
   MSG msg;
   WNDCLASS wndclass = {0};

   wndclass.style = CS_HREDRAW | CS_VREDRAW;
   wndclass.lpfnWndProc = WndProc;
   wndclass.cbClsExtra = 0;
   wndclass.cbWndExtra = 0;
   wndclass.hInstance = hInstance;
   wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
   wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
   wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
   wndclass.lpszMenuName = NULL;
   wndclass.lpszClassName = "WinApp";

   if (!RegisterClass(&wndclass))
      {
      MessageBox(NULL,"Could not create window.", "Error", 0);
      return 0;
      }

   hMainWnd = CreateWindow("WinApp","Circle Calculator v 2.0 ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT, CW_USEDEFAULT, 400, 600, NULL, NULL, hInstance, NULL);

   //hLogoImage = (HBITMAP)LoadImage(hInstance, "logo.bmp", IMAGE_BITMAP, 52, 52, LR_LOADFROMFILE);

   ShowWindow(hMainWnd, iCmdShow);
   UpdateWindow(hMainWnd);

   while (GetMessage(&msg, NULL, 0, 0))
      {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      }

   return (int) msg.wParam;
   }

// This function processes the various messages for the window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
   {

	float r, O, P;
    switch (message)
      {
      case WM_COMMAND:
    	  switch(wParam)
    	  {
    	  case CALCULATE_BUTTON:
    		  MessageBeep(MB_OK);
              char radius[20],circumferenceD[10],circumference[10],areaD[10],area[10], units[3],Answer[100];
              GetWindowText(hEditRadius,radius,20);
              r=atof(radius);
              O = 2*PI*r;
              P = PI*r*r;

              //find decimal part of the radius and convert the radius from decimal to char
              float decimalr = 0;
              for (int Caret = 6, Digit = 10; Caret >= 0; -- Caret, Digit = Digit * 10) // Caret is use to set precision also
              decimalr = decimalr + (static_cast<long int>(r*Digit)%10)*pow(10,Caret-1);

              char radiusD[10];

              tochar(decimalr,radiusD);
              tochar(r,radius);

              //find and convert decimal part of the circumference of circle
              float decimal = 0;
              for (int Caret = 6, Digit = 10; Caret >= 0; -- Caret, Digit = Digit * 10) // Caret is use to set precision also
              decimal = decimal + (static_cast<long int>(O*Digit)%10)*pow(10,Caret-1);

              tochar(decimal,circumferenceD);
              tochar(O,circumference);

              //find and convert area of circle
//              int decimala1 = static_cast<int>(P*10)%10;
//              int decimala2 = static_cast<int>(P*100)%10;
//              int decimala3 = static_cast<int>(P*1000)%10;
//              int decimala4 = static_cast<int>(P*10000)%10;
//
//              int decimala = decimala1*1000+decimala2*100+decimala3*10+decimala4*1;

              float decimala = 0;
              for (int Caret = 6, Digit = 10; Caret >= 0; -- Caret, Digit = Digit * 10) // Caret is use to set precision also
              decimala = decimala + (static_cast<long int>(P*Digit)%10)*pow(10,Caret-1);

              tochar(decimala,areaD);
              tochar(P,area);

              strcpy(Answer,TEXT("\r Answer:"));
              strcat(Answer,TEXT("\r\n"));
              strcat(Answer,TEXT("r= "));
              strcat(Answer,radius);
              strcat(Answer,".");
              strcat(Answer,radiusD);
              GetWindowText(hEditUnits,units,3);
              strcat(Answer," ");
              strcat(Answer,units);
              strcat(Answer,TEXT(";\r\n"));
              strcat(Answer,"O= ");
              strcat(Answer,circumference);
              strcat(Answer,".");
              strcat(Answer,circumferenceD);
              strcat(Answer," ");
              strcat(Answer,units);
              strcat(Answer,TEXT(";\r\n"));
              strcat(Answer,"P= ");
              strcat(Answer,area);
              strcat(Answer,".");
              strcat(Answer,areaD);
              strcat(Answer," ");
              strcat(Answer,units);
              strcat(Answer,TEXT(";\r\n"));
              SetWindowTextA(hEditAnswer,Answer);
    		  break;
    	  }
    	  return 0;
          break;
      case WM_CREATE:
    	  loadImages();
    	  AddControls(hWnd);
    	  return 0;
    	  break;
      case WM_DESTROY:
         PostQuitMessage(0);
         return 0;
      }
   return DefWindowProc(hWnd, message, wParam, lParam);
   }

void AddControls(HWND hWnd)
{
   // text label and text input for radius
   CreateWindow("static", "r= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);
   hEditRadius = CreateWindow("edit","0", WS_VISIBLE | WS_CHILD | SS_CENTER,
		   102, 152, 248, 25, hWnd, NULL, NULL, NULL);

   // text label and combobox for units
   CreateWindow("static", "Units*", WS_VISIBLE | WS_CHILD | SS_CENTER, 102, 204, 100, 25, hWnd, NULL, NULL, NULL);
   hEditUnits = CreateWindow(WC_COMBOBOX, TEXT(""), CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
          						   202, 204, 100, 150, hWnd, (HMENU) NULL, HINSTANCE(NULL),0);
                 SendMessage(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 0, (LPARAM) TEXT("cm"));
              	 SendMessage(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 1, (LPARAM) TEXT("mm"));
              	 SendMessage(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) TEXT("m"));
              	 SendMessage(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) TEXT("in"));
              	 SendMessage(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) TEXT("yd"));
              	 SendMessage(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) TEXT("ft"));

              	// SEND THE CB_SETCURSEL MESSAGE TO DISPLAY AN INITIAL ITEM IN SELECTION FIELD
              	 SendMessage(hEditUnits, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);

   hEditAnswer = CreateWindow("edit", TEXT("\r Answer:\r\n r= 0 cm;\r\n O= 0 cm;\r\n P= 0 cm;\r\n"), WS_VISIBLE | WS_CHILD | ES_LEFT | ES_MULTILINE ,
		   50, 308, 300, 100, hWnd, NULL, NULL, NULL);

   hCalculateButton= CreateWindow("button","Calculate", WS_VISIBLE | WS_CHILD | BS_BITMAP,
		   250, 240, 100, 50, hWnd, (HMENU)CALCULATE_BUTTON, NULL, NULL);
   SendMessage(hCalculateButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hStartImage);

   hLogo = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
   	  5, 480, 340, 60, hWnd, NULL, NULL, NULL);
   SendMessage(hLogo,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

   hProjectSponsor = CreateWindow("static", "Copyright Znavstveni", WS_VISIBLE | WS_CHILD | WS_EX_NOACTIVATE | SS_CENTER, 80, 495, 160, 35, hWnd, NULL, NULL, NULL);



}

void loadImages()
{
	hLogoImage = (HBITMAP)LoadImage(NULL, "logo_bs.bmp", IMAGE_BITMAP, 340, 60, LR_LOADFROMFILE);
	hRestartImage = (HBITMAP)LoadImage(NULL, "reset-button.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE);
    hStartImage =  (HBITMAP)LoadImage(NULL,"start-button.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE);
}

