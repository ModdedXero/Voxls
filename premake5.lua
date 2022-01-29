workspace "Voxls"
	architecture "x64"
	startproject  "Voxls"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "Voxls/vendor/GLFW/include"
IncludeDir["GLM"] = "Voxls/vendor/glm"
IncludeDir["Vulkan"] = "Voxls/vendor/vulkan/include"

include "Voxls/vendor/GLFW"
	
project "Voxls"
	location "Voxls/src"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Voxls/src/**.h",
		"Voxls/src/**.cpp",
		"Voxls/vendor/glm/**.hpp",
		"Voxls/vendor/glm/**.inl",
	}

	includedirs
	{
		"Voxls/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.Vulkan}"
	}

	links
	{
		"GLFW",
		"Voxls/vendor/vulkan/lib/vulkan-1.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VX_DIST"
		optimize "On"