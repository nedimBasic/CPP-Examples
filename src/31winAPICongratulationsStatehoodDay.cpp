/*
 * 31winAPICongratulationsStatehoodDay.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: nedim.basic
 *
   Project: Open access to Knowledge

   Project Sponsor: Academic Portal

   Version: 1.0

   Copyright: All rights are reserved
   //============================================================================
   //	Task        :  Append program with follow requirements:

					   Congratulations on Statehood Day
					   Sretan Dan Drzavnosti


   //   Learn terms : Unity of pro-Bosnian, anti-fascist forces
    *                 Probosanci, antifasisticke snage


   //============================================================================
 */
#include <windows.h>
#include <commctrl.h>
#include <w32api.h>
#include <wingdi.h>

#define CLEAR_BUTTON 10
#define CALCULATE_BUTTON 11
#define IDC_CALCULATION 12
#define IDC_UNITS 13

#define FILE_MENU_OPEN 14
#define FILE_MENU_PRINT 15
#define FILE_MENU_EXIT 16
#define HELP_MENU_WELCOME 17
#define HELP_MENU_ABOUT 18

#define PRINT_BUTTON 19
#define CANCEL_PRINT_BUTTON 20


// Global handler:
HWND hMainWnd,hEditCalculations,hEditRadius,hStaticRadius,hClearButton,hCalculateButton,hEditAnswer,hLogo,hProjectSponsor,
	 hstaticCalculationEn,hstaticCalculationBa,hEditUnitsEn,hEditUnitsBa,hStaticUnitsEn, hStaticUnitsBa;
HBITMAP hLogoImage, hRestartImage, hStartImage;
HFONT hFont;
HMENU hMenu;

// Function prototype:
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void AddControls(HWND);
void loadImages();
void AddMenus(HWND);


