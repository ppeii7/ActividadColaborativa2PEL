//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
#define ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
#include "Matriz.h"

template<typename T>
class CalculadoraAvanzada {
public:
    CalculadoraAvanzada();
    T suma(T a, T b);
    Matriz<T> suma(Matriz<T> a, Matriz<T> b);
    T resta(T a, T b);
    Matriz<T> resta(Matriz<T> a, Matriz<T> b);
    T multiplica(T a, T b);
    Matriz<T> multiplica(Matriz<T> a, Matriz<T> b);
    T division(T a, T b);
    Matriz<T> traspuesta(Matriz<T> matriz);
    T determinante(Matriz<T> matriz);
    Matriz<T> subMatriz(Matriz<T> matriz1, int columnaFuera);

};


#endif //ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
