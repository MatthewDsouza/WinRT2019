# include <windows.h>
# include "SplashScreen.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstances, LPSTR lpszCmdLine, int iCmdShow)
{
	
	//variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("myappname");
	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));


	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("MY application"),
		WS_OVERLAPPED,
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

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wparam, LPARAM lparam)
{
	
	HDC hdc,cdc;
	PAINTSTRUCT ps;
	RECT rc;
	HINSTANCE hInstance;
	static HBITMAP hbitSS;
	BITMAP bitSS;
	//TCHAR str[255] = TEXT("Hello world");

	//code
	switch (iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, TEXT("my window created"), TEXT("ERROR!!"), MB_OK);
		hInstance = GetModuleHandle(NULL);
		hbitSS = LoadBitmap(hInstance, MAKEINTRESOURCE(MY_ABC));
		MessageBox(hwnd, TEXT("BMP  loaded!!!!!!!!"), TEXT("sucess loading!!"), MB_OK);
		if (hbitSS == NULL)
		{
			
			MessageBox(hwnd, TEXT("BMP dint load!!!!!!!!"), TEXT("ERROR!!"), MB_OK);
			DestroyWindow(hwnd);
		}
		break;

	case WM_PAINT:
		//MessageBox(hwnd, TEXT("strted paint!!!!!!!!"), TEXT("sucess loading!!"), MB_OK);
		
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		//hdc = GetDC(hwnd);
		cdc = CreateCompatibleDC(NULL);
		SelectObject(cdc,hbitSS);
		GetObject(hbitSS, sizeof(BITMAP), &bitSS);
		//StretchBlt(hdc, 0, 0, rc.left,rc.right, cdc,0,0,  0, 0, SRCCOPY);
		StretchBlt(hdc, 0,0,1290,1300,cdc, 0, 0, 390, 590, SRCCOPY);
		DeleteObject(cdc);
		EndPaint(hwnd, &ps);
		break;
	
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;



	}
	return(DefWindowProc(hwnd, iMsg, wparam, lparam));

}


