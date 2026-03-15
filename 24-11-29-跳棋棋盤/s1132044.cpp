#include "framework.h"
#include "s1132044.h"
#include <windowsx.h>
#include <math.h>
#define MAX_LOADSTRING 100

// 全域變數:
HINSTANCE hInst;                                // 目前執行個體
WCHAR szTitle[MAX_LOADSTRING];                  // 標題列文字
WCHAR szWindowClass[MAX_LOADSTRING];            // 主視窗類別名稱
// 這個程式碼模組所包含之函式的向前宣告:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	// TODO: 在此放置程式碼。
	// 將全域字串初始化
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_S11320441129CLASS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	// 執行應用程式初始化:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_S11320441129CLASS));
	MSG msg;
	// 主訊息迴圈:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}
//
//  函式: MyRegisterClass()
//
//  用途: 註冊視窗類別。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_S11320441129CLASS));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_S11320441129CLASS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	return RegisterClassExW(&wcex);
}
//
//   函式: InitInstance(HINSTANCE, int)
//
//   用途: 儲存執行個體控制代碼並且建立主視窗
//
//   註解:
//
//        在這個函式中，我們將執行個體控制代碼儲存在全域變數中，
//        並建立及顯示主程式視窗。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 將執行個體控制代碼儲存在全域變數中
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
//
//  函式: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  用途: 處理主視窗的訊息。
//
//  WM_COMMAND  - 處理應用程式功能表
//  WM_PAINT    - 繪製主視窗
//  WM_DESTROY  - 張貼結束訊息然後傳回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static struct myGame g = { 0 };
	static int previous = 0;
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_CREATE:
	{
		//init(g);
		//saveBoard(g);
		readBoard(g);
		initChase(g);
	}
	break;
	case WM_RBUTTONDOWN:
	{
		chase[0][0][0] = g.Ac[chase[0][0][0]][0] - 1;
		RECT rc;
		SetRect(&rc, g.A[chase[0][0][0]].p.x - g.A[chase[0][0][0]].r * 4, g.A[chase[0][0][0]].p.y - g.A[chase[0][0][0]].r * 4
			, g.A[chase[0][0][0]].p.x + g.A[chase[0][0][0]].r * 4, g.A[chase[0][0][0]].p.y + g.A[chase[0][0][0]].r * 4);
		InvalidateRect(hWnd, &rc, true);
	}
	break;
	case WM_LBUTTONDOWN:
	{
		myPoint p;
		p.x = GET_X_LPARAM(lParam);
		p.y = GET_Y_LPARAM(lParam);
		int i;
		RECT rc;
		for (i = 0; i < Cn; i++)
		{
			if (inSide(g.A[i], p))
			{
				g.A[previous].color = RGB(255, 255, 255);
				for (int j = 0; j < 8; j++)
					if (g.Ac[previous][j] > 0)  g.A[g.Ac[previous][j] - 1].pencolor = RGB(0, 0, 0);
				SetRect(&rc, g.A[previous].p.x - g.A[previous].r * 4, g.A[previous].p.y - g.A[previous].r * 4
					, g.A[previous].p.x + g.A[previous].r * 4, g.A[previous].p.y + g.A[previous].r * 4);
				InvalidateRect(hWnd, &rc, true);
				SetRect(&rc, g.A[i].p.x - g.A[i].r * 4, g.A[i].p.y - g.A[i].r * 4, g.A[i].p.x + g.A[i].r * 4, g.A[i].p.y + g.A[i].r * 4);
				g.A[i].color = RGB(128, 128, 128);
				for (int j = 0; j < 8; j++)
					if (g.Ac[i][j] > 0)  g.A[g.Ac[i][j] - 1].pencolor = RGB(255, 0, 0);
				InvalidateRect(hWnd, &rc, true);
				previous = i;
				break;
			}
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		draw(hdc, g);
		updateChase(g);
		drawChase(hdc, chaseCircle);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
// [關於] 方塊的訊息處理常式。
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