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
    Usuario dueño;
    Matriz<T> subMatriz(Matriz<T> matriz1, int columnaFuera); // Lo pongo privado porque es un metodo que solo se llamara dentro de esta clase, especificamente dentro de determinante
public:
    CalculadoraAvanzada(Usuario dueño);
    void mostrarUsos();
    T suma(T a, T b);
    Matriz<T> suma(Matriz<T> a, Matriz<T> b);
    T resta(T a, T b);
    Matriz<T> resta(Matriz<T> a, Matriz<T> b);
    T multiplica(T a, T b);
    Matriz<T> multiplica(Matriz<T> a, Matriz<T> b);
    T division(T a, T b);
    Matriz<T> traspuesta(Matriz<T> matriz);
    T determinante(Matriz<T> matriz);
};


#endif //ACTIVIDADCOLABORATIVA2_CALCULADORAAVANZADA_H
