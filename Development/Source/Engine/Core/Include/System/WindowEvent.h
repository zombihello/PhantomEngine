/**
 * @file
 * @addtogroup Core Core
 */

#pragma once

/**
 * @brief Enumeration of types event window
 */
enum EWindowEventType
{
	WET_None,			/**< No event */
	WET_WindowClose		/**< Close window */
};

/**
 * @ingroup Core
 * @brief Storage of window event
 */
struct WindowEvent
{
	/**
	 * @brief Constructor
	 */
	WindowEvent()
		: type( WET_None )
	{}

	EWindowEventType	type;			/**< Type of event */
};