#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
# env.Append(CPPPATH=["src/"])

godot_cpp_path = "godot-cpp"
env.Append(
    CPPPATH=[
        "src/",
        godot_cpp_path + "/include",
        godot_cpp_path + "/include/core",
        godot_cpp_path + "/include/gen",
    ]
)
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "game/bin/libEnhancedInputModule.{}.{}.framework/libEnhancedInputModule.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "game/bin/libEnhancedInputModule.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "game/bin/libEnhancedInputModule.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "game/bin/libEnhancedInputModule.{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

# Set library as the default build target
Default(library)

