#pragma once

#ifdef ICE_PLATFORM_WINDOWS
	#ifdef ICE_BUILD_DLL
		#define ICE_API __declspec(dllexport)
	#else
		#define ICE_API __declspec(dllimport)
	#endif


#else
	#error ICE only supports windows for now

#endif


#ifdef ICE_ENABLE_ASSERT
	#define ICE_CORE_ASSERT(x, ...) { if (!(x)) { ICE_CORE_ERROR("Assertion Failed at: {0}: ", __VA_ARGS__); __debugbreak(); } }
	#define ICE_ASSERT(x, ...) { if (!(x)) { ICE_ERROR("Assertion Failed at {0}: ", __VA_ARGS__); __debugbreak(); } }
#else
	#define ICE_CORE_ASSERT(x, ...)
	#define ICE_ASSERT(x, ...)

#endif


// 1 * (2 ^ x)
#define BIT(x) (1 << x)
