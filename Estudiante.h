//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_ESTUDIANTE_H
#define ACTIVIDADCOLABORATIVA2_ESTUDIANTE_H
#include <string>
#include "Usuario.h"
#include "ListaGenerica.h"
#include "Fichero.h"




class Estudiante : public Usuario {

private:

    ListaGenerica<std::string> asignaturas;
    ListaGenerica<double> notas;
    ListaGenerica<Fichero> mochila;

    int buscarAsignatura(std::string asignatura);
public:
    Estudiante();
    Estudiante(std::string id, std::string nombre, std::string apellido);

    // Notas
    bool addNota(std::string asignatura, double nota);
    double getNota(std::string asignatura);
    int getNumAsignaturas();
    void mostrarNotas();
    std::string toString();

    // Mochila
    bool cargarFichero(Fichero fichero);
    int getNumFicheros();
    Fichero& getFichero(int posicion);
};

#endif //ACTIVIDADCOLABORATIVA2_ESTUDIANTE_H