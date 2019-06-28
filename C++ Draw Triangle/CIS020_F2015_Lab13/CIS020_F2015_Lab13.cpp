// CIS020_F2015_Lab13.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CIS020_F2015_Lab13.h"
#include "assemble.cpp"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DialogBox1(HWND, UINT, WPARAM, LPARAM);
TRIANGLE_3 DoAssembly(TRIANGLE_3, int, signed int);

void DrawTriangle(HDC hdc)
{
	// Draw the triangle
	MoveToEx(hdc, triangle.a.x, triangle.a.y, NULL);
		
	LineTo(hdc,triangle.b.x, triangle.b.y);
	LineTo(hdc,triangle.c.x, triangle.c.y);
	LineTo(hdc,triangle.a.x, triangle.a.y);
}

void OutputText(HDC hdc)
{
	TCHAR sz_A[] = _T("A = (");
	TCHAR sz_B[] = _T("B = (");
	TCHAR sz_C[] = _T("C = (");
	TCHAR sz_Comma[] = _T(",");
	TCHAR sz_Close[] = _T(")");
	TCHAR sz_Value[32] = {0};

	// draw the a,b,c coordinate text
	TextOut(hdc, 10, 10, sz_A, 5);
	TextOut(hdc, 10, 30, sz_B, 5);
	TextOut(hdc, 10, 50, sz_C, 5);

	// A = 0, 0, 0)
	_stprintf_s( sz_Value, _T("%i"), triangle.a.x);
	TextOut(hdc, 40, 10, sz_Value, 3);
	TextOut(hdc, 65, 10, sz_Comma, 1);
	_stprintf_s( sz_Value, _T("%i"), triangle.a.y);
	TextOut(hdc, 75, 10, sz_Value, 3);
	TextOut(hdc, 100, 10, sz_Comma, 1);
	_stprintf_s( sz_Value, _T("%i"), triangle.a.z);
	TextOut(hdc, 110, 10, sz_Value, 3);
	TextOut(hdc, 135, 10, sz_Close, 1);

	// B = 0, 0, 0)
	_stprintf_s( sz_Value, _T("%i"), triangle.b.x);
	TextOut(hdc, 40, 30, sz_Value, 3);
	TextOut(hdc, 65, 30, sz_Comma, 1);
	_stprintf_s( sz_Value, _T("%i"), triangle.b.y);
	TextOut(hdc, 75, 30, sz_Value, 3);
	TextOut(hdc, 100, 30, sz_Comma, 1);
	_stprintf_s( sz_Value, _T("%i"), triangle.b.z);
	TextOut(hdc, 110, 30, sz_Value, 3);
	TextOut(hdc, 135, 30, sz_Close, 1);

	// C = 0, 0, 0)
	_stprintf_s( sz_Value, _T("%i"), triangle.c.x);
	TextOut(hdc, 40, 50, sz_Value, 3);
	TextOut(hdc, 65, 50, sz_Comma, 1);
	_stprintf_s( sz_Value, _T("%i"), triangle.c.y);
	TextOut(hdc, 75, 50, sz_Value, 3);
	TextOut(hdc, 100, 50, sz_Comma, 1);
	_stprintf_s( sz_Value, _T("%i"), triangle.c.z);
	TextOut(hdc, 110, 50, sz_Value, 3);
	TextOut(hdc, 135, 50, sz_Close, 1);
}


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CIS020_F2015_LAB13, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS020_F2015_LAB13));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS020_F2015_LAB13));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CIS020_F2015_LAB13);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   	// I know. Bizzare spot, but I'm going to initialize the triangle coordinates here. So there.
   	triangle.a.x = 100;
	triangle.a.y = 100;
	triangle.a.z = 100;
	triangle.b.x = 100;
	triangle.b.y = 300;
	triangle.b.z = 100;
	triangle.c.x = 300;
	triangle.c.y = 300;
	triangle.c.z = 100;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			UpdateWindow(hWnd);
			break;
		case IDM_ASSEMBLE:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogBox1); // call the input dialog box
			InvalidateRect(hWnd, NULL, TRUE);	// InvalidateRect makes sure the entire main window is refreshed by BeginPoint
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawTriangle(hdc);			// Draw the triangle
		OutputText(hdc);			// TextOut the triangle corrdinate text

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// Message handler for DialogBox1.
INT_PTR CALLBACK DialogBox1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (message)
	{
	case WM_INITDIALOG:

		CheckRadioButton(hDlg, IDC_rdo_Move, IDC_rdo_Resize, IDC_rdo_Move);

		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{

		case IDOK:
			{
				int iMod;
				signed int iInput;
				BOOL bGood;

				if (IsDlgButtonChecked(hDlg, IDC_rdo_Move) == BST_CHECKED)
					iMod = iMOVE;
				else
					iMod = iRESIZE;

				iInput = GetDlgItemInt(hDlg, IDC_EDIT1, &bGood, TRUE);
				if ( !bGood )
					iInput = 0;

				// call the inline assembly routine
				triangle = DoAssembly(triangle, iMod, iInput);

				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			case IDCANCEL:
			{
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
		}
		break;
	}
	return (INT_PTR)FALSE;
}
