//
// Created by jadel on 07/10/2026.
//

#include "Usuario.h"


Usuario:: Usuario() {
    this->id = 0;
    this->nombre = "";
    this->apellido = "";
}

Usuario:: Usuario(std::string id, std::string nombre, std::string apellido) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
}

std::string Usuario:: getId() {
    return this->id;
}

std::string Usuario:: getNombre() {
    return this->nombre;
}

std::string Usuario:: getApellido() {
    return this->apellido;
}

std::string Usuario:: toString() {
    return "Nombre: " + this->nombre + ", apellido: " + this->apellido;
}