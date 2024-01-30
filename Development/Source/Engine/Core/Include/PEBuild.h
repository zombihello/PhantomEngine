/**
 * @file
 * @addtogroup Core Core
 */

#pragma once

// Define 'PLATFORM_64BIT' if it not defined
#ifndef PLATFORM_64BIT
	#define PLATFORM_64BIT 0
#endif // !PLATFORM_64BIT

// When we don't have any PLATFORM_XXXBIT its mean what we try to compile on unknown bit platform
#if !PLATFORM_64BIT
	#error Unknown bit platform
#endif // !PLATFORM_64BIT