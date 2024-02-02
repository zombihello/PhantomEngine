/**
 * @file
 * @addtogroup Core Core
 */

#pragma once
#include "Misc/Types.h"
#include "CoreDefines.h"
#include "System/WindowEvent.h"

/**
 * @ingroup Core
 * @brief Enumeration of types window styles
 */
enum EStyleWindow
{
	SW_None				= 0,							/**< No styles */
	SW_Resizable		= 1 << 0,						/**< Resizable window */
	SW_Decorated		= 1 << 1,						/**< Decorated window  */
	SW_Fullscreen		= 1 << 2,						/**< Fullscreen window  */
	SW_Hidden			= 1 << 3,						/**< Hidden window */
	SW_Minimized		= 1 << 4,						/**< Window is minimized. If set flag SW_Maximized or SW_Fullscreen will be ignore */
	SW_Maximized		= 1 << 5,						/**< Window is maximized. If set flag SW_Minimized or SW_Fullscreen will be ignore */

	SW_Default			= SW_Decorated | SW_Resizable	/**< Default style - combined decorated and resizable style  */
};

/**
 * @ingroup Core
 * @brief The base class for work with window
 */
class CBaseWindow
{
public:
	/**
	 * @brief Destructor
	 */
	virtual ~CBaseWindow() {}

	/**
	 * @brief Create window
	 *
	 * @param InTitle	Title
	 * @param InWidth	Width
	 * @param InHeight	Height
	 * @param InFlags	Combinations flags of EStyleWindow for set style of window
	 * @return Return TRUE if window is created successfully, otherwise returns FALSE
	 */
	virtual bool Create( const achar* InTitle, uint32 InWidth, uint32 InHeight, uint32 InFlags = SW_Default ) = 0;

	/**
	 * @brief Close window
	 */
	virtual void Close() = 0;

	/**
	 * @brief Show cursor
	 * @param InIsShowCursor	Is need show or hide cursor
	 */
	virtual void ShowCursor( bool InIsShowCursor = true ) = 0;

	/**
	 * @brief Show window
	 * @param InIsShowWindow	Is need show or hide window
	 */
	virtual void ShowWindow( bool InIsShowWindow = true ) = 0;

	/**
	 * @brief Maximize window
	 */
	virtual void Maximize() = 0;

	/**
	 * @brief Minimize window
	 */
	virtual void Minimize() = 0;

	/**
	 * @brief Handle window event
	 *
	 * @param OutWindowEvent	Occurred window event
	 * @return Return TRUE if queue of events not empty, otherwise returns FALSE
	 */
	virtual bool PollEvent( WindowEvent& OutWindowEvent ) = 0;

	/**
	 * @brief Set title of window
	 * @param InTitle	New title
	 */
	virtual void SetTitle( const achar* InTitle ) = 0;

	/**
	 * @brief Set size of window
	 *
	 * @param InWidth	Width
	 * @param InHeight	Height
	 */
	virtual void SetSize( uint32 InWidth, uint32 InHeight ) = 0;

	/**
	 * @brief Set fullscreen mode
	 * @param InIsFullscreen	Enable or disable fullscreen mode
	 */
	virtual void SetFullscreen( bool InIsFullscreen ) = 0;

	/**
	 * @brief Is window open
	 * @return Return TRUE if window is opened, otherwise returns FALSE
	 */
	virtual bool IsOpen() const = 0;

	/**
	 * @brief Is showing cursor
	 * @return Return TRUE if cursor is showing, otherwise returns FALSE
	 */
	virtual bool IsShowingCursor() const = 0;

	/**
	 * @brief Is enabled fullscreen mode
	 * @return Return TRUE if fullscreen mode is enabled, otherwise returns FALSE
	 */
	virtual bool IsFullscreen() const = 0;

	/**
	 * @brief Get size window
	 *
	 * @param OutWidth		Output window width
	 * @oaram OutHeight		Output window height
	 */
	virtual void GetSize( uint32& OutWidth, uint32& OutHeight ) const = 0;

	/**
	 * @brief Get window handle
	 * @return Return window handle
	 */
	virtual WindowHandle_t GetHandle() const = 0;
};