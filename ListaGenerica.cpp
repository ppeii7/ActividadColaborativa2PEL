//
//
#include "ListaGenerica.h"
#include <iostream>

template<typename T>
ListaGenerica<T>::ListaGenerica() {
    this->length = 0;
}

template<typename T>
void ListaGenerica<T>::add(T nuevo) {
    if (length < 50) {
        this->almacen[length++]=nuevo;
    } else {
        std::cout << "Lista llena" << std::endl;
    }
}

template<typename T>
void ListaGenerica<T>::remove(int posicion) {
    if (posicion < 0 || posicion >= length) {
        std::cout << "Posicion invalida" << std::endl;
    }else {
        for (int i = posicion; i < length - 1; i++) {
            almacen[i] = almacen[i + 1];
        }
        length--;
    }
}

template<typename T>
int ListaGenerica<T>::getLength() {
    return length;
}

template<typename T>
T& ListaGenerica<T>::at(int position) {
    int posicionFinal = 0;

    if ((position >= 0 && position < length) || position == 49) {
        posicionFinal = position;
    } else {
        std::cout << "Posicion invalida" << std::endl;
    }

    return almacen[posicionFinal];
}

template<typename T>
void ListaGenerica<T>::recorrer() {
    for (int i = 0; i < length; i++) {
        std::cout << i <<": " <<almacen[i] << std::endl;
    }
}