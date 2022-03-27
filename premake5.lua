workspace "Radical"
    architecture "x64"
    startproject "SandBox"

    configurations
    {
        "Debug",
        "Release"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Radical/vendor/GLFW/include"

include "Radical/vendor/GLFW"

project "Radical"
    location "Radical"
    kind "SharedLib"
    staticruntime "Off"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    pchheader "rlpch.h"
    pchsource "Radical/src/rlpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"


    defines
    {
        "RL_PLATFORM_WINDOWS",
        "RL_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/SandBox")
    }

    filter "configurations:Debug"
        defines 
        {
            "RL_DEBUG",
            "RL_ENABLE_ASSERTS"
        }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "RL_RELEASE"
        runtime "Release"
        optimize "On"
    
project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    staticruntime "Off"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir    ("bin-int/".. outputDir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Radical/vendor/spdlog/include",
        "Radical/src",
        "Radical/vendor/GLFW/include"
    }

    links
    {
        "Radical"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    defines
    {
        "RL_PLATFORM_WINDOWS",
    }

    filter "configurations:Debug"
        defines "RL_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "RL_RELEASE"
        runtime "Release"
        optimize "On"
