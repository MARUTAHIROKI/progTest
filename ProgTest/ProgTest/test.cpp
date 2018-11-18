#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int){
	OPENFILENAME ofn;
	char szFile[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFilter = TEXT("テキストファイル(*.txt)\0*.txt\0")
	TEXT("すべてのファイル(*.*)\0*.*\0\0");
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_FILEMUSTEXIST;
	
	GetOpenFileName(&ofn);
	
	MessageBox(NULL, szFile, "開かれましょう", MB_OK);

	return 0;
}