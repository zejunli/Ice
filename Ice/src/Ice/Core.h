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
