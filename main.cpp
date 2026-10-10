#include <iostream>



void menuAdministrator() {

}

void menuProfesor() {
    std:: cout << "Bienvenido profesor  " <<std::endl;
}

void menuEstudiante() {

}

void printMenuPrincipal() {

    std:: cout << "MENÚ PRINCIPAL" << std::endl;
    std:: cout << "============================" << std::endl;

    std:: string id;
    std:: cout << "Ingrese su id: " << std::endl;
    std:: cin >> id;
    int opcion;

    if (id.contains('a')){
        opcion = 1;
    }else if (id.contains('p')) {
        opcion = 2;
    }else if (id.contains('e')) {
        opcion = 3;
    }


    switch (opcion) {
        case (1) :
            menuAdministrator();
            break;
        case 2:
            menuProfesor();
            break;
        case 3:
            menuEstudiante();
            break;

        default:
            std::cout << "Opcion no valida." << std::endl;
            break;
    }

}






int main() {

    return 0;
}