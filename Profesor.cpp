//
// Created by jadel on 07/10/2026.
//

#include "Profesor.h"


Profesor::Profesor() : Usuario() {
}

Profesor::Profesor(std::string id, std::string nombre, std::string apellido) : Usuario(id, nombre, apellido) {
}

bool Profesor::tieneEstudiante(std::string idEstudiante) {
    bool retorno = false;
    for (int i = 1; i <= clase.getLength(); i++) {
        if (clase.at(i) == idEstudiante) {
            retorno = true;
        }
    }
    return retorno;
}

bool Profesor::inscribirEstudiante(std::string idEstudiante) {
    bool retorno;
    if (tieneEstudiante(idEstudiante)) {
        retorno = false;
    } else {
        retorno = clase.add(idEstudiante);
    }
    return retorno;
}

bool Profesor::quitarEstudiante(std::string idEstudiante) {
    bool retorno = false;
    for (int i = 1; i <= clase.getLength(); i++) {
        if (clase.at(i) == idEstudiante) {
            clase.remove(i);
            retorno = true;
        }
    }
    return retorno;
}

int Profesor::getNumEstudiantes() {
    return clase.getLength();
}

std::string Profesor::getIdEstudiante(int pos) {
    return clase.at(pos);
}

bool Profesor::calificarEstudiante(Estudiante* estudiante, const std::string& asignatura, double nota) {
    bool retorno ;
    if (estudiante == nullptr) {
        retorno = false;
    } else if (!tieneEstudiante(estudiante->getId())) { // Verificamos si el profesor tiene a este estudiante usando su ID
        retorno = false;
    } else { // Si es su alumno, delega la inserción real al estudiante
        retorno = estudiante->addNota(asignatura, nota);
    }

    return retorno;
}