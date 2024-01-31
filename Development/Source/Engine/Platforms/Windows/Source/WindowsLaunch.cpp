#include <iostream>
#include <Windows.h>
#include "WindowsWindow.h"

/*
==================
WinMain
==================
*/
int WINAPI WinMain( HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nCmdShow )
{
	// Create a test window
	bool				bExit = false;
	CWindowsWindow		window;
	window.Create( "ExampleGame", 1280, 720 );

	// Our main loop
	while ( !bExit )
	{
		// Handle window events
		WindowEvent		windowEvent;
		while ( window.PollEvent( windowEvent ) )
		{
			switch ( windowEvent.type )
			{
				// Close the window if user pressed on close button
			case WET_WindowClose:
				bExit = true;
				break;
			}
		}
	}

	// Close the window and exit from app
	window.Close();
	return 0;
}