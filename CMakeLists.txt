cmake_minimum_required(VERSION 4.3)
project(ActividadColaborativa2)

set(CMAKE_CXX_STANDARD 23)

add_executable(ActividadColaborativa2 main.cpp
        CalculadoraAvanzada.cpp
        CalculadoraAvanzada.h
        Usuario.cpp
        Usuario.h
        Estudiante.cpp
        Estudiante.h
        Profesor.cpp
        Profesor.h
        Fichero.cpp
        Fichero.h
        Matriz.cpp
        Matriz.h
)
