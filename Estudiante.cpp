//
// Created by jadel on 07/10/2026.
//

#include "Estudiante.h"

Estudiante::Estudiante() {
    Usuario();
}

Estudiante::Estudiante(std:: string id, std::string nombre, std:: string apellido) {
    Usuario(id,nombre, apellido);
}
