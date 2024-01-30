/**
 * @file
 * @addtogroup WindowsPlatform Windows platform
 */

#pragma once
#include <SDL.h>
#include <SDL_syswm.h>

#include "Core.h"
#include "System/BaseWindow.h"

/**
 * @ingroup WindowsPlatform
 * @brief The class for work with window on Windows
 */
class CWindowsWindow : public CBaseWindow
{
public:
	/**
	 * @brief Constructor
	 */
	CWindowsWindow();

	/**
	 * @brief Destructor
	 */
	~CWindowsWindow();

	/**
	 * @brief Create window
	 *
	 * @param InTitle	Title
	 * @param InWidth	Width
	 * @param InHeight	Height
	 * @param InFlags	Combinations flags of EStyleWindow for set style of window
	 * @return Return TRUE if window is created successfully, otherwise returns FALSE
	 */
	virtual bool Create( const achar* InTitle, uint32 InWidth, uint32 InHeight, uint32 InFlags = SW_Default ) override;

	/**
	 * @brief Close window
	 */
	virtual void Close() override;

	/**
	 * @brief Show cursor
	 * @param InIsShowCursor	Is need show or hide cursor
	 */
	virtual void ShowCursor( bool InIsShowCursor = true ) override;

	/**
	 * @brief Show window
	 * @param InIsShowWindow	Is need show or hide window
	 */
	virtual void ShowWindow( bool InIsShowWindow = true ) override;

	/**
	 * @brief Maximize window
	 */
	virtual void Maximize() override;

	/**
	 * @brief Minimize window
	 */
	virtual void Minimize() override;

	/**
	 * @brief Handle window event
	 *
	 * @param OutWindowEvent	Occurred window event
	 * @return Return TRUE if queue of events not empty, otherwise returns FALSE
	 */
	virtual bool PollEvent( WindowEvent& OutWindowEvent ) override;

	/**
	 * @brief Set title of window
	 * @param InTitle	New title
	 */
	virtual void SetTitle( const achar* InTitle ) override;

	/**
	 * @brief Set size of window
	 *
	 * @param InWidth	Width
	 * @param InHeight	Height
	 */
	virtual void SetSize( uint32 InWidth, uint32 InHeight ) override;

	/**
	 * @brief Set fullscreen mode
	 * @param InIsFullscreen	Enable or disable fullscreen mode
	 */
	virtual void SetFullscreen( bool InIsFullscreen ) override;

	/**
	 * @brief Is window open
	 * @return Return TRUE if window is opened, otherwise returns FALSE
	 */
	virtual bool IsOpen() const override;

	/**
	 * @brief Is showing cursor
	 * @return Return TRUE if cursor is showing, otherwise returns FALSE
	 */
	virtual bool IsShowingCursor() const override;

	/**
	 * @brief Is enabled fullscreen mode
	 * @return Return TRUE if fullscreen mode is enabled, otherwise returns FALSE
	 */
	virtual bool IsFullscreen() const override;

	/**
	 * @brief Get size window
	 *
	 * @param OutWidth		Output window width
	 * @oaram OutHeight		Output window height
	 */
	virtual void GetSize( uint32& OutWidth, uint32& OutHeight ) const override;

	/**
	 * @brief Get window handle
	 * @return Return window handle
	 */
	virtual WindowHandle_t GetHandle() const override;

private:
	bool			bIsShowCursor;			/**< Is showed cursor */
	bool			bIsFullscreen;			/**< Is enabled fullscreen mode */
	SDL_Window*		sdlWindow;				/**< SDL window */
	SDL_SysWMinfo*	sdlWindowInfo;			/**< System info from SDL */
	HANDLE			handle;					/**< OS handle on window */
};