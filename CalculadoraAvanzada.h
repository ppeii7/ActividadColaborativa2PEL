//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
#define ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
#include "Matriz.h"
#include "Usuario.h"

template<typename T>
class CalculadoraAvanzada {
private:
    Matriz<T> subMatriz(Matriz<T> matriz1, int columnaFuera); // Lo pongo privado porque es un metodo que solo se llamara dentro de esta clase, especificamente dentro de determinante
public:
    CalculadoraAvanzada();
    void mostrarUsos();
    T suma(T a, T b);
    Matriz<T> sumaMatriz(Matriz<T> a, Matriz<T> b);
    T resta(T a, T b);
    Matriz<T> restaMatriz(Matriz<T> a, Matriz<T> b);
    T multiplica(T a, T b);
    Matriz<T> multiplicaMatriz(Matriz<T> a, Matriz<T> b);
    T division(T a, T b);
    Matriz<T> traspuesta(Matriz<T> matriz);
    T determinante(Matriz<T> matriz);
};

#include "CalculadoraAvanzada.cpp" // Me sale que lo tengo que meter pero si lo meto me da error en el otro archivo
#endif //ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
