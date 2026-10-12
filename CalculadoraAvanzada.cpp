//
// Created by jadel on 07/10/2026.
//

#include "CalculadoraAvanzada.h"

template<typename T>
CalculadoraAvanzada<T>::CalculadoraAvanzada(Usuario dueño) {
    this->dueño = dueño;
    this->mostrarUsos();
}

template<typename T>
void CalculadoraAvanzada<T>::mostrarUsos() {
    std::cout<< "Esta calculadora puede hacer lo siguiente: \n\t Suma, resta, multiplicacion y division de numeros \n\t Suma, resta, multiplicacion de matrices \n\t Traspuesta y determinante de una matriz" << std::endl;
}

template<typename T>
T CalculadoraAvanzada<T>::suma(T a, T b) {
    return a + b;
}
template<typename T>
Matriz<T> CalculadoraAvanzada<T>::suma(Matriz<T> matriz1, Matriz<T> matriz2) {
    Matriz<T>* result = new Matriz<T>(matriz1.getFilas(), matriz1.getColumnas());
    if (matriz2.getFilas() != matriz1.getFilas() || matriz2.getColumnas() != matriz1.getColumnas()) {
        std::cout << "Matrices de distinto tamaño no se pueden sumar" << std::endl; // Si los tamaños no son compatibles para la suma devuelvo la matriz llena de unos
    } else {
        for (int i = 0; i < matriz1.getFilas(); i++) {
            for (int j = 0; j < matriz1.getColumnas(); j++) {
                result->modMatriz(i, j, (matriz1.getFromM(i,j) + matriz2.getFromM(i, j)));
            }
        }
    }
    return *result;
}

template<typename T>
T CalculadoraAvanzada<T>::resta(T a, T b) {
    return a - b;
}

template<typename T>
Matriz<T> CalculadoraAvanzada<T>::resta(Matriz<T> matriz1, Matriz<T> matriz2) {
    Matriz<T>* result = new Matriz<T>(matriz1.getFilas(), matriz1.getColumnas());
    if (matriz2.getFilas() != matriz1.getFilas() || matriz2.getColumnas() != matriz1.getColumnas()) {
        std::cout << "Matrices de distinto tamaño no se pueden restar" << std::endl; // Si los tamaños no son compatibles para la resta devuelvo la matriz llena de unos
    } else {
        for (int i = 0; i < matriz1.getFilas(); i++) {
            for (int j = 0; j < matriz1.getColumnas(); j++) {
                result->modMatriz(i, j, (matriz1.getFromM(i,j) - matriz2.getFromM(i, j)));
            }
        }
    }
    return *result;
}

template<typename T>
T CalculadoraAvanzada<T>::multiplica(T a, T b) {
    return a * b;
}

template<typename T>
Matriz<T> CalculadoraAvanzada<T>::multiplica(Matriz<T> matriz1, Matriz<T> matriz2) {
    Matriz<T>* result = new Matriz<T>(matriz1.getFilas(), matriz2.getColumnas()); // Creo una matriz resultado con el tamaño de filas que la primera Matriz y las columnas de la segunda
    if (matriz2.getFilas() != matriz1.getColumnas()) {
        std::cout<< "No se pueden multiplicar" << std::endl; // Si sus tamaños son incompatibles devuelvo una matriz llena de unos
    }
    else {
        // i = iterador de las filas de matriz1
        for (int i = 0; i < matriz1.getFilas(); i++) {
            // j = iterador de las columnas de matriz2
            for (int j = 0; j < matriz2.getColumnas(); j++) {
                T suma = 0;
                // k = iterador de la dimensión compartida (columnas de matriz1 / filas de matriz2)
                for (int k = 0; k < matriz1.getColumnas(); k++) {
                    // Se multiplica fila por columna y se acumula
                    suma = suma + (matriz1.getFromM(i, k) * matriz2.getFromM(k,j));
                }
                // Se asigna el total a la coordenada exacta [i][j]
                result->modMatriz(i, j, suma);
            }
        }
    }
    return *result;
}

template<typename T>
T CalculadoraAvanzada<T>::division(T a, T b) {
    return a / b;
}

template<typename T>
Matriz<T> CalculadoraAvanzada<T>::traspuesta(Matriz<T> matriz) {
    Matriz<T>* result = new Matriz<T>(matriz.getColumnas(), matriz.getFilas());
    for (int i = 0; i < matriz.getFilas(); i++) {
        for (int j = 0; j < matriz.getColumnas(); j++) {
            result->modMatriz(j, i, matriz.getFromM(i, j));
        }
    }
    return *result;
}

template<typename T>
T CalculadoraAvanzada<T>::determinante(Matriz<T> matriz) {
    T resultado = 0;
    if (matriz.getFilas() == matriz.getColumnas()) {
        const int n = matriz.getFilas();

        switch(n) {
            case 1: // Si solo tiene una fila, igualo resultado a ese valor
                resultado = matriz.getFromM(0, 0);
                break;
            case 2: // Si tiene dos filas igualo resultado a la multiplicacion en diagonal de izq a derecha menos la otra diagonal
                resultado = matriz.getFromM(0, 0) * matriz.getFromM(1, 1) - matriz.getFromM(1, 0) * matriz.getFromM(0,1);
                break;
            default:
                int signo = 1;
                Matriz<T> subM;
                for (int i = 0; i < n; i++) {
                    subM = this->subMatriz(matriz, i); // Saco submatriz quitando la fila 0 y la columna i
                    resultado += signo * matriz.getFromM(0, i) * this->determinante(subM); // Le sumo la multiplicacion del signo por el valor de la fila 0 y columna i por el determinante de la submatriz
                    signo*=-1; // Cambio el signo para la siguiente iteracion
                }
        }
    } else {
        std::cout<< "No es cuadratica, por lo que no se puede sacar su determinante" << std::endl;
    }
    return resultado;
}

template <typename T>
Matriz<T> CalculadoraAvanzada<T>::subMatriz(Matriz<T> matriz1, int columnaFuera) {
    Matriz<T>* subMatriz = new Matriz<T>(matriz1.getFilas()-1, matriz1.getColumnas()-1);
    bool columnaFueraPasada = false;
    for (int i = 1; i < matriz1.getFilas(); i++) { // Empieza desde 1 porque siempre estoy quitando la fila 0
        for (int j = 0; j < matriz1.getColumnas(); j++) {
            if (j != columnaFuera && columnaFueraPasada == false) { // Si todavia no hemos pasado la columna que queremos quitar
                subMatriz->modMatriz(i-1, j, matriz1.getFromM(i,j));
            } else if (j!= columnaFuera && columnaFueraPasada == true) { // Si ya pasamos la columna que queriamos quitar le resto 1 a j de la submatriz para que no se vaya fuera de su rango
                subMatriz->modMatriz(i-1, j-1, matriz1.getFromM(i,j));
            } else { // Si j == a la columna que queremos quitar, ponemos que ya pasamos esa columna
                columnaFueraPasada = true;
            }
        }
        columnaFueraPasada = false; // Reiniciamos el booleano para la siguiente iteracion de j
    }
    return *subMatriz;
}
