function LinkSDL2()
    includedirs     {
        extSDL2 .. "/include/"
    }

    filter "platforms:Win64"
        links       {
            extSDL2 .. "/lib/Win64/SDL2.lib"
        }

        postbuildcommands    {
            "{COPY} " .. extSDL2 .. "/lib/Win64/SDL2.dll " .. binariesDir .. outputDir .. "/"
        }
    filter {}
end