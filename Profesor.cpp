//
// Created by jadel on 07/10/2026.
//

#include "Profesor.h"


Profesor::Profesor() {
    Usuario();
}

Profesor::Profesor(std::string id, std::string nombre, std::string apellido) {
    Usuario(id, nombre, apellido);
}

bool Profesor::tieneEstudiante(std::string idEstudiante) {
    for (int i = 1; i <= clase.getLength(); i++) {
        if (clase.at(i) == idEstudiante) return true;
    }
    return false;
}

bool Profesor::inscribirEstudiante(std::string idEstudiante) {
    if (tieneEstudiante(idEstudiante)) return false;
    return clase.add(idEstudiante);
}

bool Profesor::quitarEstudiante(std::string idEstudiante) {
    for (int i = 1; i <= clase.getLength(); i++) {
        if (clase.at(i) == idEstudiante) {
            clase.remove(i);
            return true;
        }
    }
    return false;
}

int Profesor::getNumEstudiantes() {
    return clase.getLength();
}

std::string Profesor::getIdEstudiante(int pos) {
    return clase.at(pos);
}