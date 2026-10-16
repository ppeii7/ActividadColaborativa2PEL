//
// Created by jadel on 07/10/2026.
//

#include "Estudiante.h"
#include <iostream>

// La lista de inicializacion (: Usuario(...)) construye la parte Usuario del estudiante.
// Llamar a Usuario(...) dentro del cuerpo solo crearia un objeto temporal.
Estudiante::Estudiante() : Usuario() {
}

Estudiante::Estudiante(std::string id, std::string nombre, std::string apellido)
    : Usuario(id, nombre, apellido) {
}

// ---------- Notas ----------

int Estudiante::buscarAsignatura(std::string asignatura) {
    int retorno = -1;
    for (int i = 1; i <= this->asignaturas.getLength(); i++) {
        if (this->asignaturas.at(i) == asignatura) {
            retorno = i;
        }
    }
    return retorno;
}

bool Estudiante::addNota(std::string asignatura, double nota) {
    bool retorno = true;
    if (nota < 0 || nota > 10) {
        std::cout << "Nota invalida (debe estar entre 0 y 10)" << std::endl;
        retorno = false;
    }

    int pos = this->buscarAsignatura(asignatura);
    if (pos != -1) {
        this->notas.at(pos) = nota; // La asignatura ya existe: se actualiza su nota
        retorno = true;
    }

    if (this->asignaturas.estaLlena()) {
        std::cout << "No caben mas asignaturas" << std::endl;
        retorno = false;
    }

    // Las dos listas se modifican siempre juntas para que no se descuadren
    this->asignaturas.add(asignatura);
    this->notas.add(nota);
    return retorno;
}

double Estudiante::getNota(std::string asignatura) {
    double retorno;
    int pos = this->buscarAsignatura(asignatura);
    if (pos == -1) {
        retorno = -1;
    } else {
        retorno = this->notas.at(pos);
    }
    return retorno;
}

int Estudiante::getNumAsignaturas() {
    return this->asignaturas.getLength();
}

void Estudiante::mostrarNotas() {
    if (this->asignaturas.getLength() == 0) {
        std::cout << "Sin notas registradas" << std::endl;
    } else {
        for (int i = 1; i <= this->asignaturas.getLength(); i++) {
            std::cout << this->asignaturas.at(i) << ": " << this->notas.at(i) << std::endl;
        }
    }
}


std::string Estudiante::toString() {
    return Usuario::toString() + ", asignaturas: " + std::to_string(this->asignaturas.getLength());
}

// ---------- Mochila ----------

bool Estudiante::cargarFichero(Fichero fichero) {
    return this->mochila.add(fichero);
}

int Estudiante::getNumFicheros() {
    return this->mochila.getLength();
}

Fichero& Estudiante::getFichero(int posicion) {
    return this->mochila.at(posicion);
}