#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int){
	OPENFILENAME ofn;
	char szFile[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFilter = TEXT("�e�L�X�g�t�@�C��(*.txt)\0*.txt\0")
	TEXT("���ׂẴt�@�C��(*.*)\0*.*\0\0");
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_FILEMUSTEXIST;
	
	GetOpenFileName(&ofn);
	
	MessageBox(NULL, szFile, "�J����܂��傤", MB_OK);

	return 0;
}