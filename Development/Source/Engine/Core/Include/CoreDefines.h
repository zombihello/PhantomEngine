/**
 * @file
 * @addtogroup Core Core
 */

#pragma once

// By default all defines PLATFORM_XXX is 0
#define PLATFORM_WINDOWS		0

// Platform specific definitions
#if _WIN32 || _WIN64        // Windows platform
	#include "WindowsPlatform.h"
#else
	#error Unknown platform
#endif // _WIN32 || _WIN64