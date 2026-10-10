//
//

#ifndef ACTIVIDADCOLABORATIVA2_LISTAGENERICA_H
#define ACTIVIDADCOLABORATIVA2_LISTAGENERICA_H

template <typename T>
class ListaGenerica {
private:
    T almacen[50];
    int length;
public:
    ListaGenerica();
    void add(T nuevo);
    void remove(int posicion);
    int getLength();
    T& at(int position);
    void recorrer();
};

#include "ListaGenerica.cpp"
#endif //ACTIVIDADCOLABORATIVA2_LISTAGENERICA_H
