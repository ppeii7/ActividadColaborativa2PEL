//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_PROFESOR_H
#define ACTIVIDADCOLABORATIVA2_PROFESOR_H
#include "Estudiante.h"
#include "ListaGenerica.h"
#include "Usuario.h"


class Profesor : public Usuario{

private:
ListaGenerica<std::string> clase;



public:
Profesor();
Profesor(std::string id, std::string nombre, std::string apellido);

bool inscribirEstudiante(std::string idEstudiante);
bool quitarEstudiante(std::string idEstudiante);
bool tieneEstudiante(std::string idEstudiante);
int getNumEstudiantes();
std::string getIdEstudiante(int pos);
};


#endif //ACTIVIDADCOLABORATIVA2_PROFESOR_H
