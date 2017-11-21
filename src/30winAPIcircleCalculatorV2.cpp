/* Filename:  30winAPIcircleCalculatorV2.cpp

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
                  Text combobox for units cm, mm, m, in, yd and ft
                  Restart button for clearing content of text input with loaded images restart button and system loaded sound OK
                  Start button for calculation based on given r with loaded images start button and system loaded sound OK
                  Text input for screen answer for calculation after use given parameters
                  Static logo of the project sponsor with load bmp picture and static title of copyright logo

// Learn terms : 1. windows.h, commctrl.h
                 2. WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
                 3. CreateWindow(lpszClassName,lpszTitleName,TypeofWindow,startXposition,startYposition,weight,height,HWND,HMENU,HINSTANCE,NULL)
                 4. WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam))
                 5. GetMessage(&msg, NULL, 0, 0)
                 6. HWND
                 7. WNDCLASS (attributes hbrBackground,hCursor,hInstance,lpszClassName,lpszClassName)
                 9. RegisterClass(&WNDCLASS)
                 10. user inline function stringLength (char *String), stringToInt (char *String), char *tochar (long int i, char *p)
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
#include <w32api.h>
#include <wingdi.h>

#define CLEAR_BUTTON 0
#define CALCULATE_BUTTON 1
#define IDC_CALCULATION 2

#define PI 3.141592 // Precision is set on 6 decimal places

// Global handler:
HWND hMainWnd,hEditCalculations,hEditRadius,hStaticRadius,hEditArea,hStaticArea,hEditCircumference,hStaticCircumference,
     hEditUnits,hClearButton,hCalculateButton,hEditAnswer, hLogo, hProjectSponsor;
HBITMAP hLogoImage, hRestartImage, hStartImage;
HICON hWinIcon;
HFONT hFont;

// Function prototype:
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
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
void printAnswer(HWND hwnd, char calculations[25], char radiusD[10], char radius[20],char areaD[10], char area[20],
		char circumferenceD[10],char circumference[10], char units[3], char Answer[100]);

// A Win32 application uses a WinMain function instead of main if use int main function, only main function will be executed

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, INT iCmdShow)
   {
   MSG msg;
   WNDCLASS wndclass = {0};

   wndclass.style = CS_HREDRAW | CS_VREDRAW | DS_SETFONT;
   wndclass.lpfnWndProc = WndProc;
   wndclass.cbClsExtra = 0;
   wndclass.cbWndExtra = 0;
   wndclass.hInstance = hInstance;
   wndclass.hIcon = (HICON)LoadImage(NULL,TEXT("title.ico"), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
   wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
   wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
   wndclass.lpszMenuName = NULL;
   wndclass.lpszClassName = "WinApp";

   if (!RegisterClass(&wndclass))
      {
      MessageBox(NULL,"Could not create window.", "Error", 0);
      return 0;
      }

   hMainWnd = CreateWindow(TEXT("WinApp"),TEXT("Circle Calculator v 2.0 "), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT, CW_USEDEFAULT, 400, 600, NULL, NULL, hInstance, NULL);

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
//    case WM_PAINT:
//          HDC     hDC;
//          PAINTSTRUCT ps;
//          hDC = BeginPaint(hWnd, &ps);
//
//                                    // Paint the line
//                                       MoveToEx(hDC, 0, 0, NULL);
//                                       LineTo(hDC, 50, 50);
//
//               EndPaint(hWnd, &ps);
//               return 0;
    case WM_COMMAND:
    
    	switch((wParam))
                	  {
                	  case IDC_CALCULATION:
                          if ((wParam) == CBN_SELENDOK)
                          {
                              MessageBeep(MB_OK);
                              MessageBox(hWnd,"Test","OK",MB_OK);
                          }
                          break;
                	  case CLEAR_BUTTON:
                	  {
                		 MessageBeep(MB_OK);
                		 SetWindowText(hEditRadius, TEXT("0"));
                		 SendMessage(hEditCalculations, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);
                		 SendMessage(hEditUnits, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);
                		 SetWindowText(hEditAnswer, TEXT("\r Answer:\r\n r= 0.0 cm;\r\n O= 0.0 cm;\r\n P= 0.0 cm2;\r\n"));
                		 break;
                	  }
                	  case CALCULATE_BUTTON:
                		  {
                		  MessageBeep(MB_OK);
                          int val;
                          char calculations[25],radius[20],area[20],circumferenceD[10],circumference[10],areaD[10],units[3], Answer[100];
                          GetWindowText(hEditCalculations,calculations,25);
                          if(strcmp(calculations,"")==0)
                                            	    {
                                            	    	val = MessageBox(hWnd,"You did not enter anything in field of the calculations!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
                                            	    	switch(val)
                                            	    	{
                                            	    	case IDABORT:
                                            	    		DestroyWindow(hWnd);
                                            	    		break;
                                            	    	case IDRETRY:
                                            	    		return 0;
                                            	    	case IDIGNORE:
                                            	    		break;
                                            	    	}
                                            	    	break;
                                            	    }
                          if(strcmp(calculations,"Find O and P | Given r")==0)
                          {
                        	                                                  ShowWindow(hStaticRadius, SW_NORMAL);
                        	                                                  ShowWindow(hEditRadius, SW_NORMAL);
                        	              	                            	  EnableWindow(hEditRadius,true);
                        	              	                            	  ShowWindow(hStaticArea,SW_HIDE);
                        	              	                            	  ShowWindow(hEditArea, SW_HIDE);
                        	              	                            	  EnableWindow(hEditArea,false);
                        	              	                            	  ShowWindow(hStaticCircumference,SW_HIDE);
                        	              	                            	  ShowWindow(hEditCircumference, SW_HIDE);
                        	              	                            	  EnableWindow(hEditCircumference,false);
                        	  GetWindowText(hEditRadius,radius,20);
            				  if(strcmp(radius,"")==0 )
            							{
            								val = MessageBox(hWnd,"You did not enter anything in field of the radius!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
            								switch(val)
            								{
            								case IDABORT:
            									DestroyWindow(hWnd);
            									break;
            								case IDRETRY:
            									return 0;
            								case IDIGNORE:
            									break;
            								}
            								break;
            							}

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

            				  printAnswer(hEditAnswer,calculations,radiusD,radius,areaD,area,circumferenceD,circumference,units,Answer);
            				  break;
            				  }

                          if(strcmp(calculations,"Find O and r | Given P")==0)
                             {
                        	                                  ShowWindow(hStaticRadius, SW_HIDE);
                        	                                  ShowWindow(hEditRadius, SW_HIDE);
                        	                            	  EnableWindow(hEditRadius,false);
                        	                            	  ShowWindow(hStaticArea,SW_NORMAL);
                        	                            	  ShowWindow(hEditArea, SW_NORMAL);
                        	                            	  EnableWindow(hEditArea,true);
                        	                            	  ShowWindow(hStaticCircumference,SW_HIDE);
                        	                            	  ShowWindow(hEditCircumference, SW_HIDE);
                        	                            	  EnableWindow(hEditCircumference,false);
                        	  GetWindowText(hEditArea,area,20);
                        	  if(strcmp(area,"")==0 )
                        		{
                        		val = MessageBox(hWnd,"You did not enter anything in field of the area!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
                        			switch(val)
                        				{
                        				 case IDABORT:
                        				 DestroyWindow(hWnd);
                        				 	 break;
                        				case IDRETRY:
                        					return 0;
                        				case IDIGNORE:
                        					break;
                        				}
                        			break;
                        		}

                        		P=atof(area);
                        		r = sqrt(P/PI);
                        		O = 2*PI*r;

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
                        		float decimala = 0;
                        		for (int Caret = 6, Digit = 10; Caret >= 0; -- Caret, Digit = Digit * 10) // Caret is use to set precision also
                        		decimala = decimala + (static_cast<long int>(P*Digit)%10)*pow(10,Caret-1);

                        		tochar(decimala,areaD);
                        		tochar(P,area);
                        		printAnswer(hEditAnswer,calculations,radiusD,radius,areaD,area,circumferenceD,circumference,units,Answer);
                               break;
                		   }
                          if(strcmp(calculations,"Find r and P | Given O")==0)
                                           {
                        	                                  ShowWindow(hStaticRadius, SW_HIDE);
                        	                                  ShowWindow(hEditRadius, SW_HIDE);
                        	                            	  EnableWindow(hEditRadius,false);
                        	                            	  ShowWindow(hStaticArea,SW_HIDE);
                        	                            	  ShowWindow(hEditArea, SW_HIDE);
                        	                            	  EnableWindow(hEditArea,false);
                        	                            	  ShowWindow(hStaticCircumference,SW_NORMAL);
                        	                            	  ShowWindow(hEditCircumference, SW_NORMAL);
                        	                            	  EnableWindow(hEditCircumference,true);
                                      	  GetWindowText(hEditCircumference,circumference,20);
                                      	  if(strcmp(circumference,"")==0 )
                                      		{
                                      		val = MessageBox(hWnd,"You did not enter anything in field of the circumference!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
                                      			switch(val)
                                      				{
                                      				 case IDABORT:
                                      				 DestroyWindow(hWnd);
                                      				 	 break;
                                      				case IDRETRY:
                                      					return 0;
                                      				case IDIGNORE:
                                      					break;
                                      				}
                                      			break;
                                      		}

                                      		O=atof(circumference);
                                      		r = O /(2*PI);
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

                                      		float decimala = 0;
                                      		for (int Caret = 6, Digit = 10; Caret >= 0; -- Caret, Digit = Digit * 10) // Caret is use to set precision also
                                      		decimala = decimala + (static_cast<long int>(P*Digit)%10)*pow(10,Caret-1);

                                      		tochar(decimala,areaD);
                                      		tochar(P,area);
                                      		printAnswer(hEditAnswer,calculations,radiusD,radius,areaD,area,circumferenceD,circumference,units,Answer);
                                            break;
                              		   }
                		  return 0;
                		  break;
                		}
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

	// Text label and combobox Choose a Calculation
	CreateWindow("static", "Choose a Calculation", WS_VISIBLE | WS_CHILD |SS_CENTER, 50, 50, 300, 25, hWnd, NULL, NULL, NULL);
	hEditCalculations = CreateWindow(WC_COMBOBOX, TEXT(""), CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
	    	    	    						      50, 102, 298, 100, hWnd, (HMENU)IDC_CALCULATION, NULL,NULL);
	    	    	         SendMessage(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 0, (LPARAM) TEXT("Find O and P | Given r"));
	    	    	    	 SendMessage(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 1, (LPARAM) TEXT("Find O and r | Given P"));
	    	    	    	 SendMessage(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) TEXT("Find r and P | Given O"));
	    	    	    	// SEND THE CB_SETCURSEL MESSAGE TO DISPLAY AN INITIAL ITEM IN SELECTION FIELD
	    	    	    	 SendMessage(hEditCalculations, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);
	// Text label and text input for radius, area, circumference
	hStaticRadius=CreateWindow("static", "r= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);
	hEditRadius = CreateWindow("edit","0", WS_VISIBLE | WS_CHILD | SS_CENTER,
	    	102, 152, 248, 25, hWnd, NULL, NULL, NULL);
	// area
	hStaticArea=CreateWindow("static", "P= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);
	ShowWindow(hStaticArea, SW_HIDE);
    hEditArea = CreateWindow("edit","0", WS_VISIBLE | WS_CHILD | SS_CENTER,
		    102, 152, 248, 25, hWnd, NULL, NULL, NULL);
    ShowWindow(hEditArea, SW_HIDE);
    EnableWindow(hEditArea,false);
    //circumference
    hStaticCircumference=CreateWindow("static", "O= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);
    ShowWindow(hStaticCircumference, SW_HIDE);
    hEditCircumference = CreateWindow("edit","0", WS_VISIBLE | WS_CHILD | SS_CENTER,
    	   102, 152, 248, 25, hWnd, NULL, NULL, NULL);
    ShowWindow(hEditCircumference, SW_HIDE);
    EnableWindow(hEditCircumference,false);

   // Text label and combobox for units
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

   // Restart button for clearing content of text input with loaded images restart button and system loaded sound OK
   hClearButton = CreateWindow(TEXT("button"),NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,
		   50, 240, 100, 50, hWnd,(HMENU) CLEAR_BUTTON, NULL, NULL);
   SendMessage(hClearButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hRestartImage);

   // Start button for calculation based on given r with loaded images start button and system loaded sound OK
   hCalculateButton= CreateWindow(TEXT("button"),"Calculate", WS_VISIBLE | WS_CHILD | BS_BITMAP,
		   250, 240, 100, 50, hWnd, (HMENU)CALCULATE_BUTTON, NULL, NULL);
   SendMessage(hCalculateButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hStartImage);

   // Text input for screen answer for calculation after use given parameters
   hEditAnswer = CreateWindow(TEXT("edit"), TEXT("\r Answer:\r\n r= 0.0 cm;\r\n O= 0.0 cm;\r\n P= 0.0 cm2;\r\n"), WS_VISIBLE | WS_CHILD | ES_LEFT | ES_MULTILINE ,
		   50, 308, 300, 100, hWnd, NULL, NULL, NULL);

  // Static logo of the project sponsor with load bmp picture and static title of copyright logo
   hLogo = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
   	  5, 480, 340, 60, hWnd, NULL, NULL, NULL);
   SendMessage(hLogo,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

   hProjectSponsor = CreateWindow("static", "Copyright Znavstveni", WS_VISIBLE | WS_CHILD | WS_EX_NOACTIVATE | SS_LEFT | DS_SETFONT,
		   80, 495, 160, 35, hWnd, NULL, NULL, NULL);
//   hFont=CreateFontA(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
//   		   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
//   SendMessage (hProjectSponsor, WM_SETFONT, WPARAM (hFont), TRUE);
}

void loadImages()
{
	hLogoImage = (HBITMAP)LoadImage(NULL, "logo_bs.bmp", IMAGE_BITMAP, 340, 60, LR_LOADFROMFILE);
	hRestartImage = (HBITMAP)LoadImage(NULL, "reset-button.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE);
    hStartImage =  (HBITMAP)LoadImage(NULL,"start-button.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE);
}

void printAnswer(HWND hwnd, char calculations[25], char radiusD[10], char radius[20],char areaD[10], char area[20],
		char circumferenceD[10],char circumference[10], char units[3], char Answer[100])
{
	 strcpy(Answer,TEXT("\r Answer:"));
					  strcat(Answer,TEXT("\r\n"));
					  strcat(Answer,TEXT(" r= "));
					  strcat(Answer,radius);
					  strcat(Answer,".");
					  strcat(Answer,radiusD);
					  GetWindowText(hEditUnits,units,3);
					  strcat(Answer," ");
					  strcat(Answer,units);
					  strcat(Answer,TEXT(";\r\n"));
					  strcat(Answer," O= ");
					  strcat(Answer,circumference);
					  strcat(Answer,".");
					  strcat(Answer,circumferenceD);
					  strcat(Answer," ");
					  strcat(Answer,units);
					  strcat(Answer,TEXT(";\r\n"));
					  strcat(Answer," P= ");
					  strcat(Answer,area);
					  strcat(Answer,".");
					  strcat(Answer,areaD);
					  strcat(Answer," ");
					  strcat(Answer,units);
					  strcat(Answer,TEXT("2;\r\n"));
	SetWindowTextA(hwnd,Answer);

}
