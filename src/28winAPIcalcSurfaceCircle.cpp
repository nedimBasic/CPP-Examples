// Name        : 28winAPIcalcSurfaceCircle.cpp
// Author      : Nedim Basic
// Version     : 1.0
// Copyright   : All rights are reserved
// Task        : Made program with follow requirements:
//               Windows with title 'Circle Calculator v 1.0'
//               Text label r side by side of text input r
//               Text input r
//               Text label Units* side by side of text input Units
//               Text input for Units m, cm, mm, in, yd, ft,
// Learn terms : 1. windows.h
//               2. WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//               3. CreateWindowW()
//               4. WndProc()
//               5. GetMessage()
//               6. HWND
//               7. WNDCLASSW (attributes hbrBackground,hCursor,hInstance,lpszClassName,lpszClassName)
//               9. RegisterClassW()
//               10. AddMenus() HMENU,CreateMenu(),SetMenu(hWnd,hMenu), AppendMenu()
//               11. AddControls() HMENU,CreateMenu(), SetMenu(hWnd,hMenu); AppendMenu()
//               12. atof(string) function for convert string into double
//============================================================================
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <wingdi.h> // Library for graphics
#include <commctrl.h> // Library for WM_COMBOBOX

#define FILE_MENU_OPEN 1
#define FILE_MENU_PRINT 2
#define FILE_MENU_EXIT 3
#define OPEN_MENU_STANDARD 4
#define OPEN_MENU_SCIENTIFIC 5
#define HELP_MENU_WELCOME 6
#define HELP_MENU_ABOUT 7
#define CLEAR_BUTTON 8
#define CALCULATE_BUTTON 9
#define PRINT_BUTTON 10
#define CANCEL_PRINT_BUTTON 11
#define PI 3.1415

#define IDI_ICON_TITLE 12



// Step 4: Prototype of all functions
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);
void loadImages();
LRESULT CALLBACK PrintProcedure(HWND, UINT, WPARAM, LPARAM);
void registerDialogPrintClass(HINSTANCE);
void displayDialogPrint(HWND);
void CalculatorPaint();

HWND  hMainWindow, hDlgP, hEditCalculations, hEditRadius, hEditUnits, hClearButton, hCalculateButton, hEditAnswer,
      hProjectSponsor, hLogo, hPrint, hCancel, hSelectPrinter, hNumberCopies;
