//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_PROFESOR_H
#define ACTIVIDADCOLABORATIVA2_PROFESOR_H
#include "Estudiante.h"
#include "ListaGenerica.h"
#include "Usuario.h"


class Profesor : public Usuario {

private:
    ListaGenerica<Estudiante> clase;
public:

    Profesor();
    Profesor(std::string id, std::string nombre, std::string apellido);



};


#endif //ACTIVIDADCOLABORATIVA2_PROFESOR_H
