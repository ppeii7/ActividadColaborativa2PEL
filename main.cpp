#include <iostream>

#include "Profesor.h"
#include "Usuario.h"

void liberarTodos(ListaGenerica<Usuario*>& l) {
    for (int i = 1; i < l.getLength(); i++) delete l.at(i);
}

Usuario* buscarUsuario(ListaGenerica<Usuario*>& listaUsuarios,std::string& id) {
    for (int i = 1; i < listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId() == id) {
            return u;
        }
    }
    return nullptr;
}

void menuAdministrator(ListaGenerica<Usuario*>& usuarios, int& contadorId) {
    int opcion = 0;
    do {
        std::cout << "Bienvenido administrador " << std::endl;
        std::cout << "1. Alta de usuario" << std::endl;
        std::cout << "2. Baja de usuario" << std::endl;
        std::cout << "3. Modificar usuario" << std::endl;
        std::cout << "4. Listar usuarios" << std::endl;
        std::cout << "5. Calculadora" << std::endl;
        std::cout << "6. Cerrar sesion" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                std::cout << "Cerrando sesion..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 6);
}






void menuProfesor(Profesor* p, ListaGenerica<Usuario*>& listaUsuarios) {
    int opcion = 0;
    do {
        std::cout << "Bienvenido profesor " << p->getNombre() << std::endl;
        std::cout << "1. Ver datos de mi clase" << std::endl;
        std::cout << "2. Ver notas de alumnos" << std::endl;
        std::cout << "3. Anadir estudiante a mi clase" << std::endl;
        std::cout << "4. Eliminar estudiante de mi clase" << std::endl;
        std::cout << "5. Calculadora" << std::endl;
        std::cout << "6. Cerrar sesion" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                std::cout << "Cerrando sesion..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 6);
}



void menuEstudiante(Estudiante* e) {
    int opcion = 0;
    do {
        std::cout << "Bienvenido estudiante " << e->getNombre() << std::endl;
        std::cout << "1. Ver mis notas" << std::endl;
        std::cout << "2. Cargar fichero en la mochila" << std::endl;
        std::cout << "3. Ver mi mochila" << std::endl;
        std::cout << "4. Ver contenido de un fichero" << std::endl;
        std::cout << "5. Calculadora" << std::endl;
        std::cout << "6. Cerrar sesion" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                std::cout << "Cerrando sesion..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 6);
}

void printMenuPrincipal(ListaGenerica<Usuario*>& listaUsuarios) {

    std:: cout << "MENÚ PRINCIPAL" << std::endl;
    std:: cout << "============================" << std::endl;

    std:: string id;
    std:: cout << "Ingrese su id: " << std::endl;
    std:: cin >> id;
    int opcion = 0;



    Usuario* u = buscarUsuario(listaUsuarios, id);
    if (u == nullptr) {
        std::cout << "Usuario no encontrado." << std::endl;
        return;
    }

    if (u->getId()[0]=='A'){
        opcion = 1;
    }else if (u->getId()[0]==('P')) {
        opcion = 2;
    }else if (u->getId()[0]==('E')) {
        opcion = 3;
    }

    int contadorId = 2;

    switch (opcion) {
        case (1) :
            menuAdministrator(listaUsuarios,contadorId);
            break;
        case 2:
            menuProfesor(static_cast<Profesor*>(u),listaUsuarios);
            break;
        case 3:
            menuEstudiante(static_cast<Estudiante*>(u));
            break;

        default:
            std::cout << "Opcion no valida." << std::endl;
            break;
    }

}






int main() {
    ListaGenerica<Usuario*> listaUsuarios;
    Usuario* admin = new Usuario("A0000", "Admin", "");
    listaUsuarios.add(admin);
    Profesor* p1 = new Profesor("P0001", "Jorge", "García");
    listaUsuarios.add(p1);

    printMenuPrincipal(listaUsuarios);

    liberarTodos(listaUsuarios);

    return 0;
}