workspace "Ice"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Ice/vendor/GLFW/include"
IncludeDir["Glad"] = "Ice/vendor/Glad/include"
IncludeDir["imgui"] = "Ice/vendor/imgui"
IncludeDir["glm"] = "Ice/vendor/glm"


-- include premake5.lua of GLFW
include "Ice/vendor/GLFW"
include "Ice/vendor/Glad"
include "Ice/vendor/imgui"

	
project "Ice"
	location "Ice"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "icepch.h"
	pchsource "Ice/src/icepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}


	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ICE_PLATFORM_WINDOWS",
			"ICE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	
	filter "configurations:Debug"
		defines "ICE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ICE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ICE_DIST"
		runtime "Release"
		optimize "on" 
		
		
		

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ice/vendor/spdlog/include",
		"Ice/src",
		"Ice/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Ice"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ICE_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "ICE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ICE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ICE_DIST"
		runtime "Release"
		optimize "on"
