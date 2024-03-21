cmake_minimum_required(VERSION 3.27)
project(Projekt_Labirynt C)

set(CMAKE_C_STANDARD 11)

add_executable(Projekt_Labirynt
        czytanieZPliku.c
        wczyt.h
        wczyt.c)
