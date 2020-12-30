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

link_directories(minhook/build/Release)

add_library(Infernus_V2 SHARED
        Infernus/Client/Commands/SpamCommand.cpp
        Infernus/Client/Commands/SpamCommand.h
        Infernus/Client/Commands/SpeedCommand.cpp
        Infernus/Client/Commands/SpeedCommand.h
        Infernus/Client/Commands/TestCommand.cpp
        Infernus/Client/Commands/TestCommand.h
        Infernus/Client/Hooks/Actor.h
        Infernus/Client/Hooks/ClientInstance.h
        Infernus/Client/Hooks/GameMode.h
        Infernus/Client/Hooks/KeyItem.h
        Infernus/Client/Hooks/LoopbackPacketSender.h
        Infernus/Client/Hooks/MouseItem.h
        Infernus/Client/Hooks/RenderContext.h
        Infernus/Client/Modules/AirJump.cpp
        Infernus/Client/Modules/AirJump.h
        Infernus/Client/Modules/ArrayList.cpp
        Infernus/Client/Modules/ArrayList.h
        Infernus/Client/Modules/AutoSprint.cpp
        Infernus/Client/Modules/AutoSprint.h
        Infernus/Client/Modules/Clickgui.cpp
        Infernus/Client/Modules/Clickgui.h
        Infernus/Client/Modules/ClickTP.cpp
        Infernus/Client/Modules/ClickTP.h
        Infernus/Client/Modules/Freecam.cpp
        Infernus/Client/Modules/Freecam.h
        Infernus/Client/Modules/Hitbox.cpp
        Infernus/Client/Modules/Hitbox.h
        Infernus/Client/Modules/Instabreak.cpp
        Infernus/Client/Modules/Instabreak.h
        Infernus/Client/Modules/Jesus.cpp
        Infernus/Client/Modules/Jesus.h
        Infernus/Client/Modules/Jetpack.cpp
        Infernus/Client/Modules/Jetpack.h
        Infernus/Client/Modules/Killaura.cpp
        Infernus/Client/Modules/Killaura.h
        Infernus/Client/Modules/NoPacket.cpp
        Infernus/Client/Modules/NoPacket.h
        Infernus/Client/Modules/Nuker.cpp
        Infernus/Client/Modules/Nuker.h
        Infernus/Client/Modules/Spammer.cpp
        Infernus/Client/Modules/Spammer.h
        Infernus/Client/Modules/Speed.cpp
        Infernus/Client/Modules/Speed.h
        Infernus/Client/Modules/TabGUI.cpp
        Infernus/Client/Modules/TabGUI.h
        Infernus/Client/Modules/TestModule.cpp
        Infernus/Client/Modules/TestModule.h
        Infernus/Client/Modules/Triggerbot.cpp
        Infernus/Client/Modules/Triggerbot.h
        Infernus/Client/Modules/MemeplexDisablerxd.cpp
        Infernus/Client/Modules/MemeplexDisablerxd.h
        Infernus/Client/Modules/Fly.cpp
        Infernus/Client/Modules/Fly.h
        Infernus/Client/Modules/Velocity.cpp
        Infernus/Client/Modules/Velocity.h
        Infernus/Client/Modules/Uninject.cpp
        Infernus/Client/Modules/Uninject.h
        Infernus/Client/ClientManager.cpp
        Infernus/Client/ClientManager.h
        Infernus/Other/Module.cpp
        Infernus/Other/Module.h
        Infernus/Other/Utils.cpp
        Infernus/Other/Utils.h
        Infernus/SDK/Classes/Actor.h
        Infernus/SDK/Classes/ClientInstance.h
        Infernus/SDK/Classes/GameMode.h
        Infernus/SDK/Classes/LocalPlayer.h
        Infernus/SDK/Classes/LoopbackPacketSender.h
        Infernus/SDK/Classes/MinecraftUIRenderContext.h
        Infernus/SDK/Classes/MultiPlayerLevel.h
        Infernus/SDK/Classes/Packet.h
        Infernus/SDK/Classes/TextHolder.h
        Infernus/SDK/Minecraft.h
        Infernus/Infernus.cpp)

target_link_libraries(Infernus_V2 PRIVATE minhook.x64)
target_include_directories(Infernus_V2 PRIVATE minhook/include)
