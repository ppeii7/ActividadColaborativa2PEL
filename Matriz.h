//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_MATRIZ_H
#define ACTIVIDADCOLABORATIVA2_MATRIZ_H
#include "ListaGenerica.h"


template <typename T>
class Matriz {
private:
    int filas, columnas;
    ListaGenerica<T> matriz[50]; // Hago una lista de listas
public:
    Matriz();
    Matriz(int filas);
    Matriz(int filas, int columnas);
    void printMatriz();
    void modMatriz(int fila, int columna, T valor); // Funcion para modificar desde la clase Matriz
    T getFromM(int fila, int columna); // Funcion para sacar un valor desde la clase Matriz
    int getFilas();
    int getColumnas();
};


#endif //ACTIVIDADCOLABORATIVA2_MATRIZ_H
