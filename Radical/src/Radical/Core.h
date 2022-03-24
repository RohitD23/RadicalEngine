#pragma once

#ifdef RL_PLATFROM_WINDOWS
	#ifdef RL_BUILD_DLL
		#define RL_API __declspec(dllexport)
	#else
		#define RL_API __declspec(dllimport)
	#endif
#else
	#error Radical Only Supports Windows.
#endif 

