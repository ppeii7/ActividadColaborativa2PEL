//
// Created by jadel on 07/10/2026.
//

#ifndef ACTIVIDADCOLABORATIVA2_USUARIO_H
#define ACTIVIDADCOLABORATIVA2_USUARIO_H
#include <string>


class Usuario {

private:
    std:: string id;
    std:: string nombre;
    std::string apellido;

public:

    Usuario();
    Usuario(std::string id, std::string nombre, std::string apellido);
    std::string getId();
    std::string getNombre();
    std::string getApellido();
    std::string toString();
};


#endif //ACTIVIDADCOLABORATIVA2_USUARIO_H