HMENU hMenu;
HBITMAP hLogoImage, hRestartImage, hStartImage;
HICON hIcon;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc = {0};

    //Step 1: Registering the Window Class
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = L"circleCalculatorWindowClass";
    wc.lpfnWndProc = WndProc;
    wc.hIcon = hIcon;
    hIcon = (HICON)LoadImage(hInstance, "title.ico",IMAGE_ICON,
        		     10,
                     10, 0);
    if(!RegisterClassW(&wc))
    	return -1;

    registerDialogPrintClass(hInstance);

    // Step 2: Creating the Window
    hMainWindow = CreateWindowW(L"circleCalculatorWindowClass", L"Circle Calculator v 1.0", WS_OVERLAPPEDWINDOW| WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 400, 600,
    					NULL, (HMENU) IDI_ICON_TITLE, NULL, NULL);

   // SendMessageW(hMainWindow, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);


    hLogoImage = (HBITMAP)LoadImage(hInstance, "logo.bmp", IMAGE_BITMAP, 52, 52, LR_LOADFROMFILE);
    hLogo = CreateWindowW(L"static",NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 5, 475, 52, 52, hMainWindow, NULL, NULL, NULL);
    SendMessageW(hLogo,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

    // Step 3: The Message Loop
    MSG Msg = {0};
    while(GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}

	//Step 5:Implementation of all functions
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{   int val;
    switch(msg)
    {
    case WM_COMMAND:
    	switch(wParam)
    	{
    	case FILE_MENU_OPEN:
    		MessageBeep(MB_ICONERROR); // Does not hear any sound
    		break;
    	case FILE_MENU_PRINT:
    		displayDialogPrint(hWnd);
    	    MessageBeep(MB_ICONERROR);
    	    break;
    	case FILE_MENU_EXIT:
    		val = MessageBoxW(hWnd,L"Are you sure?", L"Wait!", MB_YESNOCANCEL | MB_ICONEXCLAMATION);
    		switch (val)
    		{
    		case IDYES:
    			DestroyWindow(hWnd);
    			break;
    		default:
    			return 0;
    		}
    		break;
    	case OPEN_MENU_STANDARD:
    		MessageBeep(MB_ICONERROR);
    		char unit1[100], text1[100];
    		strcpy(text1,"Circle Calculator v1.0 | Standard (" );
    		    	    GetWindowText(hEditUnits,unit1, 100);
    		    	    strcat (text1,unit1);
    		    	    strcat (text1,")");
    		    	    SetWindowText(hWnd,text1);
    		    	    break;
    	case OPEN_MENU_SCIENTIFIC:
    	    MessageBeep(MB_ICONERROR);
    	    char unit2[100],text2[100];
    	    strcpy(text2,"Circle Calculator v1.0 | Scientific (" );
    	    			GetWindowText(hEditUnits,unit2, 100);
    	    			strcat (text2,unit2);
    	    			strcat (text2,")");
    	    			SetWindowText(hWnd,text2);
    	    			break;
    	case HELP_MENU_WELCOME:
    	    MessageBeep(MB_OK);
    	    break;
    	case HELP_MENU_ABOUT:
    	    MessageBeep(MB_OK);
    	    break;

    	    // action for buttons
    	case CLEAR_BUTTON:
    	    MessageBeep(MB_OK);
    	    SetWindowText(hEditRadius, TEXT("0"));
    	    SetWindowText(hEditUnits, TEXT ("cm"));
    	    SetWindowText(hEditAnswer, TEXT("Answer: r= 0 cm; O= 0 cm; P= 0 cm;"));
    	    break;
    	case CALCULATE_BUTTON:
    	    MessageBeep(MB_OK);
    	    char rC[10], PC[5], OC[5],Units[3], Answer[50];
    	    GetWindowText(hEditRadius,rC,10);
    	    GetWindowText(hEditUnits,Units,3);
    	    if(strcmp(rC,"")==0 || strcmp(Units,"")==0)
    	    {
    	    	val = MessageBoxW(hWnd,L"You did not enter anything !", NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);
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
    	    strcpy(Answer,"Answer: r= ");
    	    strcat(Answer, rC);
    	    strcat(Answer, " ");
    	    strcat(Answer, Units);
    	    strcat(Answer, "; O= ");

    	    int r, O, P;
    	    	r=0;
    	    	O=0;
    	    	P=0;

    	    	r=atof(rC);
    	    	O = 2*PI*r;
    	    // convert O to char OC to_string() function

    	    strcat(Answer, OC);
    	    strcat(Answer, " ");
    	    strcat(Answer, Units);
    	    strcat(Answer, "; P= ");
    	    P = PI*r*r;

    	    // covert P to char PC

    	    strcat(Answer, PC);
    	    strcat(Answer, " ");
    	    strcat(Answer, Units);
    	    strcat(Answer, ";");

    	    SetWindowText(hEditAnswer,Answer);
    	    break;

    	}
    	break;
    case WM_CREATE:
    	 loadImages();
    	 AddControls(hWnd);
    	 AddMenus(hWnd);
    	break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProcW(hWnd, msg, wParam, lParam);
    }
    return 0;
}
	//Step 6:Implementation of menu function
void AddMenus(HWND hWnd)

{
	hMenu = CreateMenu();
	HMENU  hFileMenu = CreateMenu();
	HMENU  hHelpMenu = CreateMenu();
	HMENU  hSubOpenMenu = CreateMenu();

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");

	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubOpenMenu, "Open");
	AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_PRINT, "Print");
	AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");
		AppendMenu(hSubOpenMenu, MF_STRING, OPEN_MENU_STANDARD, "Standard");
		AppendMenu(hSubOpenMenu, MF_STRING, OPEN_MENU_SCIENTIFIC, "Scientific");

	AppendMenu(hHelpMenu, MF_STRING, HELP_MENU_WELCOME, "Welcome");
	AppendMenu(hHelpMenu, MF_STRING, HELP_MENU_ABOUT, "About");

	SetMenu(hWnd,hMenu);

}

