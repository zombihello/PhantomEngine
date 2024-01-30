/**
 * @file
 * @addtogroup Core Core
 */

#pragma once
#include "PEBuild.h"

/**
 * @ingroup Core
 * @brief Signed int 8-bit
 */
typedef	signed char			int8;

/**
 * @ingroup Core
 * @brief Signed int 16-bit
 */
typedef	short				int16;

/**
 * @ingroup Core
 * @brief Signed int 32-bit
 */
typedef	int					int32;

/**
 * @ingroup Core
 * @brief Signed int 64-bit
 */
typedef	long long			int64;

/**
 * @ingroup Core
 * @brief Unsigned int 8-bit
 */
typedef	unsigned char		uint8;

/**
 * @ingroup Core
 * @brief Unsigned int 16-bit
 */
typedef	unsigned short		uint16;

/**
 * @ingroup Core
 * @brief Unsigned int 32-bit
 */
typedef	unsigned int		uint32;

/**
 * @ingroup Core
 * @brief Unsigned int 64-bit
 */
typedef	unsigned long long	uint64;

/**
 * @ingroup Core
 * @brief Unsigned int 8-bit
 */
typedef	uint8		        byte;

/**
 * @ingroup Core
 * @brief ANSI char
 */
typedef char				achar;

/**
 * @ingroup Core
 * @brief Unicode char
 */
typedef wchar_t				tchar;

#if PLATFORM_64BIT
    /**
     * @ingroup Core
     * @brief Pointer type
     */
    typedef int64           ptrint;

    /**
     * @ingroup Core
     * @brief Unsigned pointer type
     */
    typedef uint64          uptrint;
#else
    #error Unknown bit platform
#endif // PLATFORM_64BIT