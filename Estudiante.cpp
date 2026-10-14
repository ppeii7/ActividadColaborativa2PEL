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
    for (int i = 1; i <= this->asignaturas.getLength(); i++) {
        int aux;
        if (this->asignaturas.at(i) == asignatura) {
            aux=i;
        }
        return aux;
    }
    return -1;
}

bool Estudiante::addNota(std::string asignatura, double nota) {
    bool aux=true;
    int pos = this->buscarAsignatura(asignatura);
    if (nota < 0 || nota > 10) {
        std::cout << "Nota invalida (debe estar entre 0 y 10)" << std::endl;
        aux = false;
    }else if (pos != -1){
        this->notas.at(pos) = nota; // La asignatura ya existe: se actualiza su nota
        aux = true;
    }else if (this->asignaturas.estaLlena()) {
        std::cout << "No caben mas asignaturas" << std::endl;
        aux = false;
    }else{ // Las dos listas se modifican siempre juntas para que no se descuadren
        this->asignaturas.add(asignatura);
        this->notas.add(nota);
    }

    return aux;
}

double Estudiante::getNota(std::string asignatura) {
    int pos = this->buscarAsignatura(asignatura);
    int aux;
    if (pos == -1) {
       aux= -1;
    }else{
        aux = this->notas.at(pos);
    }
    return aux;
}

int Estudiante::getNumAsignaturas() {
    return this->asignaturas.getLength();
}

void Estudiante::mostrarNotas() {
    if (this->asignaturas.getLength() == 0) {
        std::cout << "Sin notas registradas" << std::endl;
        return;
    }
    for (int i = 1; i <= this->asignaturas.getLength(); i++) {
        std::cout << this->asignaturas.at(i) << ": " << this->notas.at(i) << std::endl;
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