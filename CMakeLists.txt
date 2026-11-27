cmake_minimum_required(VERSION 4.3)
project(CrazyEights)

set(CMAKE_CXX_STANDARD 23)

option(COMMANDLINE, "Enable Command Line only" ON)
option(BOT, "simulate player play" OFF)



add_executable(CrazyEights
        src/Player.cpp
       include/Player.h
        include/Card.h
        src/Deck.cpp
        include/Deck.h
        src/GameState.cpp
        include/GameState.h
include/vendor/enum.h)

target_include_directories(CrazyEights PRIVATE include)

if(BOT)
    target_sources(CrazyEights PRIVATE src/interfaces/Bot.cpp)
elseif(COMMANDLINE)
    target_sources(CrazyEights PRIVATE src/interfaces/CommandLine.cpp)
else()
    message(FATAL_ERROR "Either BOT or COMMANDLINE must be ON.")
endif()