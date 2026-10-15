//
// Created by jadel on 07/10/2026.
//

#include "Fichero.h"
#include <fstream>

Fichero::Fichero() : ruta(""), contenido(""), cargado(false) {}

Fichero::Fichero(std::string ruta) : ruta(ruta), contenido(""), cargado(false) {
    std::ifstream in(ruta);            // se cierra solo al salir
    if (in.is_open()) {
        std::string linea;
        while (std::getline(in, linea)) contenido += linea + "\n";
        cargado = true;
    }
}

bool Fichero::estaCargado() {
    return cargado;
}
std::string Fichero::getRuta() {
    return ruta;
}
std::string Fichero::getContenido() {
    return contenido;
}