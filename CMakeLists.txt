cmake_minimum_required(VERSION 3.26)
project(ZombieNoSpaghetti)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZombieNoSpaghetti main.cpp
        Header/WindowConfig.h
        Source/WindowConfig.cpp
        Header/Player.h
        Source/Player.cpp
        Header/Collision.h
        Source/Collision.cpp
        Header/BitMap.h
        Source/BitMap.cpp
        Header/Button.h
        Source/Button.cpp
        Header/CustomButtons.h
        Source/CustomButtons.cpp
        Header/Animations.h
        Source/Animations.cpp
        Source/Arrow.cpp
        Header/Arrow.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Users/coons/CLionProjects/ZombieNoSpaghetti/include/SFML)
target_link_libraries(ZombieNoSpaghetti sfml-system sfml-window sfml-graphics sfml-audio)
