/**
 * @file
 * @addtogroup WindowsPlatform Windows platform
 */

#pragma once
#include <Windows.h>

#include "Misc/Types.h"

// Mark what we on Windows
#undef PLATFORM_WINDOWS
#define PLATFORM_WINDOWS	1

/**
 * @ingroup WindowsPlatform
 * @brief Typedef of window handle
 */
typedef void* WindowHandle_t;