void AddControls(HWND hWnd)

{
	CreateWindowW(L"static", L"Choose a Calculation", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 50, 300, 25, hWnd, NULL, NULL, NULL);
	hEditCalculations = CreateWindowW(WC_COMBOBOXW, L"", CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD | WS_BORDER | TA_CENTER,
	    						      50, 102, 298, 100, hWnd, (HMENU) NULL, HINSTANCE(NULL),0);
	         SendMessageW(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 0, (LPARAM) L"Find O and P | Given r");
	    	 SendMessageW(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 1, (LPARAM) L"Find O and r | Given P");
	    	 SendMessageW(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) L"Find r and P | Given O");
	    	// SEND THE CB_SETCURSEL MESSAGE TO DISPLAY AN INITIAL ITEM IN SELECTION FIELD
	    	 SendMessageW(hEditCalculations, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);



    CreateWindowW(L"static", L"r= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);
    hEditRadius = CreateWindowW(L"edit", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER, 102, 152, 248, 25, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Units*", WS_VISIBLE | WS_CHILD | SS_CENTER, 102, 204, 100, 25, hWnd, NULL, NULL, NULL);
    hEditUnits = CreateWindowW(WC_COMBOBOXW, L"", CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
    						   202, 204, 100, 150, hWnd, (HMENU) NULL, HINSTANCE(NULL),0);
             SendMessageW(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 0, (LPARAM) L"cm");
        	 SendMessageW(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 1, (LPARAM) L"mm");
        	 SendMessageW(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) L"m");
        	 SendMessageW(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) L"in");
        	 SendMessageW(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) L"yd");
        	 SendMessageW(hEditUnits,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) L"ft");

        	// SEND THE CB_SETCURSEL MESSAGE TO DISPLAY AN INITIAL ITEM IN SELECTION FIELD
        	 SendMessageW(hEditUnits, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);


    hClearButton = CreateWindowW(L"button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP, 50, 240, 100, 50, hWnd,(HMENU)CLEAR_BUTTON, NULL, NULL);
    SendMessageW(hClearButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hRestartImage);

    hCalculateButton= CreateWindowW(L"button", L"Calculate", WS_VISIBLE | WS_CHILD | BS_BITMAP, 250, 240, 100, 50, hWnd, (HMENU)CALCULATE_BUTTON, NULL, NULL);
    SendMessageW(hCalculateButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hStartImage);

    hEditAnswer = CreateWindowW(L"edit", L"Answer: r= 0 cm; O= 0 cm; P= 0 cm;", WS_VISIBLE | WS_CHILD | ES_MULTILINE, 50, 308, 300, 100, hWnd, NULL, NULL, NULL);

    hProjectSponsor = CreateWindowW(L"static", L"Federalno Ministarstvo Obrazovanja i Nauke", WS_VISIBLE | WS_CHILD | WS_EX_NOACTIVATE | SS_CENTER, 54, 475, 300, 27, hWnd, NULL, NULL, NULL);
    //hLogo = CreateWindowW(L"static",NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | WS_BORDER, 5, 475, 52, 52, hMainWindow, NULL, NULL, NULL);
    //SendMessageW(hLogo,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

	CreateWindowW(L"static", L"Copyright Trusted Nedim Basic Store App", WS_VISIBLE | WS_CHILD | WS_EX_NOACTIVATE | SS_CENTER, 54, 502, 300, 27, hWnd, NULL, NULL, NULL);
}

