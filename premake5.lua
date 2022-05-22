workspace "Ice"
	architecture "x64"

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

-- include premake5.lua of GLFW
include "Ice/vendor/GLFW"
include "Ice/vendor/Glad"
include "Ice/vendor/imgui"

	
project "Ice"
	location "Ice"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "icepch.h"
	pchsource "Ice/src/icepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}"
	}


	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ICE_PLATFORM_WINDOWS",
			"ICE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	
	filter "configurations:Debug"
		defines "ICE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ICE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ICE_DIST"
		buildoptions "/MD"
		optimize "On" 



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Ice/src"
	}

	links
	{
		"Ice"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ICE_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "ICE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ICE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ICE_DIST"
		buildoptions "/MD"
		optimize "On" 
