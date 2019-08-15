//headers
#include<windows.h>

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
	MessageBox(0, TEXT("Application is started"), TEXT("Messsage"), MB_OK);
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
	//wsprintf(str, TEXT("before create window"));
	
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
	TCHAR str[255];
	//code
	switch (iMsg)
	{
	case WM_CREATE:
		wsprintf(str, TEXT("WM_CREATE is arrived"));
		MessageBox(hwnd, str, TEXT("Messsage"), MB_OK | MB_ICONINFORMATION);
		break;
	case WM_KEYDOWN:
		wsprintf(str, TEXT("WM_KEYDOWN is arrived"));
		MessageBox(hwnd, str, TEXT("Messsage"), MB_OK );
		break;
	case WM_LBUTTONDOWN:
		wsprintf(str, TEXT("WM_LBUTTONDOWN is arrived"));
		MessageBox(hwnd, str, TEXT("Messsage"), MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return(DefWindowProc(hwnd, iMsg, wparam, lparam));

}