void loadImages()
{
	//hLogoImage = (HBITMAP)LoadImage(NULL, "logo.bmp", IMAGE_BITMAP, 52, 52, LR_LOADFROMFILE);
	hRestartImage = (HBITMAP)LoadImageW(NULL, L"reset-button.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE);
	hStartImage =  (HBITMAP)LoadImageW(NULL, L"start-button.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE);
}

LRESULT CALLBACK PrintProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg)
	{
	 case WM_COMMAND:
		 switch(wp)
		 {
	      case CANCEL_PRINT_BUTTON:
	    	 EnableWindow(hMainWindow,true);
	    	 DestroyWindow(hWnd);
	    	 break;
	      case PRINT_BUTTON:
	      	   MessageBeep(MB_OK);
	      	   break;
	      default:
	    	  return DefWindowProcW(hWnd, msg, wp, lp);
		 }
		 break;
	 case WM_CLOSE:
		EnableWindow(hMainWindow,true);
		DestroyWindow(hWnd);
		break;
	  default:
	    return DefWindowProcW(hWnd, msg, wp, lp);
	  }
	    return 0;
}
 void registerDialogPrintClass(HINSTANCE hInstance)
 {
	 WNDCLASSW dialogprint= {0};

	     //Step 1: Registering the Dialog Class
	 dialogprint.hbrBackground = (HBRUSH)COLOR_WINDOW;
	 dialogprint.hCursor = LoadCursor(NULL,IDC_CROSS);
	 dialogprint.hInstance = hInstance;
	 dialogprint.lpszClassName = L"printDialogPrintClass";
	 dialogprint.lpfnWndProc = PrintProcedure;

	 RegisterClassW(&dialogprint);
 }

 void displayDialogPrint(HWND hWnd)
 {
	 // Step 2: Creating the Dialog Print Window
		    hDlgP = CreateWindowW(L"printDialogPrintClass", L"Print Circle Calculator v 1.0", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 400, 400, 400, 250,
		    		 hWnd, NULL, NULL, NULL);

		    hPrint = CreateWindowW(L"button", L"Print",WS_VISIBLE | WS_CHILD | SS_CENTER, 217, 150, 70, 25, hDlgP, (HMENU) PRINT_BUTTON, NULL, NULL);
		    hCancel = CreateWindowW(L"button", L"Cancel",WS_VISIBLE | WS_CHILD | SS_CENTER, 289, 150, 70, 25, hDlgP, (HMENU) CANCEL_PRINT_BUTTON, NULL, NULL);

		    CreateWindowW(L"Static", L"Select Printer", WS_VISIBLE | WS_CHILD | SS_CENTER | WS_EX_NOACTIVATE, 15, 25, 100, 25, hDlgP, NULL, NULL, NULL);
		    hSelectPrinter =  CreateWindowW(L"Edit", L"PDF", WS_VISIBLE | WS_CHILD | SS_CENTER, 117, 25, 250, 50, hDlgP, NULL, NULL, NULL);

		    CreateWindowW(L"Static", L"Number of copies", WS_VISIBLE | WS_CHILD | SS_CENTER | WS_EX_NOACTIVATE, 15, 108, 200, 25, hDlgP, NULL, NULL, NULL);
		    hNumberCopies =  CreateWindowW(WC_COMBOBOXW, L"", CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
		    		217, 108, 50, 250, hDlgP, NULL, NULL, NULL);
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 0, (LPARAM) L"1");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 1, (LPARAM) L"2");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 2, (LPARAM) L"3");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 3, (LPARAM) L"4");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 4, (LPARAM) L"5");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 5, (LPARAM) L"6");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 6, (LPARAM) L"7");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 7, (LPARAM) L"8");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 8, (LPARAM) L"9");
		    SendMessageW(hNumberCopies,(UINT) CB_ADDSTRING,(WPARAM) 9, (LPARAM) L"10");

		   // SEND THE CB_SETCURSEL MESSAGE TO DISPLAY AN INITIAL ITEM IN SELECTION FIELD
		   SendMessageW(hNumberCopies, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);
		   EnableWindow(hWnd,false);
 }

 void CalculatorPaint()
 {

 }
