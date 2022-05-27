#define _CRT_SECURE_NO_WARNING

#pragma warning(disable:4996)

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	//char lpszAppName[] = "C:\\Users\\Lenovo\\source\\repos\\Parent\\x64\\Debug\\Child.exe";
	char lpszAppName[] = "Child.exe";
	char* ch = new char[1];
	char* lpCommLine = new char[1];

	lpCommLine = strcpy(lpCommLine, "");
	cout << "Введите размер массива: " << endl;
	double n;
	cin >> n;
	ch = _itoa(n, ch, 10);
	lpCommLine = strcat(lpCommLine, ch);
	lpCommLine = strcat(lpCommLine, " ");
	double el;
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> el;
		ch = _itoa(el, ch, 10);
		lpCommLine = strcat(lpCommLine, ch);
		lpCommLine = strcat(lpCommLine, " ");
	}
	cout << "Введите А. Все элементы массива >A будут размещены в массиве слева, остальные - заполнены нулями:" << endl;
	double A;
	cin >> A;
	ch = _itoa(A, ch, 10);
	lpCommLine = strcat(lpCommLine, ch);

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USECOUNTCHARS;
	si.dwYCountChars = 500;
	

	PROCESS_INFORMATION piApp;

	if (!CreateProcess(lpszAppName, lpCommLine, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		_cputs("Новый процесс не создан.\n");
		_getch();
		
	}

	WaitForSingleObject(piApp.hProcess, INFINITE);
	CloseHandle(piApp.hProcess);
	CloseHandle(piApp.hThread);
	
	return 0;
}