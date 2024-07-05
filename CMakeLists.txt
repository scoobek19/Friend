cmake_minimum_required(VERSION 3.21)
project(projaka)

set(CMAKE_CXX_STANDARD 17)

add_executable(projaka main.cpp interfejs/Intr2.cpp interfejs/Intr2.h znajomy/Osoba.cpp znajomy/Osoba.h znajomy/Ksiazka.cpp znajomy/Ksiazka.h narzedzia/utils.cpp narzedzia/utils.h
        narzedzia/regex.cpp
        narzedzia/regex.h
        znajomy/wypozyczenie.h)
