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
    Matriz<ListaGenerica<T>> subMatriz(Matriz<ListaGenerica<T>> matriz1, int columnaFuera); // Lo pongo privado porque es un metodo que solo se llamara dentro de esta clase, especificamente dentro de determinante
public:
    CalculadoraAvanzada();
    void mostrarUsos();
    T suma(T a, T b);
    Matriz<ListaGenerica<T>> suma(Matriz<ListaGenerica<T>> a, Matriz<ListaGenerica<T>> b);
    T resta(T a, T b);
    Matriz<ListaGenerica<T>> resta(Matriz<ListaGenerica<T>> a, Matriz<ListaGenerica<T>> b);
    T multiplica(T a, T b);
    Matriz<ListaGenerica<T>> multiplica(Matriz<ListaGenerica<T>> a, Matriz<ListaGenerica<T>> b);
    T division(T a, T b);
    Matriz<ListaGenerica<T>> traspuesta(Matriz<ListaGenerica<T>> matriz);
    T determinante(Matriz<ListaGenerica<T>> matriz);
};

// #include "CalculadoraAvanzada.cpp" // Me sale que lo tengo que meter pero si lo meto me da error en el otro archivo
#endif //ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
