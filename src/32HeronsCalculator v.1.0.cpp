/*
 *  32HeronsCalculator v.1.0.cpp
 *
 *  Created on: Nov 30, 2017.
 *      Author: nedim.basic
 *
   Project: Open access to Knowledge

   Project Sponsor: Academic Portal

   Version: 1.0

   Copyright: All rights are reserved
   //============================================================================
   //	Task        :  Append program  of a mathematicks calculator with follow requirements:
					   Calculates the area of a triangle given three sides.
					   Triangle by Heron's formula.
   //   Learn terms :
                      char *strcpy (char *, const char *) - copy string into string
                      char *strcat (char *, const char *) - concate string with string
                      int strcmp (const char *, const char *) - compare two strings
                      double atof (const char *) - covert string into double
                      extern long double __cdecl modfl (long double, long double*) - Break into fractional and integral parts
   //============================================================================
 */

#include <windows.h>
#include <cmath>      //Include because of using   pow(long double __x, long double __y), sqrt(long double __x) functions
#include <w32api.h>
#include <wingdi.h>
#include <commctrl.h> //Include becasue of using WM_COMBOBOX
#include <string.h> //Include because of using char *strcpy (char *, const char *), char *strcat (char *, const char *),int strcmp (const char *, const char *) functions
#include <stdlib.h> //Include because of using atof (const char *) function
#include <string> //Include because of using to_string

#define BUTTON_CLEAR 10
#define BUTTON_EXECUTE 11

// Identifier for edit boxes
#define EDIT_SIDE_A 12
#define EDIT_SIDE_B 13
#define EDIT_SIDE_C 14
#define EDIT_UNITS 15
#define EDIT_AREA 16

// Global handler:
HWND hMainWnd,
     hTriangle,
	 hButtonExecute,hButtonClear,
	 hStaticSideA,hEditSideA,hStaticSideB,hEditSideB,hStaticSideC,hEditSideC,
     hStaticUnitsEn,hEditUnitsEn,
	 hStaticAreaS,hEditAreaS,
	 hAreaFormula,hSemiperimeterFormula,
	 hLogo,hProjectSponsor;
HBITMAP hLogoImage,hTriangleImage,hAreaForlumaImage,hSemiperimeterForlumaImage;
HMENU hMenu;

