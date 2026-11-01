cmake_minimum_required(VERSION 4.3)
project(CrazyEights)

set(CMAKE_CXX_STANDARD 20)

add_executable(CrazyEights src/main.cpp
        include/Player.h
        src/Player.cpp
       include/Player.h
        include/Card.h
        src/Deck.cpp
        include/Deck.h)
