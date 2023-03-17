cmake_minimum_required(VERSION 3.23)
project(TAD_Colectie)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories("Proiect C++")

include_directories("Proiect C++/Colectie (cu rel)")

include_directories("Teste (cu relatie)")

add_executable(TAD_Colectie
        "Proiect C++/Colectie (cu rel)/App.cpp"
        "Proiect C++/Colectie (cu rel)/Colectie.cpp"
        "Proiect C++/Colectie (cu rel)/Colectie.h"
        "Proiect C++/Colectie (cu rel)/IteratorColectie.cpp"
        "Proiect C++/Colectie (cu rel)/IteratorColectie.h"
        "Teste (cu relatie)/TestExtins.cpp"
        "Teste (cu relatie)/TestExtins.h"
        "Teste (cu relatie)/TestScurt.cpp"
        "Teste (cu relatie)/TestScurt.h"
        )
