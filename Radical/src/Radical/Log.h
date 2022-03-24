#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "Core.h"

namespace Radical {
	class RL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define RL_CORE_TRACE(...)  Radical::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RL_CORE_INFO(...)   Radical::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RL_CORE_WARN(...)   Radical::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RL_CORE_ERROR(...)  Radical::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RL_CORE_FATAL(...)  Radical::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define RL_TRACE(...)  Radical::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RL_INFO(...)   Radical::Log::GetClientLogger()->info(__VA_ARGS__)
#define RL_WARN(...)   Radical::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RL_ERROR(...)  Radical::Log::GetClientLogger()->error(__VA_ARGS__)
#define RL_FATAL(...)  Radical::Log::GetClientLogger()->fatal(__VA_ARGS__)
