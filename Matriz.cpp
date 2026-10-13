//
// Created by jadel on 07/10/2026.
//

#include "Matriz.h"
#include <iostream>

template <typename T>
Matriz<T>::Matriz() { // Con constructor vacio se hace una matriz 3x3
    this->filas = 3;
    this->columnas= 3 ;
    for (int i = 1; i <= this->filas; i++) {
        ListaGenerica<T> fila;
        matriz.add(fila);
        for (int j = 1; j <= this->columnas; j++) {
            matriz.at(i).add(1); // Pongo todos los valores de la matriz a 1
        }
    }
}

template <typename T>
Matriz<T>::Matriz(int filas) { // Constructor con la misma cantidad de filas y columnas
    this->filas = filas;
    this->columnas = filas;
    for (int i = 1; i <= this->filas; i++) {
        ListaGenerica<T> fila;
        matriz.add(fila);
        for (int j = 1; j <= this->columnas; j++) {
            matriz.at(i).add(1); // Pongo todos los valores de la matriz a 1
        }
    }
}

template <typename T>
Matriz<T>::Matriz(int filas, int columnas) { // Constructor con filas y columnas determinadas
    this->filas = filas;
    this->columnas = columnas;
    for (int i = 1; i <= this->filas; i++) {
        ListaGenerica<T> fila;
        matriz.add(fila);
        for (int j = 1; j <= this->columnas; j++) {
            matriz.at(i).add(1); // Pongo todos los valores de la matriz a 1
        }
    }
}


template <typename T>
void Matriz<T>::printMatriz() {
    for (int i = 1; i <= filas; i++) {
        for (int j = 1; j <= columnas; j++) {
            std::cout << this->getFromM(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matriz<T>::modMatriz(int fila, int columna, T valor) {
    matriz.at(fila).modLista(columna, valor); // Para modificar desde esta clase modifico la Lista puesta en la fila que quiero
}

template <typename T>
T& Matriz<T>::getFromM(int fila, int columna) {
    return matriz.at(fila).at(columna); // Para sacar un valor desde esta clase saco el valor de la Lista puesto es la fila que quiero
}

template <typename T>
int Matriz<T>::getFilas() {
    return filas;
}

template <typename T>
int Matriz<T>::getColumnas() {
    return columnas;
}