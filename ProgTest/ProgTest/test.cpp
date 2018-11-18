#include <windows.h>

#define BUTTON1 100
#define BUTTON2 200

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

	// 変数宣言
	OPENFILENAME fname,fname2;
	static HWND button, button2, text, text2, text3, text4;
	char image_path[MAX_PATH] = "", image_path2[MAX_PATH] = "";

	// ファイルを開くの初期化？
	ZeroMemory(&fname, sizeof(fname));
	fname.lStructSize = sizeof(OPENFILENAME);
	fname.lpstrFilter = TEXT("テキストファイル(*.txt)\0*.txt\0")
	TEXT("すべてのファイル(*.*)\0*.*\0\0");
	fname.lpstrFile = image_path;
	fname.nMaxFile = MAX_PATH;
	fname.Flags = OFN_FILEMUSTEXIST;

	ZeroMemory(&fname2, sizeof(fname2));
	fname2.lStructSize = sizeof(OPENFILENAME);
	fname2.lpstrFilter = TEXT("テキストファイル(*.txt)\0*.txt\0")
		TEXT("すべてのファイル(*.*)\0*.*\0\0");
	fname2.lpstrFile = image_path2;
	fname2.nMaxFile = MAX_PATH;
	fname2.Flags = OFN_FILEMUSTEXIST;

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		text = CreateWindow(
			TEXT("STATIC"), TEXT("入力画像ファイルを指定してください"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 10, 300, 20,
			hwnd, (HMENU)1,
			((LPCREATESTRUCT)(lp))->hInstance, NULL
		);

		button = CreateWindow(
			TEXT("BUTTON"), TEXT("ファイルを開く"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 10, 150, 20,
			hwnd, (HMENU)BUTTON1,
			((LPCREATESTRUCT)(lp))->hInstance, NULL
		);

		text2 = CreateWindow(
			TEXT("STATIC"), " ",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 30, 1000, 20,
			hwnd, (HMENU)1,
			((LPCREATESTRUCT)(lp))->hInstance, NULL
		);

		text3 = CreateWindow(
			TEXT("STATIC"), TEXT("CSVファイルを指定してください"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 50, 300, 20,
			hwnd, (HMENU)1,
			((LPCREATESTRUCT)(lp))->hInstance, NULL
		);

		button2 = CreateWindow(
			TEXT("BUTTON"), TEXT("ファイルを開く"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 50, 150, 20,
			hwnd, (HMENU)BUTTON2,
			((LPCREATESTRUCT)(lp))->hInstance, NULL
		);

		text4 = CreateWindow(
			TEXT("STATIC"), " ",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 70, 1000, 20,
			hwnd, (HMENU)1,
			((LPCREATESTRUCT)(lp))->hInstance, NULL
		);
		return 0;
	case WM_COMMAND:
		//ボタンが押された時の処理
		switch (LOWORD(wp)) {
		case BUTTON1:
			GetOpenFileName(&fname);
			SetWindowText(text2, image_path);
			break;
		case BUTTON2:
			GetOpenFileName(&fname2);
			SetWindowText(text4, image_path2);
			break;
		default:
			break;
		}

		return 0;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("KITTY");

	if (!RegisterClass(&winc)) return -1;

	hwnd = CreateWindow(
		TEXT("KITTY"), TEXT("ConcreteDefect"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1000, 300,
		NULL, NULL, hInstance, NULL
	);

	if (hwnd == NULL) return -1;

	while (GetMessage(&msg, NULL, 0, 0)) DispatchMessage(&msg);
	return msg.wParam;
}