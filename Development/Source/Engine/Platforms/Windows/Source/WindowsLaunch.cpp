#include <iostream>
#include <Windows.h>

/*
==================
WinMain
==================
*/
int WINAPI WinMain( HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nCmdShow )
{
	MessageBoxA( NULL, "Its works!", "Engine", MB_OK );
	return 0;
}