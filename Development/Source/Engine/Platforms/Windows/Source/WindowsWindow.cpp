#include <stdio.h>
#include "WindowsWindow.h"

/*
==================
CWindowsWindow::CWindowsWindow
==================
*/
CWindowsWindow::CWindowsWindow()
	: bIsShowCursor( false )
	, bIsFullscreen( false )
	, sdlWindow( nullptr )
	, sdlWindowInfo( nullptr )
	, handle( nullptr )
{}

/*
==================
CWindowsWindow::~CWindowsWindow
==================
*/
CWindowsWindow::~CWindowsWindow()
{
	Close();
}

/*
==================
CWindowsWindow::Create
==================
*/
bool CWindowsWindow::Create( const achar* InTitle, uint32 InWidth, uint32 InHeight, uint32 InFlags /* = SW_Default */ )
{
	// Do nothing if we already create the window
	if ( sdlWindow )
	{
		printf( "Warning: CWindowsWindow::Create: Window already created\n" );
		return true;
	}

	// Combine flags for SDL2
	uint32		sdlFlags = 0;
	if ( InFlags & SW_Hidden )
	{
		sdlFlags = SDL_WINDOW_HIDDEN;
	}
	else
	{
		sdlFlags = SDL_WINDOW_SHOWN;
	}

	if ( bIsFullscreen || InFlags & SW_Fullscreen )
	{
		bIsFullscreen = true;
		sdlFlags |= SDL_WINDOW_FULLSCREEN;
	}
	else
	{
		if ( InFlags & SW_Resizable )
		{
			sdlFlags |= SDL_WINDOW_RESIZABLE;
		}

		if ( !( InFlags & SW_Decorated ) )
		{
			sdlFlags |= SDL_WINDOW_BORDERLESS;
		}
		
		if ( InFlags & SW_Minimized )
		{
			sdlFlags |= SDL_WINDOW_MINIMIZED;
		}

		if ( InFlags & SW_Maximized )
		{
			sdlFlags |= SDL_WINDOW_MAXIMIZED;
		}
	}

	// Create the window
	sdlWindow = SDL_CreateWindow( InTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, InWidth, InHeight, sdlFlags );
	if ( !sdlWindow )
	{
		printf( "Error: Failed created window (%ix%i) with title '%s' and flags 0x%X. SDL error: %s", InWidth, InHeight, InTitle, InFlags, SDL_GetError() );
		return false;
	}

	// Get OS handle on window
	sdlWindowInfo = new SDL_SysWMinfo();
	SDL_VERSION( &sdlWindowInfo->version );
	SDL_GetWindowWMInfo( sdlWindow, sdlWindowInfo );
	handle = sdlWindowInfo->info.win.window;

	return false;
}

/*
==================
CWindowsWindow::Close
==================
*/
void CWindowsWindow::Close()
{
	// Do nothing if the window already close
	if ( !sdlWindow )
	{
		return;
	}

	SDL_DestroyWindow( sdlWindow );
	delete sdlWindowInfo;

	// Show mouse if it need
	if ( !bIsShowCursor )
	{
		SDL_SetRelativeMouseMode( SDL_FALSE );
	}

	sdlWindow = nullptr;
	sdlWindowInfo = nullptr;
	handle = nullptr;
	bIsFullscreen = false;
	bIsShowCursor = false;
	printf( "Window with handle %p closed\n", handle );
}

/*
==================
CWindowsWindow::ShowCursor
==================
*/
void CWindowsWindow::ShowCursor( bool InIsShowCursor /* = true */ )
{
	bIsShowCursor = InIsShowCursor;
	SDL_SetRelativeMouseMode( InIsShowCursor ? SDL_FALSE : SDL_TRUE );
}

/*
==================
CWindowsWindow::ShowWindow
==================
*/
void CWindowsWindow::ShowWindow( bool InIsShowWindow /* = true */ )
{
	if ( sdlWindow )
	{
		if ( InIsShowWindow )
		{
			SDL_ShowWindow( sdlWindow );
		}
		else
		{
			SDL_HideWindow( sdlWindow );
		}
	}
}

/*
==================
CWindowsWindow::Maximize
==================
*/
void CWindowsWindow::Maximize()
{
	if ( sdlWindow )
	{
		SDL_MaximizeWindow( sdlWindow );
	}
}

/*
==================
CWindowsWindow::Minimize
==================
*/
void CWindowsWindow::Minimize()
{
	if ( sdlWindow )
	{
		SDL_MinimizeWindow( sdlWindow );
	}
}

/*
==================
CWindowsWindow::PollEvent
==================
*/
bool CWindowsWindow::PollEvent( WindowEvent& OutWindowEvent )
{
	// Do nothing if window isn't created
	if ( !sdlWindow )
	{
		return false;
	}

	// By default set window event to none
	OutWindowEvent.type = WET_None;

	// Polls for currently pending SDL2 events
	SDL_Event		sdlEvent;
	bool			bIsNotEndQueue = SDL_PollEvent( &sdlEvent );

	// Handle SDL2 events
	switch ( sdlEvent.type )
	{
		// Window events
	case SDL_WINDOWEVENT:
		switch ( sdlEvent.window.event )
		{
			// Close window
		case SDL_WINDOWEVENT_CLOSE:
			OutWindowEvent.type = WET_WindowClose;
			break;
		}
		break;

		// Unknown event
	default:
		OutWindowEvent.type = WET_None;
		break;
	}

	return bIsNotEndQueue;
}

/*
==================
CWindowsWindow::SetTitle
==================
*/
void CWindowsWindow::SetTitle( const achar* InTitle )
{
	if ( sdlWindow )
	{
		SDL_SetWindowTitle( sdlWindow, InTitle );
	}
}

/*
==================
CWindowsWindow::SetSize
==================
*/
void CWindowsWindow::SetSize( uint32 InWidth, uint32 InHeight )
{
	if ( sdlWindow )
	{
		SDL_SetWindowSize( sdlWindow, InWidth, InHeight );
		SDL_SetWindowPosition( sdlWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED );
	}
}

/*
==================
CWindowsWindow::SetFullscreen
==================
*/
void CWindowsWindow::SetFullscreen( bool InIsFullscreen )
{
	if ( sdlWindow )
	{
		bIsFullscreen = InIsFullscreen;
		SDL_SetWindowFullscreen( sdlWindow, InIsFullscreen ? SDL_WINDOW_FULLSCREEN : 0 );
	}
}

/*
==================
CWindowsWindow::IsOpen
==================
*/
bool CWindowsWindow::IsOpen() const
{
	return sdlWindow;
}

/*
==================
CWindowsWindow::IsShowingCursor
==================
*/
bool CWindowsWindow::IsShowingCursor() const
{
	return bIsShowCursor;
}

/*
==================
CWindowsWindow::IsFullscreen
==================
*/
bool CWindowsWindow::IsFullscreen() const
{
	return bIsFullscreen;
}

/*
==================
CWindowsWindow::GetSize
==================
*/
void CWindowsWindow::GetSize( uint32& OutWidth, uint32& OutHeight ) const
{
	if ( sdlWindow )
	{
		SDL_GetWindowSize( sdlWindow, ( int* )&OutWidth, ( int* )&OutHeight );
	}
}

/*
==================
CWindowsWindow::GetHandle
==================
*/
WindowHandle_t CWindowsWindow::GetHandle() const
{
	return handle;
}