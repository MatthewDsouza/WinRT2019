//headers
#include<windows.h>
//#define MYTIMER 101

//global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstances, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable decalaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("MY application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//messagel loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lparam)
{

	//code
	//code
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	static int ipaintflag = 0;
	HBRUSH hbrush;


	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	
	case WM_CHAR:
		switch (LOWORD(wparam))
		{
		case 'r':
		case 'R':
			GetClientRect(hwnd, &rc);
			ipaintflag = 1;
			//MessageBox(hwnd, TEXT("key r"), TEXT("MessageBox"), MB_OK);
			InvalidateRect(hwnd, &rc,FALSE);
			
			break;
		case 'g':
		case 'G':
			GetClientRect(hwnd, &rc);
			ipaintflag = 2;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		case 'b':
		case 'B':
			GetClientRect(hwnd, &rc);
			ipaintflag = 3;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		case 'c':
		case 'C':
			GetClientRect(hwnd, &rc);
			ipaintflag = 4;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		case 'm':
		case 'M':
			GetClientRect(hwnd, &rc);
			ipaintflag = 5;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		case 'y':
		case 'Y':
			GetClientRect(hwnd, &rc);
			ipaintflag = 6;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		case 'k':
		case 'K':
			GetClientRect(hwnd, &rc);
			ipaintflag = 7;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		case 'w':
		case 'W':
			GetClientRect(hwnd, &rc);
			ipaintflag = 8;
			InvalidateRect(hwnd, &rc, FALSE);
			break;
		default:
			MessageBox(hwnd, TEXT("Not press from above"), TEXT("MESSAGE"), MB_OKCANCEL | MB_ICONINFORMATION);

		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);
		
		switch (ipaintflag)
		{
		case 1:
			
			hbrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);

			break;
			
		case 2:
			hbrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		case 3:
			hbrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		case 4:
			hbrush = CreateSolidBrush(RGB(0, 225, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		case 5:
			hbrush = CreateSolidBrush(RGB(225, 0, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		case 6:
			hbrush = CreateSolidBrush(RGB(225, 225, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		case 7:
			hbrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;
		case 8:
			hbrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hbrush);
			FillRect(hdc, &rc, hbrush);
			break;

		}
		break;
		EndPaint(hwnd, &ps);
	

	}
	return(DefWindowProc(hwnd, iMsg, wparam, lparam));

}

