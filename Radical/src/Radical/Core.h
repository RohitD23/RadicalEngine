#pragma once

#ifdef RL_PLATFORM_WINDOWS
	#ifdef RL_BUILD_DLL
		#define RL_API __declspec(dllexport)
	#else
		#define RL_API __declspec(dllimport)
	#endif
#else
	#error Radical Only Supports Windows.
#endif 

#ifdef RL_ENABLE_ASSERTS
#define RL_ASSERT(x, ...) { if(!(x)) { RL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define RL_CORE_ASSERT(x, ...) { if(!(x)) { RL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define RL_ASSERT(x, ...)
#define RL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)