//
//

#ifndef ACTIVIDADCOLABORATIVA2_LISTAGENERICA_H
#define ACTIVIDADCOLABORATIVA2_LISTAGENERICA_H

template<typename T>
class ListaGenerica {
private:
    T almacen[50]; //La posicion 0 del los contenedores debe d eesta siempre vacia
    int length;

public:
    ListaGenerica();
    bool add(T nuevo);//devuelve true/false, en base a si ha sido añadido correctamente
    void remove(int posicion);
    int getLength();
    bool estaLlena();
    T& at(int position);
    void recorrer();
    void modLista(int posicion, T valor);
};

#include "ListaGenerica.cpp"
#endif //ACTIVIDADCOLABORATIVA2_LISTAGENERICA_H