// Function prototype:
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void AddControls(HWND);
void loadImages();
char *tochar(long int i, char *p);

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
   //LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
   wndclass.hIcon = (HICON)LoadImage(NULL,TEXT("academic_logo_icon.ico"), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
   //wndclass.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);
   wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
   wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
   wndclass.lpszMenuName = NULL;
   wndclass.lpszClassName = "WinApp";

   if (!RegisterClass(&wndclass))
      {
      MessageBox(NULL,"Could not create window.","Error", 0);
      return 0;
      }

   hMainWnd = CreateWindow(TEXT("WinApp"),TEXT("Heron's Formula Calculator v.1.0 "), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT, CW_USEDEFAULT, 400, 620, NULL, NULL, hInstance, NULL);

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
    LRESULT result = 0;
    bool wasHandled = false;

    switch (message)
      {
   /* case WM_PAINT:
          HDC     hDC;
          PAINTSTRUCT ps;
          hDC = BeginPaint(hWnd, &ps);
                                    // Paint the line
                                       MoveToEx(hDC, 45, 25, NULL);
                                       LineTo(hDC, 45, 70);
                                       MoveToEx(hDC, 350, 25, NULL);
                                       LineTo(hDC, 350, 70);
                                       MoveToEx(hDC, 45, 25, NULL);
                                       LineTo(hDC, 350, 25);
                                       MoveToEx(hDC, 45, 70, NULL);
                                       LineTo(hDC, 350, 70);
               EndPaint(hWnd, &ps);
               return 0;
               break;*/
       case WM_COMMAND:
    	switch(LOWORD(wParam))
            {
                	  case BUTTON_CLEAR:
                	  {
                		 MessageBeep(MB_OK);
                		 SetWindowText(hEditSideA,"");
                		 SetWindowText(hEditSideB,"");
                		 SetWindowText(hEditSideC,"");
                		 SendMessage(hEditUnitsEn, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
                		 SetWindowText(hEditAreaS,"");
                	  }
                	  break;
                	  case BUTTON_EXECUTE:
                	  {
                		MessageBeep(MB_OK);
                		char sideA[60],sideB[60],sideC[60],areaD[8],areaI[60],units[3];
                		int val;
                		GetWindowText(hEditSideA,sideA,60);
                		GetWindowText(hEditSideB,sideB,60);
                		GetWindowText(hEditSideC,sideC,60);
                		// Validate empty input
                		if(strcmp(sideA,"")==0)
                		  {
                		    val = MessageBox(hWnd,"You did not enter anything in field of the side a!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
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
                         }
                		// Validate empty input sideB
                		 if(strcmp(sideB,"")==0)
                		   {
                		    val = MessageBox(hWnd,"You did not enter anything in field of the side b!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
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
                		   }
                		 // Validate empty input sideC
                		 if(strcmp(sideC,"")==0)
                		   {
                		     val = MessageBox(hWnd,"You did not enter anything in field of the side c!", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
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
                		    }

                		// Convert char into double
                		long double a,b,c,P,s;
                		a=atof(sideA);
						b=atof(sideB);
						c=atof(sideC);

						if (a+b > c && a+c > b && b+c > a)
						{
					    // Calculate area using Heron's formula.
						s=(a+b+c)/2;
						P=sqrt(s*(s-a)*(s-b)*(s-c));

						// How calcualte decimal part of float number
//						long int decimala = 0;
//					    for (long int Caret = 8, Digit = 10; Caret >= 0; -- Caret, Digit = Digit * 10) // Caret is use to set precision also
//					    decimala += (static_cast<long int>(P*Digit)%10)*pow(10,Caret-1);

						long double intpartP;
						long double decpartP;
						decpartP = modfl(P, &intpartP);

					    // Convert long int into char and set precision on 9 decimals
						decpartP=decpartP*pow(10,9);
						tochar(decpartP,areaD);
						tochar(P,areaI);

						// Put text into edit box for area
						char area[162];
						strcpy(area,areaI);
						strcat(area,TEXT("."));
						strcat(area,areaD);
						GetWindowText(hEditUnitsEn,units,3);
						strcat(area,TEXT(" "));
						strcat(area,units);
						strcat(area,TEXT("2"));

						// Message box only for testing phase
                		MessageBox(hWnd,area,"Test", MB_OK);

                		SetWindowText(hEditAreaS,area);
						}
						else SetWindowText(hEditAreaS,"Error");
                	  }
                	  break;
             }
    	wasHandled = true;
    	result=0;
    	break;
       case WM_CREATE:

    	  loadImages();
    	  AddControls(hWnd);
    	  wasHandled = true;
    	  result = 0;
       break;
       case WM_DISPLAYCHANGE:
                {
                    InvalidateRect(hWnd, NULL, FALSE);
                }
                wasHandled = true;
                result = 0;
                break;

            case WM_DESTROY:
                {
                    PostQuitMessage(0);
                }
                wasHandled = true;
                result = 1;
                break;
            }
        if (!wasHandled)
        {
            result = DefWindowProc(hWnd, message, wParam, lParam);
        }
    return result;
}

void AddControls(HWND hWnd)
{
	// Text label and combobox Choose a Calculation
	CreateWindow("static",TEXT("Calculates the area of \n a triangle given three sides"), WS_VISIBLE | WS_CHILD |SS_CENTER,
			50, 30, 300, 40, hWnd, NULL, NULL, NULL);

	// Static handler of picture of triangle with load bmp picture.
	hTriangle = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
					100, 80, 230, 170, hWnd, NULL, NULL, NULL);
	SendMessage(hTriangle,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hTriangleImage);

	// Static handler of the side a from the triangle.
	hStaticSideA = CreateWindow("static", TEXT("side a"), WS_VISIBLE | WS_CHILD | SS_CENTER,
						50, 252, 40, 20, hWnd, NULL, NULL, NULL);
	// Edit handler of the side a from the triangle.
	hEditSideA = CreateWindow("Edit", NULL, WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
							94, 252, 60, 20, hWnd, (HMENU) EDIT_SIDE_A, NULL, NULL);
	// Button handler of the button EXECUTE for calculate area of the triangle using Herons Formula
	hButtonExecute = CreateWindow("Button", TEXT("EXECUTE"), WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
								200, 252, 100, 20, hWnd, (HMENU) BUTTON_EXECUTE, NULL, NULL);

	// Static handler of the side b from the triangle.
	hStaticSideB = CreateWindow("static", TEXT("side b"), WS_VISIBLE | WS_CHILD | SS_CENTER,
							50, 280, 40, 20, hWnd, NULL, NULL, NULL);
	// Edit handler of the side b from the triangle.
	hEditSideB = CreateWindow("Edit", NULL, WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
								94, 280, 60, 20, hWnd, (HMENU) EDIT_SIDE_B, NULL, NULL);
	// Button handler of the button CLEAR all inputs of the triangle using Herons Formula
	hButtonExecute = CreateWindow("Button", TEXT("CLEAR"), WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
											200, 280, 100, 20, hWnd, (HMENU) BUTTON_CLEAR, NULL, NULL);

	// Static handler of the side a from the triangle.
	hStaticSideC = CreateWindow("static", TEXT("side c"), WS_VISIBLE | WS_CHILD | SS_CENTER,
								50, 306, 40, 20, hWnd, NULL, NULL, NULL);
	// Edit handler of the side c from the triangle.
	hEditSideC = CreateWindow("Edit", NULL, WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
									94, 306, 60, 20, hWnd, (HMENU) EDIT_SIDE_C, NULL, NULL);
	// Text label and combobox for units
	   hStaticUnitsEn = CreateWindow("static", "Units*", WS_VISIBLE | WS_CHILD | SS_CENTER, 200, 306, 100, 20, hWnd, NULL, NULL, NULL);
	   hEditUnitsEn = CreateWindow(WC_COMBOBOX, TEXT(""), CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD | WS_BORDER,
	          						   306, 306, 60, 200, hWnd, (HMENU) EDIT_UNITS, HINSTANCE(NULL),0);
	   // load the combobox with item list.
	   //Send a CB_ADDSTRING message to load each item
	   	char UnitsEn[6][12]=
	   	{
	   			TEXT("cm"),TEXT("mm"),TEXT("m"),TEXT("in"),TEXT("yd"),TEXT("ft")
	   	};
	   			char B[3];
	   			int  m = 0;
	   			memset(&B,0,sizeof(B));
	   				for (m = 0; m <= 5; m += 1)
	   					{
	   						strcpy(B,UnitsEn[m]);
	   						// Add string to combobox.
	   						SendMessage(hEditUnitsEn,(UINT) CB_ADDSTRING, (WPARAM) 0,(LPARAM) B);
	   					}
	   	// Send the CB_SETCURSEL message to display an initial item
	   	//  in the selection field
	   	SendMessage(hEditUnitsEn, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	// Create one line under Units*
	 CreateWindow("static", "---------------------------------------------------------------------------------------",
			     WS_VISIBLE | WS_CHILD | SS_CENTER | WS_EX_NOACTIVATE, 5, 328, 380, 10, hWnd, NULL, NULL, NULL);

	// Static handler of the Area P with is calculated from the triangle.
	 hStaticAreaS = CreateWindow("static", TEXT("area P"), WS_VISIBLE | WS_CHILD | SS_CENTER,
			                      94, 342, 60, 20, hWnd, NULL, NULL, NULL);
	// Edit handler of the side c from the triangle.
	 hEditAreaS = CreateWindow("Edit", NULL, WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
			                 200, 342, 162, 20, hWnd, (HMENU) EDIT_AREA, NULL, NULL);

	// Static handler of picture of Heron's Area formula with load bmp picture.
	 hAreaFormula = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
				80, 370, 260, 48, hWnd, NULL, NULL, NULL);
	 SendMessage(hAreaFormula,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hAreaForlumaImage);
	// Static handler of picture of Heron's Semiperimeter formula with load bmp picture.
	 hSemiperimeterFormula = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
			120, 436, 200, 48, hWnd, NULL, NULL, NULL);
	 SendMessage(hSemiperimeterFormula,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hSemiperimeterForlumaImage);

	// Static logo of the project sponsor with load bmp picture and static title of copyright logo
	 hLogo = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
			40, 504, 320, 60, hWnd, NULL, NULL, NULL);
     SendMessage(hLogo,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

     hProjectSponsor = CreateWindow("static", TEXT("Copyright©"), WS_VISIBLE | WS_CHILD | SS_LEFT | WS_EX_NOACTIVATE,
		   40, 484, 160, 20, hWnd, NULL, NULL, NULL);
}
void loadImages()
{
	hTriangleImage = (HBITMAP)LoadImage(NULL, "triangle_abc.bmp", IMAGE_BITMAP, 230, 170, LR_LOADFROMFILE);
	hAreaForlumaImage = (HBITMAP)LoadImage(NULL, "HeronsAreaFormula.bmp", IMAGE_BITMAP, 260, 48, LR_LOADFROMFILE);
	hSemiperimeterForlumaImage = (HBITMAP)LoadImage(NULL, "HeronsSemiperimeterFormula.bmp", IMAGE_BITMAP, 200, 48, LR_LOADFROMFILE);
	hLogoImage = (HBITMAP)LoadImage(NULL, "academic_logo_en.bmp", IMAGE_BITMAP, 320, 60, LR_LOADFROMFILE);
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
