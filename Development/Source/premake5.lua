--------- GLOBAL VARIABLES -----------------	

-- Path to intermediate directory for engine and game
intermediateDir				= "%{wks.location}/"

-- Path to binaries directory
binariesDir				    = "%{wks.location}/../../../Binaries/"

-- Output directory name
outputDir			        = "%{cfg.platform}/"

-- Path to external directory
externalDir			        = "%{wks.location}/../../External/";

-- Path to externals
extSDL2			            = externalDir .. "SDL2"

-- Include modules of external libs
include( extSDL2 )

workspace "PhantomEngine"
    location( "../Intermediate/" .. _ACTION .. "/" )
    configurations 	    { "Debug", "DebugWithEditor", "Release", "ReleaseWithEditor", "Shipping" }
    platforms 		    { "Win64"}
    defaultplatform	    "Win64"

    ---------------- GLOBAL SETTINGS ---------------

    characterset 		"Unicode"
    floatingpoint 		"Fast"

    targetname( "%{prj.name}-%{cfg.platform}-%{cfg.buildcfg}" )
    targetdir( binariesDir .. outputDir )
	objdir( intermediateDir .. outputDir .. "%{prj.name}/%{cfg.buildcfg}/" )

    flags { "MultiProcessorCompile" }

    --------------- PLATFORM SETTINGS --------------

    filter "platforms:Win64"
        system 			"Windows"
        architecture 	"x64"
        cppdialect 		"C++17"
        staticruntime 	"Off"
        debugdir( binariesDir .. outputDir )

        defines 		{ "_WIN64", "PLATFORM_64BIT=1" }
	filter {}

    --------------- CONFIGURATION SETTINGS --------------

	filter "configurations:Debug*"
        defines 	        { "DEBUG=1",  "RELEASE=0", "SHIPPING=0" }
        symbols 	        "On"
        inlining            "Disabled"
        runtime 	        "Debug"

    filter "configurations:Release*"
        defines 	        { "NDEBUG", "DEBUG=0", "RELEASE=1", "SHIPPING=0" }
        optimize 	        "Speed"
		runtime 			"Release"
        inlining            "Auto"

    filter "configurations:Shipping"
        defines 	        { "NDEBUG", "DEBUG=0", "RELEASE=0", "SHIPPING=1" }
        optimize            "Speed"
		runtime 			"Release"
        inlining            "Auto"
    filter {}

    	-------------- BUILD TYPE SETTINGS -------------
	
	-- StaticLib
	filter "kind:StaticLib"
        targetdir( intermediateDir .. outputDir .. "%{prj.name}/Lib/" )
    filter { "kind:StaticLib", "platforms:Win64" }
        symbolspath( intermediateDir .. outputDir .. "%{prj.name}/Lib/%{cfg.buildtarget.basename}.pdb" )

    -- SharedLib
    filter "kind:SharedLib"
        symbolspath( intermediateDir .. outputDir .. "%{prj.name}/Lib/%{cfg.buildtarget.basename}.pdb" )
    filter {}

    --------------- PROJECT --------------

    project "ExampleGame"
        kind        "WindowedApp"
        language    "C++"
        location( intermediateDir )

        ----------- PROJECT SETTINGS --------

        includedirs         {
            "Engine/**/Include/",
            "Games/ExampleGame/Include/"
        }

        files               {
            "Engine/**/Include/**.h",
            "Engine/**/Include/**.inl",
            "Engine/**/Source/**.cpp",
            "Games/ExampleGame/Include/**.h",
            "Games/ExampleGame/Include/**.inl",
            "Games/ExampleGame/Source/**.cpp",
        }

        ---------- PLATFORM SPECIFIC SETTINGS ---------

        -- Exclude platform specific for other platforms
        filter "platforms:not Win64"
            excludes { "**/Windows/**.*" }
        filter {}

        -- Platform specific settings
        filter "platforms:Win64"
        filter {}

        --------- LINK EXTERNAL LIBS -------

        LinkSDL2()

        ------ EDITOR SETTINGS -----

        filter "configurations:*WithEditor"
            defines     { "WITH_EDITOR=1" }
        filter "configurations:not *WithEditor"
            -- If we build the engine without editor, we will need exclude all of Editor source files
            excludes    { "Engine/Editor/**.*" }
            defines     { "WITH_EDITOR=0" }
        filter {}