void printAnswer(HWND hwnd,char calculations[45],char radius[60],char units[10],char Answer[100],int ln);

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
   wndclass.hIcon = (HICON)LoadImage(NULL,TEXT("royal_icon.ico"), IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
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

   hMainWnd = CreateWindow(TEXT("WinApp"),TEXT("Bosnia Calculator v. 1.0 "), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      CW_USEDEFAULT, CW_USEDEFAULT, 400, 700, NULL, NULL, hInstance, NULL);

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
//    case WM_PAINT:
//          HDC     hDC;
//          PAINTSTRUCT ps;
//          hDC = BeginPaint(hWnd, &ps);
//                                    // Paint the line
//                                       MoveToEx(hDC, 45, 25, NULL);
//                                       LineTo(hDC, 45, 90);
//                                       MoveToEx(hDC, 350, 25, NULL);
//                                       LineTo(hDC, 350, 90);
//                                       MoveToEx(hDC, 45, 25, NULL);
//                                       LineTo(hDC, 350, 25);
//                                       MoveToEx(hDC, 45, 90, NULL);
//                                       LineTo(hDC, 350, 90);
//               EndPaint(hWnd, &ps);
//               return 0;
//               break;
    int val;
    case WM_COMMAND:

    	switch(LOWORD(wParam))
            {
                      case FILE_MENU_EXIT:
                      MessageBeep(MB_OK);
                      val = MessageBox(hWnd,"Are you sure?","Wait!", MB_YESNOCANCEL | MB_ICONEXCLAMATION);
    		          switch (HIWORD(val))
    		          {
                            case IDYES:
                            DestroyWindow(hWnd);
                            break;
                            default:
                            return 0;
                      }
                      break;
                	  case IDC_CALCULATION:
                          if (HIWORD(wParam) == CBN_SELENDOK || HIWORD(wParam) == CBN_SELENDCANCEL)
                          {
                          char calculations[45];
                          GetWindowText(hEditCalculations,calculations,45);
                          // Validation of a combobox inputs and changing windows outputs
                            if(strcmp(calculations,"Congratulations on Statehood Day")==0)
                                {
                            	    ShowWindow(hstaticCalculationEn, SW_NORMAL);
                            	    ShowWindow(hstaticCalculationBa, SW_HIDE);
                            	    ShowWindow(hStaticUnitsEn, SW_NORMAL);
                            	    ShowWindow(hStaticUnitsBa, SW_HIDE);
                            	    EnableWindow(hEditUnitsEn,true);
                            	    EnableWindow(hEditUnitsBa,false);
                            	    SetWindowText(hEditRadius, TEXT("Unity of pro-Bosnian,anti-fascist forces"));
                                 }
                            if(strcmp(calculations,"Cestitke na Dan Drzavnosti")==0)
                             {
                            	ShowWindow(hstaticCalculationEn, SW_HIDE);
                            	ShowWindow(hstaticCalculationBa, SW_NORMAL);
                            	ShowWindow(hStaticUnitsEn, SW_HIDE);
                            	ShowWindow(hStaticUnitsBa, SW_NORMAL);
                            	ShowWindow(hEditUnitsBa, SW_NORMAL);
                            	EnableWindow(hEditUnitsEn,false);
                            	EnableWindow(hEditUnitsBa,true);
                            	SetWindowText(hEditRadius, TEXT("Probosanci,antifasisticke snage"));
                             }
                        }
                          break;
                	  case CLEAR_BUTTON:
                	  {
                		 MessageBeep(MB_OK);
                		 ShowWindow(hstaticCalculationEn, SW_NORMAL);
                		 ShowWindow(hstaticCalculationBa, SW_HIDE);
                		 ShowWindow(hStaticUnitsEn, SW_NORMAL);
                		 ShowWindow(hStaticUnitsBa, SW_HIDE);
                		 EnableWindow(hEditUnitsEn,true);
                		 EnableWindow(hEditUnitsBa,false);
                		 SetWindowText(hEditRadius, TEXT("Unity of pro-Bosnian,anti-fascist forces"));
                		 SendMessage(hEditCalculations, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);
                		 SendMessage(hEditUnitsEn, CB_SETCURSEL, (WPARAM) 0, (LPARAM) 0);
                		 SetWindowText(hEditAnswer, TEXT("\r Answer:\r\n radius = Unity of pro-Bosnian,anti-fascist forces. \r\n"));
                		 break;
                	  }
                	  case CALCULATE_BUTTON:
                		  {
                		  MessageBeep(MB_OK);
                          int val;
                          char calculations[45],radius[60],units[10],Answer[100];
                          GetWindowText(hEditCalculations,calculations,45);
                          if(strcmp(calculations,"")==0)
                                            	    {
                                            	    	val = MessageBox(hWnd,"You did not enter anything in field of the calculations!", NULL, MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);
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
                          if(strcmp(calculations,"Congratulations on Statehood Day")==0)
                          {
                                MessageBox(hWnd,"Congratulations on Statehood Day 25. November!", "Answer!", MB_OK | MB_ICONEXCLAMATION);
                                printAnswer(hEditAnswer,calculations,radius,units,Answer,1);
                           }
                          if(strcmp(calculations,"Cestitke na Dan Drzavnosti")==0)
                          {
            					MessageBox(hWnd,"Cestitke na Dan Drzavnosti 25. Novembar!", "Odgovor!", MB_OK | MB_ICONEXCLAMATION);
            					printAnswer(hEditAnswer,calculations,radius,units,Answer,2);
                           }
                     }
                		  return 0;
                		  break;
        }
           wasHandled = true;
           result=0;
           break;
       case WM_CREATE:
          AddMenus(hWnd);
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
	CreateWindow("static", "Choose a Calculation", WS_VISIBLE | WS_CHILD |SS_CENTER, 50, 50, 300, 25, hWnd, NULL, NULL, NULL);
	hEditCalculations = CreateWindow(WC_COMBOBOX, TEXT(""), CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
	    	    	    						      50, 102, 298, 100, hWnd, (HMENU)IDC_CALCULATION, NULL,NULL);
    // load the combobox with item list.
    //Send a CB_ADDSTRING message to load each item
	char Options[2][45]=
	{
			TEXT("Congratulations on Statehood Day"), TEXT("Cestitke na Dan Drzavnosti")
	};
			char A[45];
			int  k = 0;
			memset(&A,0,sizeof(A));
				for (k = 0; k <= 1; k += 1)
					{
						strcpy(A,Options[k]);
						// Add string to combobox.
						SendMessage(hEditCalculations,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A);
					}
	// Send the CB_SETCURSEL message to display an initial item
	//  in the selection field
	SendMessage(hEditCalculations, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	// Text label and text input for radius, area, circumference
	hStaticRadius=CreateWindow("static", "radius= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);
	hEditRadius = CreateWindow("edit","Unity of pro-Bosnian,anti-fascist forces", WS_VISIBLE | WS_CHILD | SS_CENTER,
	    	102, 152, 248, 25, hWnd, NULL, NULL, NULL);

   // Text label and combobox for units
   hStaticUnitsEn = CreateWindow("static", "Units*", WS_VISIBLE | WS_CHILD | SS_CENTER, 102, 204, 100, 25, hWnd, NULL, NULL, NULL);
   hEditUnitsEn = CreateWindow(WC_COMBOBOX, TEXT(""), CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
          						   202, 204, 100, 150, hWnd, (HMENU) NULL, HINSTANCE(NULL),0);
   // load the combobox with item list.
   //Send a CB_ADDSTRING message to load each item
   	char CitizensEn[4][10]=
   	{
   			TEXT("Bosnian"),TEXT("Croatian"),TEXT("Serbian"),TEXT("Other")
   	};
   			char B[10];
   			int  m = 0;
   			memset(&B,0,sizeof(B));
   				for (m = 0; m <= 3; m += 1)
   					{
   						strcpy(B,CitizensEn[m]);
   						// Add string to combobox.
   						SendMessage(hEditUnitsEn,(UINT) CB_ADDSTRING, (WPARAM) 0,(LPARAM) B);
   					}
   	// Send the CB_SETCURSEL message to display an initial item
   	//  in the selection field
   	SendMessage(hEditUnitsEn, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);


   // Restart button for clearing content of text input with loaded images restart button and system loaded sound OK
   hClearButton = CreateWindow(TEXT("button"),NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,
		   50, 240, 100, 60, hWnd,(HMENU) CLEAR_BUTTON, NULL, NULL);
   SendMessage(hClearButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hRestartImage);

   // Start button for calculation based on given r with loaded images start button and system loaded sound OK
   hCalculateButton= CreateWindow(TEXT("button"),"Calculate", WS_VISIBLE | WS_CHILD | BS_BITMAP,
		   250, 240, 100, 60, hWnd, (HMENU)CALCULATE_BUTTON, NULL, NULL);
   SendMessage(hCalculateButton,BM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hStartImage);

   // Text input for screen answer for calculation after use given parameters
   hEditAnswer = CreateWindow(TEXT("edit"),
		    TEXT("\r\r Answer:\r\n Unity of pro-Bosnian,anti-fascist \r\n forces gave best wishes to our country’s  \r\n citizens on this historic date.\r\n "),
		    WS_VISIBLE | WS_CHILD | ES_LEFT | ES_MULTILINE ,
		   50, 308, 300, 80, hWnd, NULL, NULL, NULL);

  // Static logo of the project sponsor with load bmp picture and static title of copyright logo
   hLogo = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,
   	  100, 425, 180, 200, hWnd, NULL, NULL, NULL);
   SendMessage(hLogo,STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hLogoImage);

   hProjectSponsor = CreateWindow("static", "Copyright", WS_VISIBLE | WS_CHILD | SS_LEFT,
		   50, 400, 300, 25, hWnd, NULL, NULL, NULL);

//   hFont=CreateFontA(22, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
//   		   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Calibri");
//   SendMessage (hProjectSponsor, WM_SETFONT, WPARAM (hFont), TRUE);

// Bosnian Version Calculator v.1.0
    // Text label for Biraj racunicu !
    hstaticCalculationBa = CreateWindow("static", "Biraj racunicu !", WS_VISIBLE | WS_CHILD |SS_CENTER, 50, 50, 300, 25, hWnd, NULL, NULL, NULL);
    ShowWindow(hstaticCalculationBa, SW_HIDE);

   	// Text label and text input for radius, area, circumference
   	hStaticRadius=CreateWindow("static", "radius= ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 152, 50, 25, hWnd, NULL, NULL, NULL);

      // Text label and combobox for units
      hStaticUnitsBa = CreateWindow("static", "Jedinica*", WS_VISIBLE | WS_CHILD | SS_CENTER, 102, 204, 100, 25, hWnd, NULL, NULL, NULL);
      ShowWindow(hStaticUnitsBa,SW_HIDE);
      hEditUnitsBa = CreateWindow(WC_COMBOBOX, TEXT(""), CBS_DROPDOWN | CBS_HASSTRINGS | WS_VISIBLE | WS_CHILD,
             						   202, 204, 100, 150, hWnd, (HMENU) NULL, HINSTANCE(NULL),0);
      // load the combobox with item list.
      //Send a CB_ADDSTRING message to load each item
      	char CitizensBa[4][10]=
      	{
      			TEXT("Bosnjak"),TEXT("Hrvat"),TEXT("Srbin"),TEXT("Ostali")
      	};
      			char C[10];
      			int  n = 0;
      			memset(&C,0,sizeof(C));
      				for (n = 0; n <= 3; n += 1)
      					{
      						strcpy(C,CitizensBa[n]);
      						// Add string to combobox.
      						SendMessage(hEditUnitsBa,(UINT) CB_ADDSTRING, (WPARAM) 0,(LPARAM) C);
      					}
      	// Send the CB_SETCURSEL message to display an initial item
      	//  in the selection field
        SendMessage(hEditUnitsBa, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
      	ShowWindow(hEditUnitsBa,SW_HIDE);
        EnableWindow(hEditUnitsBa,true);
}

void loadImages()
{
	hLogoImage = (HBITMAP)LoadImage(NULL, "royal.bmp", IMAGE_BITMAP, 180, 200, LR_LOADFROMFILE);
	hRestartImage = (HBITMAP)LoadImage(NULL, "reset-button.bmp", IMAGE_BITMAP, 80, 65, LR_LOADFROMFILE);
    hStartImage =  (HBITMAP)LoadImage(NULL,"start-button.bmp", IMAGE_BITMAP, 80, 65, LR_LOADFROMFILE);
}

void printAnswer(HWND hwnd, char calculations[45],char radius[60], char units[10], char Answer[100], int ln)
{
			if(ln==1)
				{ strcpy(Answer,TEXT("\r Answer:")); }
			else if (ln==2)
				{strcpy(Answer,TEXT("\r Odgovor:"));};

					  strcat(Answer,TEXT("\r\n"));
					  GetWindowText(hEditRadius,radius,60);
					  strcat(Answer," ");
					  strcat(Answer,radius);
					  strcat(Answer,". ");

					  if(ln==1)
					  { GetWindowText(hEditUnitsEn,units,10);
									  strcat(Answer,units);
									  strcat(Answer," 's");
					  }
					  else if (ln==2)
					  { GetWindowText(hEditUnitsBa,units,10);
						strcat(Answer,units);
					  };

					  if (ln==1)
					  strcat(Answer,TEXT(" gave best wishes to our country’s \r\n citizens on this historic date.\r\n"));
					  else if (ln==2)
				      strcat(Answer,TEXT(" zeli sve najbolje gradjanima domovine na \r\n ovaj historijski datum.\r\n"));

	SetWindowTextA(hwnd,Answer);
}
void AddMenus(HWND hWnd)

{
	hMenu = CreateMenu();
	HMENU  hFileMenu = CreateMenu();
	HMENU  hHelpMenu = CreateMenu();

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_OPEN, "Open");
	AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_PRINT, "Print");
	AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

	AppendMenu(hHelpMenu, MF_STRING, HELP_MENU_WELCOME, "Welcome");
	AppendMenu(hHelpMenu, MF_STRING, HELP_MENU_ABOUT, "About");

	SetMenu(hWnd,hMenu);
}
