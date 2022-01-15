cmake_minimum_required(VERSION 3.15)
project(SportsBetManager-Improved)

set(CMAKE_CXX_STANDAR_17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
        SportsBet.cpp SportsBet.h Date.cpp Date.h Spread.cpp Spread.h Prop.cpp Prop.h OverUnder.cpp OverUnder.h UserInterface.cpp SportsBetManager.cpp SportsBetManager.h)

add_executable(SportsBetManager-Improved ${SOURCE_FILES})