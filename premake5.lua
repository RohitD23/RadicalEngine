workspace "Radical"
    architecture "x64"
    startproject "SandBox"

    configurations
    {
        "Debug",
        "Release"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Radical"
    location "Radical"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"


    defines
    {
        "RL_PLATFROM_WINDOWS",
        "RL_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/SandBox")
    }

    filter "configurations:Debug"
        defines "RL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RL_RELEASE"
        optimize "On"
    
project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
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
        "Radical/src"
    }

    links
    {
        "Radical"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    defines
    {
        "RL_PLATFROM_WINDOWS",
    }

    filter "configurations:Debug"
        defines "RL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RL_RELEASE"
        optimize "On"
