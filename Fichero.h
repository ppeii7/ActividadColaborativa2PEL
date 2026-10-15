//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_FICHERO_H
#define ACTIVIDADCOLABORATIVA2_FICHERO_H


#include <string>

class Fichero {
private:
    std::string ruta;
    std::string contenido;
    bool cargado;
public:
    Fichero();
    Fichero(std::string ruta);
    bool estaCargado();
    std::string getRuta();
    std::string getContenido();
};

#endif //ACTIVIDADCOLABORATIVA2_FICHERO_H
