cmake_minimum_required(VERSION 4.1)
project(Kedy C)

set(CMAKE_C_STANDARD 17)

add_executable(Kedy src/main.c
        headers/fenster.h
        headers/renderer.h
        src/renderer.c
        globals.h
        headers/input_manager.h
        src/input_manager.c
        headers/simulator.h
        src/simulator.c
)
