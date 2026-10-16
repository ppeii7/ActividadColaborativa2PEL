#include "ListaGenerica.h"
#include <iostream>


template<typename T>
ListaGenerica<T>::ListaGenerica() {
    this->length = 1;
    for (int i = 0; i < 50; i++) {
        almacen[i] = T();
    }
}

template<typename T>
bool ListaGenerica<T>::add(T nuevo) {
    bool retorno = false;
    if (length < 50) {
        this->almacen[length++] = nuevo;
        retorno = true;
    } else {
        std::cout << "Lista llena" << std::endl;
    }
    return retorno;
}

template<typename T>
void ListaGenerica<T>::remove(int posicion) {
    if (posicion < 1 || posicion >= length) {
        std::cout << "Posicion invalida" << std::endl;
    } else {
        for (int i = posicion; i < length - 1; i++) {
            almacen[i] = almacen[i + 1];
        }
        length--;
        almacen[length] = T();
    }
}

template<typename T>
int ListaGenerica<T>::getLength(){
    return length - 1;
}

template<typename T>
bool ListaGenerica<T>::estaLlena(){
    return length >= 50;
}

template<typename T>
T& ListaGenerica<T>::at(int position) {
    if (position < 0 || position >= length) {
        std::cout << "Posicion invalida" << std::endl;
        position = 0;
    }
    return almacen[position];
}

template<typename T>
void ListaGenerica<T>::recorrer() {
    for (int i = 0; i < length; i++) {
        std::cout << i << ": " << almacen[i] << std::endl;
    }
}

template<typename T>
void ListaGenerica<T>::modLista(int posicion, T valor) {
    if (posicion > 0 && posicion < length) {
        almacen[posicion] = valor;
    } else {
        std::cout << "Posicion invalida" << std::endl;
    }
}
