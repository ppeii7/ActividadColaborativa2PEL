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
