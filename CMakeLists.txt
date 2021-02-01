cmake_minimum_required(VERSION 3.17)
project(Infernus_V2)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
    )
endif()

link_directories(minhook/Release)

file(GLOB source
        Infernus/Client/Commands/*.cpp
        Infernus/Client/Commands/*.h
        Infernus/Client/Hooks/*.cpp
        Infernus/Client/Hooks/*.h
        Infernus/Client/Modules/*.cpp
        Infernus/Client/Modules/*.h
        Infernus/Client/*.cpp
        Infernus/Client/*.h
        Infernus/Other/*.cpp
        Infernus/Other/*.h
        Infernus/SDK/*.cpp
        Infernus/SDK/*.h
        Infernus/SDK/Classes/*.cpp
        Infernus/SDK/Classes/*.h
        Infernus/*.cpp
        Infernus/*.h
)

add_library(Infernus_V2 SHARED ${source})

target_link_libraries(Infernus_V2 PRIVATE minhook.x64)
target_include_directories(Infernus_V2 PRIVATE 
        minhook/include
        packages/nlohmann.json.3.9.1/build/native/include
)
